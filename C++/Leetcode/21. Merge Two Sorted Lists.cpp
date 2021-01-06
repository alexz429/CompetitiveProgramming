/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//simple comparison between the two nodes; struct understanding more than algo
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* cur = nullptr;
        while((l1!=nullptr)||(l2!=nullptr)){
            if(l1==nullptr||(l2!=nullptr&&l2->val<l1->val)){
                cur = new ListNode(l2->val, cur);
                l2 = l2->next;
            }
            else{
                cur = new ListNode(l1->val, cur);
                l1 = l1->next;
            }
        }
        ListNode* out = nullptr;
        while(cur!=nullptr){//flip list around; works although bad
            out = new ListNode(cur->val, out);
            cur = cur->next;
        }
        return out;
        
    }
};