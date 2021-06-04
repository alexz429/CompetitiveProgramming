//binary search for power
class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = 46340;
        while(low<high){
            int mid = (low+high+1)/2;
            if(mid*mid>x){
                high = mid-1;
            }
            else{
                low = mid;
            }
        }
        return low;
    }
};