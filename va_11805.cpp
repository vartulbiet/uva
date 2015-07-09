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
	int n =0;
	cin>>n;
	int it =0;
	while(n!=0)
	{
		int p,q,r;
		cin>>p>>q>>r;
		vector<int>arr(p);
		for(int i =0;i<p;i++)
		{
			arr[i] = q++;
			//cout<<arr[i]<<" ";
			if(q>p)
			q =1;
		}
		int ans = r%p;
		cout<<"Case "<<++it<<": "<<arr[ans]<<endl;
		n--;
	}
	return 0;
}