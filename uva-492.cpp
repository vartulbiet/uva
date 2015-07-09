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
		int last =0;
		for(int i =0;i<s.size();i++)
		{
			if(!((s[i]>='a' && s[i]<='z') ||(s[i]>='A' && s[i]<='Z')))
			{
				string h = s.substr(last,i-last);
				//cout<<h<<endl;
				if(h[0]=='a' || h[0]=='e' || h[0]=='i' || h[0] =='o' || h[0]=='u' || h[0]=='A' || h[0]=='E' || h[0]=='I' || h[0] =='O' || h[0]=='U')
				h+="ay";
				else if((h[0]>='a' && h[0]<='z') ||(h[0]>='A' && h[0]<='Z'))
				{
					string j = h.substr(0,1);
					string g= h.substr(1,h.size()-1);
					g+=j;
					h =g;
					h+="ay";
				}
				cout<<h<<s[i];
				last = i+1;
			}
		}
		cout<<endl;
	}
	return  0;
}