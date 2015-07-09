#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;
vector<bool>primes(1000000);
void get_primes()
{
	primes[0]=false;
	primes[1] = false;
	primes[2] = true;
	primes[3] = true;
	for(int i =4;i<1000000;i++)
	{
		if(i%2==0)
		primes[i]= false;
		else
		{
			int x = sqrt(double(i));
			primes[i] = true;
			for(int k =2;k<=x;k++)
			{
				if(i%k==0)
				{
					primes[i] =false;
					break;
				}
			}
		}
	}
}
int main()
{
	int n =0;
	cin>>n;
	get_primes();
	vector<int>jj;
	int i =4;
	jj.push_back(1);
	jj.push_back(2);
	jj.push_back(3);
	while(jj.size()!=50)
	{
	bool t = true;
		int z = sqrt(double(i))+1;
		for(int j =2;j<=z;j++)
		{
			if(primes[j]==true)
			{
				if(!(j==2 ||j==3 ||j==5 ||j==7))
					{t = false;break;}
			}

		}
		if(t)
		jj.push_back(i);
	}
	cout<<jj[n];
	return 0;
}