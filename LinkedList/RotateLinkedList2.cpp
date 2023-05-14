/**
 * Def : Given the head of a singly linked list and two integers left and
 * right where left <= right, reverse the nodes of the list from position
 * left to position right, and return the reversed list.
 *
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *leftList = dummy, *rightList = head, *temp = NULL, *nextNode = NULL, *curr, *currR;

        for (int i = 0; i < left - 1; i++)
            leftList = leftList->next;

        // pointing to left
        curr = leftList->next;

        // Pointing to left
        currR = curr;

        for (int i = left; i <= right; i++)
        {
            nextNode = curr->next;
            curr->next = temp;
            temp = curr;
            curr = nextNode;
        }

        leftList->next = temp;
        currR->next = curr;

        return dummy->next;
    }
};