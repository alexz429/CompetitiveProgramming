//rolling hash
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0)return 0;
        if(needle.length()>haystack.length())return -1;
        long long need = 0;
        long long power = 1;
        long long SENTINEL = 1000000007;
        for(int i=1;i<needle.length();i++){
            power = (power*26)%SENTINEL;
        }
        for(int i=0;i<needle.length();i++){
            need= (need*26)%SENTINEL + (needle[i]-'a');
        }
        long long comp = 0;
        for(int i=0;i<needle.length();i++){
            comp= (comp*26)%SENTINEL + (haystack[i]-'a');
        }
        if(comp==need)return 0;
        for(int i=0;i<(haystack.length()-needle.length());i++){
            comp = (comp + SENTINEL - power*(haystack[i]-'a'))%SENTINEL;
            comp = (comp*26)%SENTINEL + (haystack[i+needle.length()] - 'a');
            if(need==comp) return (i+1);
        }
        
            
            
        return -1;
    }
};