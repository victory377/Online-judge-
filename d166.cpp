#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

int main()
{
    int a[51]={0},b[51]={0};
    string str;
    
    while(getline(cin,str))
    {
        if(str[0] == '-' && str[1] == '1')
            break;
        istringstream ss (str);
        int i=1;
        while(ss>>a[i]) i++;
        
        int temp,p;
        //cout<<i<<endl;
        for(int j=1;j<i;j++)
        {
            temp=0;
            for(int k=1;k<i;k++)
            {
                if(b[k]==0)
                    temp++;
                if(temp == a[j]+1){
                    b[k]=j;
                    //cout<<"k:"<<k<<endl;
                    //cout<<"temp:"<<temp<<endl;
                    //cout<<"b[k]:"<<b[k+1]<<endl;
                    //cout<<"a[j]:"<<a[j]<<endl;
                    break;
                }
                else if(a[j]==0)
                {
                    p=k;
                    while(b[p]!=0)p++; 
                    //cout<<"11111111111p:"<<p<<" "<<j<<endl;
                    b[p]=j;
                    //cout<<"b[k]:"<<b[p]<<endl;
                    break;	 
                }	
            }	
        } 
        
        for(int j=1;j<i;j++)
            cout<<b[j]<<" ";
        cout<<endl;	
        for(int j=1;j<i;j++){
            a[j]=0;
            b[j]=0;
        }
        
    }
    return 0;
}