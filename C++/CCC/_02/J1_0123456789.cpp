#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string two=" * * *\n      *\n      *\n      *\n * * *\n*\n*\n*\n * * *\n";
string one="      *\n      *\n      *\n\n      *\n      *\n      *\n";
string three=" * * *\n      *\n      *\n      *\n * * *\n      *\n      *\n      *\n * * *\n";
string four="*     *\n*     *\n*     *\n * * *\n      *\n      *\n      *\n";
string five=" * * *\n*\n*\n*\n * * *\n      *\n      *\n      *\n * * *\n";
string six=" * * *\n*\n*\n*\n * * *\n*     *\n*     *\n*     *\n * * *\n";
string seven=" * * *\n      *\n      *\n      *\n\n      *\n      *\n      *\n";
string eight=" * * *\n*     *\n*     *\n*     *\n * * *\n*     *\n*     *\n*     *\n * * *\n";
string nine=" * * *\n*     *\n*     *\n*     *\n * * *\n      *\n      *\n      *\n * * *\n";
string zero=" * * *\n*     *\n*     *\n*     *\n\n*     *\n*     *\n*     *\n * * *\n";
string output[10];
int main(){
    output[0]=zero;
output[1]=one;
output[2]=two;
output[3]=three;
output[4]=four;
output[5]=five;
output[6]=six;
output[7]=seven;
output[8]=eight;
output[9]=nine;
string *index=&output[0];
int add;
scanf("%d", &add);
// printf("%d", add);
index+=add;
    std::cout<<*index;
}
