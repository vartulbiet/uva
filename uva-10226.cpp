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
	char x[30];
	gets(x);
	gets(x);
	while(n>0)
	{
		
		char*p;
		map<string,int>mymap;
		int total =0;
		while(gets(x))
		{
			p= (char*)malloc(sizeof(char)*strlen(x));
			//for(int i =0;i<strlen(x);i++)
			//cout<<x[i];
			//cout<<endl;
			if(strlen(x)==0)
			break;
			p=x;
			string h =p;
		//	cout<<h;
			mymap[h]++;
			total++;
		}
		for(std::map<string,int>::iterator it= mymap.begin();it!=mymap.end();it++)
		{
			cout<<it->first<<" ";
			double d= ((double)it->second/(double)total)*100;
			printf("%.4lf\n",d);
		}
		if(n!=1)
		cout<<endl;
		n--;
	}
	return 0;
}