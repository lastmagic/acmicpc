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
const int left_param = -2;
const int left_mid = -3;
char buf[50];
int ans;
int len;
int idx;
bool flag;
std::stack<int> s;
void input(){
	scanf("%s", buf);
}

void init(){
	idx = ans =0;
	len = strlen(buf);
	flag = true;
}
void chk_close(int arg){
	if(s.empty()){
		flag =false;
	}
	int now = s.top();
	if(now == arg){
		s.pop();
		s.push(-arg);
	}else if(now > 0){
		s.pop();
		while(s.top()>0){
			now += s.top();
			s.pop();
		}
		if(s.top()==arg){
			s.pop();
			s.push((-arg)*now);
		}
		else{
			flag= false;
		}
	}else{
		flag = false;
	}
}
void process(){
	while(idx<len){
		if(buf[idx] == '('){
			s.push(left_param);
		}else if(buf[idx] == '['){
			s.push(left_mid);
		}else if(buf[idx] == ')'){
			chk_close(left_param);
		}else if(buf[idx] == ']'){
			chk_close(left_mid);
		}
		if(!flag) break;
		idx++;
	}
}

void output(){
	if(flag){
		int sum=0;
		while(!s.empty()){
			if(s.top() < 0){
				flag = false;
				break;
			}
			sum += s.top();
			s.pop();
		}
		if(flag){
			printf("%d\n", sum);
		}
		else{
			printf("0");
		}
	}else{
		printf("0");
	}
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}
