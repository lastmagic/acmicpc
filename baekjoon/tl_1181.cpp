#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
char arr[22222][55];
char *sortList[22222];
int n;
void swap(char *a, char *b){
	char *tmp;
	tmp =a;
	a =b;
	b =tmp;
}
void exchangeSort(int size){
  for(int i=0; i<size; i++){
    for(int j=i+1; j<size; j++){
			int i_len = strlen(sortList[i]);
			int j_len = strlen(sortList[j]);

      if(i_len < j_len){
				continue;
			}
			else if(i_len > j_len){
				char *tmp;
				tmp = sortList[i];
				sortList[i] = sortList[j];
				sortList[j] =tmp;
      }
			else{
				for(int k=0; k<i_len; k++){
					if(sortList[i][k] > sortList[j][k]){
						char *tmp;
						tmp = sortList[i];
						sortList[i] = sortList[j];
						sortList[j] =tmp;
					}
				}
			}
    }
  }
}
int main(int argc, char const *argv[]) {

	scanf("%d", &n);
  for(int i=0; i<n; i++){
		scanf("%s", arr[i]);
		sortList[i] = arr[i];
  }
  exchangeSort(n);
	for(int i=0; i<n; i++){
		if(i==0) {
			printf("%s\n", sortList[i]);
			continue;
		}
    if(strcmp(sortList[i-1], sortList[i]) != 0)
			printf("%s\n", sortList[i]);
  }
  return 0;
}
