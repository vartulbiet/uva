#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#define REP(i, a, b) for ( int i = int(a); i <= int(b); i++ )
#define PB push_back
#define MP make_pair
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define MAXN 1000
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define INF 1<<30
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void reverseWords(string &s) {
        string ans;
        vector<string>res;
        int last =0;
        for(int i =0;i<s.size();i++)
        {
            if(s[i] ==' ')
            {
                string f =s.substr(last,i-last);
                if(f != "")
                {
                cout<<f<<"--"<<endl;
                
                res.push_back(f);
                }
                last = i+1;
            }
        }
        string y = s.substr(last,s.size()-last);
        if(y != "")
        res.push_back(y);
        reverse(res.begin(),res.end());
        
             s.erase(s.begin(),s.end());
        for(int i =0;i<res.size();i++)
            cout<<res[i]<<"~~~"<<endl;
        for(int i =0;i<res.size()-1;i++)
        {
            s +=res[i];s+=" ";
        }
        s+=res[res.size()-1];
    }
int main()
{
    string s =" ";
    reverseWords(s);
    cout<<s<<"--"<<endl;
    return 0;
}