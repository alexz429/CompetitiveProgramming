/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null)
            return null;
        boolean changed = false;
        while (head.next != null && head.val == head.next.val) {
            head = head.next;
            changed = true;
        }
        if (changed)
            head = deleteDuplicates(head.next);
        else
            head.next = deleteDuplicates(head.next);
        return head;
    }
}