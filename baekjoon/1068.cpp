#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> tree[55];
int root;
int del;
int ans;
void input(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int p;
		scanf("%d", &p);
		if(p==-1) root = i;
		else{
			tree[p].push_back(i);
		}
	}
	scanf("%d", &del);
}

void dfs(int start)
{
	if(start==del) return;
	if(tree[start].size()==0) ans++;
	else{
    if(tree[start].size()==1){
      if(tree[start].front() == del)
        ans++;
    }
		for(vector<int>::iterator e= tree[start].begin(); e!=tree[start].end(); e++){
			dfs(*e);
		}
	}
}

void output(){
	printf("%d", ans);
}
int main(){
	input();
	dfs(root);
	output();
}
