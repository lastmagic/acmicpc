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
    graph[node].push_back(make_pair(left, right));
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
    for(auto it = levelPosition[i].begin(); it != levelPosition[i].end(); it++) {
      if ((*it) > curMax) curMax = (*it);
      if ((*it) < curMin) curMin = (*it);
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
