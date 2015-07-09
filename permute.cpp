#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,bool>mymap;
void permute(string x)
{
	if(mymap.find(x) ==mymap.end())
	{
		mymap[x] =true;
	for(int i =0;i<x.size()-1;i++)
	{
		char temp =x[i+1];
		x[i+1] = x[i];
		x[i] = temp;
		permute(x);
		temp = x[i+1];
		x[i+1] = x[i];
		x[i] = temp;
	}
	}else
	return;
}

int main()
{
	string x;
	cin>>x;
	permute(x);
	for(std::map<string,bool>::iterator it =mymap.begin();it!=mymap.end();it++)
	{
		cout<<it->first<<endl;
	}
	cout<<mymap.size()<<endl;
	return 0;
}