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