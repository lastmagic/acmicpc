#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using std::pair;
using std::vector;

using pii=pair<int,int>;
using lint=long long;
int n;
char ans[555555];
int buf[111111];
int idx;
int cnt;
int num;
bool flag;
std::stack<int> s;
void input(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &buf[i]);
	}
}

void init(){
	memset(ans, 0, sizeof(ans));
	idx = cnt = 0;
	num =1;
	flag = true;
}

void process(){
	s.push(num);
	ans[cnt] = '+';

	while(idx<n){
		if(s.empty()){
			s.push(++num);
			ans[++cnt] = '+';
		}
		int now = s.top();
		if(now > buf[idx]){
			flag = false;
			break;
		}else if(now == buf[idx]){
			s.pop();
			ans[++cnt] = '-';
			idx++;
		}else{
			s.push(++num);
			ans[++cnt] = '+';
		}
	}
}

void output(){
	if(flag){
		for(int i=0; i<=cnt; i++){
			printf("%c\n", ans[i]);
		}
	}else{
		printf("NO");
	}
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}
