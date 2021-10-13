/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
    public int recurse(ListNode cur, int n) {
        if (cur == null)
            return 0;
        int x = recurse(cur.next, n);
        if (x == n) {
            cur.next = cur.next.next;
        }
        return x + 1;
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        int test = recurse(head, n);
        if (test == n)
            return head.next;
        return head;
    }
}