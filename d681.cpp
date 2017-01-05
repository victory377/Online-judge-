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
