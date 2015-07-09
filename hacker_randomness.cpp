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
#define MP make_pair
#define INF 1<<30
using namespace std;
int generate_all_substrings(string s)
{
	set<string> substrings;
	string substring = "";
    string::iterator iter;
	    for(iter = s.begin(); iter != s.end(); ++iter, substring = "")
	    {
	        for(string::iterator iter_2 = iter; iter_2 != s.end(); ++iter_2)
	        {
	            substring += *iter_2;
	            substrings.insert(substring);  
	        }      
	        substrings.insert(substring);              
	    }
    cout<<substrings.size();
	return substrings.size();
	}
int main()
    {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i =0;i<k;i++)
    {
      int x,y;
        cin>>x>>y;
        s[x-1] = y;
        cout<<generate_all_substrings(s)<<endl;
        cout<<s<<endl;
    }
    return 0;
}