#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
const int NOR = 1;
const int REV = -1;
using std::pair;
using std::vector;
using std::deque;
using pii=pair<int,int>;
using lint=long long;
deque<int> dq;
char buf[111111];
int n;
int len;
int flag;
bool err;
void input(){
	scanf("%s", buf);
	scanf("%d", &n);
	char tmp;
	scanf(" %c",&tmp);
	for(int i=0; i<n; i++){
		int num;
		scanf("%d,", &num);
		dq.push_back(num);
	}
	scanf(" %c",&tmp);
}

void init(){
	dq = deque<int>();
	flag=NOR;
	err = false;
}

void process(){
	for(int i=0; buf[i]!='\0'; i++){
		if(buf[i]=='R'){
			flag = -flag;
		}else if(buf[i]=='D'){
			if(dq.empty()){
				err = true;
				break;
			}
			if(flag == NOR){
				dq.pop_front();
			}else if(flag == REV){
				dq.pop_back();
			}
		}else{
			break;
		}
	}
}

void output(){
	if(err) printf("error\n");
	else{
		printf("[");
		if(!dq.empty()){
			if(flag == NOR){
					auto it = dq.begin();
					printf("%d", *it);
				for(it++; it!=dq.end(); it++){
					printf(",%d", *it);
				}
			}
			else{
				auto it = dq.rbegin();
				printf("%d", *it);
				for(it++; it!=dq.rend(); it++){
					printf(",%d", *it);
				}
			}
		}
		printf("]\n");
	}
}

int main(void){
	int tc;
	scanf("%d", &tc);
	for(int i=0; i<tc; i++){
		init();
		input();
		process();
		output();
	}
	return 0;
}
