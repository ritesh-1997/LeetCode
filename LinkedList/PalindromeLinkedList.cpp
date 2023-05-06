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

/**
 * 
 * get the length of list
 * find half and move one pointer to the half
 * reverse the second half of the list
 * and then move one pointer from first half and one from second
 * if val is different then return false other move till end of list
 * return tue after the loop
 * 
*/
class Solution {
public:
    
    bool isPalindrome(ListNode* head) {
        int size = 0;
        if(!head){
            return false;
        }
        
        // count size of list
        ListNode *start = head,*halfList = NULL;
        while(start){
            size++;
            start = start->next;
        }

        // find half size of list
        int half = size/2,i=0;

        // move to half of list
        halfList = head;

        while(i<half){
            i++;
            halfList = halfList->next;
        }
        //halfList = start;

        // reverse the second half;
        ListNode *temp = NULL, *nextNode = NULL,*newHead  =head;
        while(halfList){
            nextNode = halfList->next;
            halfList->next = temp;
            temp = halfList;
            halfList = nextNode;
        }

        // check for palindrome
        while(temp){
            if(temp->val != newHead->val){
                return false;
            }
            temp = temp->next;
            newHead = newHead->next;
        }
        return true;

    }
};