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
	
	while(getline(cin,s))
	{
		int last =0;
		for(int i =0;i<s.size();i++)
		{
			
			if(s[i]==' ')
			{
				for(int h =i-1;h>=last;h--)
				cout<<s[h];
				cout<<" ";
				last =i+1;
			}
		}
	//	cout<<"-------------------------------";
		for(int h =s.size()-1;h>=last;h--)
				cout<<s[h];
				cout<<endl;
		
	}
	return 0;
}