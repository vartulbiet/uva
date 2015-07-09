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
	string s;
	while(getline(cin,s))
	{
		if((s[0]>='a' && s[0]<='z')|| (s[0]>='A' && s[0]<='Z') || (s[0]==' '||s[0]=='?' || s[0]==';'|| s[0]==':' ||s[0]=='.' || s[0]==','|| s[0]=='!'))
		{
			string h;
			for(int i =s.size()-1;i>=0;i--)
			{
				int g = s[i]+0;
				if(g<100)
				{
				int x =g/10;
				int y = g-10*x;
					cout<<10*y+x;
				}
				else
				{
					int x =g/100;
				int y = g/10-10*x;
				int z = g-x*100-y*10;
					cout<<100*z+10*y+x;
				}
			
			}
			cout<<endl;
		}
		else
		{
			reverse(s.begin(),s.end());
			string kk;
			for(int k =0;k<s.size();k=k+2)
			{
				string hh =s.substr(k,2);
				//cout<<hh;
				int value = (hh[0]-'0')*10+(hh[1]-'0');
				if(value<32)
				{
				value+=100;
				k++;
				}
				//cout<<value<<endl;
				char g =(char)value;
				kk+=g;
			}
			cout<<kk<<endl;
		}
	}
	return 0;
}