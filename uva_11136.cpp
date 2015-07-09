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
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		multiset<long long int>temp;
		long long int ans =0;
		for(long long int i =0;i<n;i++)
		{
			long long int x;
			cin>>x;
			for(int j =0;j<x;j++)
			{
				long long int y =0;
				cin>>y;
				temp.insert(y);
			}
			//sort(temp.begin(),temp.end());
			 std::multiset<long long int>::iterator it,lt;
			
			// for(it=temp.begin();it!=temp.end();it++)
			 //cout<<*it<<"-- ";
			 //cout<<endl;
			 if(temp.size()>=2)
			 {
			  it= temp.begin();
				long long int f = *it;
			
			//cout<<"--"<<f<<" ";
				lt= (--temp.end());
				long long int l = *lt;
			//cout<<l<<endl;
				temp.erase(it);
				temp.erase(lt);
				ans+=(l-f);
				}
		}
		cout<<ans<<endl;
		cin>>n;
	}
	return 0;
}