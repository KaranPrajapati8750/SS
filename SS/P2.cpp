/*A binary matrix of nxm was given, you have to toggle any column k number of times so that you can get the maximum number of rows having all 1’s.

for eg, n=3, m=3,

1 0 0

1 0 1

1 0 0
if k=2, then we will toggle column 2 and 3 once and we will get rows 1 and 3 with 1 1 1 and 1 1 1 i.e. all 1’s so answer is 2 as there are 2 rows with all 1’s.

if k=3, then we will toggle column 2 thrice and we will get row 2 with 1 1 1 i.e. all 1’s so answer is 1 as there is 1 row with all 1’s.*/


#include<bits/stdc++.h>
using namespace std;
#define MAXX 10

int solve(vector<vector<int>> mat,int m, int n, int k){

    int ans=0;
    vector<int> v(100,0);

    for(int i=0;i<m;i++){

        int key=0,zeros=0;
        
        for(int j=0;j<n;j++){
            
            key += (mat[i][j]* pow(2,j));

            if(mat[i][j]==0){zeros+=1;}

        }
		
        //K should be greater than zeros in the row to make it all 1's 
        //and as the row can be flipped multiple times ,it will give same output after even flips
        
        //In other words, **(K-zeros) should be a non negative even number**
        if(k>=zeros && (zeros-k)%2 == 0){
            v[key] += 1;
            ans = max(ans,v[key]);
        }

    }
    //for(int i=0;i<v.size();i++)
		//cout<<v[i]<<" "<<endl;
        
    return ans;

}

int main(){

    int m,n,k;
    cout<<"Enter m,n,k:"<<endl;
    cin>>m>>n>>k;
	
    vector<vector<int>> mat(m, vector<int> (n, 0)); 
    
    cout<<"Enter elements in matrix:"<<endl;
    
    for(int i=0;i<m;i++){
        
        for(int j=0;j<n;j++){
			cin>>mat[i][j];
        }
    }
	cout<<"Result:"<<endl;
    cout<<solve(mat,m,n,k);
    
    return 0;
}