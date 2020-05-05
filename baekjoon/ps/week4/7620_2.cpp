#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <stdlib.h>
using namespace std;

typedef vector<int> VI;
VI tops, bottoms; // n2[n1]
string s1, s2;
int N;

int INF = (1<<30);

struct entry { int dist, top, bottom, lbottom; };
vector<entry> state1, state2;

void solve(int start, int end, int start2, int end2)
{
	int N1 = end - start;
	int N2 = end2 - start2; // Could be zero.
	if (end < start + 1)
		return;  // Already solved
	int mid = N1 / 2;
	state1.resize(N2+1);
	state2.resize(N2+1);

	for(int i = 0; i <= N2; i++) {
		state1[i].dist = i;  // We can generate an empty string by deleting everything.
		state1[i].top = i;
		state1[i].bottom = 0;
	}

	// Produce string 1 from string 2.
	for(int n1 = 1; n1 <= N1; n1++)
	{
		for(int n2 = 0; n2 <= N2; n2++)
		{
			entry &e = state2[n2];

			// We can always just add this character.
			{
				int newdist = state1[n2].dist + 1;
				e = state1[n2];
				e.lbottom = n2;
				e.dist = newdist;
			}

			// We can delete a character, if there is one.
			if (n2 > 0) {
				int newdist = state2[n2-1].dist + 1;
				if (newdist < e.dist) {
					e = state2[n2-1];
					e.dist = newdist;
				}
			}

			// We can change or copy.
			if (n2 > 0) {
				int newdist = state1[n2-1].dist +
					(s1[n1+start-1] == s2[n2+start2-1] ? 0 : 1);
				if (newdist < e.dist) {
					e = state1[n2-1];
					e.lbottom = n2;
					e.dist = newdist;
				}
			}

			if (n1 == mid) {
				e.top = n2;
				e.bottom = e.lbottom;
			}

			assert(e.top >= e.bottom);
		}
		swap(state1,state2);
	}

#ifdef GENERATE_CHECK_OUTPUT
	cout << state1[N2].dist << endl;
	exit(0);
#endif

	// Look, ma, no special cases at all!
	// If mid == 0, then we need to avoid:
	//  - Recursing indefinitely.
	//  - Writing the wrong value to bottoms[start].
	// (Most of this complexity is to compute tops[0], which
	//  could just as easily be computed directly.)
	tops[start + mid] = state1[N2].top + start2;
	if (mid)
		bottoms[start + mid] = state1[N2].bottom + start2;
	if (bottoms[end] != -1)
		assert(bottoms[end] == state1[N2].lbottom + start2);
	bottoms[end] = state1[N2].lbottom + start2;
	solve(start, start+mid, (mid ? start2 : tops[start]), bottoms[start+mid]);
	if (mid != 0)
		solve(start+mid, end, tops[start+mid], end2);
}

int main()
{
	getline(cin, s2);
	getline(cin, s1);
	int N1 = s1.length();
	int N2 = s2.length();
	tops.resize(N1+1);
	bottoms.resize(N1+1);
	fill(bottoms.begin(), bottoms.end(), -1);
	tops[0] = -1;  // this gets computed.
	bottoms[0] = 0;  // this doesn't.
	solve(0, N1, 0, N2);
	tops[N1] = N2;
	assert(bottoms[0] == 0);
	for(int i = 0; i <= N1; i++)
	{
		assert(bottoms[i] <= tops[i]);
		assert(tops[i] <= N2);
		if (i > 0) {
			if (bottoms[i] == tops[i-1]) {
				cout << 'a' << ' ' << s1[i-1] << endl;
			} else if (bottoms[i] == tops[i-1] + 1) {
				if (s1[i-1] == s2[bottoms[i]-1])
					cout << 'c';
				else
					cout << 'm';
				cout << ' ' << s1[i-1] << endl;
			} else {
				assert(false);
			}
		}
		for(int j = bottoms[i]+1; j <= tops[i]; j++)
			cout << 'd' << ' ' << s2[j-1] << endl;
	}
}
