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
#define ll  long long 
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
#define MP make_pair
#define ii pair<int,int>
using namespace std;
ll ans;
void cal(vector<string>arr,int sx,int sy)
{

	int m = arr.size();
	if(sx<0 ||sy<0 ||sx>=m ||sy>=m)
	return;
	if(sx == 0)
	{
		ans++;
		ans %= 1000007;
		
	}
	else
	{
		if(sx-1>=0 && sx-1<m && sy-1>=0 && sy-1<m)
		{
			if( arr[sx-1][sy-1] =='.')
			{
				//vec.PB(MP(sx-1,sy-1));
				cal(arr,sx-1,sy-1);
				//vec.pop_back();
			}
			else
			{
				if(sx-2>=0 && sx-2<m && sy-2>=0 && sy-2<m && arr[sx-2][sy-2] =='.')
				{
				//vec.PB(MP(sx-2,sy-2));
				cal(arr,sx-2,sy-2);
				//vec.pop_back();
				}
			}
		}
		if(sx-1>=0 && sx-1<m && sy+1>=0 && sy+1<m)
		{
			if( arr[sx-1][sy+1] =='.')
			{
			//cout<<"ji"<<" ";
			//vec.PB(MP(sx-1,sy+1));
				cal(arr,sx-1,sy+1);
				//vec.pop_back();
			}
			else
			{
				if(sx-2>=0 && sx-2<m && sy+2>=0 && sy+2<m && arr[sx-2][sy+2] =='.')
				{
				//vec.PB(MP(sx-2,sy+2));
					cal(arr,sx-2,sy+2);
				//	vec.pop_back();
				}
			}
		}
	}
}
int main()
{
	int n =0;
	cin>>n;
	int tc =1;
	while(n--)
	{
		ans =0;
		int r=0;
		cin>>r;
	
		vector<string>arr;
		for(int i =0;i<r;i++)
		{
			string s;
			cin>>s;
			//cout<<s<<endl;
		arr.push_back(s);
		}
		int sx,sy=0;
		for(int i =0;i<r;i++)
		{
			//cout<<arr[i]<<endl;
			for(int j =0;j<r;j++)
			if(arr[i][j]=='W')
			{
				sx =i;sy=j;
			//cout<<i<<j<<endl;
			}
			
		}
		
	//	vec.PB(MP(sx,sy));
		cal(arr,sx,sy);
		cout<<"Case "<<tc++<<": "<<ans<<endl;
	}
	return 0;
}