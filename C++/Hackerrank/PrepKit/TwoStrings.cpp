string twoStrings(string s1, string s2) {
    set<char> set;
    for(int i=0;i<s1.length();i++){
        set.insert(s1[i]);
    }
    for(int i=0;i<s2.length();i++){
        if(set.find(s2[i]) != set.end()){
            return "YES";
        }
    }
    return "NO";

}