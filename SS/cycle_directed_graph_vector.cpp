#include <iostream>
using namespace std;

#define MAX 100

class Solution {
public:

bool helper(int node,int color[],int adj[MAX][MAX])
{
    
    color[node] = 1;

    for(int v=0; v<V;v++){
        
        if(color[v]=1)
            return true;

        if(color[v]==0 && helper(v,color)){
            return true;
        } 


    }
    color[node] = 2;
    return false;
}

bool isCyclic(int V, int adj[MAX][MAX])
{
    int color[V];

    for(int i=0;i<V;i++){
        color[i] = 0;
    }

    for(int i=0;i<V;i++){
        if(color[i]==0){
            if(helper(i,color,adj))
                break;
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


	    for(int i =0;i<E;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u][v] =1;
	    }

        Solution obj;
	    
	    cout<<obj.isCyclic(V, adj)<<endl;
	    
	}
	
	return 0;
}

