#include <iostream>
#include <complex>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
using namespace std;
typedef complex<double> point;
 
#define PI 3.141592653589793
#define EPS 0.0000000001
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define cross(a,b)  ((conj(a)*b).imag())
#define dot(a,b)  ((conj(a)*b).real())
#define length(a)  hypot((a).X,(a).Y)
#define lenSqr(a)  dot(a,a)
#define len(v) ((int)v.size)
#define normalize(a)  (a)/(lenght(a))
int GCD(int i,int j)
{
    if(j==0)
       return i;
    else return GCD(j,i%j);
}
double getArea(vector<point> &poly)
{
    double area = 0;
    int n = (int)poly.size();
    for (int i=0;i<n;i++)
        area+=cross(poly[i],poly[(i+1)%n]);
    area = fabs(area/2);
    return area;
 
}
 
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        vector<point> poly;
int x,y;
        for (int i=0;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            point p(x,y);
            poly.push_back(p);
        }
        long long b = 0;
 
        double area = getArea(poly);
		cout<<area<<endl;
        poly.push_back(poly[0]);
        n++;
        for (int i=0;i<n-1;i++){
            b+=GCD(fabs(poly[i].X-poly[i+1].X),fabs(poly[i].Y-poly[i+1].Y))+1;
        }
    b-=n-1;
	cout<<b<<endl;
        long long i = floor(area)+1-b/2;
        cout << i << endl;
    }
    return 0;
}