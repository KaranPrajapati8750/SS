#include<iostream>
using namespace std;

#define MAX 200;


int cycles[MAX][MAX];
bool mat[MAX][MAX];


void dfs(int node,int origin,int color[],int parent[],int mark[],int &cycle_num){

    if(color[node]==2){
        return;
    }

    if(color[node]==1){
        
        cycle_num++;
        int cur=origin; 

        mark[cur] = cycle_num;

        while(cur!=node){
            cur = parent[cur];
            mark[cur] = cycle_num;
        }
        return ;

    }

    parent[node] = origin;

    color[node] = 1;

    for(int i=0; i<V; i++){
        
        if(mat[node][i]){

            if(i==par[node]){
                continue;
            }

        }
        dfs(i,node,color,parent,mark,cycle_num);

    }

    color[node] = 2;

}

void printCycles(int E,int mark[],int &cycle_num){

    for(int i=0; i<E; i++){
        
        if(mark[i]!=0){
            cycles[mark[i]][i];
        }

    }

    for(int i=0; i<=cycle_num; i++){
        cout<<"Cycle no. "<<i<<": ";

        for(auto j:cycles[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }



}

int main(){

    int V,E;
    cin>>V>>E;

    for(int i=0;i<E;i++){

        int u,v;
        cin>>u>>v;

        mat[u][v]=1;

        mat[v][u]=1;

    }

    int color[V];
    int parent[V];

    int mark[V];

    int cycle_num=0;
    
    for(int i=0;i<V;i++){
        dfs(i,-1,color,parent,mark,cycle_num);
    }
    printCycles(E,mark,cycle_num);

    return 0;

}



