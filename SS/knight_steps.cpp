#include<iostream>

using namespace std;

struct cord{
    int x,y,dis;
};

struct Node{
    cord data;
    Node* next;
};

//Queue using linked list
class Queue{

    public:

    Node* front, *end;
    int num;

    //initialization
    Queue(){

        front=NULL;
        end=NULL;
        num=0;

    }

    
    bool isEmpty(){
        
        if(num==0)return 1;

        return 0;

    }

    int size(){
        return num;
    }

    void enQ(cord x){

        Node *newnode = new Node;
        newnode->data = x;
        newnode->next = NULL;

        if(front == NULL && end==NULL ){
            front = end = newnode;
        }

        else{
            end->next=newnode;
            end = newnode;
        }

        num++;

    }

    cord deQ(){
        
        Node* temp = front;
        cord tempData = temp->data;

        front=front->next;
        
        if(front==NULL) end = NULL;

        num--;

        delete(temp);
        return tempData;
    }


};

bool isValid(int x,int y,int M,int N){

    if(x>=0 && y< M && x>=0 && y<N){

        return true;

    }
    return false;

}


int minKnightSteps(int M,int N, cord src, cord dest){

    int row[] = {-1,-2,-2,-1,1,2,2,1};
    int col[] = {-2,-1,1,2,-2,-1,1,2};

    bool vis[M+1][N+1];

    for(int i=0;i<=M;i++){
        for(int j=0;j<=N;j++){
            vis[i][j]=0;
        }
    }

    vis[src.x][src.y]=1;   

    src.dis = 0;

    Queue q;

    q.enQ(src);

    while(!q.isEmpty())
    {
        cord temp = q.deQ();

        int cordX = temp.x;
        int cordY = temp.y;
        int res = temp.dis;

        if(dest.x == cordX && dest.y == cordY){
            return res;
        }

        else{
            for(int i=0;i<8;i++){

                int x = cordX + row[i];
                int y = cordY + col[i];

                if(!vis[x][y] && isValid(x,y,M,N)){
                    
                    cord pos1;
                    pos1.x = x;
                    pos1.y = y;
                    pos1.dis = res+1; 

                    vis[x][y]=1;  
                    q.enQ(pos1);
                    
                }
            }

        }

    }
    return -1;
}


int main(){

    int t;
    cin>>t;
    while(t--){

        int M,N;
        cin>>M>>N;

        cord src,dest;

        cin>>src.x>>src.y>>dest.x>>dest.y;

        cout<<minKnightSteps(M,N,src,dest);
        cout<<endl;

    }

    return 0;

}