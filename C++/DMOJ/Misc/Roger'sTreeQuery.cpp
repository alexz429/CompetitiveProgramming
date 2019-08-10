#include <bits/stdc++.h>

using namespace std;
class segment{
    public:
    int* diff;
    int size;
    vector<int> leftLink;
    vector<int> rightLink;
    map<int,int> direct;
    segment::segment(int maxSize){
        
        diff=new int[maxSize];
        fill(&diff[0], &diff[maxSize], 0);
    }
    void segment::pushSet(vector<int> children){
        int tally=0;
        for(int next:children){
            direct[next]=tally++;
        }
    }
    void pushLeft(int limit){
        diff[0]++;


    }

};