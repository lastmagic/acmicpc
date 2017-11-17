#include<cstdio>
#include<vector>
using namespace std;

int N,K;
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a>b?a:b;}

const int maxn=1000000;
int data[2*maxn],deque_min[2*maxn],deque_max[2*maxn],M[maxn];

int main(){
	//var;
	int pivot,i,j,c;

	//code
	scanf("%d %d",&N,&K);

	for(i=0;i<N;i++)
		scanf("%d",&data[i]);

	for(c=0,pivot=K-1;pivot<N;pivot+=K){
		deque_max[K-1]=deque_min[K-1]=data[pivot];

		for(i=1;i<K;i++){
			deque_min[K-i-1]=min(deque_min[K-i],data[pivot-i]);
			deque_max[K-i-1]=max(deque_max[K-i],data[pivot-i]);

			if(pivot+i-1 >= N-1) {
				deque_max[K+i-1]=deque_min[K+i-1]=0x7fffffff;
			}
			else {
				deque_min[K+i-1]=min(deque_min[K+i-2],data[pivot+i]);
				deque_max[K+i-1]=max(deque_max[K+i-2],data[pivot+i]);
			}
		}
		for(i=0,j=K-1;i<K;++i,++j){
			if(++c > N-K+1) break;
			M[c-1]=max(deque_max[i],deque_max[j]);
			printf("%d ",min(deque_min[i],deque_min[j]));
		}
	}
	printf("\n");
	for(i=0;i<N-K+1;++i)
		printf("%d ",M[i]);

	return 0;
}
