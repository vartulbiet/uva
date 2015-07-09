#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int i=1000;
	int primenumbers[1000];
	primenumbers[0] =1;
	primenumbers[1] =2;
	primenumbers[2] =3;
	int index =3;
	for(int i=4;i<=1000;i++)
		{
			bool val = false;
			int j =sqrt(i);
			for(int k =2;k<=j;k++)
			{
				if(i%k ==0)
				{
				val = true;
				break;
				}
			}
			if(val == false)
			primenumbers[index++] = i;
		}
	
	int input;
	cin>>input;
	int count  =0;
	cin>>count;
	int k =0;
	int counter =0;
	cout<<input <<" "<<count<<": " ;
	while(primenumbers[k]<=input)
	{
		counter++;
		k++;
	}
	if(k<count)
	{
		for(int i=0;i<k;i++)
			cout<<primenumbers[i]<<" ";
		cout<<endl;
	}
	else
	{
			int m = (k+1)/2 - count;
			int j = m;
			int g =0;
			if(k%2!=0)
			{
			while(g<2*count-1)
			{
				cout<<primenumbers[j++]<<" ";
				g++;
			}
			}
			else
			{
				while(g<(2*count))
			{
				cout<<primenumbers[j++]<<" ";
				g++;
			}
			}
			cout<<endl;
	}
}