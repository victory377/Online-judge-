#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    string str,temp,str2;
    int num,a=0,b=0;
    int x[5],y[5],t[5];
    
    while(scanf("%d %d %d %d %d",&x[0],&x[1],&x[2],&x[3],&num) == 5)
    {
        for(int i=0;i<4;i++)
            t[i]=x[i];
        for(int i=0;i<num;i++)
        {   a=0;
            b=0;
            scanf("%d %d %d %d",&y[0],&y[1],&y[2],&y[3]);
            for(int j=0;j<4;j++)
            {
                for(int k=0;k<4;k++)
                {
                    if(x[j] == y[k])
                    {
                        if(j==k)
                        {
                            a++;
                            x[j] = -2;
                            y[k] = -1;
                        }
                    }
                }
            }
            for(int j=0;j<4;j++)
            {
                for(int k=0;k<4;k++)
                {
                    if(x[j] == y[k])
                    {
                        if(j!=k)
                        {
                            b++;
                            x[j] = -2;
                            y[k] = -1;
                        }
                    }
                }
            }
            printf("%dA%dB\n",a,b);
            for(int i=0;i<4;i++)
                x[i]=t[i];
        }    
    }
    return 0;
}