/*
TSP Problem

input-
3
5 
0 0 100 100 70 40 30 10 10 5 90 70 50 20
6 
88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14
10 
39 9 97 61 35 93 62 64 96 39 36 36 9 59 59 96 61 7 64 43 43 58 1 36

output-
200
304
366

*/


#include <iostream>

using namespace std;

#define INT_MAX 1000

int visited[40] = {0};

struct cord{
   int x; int y;
};
 
int solve(cord customers[], int n, int x, int y,int hx, int hy, int cnt){
   
    if(cnt==n)
      return abs(x-hx) + abs(y-hy);
      
    int ans = INT_MAX;
    
    for(int i =0;i<n;i++){
       cord c = customers[i];
    
       if(!visited[i]){
           visited[i] = 1;
           int val = abs(x-c.x) + abs(y-c.y);
           ans = min(ans , val + solve(customers,n,c.x,c.y,hx,hy,cnt+1));
           visited[i] = 0;
       }
      
    }
    return ans;
}
 
int main(){
 
    int t;
    cin>>t;
 
    while(t--){
 
        int n; 
        cin>>n; 

        cord customers[n];

        int ox,oy; cin>>ox>>oy;//office coordinates
        int hx,hy; cin>>hx>>hy;//house coordinates

        //customer coordinates
        for(int i =0;i<n;i++){
            cin>>customers[i].x>>customers[i].y;
        }
        //int ans = 0;
        int ans = solve(customers,n,ox,oy,hx,hy,0);
        cout<<ans<<endl;
   }
   
   
   return 0;
}