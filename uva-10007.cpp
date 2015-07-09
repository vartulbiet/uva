#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<vector>
#include <cstring>
#include <string>
#include <cctype>
#include <sstream>
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
#define INF 1<<30
using namespace std;

int main()
{
	int n;
	cin>>n;
	long long h =1;
	long long k =1;
	for(int i =2;i<=n;i++)
	{
		h *=(n+i);
		k =k*i;
	}
	cout<<h/k<<endl;
	return 0;
}