#include <iostream>
using namespace std;

int dp[1000][1000];
int A[1000];
int mini,ans,tot;

int ABS(int x)
{
    if(x<0)
        x=-1*x;
    return x;
}

int solve(int i,int curr,int n)
{
    if(i==n)
    {
        int x=ABS(tot-2*curr);//mini = minimum diff b/w two subsets

        if(x<mini)//if we get new minimum diff then update ans and minimum diff
        {
            mini=x;
            ans=max(curr,tot-curr);//store the max sum subset
        }
        return 1;
    }
    
    if(dp[i][curr]!=-1)//look up
        return dp[i][curr];
    
    //either we can add current element into curr sum or don't add it
    return dp[i][curr]=solve(i+1,curr+A[i],n) + solve(i+1,curr,n);

}

int main()
{
	int n;
    cin>>n;
 
    mini=10000000;
 
    ans=tot=0;
 
    for(int i=0;i<n;i++){
        cin>>A[i];
        tot+=A[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            dp[i][j]=-1;
    }

    solve(0,0,n);
    cout<<ans;
}