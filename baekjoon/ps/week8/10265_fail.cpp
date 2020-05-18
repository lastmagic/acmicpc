#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>

using std::pair;
using std::vector;
using std::greater;
using pii=pair<int,int>;
using lint=long long;

#define DEFAULT 0
#define FINISH_TIME 1
int n,k;
bool graph[1001][1001];
bool visited[1001];
int cnt;
typedef struct vertex{
	int startTime;
	int finishTime;
	int v;
}vertex;
vector<vertex> vTime;
vector<int> sccSize;
int startTime[1001];
int finishTime[1001];
int curTime;
int cumulateSum[1001];
int ans;
void input(){
	scanf("%d %d", &n, &k);
	for (int i=1; i<=n; i++) {
		int v;
		scanf("%d", &v);
		graph[i][v] = true;
	}
}

void init(){
	memset(visited, 0, sizeof(visited));
	memset(graph, 0, sizeof(graph));
	memset(startTime, 0, sizeof(startTime));
	memset(finishTime, 0, sizeof(finishTime));
	curTime = 0;
	ans = 0;
}

void dfs(int v, int type) {
	if (visited[v]) return;
	visited[v] = true;

	if (type == DEFAULT) {
		vertex cur;
		cur.v = v;
		cur.startTime = ++curTime;

		for(int i=1; i<=n; i++) {
			if (graph[v][i] && !visited[i]) {
				dfs(i, type);
			}
		}
		curTime++;
		cur.finishTime = ++curTime;
		vTime.push_back(cur);
	} else if (type == FINISH_TIME) {
		cnt++;
		for(int i=1; i<=n; i++) {
			if (graph[v][i] && !visited[i]) {
				dfs(i, type);
			}
		}
	} else {
		printf("Error");
		exit(-1);
	}
}

bool comp(vertex v1, vertex v2) {
	return v1.finishTime > v2.finishTime;
}

void doDfsByType(int type) {
	if (type == DEFAULT) {
		for(int i=1; i<=n; i++) {
			if (!visited[i]) {
				dfs(i, type);
			}
		}
		sort(vTime.begin(), vTime.end(), comp);
	} else if (type == FINISH_TIME){
		for(auto &it: vTime){
			if (!visited[it.v]) {
				cnt = 0;
				dfs(it.v, type);
				sccSize.push_back(cnt);
			}
		}
	} else {
		printf("Error");
		exit(-1);
	}
	
}

void inverseGraph() {
	int iGraph[1001][1001];

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			iGraph[j][i] = graph[i][j];
		}
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			graph[i][j] = iGraph[i][j];
		}
	}
}

void findSCC() {
	// dfs
	doDfsByType(DEFAULT);
	// inverse
	inverseGraph();
	// finishTime 기준으로 다시 dfs
	memset(visited, 0, sizeof(visited));
	doDfsByType(FINISH_TIME);
}

bool isPromise(int curVal, int curIndex) {
	// 더했을때 k보다 작거나 같지만
	// 현재 찾은 최대값 보다는 커야 한다.
	int curMax = (curVal + cumulateSum[sccSize.size() - 1] - cumulateSum[curIndex]);
	return (curMax <= k) && (curMax >= ans);	
}

void find(int curVal, int curIndex) {
	if (curIndex >= sccSize.size()) return;
	int nextVal = curVal + sccSize[curIndex];
	int nextIndex = curIndex + 1;

	if (nextVal > ans && nextVal <= k) {
		ans = nextVal;
	}

	if (isPromise(nextVal, nextIndex) && !visited[nextIndex]) {
		visited[nextIndex] = true;
		find(nextVal, nextIndex);
		visited[nextIndex] = false;
	}
}

void findMaxVal() {
	int index = 0;
	for (auto &cur: sccSize) {
		int curVal = 0;
		int curIndex = index;

		if (isPromise(curVal, curIndex) && !visited[curIndex]) {
			visited[curIndex] = true;
			find(curVal, curIndex);
			visited[curIndex] = false;
		}
		index++;
	}
}

void findAns() {
	memset(visited, 0, sizeof(visited));
	findMaxVal();
}

void process(){
	// step1. find SCC by DFS
	findSCC();
	// step2. Sort SCC Size and find cumulateSum
	sort(sccSize.begin(), sccSize.end(), greater<int>());
	int i = 0;
	for (auto &it: sccSize) {
		cumulateSum[i+1] += cumulateSum[i] + it;
		i++;
	}
	// step3. Check combination of SCC size, to reach most likely to k
	findAns();
}

void output(){
	printf("%d", ans);
}

int main(void){
	init();
	input();
	process();
	output();
	return 0;
}
