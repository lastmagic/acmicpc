#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int n,arr[80];
bool flag = false;

bool check(int pos)
{
    bool chk;
    for(int i=1; i<=pos/2+1; i++)
    {
        chk = false;
        for(int j=0; j<i; j++)
        {
            if(arr[pos-j] != arr[pos-j-i])
                chk = true;
        }
        if(!chk) return false;
    }
    return true;
}

void good_num(int pos)
{
    if(flag) return;
    if(pos == n)
    {
        flag = true;
        return;
    }
    for(int i=1; i<=3; i++)
    {
        arr[pos] = i;
        if(check(pos))
            good_num(pos+1);
        if(flag) return;
    }
}
int main(void)
{
    cin >> n;
    good_num(0);
    for(int i=0; i<n; i++)
        cout << arr[i];
    return 0;
}
