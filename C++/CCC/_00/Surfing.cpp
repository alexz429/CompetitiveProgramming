#include <bits/stdc++.h>
using namespace std;
unordered_set<string> hit;
map<string, vector<string>> direct;
    
bool recurse(string at, string goal){
    if(at.compare(goal)==0){
        return true;
    }
    if(hit.find(at)!=hit.end()){
        return false;
    }
    hit.insert(at);
    for(string next:direct[at]){
        if(recurse(next,goal))return true;
    }
    return false;
    
}
int main(){
    // ofstream cout;
    // ifstream cin;
    // cin.open("C:\\Users\\alex.zhang\\Desktop\\SURF.IN2");
    // cout.open("C:\\Users\\alex.zhang\\Desktop\\OUTPUT.txt");
    int max;
    cin>>max;
    for(int count=0;count<max;count++){
        string from;
        cin>>from;
        while(true){
            string next;
            getline(cin, next);
            int index=0;
            while((index=next.find("<A HREF=", index))!=string::npos){
                
                index+=9;
                int limit=next.find(">", index);
                cout<<"Link from "<<from<<" to "<<next.substr(index,limit-index-1)<<endl;
                direct[from].push_back(next.substr(index,limit-index-1));
                
            }
            if(next.find("</HTML>")!=string::npos){
                // printf("_________________________");
                break;
            }
        }
    }
    // printf("______________________________");
    string next;
    getline(cin,next);

    
    while(next.compare("The End")!=0){
        hit.clear();
        string next2;
        getline(cin,next2);
        if(recurse(next,next2)){
            cout<<"Can ";
        }
        else{
            cout<<"Can't ";
        }
        cout<<"surf from "<<next<<" to "<<next2<<"."<<endl;
        getline(cin,next);
    }

}