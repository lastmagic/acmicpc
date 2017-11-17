#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int* tenToBinary(long long num)
{
  int *binary = new int[100];
  int bit=0;
  int size=0;
  for(int i=1; i<100; i++)
  {
    if(num == 0)
    {
      binary[i] = '\0';
      break;
    }
    bit = num%2;
    num /= 2;
    binary[i] = bit;
    size++;
  }
  binary[0] = size;
  return binary;
}
long long binaryToTen(int *binary)
{
  int size = binary[0];
  long long num=0;
  long long mul=1;
  for(int i=size; i>0; i--)
  {
    if(binary[i]%2)
      num += mul;
    mul *= 2;
  }
  return num;
}
int main(int argc, char const *argv[]) {

  long long num;
  cin >> num;
  int *temp;
  temp = tenToBinary(num);
  cout << binaryToTen(temp);
  return 0;
}
