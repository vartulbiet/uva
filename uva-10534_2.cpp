#include<iostream>
#include<vector>
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
#include<string.h>
#include <iomanip>
#include <cstdio>
#include<math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ull unsigned long long 
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
using namespace std;


int * LIS_Lengths(vector<int> a) {
    int* lis = new int[a.size()];
    int b[a.size()];
    int maxLength = 1, lowerBound;
    lis[0] = 1, b[0] = a[0];
 
    for (size_t i = 1; i < a.size(); i++) {
        lowerBound = lower_bound(b, b + maxLength, a[i]) - b;
        lis[i] = lowerBound + 1;
        if (lowerBound == maxLength)    b[maxLength++] = a[i];
        else    b[lowerBound] = a[i];
    }
    return lis;
}


int main()
{
	int n =0;
	while(scanf("%d",&n)!=EOF)
	{
		vector<int>arr(n);
	
		for(int i =0;i<n;i++)
		{
			cin>>arr[i];
		}
		int ans =0;
		int*lis =LIS_Lengths(arr);
		reverse(arr.begin(),arr.end());
		int*lds = LIS_Lengths(arr);
		reverse(lds, lds + n);
		for(int i =0;i<n;i++)
		{
			//cout<<lis[i]<<" "<<lds[i]<<endl;
			ans =max(min(lis[i],lds[i]),ans);
		}
		cout<<ans*2-1<<endl;
	}
	return 0;
}