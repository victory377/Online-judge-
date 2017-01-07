On line judge
===
研所期間練習C++，因而有練習解題，解了基礎題庫106題。
![](https://i.imgur.com/VMGK35f.png)

### 下面放了其中較印象深刻的題目！


![](https://i.imgur.com/xWNU555.png)
***************************************
這題主要作字串的訓練，我選擇先做完A的驗
證，在作B的檢驗，且檢驗完的字串必須不是
原本的值，不然就會錯誤，並且要使用scanf
與printf，否則程式會TLE。 
***************************************
~~~ c
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
~~~
![](https://i.imgur.com/4ADbKfD.png)
* 先分析矩陣的數字順序，以二維陣列為例，
00 01 02
10 11 12
20 21 22
先從1 3 5 7 下手找規律，基本上都相差二的倍數
所以就迴圈先去填奇數後，在填偶數最後加上中心，
因為偶數陣列沒有中心，須先做判斷！
~~~ c
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

~~~
![](https://i.imgur.com/FphnKAC.png)
* 這題著重於陣列的加總，先針對行與列間個別的加總，之後就針對測試判斷是否有同行或同列，若沒有則由小加到大的位置。

~~~ c
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

~~~
![](https://i.imgur.com/dYfOt4d.png)
* 複習資料結構的queue的實作，每個會經過的點分別紀錄其座標及level，並透過BFS來計算最短路徑，最後跑到終點後，仍然無法走出一條路，則代表無法找到正確的最短路徑。
	* queue
	* BFS
~~~ c
#include <iostream>
#include <cstdlib>

using namespace std;

class node{
    int x;
    int y;
    int level;
    node *next;
    friend class Queue;
};
class Queue{
    node *front;
    node *rear;
public:
    Queue();
    int enqueue(int x,int y,int level);
    node* dequeue();
    int bfs(int s_x,int s_y,int e_x,int e_y,char n[][101]);
};

Queue::Queue()
{
    front =NULL;
    rear = NULL;
}
int Queue::enqueue(int x,int y,int level)
{
    node *new_node;
    new_node =new node;
    
    new_node->x = x;
    new_node->y = y;
    new_node->level = level;
    if(rear==NULL)
        front = new_node;
    else
        rear->next = new_node;
    rear = new_node;
    return 1;
}

node* Queue::dequeue()
{
    node *top;
    if(front != NULL)
    {
        top = front;
        front = front->next;
        if(front==NULL)
            rear = NULL;
        return top;
    }
    else
        return NULL;
}

int Queue::bfs(int s_x, int s_y,int e_x, int e_y, char n[][101])
{
    int flag=0,level=1;
    node *temp;
    Queue();
    enqueue(s_x,s_y,level);
    
    while(front != NULL)
    {
        temp = dequeue();
        //cout<<temp->x<<" "<<temp->y<<" "<<temp->level<<endl;
        
       level = temp->level;
        if(temp->x == e_x && temp->y == e_y){
            flag=1;
            break;
        }
      // level = temp->level;
        
    if(n[temp->x][temp->y]=='.'){
        n[temp->x][temp->y]='#';
        
        if(n[temp->x+1][temp->y]=='.')      //down
            enqueue(temp->x+1,temp->y,level+1);
        if(n[temp->x][temp->y+1]=='.')      //right
            enqueue(temp->x,temp->y+1,level+1);
        if(n[temp->x][temp->y-1]=='.')      //left
            enqueue(temp->x,temp->y-1,level+1);
        if(n[temp->x-1][temp->y]=='.')     //up
            enqueue(temp->x-1,temp->y,level+1);
        }
    }
    if(flag)
        return level;
    else
        return 5001;
}

int main()
{
    int num,step;
    char n[101][101];
    Queue q;
    
    while(cin>>num)
    {
        for(int i=1;i<=num;i++)
            for(int j=1;j<=num;j++)
                cin>>n[i][j];
        
        step = 0;
    
        step = q.bfs(2,2,num-1,num-1,n);
       
        if(step>5000)
            cout<<"No solution!"<<endl;
        else
            cout<<step<<endl;
        Queue();
    }
    return 0;
}
~~~
![](https://i.imgur.com/X9ZkL2R.png)
* bubble sort來計算總比較次數
~~~ c
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
~~~
![](https://i.imgur.com/xc1buCP.png)
* 不斷找出累積最大的數
~~~ c
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
~~~
![](https://i.imgur.com/zMyrS02.png)
* 有序數列經過反轉後，可以得到新的數列，如123456789依序去找，若反轉述列如236402210，代表數字1前面有兩個比他大的數，所以我是一空數列去填空，初始值設定為0，若空格為0則有個數會一直往下加，此數是為了找到數字的正確位置，若特別遇到0的數要處理，先遇到的則放在數列的前方，直到放完全部數，就完成算出反轉後的數列！

~~~ c
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
~~~ 
![](https://i.imgur.com/c5qhcdK.png)
*此題固定計算5個bits間的邏輯值，所以先取的要計算的邏輯符號，在找尋左右兩側的數值做運算，最後就能找出答案！

~~~ c
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstring>

using namespace std;

class check{
public:
    char n[5],m[5],s[4];
    int sign;
    
    void compute(char n[5],char m[5],int sign)
    {
        int p,k;
        for(int j=0;j<5;j++){
            p = n[j]-48;
            k = m[j]-48;
            if(sign){
                if(p & k)
                    n[j] = 49;
                else
                    n[j] = 48;}
            else{
                if(p | k)
                    n[j] = 49;
                else
                    n[j] = 48;
            }
        }
    }
    void show()
    {
        for(int i=0;i<5;i++)
            cout <<n[i];
    }
    void show_m()
    {
        for(int i=0;i<5;i++)
            cout <<m[i];
    }
    void symbol()
    {
        if(s[0] == 'o')
            sign =0;
        else
            sign =1;
    }
};

int main()
{
    check m1;
    string str;
        
    while(getline(cin,str))
    {
        istringstream in(str);
        
        in >>m1.n;
        m1.show();
        
        while(in >>m1.s){
            m1.symbol();
            if(m1.sign)
                cout<<"&&";
            else
                cout<<"||";
            in>>m1.m;
            m1.show_m();
            m1.compute(m1.n,m1.m,m1.sign);}
        cout<<" "<<"="<<" ";
        m1.show();
        cout<<endl;
    }
    return 0;
}
~~~

### 新手訓練 ~ for + if
************************************ 
非常奇怪，這題的題目是要求b跟c都是
int範圍的數字，但我只用int去存b跟c
會有錯誤，因為運算完後才會將值ass
ign給n，所以就發生溢位了。 
************************************
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{ 
	int num=0,a;
	long long int n,b,c;
	
	while(cin>>num)
	{
		for(int i=0;i<num;i++)
		{	a=0;
			b=0;
			c=0;
			n=0;
			cin>>a;
			switch(a)
			{
				case 1:
					cin>>b>>c;
					n=b+c;
					cout<<n<<endl;
					break;
				case 2:
					cin>>b>>c;
					n=b-c;
					cout<<n<<endl;
					break;	
				case 3:
					cin>>b>>c;
					n=b*c;
					cout<<n<<endl;
					break;
				case 4:
					cin>>b>>c;
					n=b/c;
					cout<<n<<endl;
					break;
			}
		}
	}
    return 0;
}


*********a291nAnB problem*********
***************************************
這題主要作字串的訓練，我選擇先做完A的驗
證，在作B的檢驗，且檢驗完的字串必須不是
原本的值，不然就會錯誤，並且要使用scanf
與printf，否則程式會TLE。 
***************************************
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

*****a248: 新手訓練 ~ 陣列應用*****
************************************
觀察除法的特性，取得餘數後先乘10，在
利用除法把商找出來，然後依造題目規定
，完成N位小數點。
*********************************** 
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int num,div,n,less,t[10001]={0};
	while(cin>>num>>div>>n)
	{
		less=num%div;
		num=num/div;
		//cout << less <<num<<endl;
		for(int i=0;i<n;i++)
		{
			t[i]=(less*10)/div;
			less=(less*10)%div;
		}
		cout<<num<<".";
		for(int i=0;i<n;i++)
		cout<<t[i];
		cout<<endl;
		for(int i=0;i<n;i++)
		t[i] = 0;
		num=0,div=0,n=0,less=0;
	}
	return 0;
}


*******a414.位元運算之進位篇*******
*************************************
必須用scanf來取值，因為輸入會有一堆雜
亂的值，會造成TLE。 
*************************************
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int num,n[32],i,counter;
	
	while(scanf("%d",&num) == 1)
	{
		if(num==0)
		break;
		i=0;
		counter=0;
		while(num!=0)
		{
			n[i]=num%2;
			num/=2;
			i++;
		}
		for(int j=0;j<=i;j++)
		{
			if(n[j]!=1)
			break;
			counter++;
		}
		printf("%d\n",counter);
		for(int j=0;j<=i;j++)
			n[j] = 0;
	}
	return 0;
}
