#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#define MAX 1<<29
using namespace std;

int main()
{

   
    long long s,d,ans,all,last5;
    int i,j,k;
    while(scanf(" %lld %lld",&s,&d)==2){
        ans = -MAX;
        if(d>4*s)    ans = 10*s-2*d;
        else if(2*d>3*s)    ans = 8*s-4*d;
        else if(3*d>2*s)    ans = 6*s-6*d;
        else if(4*d>s)        ans = 3*s-9*d;
        else    ans = -12*d;
        if(ans>0)
            printf("%lld\n",ans);
        else
            printf("Deficit\n");
    }
   
    return 0;
}