/*
A man has some camels with him.He has to take these camels to the opposite end.Each camel has some cost to go from one end to other.
->While going to opposite end , he will take 2 camels along with him, the cost will be the maximum of the cost of both the camels.
->On reaching opposite end, he will take one camel from opposite end to go back to first end, the cost will be taken as the cost of that camel.
->At the end, he has to move all the camels to the opposite end.
Find the minimum cost to take camels to opposite end.
Example->
INPUT
2              
4
1 2 8 9        
6
14 45 73 86 95 98
OUTPUT
16
434
*/


#include<iostream> 
using namespace std; 
 
int globalAns = 100000; 
 
void solve(int a[], int n, bool vis[], int LtoR, int ans, int visCnt){
 
    if(ans>globalAns) return;                                                       /* optimization */
    if(visCnt == n){                                                                 /*base case // all visited */
       // TO CHECK ALL THE ANSWERS SIMPLY PRINT THE ANS EVERYTIME 
       globalAns = min(ans, globalAns);   
    }
    
    if(LtoR == 1){//Forward trip
    
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
             
                if(vis[i] == false && vis[j] == false){
                    int bada = max(a[i],a[j]); 
           
                     /* backtracking logic */
                    vis[i] = true; vis[j] = true; 
                    solve(a,n,vis,1-LtoR, ans + bada, visCnt + 2); 
                    vis[i] = false; vis[j] = false; 
                }
            
            }
        }
        
    }
    else{//Backward trip
 
        for(int i = 0; i<n; i++){
            if(vis[i] == true){
               /* backtracking logic */
                vis[i] = false; 
                solve(a,n,vis,1-LtoR, ans + a[i], visCnt - 1); 
                vis[i] = true; 
            }
        }
       
    }
}
 
 
int main(){
    
    int t; 
    cin>>t; 
    while(t--){
        int n; 
        cin>>n; 
        int a[n]; 
        bool vis[n]; 
        for(int i = 0; i<n; i++)cin>>a[i]; 
        for(int i = 0; i<n; i++)vis[i] = false;

        int ans=0;

        solve(a,n,vis,1,ans,0); 
        cout<<globalAns<<endl; 

        globalAns=1000000;

    }
    return 0;   
}