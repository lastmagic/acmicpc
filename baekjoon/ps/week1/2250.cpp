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
