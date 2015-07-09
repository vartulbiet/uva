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
#define INF 1<<30
using namespace std;
long long int powert(long long int y,long long int x)
{
	if(x == 1)
	return y;
	else
	return y*powert(y,x-1);
}
int main()
{
	int n =0;
	cin>>n;
	int tt =1;
	while(n--)
	{
		string s;
		cin>>s;
		int y = s.size();
		map<char,int>arr;
		arr['A'] = 0;arr['C'] = 1;arr['G'] = 2;arr['T'] = 3;
		long long int val =0;
		for(int i =0;i<y-1;i++)
		{
			val += (arr[s[i]]*powert(4,(y-i-1)));
		//	cout<<val<<endl;
		}
		val += arr[s[y-1]];
		cout<<"Case "<<tt++<<": ("<<y<<":"<<val<<")"<<endl;
	}
	return 0;
}