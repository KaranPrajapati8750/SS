#include <iostream>
using namespace std;

#define MAX 100

class Solution {
public:

    bool helper(int V,int adj[][MAX],bool vis[],int path[],int node,int counter,int &start,int &end)
    {
        path[counter] = node;

        for(int i = 0; i < V; i++){
            
            if(adj[node][i]==1){
                
                if(vis[i]==true){

                    start=i;
                    end=node;
                    return 1;
                
                }

                vis[i]=true;
                int loop=helper(V,adj,vis, path,i,counter+1,start,end);

                if(loop==1)
                    return 1;
                
                vis[i]=false;

            }


        }


    
    }

    bool isCyclic(int V, int adj[][MAX],int path[],int &start,int &end)
    {
        bool vis[V];
        for(int i=0;i<V;i++){
            vis[i] = false;
        }
        
        for(int i = 0; i < V; i++){

            vis[i]=true;
            path[0]=i;

            for(int j = 0; j <V; j++){

                    if(adj[i][j]==1){

                        if(vis[j]==true){
                            
                            if(i==j){
                                start=i;
                                end=i;
                                return 1;// self loop
                            }

                        }

                        vis[j]=true;

                        int loop = helper(V,adj,vis,path,j,1,start,end);

                        if(loop==1) return 1;
    
                        vis[j]=false;

                    }

            }


        }

    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int V, E;
	    cin >> V >> E;
	    
        int adj[MAX][MAX];

        for(int i = 0; i <MAX; i++){
            for(int j = 0; j <MAX;j++){
                adj[i][j]=0;
            }
        }

	    for(int i =0;i<E;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u][v] =1;
	    }

        int path[E];
        for(int i=0;i<E;i++){
            path[i] =-1;
        }

        Solution obj;
	    
	    bool k=0;
        int startNode = -1;
        int endNode=-1;

        k=obj.isCyclic(V, adj,path,startNode,endNode);

        if(k==0){
            cout<<0<<endl;
            return 0;
        }

        if(k==1){
            
            
            cout<<startNode<<" "<<endNode<<endl;;

            for(int i=0;i<E;i++){
                cout<<path[i]<<" ";
            }
            cout<<endl;


            int start_i=0;
            int end_i=0;

            for(int i=0;i<E;i++){
                
                if(path[i]==startNode)start_i=i;

                if(path[i]==endNode) end_i=i;

            }
        
            for(int i=start_i;i<=end_i;i++){
                cout<<path[i]<<" ";
            }
            cout<<endl;
        }
}
return 0;
}