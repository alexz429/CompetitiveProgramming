void minimumBribes(vector<int> q) {
    set<int> set;
    for(int i=0;i<q.size();i++){
        set.insert(i+1);
    }
    int total=0;
    for(int i=0;i<q.size();i++){
        set.erase(q[i]);
        int temp=0;
        // printf("%d\n",total);
        int tally=0;
        for(int next:set){
            if(tally>=3)break;
            if(next<q[i]){
                temp++;
            }
            if(temp>2){
                printf("Too chaotic\n");
                return;
            }
            tally++;
        }
        total+=temp;
    }
    printf("%d\n", total);
}