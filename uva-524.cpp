#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<map>
#include<vector>
using namespace std;
int start =0;
map<int,bool>prime;

int* update_arr(int*arr,int value,int size)
{
	int*brr=(int*) malloc(sizeof(int)*(size-1));
	int j=0;
	for(int i=0;i<size;i++)
	{
		if(arr[i]!=value)
			brr[j++]=arr[i];
		//cout<<arr[i]<<"   "<<brr[j]<<endl;
	}
	return brr;
}
bool checkprime(int x)
{
	if(prime[x])
		return true;
	else
		return false;
}

void call_prime_circle(int *arr,int prev,int size,vector<int>printing,bool even)
{
	if(size ==0 && checkprime(printing.at(printing.size()-1)+printing[0]))
	{
		for(int i=0;i<printing.size()-1;i++)
			cout<<printing[i]<<" ";
		cout<<printing[printing.size()-1];
		cout<<endl;
	}
	else
	{
			int setVAL =1;
			if(even == true)
				{
					setVAL =0;
					even =false;
				}
			else
				even = true;
		for(int i=0;i<size;i++)
		{
			if(arr[i]%2 == setVAL && checkprime(prev+arr[i]))
			{
			int*brr = update_arr(arr,arr[i],size);
			printing.push_back(arr[i]);
			call_prime_circle(brr,arr[i],size-1,printing,even);
			printing.pop_back();
			}
		}
	}
}

int main()
{
	int d;
	prime[2] =true;
	prime[3] =true;
	prime[5] =true;
	prime[7] =true;
	prime[11] =true;
	prime[13] =true;
	prime[29] =true;
	prime[17] =true;
	prime[19] =true;
	prime[23] =true;
	prime[31] =true;
	int m =0;
	while(scanf("%d",&d)==1)
	{
		if(m)
			cout<<endl;
	int arr[20];
	for(int i=0;i<d;i++)
		arr[i]=i+1;
	vector<int>printing;
	start =arr[0];
	int*brr = update_arr(arr,arr[0],d);
	printing.push_back(arr[0]);
	cout<<"Case "<<++m<<":"<<endl;
	call_prime_circle(brr,arr[0],d-1,printing,true);
	}
	return 0;
}