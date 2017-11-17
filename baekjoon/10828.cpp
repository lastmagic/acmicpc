#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
class stack
{
private:
  int size;
  int capacity;
  int top;
  int *arr;

public:
  stack(int num)
  {
    capacity = num;
    arr = new int[capacity];
    top = -1;
    size = 0;
  }
  void init();
  void push(int num);
  void pop();
  int getSize();
  void getTop();
  int getTopValue();
  void print();

};

void stack::init()
{
  size = 0;
  top = -1;
}
void stack::push(int num)
{
  if(size == capacity)
  {
    int *temp = new int[capacity*2];
    for(int i=0; i<capacity; i++)
    {
      temp[i] = arr[i];
    }
    arr = temp;
    delete temp;
    capacity = 2 * capacity;
  }
  arr[++top] = num;
  size++;
}
void stack::pop()
{
  if(size == 0)
  {
    cout << -1 <<"\n";
  }
  else
  {
    cout << arr[top--] <<"\n";
    size--;
  }
}
int stack::getSize()
{
  return size;
}

void stack::getTop()
{
  if(top == -1)
    cout << -1 <<"\n";
  else
    cout << arr[top] << "\n";
}
void stack::print()
{
  cout <<"Stack print = ";
  for(int i=0; i<size; i++)
  {
    cout <<arr[i] <<" ";
  }
  cout <<"end here\n";
}
int main(int argc, char const *argv[]) {

  stack *s1 = new stack(10000);
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
    else if(str.compare("top")==0)
    {
      s1->getTop();
    }
  }
  return 0;
}
