#include<iostream>
using namespace std;
int main(){
   int matrix[3][3], transMatrix[3][3];
   cout<<"Enter elements of matrix: "<<endl;
   for(int i =0;i<3;i++) {
     for(int j=0;j<3;j++) {
       cin>>matrix[i][j];
     }
   }
   // Finding the transpose matrix.
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      transMatrix[j][i] = matrix[i][j];
    }
  }
  
  return 0;
}