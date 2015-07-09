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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
struct point{
int x;
int y;
};
void intersection(point p1,point q1,point p2,point q2)
{
		double sl = (q1.y-p1.y)/(q1.x-p1.x);
		double c1 = p1.y - sl*p1.x;
		double sl2 = (q2.y-p2.y)/(q2.x-p2.x);
		double c2 = p2.y - sl2*p2.x;
		double aa = (c2-c1)/(sl-sl2);
		double bb = sl*aa+c1;
		cout<<aa<<" "<<bb;
}
int check_segment(point a,point r,point b)
{
	if(r.x>=min(a.x,b.x)&& r.x<=max(a.x,b.x) && r.y>=min(a.y,b.y)&& r.y<=max(a.y,b.y))
	return true;
	else
	return false;
}
int orientation(point a,point b,point r)
{
	int u = (b.y-a.y)*(r.x-b.x)-(r.y-b.y)*(b.x-a.x);
	if(u==0)
	return u;
	if(u>0)
	return 1;
	else
	return 2;
}
int check_intersect(point p1,point q1,point p2,point q2)
{
	int a = orientation(p1,q1,p2);
	int b = orientation(p1,q1,q2);
	int c = orientation(p2,q2,p1);
	int d = orientation(p2,q2,q1);
	if(a!=b && c!=d)
		return 1;
	if(a == 0 && check_segment(p1,p2,q1))
		return 2;
	if(a == 0 && check_segment(p1,q2,q1))
		return 2;
	if(a == 0 && check_segment(p2,p1,q2))
		return 2;
	if(a == 0 && check_segment(p2,q1,q2))
		return 2;
	return 0;
}
int main()
{
	point p1,q1;
	point p2,q2;
	int n =0;
	cin>>n;
	cout<<"INTERSECTING LINES OUTPUT"<<endl;
	while(n--)
	{
	cin>>p1.x>>p1.y>>q1.x>>q1.y;
	cin>>p2.x>>p2.y>>q2.x>>q2.y;
	int x = check_intersect(p1,q1,p2,q2);
	//cout<<x<<endl;
	if(x == 0)
	cout<<"NONE";
	else if(x == 1)
	{
		cout<<"POINT ";
		intersection(p1,q1,p2,q2);
	}
	else
	{
		cout<<"LINE";
	}
	cout<<endl;
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}