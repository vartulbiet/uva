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
#define graphAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<10
using namespace std;
		int arr[200005];
		int brr[200005];

int main()
{
	int n =0;
	cin>>n;
	int tc =1;
	while(n!=0)
	{
		int m =0;
		cin>>m;
		for(int i =0;i<m;i++)
		{
			cin>>arr[i];
		}
		for(int i =m;i<2*m;i++)
		{
			arr[i] = arr[i-m];
		}
		for(int i =0;i<m;i++)
		{
			int x =0;
			cin>>x;
			arr[i] -=x;
			arr[i+m]-=x;
		}
		for(int i =0;i<2*m;i++)
		arr[i] += arr[i-1];
		int ans =0; int mi =1; int cn =0;
		for(int i =0;i<2*m;i++)
		{
			 if (arr[i] >= mi) {
                                if (++cn > m) break;
                        } else {
                                mi = arr[i];
                                ans = i+1;
                                cn = 1;
                                if (i >= m) break;
                        }
		}
		cout<<"Case "<<tc++<<": ";
		if(cn<=m)
		cout<<"Not possible"<<endl;
		else
		cout<<"Possible from station "<<ans+1<<endl;
		n--;
	}
	return 0;
}