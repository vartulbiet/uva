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
#include<assert.h>
using namespace std;
int main()
{
int m,n,p;
scanf("%d%d%d",&m,&n,&p);
vector<map<int,int> > vect(m+1);
int k =0;
while(p--)
{
int x,y;
scanf("%d%d",&x,&y);
/*map<int,int>mapp =vect[x];
if(mapp.find(y) == mapp.end())
mapp[y] =1;
else
mapp[y]++;
vect[x] = mapp;*/
//instead of this you can do it like this
if(vect[x].find(y) == vect[x].end()) {
vect[x].insert(make_pair(y, 1));
} else {
vect[x][y]++;
}
}
for(int i =1;i<=m;i++)
{
if(vect[i].size()==0)
{
printf("%d\n",n-1);
}
else
{
//map<int,int>my =vect[i]; can avoid assignment
int y = n-1;bool ct =true;
//assert(my.size()<=10000 && m<=10000);
//assert();
for(std::map<int,int>::iterator bt = vect[i].begin();bt != vect[i].end() && ct;bt++)
{
int col = bt->first;
int val =bt->second;
int nxt_col = col+1;
int nxt_val =0;
std::map<int,int>::iterator gt = bt;
gt++;

if(gt != vect[i].end() && gt->first == nxt_col)
nxt_val = vect[i][nxt_col];

if(col !=n)
{
if(col+val>nxt_val+nxt_col)
ct =false;
}
if(col == n)
{
y+=val;
}
if(col ==1)
y-=val;
}
if(ct)
printf("%d\n",y);
else
printf("-1\n");
}
}
return 0;
}