//Subtract price of every possible day with smallest price up to that point
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best = 0, small = 100000;
        for(int i=0;i<prices.size();i++){
            small = min(prices[i], small);
            best = max(best, prices[i]-small);
        }
        return best;
    }
};