/*A binary matrix of nxm was given, you have to toggle any column k number of times so that you can get the maximum number of rows having all 1’s.

for eg, n=3, m=3,

1 0 0

1 0 1

1 0 0
if k=2, then we will toggle column 2 and 3 once and we will get rows 1 and 3 with 1 1 1 and 1 1 1 i.e. all 1’s so answer is 2 as there are 2 rows with all 1’s.

if k=3, then we will toggle column 2 thrice and we will get row 2 with 1 1 1 i.e. all 1’s so answer is 1 as there is 1 row with all 1’s.*/


#include<iostream>
using namespace std;
#define MAXX 10000

bool mat[MAXX][MAXX];
int v[MAXX];

int pow(int a,int b)
{   
    
    int res=1;

    while(b>1){
        
        if(b%2 == 1){
            res *= a;
        }

        a *= a;
        b /= 2;

    }
    return res;

}

int solve(int m, int n, int k){

    int ans=0;
    
    for(int i=0;i<m;i++){

        int key=0,zeros=0;
        
        for(int j=0;j<n;j++){
            
            key += (mat[i][j]* pow(2,j));

            if(mat[i][j]==0){zeros+=1;}

        }
		
        //K should be greater than zeros in the row to make it all 1's 
        //and as the row can be flipped multiple times ,it will give same output after even flips
        
        //In other words, **(K-zeros) should be a non negative even number**
        if(k>=zeros && (k-zeros)%2 == 0){
            v[key] += 1;
            ans = max(ans,v[key]);
        }

    }
    //for(int i=0;i<v.size();i++)
		//cout<<v[i]<<" "<<endl;
        
    return ans;

}

int main(){

    int t;
    cin>>t;

    while(t--){

        for(int i=0;i<MAXX;i++){
            v[i]=0;
            for(int j=0;j<MAXX;j++){
                mat[i][j]=0;
            }
        }

        int m,n,k;
        cin>>m>>n>>k;
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
            }
        }

        cout<<solve(m,n,k)<<endl;
        
 
    }
    return 0;
}