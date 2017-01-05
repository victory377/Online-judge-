#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

int main()
{
    int num[500][500],n=0,m=0,total,sum[500][500],sum2[500][500],x1,x2,y1,y2;
    
    while(scanf("%d %d",&n,&m)==2)
    {
        sum[1][0]=0;
        sum2[1][0]=0;
        sum[0][1]=0;
        sum2[0][1]=0;
        x1=0,x2=0,y1=0,y2=0;
        
        for(int i=1;i<=n;i++)  //row
        {
            total = 0;
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&num[i][j]);
                total += num[i][j];
                sum[i][j]=total;
            }
        }
        
        for(int i=1;i<=n;i++)//column
        {
            total=0;
            for(int j=1;j<=n;j++)
            {
                total += num[j][i];
                sum2[j][i] = total;
            }
        }
        
        for(int i=0;i<m;i++)
        {
            total =0;
            cin>>x1>>x2>>y1>>y2;
            if((x2==y2)&&(y1!=x1))
                cout<<sum2[y1][y2]-sum2[x1-1][x2]<<endl;
            else if((x1==y1)&&(x2!=y2))
                cout<<sum[y1][y2]-sum[x1][x2-1]<<endl;
            else
            {
                for(int i=x1;i<=y1;i++)
                    total = total + sum[i][y2]-sum[i][x2-1];
                cout<<total<<endl;
            }
        }
    }
    return 0;
}

