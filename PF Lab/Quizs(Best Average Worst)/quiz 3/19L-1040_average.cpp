#include<iostream>
using namespace std;
int main(){
   int m[3][3], t[3][3];
   for(int i =0;i<3;i++) {
     for(int j=0;j<3;j++) {
       cin>>m[i][j];
     }
   }
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      m[j][i] = t[i][j];
    }
  }
  
  return 0;
}