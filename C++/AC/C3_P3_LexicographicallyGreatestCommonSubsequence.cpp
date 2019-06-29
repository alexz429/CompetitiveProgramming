#include <bits/stdc++.h>
using namespace std;
string* stuff;
int* indexes;
int main(){
    int max;
    
    scanf("%d", &max);
    
    stuff=new string[max];
    indexes=new int[max];
    fill(&indexes[0], &indexes[max], 0);
    // cout<<indexes[0]<<endl;
    for(int count=0;count<max;count++){
        cin>>stuff[count];
    }
    string out("");
    for(int count=0;count<26;count++){
        char next='z'-count;
        while(true){
            bool foundAll=true;
            int attempt[max];
            for(int count2=0;count2<max;count2++){
                // cout<<indexes[count2]<<endl;
                size_t at=stuff[count2].find(next, indexes[count2]);
                if(at!=string::npos){
                    attempt[count2]=(int)at+1;
                }
                else{
                    foundAll=false;
                    break;
                }
            }
            
            if(foundAll){
                for(int i=0;i<max;i++){
                    indexes[i]=attempt[i];
                }
                out.push_back(next);
            }
            else{
                break;
            }
        }
    }

    cout<<(out.size()==0?"-1":out)<<endl;
    
}