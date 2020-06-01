/*
https://www.acmicpc.net/problem/2787
흔한 수열 문제

수업시간이 너무나 지루했던 태석이는 종이에 길이가 N인 수열 A를 적었다. 이 수열은 1보다 크거나 같고, N보다 작거나 같은 양의 정수로 이루어져 있고, 각 숫자는 정확히 한 번씩 등장한다.

그런 다음 태석이는 다른 종이에 수열 A에 대한 설명을 M개 적었다.

각 설명은 다음과 같은 형태로 되어있다.

1 x y v - x번째 수부터, y번째 수 중 제일 큰 값은 v
2 x y v - x번째 수부터, y번째 수 중 제일 작은 값은 v
태석이는 설명만 적은 종이를 보성이에게 주었다. 보성이는 M개의 설명만 가지고 태석이가 원래 적은 수열을 맞추어보려고 한다.

M개의 설명이 주어졌을 때, 태석이가 원래 적은 수열을 구해 출력하는 프로그램을 작성하시오. 수열은 여러개 존재할 수 있다.

Keyword: Network Flow, Maximum Bipartite Matching, Graph

Note: Maximum Bipartite Matching 자체가 A -> B로 갈 수 있는
Edge만 명확하게 나눌 수 있다면 구현이 어려운 문제는 아니었다.
다만 각 Vertex별로 최대,최소값에 따라서 Edge를 parsing하는 부분이 생각보다
고민이 많이 필요했던 부분이라고 생각한다.
직접 flow로 구현하는 경우도 있을 것이라고 생각되는데, 아직 flow문제에 익숙치 않아서
연습이 필요한 부분이라 생각한다.
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

#define MAX_N 201
#define MAX 1
#define MIN 2
using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;

int N,M;
bool connection[MAX_N][MAX_N]; // connection[u][v] == u,v 연결시 true, 아닐시 false
int range[3][MAX_N]; // range[MAX][i] == vertex i가 연결될 수 있는 최대값, range[MIN][i] == vertex i가 연결될 수 있는 최소값.
bool visited[MAX_N];
int match[MAX_N]; // 이분매칭에 오른쪽 집합
int ans[MAX_N]; // 이분매칭에 왼쪽 집합
bool isFound;
bool dfs(int);

void init(){
  memset(connection, 1, sizeof(connection));
  for(int i=1; i<=N; i++) {
    range[MIN][i] = 1;
    range[MAX][i] = N;
  }
  isFound = false;
}

void input(){
  for(int i=1; i<=M; i++) { // M개의 조건 입력
    int cmd, x, y, v;
    scanf("%d %d %d %d", &cmd, &x, &y, &v);
    for (int j=1; j<=N; j++) {
      if (j < x || j > y) { // v가 존재 할 수 있는 범위에 벗어난 vertex(j)는 v와 연결될 가능성이 없으므로 false로 초기화
        connection[j][v] = false;
        continue;
      }

      if (cmd == MAX) {
        if (range[MAX][j] > v) {
          range[MAX][j] = v;
        }
      } else if (cmd == MIN) {
        if (range[MIN][j] < v) {
          range[MIN][j] = v;
        }
      } else {
        printf("wrong input\n");
        exit(-1);
      }
    }
  }
}

bool isVisitable(int now, int next) { // 접근가능 할 경우 접근
  return (connection[now][next] && match[next] == -1);
}

bool replaceIfPossible(int now, int next) { // 기존 next가 연결된 vertex를 재귀적으로 변경가능시 변경
  return (connection[now][next] && dfs(match[next]));
}

bool dfs(int now) {
  if (visited[now]) {
    return false;
  }

  visited[now] = true;
  for (int next=1; next<=N; next++) {
    if (isVisitable(now, next)) {
      ans[now] = next;
      match[next] = now;
      return true;
    }
  }

  for (int next=1; next<=N; next++) {
    if (replaceIfPossible(now, next)) {
      ans[now] = next;
      match[next] = now;
      return true;
    }
  }

  return false;
}

bool findMaxMatching() {
  for(int i=1; i<=N; i++){
    for(int j=1; j<range[MIN][i]; j++) { // vertex(i)의 최소값보다 작은 vertex의 경우 연결삭제
      connection[i][j] = false;
    }
    for(int j=range[MAX][i]+1; j<=N; j++) { // vertex(i)의 최대값보다 큰 vertex의 경우 연결삭제
      connection[i][j] = false;
    }
  }
  int matchingCnt = 0;
  memset(match, -1, sizeof(match));
  memset(ans, -1, sizeof(ans));

  for (int i=1; i<=N; i++) {
    memset(visited, 0, sizeof(visited));
    if (ans[i] == -1 && dfs(i)) {
      matchingCnt++;
    }
  }

  return matchingCnt == N;
}

void process(){
	isFound = findMaxMatching();
}

void output(){
  if (isFound) {
    for (int i=1; i<=N; i++) {
      printf("%d ", ans[i]);
    }
  } else {
    printf("-1");
  }
}

int main(void){
  scanf("%d %d", &N, &M);
  init();
  input();
  process();
  output();
  return 0;
}
