#include <iostream>
#include <cstring>
using namespace std;
class que
{
private:
  int *arr;
  int front;
  int rear;
  int size;
  int capacity;
public:
  que(int num)
  {
    capacity = num;
    arr = new int[capacity];
    for(int i=0; i<capacity; i++)
    {
      arr[i] = i+1;
    }
    front = 1;
    rear = capacity;
  }
  void pop(int num)
  {
    front = front +1;
  }
};
int posDiff(int num1, int num2)
{
  if(num1 > num2)
    return num1 - num2;
  else
    return num2 - num1;
}
int main(int argc, char const *argv[]) {
  int size, num,cnt=0,pos=1, cur;
  cin >> size >> num;
  for(int i=0; i<num; i++)
  {
    cin >> cur;
    cout << "cur = " << cur <<" pos = "<< pos << "size = "<< size << "\n";
    if(posDiff(cur, pos) < posDiff(size+pos , cur))
    {
      cnt += posDiff(cur,pos);
      pos = cur;
    }
    else
    {
      cnt += posDiff(size+pos, cur);
      pos = cur;
    }

  }
  cout << cnt;
  return 0;
}
