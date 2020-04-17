/*
https://www.acmicpc.net/problem/3114
사과와 바나나
A나라와 B나라가 국경선을 놓고 몇 년째 싸우고 있다. 분쟁 지역의 크기는 직사각형이고, R×C 개의 칸으로 나누어져 있다. 모든 칸에는 사과 나무 또는 바나나 나무가 심어져 있다.
방금, 기나긴 영토 분쟁을 끝내기 위해 중립국에서 협상가 김상근이 도착했다. 상근이는 불도저를 이용해 일부 칸에 있는 나무를 모두 제거하고, 그러한 칸을 국경선으로 이용하려고 한다. 불도저는 가장 왼쪽 윗칸에서 출발하며, 한 칸 아래, 오른쪽, 오른쪽 아래 대각선으로 이동할 수 있다. 불도저는 오른쪽 아랫칸에 도착할 때까지 이동한다.
A는 불도저가 지나간 길의 아래쪽을 가지게 되고, B는 위쪽을 가지게 된다. 따라서, 땅을 하나도 받지 못하는 경우가 생길 수도 있다.
김상근은 A에 사는 사람들은 사과를 좋아하고, B에 사는 사람들은 바나나를 좋아한다는 사실을 알고 있다. 따라서, 불도저가 지나간 길의 아래쪽에 있는 사과 나무의 개수와 위쪽에 있는 바나나 나무 개수의 합을 크게 만들려고 한다.
가능한 합 중 가장 큰 합을 구하는 프로그램을 작성하시오. 

Keyword: DP, Kadane's algorithm

Memo: 
1. 처음에 Memorization 을 이용한 Top-Down 방법을 사용했는데 실패했다.
어느정도 비슷한 결과 값을 얻을 수 있었지만 초기에 0번째 줄, 행에서의 최적값을 정의하기가 매우 까다로웠기 때문이다
(같은 위치를 참조하더라도 지나온 길에 따라 값이 달라지기 때문)
=>아마 Top-Down 방법으로 풀기에는 매우 까다로운 문제라고 생각된다.
반대로 Bottom-Up 방식으로는 굉장히 쉽게 풀렸는데 사고를 조금 더 유연하게 해야겠다는 생각이 들었다.

2. scanf를 사용해서 입력을 받으려고 했는데 c++에서 string 자료형을 사용하기 위해서 cin이 필수적이었다.
2~3년 전에 알고리즘을 풀때는 cin.cout을 자주 사용하다가 한번 알고리즘은 같은데 cin,cout 때문에 시간초과를 맞은 이후로 사용하지
않았는데, 유도리 있게 섞어쓰는 습관을 들여야겠다.
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define MAX_N 1505
#define A 1
#define B 2

using std::pair;
using std::string;
using std::ios;
using std::cin;
using std::cout;
using std::max;
using pii=pair<int,int>;
int D[MAX_N][MAX_N];
int apple[MAX_N][MAX_N];
int banana[MAX_N][MAX_N];
int r,c;
int ans;
void input(){
	ios::sync_with_stdio(false);// cin,cout 사용

	cin >> r >> c;
	// 과일 지도 입력
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			string tmp;
			cin >> tmp;
			int fruitCnt = atoi(tmp.substr(1).c_str());

			if(tmp.find("A") != -1) {
				apple[i][j] = fruitCnt;
			}else if(tmp.find("B") != -1) {
				banana[i][j] = fruitCnt;
			}
		}
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			// 사과는 우상단쪽에서 계산하기 때문에 행에 대해서 누적합을 구한다.
			if (j != 0) {
				apple[i][j] += apple[i][j-1];
			}
			// 바나나는 좌하단쪽에서 계산하기 때문에 열에 대해서 누적합을 구한다.
			if(i != 0) {
				banana[i][j] += banana[i-1][j];
			}
		}
	}
}

void init(){
	memset(D, 0, sizeof(D));
	memset(apple, 0, sizeof(apple));
	memset(banana, 0, sizeof(banana));
}

void process(){
	for(int i=0; i<r; ++i) {
		for(int j=0; j<c; ++j) {
			// i or j가 0인경우 불도저가 지나온 길에 있어봐도 쓸 수 없으므로 0 사용
			int prevApple = (j!=0)? apple[i+1][j-1]: 0;
			int prevBanana = (i!=0)? banana[i-1][j+1]: 0;
			// 현재 [i][j] 바로 아래칸으로 갈때는 해당 칸이 추가됨으로서 생기는 사과의 개수를 비교
			if (i+1 < r) {
				D[i+1][j] = max(D[i+1][j], D[i][j] + prevApple);
			}
			// 현재 [i][j] 바로 오른쪽칸으로 갈때는 해당 칸이 추가됨으로서 생기는 바나나 개수를 비교
			if (j+1 < c) {
				D[i][j+1] = max(D[i][j+1], D[i][j] + prevBanana);
			}
			// 현재 [i][j] 우하단 대각선으로 갈때는 해당 칸이 추가됨으로서 생기는 사과, 바나나 개수를 비교
			if (i+1 < r && j+1 < c) {
				D[i+1][j+1] = max(D[i+1][j+1], D[i][j] + apple[i+1][j] + banana[i][j+1]);
			}
		}
	}
}

void output(){
	cout << D[r-1][c-1];
}

int main(void){
	init();
	input();
	process();
	output();
	return 0;
}
