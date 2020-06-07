/*
https://www.acmicpc.net/problem/1415
사탕

다솜이는 슈퍼에서 사탕을 사려고 한다. 슈퍼에는 사탕이 N종류가 있다. 각각의 사탕은 가격이 있다. 다솜이는 사탕을 사는데, 사탕의 가격의 합이 소수가 되게하려고 한다.
가격이 같은 사탕은 모양이 같게 생겼다. 따라서 다솜이는 사탕을 적절히 샀을 때, 그 모양이 전부 똑같은 방법은 사지 않으려고 한다.
예를 들어, (1, 2, 1, 3, 1)을 사는 것과, (3, 1, 1, 1, 2)를 사는 것은 같은 방법이다. 따라서 한번만 세야 한다.
입력
첫째 줄에 슈퍼에 있는 사탕의 개수 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 각 사탕의 가격이 주어진다. 사탕의 가격은 10,000보다 작거나 같은 음이 아닌 정수이다.
출력
첫째 줄에 다솜이가 사탕을 살 수 있는 방법의 경우의 수를 출력한다.

Keyword: DP
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

#define MAX_CANDY_PRICE 500000

using std::pair;
using std::vector;
using std::sort;
using pii=pair<int,int>;
using lint=long long;
int n;
lint ans;
vector<pii> price;
lint dp[MAX_CANDY_PRICE+1];
bool isPrime[MAX_CANDY_PRICE+1];
void input(){
	scanf("%d", &n);
	lint tmp;
	for (int i=0; i<n; i++) {
		scanf("%lld", &tmp);
		bool find = false;
		for (auto &it: price) {
			if (it.first == tmp) {
				it.second += 1;
				find = true;
				break;
			}
		}
		if (!find) {
			price.push_back({tmp, 1});
		}
	}
}

void eratos() {
	int range = sqrt(MAX_CANDY_PRICE);
	for (int i = 2; i <= range; i++) {
		if (isPrime[i]) {
			for (int j = i*2; j<= MAX_CANDY_PRICE; j+=i) {
				isPrime[j] = false;
			}
		}
	}
}

void init(){
	sort(price.begin(), price.end());
	memset(dp, 0, sizeof(dp));
	memset(isPrime, 1, sizeof(isPrime));
	eratos();
	ans = 0;
	dp[0] = 1;
}

bool isSelectable(int primNum, int curVal, int curCnt) {
	return primNum >= (curVal * curCnt);
}

void findPrimeCombination() {
	for (auto p : price) {
		if (p.first == 0) continue;
		int cur = p.first;
		int curCnt = p.second;
		
		for (int i=MAX_CANDY_PRICE; i>=0; i--) {
			for(int j=1; j<=curCnt; j++) {
				// i에서 (cur * j) 값 만큼 뺀 숫자를 만들 수 있는 경우의 수 만큼 dp[i]에 추가
				if (isSelectable(i, cur, j)) {
					dp[i] += dp[i - (cur * j)];
				}
			}
		}
	}

	for (int i=2; i<=MAX_CANDY_PRICE; i++) {
		if (isPrime[i]) {
			ans += dp[i];
		}
	}

	// input에 0이 포함된 경우 0의 수만큼 정답이 추가됨.
	if (price.front().first == 0) {
		ans *= price.front().second + 1;
	}
}

void process(){
	findPrimeCombination();
}

void output(){
	printf("%lld", ans);
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}
