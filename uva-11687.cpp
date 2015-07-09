#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;
int get_count(int n)
{
	int g =1;
	while(n>9)
	{
	g++;
	n =n/10;
	}
	return g;
}
int main()
{
	string s;
	getline(cin,s);
	while(s!="END")
	{
		int n =s.size();
		if(s=="1")
		cout<<'1'<<endl;
		else
		{
		int t =1;
		while(n!=1)
		{
			n = get_count(n);
			t++;
		}
		cout<<t+1<<endl;
		}
		getline(cin,s);
	}
	return 0;
}