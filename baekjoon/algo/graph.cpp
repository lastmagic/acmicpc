/*그래프 사용시 cpp에서는 벡터를 이용하는것이 좋음.
(u,v)를 추가하고싶다면
1차원 벡터를 두고 그 벡터에 인덱스가 u, 푸쉬하는게 v
이런식으로 이용하게 됨
만약 edge에 특정한 값이 더 있어야 하는 경우
cost만 추가한다면
typdef pair<int, int> P;
vector<P> grahp[N];
이런식으로 이용 할 수 있음.

cost이외의 데이터가 더 필요한 경우는 아예 구조체를 선언해서 사용하는 것이 편함
인풋을 받아올때는

graph[u].push_back(v);

pair를 사용할 수 있고 c++11이상으로 컴파일 할 수 있다면
graph[u].push_back({u,cost});
이런식으로 중괄호만으로 pair를 만들어서 넣을 수 있다. (굳이 make_pair함수 사용할 필요 X)

벡터를 반복해야 할 경우 보통 3가지 방법을 사용하는데 가장기초는 반복자 사용

for(vector<T>::iterator it =graph[index].begin(); it!=graph[index].end(); it++)
이 경우 소스사 상당히 길어지게 된다 별로 쓸게 못됨.
이래서 나오게 된게 데이터타입을 자동으로 지정해주는 auto
위와 같은 소스를 auto로 만들경우
for(auto it = graph[index].being(); it!=graph[index].end(); it++)
아까보다는 가독성이 훨씬 좋아지는 것을 알 수 있다.
하지만 근본적으로 call by reference를 지원하지 않기 때문에 c-b-r을 지원하기위해서는
참조자와 auto를 같이쓰는 문법이 가장 깔끔하고 직관적이다.
for(auto &e: graph[index])
위의 두 소스와 비슷한 식으로 이루어져 있지만 c-b-r이기 때문에 원래 가리키는 대상자체의
새로운 이름이 되어서 값을 바꿀 수 있다.
훨씬 편하게 쓸 수 있음!
*/
