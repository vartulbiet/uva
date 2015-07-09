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
using namespace std;

int main()
{
	int a,b,c;map<int,int>mymap;
	for(int i =0;i<10000;i++)
	mymap[i] =0; int ma =0;int mi =100000;
	while(scanf("%d%d%d",&a,&b,&c)==3)
	{
		for(int i =a;i<c;i++)
		{
		if(mymap.find(i)==mymap.end() || mymap[i]<b)
			mymap[i] = b;
			ma =max(ma,i);
			mi =min(mi,i);
		}
		ma =max(ma,c);
		mi= min(mi,c);
	}int prev =-1;
	int tt =0;
	for(int i =mi;i<=ma;i++)
		{
			if(mymap[i]!=prev){
			if(tt!=0)
			cout<<" ";
			tt++;
			cout<<i<<" "<<mymap[i];
			prev= mymap[i];}
		}
		cout<<endl;
	return 0;
}