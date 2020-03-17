/*
https://www.acmicpc.net/problem/2448
별 찍기 - 11

예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.
첫째 줄에 N이 주어진다. N은 항상 3×2k 수이다. (3, 6, 12, 24, 48, ...) (k ≤ 10)

24

                       *                        
                      * *                       
                     *****                      
                    *     *                     
                   * *   * *                    
                  ***** *****                   
                 *           *                  
                * *         * *                 
               *****       *****                
              *     *     *     *               
             * *   * *   * *   * *              
            ***** ***** ***** *****             
           *                       *            
          * *                     * *           
         *****                   *****          
        *     *                 *     *         
       * *   * *               * *   * *        
      ***** *****             ***** *****       
     *           *           *           *      
    * *         * *         * *         * *     
   *****       *****       *****       *****    
  *     *     *     *     *     *     *     *   
 * *   * *   * *   * *   * *   * *   * *   * *  
***** ***** ***** ***** ***** ***** ***** *****
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
int n;
char star[3100][6300];
void input(){
  scanf("%d", &n);
}

void init(){
  memset(star, 0, sizeof(star));
}

void setStar(int numOfStar, int height, int space) {
  if (numOfStar == 3) {
    star[height][space] = '*';
    star[height+1][space - 1] = '*';
    star[height+1][space + 1] = '*';
    star[height+2][space - 2] = '*';
    star[height+2][space - 1] = '*';
    star[height+2][space] = '*';
    star[height+2][space + 1] = '*';
    star[height+2][space + 2] = '*';

    return;
  }

  setStar(numOfStar / 2, height, space);
  setStar(numOfStar / 2, height + numOfStar / 2, (space) - (numOfStar / 2));
  setStar(numOfStar / 2, height + numOfStar / 2, (space) + (numOfStar / 2));
}

void process(){
  setStar(n, 0, n-1);
}

void output(){
  for (int i=0; i<n; i++) {
    for (int j=0; j<2*n-1; j++) {
      if (star[i][j] == ' ' || star[i][j] == '\n' || star[i][j] == '*')
        printf("%c", star[i][j]);
      else
        printf(" ");
    }
    if (i != n-1) {
      printf("\n");
    }
  }
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}
