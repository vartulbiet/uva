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
	map<string,string>mymap;
	string a,b;
	char c[100];
	char*ptr;
	while(gets(c))
	{
		if(strlen(c)==0)
		break;
		ptr = strtok(c," ");
		a =ptr;
		ptr = strtok(NULL,"");
		b =ptr;
		mymap[b] =a;
		//getline(cin,a);
	}

	while(gets(c))
	{
		string s =c;
		if(mymap.find(s)!=mymap.end())
		cout<<mymap[s]<<endl;
		else
		cout<<"eh"<<endl;
	}
	return 0;
}