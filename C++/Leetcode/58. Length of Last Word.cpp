/*
    Implementation
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool space = false;
        for(int i=0;i<s.length();i++){
            
            if(s[i]==' '){
                space= true;
            }
            else{
                if(space){//to deal with trailing spaces, don't set count to 0 until new word is found.
                    count = 0;
                    space = false;
                }
                count++;
            }
        }
        return count;
    }
};