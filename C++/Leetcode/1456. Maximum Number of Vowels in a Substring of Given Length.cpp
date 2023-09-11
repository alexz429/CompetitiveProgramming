class Solution {
public:
    bool isVowel(char a){
        return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
    }
    int maxVowels(string s, int k) {
        int l = 0;
        int best = -1;
        int tally = 0;
        for(int i=0;i < s.size();i++){
            char next = s[i];
            if(isVowel(next)){
                tally++;
            }
            if(i >= k){
                if(isVowel(s[l]))tally--;
                l++;
            }
            best = max(best, tally);
        }
        return best;
    }
};