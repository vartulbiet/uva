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
char arr[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
map<pair<int,string>, bool>mymap;
string vecToString(vector<char>c)
{
	string f;
	for(int i =0;i<c.size();i++)
	f+=c[i];
	return f;
}
void recurse(int k,vector<char>vec)
{
	if(k==5)
	return;
	else
	{
		string x = vecToString(vec);
		if(mymap.find(make_pair(x.size(),x))==mymap.end())
		{
			mymap[make_pair(x.size(),x)] = true;
			for(int i =0;i<26;i++)
			{
				vector<char>temp = vec;
				if(temp[temp.size()-1]<arr[i])
				{
				temp.PB(arr[i]);
				recurse(k+1,temp);
				}
			}
		}
	}
}
int main()
{
	int n =5;
	for(int i =0;i<26;i++)
	{
		vector<char>temp;
		temp.PB(arr[i]);
		recurse(0,temp);
	}
	map<string,int>count;
	int y =1;
	for(std::map<pair<int,string>,bool>::iterator it =mymap.begin();it!=mymap.end();it++)
	{
		string s = it->first.second;
		//cout<<s<<endl;
		count[s]= y++;
	}
	string h;
	while(getline(cin,h))
	{
		if(count.find(h)==count.end())
		cout<<"0"<<endl;
		else
		cout<<count[h]<<endl;
	}
	return 0;
}