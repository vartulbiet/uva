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
bool checkPrime(int t)
{
	if(t==1 || t==2 || t==3 || t==5)
	return true;
	if(t%2==0)
	return false;
	else
	{
		int y = sqrt(t);
		for(int i =2;i<=y+1;i++)
		{
			if(t%i==0)
			return false;
		}
		return true;
	}
}

int main()
{
	string s;
	while(getline(cin,s))
	{	
		int val =0;
		for(int i =0;i<s.size();i++)
		{
			if(s[i]>='a'&& s[i]<='z')
			val += s[i]-'a'+1;
			else
			val += s[i]-'A'+27;
		}
		bool ans = checkPrime(val);
		if(ans)
		cout<<"It is a prime word."<<endl;
		else
		cout<<"It is not a prime word."<<endl;
	}
	return 0;
}