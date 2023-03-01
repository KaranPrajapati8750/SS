/* 

1                   // No of test cases
5 3 5            // N ,M, O
1 2 4 6 0     // digits that are working (total number of digits = N),
1 2 3         // describing operations allowed (1–> ‘+’, 2–> ‘-‘, 3–> ‘*’ , 4–> ‘/’ )(total number is equals to M)
5                 // number we want to make

Output:
4

3                   // No of Test cases
6 4 5            // N ,M, O
1 2 4 6 9 8  // digits that are working (total number of digits = N),
1 2 3 4        // describing operations allowed (1–> +, 2–> -, 3–> , 4–>/)
91                // number we want to make
6 3 5           // 2nd test case
0 1 3 5 7 9
1 2 4           // +, -, / allowed here
28
5 2 10
1 2 6 7 8
2 3               // -, allowed
981

Output:

2        // 91 can be made by directly entering 91 as 1,9 digits are working, so only 2 operations
5            // 35-7=, other ways are 1+3*7=
9          //62*16-11=

*/

#include<iostream>
using namespace std;

#define INT_MAX 100000

int n,m,o,num;
 
int solve(int digits[], int sign[], int op, int val, int num){
  // base case
  if(op>o)return INT_MAX;
  
  if(val == num)return op;
  
  // recursive case
  int ans1 = INT_MAX;
  
  for(int i =0;i<n; i++){
     int x = val*10 + digits[i];
     ans1 = min(ans1,solve(digits,sign,op+1,x,num));
  }
 
  int ans2 = INT_MAX;
  
   int x;
  
   for(int i =0;i<n;i++){
  
      if(sign[1]==1){
         x = val + digits[i];
         ans2 = min(ans2, solve(digits,sign,op+2,x,num));
      }
      
      if(sign[2]==1){
         x = val - digits[i];
         ans2 = min(ans2, solve(digits,sign,op+2,x,num));
      }
      
      if(sign[3]==1){
         x = val *digits[i];
         ans2 = min(ans2, solve(digits,sign,op+2,x,num));
      }
      
      if(sign[4]==1 && digits[i]!=0)
      {  x = val/digits[i];
         ans2 = min(ans2, solve(digits,sign,op+2,x,num));
      }

   }
   if(ans2!=INT_MAX)ans2++;
   return min(ans1,ans2);
   
}
 
int main(){

     
   cin>>n>>m>>o;
 
   int digits[n],sign[5]={0};
 
   for(int i=0; i<n;i++)cin>>digits[i];
 
   for(int i =0; i<m;i++){
      int x; cin>>x; sign[x]++;
   }
 
   cin>>num;
 
   int ans = INT_MAX;
 
   for(int i =0;i<n;i++){
      ans = min(ans, solve(digits,sign,1,digits[i],num));
   }
 
   if(ans!=INT_MAX)cout<<ans<<endl;
 
   else cout<<-1<<endl;
   return 0;
}
