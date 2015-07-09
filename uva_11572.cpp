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
	ull n =0;
	cin>>n;
	while(n>0)
	{
		ull c =0;
		cin>>c;
		map<ull,int>mymap;
		int ans =0;int nas =0;
		for(ull i =0;i<c;i++)
		{
			ull nx;
			cin>>nx;
			if(mymap.find(nx)==mymap.end())
			{
				ans++;
				mymap[nx] =1;
			}
			else{
			ans =1;mymap.erase(mymap.begin(),mymap.end());	}
			nas = max(ans,nas);
		}
		cout<<nas<<endl;
		n--;
	}
	return 0;
}