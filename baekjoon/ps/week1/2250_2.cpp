/*
https://www.acmicpc.net/problem/2250
트리의 높이와 너비

이진트리를 다음의 규칙에 따라 행과 열에 번호가 붙어있는 격자 모양의 틀 속에 그리려고 한다. 이때 다음의 규칙에 따라 그리려고 한다.

이진트리에서 같은 레벨(level)에 있는 노드는 같은 행에 위치한다.
한 열에는 한 노드만 존재한다.
임의의 노드의 왼쪽 부트리(left subtree)에 있는 노드들은 해당 노드보다 왼쪽의 열에 위치하고, 오른쪽 부트리(right subtree)에 있는 노드들은 해당 노드보다 오른쪽의 열에 위치한다.
노드가 배치된 가장 왼쪽 열과 오른쪽 열 사이엔 아무 노드도 없이 비어있는 열은 없다.
이와 같은 규칙에 따라 이진트리를 그릴 때 각 레벨의 너비는 그 레벨에 할당된 노드 중 가장 오른쪽에 위치한 노드의 열 번호에서 가장 왼쪽에 위치한 노드의 열 번호를 뺀 값 더하기 1로 정의한다. 트리의 레벨은 가장 위쪽에 있는 루트 노드가 1이고 아래로 1씩 증가한다.

아래 그림은 어떤 이진트리를 위의 규칙에 따라 그려 본 것이다. 첫 번째 레벨의 너비는 1, 두 번째 레벨의 너비는 13, 3번째, 4번째 레벨의 너비는 각각 18이고, 5번째 레벨의 너비는 13이며, 그리고 6번째 레벨의 너비는 12이다.

우리는 주어진 이진트리를 위의 규칙에 따라 그릴 때에 너비가 가장 넓은 레벨과 그 레벨의 너비를 계산하려고 한다. 위의 그림의 예에서 너비가 가장 넓은 레벨은 3번째와 4번째로 그 너비는 18이다. 너비가 가장 넓은 레벨이 두 개 이상 있을 때는 번호가 작은 레벨을 답으로 한다. 그러므로 이 예에 대한 답은 레벨은 3이고, 너비는 18이다.

임의의 이진트리가 입력으로 주어질 때 너비가 가장 넓은 레벨과 그 레벨의 너비를 출력하는 프로그램을 작성하시오
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 1234567890

using std::pair;
using std::vector;
using std::make_pair;
using pii=pair<int,int>;
using lint=long long;
int n;
vector<pii> graph[10001];
vector<int> levelPosition[10001];
int parent[10001];
int root;
int breadth = 0;
int maxLevel = -1;
int resLevel = -1;
int resBreadth = -1;
bool visited[10001];
void findRoot(int node) {
  while(parent[node]) {
    node = parent[node];
  }

  root = node;
}
void input(){
  int left, right, node;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d %d %d", &node, &left, &right);
    graph[node].push_back({left, right});
    if(left != -1)
      parent[left] = node;
    if(right != -1)
      parent[right] = node;
  }
  findRoot(node);
}

void init(){
  memset(visited, 0, sizeof(visited));
}

void bfs(int node, int level) {
  if (maxLevel < level) maxLevel = level;
  if (visited[node]) return;
  visited[node] = true;
  pii curNode = graph[node].back();
  int left = curNode.first;
  int right = curNode.second;
  
  // leaf 인경우 예외처리
  if (left == -1 && right == -1) {
    levelPosition[level].push_back(++breadth);
    return;
  }

  // leaf 가 아닌경우 중위순회
  if (left != -1 && !visited[left]) {
    bfs(left, level+1);
  }

  levelPosition[level].push_back(++breadth);

  if (right != -1 && !visited[right]) {
    bfs(right, level+1);
  }
}

void findRes() {
  for(int i=1; i<=maxLevel; i++) {
    int curMax = -INF;
    int curMin = INF;
    for(auto cur: levelPosition[i]) {
      if (cur > curMax) curMax = cur;
      if (cur < curMin) curMin = cur;
      if ((curMax - curMin) + 1 > resBreadth){
        resBreadth = (curMax - curMin) + 1;
        resLevel = i;
      }
    }
  }
}

void process(){
	bfs(root, 1);
  findRes();
}
void output(){
  printf("%d %d", resLevel, resBreadth);
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}
