#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    int num,n[30001]={0},MAX,com,j,m[10000];
    while(cin>>num)
    {
        for(int i=1;i<=num;i++)
        {
            cin>>com;
            n[com]++;
        }
        MAX = 0 ;
        j=0;
        for(int i=1;i<=30001;i++)
            if(n[i]>MAX)
                MAX = n[i];
        for(int i=1;i<=30001;i++)
            if(MAX==n[i])
            {
                m[j] = i;
                j++;
            }
        for(int i=0;i<j;i++)
            cout<<m[i]<<" "<<MAX<<endl;
    }
    return 0;
}