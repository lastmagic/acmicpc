/*
https://www.acmicpc.net/problem/2613
숫자구슬

N개의 숫자 구슬이 <그림 1>과 같이 막대에 꿰어져 일자로 놓여 있다. 이들 구슬은 막대에서 빼낼 수 없고, 바꿀 수 없다.
이 숫자 구슬을 M개의 그룹으로 나누었을 때 각각의 그룹의 합 중 최댓값이 최소가 되도록 하려 하다. 예를 들어 세 그룹으로 나눈다고 할 때 <그림 2>와 같이 그룹을 나누면 그룹의 합은 각각 11, 15, 18이 되어 그 중 최댓값은 18이 되고, <그림 3>과 같이 나누면 각 그룹의 합은 각각 17, 12, 15가 되어 그 중 최댓값은 17이 된다. 숫자 구슬의 배열이 위와 같을 때는 그룹의 합 중 최댓값이 17보다 작게 만들 수는 없다. 그룹에 포함된 숫자 구슬의 개수는 0보다 커야 한다.
각 그룹의 합 중 최댓값이 최소가 되도록 M개의 그룹으로 나누었을 때, 그 최댓값과 각 그룹을 구성하는 구슬의 개수를 찾아 출력하는 프로그램을 작성하시오.

Keyword: Parametric Search
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 1234567890

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
int n,m;
int group[301];
int max = -INF;
int min;
int res = INF;
lint sum = 0;
vector<int> cnt, ans;
void input(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) {
		scanf("%d", &group[i]);
		if (group[i] > max) max = group[i];
		sum += group[i];
	}
}

void init(){
	min = max;
	max = sum;
}

// 현재 값으로 split 할 수 있는지 확인
bool isSplitable(int val) {
	cnt.clear();
	int current = 0;
	int curCnt = 0;
	for(int i=0; i<n; i++) {
		
		// 값이 val보다 클때
		if (group[i] > val) {
			return false;
		}

		// 현재그룹에 더할 수 있을때
		if (current + group[i] <= val) {
			if (current == 0) {
				cnt.push_back(0);
			}
			cnt.back() += 1;
			current += group[i];
		} else {	// 다음그룹으로 넘어가야 할 때
			cnt.push_back(1);
			current = group[i];
		}
	}
	
	if (cnt.size() <= m) {
		// 나눈 그룹수가 m보다 작은경우 그룹이 m개가 되도록 split
		while (cnt.size() < m) {
			*max_element(cnt.begin(), cnt.end()) -= 1;
			cnt.push_back(1);
		}
		
		return true;
	} else {
		return false;
	}
}

void parametericSearch(int left, int right) {
	int mid = (left + right) / 2;
	if (left > right) {
		return;
	}
	if (isSplitable(mid)) {
		if (mid < res) {
			res = mid;
			ans.clear();
			ans.assign(cnt.begin(), cnt.end());
		}
		parametericSearch(left, mid - 1);
	} else {
		parametericSearch(mid + 1, right);
	}
	return;
}

void process(){
	parametericSearch(min, max);
}

void output(){
	printf("%d\n", res);
	for(auto now: ans) {
		printf("%d ", now);
	}
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}
