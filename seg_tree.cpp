#include <stdio.h>
#include <math.h>
#include<iostream>
#include<malloc.h>
using namespace std;
long long getMid(long long s, long long e) {  return s + (e -s)/2;  }
 
long long getSumUtil(long long *st, long long ss, long long se, long long qs, long long qe, long long index)
{

    if (qs <= ss && qe >= se)
        return st[index];
 

    if (se < qs || ss > qe)
        return 0;
 

    long long mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}
 

void updateValueUtil(long long *st, long long ss, long long se, long long i, long long diff, long long index)
{
    if (i < ss || i > se)
        return;
 
    st[index] = st[index] + diff;
    if (se != ss)
    {
        long long mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}
 

void updateValue(long long arr[], long long *st, long long n, long long i, long long new_val)
{

    if (i < 0 || i > n-1)
    {

        return;
    }
 

    long long diff = new_val - arr[i];
 
    // Update the value in array
    arr[i] = new_val;

    updateValueUtil(st, 0, n-1, i, diff, 0);
}
 

long long getSum(long long *st, long long n, long long qs, long long qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        return -1;
    }
 
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
long long min(long long x ,long long y)
{
	return x>y?y:x;
}
long long constructSTUtil(long long arr[], long long ss, long long se, long long *st, long long si)
{

    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 

    long long mid = getMid(ss, se);
    st[si] =  (constructSTUtil(arr, ss, mid, st, si*2+1)+
              constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}
 

long long *constructST(long long arr[], long long n)
{
    long long x = (long long)(ceil(log2(n))); //Height of segment tree
    long long max_size = 2*(long long)pow(2, x) - 1; //Maximum size of segment tree
    long long *st = new long long[max_size];
 

    constructSTUtil(arr, 0, n-1, st, 0);
 

    return st;
}
 

int main()
{
	long long n =0;
	cin>>n;
	long long t =0;
	cin>>t;
	long long *arr= (long long*)malloc(sizeof(long long)*n);
	
   for(long long i =0;i<n;i++)
   {
	long long tt;
	cin>>tt;
	arr[i] =tt;
   }

    long long *st = constructST(arr, n);
	for(long long i =0;i<t;i++)
	{
		char s;long long x;long long y;
		cin>>s>>x>>y;
		if(s=='S')
		cout<<getSum(st, n, x, y)<<endl;;
		if(s=='T')
		updateValue(arr, st, n, x, arr[x]-y);
		if(s=='G')
		updateValue(arr, st, n, x, arr[x]+y);
	}                                         
 
    return 0;
}