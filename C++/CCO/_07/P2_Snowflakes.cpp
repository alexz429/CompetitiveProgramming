#include <bits/stdc++.h>

using namespace std;
unordered_set<string> lmao;
int input[6];
int main(){
    int max;
    cin>>max;
    
    for(int count=0;count<max;count++){
          for(int i=0;i<6;i++){
              cin>>input[i];
          }
          string least="a";
          for(int i=0;i<6;i++){
              string build="";
              for(int j=0;j<6;j++){
                  build+=to_string(input[(i+j)%6])+" ";
              }
              least=build.compare(least)<0?build:least;
            //   cout<<build<<endl;
              build="";
              for(int j=0;j<6;j++){
                  build+=to_string(input[(i-j+6)%6])+" ";
              }
              least=build.compare(least)<0?build:least;
            //   cout<<build<<endl;
          }
        //   cout<<least<<endl;
          if(lmao.find(least)!=lmao.end()){
            cout<<"Twin snowflakes found."<<endl;
            return 0;
          }  
          lmao.insert(least);
    }
    cout<<"No two snowflakes are alike."<<endl;
}