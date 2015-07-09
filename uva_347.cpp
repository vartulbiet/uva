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
int turnaround(int x)
{
	vector<int>arr;
	while(x!=0)
	{
		arr.PB(x%10);
		x=x/10;
	}
	//cout<<sum<<endl;
	reverse(arr.begin(),arr.end());
	bool oneUsed[10];bool bt = true;memset(oneUsed,false,10);
	for(int i = 0;i<arr.size();i++)
	{
		if(oneUsed[arr[i]]== false &&(arr[i]%arr.size()==1 || arr[i]==1))
		oneUsed[arr[i]]= true;
		//else if(oneUsed==true && arr[i]!=1&& arr[i]%arr.size()==1)
		//bt= true;
		else
		{
			bt =false;
			break;
		}
	}
	if(bt)
	return true;
	else
	return false;
	/*for(int i =0;i<arr.size();i++)
	cout<<arr[i];
	cout<<endl;
	return true;*/
	
}
int main()
{
	int n =0;
	cin>>n;
	while(n!=0)
	{
		while(!turnaround(n))
		{
			n++;
		}
		cout<<n<<endl;
		cin>>n;
	}
	return 0;
}