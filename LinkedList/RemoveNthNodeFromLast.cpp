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
class Solution {
public:
    int countLen(ListNode * head){
        int n = 0;
        while(head){
            n++;
            head = head->next;
        }
        return n;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = countLen(head);
        int nodeTORemove = len-n;
        ListNode * newHead = head;
        if(nodeTORemove == 0){
            return head->next;
        }
        else{
            while(nodeTORemove-1 && newHead){
                newHead = newHead->next;
                nodeTORemove--;
            }
            if(newHead->next)
                newHead->next = newHead->next->next;
        }

        return head;
    }
};