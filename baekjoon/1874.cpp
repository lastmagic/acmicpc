#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using std::pair;
using std::vector;
using std::stack;
using pii=pair<int,int>;
using lint=long long;
int n;
char ans[111111];
int buf[111111];
int idx;
int num;
int cnt;
bool flag;
stack <int> s;
void input(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &buf[i]);
	}
}

void init(){
	memset(ans, 0 ,sizeof(ans));
	idx =0;
	cnt =0;
	num =1;
	flag = true;
}

void process(){
	s.push(1);
	ans[0] ='+';
	while(!s.empty()){
		if(idx >=n) {
			flag = false;
			printf("NO");
			break;
		}
		int now = s.top();
		if(buf[idx] > now){
			ans[++cnt] = '+';
			s.push(++num);
		}
		else if(buf[idx] == now){
			s.pop();
			ans[++cnt] = '-';
			idx++;
		}
		else{
			printf("NO");
			flag = false;
			break;
		}
	}
}

void output(){
	if(flag){
		for(int i=0; i<=cnt ;i++){
			printf("%c\n", ans[i]);
		}
	}
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}
