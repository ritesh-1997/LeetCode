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

 /**
 Given a linked list, swap every two adjacent nodes and return its head. 
 You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example Input
 Input 1: 

 A = 1 -> 2 -> 3 -> 4
 Input 2: 

 A = 7 -> 2 -> 1


Example Output
 Output 1: 

 2 -> 1 -> 4 -> 3
 Output 2: 

 2 -> 7 -> 1
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