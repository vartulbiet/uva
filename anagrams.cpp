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
#define ll  long long 
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;

void anagrams(char*x,int s,int n)
{
	for(int i =0;i<n;i++)
	cout<<x[i];
	cout<<endl;
	for(int i = s+1;i<n;i++)
	{
		char z = x[s];
		x[s] = x[i];
		x[i]= z;
		anagrams(x,i,n);
		z = x[s];
		x[s]= x[i];
		x[i] =z;
		//anagrams(x,s+1,n);
	}
}
int main()
{
	char x[] = "top";
	//gets(x);
	int n =sizeof(x)/sizeof(char);
	int i =0;
	anagrams(x,0,n-1);
	return 0;
}