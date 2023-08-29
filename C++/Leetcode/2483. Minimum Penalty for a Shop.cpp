class Solution {
public:
    int bestClosingTime(string customers) {
        int sum = 0;
        vector<int> psa(customers.size(), 0);
        for(int i=0;i<customers.size();i++){
            if(customers[i] == 'Y'){
                sum++;
            }
            psa[i] = sum;
        }
        int best = 0;
        int min = sum;
        for(int i=0;i<customers.size();i++){
            int next = (sum - psa[i]) + (i + 1 - psa[i]);
            // cout << next << endl;
            if(min > next){
                min = next;
                best = i+1;
            }
        }
        return best;
    }
};