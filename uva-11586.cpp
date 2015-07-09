#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;
int main()
{
	int n =0;
	cin>>n;
	string s;
		getline(cin,s);
	while(n>0)
	{
		string s;
		getline(cin,s);
		int x =0;int y =0;
		for(int i =0;i<s.size();i++)
		{
			if(s[i]=='M')
			x++;
			if(s[i]=='F')
			y++;
		}
		if(x==y && x!=1 && y!=1)
		cout<<"LOOP"<<endl;
		else
		cout<<"NO LOOP"<<endl;
		n--;
	}
	return 0;
}