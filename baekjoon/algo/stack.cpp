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

template <typename T>
void stack<T>::getTop()
{
  if(top == -1)
    cout << -1 <<"\n";
  else
    cout << arr[top] << "\n";
}
template <typename T>
void stack<T>::print()
{
  cout <<"Stack print = ";
  for(int i=0; i<size; i++)
  {
    cout <<arr[i] <<" ";
  }
  cout <<"end here\n";
}
