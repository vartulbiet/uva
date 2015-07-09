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
	int h;
	int c;

int main()
{
	int tc = 0;
	scanf("%d",&tc);
	
	while(tc>0)
	{
		vector<int> arr;
		scanf("%d%d",&c,&h);
		for(int i =0;i<c-h;i++)
		arr.PB(0);
		for(int j =c-h;j<c;j++)
		{
			arr.PB(1);
		}
		 do {
		for(int i =0;i<c;i++)
		cout<<arr[i];
		cout<<endl;
			} while ( std::next_permutation(arr.begin(),arr.end()) );
			if(tc!=1)
			cout<<endl;
		tc--;
	}
	return 0;
}