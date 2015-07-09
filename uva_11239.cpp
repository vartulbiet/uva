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
	string s;
	getline(cin,s);
		map<string,int>sub;
		map<string,string >student;
		string subb;
	while(s!="0")
	{
		if(s=="1")
		{
			vector<pair<int,string> >vec;
			for(std::map<string,int>::iterator it = sub.begin();it!=sub.end();it++)
			{
				int y =it->second*-1;
			vec.PB(make_pair(y,it->first));
			}
			sort(vec.begin(),vec.end());
			for(int i =0;i<vec.size();i++)
			{
				int z = vec[i].first*-1;
				if(vec[i].second!="vartul")
				cout<<vec[i].second<<" "<<z<<endl;
			}
			sub.erase(sub.begin(),sub.end());student.erase(student.begin(),student.end());
		}
		else
		{
			if(s[0]>=65 && s[0]<=90)
			{
				//cout<<sub[subb]<<endl;
				sub[s]=0;
				subb  =s;
			}
			else
			{
				if(student.find(s)==student.end())
				{
					student[s]=subb;
					sub[subb]++;
				}
				else
				{
					if(student[s] !=subb && student[s]!="vartul")
					{sub[student[s]]--;student[s]="vartul";}
					if(sub[student[s]]<0 && student[s]!="vartul")
					sub[student[s]]=0;
				}
			}
		}
		getline(cin,s);
	}
	return 0;
}