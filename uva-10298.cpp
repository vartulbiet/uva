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
	getline(cin,s);
	while(s!=".")
	{
		string sub;int nas =1;
		int h = s.size();
		
		for(int i =2;i<=h;i++)
		{
			if(h%i == 0)
			{
				int  L= h/i;
				int k =L;
				for( k =L;k<h;k++)
				{
				if(s[k] != s[k%L])
				{
					break;
				}
				}
				if(k==h)
				{
				nas =max(nas,i);
				}
			}
		}
		cout<<nas<<endl;
		getline(cin,s);
	}
}