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
typedef vector<int> vi;
typedef pair<int, int> ii;

map<int,int>mymap;

void do_parse(char word[])
{
	int x = 0;
	int i =0;
	while(word[i] != '\0')
	{
			if(( word[i]>='a' && word[i]<='z')|| (word[i]>='A' && word[i]<='Z'))
				x++;
			i++;
	}
	//cout<<word<<" "<<x<<endl;
	mymap[x]++;
}
void seperate(char word[])
{
	char arr[100];int j =0;int i =0;bool bt = false;
	//cout<<word<<" ===="<<endl;
	for(i =0;i<strlen(word);i++)
	{
		if(word[i] =='?'||word[i] =='!'||word[i]==','|| word[i]=='.')
		{
			arr[j] = '\0';
			//cout<<word<<endl;
			bt =true;
			do_parse(arr);
			j =-1;
		}
		else{
			arr[j] = word[i];
		bt=false;}
		j++;
	}
	arr[j] = '\0';
	if(bt == false)
		do_parse(arr);

}
int main()
{
	char input[100];
	char temp[100];
	//int i,j;
	strcpy(temp,"");
	while(scanf("%s",input) == 1)
	{
		//cout<<input<<endl;
		if(input[strlen(input) - 1] =='-')
		{
			strcpy(temp,input);
			continue;
		}
		if(!strcmp(input ,"#"))
		{
			for(std::map<int,int>::iterator it = mymap.begin();it!=mymap.end();it++)
			{
				cout<<it->first<<" "<<it->second<<endl;
			}
			cout<<endl;
			mymap.erase(mymap.begin(),mymap.end());
		}
		else if(strlen(temp))
		{
			int j =0;int i =0;
			//cout<<temp<<strlen(temp)<<endl;
			for(i = strlen(temp),j =0;input[j] != '\0';i++,j++)
			{
				temp[i] = input[j];
				//cout<<input[j];
			}
			temp[i] = '\0';	
			//printf("SEND: %s%s\n",temp,input);
			seperate(temp);
			strcpy(temp,"");
		}
		else
			seperate(input);

	}
	return 0;
}