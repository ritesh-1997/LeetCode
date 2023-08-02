/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode SwapPairs(ListNode head) {
        ListNode slow = head,fast = head;
        int temp;
        while(slow !=null && slow.next!=null){
            fast = slow.next;
            temp = slow.val;
            slow.val = fast.val;
            fast.val = temp;
            slow = fast.next;
        }
        return head;
    }
}