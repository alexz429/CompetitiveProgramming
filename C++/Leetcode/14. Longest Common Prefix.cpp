//vertical scanning: see if every 0th character is the same, the  1st, 2nd.... until either different chars are found or it exceeds a string
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)return "";
        for(int i=0;true;i++){
            char prev = 'A';
            bool done = true;
            for(string next: strs){
                if(next.length()==i||(prev!='A'&&prev!=next[i])){
                return strs[0].substr(0,i);
                }
                prev = next[i];
            }
        }
    }
};