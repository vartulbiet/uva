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
map<char,char>mymap;

int main()
{
	mymap['A'] ='2';mymap['B'] ='2';mymap['C'] ='2';
	mymap['D'] ='3';mymap['E'] ='3';mymap['F'] ='3';
	mymap['G'] ='4';mymap['H'] ='4';mymap['I'] ='4';
	mymap['J'] ='5';mymap['K'] ='5';mymap['L'] ='5';
	mymap['M'] ='6';mymap['N'] ='6';mymap['O'] ='6';
	mymap['P'] ='7';mymap['R'] ='7';mymap['S'] ='7';
	mymap['T'] ='8';mymap['U'] ='8';mymap['V'] ='8';
	mymap['W'] ='9';mymap['X'] ='9';mymap['Y'] ='9';
	int n = 0;
	cin>>n;
	while(n>0)
	{
		int t =0;
		cin>>t;
		string s;
		map<string,int>mymap1;
		for(int i =0;i<t;i++)
		{
			cin>>s;
		//	cout<<s<<endl;
			string ans;
			for(int h =0;h<s.size();h++)
			{
				if(s[h]>='0' &&s[h]<='9')
				ans.PB(s[h]);
				else if(s[h]=='-');
				else
				ans.PB(mymap[s[h]]);	
			}
			ans.insert(3,"-");
		//	cout<<ans<<endl;
		if(mymap1.find(ans)==mymap1.end())
		mymap1[ans]=1;
		else
			mymap1[ans]++;
		}
		bool bt =false;
		vector<string>vec;
		for(std::map<string,int>::iterator it= mymap1.begin();it!=mymap1.end();it++)
		{
			if(it->second>1)
			{
			bt= true;
			vec.PB(it->first);}
		}
		if(!bt)
		cout<<"No duplicates."<<endl;
		else
		{
			sort(vec.begin(),vec.end());
			for(int j =0;j<vec.size();j++)
			cout<<vec[j]<<" "<<mymap1[vec[j]]<<endl;
		}
		if(n!=1)
		cout<<endl;
		n--;
	}
	return 0;
	
}