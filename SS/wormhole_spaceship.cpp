#include<iostream>
using namespace std;
 
int n;
int ans;
bool visited[100];
 
 //wormhole representation
struct hole{
    int x1,y1,x2,y2,cost;
};
 
//coordinate representation
struct point{
    int x,y;
};

//calculate distance
int calculate(point src, point dest){
    return (abs(src.x-dest.x) + abs(src.y-dest.y));
}
 

void solve(point src, point dest, hole a[], int cost){
    
    int tempans = cost + calculate(src,dest);
    //cout<<tempans<<endl;
    ans = min(ans,tempans);
    
    for(int i = 0; i<n; i++){
        
        if(!visited[i]){//if wormhole is not visited 
            
            visited[i] = true;//visit it
            
            point holeEntrance,holeExit;
                        
            holeEntrance.x = a[i].x1; holeEntrance.y = a[i].y1;
            
            holeExit.x = a[i].x2; holeExit.y = a[i].y2;

            //if we enter hole's entrance location first
            int val =  calculate(src,holeEntrance);//calculate distance b/w src to hole entrance

            solve(holeExit, dest, a, cost + val + a[i].cost); 
            
            //if we enter hole's exit location first
            val = calculate(src,holeExit);
            
            solve(holeEntrance, dest, a, cost + val + a[i].cost);
            
            
            visited[i] = false;
        }
        
    }
    
}
 
int main(){
    
    int t; 
    cin>>t;
    while(t--){
        
        point src,dest;
        cin>>src.x>>src.y>>dest.x>>dest.y;

        cin>>n;
        hole a[n];
        
        for(int i = 0; i<n; i++)
        cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2>>a[i].cost;
        
        ans = 1000000;
        
        for(int i = 0; i<n; i++)visited[i] = false;
        
        solve(src,dest,a,0);// we want to go from source to destination
        
        cout<<ans<<endl;
    }
    
  return 0;
}