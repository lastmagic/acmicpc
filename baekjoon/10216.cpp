#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
#include<functional>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<climits>
#include<set>
#include<map>
#include<deque>
using namespace std;

typedef struct{
	int x;
	int y;
	int r;
}circle;
int T,N;
vector<circle> enemy;
int ans;
int parent[3005];
int _find(int x){
	if(x == parent[x])
		return x;
	else{
		return parent[x] = _find(parent[x]);
	}
}
void _union(int u, int v){
	u = _find(u);
	v = _find(v);
	//if(u==v)    return;
	//else{
	parent[u] = v;
	//}
}
void print_arr(int *a, int size)
{
	for(int i=1; i<=size; i++)
	{
		printf("arr[%d] = %d\n", i, a[i]);
	}
}
void calculate(int a, int b){
	int dist = (enemy[a].x-enemy[b].x)*(enemy[a].x-enemy[b].x) + (enemy[a].y-enemy[b].y)*(enemy[a].y-enemy[b].y);
	int comp_rt = (enemy[a].r + enemy[b].r)*(enemy[a].r + enemy[b].r);
	if(dist <= comp_rt){
		_union(a,b);
		printf("now i = %d j = %d\n", a,b);
		print_arr(parent, N);
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		int temp = 0;
		ans=1;
		memset(parent,0,sizeof(parent));
		scanf("%d",&N);
		for(int i=1;i<=N;i++){
			parent[i] = i;
		}
		enemy.clear();
		enemy.resize(N+1);
		for(int i=1;i<=N;i++){
			scanf("%d %d %d",&enemy[i].x,&enemy[i].y,&enemy[i].r);
		}
		for (int i = 1; i<N; i++) {
			for (int j = i + 1; j <= N; j++) {
				calculate(i, j);
			}
		}
		for (int i = 1; i <= N; i++) parent[i] = _find(i);
		sort(parent + 1, parent + N + 1);
		temp = parent[1];
		for (int i = 2; i <= N; i++) {
			if (parent[i] != temp) {
				ans++, temp = parent[i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
