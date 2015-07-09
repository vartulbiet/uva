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
#define ll  long long 
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
#define MP make_pair
using namespace std;
ll gcd(ll x,ll y)
{
	while(y != 0)
	{
		ll temp = y;
		y = x%y;
		x = temp;
	}
	return x;
}
void reduce(pair<ll,ll> *r)
{
int x, y;
if (r->first == 0) {
r->second = 1;
return;
}
while (((r->first | r->second) & 1) == 0) {
r->first >>= 1;
r->second >>= 1;
}
for (x = r->first, y = r->second; x != 0 && y != 0;) {
while ((x & 1) == 0)
x >>= 1;
while ((y & 1) == 0)
y >>= 1;
if (x > y)
x -= y;
else
y -= x;
}
x = (x != 0) ? x : y;
r->first /= x;
r->second /= x;
}
int main()
{
	char x;
	map<string,int>mymap;
	vector<string>vec;
	pair<ll,ll>arr[70][70];
	for(int i =0;i<70;i++)
	{
		for(int j =0 ;j<70;j++)
			arr[i][j] = MP(0,0);
	}
		/*for(int i =0;i<10;i++)
			{
				for(int j =0 ;j<10;j++)
					cout<<arr[i][j].first<<"/"<<arr[i][j].second<<" ";
				cout<<endl;
			}*/
	int k =0;
	cin>>x;
	while(x != '.'){
		if(x == '!')
		{
			int a,b;
			string m,n,p;
			cin>>a>>m>>p>>b>>n;
			if(mymap.find(m) == mymap.end())
			{
				mymap[m] = k++; 
				vec.PB(m);
			}
			if(mymap.find(n) == mymap.end())
			{
				mymap[n] = k++; 
				vec.PB(n);
			}
			arr[mymap[m]][mymap[n]] = MP(a,b);
			arr[mymap[n]][mymap[m]] = MP(b,a);
			reduce(&arr[mymap[m]][mymap[n]]);
			reduce(&arr[mymap[n]][mymap[m]]);
		}
		else
		{
			for(int k = 0;k<70;k++)
			{
				for(int i = 0;i<70;i++)
				{
					if(arr[i][k].first == 0)
						continue;
					for(int j =0;j<70;j++)
					{
						if(arr[i][j].first != 0 || arr[j][k].first == 0)
							continue;
						arr[i][j].first = arr[i][k].first * arr[k][j].first;
						arr[i][j].second  = arr[i][k].second * arr[k][j].second;
						reduce(&arr[i][j]);
							//ll h =gcd(arr[i][j].first,arr[i][j].second);
							//arr[i][j].first = arr[i][j].first / h ;
							//arr[i][j].second = arr[i][j].second / h;
					}
				}
			}
			/*for(int i =0;i<10;i++)
			{
				for(int j =0 ;j<10;j++)
					cout<<arr[i][j].first<<"/"<<arr[i][j].second<<" ";
				cout<<endl;
			}*/
			string m,n,p;
			cin>>m>>n>>p;
			if(mymap.find(m) == mymap.end())
			{
				mymap[m] = k++; 
				vec.PB(m);
			}
			if(mymap.find(p) == mymap.end())
			{
				mymap[p] = k++; 
				vec.PB(p);
			}
			if(arr[mymap[m]][mymap[p]].first == 0)
				cout<<"? "<<m<<" = "<<"? "<<p<<endl;
			else
			cout<<arr[mymap[m]][mymap[p]].first<<" "<<m<<" = "<<arr[mymap[m]][mymap[p]].second<<" "<<p<<endl;
		}
		cin>>x;
	}
	return 0;
}