

#include<iostream>
using namespace std;

#define MAX 3001
#define INF 1e8

int mat[MAX+1][MAX+1];

void reset(){

    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            mat[i][j] = INF;
        }
    }

}

void Djikstra(int V,int E,int src){

    bool vis[V];   
    int distances[V];

    for(int i=0;i<V;i++){
        vis[i]=0;
        distances[i]=INF;
    }
    distances[src]=0;

    for(int count =1;count<V;count++){

        int closest;
        int mini=INF;

        for(int i=0;i<V;i++){
            if(!vis[i] && distances[i]<=mini){
                closest=i;
                mini = distances[i];
            }
        }
        vis[closest]=1;

        for(int i=0;i<V;i++){

            if(distances[closest]+mat[closest][i]<distances[i]){
                distances[i] = distances[closest] + mat[closest][i];
            }

        }



    }

    for(int i=0;i<V;i++)
        cout<<distances[i]<<" ";

    cout<<endl;

    return;

}



int main(){

    cout<<"Enter no. of test cases:"<<"\n";
    int t;
    cin>>t;
    while(t--){
        
        cout<<"Enter no. of vertices and edges:"<<"\n";
        int V,E;
        cin>>V>>E;

        reset();
        
        cout<<"Enter edges , distances and source:"<<"\n";

        for(int i=0;i<E;i++){
            int u,v,dis;
            cin>>u>>v>>dis;
            mat[u][u]=0;
            mat[v][v]=0;
            mat[u][v]=dis;
            //for undirected, uncomment below line
            //mat[v][u]=dis;
        }
        int src;
        cin>>src;

        Djikstra(V,E,src);
       
    }

    return 0;

}