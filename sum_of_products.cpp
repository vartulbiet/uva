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
#define MOD 100003
int main()
{
    int n =0;
    cin>>n;
    vector<int>input(n);
    for(int i =0;i<n;i++)
    {
        cin>>input[i];
    }
    
    vector<ll>ans(n+1);
    for(int i =0;i<n+1;i++)
        ans[i] = 0;
    vector<ll>arr(n+1);
    vector<vector<ll> >table;

    table.PB(arr);
    table.PB(arr);

      for(int i =0;i<2;i++)
        table[i][0] = 0;
    for(int j =0;j<n+1;j++)
        table[0][j] = 1;

    int k =1;
  int tear = 1;
  vector<ll>are(n+1);
    for(int i =1;i<=n;i++)
    {
        for(int j =tear;j<=n;j++)
         {
            table[k][j] = ((table[k-1][j-1])%MOD*(input[j-1])%MOD)%MOD;
            table[k][j] += table[k][j-1];
            table[k][j]%= MOD;
        }
        arr[i] = table[k][n];
 for(int j=0;j<n+1;j++)
            cout<<table[k][j]<<" ";
        cout<<endl;
        table[k-1] =are;
        for(int j =0;j<tear;j++)
            table[k-1][j] = 0;
        for(int j=tear;j<=n;j++)
            table[k-1][j] = table[k][j];
        for(int j=0;j<n+1;j++)
            cout<<table[k-1][j]<<" ";
        cout<<endl;
        table[k] = are;
        tear = tear+1;
    }
    int q =0;
    scanf("%d",&q);
    while(q--)
        {
        int y =0;
        scanf("%d",&y);
        cout<<arr[y]<<endl;
    }
    return 0;
}