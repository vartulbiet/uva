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
		string s;
		int i =1;
		getline(cin,s);
	while(s!="#")
	{
		if(s=="HELLO")
		cout<<"Case "<<i++<<": "<<"ENGLISH"<<endl;
		else if(s=="HOLA")
		cout<<"Case "<<i++<<": "<<"SPANISH"<<endl;
		else if(s=="BONJOUR")
		cout<<"Case "<<i++<<": "<<"FRENCH"<<endl;
		else if(s=="HALLO")
		cout<<"Case "<<i++<<": "<<"GERMAN"<<endl;
		else if(s=="ZDRAVSTVUJTE")
		cout<<"Case "<<i++<<": "<<"RUSSIAN"<<endl;
		else if(s=="CIAO")
		cout<<"Case "<<i++<<": "<<"ITALIAN"<<endl;
		else
		cout<<"Case "<<i++<<": "<<"UNKNOWN"<<endl;
		getline(cin,s);
	}
	return 0;
}