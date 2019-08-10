#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll thirdBase[20];
    ll pre=1;
    for(ll count=0;count<20;count++){
        thirdBase[count]=pre;
        pre*=3;
    }
    string bin,tri;
    cin>>bin>>tri;
    ll a=0,b=0;
    ll base=1,length=tri.length();
    
    for(ll count=0;count<length;count++){
        b+=(tri.at(length-count-1)-'0')*base;
        base*=3;
    }
     base=1,length=bin.length();
    
    for(ll count=0;count<length;count++){
        a+=(bin.at(length-count-1)-'0')*base;
        base*=2;
    }
    
    ll val=1;

    for(ll count=0;count<length;count++){
        ll OG;
        if((a&val)!=0){
            OG=a-val;
        }
        else{
            OG=a+val;
        }
        
        val<<=1;
        ll diff=log(abs(b-OG))/log(3);
        bool got=false;
        
        // prllf("%d\n", OG);
        if(tri.length()-1-diff<0||tri.length()-1-diff>=tri.length())continue;
        ll OG2=(b-(tri.at(tri.length()-1-diff)-'0')*thirdBase[diff]+0.5);
        for(ll count=0;count<3;count++){
            // prllf("%d comp", OG2);
            if(OG2==OG){
                got=true;
                break;
            }
            OG2+=thirdBase[diff];
        }
        if(got){
            printf("%lld", OG);
            return 0;
        }
    }    

}