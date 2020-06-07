/*
https://www.acmicpc.net/problem/2515
전시장
전시장에서 그림을 판매하는 업체에 하나의 전시대가 배정된다. 전시될 그림은 직사각형의 모양을 가지고 있고, 그림의 높이는 다를 수 있지만 폭은 모두 동일하다고 가정한다. 각 그림에는 가격이 매겨져 있다. 
업체는 그림들을 관람객에게 보이기 위해 전시대에 배치하는데, 전시대의 폭이 그림의 폭과 동일하여 겹쳐서 배치해야만 한다. 예를 들어, 위의 그림은 전시대에 네 개의 그림 A, B, C, D를 C, B, A, D의 순서로 겹쳐서 배치한 상황을 보여준다.
위 그림의 오른쪽 부분은 전시된 그림들의 배치를 옆에서 본 모양을 나타내고, 왼쪽 부분은 배치한 그림들을 앞에서 보아서 관람객들이 보게 될 모양을 나타낸다. 그림 A는 앞의 그림 B때문에 가려져서 관람객에게 전혀 보이지 않고, 부분적으로라도 보이는 그림은 B, C, D 뿐이다. 
보이는 부분의 세로 길이가 특정 정수 S이상인 그림만 관람객이 관심을 보이고 사게 된다고 가정한다. 전시된 그림들 중 보이는 부분의 세로 길이가 S이상인 그림을 판매가능 그림이라고 부른다. 
그림의 높이와 가격이 주어질 때, 판매가능 그림들의 가격의 합이 최대가 되도록 그림을 배치할 때, 그 최대합을 구하는 프로그램을 작성하시오.
Keyword: DP, LIS
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using std::sort;
using pii=pair<int,int>;
int n;
int s;
int dp[300001];
int ans;
vector<pii> picture;
void input(){
	scanf("%d %d", &n, &s);
	int height, price;
	for (int i=0; i<n; i++) {
		scanf("%d %d", &height, &price);
		picture.push_back({ height, price });
	}
}

void init(){
	sort(picture.begin(), picture.end());
	memset(dp, 0, sizeof(dp));
	ans = 0;
}

void findLIS() {
	int j = 0;
	int curMax = 0;
	for(int i=0; i<n; i++) {
		// j가 i보다 앞에있으면서 둘의 높이차가 S이상이라 i를 판매 가능할 때의 j중 가장 가중치가 큰 j 선택
		while((i >= j) && (s <= picture[i].first - picture[j].first)) {
			if (curMax < dp[j]) {
				curMax= dp[j];
			}
			j++;
		}
		// 가중치가 가장큰 j를 이용한 상태에서 i를 포함했을때의 최대값 갱신
		dp[i] = curMax + picture[i].second;
		// 기존의 최대값 보다 크다면 갱신
		if (dp[i] > ans) {
			ans = dp[i];
		}
	}
}

void process(){
	findLIS();
}

void output(){
	printf("%d", ans);
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}
