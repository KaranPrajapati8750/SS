/*
7

5 10
2 3 5 7 6 2 1 9 8 5
 
4 7
12 3 5 67 54 3 4
 
8 9
1 2 3 4 5 6 7 8 9
 
4 10
9 18 7 6 3 24 1 5 8 9
 
1 4
1 2 3 4
 
5 4
1 2 3 4
 
2 15
1 34 5 7 3 21 90 81 32 4 23 42 84 11 29
 
output -
4 
59
6
11 
0 
-1 
1



*/

#include <iostream>
using namespace std;

#define INT_MAX 10000

#define INT_MIN -10000

int companies, mines, ANS;

void calculateOilMines(int i, int minesArr[], bool visited[], int minV, int maxV, int sum,
                        int divisions){
    // Base Case
   
    if(visited[i]){
        int newMin = min(sum, minV);
        int newMax = max(sum, maxV);

        if(divisions == companies - 1){
            ANS = min(ANS, newMax - newMin);
        }
        return;
    }

    // Main Case
    visited[i] = 1;
    int j = (i + 1) % mines;//mines are adjacent to each other,they should be include in circular fashion

    calculateOilMines(j, minesArr, visited, minV, maxV, sum + minesArr[i], divisions);

    int newMax=max(sum,maxV);
    int newMin=min(sum,minV);


    calculateOilMines(j, minesArr, visited, newMin, newMax, minesArr[i], divisions + 1);
    visited[i] = 0;
    return;
}

int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--){

        cin>>companies>>mines;

        int minesArr[mines];

        for(int i=0; i<mines;i++){
            cin>>minesArr[i];
        }

        if(companies>mines){
            cout<<-1<<endl;
        }

        else{

            bool visited[mines+1];

            for(int i=0; i<=mines; i++){
                visited[i] = 0;
            }
                
            ANS = INT_MAX;    
            for(int i=0; i<mines; i++)
                calculateOilMines(i, minesArr, visited, INT_MAX, INT_MIN, 0, 0);  

            cout << ANS <<endl; 
        }       
    }
    return 0;

}