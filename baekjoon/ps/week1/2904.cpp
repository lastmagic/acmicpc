/*
https://www.acmicpc.net/problem/2904
수학은 너무 쉬워

상근이의 할머니는 매우 유명한 수학자이다. 할머니는 매일 수학 문제로 상근이를 힘들게 한다. 할머니는 종이 N장에 숫자를 하나씩 쓴 다음 상근이에게 준다. 그 다음 상근이는 다음과 같이 문제를 풀어야 한다.

두 수 A와 B를 고르고, A를 나눌 수 있는 소수 X를 고른다. 그 다음, A를 지우고 A/X를 쓰고, B를 지우고 B×X를 쓴다.

상근이는 위의 행동을 무한히 반복할 수 있다. 할머니는 상근이가 만든 수를 보고 점수를 계산한다. 점수가 높을수록 할머니는 상근이에게 사탕을 많이 준다. 점수는 종이에 적혀있는 모든 수의 최대공약수이다.

상근이가 얻을 수 있는 가장 높은 점수를 구하는 프로그램을 작성하시오. 또, 그 점수를 얻으려면 최소 몇 번 해야 하는지도 구한다.
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using std::pair;
using std::make_pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
int n;
int arr[101];
bool isPrime[1000001];
int primeCnt[1000001];
int resCnt = 0;
int res = 1;
vector<pii> v[101];
void input(){
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
}
void eratos() {
  int range = sqrt(1000000);
  for(int i=2; i<=range; i++) {
    if(isPrime[i]) {
      for (int j=i*2; j<=1000000; j+=i) {
        isPrime[j] = false;
      }
    }
  }
}

void init(){
  memset(isPrime, 1, sizeof(isPrime));
  memset(primeCnt, 0, sizeof(primeCnt));
  eratos();
}

void primeFactorization(int n, int index) {
  int cur = n;
  for(int i=2; i<=n; i++) {
    //  해당 소수로 나눌 수 있으면
    int cnt = 0;
    while(isPrime[i] && (cur / i) && (cur % i == 0)) {
      cnt++;
      cur = cur / i;
    }
    if (cnt) {
      v[index].push_back(make_pair(i, cnt));
      primeCnt[i] += cnt;
    }
    if (cur == 1) {
      return;
    }
  }
}

void distributePrimeNumber() {
for (int i=2; i<1000000; i++) {
    if (primeCnt[i]) {
      int q = primeCnt[i] / n;
      int r = primeCnt[i] % n;

      for(int j=0; j<n; j++) {
        bool isFoundPrime = false;
        for (auto it = v[j].begin(); it != v[j].end(); it++) {
          if(it->first == i) {
            isFoundPrime = true;
            resCnt += abs(it->second - q);
            break;
          }
        }
        if (!isFoundPrime) {
          resCnt += q;
        }
      }
      res *= pow(i, q);
      resCnt -= r;
    }
  }
  // resCnt는 in,out 상관없이 2번씩 세었으니 2로 나눠줌.
  resCnt /= 2;
}

void process(){
  // Step 1 primeFactorization
  for (int i=0; i<n; i++) {
    primeFactorization(arr[i], i);
  }

  // Step 2 distribute primeNumber
  distributePrimeNumber();
}

void output(){
  printf("%d %d", res, resCnt);
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}
