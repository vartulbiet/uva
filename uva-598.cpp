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
	map<vector<string> ,bool >mymap;
void print_as_desired(int g)
{
	cout<<"Size "<<g<<endl;
	vector< vector<string> >ans;
	for(std::map<vector<string> ,bool >::iterator it =mymap.begin();it!=mymap.end();it++)
	{
		vector<string> h =it->first;
		if(h.size()==g)
		{
			ans.PB(h);
		}
	}
	reverse(ans.begin(),ans.end());
	for(int k =0;k<ans.size();k++)
	{
		vector<string> t =ans[k];
		for(int i =0;i<t.size();i++){
		cout<<t[i];
		if(i!=t.size()-1)
		cout<<", ";
		}
		cout<<endl;
	}
}
int main()
{
	int n =0;
	cin>>n;
	string s;
		getline(cin,s);
		getline(cin,s);
	while(n>0)
	{
		int a,b;
		getline(cin,s);
		 if(s != "*") {
            if(sscanf(s.c_str(), "%d %d\n", &a, &b) == 1)
                b = a;
        } else a = 0, b = 0;
		string z;vector<string>vec;
		//cout<<s<<endl;
		while(getline(cin,z) && z.size()>0)
		{
		//	cout<<z<<"----";
			vec.PB(z);
		}
		reverse(vec.begin(),vec.end());
	int m = 1<<vec.size();

		for(int i =m-1;i>0;i--)
		{
			vector<string>temp;
			int h =i;
			//cout<<h<<endl;
			int tt =0;
			while(h>0)
			{
				if(h&1)
				{
					//cout<<vec[tt]<<"--"<<h<<"--";
					temp.PB(vec[vec.size()-1-tt]);
				}
				tt++;
				h>>=1;
			}
			//cout<<endl;
			mymap[temp] = true;
		}

			if(s=="*")
			{
				for(int i =1;i<=vec.size();i++)
				{
				print_as_desired(i);
				cout<<endl;
				}
			}
			else if(s.size()==1)
			{
				print_as_desired(a);
				cout<<endl;
			}
			else
			{
				for(int i =a;i<=b;i++)
				{
				print_as_desired(i);
				cout<<endl;
				}
			}
			n--;
			mymap.erase(mymap.begin(),mymap.end());
			if(n!=0)
			cout<<endl;
	}
	return 0;
}