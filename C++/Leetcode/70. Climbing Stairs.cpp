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

/*
recursive rebuilding of listnode using global array
offset array by 200 to make sure negative numbers aren't out of bounds (not optimized but who cares)
*/
class Solution {
public:
    bool lol[500];
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(lol[head->val+200]) return (deleteDuplicates(head->next));
        lol[head->val+200]=true;
        head->next = deleteDuplicates(head->next);
        return head;
    }
};