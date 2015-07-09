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
#define pb push_back
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define MAXN 1000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct token {
string s;
bool astrk_before;
};

//Check if RegEx string is empty or not
bool hasNextToken(string r) {
return (r.size() != 0);
}

//Remove adjacent astriks for better handling
string remove_consicutive_astriks(string r) {
string ret = "";
ret += r[0];
int r_len = r.size();
for(int i = 1; i < r_len; i++) {
if(r[i] == '*' && r[i-1] == '*') continue;
ret += r[i];
}
return ret;
}

//Get the next non-astrik token from RegEx, also check if an astrik appears before it or not
pair<token, string> getNextToken(string r) {
token t; t.s = "";
int r_len = r.size();
string ret = "";
int i = (t.astrk_before = (r[0] == '*'));
for( ; i < r_len; i++) {
if(r[i] == '*') break;
t.s += r[i];
}
for(; i < r_len; i++) ret += r[i];
return make_pair(t, ret);
}

//Main Logic
bool check(string input, string reg_exp) {
if(hasNextToken(reg_exp)) {
    reg_exp = remove_consicutive_astriks(reg_exp);
   }

   bool match = true, found_next = false;    
   int input_len = 0, token_len = 0;
   token next;
   pair<token, string> token_and_regex;

   while(true) {
    //If we do not have any more tokens then input should be empty too  
    if(!hasNextToken(reg_exp)) {
    match = (input.size() == 0);
    break;
    }
    token_and_regex = getNextToken(reg_exp);
    next = token_and_regex.first;    
    reg_exp = token_and_regex.second;    

    //next could be just *, in that case everything in the input matches    
    if(next.astrk_before && next.s.size() == 0) {    
    break;
    }
    //if there is not an astrik before and next token string is empty, then input string should be empty too
    if(!next.astrk_before && next.s.size() == 0) {    
    match = (input.size() == 0);
    break;
    }

    input_len = input.size();
    token_len = next.s.size();
    found_next = false;

    if(input_len == 0) {    
    match = false; break;    
    }
   
    //if there is an astrik before the pattern, then get the first occurence of the token
    if(next.astrk_before) {    
    int i = 0;
    for( ; i < input_len; ) {
    if(input[i] != next.s[0]) {
    i++; continue;
    }
    found_next = true;
    int j = i;
    for(int k = 0; k < token_len; k++, j++) {
    if(j >= input_len || next.s[k] != input[j]) {
    found_next = false; break;
    }
    }

    if(found_next) {
    i = j; break;
    } else {
    i++;
    }
    }

    if(!found_next) {    
    match = false; break;
    }    
    string in = "";
    for( ; i < input_len; i++) in += input[i];
    input = in;

    } else {    
    int i = 0, k = 0;
    found_next = true;
    for( ; k < token_len; k++ ) {
    if(i < input_len && input[i] == next.s[k]) {
    i++;
    } else {
    found_next = false;
    break;
    }
    }

    if(!found_next) {    
    match = false;
    break;
    }    
    string in = "";
    for( ; i < input_len; i++) in += input[i];
    input = in;
    }    
   }

   return match;
}

int main()
{
   int T;
   cin>>T;
   getchar();
   while(T--) {
    string input, reg_exp;
    getline(cin, input);
    getline(cin, reg_exp);
    cout<<input<<endl;
    cout<<reg_exp<<endl;
    cout<<(check(input, reg_exp)?"Match":"Doesn't Match")<<endl;
   }
   return 0;
}