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
int main()
{
	int n =0;
	cin>>n;
	string x,y;
	getline(cin,x);
	map<string,string>mymap;
	while(n>0)
	{
		getline(cin,x);getline(cin,y);
		mymap[x]= y;
		n--;
	}
	int m =0;
	cin>>m;
	getline(cin,x);
	while(m>0)
	{
		getline(cin,x);
		cout<<mymap[x]<<endl;
		m--;
	}
	return 0;
	
}