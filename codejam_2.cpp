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
#define ll long long int
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
map<ull,ull> arr[10005];

ull calculate(vector<ull>vec,ull ind,ull curr_e,ull max_e,ull get)
{
	if(ind == vec.size())
	return 0;
	if(arr[ind].find(curr_e) != arr[ind].end())
		return arr[ind][curr_e];
	if(curr_e>max_e)
	curr_e =max_e;
	ull max_gain =0;
	for(ull i =0;i<=curr_e;i++)
	{
		max_gain = max(max_gain,i*vec[ind]+calculate(vec,ind+1,curr_e-i+get,max_e,get));
	}
	return arr[ind][curr_e] = max_gain;
}
int main()
{
	ull n =0;
	cin>>n;
	ull tc =1;
	while(n--)
	{
		ull max_E,get,count;
		cin>>max_E>>get>>count;
		vector<ull>vec;
		for(ull i =0;i<count;i++)
		{
			ull c =0;
			cin>>c;
			vec.PB(c);
		}
		ull curr_e =max_E;
		ull ans =calculate(vec,0,curr_e,max_E,get);
		cout<<"Case #"<<tc++<<": "<<ans<<endl;
		for(int i =0;i<10005;i++)
		{
			map<ull,ull>mymap;
			arr[i] =mymap;
		}
	}
	return 0;
}