#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    int num,n[10001],temp,counter;
    while(cin>>num)
    {
        counter = 0;
        for(int i=1;i<=num;i++)
            cin>>n[i];
        for(int i=1;i<num;i++)
            for(int j=1;j<num;j++)
                if(n[j]>n[j+1])
                {
                    temp=n[j];
                    n[j]=n[j+1];
                    n[j+1]=temp;
                    counter++;
                }
        cout<<counter<<endl;
    }
    
    return 0;
}