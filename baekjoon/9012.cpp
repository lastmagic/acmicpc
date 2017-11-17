#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
#define TRUE 1
#define FALSE 0
template <typename T>
class stack
{
private:
  int size;
  int capacity;
  int top;
  T *arr;

public:
  stack(int num)
  {
    capacity = num;
    arr = new T[capacity];
    top = -1;
    size = 0;
  }
  void init();
  void push(T num);
  int pop();
  int getSize();
  void getTop();
  void print();
};
template <typename T>
void stack<T>::init()
{
  size = 0;
  top = -1;
}
template <typename T>
void stack<T>::push(T num)
{
  if(size == capacity)
  {
    T *temp = new T[capacity*2];
    for(int i=0; i<capacity; i++)
    {
      temp[i] = arr[i];
    }
    delete []arr;
    arr = temp;
    capacity = 2 * capacity;
  }
  arr[++top] = num;
  size++;
}
template <typename T>
int stack<T>::pop()
{
  if(size == 0)
  {
    return FALSE;
  }
  else
  {
    //cout << arr[top--] <<"\n";
    top--;
    size--;
    return TRUE;
  }
}
template <typename T>
int stack<T>::getSize()
{
  return size;
}

int main(int argc, char const *argv[]) {

  stack <char>*s1 = new stack<char>(100);
  int num, num2, flag=TRUE;
  string str;
  cin >> num;
  for(int i=0; i<num; i++)
  {
    cin >> str;
    for(int j=0; j<str.length(); j++)
    {
      if(str.at(j) == '(')
        s1->push('(');
      else if(str.at(j) == ')')
      {
        flag = s1->pop();
        if(flag == FALSE)
          break;
      }
    }
    if(s1->getSize() || flag == FALSE)
      cout << "NO\n";
    else
      cout << "YES\n";
    s1->init();
    flag = TRUE;
  }
  return 0;
}
