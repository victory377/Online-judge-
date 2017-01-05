#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

class net
{
public:
    int total=0;
    int n[100][100];
public:
    int list_n(int x,int num,int total,int base) //順時針
    {
        int p = num;
        if(x==num)
        {
            total++;
            n[x][num] = total;
        }
        for(int i=x;i<num;i++,p--)
        {
            
            total++;
            n[x][i] = total;
            n[i][num] = total +base*1;
            n[num][p] = total +base*2;
            n[p][x] = total +base*3;
        }
        total += base*3;
        return total;
    }
    int list_m(int x,int num,int total,int base) //逆時針
    {
        int p = num;
        if(x==num)
        {
            total++;
            n[x][num] = total;
        }
        for(int i=x;i<num;i++,p--)
        {
            total++;
            n[i][x] = total;
            n[num][i] = total +base*1;
            n[p][num] = total +base*2;
            n[x][p] = total +base*3;
        }
        total += base*3;
        return total;
    }
    void show(int num)
    {
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<num;j++)
                printf("%5d",n[i][j]);
            cout<<endl;
        }
    }
};
int main()
{
    int num,times,i,temp,base,flag;
    net m1;
    while(cin>>times)
    {
        for(int j=0;j<times;j++)
        {
            cin>>num>>flag;
            i=0,temp=num;
            num--;
            base = num;
            while(num>=i)
            {
                if(flag==1)
                    m1.total=m1.list_n(i,num,m1.total,base);
                else
                    m1.total=m1.list_m(i,num,m1.total,base);
                i++;
                num--;
                base-=2;
            }
            m1.show(temp);
            m1.total = 0;
        }
    }
    return 0;
}