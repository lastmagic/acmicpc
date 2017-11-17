#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

//pq는 일반적인 컨테이너와 똑같이 사용할 수 있음
//pq <자료형, 구현방법, 연산자순위> 이름;
//비교연산자의 경우 구조체를 만들거나 클래스를 만들었을때 오버로딩을 이용해서 쓸 수 있음
//그렇지 않을경우 기본적으로 max_heap으로 구현이 됨


//priority_queue<int, vector<int>, greater<int> > pq;

typedef struct graph{
  int start;
  int end;
  int value;
}graph;

bool operator>(graph a1, graph a2)
{
  return a1.value > a2.value;
}

priority_queue<graph, vector<graph>, greater<graph> > pq2;
int main(int argc, char const *argv[]) {
  /*pq.push(3);
  pq.push(1);
  pq.push(4);*/
  graph g1 ={0,2,3};
  graph g2 ={2,5,5};

  pq2.push(g1);
  pq2.push(g2);
  while(!pq2.empty())
  {
    printf("%d\n", pq2.top().value);
    pq2.pop();
  }
  return 0;
}
