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
    while(n--)
        {
        string s;
        cin>>s;
        int i = 0;
        int j = s.size()-1;
        bool bt=false;
        while(i<j)
            {
            if(s[i] == s[j])
                {
                i++;j--;
				cout<<s[i]<<"---"<<s[j]<<endl;
            }
            else
                {
				cout<<s[i]<<" "<<s[j]<<endl;
                if(s[i+1] == s[j])
				{
                    cout<<i<<endl;
					cout<<s.substr(0,i);
					
				}
                else
                    cout<<j<<endl;
                bt = true;
                break;
            }
        }
        if(!bt)
            cout<<"-1"<<endl;
    }
    return 0;
}