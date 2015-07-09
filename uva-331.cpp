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
bool compare(vector<int>vector_1,vector<int>vector_2)
{
	if(vector_1.size()==vector_2.size())
	{
		for(int i =0;i<vector_1.size();i++)
		{
			if(vector_1[i]!=vector_2[i])
			return false;
		}
		return true;
	}
	else
	return false;
}
int swaps;
map<vector<int>,bool>mymap;
void swap(int*x,int*y)
{
	int temp;
	temp =*x;
	*x= *y;
	*y =temp;
}
void recurse(vector<int>sorted_vec,vector<int>input)
{
	//	for(int i =0;i<input.size();i++)
		//	cout<<input[i]<<" ";
			//cout<<endl;
		if(compare(sorted_vec,input))
		{
			swaps++;
			return;
		}
		else
		{
			for(int i =0;i<input.size()-1;i++)
			{
				vector<int>arr = input;
				if(arr[i]>arr[i+1])
				{
				swap(&arr[i],&arr[i+1]);
				recurse(sorted_vec,arr);
				}
			}
			return;
		}
}

int main()
{
	int n = 0;
	cin>>n;int kase =1;
	while(n!=0)
	{
		vector<int>vec;
		swaps =0;
		for(int i =0;i<n;i++)
		{
			int x =0;
			cin>>x;
			vec.PB(x);
		}
		vector<int>sorted_vec = vec;
		sort(sorted_vec.begin(),sorted_vec.end());
		if(!compare(sorted_vec,vec))
		recurse(sorted_vec,vec);
		cout<<"There are "<<swaps<<" swap maps for input data set "<<kase++<<"."<<endl;
		//cout<<swaps<<endl;
		cin>>n;
	}
	return 0;
}