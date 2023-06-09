#include<iostream>
using namespace std;
int main(){
   int mat[3][3], trans[3][3];
   
  for(int r=0;r<3;r++) {
    for(int c=0;c<3;j++) {
      trans[r][c] = mat[c][r];
    }
  }
  
  return 0;
}