#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

bool helper(int node,vector<int> g[],vector<bool> &vis,vector<int> &res,vector<bool> &rec)
{
    
    if(!vis[node]){
        
        vis[node] = true;
        rec[node] = true;
        res.push_back(node);
        for(auto i : g[node]){
            
            if(vis[i] && rec[i]){
                res.push_back(i);
                return true;
            }
            
            else if(!vis[i]){
                if(helper(i,g,vis,res,rec)) return true;
            }
            
        }
        
    }
    rec[node] = false;
    res.clear();
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    
    vector<bool> vis(V);
    vector<int> res;   
    vector<bool> rec(V);
    
    for(int i=0;i<V;i++){
        vis[i]= false;
        rec[i]=false;
    }
    
    for(int i=0;i<V;i++){
        if(helper(i,adj,vis,res,rec)){
            break;
        }
    }
    int n=res.size();
    
    //for self loop, last two elements will be equal
    if(res[n-2]==res[n-1]){
        cout<<res[n-2]<<" "<<res[n-1]<<endl;
        return true;
    }
    
    if(n){
        for(int i=0;i<n;i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    
        return true;
    }
    
    return false;
    
}

};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int V, E;
	    cin >> V >> E;
	    
	    vector<int> adj[V];
	    
	    for(int i =0;i<E;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    isCyclic(V, adj);
	    
	}
	
	return 0;
}

