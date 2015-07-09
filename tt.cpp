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
#define INF 1<<30
using namespace std;

int isIntegerPalindrome(int a) {

vector<int>ans;
    while(a!=0)
    {
         
        ans.push_back(a%10);
		cout<<a%10<<" ";a= a/10;
    }
	cout<<endl;
    bool bt = true;
    int x =0;
    int y = ans.size()-1;
    while(x<y && bt)
    {
        if(ans[x] != ans[y])
            bt =false;
        else
        {
                x++;
            y--;
        }      
    }
    if(bt)
        return 1;
    else
        return 0;
}
int main()
{
	int x; 
	cin>>x;
	cout<<isIntegerPalindrome(x)<<endl;
	return 0;
	}
	