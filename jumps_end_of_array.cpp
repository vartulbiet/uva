 #include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string>
#include <queue>
#include <sstream>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ull unsigned long long 
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
using namespace std;
#define INF 1<<20
 int jump(int A[], int n) {
        vector<int>arr;
        for(int i =0;i<n;i++)
            arr.push_back(1<<30);
            arr[0] =0;
        for(int i =0;i<n-1;i++)
        {
            for(int j = 1;j<=A[i];j++)
            {
                if(i+j<n)
                arr[i+j] = min(arr[i+j],arr[i] + 1);
            }
        }
        return arr[n-1];
    }
    int main()
    {
        int A[] = {1,2,3,4};
        int n =4;
        cout<<jump(A,n);
        return 0;
    }