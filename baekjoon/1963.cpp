#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using std::pair;
using std::vector;
using std::queue;
using P=pair<int,int>;
using lint=long long;
int tc;
int source, dest;
int ans;
bool prime[11111];
bool chk[11111];
bool flag=false;

void init(){
	ans = 0x3f3f3f3f;
	memset(chk, 0 ,sizeof(chk));
	for(int i=0; i<10000; i++){
		prime[i] = 1;
	}
	for(int i=2; i<10000; i++){
		if(prime[i]){
			for(int j=i*i; j<10000; j+=i){
				prime[j] = 0;
			}
		}
	}
}
int make_num(int *arr){
	int ret=0;
	for(int i=0; i<4; i++){
		ret += arr[i] * pow(10,3-i);
	}
	return ret;
}

void split_num(int num, int *arr){
	arr[0] = num/1000;
	arr[1] = (num%1000)/100;
	arr[2] = (num%100)/10;
	arr[3] = (num%10);
}
void input(){
	scanf("%d %d", &source, &dest);
}
void bfs(int node){
	queue<P> q;
	q.push({node, 0});
	while(!q.empty()){
		int now = q.front().first;
		int cnt = q.front().second;
		if(now == dest && ans > cnt){
			ans = cnt;
		}
		q.pop();
		if(chk[now]) continue;
		chk[now] = true;

		int ori[4]; //기존의 숫자를 저장
		int arr[4]; //변경된 숫자를 저장

		split_num(now, ori);

		for(int i=0; i<4; i++){
			split_num(now, arr);
			for(int j=0; j<10; j++){
				if(i==0&&j==0) continue;
				if(ori[i]==j)	continue;

				arr[i] = j;
				int next = make_num(arr);
				if(prime[next]){
					q.push({next, cnt+1});
				}
			}
		}
	}
}
void process(){
	bfs(source);
}
void output(){
	if(ans==0x3f3f3f3f) printf("Impossible\n");
	else printf("%d\n", ans);
}
int main(void){
	scanf("%d", &tc);
	for(int i=0; i<tc;i++){
		init();
		input();
		process();
		output();
	}
	return 0;
}
