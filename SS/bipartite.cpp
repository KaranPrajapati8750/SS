#include <iostream>

using namespace std;

int color[1000];
bool edge[1000][1000];
int E, V;


class Queue{
public:
    int num_elems,front,end;
    int arr[10000];
    Queue(){
        num_elems=0;
        front=0;
        end=0;
        for(int i=0; i<10000; i++)
            arr[i]=-1;
    }
    bool isEmpty(){
        if(num_elems==0)
            return true;
        else
            return false;
    }

    void enqueue(int x){
        arr[end++]=x;
        num_elems++;
    }
    int dequeue(){
        num_elems--;
        return arr[front++];
    }
};

void reset(){
    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++)
            edge[i][j]=false;
        color[i]=-1;
    }
}

bool isBipart(int src){

    color[src]=1;//color the src node
    Queue q;
    q.enqueue(src);

    while(!q.isEmpty()){

        int node=q.dequeue();

        if(edge[node][node]){// if there is an edge from node to node then return false
            return false;
        }

        for(int i=0; i<V; i++){//traverse node's adjacent vertices

            if(edge[node][i]){// if there is an edge

                if(color[i]==-1){// and adjacent vertex is not coloured 

                    color[i]=1-color[node];//color it with opposite colour
                    q.enqueue(i);//push it into queue

                }
                else if(color[i]==color[node]){//if colour is already same then return false
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    
    int t;
    cin>>t;

    while(t--){
        reset();
        cin>>V>>E;
        for(int i=0; i<E; i++){
            int x,y;
            cin>>x>>y;
            edge[x-1][y-1]=true;
        }
        int flag=0;
        for(int i=0; i<V; i++){
            if(color[i]==-1){
                if(!isBipart(i)){
                        flag=1;
                        cout<<"-1";
                        break;
                }
            }
        }
        if(flag==0){//when bipartite
            for(int i=0; i<V; i++){
                if(color[i]==0)
                    cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    
}