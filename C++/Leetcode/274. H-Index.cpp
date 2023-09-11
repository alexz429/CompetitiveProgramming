class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0;
        int r = citations.size();
        while(l<r){
            int mid = (l+r+1)/2;
            int tally = 0;
            for(auto next: citations){
                if(next >= mid) tally++;
            }
            if(tally >= mid){
                l=mid;
            }
            else{
                r = mid-1;
            }
        }
        return l;
    }
};