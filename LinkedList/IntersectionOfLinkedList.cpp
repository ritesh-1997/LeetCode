/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *head1 = headA, *head2 = headB;
        int l1=0,l2 =0, diff = 0;

        // Finding the length of first list
        while(head1){
            l1++;
            head1 = head1->next;
        }

        // Finding the length of second list
        while(head2){
            l2++;
            head2 = head2->next;
        }

        // finding the bigger list
        if(l1<l2){
            head1 = headB ,head2 = headA, diff = l2-l1;
        }
        else{
            head1 = headA, head2 = headB, diff = l1-l2;
        }

        // Moving forward d step in bigger list
        for(int i=0;i<diff;i++){
            head1 = head1->next;
        }

        // Moving 1-1 in both list till we find the same node
        while(head1 && head2){
            if(head1 == head2){
                return head1;
            }
            else{
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        return NULL;
    }
};