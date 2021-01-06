#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string in;
    cin>>in;
    if(in.compare("Saturday")==0){
        cout<<"Sunday\n";
    }
    else if(in.compare("Sunday")==0){
        cout<<"Monday\n";
    }
    else if(in.compare("Monday")==0){
        cout<<"Tuesday\n";
    }
    else if(in.compare("Tuesday")==0){
        cout<<"Wednesday\n";
    }
    else if(in.compare("Wednesday")==0){
        cout<<"Thursday\n";
    }
    else if(in.compare("Thursday")==0){
        cout<<"Friday\n";
    }
    else if(in.compare("Friday")==0){
        cout<<"Saturday\n";
    }
}