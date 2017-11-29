#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAXN 22222
using namespace std;
int tc;
int v,e;
int cnt;
vector<int> graph[22222];
int chk[22222];
bool flag;

void init(){
	memset(chk, 0, sizeof(chk));
	flag = true;
	cnt = 1;
	for(int i=0; i<MAXN; i++){
		graph[i].clear();
	}
}
void input(){
	scanf("%d %d", &v, &e);
	int now,next;
	for(int i=0; i<e; i++){
		scanf("%d %d", &now, &next);
		graph[now].push_back(next);
		graph[next].push_back(now);
	}
}
void dfs(int node, int color){
	if(chk[node]){
		if(chk[node]==color){
			return;
		}
		else{
			flag = false;
			return;
		}
	}
	chk[node] =color;
	for(auto &e: graph[node]){
		dfs(e,-color);
	}
}

int chk_visit_node(){
	for(int i=1; i<=v; i++){
		if(!chk[i]) return i;
	}
	return 0;
}

void process(){
	while(true){
		int index = chk_visit_node();
		if(!index) break;
		dfs(index,-cnt);
		/*
		아직 방문하지 않은 노드의 색을 임의로 칠해도 된다.
		dfs를 이미 충분히 돌린 후 방문하지 않은 노드는 연결되지 않은 노드일 것이므로
		+1이나 -1 어떤색으로 칠해도 상관이 없다.즉
		dfs(index, -cnt)를 해도
		dfs(index, cnt)를 해도 상관이 없다.
		*/
	}
}

void output(){
	if(flag) printf("YES\n");
	else printf("NO\n");
}

int main(void){
	scanf("%d", &tc);
	for(int i=0; i<tc; i++){
		init();
		input();
		process();
		output();
	}
	return 0;
}
