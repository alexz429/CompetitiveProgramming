/*
DP:
substring i,j is a palindrome if substring i+1, j-1 is a palindrome and s[i]==s[j]
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int a = 0;
        int b = 1;
        int dp[s.length()][s.length()];
        for(int i=1;i<=s.length();i++){
            for(int j=0;j<=s.length()-i;j++){
                if(i<=2&&s[j]==s[j+i-1]){
                    dp[j][j+i-1]=1;
                }
                else if(dp[j+1][j+i-2]==1&&s[j]==s[j+i-1]){
                    dp[j][j+i-1] = 1;
                }
                else{
                    dp[j][j+i-1] = 0;
                }
                if(dp[j][j+i-1]==1&&i>b){
                    a = j;
                    b = i;
                }
            }
        }
        return s.substr(a,b);
    }
};