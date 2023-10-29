using namespace std;
//I gave up and set everything to long longs because some operations were overflowing
//and I got too lazy to mod properly
typedef long long ll;
class Solution {
public:

    ll SEN = 1000000007;

    struct node{
        node* left;
        node* right;
        ll lazy = 0; //unapplied to CURRENT and children
        ll sum = 0;
        ll sqSum = 0;
    };

    node* head;

    ll arr[100000];
    ll prev[100000];

    //build just initializes segtree
    void build(node* at, ll l, ll r, ll a, ll b){
        if(l==r) return;
        at->left = new node();
        at->right = new node();
        ll mid = (l+r)/2;
        build(at->left, l, mid, a, b);
        build(at->right, mid+1, r, a, b);
    }

    void processLazy(node* at, ll l, ll r){
        ll x = at->lazy;
        if(x == 0) return;
        // cout << x << l << r << " "<<at->sqSum<<" "<<at->sum << endl;
        at->sqSum += at->sum*x*2 + (r - l + 1)*x*x;
        at->sum += (r-l+1)*x;
        at->sqSum %= SEN;
        at->sum %= SEN;
        if(l!=r){
            at->left->lazy+=x;
            at->right->lazy+=x;
        }
        at->lazy = 0;
    }

    ll qSum(node* at, ll l, ll r, ll a, ll b){
        //oob
        if(r < a || l > b) return 0;
        //process lazy if they exist
        processLazy(at, l, r);
        if(l>=a && r<=b){
          return at->sum;
        }
        ll mid = (l+r)/2;
        return (qSum(at->left, l, mid, a, b)
        + qSum(at->right, mid+1, r, a, b)) % SEN;
    }

    ll qSumSq(node* at, ll l, ll r, ll a, ll b){
        //oob
        if(r < a || l > b) return 0;
        //process lazy if they exist
        processLazy(at, l, r);
        if(l>=a && r<=b){
          return at->sqSum;
        }
        ll mid = (l+r)/2;
        return (qSumSq(at->left, l, mid, a, b)
        + qSumSq(at->right, mid+1, r, a, b))%SEN;
    }
    //[a, b]
    ll add(node* at, ll l, ll r, ll a, ll b){
        //oob
        if(r < a || l > b) return 0;
        processLazy(at, l, r);
        if(l>=a && r<=b){
          ll prevVal = at->sum;
          at->lazy += 1;  
          processLazy(at, l, r);
          return prevVal;
        }
        ll mid = (l+r)/2;
        //process current level
        ll addVal = add(at->left, l, mid, a, b) +
        add(at->right, mid+1, r, a, b);
        ll range = min(b-a+1, min(r - a + 1, b - l + 1));
        // cout << l << r << a << b <<" "<< addVal << " " << range << endl;
        at->sqSum += ((addVal*2)%SEN + range)%SEN;
        at->sqSum %= SEN;
        at->sum += range;
        at->sum %= SEN;
        return addVal;
    }

    int sumCounts(vector<int>& nums) {
        ll output = 0;
        head = new node();
        build(head, 0, nums.size()-1, 0, nums.size()-1);
        for(ll i=0;i<100000;i++){
            prev[i] = -1;
        }
        for(ll i=0;i<nums.size();i++){
            ll next = nums[i];
            ll splitIdx = prev[next-1];
            // cout << splitIdx << endl;
            add(head, 0, nums.size()-1, splitIdx + 1, i);
            // cout << "query "<<endl;
            output += qSumSq(head, 0, nums.size()-1, 0, i);
            output %= SEN;
            prev[next - 1] = i;
        }
        return output;
    }
};