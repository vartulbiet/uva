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
#define INF 1<<20
using namespace std;
int main()
{
	int n =0;
	cin>>n;
	int arr[301][301];
	while(n>0)
	{
			int k =0;int sum =0;
		cin>>k>>sum;
		for(int i =0;i<301;i++)
		{
			for(int j =0;j<301;j++)
				arr[i][j] =INF;			
		}
	
		//cout<<k<<sum;
		arr[0][0] =0;
		for(int i =0;i<k;i++)
		{
			int a,b;
			cin>>a>>b;
			for(int f = a;f<301;f++)
			{
				for(int g = b;g<301;g++)
				{
					arr[f][g] = min(arr[f][g],arr[f-a][g-b]+1);
				}
			}
		}
		int ans =INF;
		for(int f = 0;f<301;f++)
			{
				for(int g = 0;g<301;g++)
				{
					if(f*f+g*g==sum*sum)
					ans = min(ans,arr[f][g]);
				}
			}
			if(ans!=INF)
		cout<<ans<<endl;
		else
		cout<<"not possible"<<endl;
		n--;
	}
	return 0;
}