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
vector<vector<int> >vec;
  int arr[] = {2,5,3,7,11,8,10,13,6};
vector<int>get_longest_n(int x)
{
	int k =0;int j =0;
	for(int i =0;i<vec.size();i++)
	{
		vector<int>temp = vec[i];
		if(temp.size()>k && temp[temp.size()-1] <= x)
		k =i;
	}
	vector<int>ans;
	for(int i =0;i<vec[k].size();i++)
	ans.PB(vec[k][i]);
	return ans;
}
	void delete_all(int n )
{
	for(int i =0;i<vec.size();)
	{
		vector<int>temp =vec[i];
		if(temp.size()==n)
		{
			vec.erase(vec.begin()+i);
			i =0;
		}
		else
		i++;
	}
}
vector<int>longest_vec()
{
	int k =0;
	vector<int>ans;
	for(int i =0;i<vec.size();i++)
	{
		if(vec[k].size()<vec[i].size())
		k = i;
	}
	vector<int>temp =vec[k];
	for(int i =0;i<temp.size();i++)
	ans.PB(temp[i]);
	return ans;
}
int LongestIncreasingSubsequenceLength(int n)
{
		vector<int>temp;
		temp.push_back(arr[0]);
		vec.push_back(temp);
		cout<<n;
	int lar =arr[0];
	int sma = arr[0];
	for(int i =1;i<n;i++)
	{
		int x =arr[i];
		if(x>lar)
		{
			lar = x;
			vector<int>temp =longest_vec();
			temp.PB(x);
			vec.PB(temp);
		}
		else if(x<sma)
		{
			sma =x;
			vector<int>temp;
			temp.PB(x);
			vec.PB(temp);
		}
		else
		{
			vector<int>temp =get_longest_n(x);
			temp.push_back(x);
			delete_all(temp.size());
			vec.PB(temp);
		}
	}
	int ans =0;int j =0;
	for(int i =0;i<vec.size();i++)
	{
	if(vec[i].size()>ans)
	{
	ans =vec[i].size();j =i;
	}
	}
	for(int k =0;k<vec[j].size();k++)
		cout<<vec[j][k]<<" ";
		cout<<endl;
		return ans;
}

int main() {
    int n = ARRAY_SIZE(arr);
 
    printf("Length of Longest Increasing Subsequence is %d\n",
            LongestIncreasingSubsequenceLength( n));
 
    return 0;
}