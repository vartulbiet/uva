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
#define ll long long int
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
int main()
{
	int arr[] = { 5, 12, 14, 27, 3, 2, 13, 17, 7, 21 };
		int brr[] = { 3, 6, 2, 9, 7, 1, 4, 8, 5, 0 };
	for(int i =0;i<sizeof(brr)/sizeof(int);i++)
	{
		
		int index_A = brr[i];
		int temp =arr[index_A];
		int index_B = brr[index_A];
		arr[index_A] = arr[index_B];
		arr[index_B] = temp;
	}
	for(int k =0;k<sizeof(arr)/sizeof(int);k++)
	cout<<arr[k]<<endl;
	return 0;
}