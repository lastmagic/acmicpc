/*
https://www.acmicpc.net/problem/6850
Cows
Your friend to the south is interested in building fences and turning plowshares into swords. In order to help with his overseas adventure, they are forced to save money on buying fence posts by using trees as fence posts wherever possible. Given the locations of some trees, you are to help farmers try to create the largest pasture that is possible. Not all the trees will need to be used.
However, because you will oversee the construction of the pasture yourself, all the farmers want to know is how many cows they can put in the pasture. It is well known that a cow needs at least 50 square metres of pasture to survive.

Keyword: Convex Hull, Geometric, Graham Scan
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

#define INF 1234567890
#define _USE_MATH_DEFINES // PI macro 사용
struct point {
	int x;
	int y;
	float length;
	float polarAngle;
};
using std::vector;
using std::sort;
using lint=long long;
int N;
vector<point> tree; // 문제에서 주어지는 나무들 입력.
vector<point> convex; // 나무들로 이뤄지는 볼록 다각형의 꼭지점 저장
lint res;
int minX = INF;
int minY = INF;
void input(){
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		tree.push_back({x, y, 0, 0});

		if (y < minY) {
			minY = y;
			minX = x;
		} else if (y == minY && x < minX) {
			minX = x;
		}
	}
}

// 가장 left, bottom 지점을 선택하기 때문에 나올 수 있는 각도는 0~180도 이다. 따라서 해당 각을 모두 구분 할 수 있는 atan2f 사용
float getAngle(int x1, int y1, int x2, int y2){
    return atan2f((float)(y2-y1),(float)(x2-x1))*180/M_PI;
}

// 두 점 사이의 거리 계산
float getLengthSquare(int x1, int y1, int x2, int y2) {
	return sqrt((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1));
}

// most left, bottom point를 기준으로 모든 점의 angle과 length 계산
void findPolarAngleAndLength(int x, int y) {
	for(auto& it: tree) {
		float angle = getAngle(x, y, it.x, it.y);
		float length = getLengthSquare(x, y, it.x, it.y);
		it.polarAngle = angle;
		it.length = length;
	}
}

// 정렬 기준의 순서는 angle, y, x
bool compByPolarAngle(point p1, point p2) {
	if (p2.polarAngle > p1.polarAngle) {
		return true;
	} else if (p2.polarAngle < p1.polarAngle) {
		return false;
	} else {
		if (p2.y > p1.y) {
			return true;
		} else if (p2.y < p1.y) {
			return false;
		} else {
			if (p2.x > p1.x) {
				return true;
			} else {
				return false;
			}
		}
	}
	return p2.polarAngle > p1.polarAngle;
}

// 문제 조건의 정렬기준에 따라 정렬
void sortByPolarAngle(int x, int y) {
	sort(tree.begin(), tree.end(), compByPolarAngle);
}

// 같은 angle을 가지는 point중 최대 lengt를 가지는 point를 제외하고 삭제
void trimByPolarAngle(int x, int y) {
	// implement trim by polar angle
	for(int i=1; i<tree.size() - 1; i++){
		point cur = tree[i];
		point next = tree[i+1];
		if (cur.polarAngle == next.polarAngle) {
			if (cur.length < next.length) {
				tree.erase(tree.begin() + (i));
			} else {
				tree.erase(tree.begin() + (i+1));
			}
			i--;
		}
	}
}

void init(){
	findPolarAngleAndLength(minX, minY);
	sortByPolarAngle(minX, minY);
	trimByPolarAngle(minX, minY);
	convex.push_back(tree[0]);
	convex.push_back(tree[1]);
}

// triangle(p1, p2, p3) 의 면적을 구하는 함수
int calcSignArea(point p1, point p2, point p3) {
	int signArea = 0;

	signArea = ((p1.x * p2.y - p1.y * p2.x)
	 + (p2.x * p3.y - p3.x * p2.y)
	 + (p3.x * p1.y - p1.x * p3.y)) / 2;

	return signArea;
}

// p3가 p1,p2로 이루어진 segment를 기준으로 left인지 판단하는 함수
bool isLeftOfSegment(point p3) {
	if (convex.size() < 2) return false;
	int p1Index = convex.size() - 2;
	int p2Index = convex.size() - 1;

	point p1 = convex[p1Index];
	point p2 = convex[p2Index];

	int signArea = calcSignArea(p1, p2, p3);

	return signArea > 0;
}

// trim하고 남은 tree들에 대해서 convex에 참여가능 한지 판단하는 함수
void findGrahamScan() {
	int size = tree.size();
	for(int i=2; i<size ;) {
		point cur = tree[i];
		if (isLeftOfSegment(cur)) {
			convex.push_back(cur);
			i++;
		} else {
			if (i == 2) {
				i++;
				continue;
			}
			convex.pop_back();
		}
	}
}

// convex에 참여중인 point를 이용해 실제 convex의 면적을 구하는 함수
lint calcTotalArea() {
	point p1 = convex[0];
	lint sum = 0;
	int size = convex.size();
	for(int i=1; i<size - 1; i++) {
		point p2 = convex[i];
		point p3 = convex[i+1];

		sum += calcSignArea(p1, p2, p3);
	}

	return sum;
}

void process(){
	findGrahamScan();
	lint totalArea = calcTotalArea();
	res = totalArea / 50;
}

void output(){
	printf("%lld", res);
}

int main(void){
	input();
	if (N < 3) {
		printf("0");
		return 0;
	}
	init();
	process();
	output();
	return 0;
}
