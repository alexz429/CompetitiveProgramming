void checkMagazine(vector<string> magazine, vector<string> note) {
    unordered_map<string, int> map;
    for(string next: magazine){
        if(map.find(next) == map.end()){
            map[next] =1;
        }
        else{
            map[next]++;
        }
    }
    for(string next:note){
        if(map.find(next) == map.end()|| map[next] <1){
            printf("No\n");
            return;
        }
        map[next]--;
    }
    printf("Yes\n");

}