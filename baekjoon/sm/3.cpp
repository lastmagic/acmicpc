#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
// for Solve problem
int n;
int k;
int myArr[3001];
int splitPosition[3001];
// for find splitPosition
int comb[3001];
int result = 2100000000;

void input() {
  scanf("%d %d", &n, &k);
  for (int i=0; i<n; i++) {
    scanf("%d", &myArr[i]);
    comb[i] = i;
  }
}

void init() {
  memset(splitPosition, 0, sizeof(splitPosition));
}

int findRes() {
  int res = 0;
  for(int i=0; i<k; i++) {
    int max = -1;
    int min = 987654321;
    if (i==0) {
      // 0 ~ splitPosition[i]
      for(int j=0; j<=splitPosition[i]; j++) {
        if (max < myArr[j]) max = myArr[j];
        if (min > myArr[j]) min = myArr[j];
      }
    } else if (i!=k-1) {
      // splitPosition[i-1] ~ splitPosition[i]
      for(int j=splitPosition[i-1]+1; j<=splitPosition[i]; j++) {
        if (max < myArr[j]) max = myArr[j];
        if (min > myArr[j]) min = myArr[j];
      }
    } else {
      for(int j=splitPosition[i-1]+1; j<n; j++) {
        if (max < myArr[j]) max = myArr[j];
        if (min > myArr[j]) min = myArr[j];
      }
    }
    res += (max - min);
  }

  return res;
}

void printSplit() {
  printf("split = ");
  for(int i=0; i<k; i++) {
    printf("%d ", splitPosition[i]);
  }
  printf("\n");
}

void combination(int arr[], int data[], int start, int end, int index, int r) { 
    if (index == r) { 
        for (int j=0; j<r; j++) {
          splitPosition[j] = data[j];
        }
        printSplit();
        int tmp = findRes();
        printf("tmp = %d\n", tmp);
        if (tmp < result) result = tmp;
        init();
        return;
    }
    for (int i=start; i<=end && end-i+1 >= r-index; i++) { 
        data[index] = arr[i]; 
        combination(arr, data, i+1, end, index+1, r); 
    }
} 

void process(int arr[], int num, int r) { 
    int data[r]; 
    if (r != 0) {
      combination(arr, data, 0, num-1, 0, r);  
    } else {
      result = myArr[n-1] - myArr[0];
    }
}

int main() {
  input();
  init();
  process(comb, n-1, k-1);

  printf("%d", result);

  return 0;
}