class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--){
            digits[i]++;
            if(digits[i]!=10)return digits;
            digits[i]=0;
        }
        digits.insert(digits.begin(),1);//edge case when all the digits are 9
        return digits;
    }
};