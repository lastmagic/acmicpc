#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#define INF 1234567890
using namespace std;

typedef pair<int, int> P;
vector<P> graph[10100]; //각 node의 left,right저장(pair로)
vector<int> arr[10100]; //각 level의 좌표를 저장할 vector
bool visited[10100];
int V;
int parent[101000];//root를 찾기위한 배열
int bread;
int _max_level;
int _root;

void find_root(int node)//root찾기
{
    while(parent[node])
    {
        node = parent[node];
    }
    _root= node;
}
void input() //graph배열에 각 node에 left,right저장
{
    int node, left, right;
    scanf("%d", &V);
    for(int i=0; i<V; i++)
    {
        scanf(" %d %d %d", &node, &left, &right);
        if(left!=-1)
            parent[left] = node;
        if(right!=-1)
            parent[right] = node;
        graph[node].push_back(make_pair(left, right));

    }
    find_root(node);
}

void bfs(int root, int level)
{
    if(_max_level < level)
        _max_level = level;
    visited[root] = true;
    if (graph[root].back().first == -1 && graph[root].back().second == -1) //leaf인 경우 bread증가후 종료
    {
        arr[level].push_back(++bread);
        return;
    }
    /*중위순회를 이용하여 너비 계산*/
    if (graph[root].back().first != -1 && !visited[graph[root].back().first])
        bfs(graph[root].back().first, level+1);

    arr[level].push_back(++bread);

    if (graph[root].back().second != -1&& !visited[graph[root].back().second])
        bfs(graph[root].back().second, level+1);
}
void output()
{
    int _max, _min, res_level=-1, res_bread=-1;
    for(int i=1; i<=_max_level; i++) //level 1부터 _max_level까지 확인
    {
        _max=-INF;
        _min=INF;
        /*arr[i]에 들어있는 _max,_min을 찾고  너비를 구해 최대인경우 갱신*/
        for(vector<int>::iterator it=arr[i].begin(); it!=arr[i].end(); it++)
        {
            if(_max < (*it))
                _max = (*it);
            if(_min > (*it))
                _min = (*it);
        }
        if((_max-_min) > res_bread)
        {
            res_bread = _max-_min;
            res_level = i;
        }
    }
    printf("%d %d", res_level, res_bread+1);
}

int main()
{
    input();
    bfs(_root,1);
    output();
}
