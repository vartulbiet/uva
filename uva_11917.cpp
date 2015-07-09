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
	int tc =1;
	cin>>n;
	while(n!=0)
	{
		int a =0;
		cin>>a;
		map<string,int>mymap;
		for(int i =0;i<a;i++)
		{
			string x;int val;
			cin>>x>>val;
			mymap[x]  =val;
		}
		int d=0;
		cin>>d;
		string z;
		cin>>z;
		cout<<"Case "<<tc++<<": ";
		if(mymap[z]==0 || mymap[z]>d+5)
		cout<<"Do your own homework!"<<endl;
		else
		{
			if(mymap[z]>d && mymap[z]<=d+5)
			cout<<"Late"<<endl;
			else
			cout<<"Yesss"<<endl;
		}
		n--;
	}
	return 0;
}