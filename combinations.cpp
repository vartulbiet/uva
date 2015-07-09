#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,bool>mymap;
void combinations(string x)
{
	if(mymap.find(x) ==mymap.end())
	{
		mymap[x] =true;
	for(int i =0;i<x.size();i++)
	{
		string y = x;
		y.erase(y.begin()+i);
		combinations(y);
	}
	}else
	return;
}

int main()
{
	string x;
	cin>>x;
	combinations(x);
	for(std::map<string,bool>::iterator it =mymap.begin();it!=mymap.end();it++)
	{
		cout<<it->first<<endl;
	}
	cout<<mymap.size()<<endl;
	return 0;
}