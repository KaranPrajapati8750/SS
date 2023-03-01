#include<iostream>
using namespace std;
 
int dp[100][100];

int solve(int a[] , int n){
    
   for(int len = 1; len<=n; len++){//for subset of every length

       for(int left = 1; left<=n-len+1; left++){//take a left index

       int right = left + len - 1;//take a right index

       for(int k = left; k<=right; k++){//traverse b/w left and right

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

/*
Recursive


int getmaxscore(int arr[], int l, int r, int n) // r = n = elements+1
{ 
    int mscore = 0; 
    for (int i = l + 1; i < r; i++) { 
  
        int cs = getmaxscore(arr, l, i, n) + getmaxscore(arr, i, r, n); 
        if (l == 0 && r == n)//boundary case 
            cs = cs + arr[i]; 
        else
            cs = cs + (arr[l] * arr[i] * arr[r]); 
  
        if (cs > mscore) 
            mscore = cs; 
    } 
    return mscore; 
} 
*/



