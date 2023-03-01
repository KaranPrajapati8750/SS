#include<iostream>
using namespace std;
 
int dp[100][100];

int solve(int *a , int n){
    
   for(int len = 1; len<=n; len++){
       for(int left = 1; left<=n-len+1; left++){
       int right = left + len - 1;
       for(int k = left; k<=right; k++){
           dp[left][right] = max(dp[left][right],(dp[left][k-1] 
                                  + dp[k+1][right] + a[left-1]*a[k]*a[right+1]));
       }
       }
   }
   return dp[1][n];
}
 
int main(){
    
    int n; cin>>n;
    int a[n+2];
    a[0] = 1;
    a[n+1] = 1;
    for(int i =1; i<=n; i++)cin>>a[i];
    a[n+1] = 1;

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            dp[i][j] = 0;
        }

    }

    cout<<solve(a,n)<<endl;
    return 0;
}