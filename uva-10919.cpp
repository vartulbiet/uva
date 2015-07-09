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
#include <queue>
#include <sstream>
#include <iostream>
#include<string.h>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define pi 3.141592653589793
using namespace std;
int main()
{
	int a,b;
	cin>>a;
	while(a!=0)
	{
		cin>>b;
		map<int,bool>mymap;
		for(int i =0;i<a;i++)
		{
			int x;
			cin>>x;
			mymap[x] = true;
		}
		bool tt = true;
		for(int y =0;y<b;y++)
		{
			int m,n;
			int k =0;
			cin>>m>>n;
			for(int i =0;i<m;i++)
			{
				int z;
				cin>>z;
				if(mymap[z] == true)
				k++;
			}
			if(k<n)
			{
				tt = false;
			}
		}
		if(tt)
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
		cin>>a;
	}
	return 0;
}