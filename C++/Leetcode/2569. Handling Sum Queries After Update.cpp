class Solution {
    struct segTree{
        int sum;
        bool dirty;
        segTree* left;
        segTree* right;
    };

    segTree* head;

    void init(segTree* at, int l, int r, vector<int>& arr){
        // cout << l << " " << r << endl;
        if(l == r){
            at->sum = arr[l];
            return;
        }
        at->left = new segTree();
        at->right = new segTree();
        init(at->left, l, (l + r)/2, arr);
        init(at->right, (l + r)/2+1, r, arr);
        at->sum = at->left->sum + at->right->sum;
        return;
    }

    void update(segTree* at, int l, int r, int min, int max, bool dirty){
        // cout << l << " "<< r << endl;
        dirty ^= at->dirty;
        at->dirty = false;
        if(l>=min && r<=max){
            //update current sum, send dirty bit to children
        }
        else if(r<min || l > max){
            // flip dirty bit as we are out the range
            dirty^=true;
        }
        else{
            //don't resolve dirties until later
            update(at->left, l, (l + r)/2, min, max, dirty);
            update(at->right,(l + r)/2+1, r, min, max, dirty);
            at->sum = at->left->sum + at->right->sum;
            return;
        }
        // if we are still dirty, flip current sum, and dirty children
        if(at->left) at->left->dirty ^= dirty;
        if(at->right) at->right->dirty ^= dirty;
        int og = at->sum;
        if(dirty){
            at->sum = (r-l+1) - at->sum;
        }
    }

public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        long long sum = 0;
        vector<long long> output;
        for(int next: nums2){
            sum+=next;
        }
        head = new segTree();
        init(head, 0, nums1.size()-1, nums1);
        for(vector<int> next: queries){
            if(next[0] == 1){
                cout << nums1.size() << endl;
                update(head, 0, nums1.size()-1, next[1], next[2], true);
            }
            else if(next[0] == 2){
                sum += (long long)next[1]*(long long)head->sum;
            }
            else{
                output.push_back(sum);
            }
        }
        return output;
    }
};