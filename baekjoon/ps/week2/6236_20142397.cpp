/*
https://www.acmicpc.net/problem/6236
용돈관리

현우는 용돈을 효율적으로 활용하기 위해 계획을 짜기로 하였다. 현우는 앞으로 N일 동안 자신이 사용할 금액을 계산하였고, 돈을 펑펑 쓰지 않기 위해 정확히 M번만 통장에서 돈을 빼서 쓰기로 하였다. 현우는 통장에서 K원을 인출하며, 통장에서 뺀 돈으로 하루를 보낼 수 있으면 그대로 사용하고, 모자라게 되면 남은 금액은 통장에 집어넣고 다시 K원을 인출한다. 다만 현우는 M이라는 숫자를 좋아하기 때문에, 정확히 M번을 맞추기 위해서 남은 금액이 그날 사용할 금액보다 많더라도 남은 금액은 통장에 집어넣고 다시 K원을 인출할 수 있다. 현우는 돈을 아끼기 위해 인출 금액 K를 최소화하기로 하였다. 현우가 필요한 최소 금액 K를 계산하는 프로그램을 작성하시오.

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
int budget[100001];
int max = -INF;
int min;
int res = INF;
lint sum = 0;
void input(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%d", &budget[i]);
		sum += budget[i];
		if (budget[i] > max) max = budget[i];
	}
}

void init(){
	min = max -1;
	max = sum;
}

bool isWithdrawable(int val) {
	int cnt = 0;
	int current = 0;
	for (int i=0; i<n; i++) {
		if (budget[i] > val) {
			return false;
		}

		if (current + budget[i] <= val) {
			if (current == 0) {
				cnt++;
			}
			current += budget[i];
		} else {
			cnt++;
			current = budget[i];
		}
	}

	if (cnt <= m) {
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
	if (isWithdrawable(mid)) {
		if (mid < res) res = mid;
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
	printf("%d", res);
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}
