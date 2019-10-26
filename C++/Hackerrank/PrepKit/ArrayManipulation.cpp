long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> psa(n);
    for(vector<int> next:queries){
        psa[next[0]-1]+=next[2];
        if(next[1]!=n){
            psa[next[1]]-=next[2];
        }
    }
    long best=0;
    long tally=0;
    for(int next:psa){
        tally+=next;
        best=max(best,tally);
    }
    return best;

}