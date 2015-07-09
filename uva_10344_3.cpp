#include <iostream> // Accepted
#include <cstdlib>
#include <stdio.h>
#include <algorithm>

using namespace std;

bool permu(int ori_array[5], int array[5], bool v[5], const int& ptr);
bool dfs(int array[5], const int& ptr, int value);

int main()
{
    int array[5], array2[5];
    bool k, v[5];
    
    for(;;)
    {
        k = true;
        
        for(int i = 0; i < 5; i++)
        {
            cin >> array[i];
            
            if(array[i] != 0)
                k = false;
        }
        
        if(k)
            break;
        
        fill(v, v+5, false);
        
        if(permu(array, array2, v, 0))
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
    
    return 0;
}
bool permu(int ori_array[5], int array[5], bool v[5], const int& ptr)
{
    if(ptr == 5)
        return dfs(array, 1, array[0]);
    
    for(int i = 0; i < 5; i++)
    {
        if(!v[i])
        {
            v[i] = true, array[ptr] = ori_array[i];
            
            if(permu(ori_array, array, v, ptr+1))
                return true;
            
            v[i] = false;
        }
    }
    
    return false;
}
bool dfs(int array[5], const int& ptr, int value)
{
    if(ptr == 5)
    {
        if(value == 23)
            return true;
        else
            return false;
    }
    else
    {
        if(dfs(array, ptr+1, value+array[ptr]) || dfs(array, ptr+1, value-array[ptr]) || dfs(array, ptr+1, value*array[ptr]))
            return true;
        else
            return false;
    }
}

