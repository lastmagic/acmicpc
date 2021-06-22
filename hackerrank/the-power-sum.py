#!/bin/python3
import math
import os
import random
import re
import sys
#
# Complete the 'powerSum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER X
#  2. INTEGER N
#
global res
global arr
res = 0


def dfs(X, N, cur, lastVal):
    global res
    if cur == X:
        res += 1
        return
    elif cur > X:
        return
    for i in range(lastVal - 1, 0, -1):
        if cur + (i**N) <= X and arr[i] == 1:
            arr[i] = 0
            dfs(X, N, cur + (i**N), i)
            arr[i] = 1


def powerSum(X, N):
    # Write your code here
    global arr
    arr = [1 for i in range(X)]
    dfs(X, N, 0, X)
    return res


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    X = int(input().strip())
    N = int(input().strip())
    result = powerSum(X, N)
    fptr.write(str(result) + '\n')
    fptr.close()
