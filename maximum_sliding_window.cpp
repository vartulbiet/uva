//max sliding window.
#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

void maximum_sliding(int*arr,int size,int win)
{
	priority_queue<int>q;
	for(int i=0;i<win;i++)
	q.push(arr[i]);
	cout<<q.top()<<"  ";
	q.pop();
	for(int i =win;i<=size;i++)
	{
	q.push(arr[i]);
	cout<<q.top()<<" ";
	q.pop();
	}
}
int main()
{
	int arr[]={3,-1,2,1,4,5,-3,-2,1,2};
	int size  = sizeof(arr)/sizeof(int);
	int window =3;
	//int*result;
	maximum_sliding(arr,size,window);
	return 0;
}