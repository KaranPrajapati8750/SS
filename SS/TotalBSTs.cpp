/*Total number of possible Binary Search Trees with n different keys 
(countBST(n)) = Catalan number Cn = (2n)! / ((n + 1)! * n!) = 2nCn / (n+1)
For n = 0, 1, 2, 3, … values of Catalan numbers are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …. So are numbers of Binary Search Trees.

Total number of possible Binary Trees with n different keys 
(countBT(n)) = countBST(n) * n!

https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-6c849f2453e54b1aa3bb1f2026e7f508_l3.svg

Dp Solution:-
( TC-O(n2) SC-O(n) )
dp[i] += dp[j] * dp[i-j-1];

*/
#include<iostream>
using namespace std;

#define ll long long

ll TotalBST(int N,int K){

    ll res=1;

    if(K>N-K) K = N-K;

    for(ll i=0;i<K;i++){

        res *= (N-i);
        res /= (i+1);

    }

    return res;


}

int main(){

    int t;
    cin>>t;

    while(t--){

        ll n;
        cin>>n;
        
        cout<<(TotalBST(2*n,n))/(n+1)<<endl;


    }

    return 0;


}










