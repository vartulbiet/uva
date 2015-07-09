#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<stack>
#include<map>
#include<list>
#include<queue>
#include<string>
#include <algorithm>
#include<stdlib.h>
#include<math.h>
#define SIZE sizeof(arr)/sizeof(long long)
#define FEL(i,a,b) for(long long i=a;i<b;i++)
#define INF 1<<10
using namespace std;
int main()
{
	int n =0;
	cin>>n;
	string s;
	getline(cin,s);
	while(n>0)
	{
		getline(cin,s);
		if(s=="1" || s=="4" || s=="78")
		cout<<"+"<<endl;
		else if(s[s.size()-2]=='3' && s[s.size()-1]=='5')
		cout<<"-"<<endl;
		else if(s[0] =='9' && s[s.size()-1] == '4')
		cout<<"*"<<endl;
		else if(s[0] =='1' && s[1]=='9' && s[2]=='0')
		cout<<"?"<<endl;
		n--;
	}
	return 0;
}