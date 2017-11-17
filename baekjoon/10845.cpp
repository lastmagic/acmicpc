#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
class que
{
private:
  int front;
  int rear;
  int *arr;
  int size;
  int capacity;

public:
  que(int num)
  {
    arr = new int[num];
    size = 0;
    capacity = num;
    front = 0;
    rear = -1;
  }
  void push(int num)
  {
    if(size == capacity)
    {
      int *temp = new int[capacity*2];
      for(int i=0; i<capacity; i++)
      {
        temp[i] = arr[i];
      }
      delete []arr;
      arr = temp;
      capacity = 2 * capacity;
    }
    rear++;
    arr[rear%capacity] = num;
    size++;
  }
  void pop()
  {
    if(size == 0)
      cout << -1 << "\n";
    else
    {
      cout << arr[front%capacity] << "\n";
      front++;
      size--;
    }
  }
  int getSize()
  {
    return size;
  }
  void getFront()
  {
    if(size == 0)
      cout << -1 << "\n";
    else
    {
      cout << arr[front%capacity] <<"\n";
    }

  }
  void getRear()
  {
    if(size == 0)
      cout << -1 << "\n";
    else
    {
      cout << arr[rear%capacity] << "\n";
    }
  }
};
int main(int argc, char const *argv[]) {

  que *s1 = new que(10000);
  int num, num2;
  string str;
  cin >> num;
  for(int i=0; i<num; i++)
  {
    cin >> str;
    if(str.compare("push")==0)
    {
      cin >> num2;
      s1->push(num2);
    }
    else if(str.compare("pop")==0)
    {
      s1->pop();
    }
    else if(str.compare("size")==0)
    {
      cout << s1->getSize() <<"\n";
    }
    else if(str.compare("empty")==0)
    {
      if(s1->getSize()==0)
        cout << 1 <<"\n";
      else
        cout << 0 <<"\n";
    }
    else if(str.compare("front")==0)
    {
      s1->getFront();
    }
    else if(str.compare("back")==0)
    {
      s1->getRear();
    }
  }
  return 0;
}
