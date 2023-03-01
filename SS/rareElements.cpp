
/*
remember the fucking indexing
5
5 2
4 3
3 4
1 1 0 0 0
1 1 0 0 0
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1
8 2
5 6
6 4
1 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0
1 1 0 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
10 3
8 2
5 3
7 1
0 0 0 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 0
1 0 0 1 0 0 0 0 1 0
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
15 4
11 15
15 9
1 2
14 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 1 0 0 0 1 1 1 1 1 1 1 0 1
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1
20 4
13 6
20 4
1 2
17 16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0
 
Output
#1 1
#2 2
#3 2
#4 12
#5 15
 */

#include<iostream>
using namespace std;

#define MAX 101
#define INF 100000 

int mat[MAX][MAX];
bool vis[MAX][MAX];

struct point{
    int x,y;
    int level;
};

struct Node{
    point data;
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

    void enQ(point x){

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

    point deQ(){
        
        Node* temp = front;
        point tempData = temp->data;

        front=front->next;
        
        if(front==NULL) end = NULL;

        num--;

        delete(temp);
        return tempData;
    }


};

bool isValid(int x,int y,int N){

    if(x>=0 && y>=0 && x<N && y<N){
        return true;
    }
    return false;
}




int main(){

    int t;
    cin>>t;

    while(t--){

        int N;
        cin>>N;
        
        int rareNum;
        cin>>rareNum;

        point R[rareNum];

        for(int i=0;i<rareNum;i++){
            int sx,sy;
            cin>>sx>>sy;
            sx--;sy--;
            R[i].x = sx;
            R[i].y = sy;
        }


        int ans = INF;

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>mat[i][j];
            }
        }

        int row[] = {-1,0,1,0};
        int col[] = {0,-1,0,1};


        for(int i=0;i<N;i++){
            
            for(int j=0;j<N;j++){

                int cur_lvl;

                if(mat[i][j]==1){
                    
                    cur_lvl = 0;

                    for(int k=0;k<rareNum;k++){

                        Queue q;

                        for(int l =0; l<MAX; l++){for(int m =0; m<MAX; m++){vis[l][m] = 0;}}
                        
                        int res=0;
                        
                        point pos;
                        
                        pos.x=i;
                        pos.y=j;
                        pos.level=0;
                        vis[i][j]=1;

                        q.enQ(pos);

                        while(!q.isEmpty()){

                            point temp = q.deQ();

                            if(temp.x==R[k].x && temp.y==R[k].y){
                                res = temp.level;
                                break;
                            }

                            for(int z=0;z<4;z++){
                                
                                int valX = temp.x + row[z];
                                int valY = temp.y + col[z];

                                if(isValid(valX,valY,N)){
                                    
                                    if( mat[valX][valY]==1 && !vis[valX][valY] ){
                                        
                                        point pos1;
                                        pos1.x = valX;
                                        pos1.y = valY;
                                        pos1.level = temp.level+1;
                                        vis[valX][valY] = 1;

                                        q.enQ(pos1);
                                    }


                                }


                            }


                        }

                        cur_lvl = max(res,cur_lvl);

                    }

                    ans = min(ans,cur_lvl);


                }


            }



        }


    cout<<ans<<endl;


    }

    return 0;

}