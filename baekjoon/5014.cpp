#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;

#define MAXN 1000100
#define INF 987654321

const int UP=1;
const int DOWN=0;
int f,s,g,u,d;
int dist[MAXN];
int vec[2];

void input(){
	scanf("%d %d %d %d %d", &f,&s,&g,&u,&d);
	vec[UP] = u;
	vec[DOWN] = -d;
}
bool inner(int level){
	if(level >=0 && level<=f) return true;
	else return false;
}
void init(){
	for(int i=0; i<MAXN; i++){
		dist[i] = INF;
	}
}
void process(){
	queue<int> q;
	dist[s] = 0;
	q.push(s);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i=0; i<2; i++){
			int next = now + vec[i];
			if(inner(next) && (dist[next] > dist[now] +1)){
				dist[next] = dist[now] + 1;
				q.push(next);
			}
		}
	}
}

void output(){
	if(dist[g]<INF){
			printf("%d", dist[g]);
	}else{
		printf("use the stairs");
	}
}

int main(void){
	init();
	input();
	process();
	output();
	return 0;
}
