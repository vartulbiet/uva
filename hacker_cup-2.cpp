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
#define pi 3.141592653589793
using namespace std;
int main()
{
	int n =0;
	cin>>n;int tt =1;
	while(n>0)
	{
		int a,b,c;
		cout<<"Case #"<<tt++<<": ";
		cin>>a>>b>>c;
		if(a>b)
		cout<<a-b+c<<endl;
		else
		{
			if(c<a)
			cout<<c<<endl;
			else if(c%a==0|| b%a == 0)
			cout<<c<<endl;
			else
			{
				int mac =1<<30;int holk;
				for(int j =1;j<a;j++)
				{
					int h =b/j;
					int g =b%j;
					if(g<h)
					{
					int kk = c+1+a-j-1;
					if(mac>kk)
					{
						mac =c+1+a-j-1;
						holk =j;
					}
					}
				}
				cout<<mac<<endl;
			}
		}
		n--;
	}
	return 0;
}