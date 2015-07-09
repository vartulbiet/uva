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
int main()
{
	int w,h,n;
	cin>>w>>h>>n;
	while(w || h || n)
	{
		int **matrix = (int**)malloc(sizeof(int*)*w);
		for(int i =0;i<w;i++)
		matrix[i] = (int*)malloc(sizeof(int)*h);
	
		for(int i =0;i<w;i++)
			for(int j =0;j<h;j++)
				matrix[i][j] = 0;

		for(int i =0;i<n;i++)
		{
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			 if ( a > c && b <= d ) swap (a, c);
 
    else if ( a >= c && b >= d ) {
        swap (a, c);
        swap (b, d);
    }
 
    else if ( a <= c && b > d ) swap (b, d);
			for(int i = a-1;i<=c-1;i++)
			for(int j = b-1;j<=d-1;j++)
			matrix[i][j] = 1;
		}

		int c =0;
		for(int i =0;i<w;i++)
		for(int j =0;j<h;j++)
		{
			//cout<<&matrix[i][j]<<" ";
			if(matrix[i][j] == 0)
			c++;
		}
		if(c ==0)
		cout<<"There is no empty spots."<<endl;
		else if(c ==1)
		cout<<"There is one empty spot."<<endl;
		else
		cout<<"There are "<<c<<" empty spots."<<endl;
		cin>>w>>h>>n;
	}
	return 0;
}