#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
int w,h;
int map[100][100];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,0,1,-1,0,1};
bool check[100][100];
int cnt;
void input()
{
  scanf("%d %d", &w, &h);
  if(w||h) exit();

  for(int i=0; i<h; i++)
  {
    for(int j=0; j<w; j++)
    {
      scanf("%d", &map[i][j]);
      check[i][j] = false;
    }
  }
  cnt =0;
}
void bfs(int x, int y)
{

}
void process()
{
  for(int i=0; i<h; i++)
  {
    for(int j=0; j<w; j++)
    {
      if(!check[i][j])
      {
        check[i][j] = true;
        bfs(i,j);
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
