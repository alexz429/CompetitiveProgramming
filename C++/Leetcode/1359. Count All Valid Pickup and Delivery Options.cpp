class Solution {
public:
    int countOrders(int n) {
        long long output = 1;
        for(int i=1;i<n;i++){
            int x = i*2+1;
            long long sum = (x*(x+1))/2;
            output *= sum;
            output %= 1000000007;
        }
        return output;
    }
};