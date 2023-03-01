#include<iostream>
using namespace std;

#define MAX 1000
#define INF 1000000

int mat[MAX+1][MAX+1];

void reset(){

    for(int i=0;i<=MAX;i++){
        for(int j=0;j<=MAX;j++){
            mat[i][j] = INF;
        }
    }

}

void Djikstra(int V,int E,bool vis[],int distances[]){

    int src=0;
    distances[src]=0;

    for(int count =1;count<=V;count++){

        int closest=0;
        int mini=INF;

        for(int i=0;i<=V;i++){
            if(!vis[i] && distances[i]<=mini){
                closest=i;
                mini = distances[i];
            }
        }
        vis[closest]=1;

        for(int i=1;i<=V;i++){

            if(distances[closest]+mat[closest][i]<distances[i]){
                distances[i] = distances[closest] + mat[closest][i];
            }

        }



    }



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
        
        cout<<"Enter edges and distances:"<<"\n";

        for(int i=0;i<E;i++){
            int u,v,dis;
            cin>>u>>v>>dis;
            mat[u][v]=dis;
        }

        bool vis[V+1];
        int distances[V+1];

        for(int i=0;i<=V;i++){
            vis[i]=0;
            distances[i]=INF;
        }

        Djikstra(V,E,vis,distances);

        for(int i=0;i<V;i++)
        cout<<distances[i]<<" ";

        cout<<endl;

    }

    return 0;

}