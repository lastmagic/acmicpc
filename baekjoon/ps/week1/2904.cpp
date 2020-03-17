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

void process(){
  // Step 1 primeFactorization
  for (int i=0; i<n; i++) {
    primeFactorization(arr[i], i);
  }

  // Step 2 distribute primeNumber
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
