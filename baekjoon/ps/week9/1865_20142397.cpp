/*
https://www.acmicpc.net/problem/1865
웜홀
때는 2020년, 백준이는 월드나라의 한 국민이다. 월드나라에는 N개의 지점이 있고 N개의 지점 사이에는 M개의 도로와 W개의 웜홀이 있다. (단 도로는 방향이 없으며 웜홀은 방향이 있다.) 웜홀은 시작 위치에서 도착 위치로 가는 하나의 경로인데, 특이하게도 도착을 하게 되면 시작을 하였을 때보다 시간이 뒤로 가게 된다. 웜홀 내에서는 시계가 거꾸로 간다고 생각하여도 좋다.
시간 여행을 매우 좋아하는 백준이는 한 가지 궁금증에 빠졌다. 한 지점에서 출발을 하여서 시간여행을 하기 시작하여 다시 출발을 하였던 위치로 돌아왔을 때, 출발을 하였을 때보다 시간이 되돌아가 있는 경우가 있는지 없는지 궁금해졌다. 여러분은 백준이를 도와 이런 일이 가능한지 불가능한지 구하는 프로그램을 작성하여라.

Keyword: Bellman,Graph,Path

벨만포드 기본 알고리즘으로 풀리는 문제였다. 음의 사이클이 존재하는지만 확인하면 되는 간단한 문제였다.
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX_N 2222

using namespace std;
using pii=pair<int,int>;
using lint=long long;

const lint INF = 0x7f7f7f7f7f7f7f7f;
int TC;
int N,M,W;
lint dist[MAX_N];
vector<pii> adj[MAX_N];
vector<bool> ans;
bool check[MAX_N];
bool hasNegativeCycle;

void input() {
  scanf("%d %d %d" , &N, &M, &W);

  for(int i=0; i<M; i++) {
    int s,e,_t;
    scanf("%d %d %d", &s, &e, &_t);
    adj[s].push_back({e,_t});
    adj[e].push_back({s,_t});
  }

  for(int i=0; i<W; i++) {
    int s,e,_t;
    scanf("%d %d %d", &s, &e, &_t);
    adj[s].push_back({e,-_t});
  }

  for(int i=1; i<=N; i++) {
    adj[0].push_back({i,0});
  }
}

void init() {
  memset(dist, 0x7f, sizeof(dist));
  memset(check, 0, sizeof(check));
  // 이전 TC에서 사용했던 vector 초기화
  for(int i=0; i<=N; i++) {
    adj[i].clear();
  }
}

void bellman(int start) {
  dist[start] = 0;

  for(int i=0; i<N; i++) {
    hasNegativeCycle = false;
    for(int j=0; j<=N; j++) {
      for(auto &now: adj[j]) {
        if(dist[j] !=INF && dist[now.first] > dist[j] + now.second) {
          dist[now.first] = dist[j]+now.second;
          hasNegativeCycle = true;
        }
      }
    }
  }

  ans.push_back(hasNegativeCycle);
}

void process() {
  bellman(0);
}

void output() {
  for(auto isTrue: ans) {
    if (isTrue) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}

int main() {
  scanf("%d", &TC);

  for(int i=0; i<TC; i++) {
    input();
    process();
    init();
  }

  output();

  return 0;
}
