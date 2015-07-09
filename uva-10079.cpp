
    #include<iostream>
    using namespace std;
    int main ()
    {
            long long N , Max;
            while(true)
            {
                    cin>>N;
                    if(N<0)break;
                    else{
                            Max = N*(N+1)/2+1;
                            cout<<Max<<endl;
                    }
            }
            return 0;
    }
