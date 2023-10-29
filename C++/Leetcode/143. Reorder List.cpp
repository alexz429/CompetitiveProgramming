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
 using namespace std;
class Solution {
public:

    //first sol with O(n) memory
    vector<ListNode*> nodeArr;

    void recurse(int idx, ListNode* at){
        nodeArr.push_back(at);
        if(at->next){
            recurse(idx+1, at->next);
        }
        if(idx > nodeArr.size() / 2){
            at->next = nodeArr[nodeArr.size() - idx];
        }
        else if(idx == nodeArr.size() / 2){
            at->next = nullptr;
        }
        else{
            at->next = nodeArr[nodeArr.size() - 1 - idx];
        }
    }

    void reorderList(ListNode* head) {
        recurse(0, head);
    }

    // second sol with O(1) memory
    ListNode* at;
    int traversed = 0;
    int done = 0;

    void recurse(ListNode* cur){
        traversed++;
        if(cur->next){
            recurse(cur->next);
        }
        if(done == (traversed - 1) / 2){
            cur->next = nullptr;
        }
        else if(done < (traversed - 1) / 2){
            cur->next = at->next;
            at->next = cur;
            at = cur->next;
        }
        done++;
    }

    void reorderList(ListNode* head) {
        at = head;
        recurse(head);
    }
};