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
 * In a linked list of size n, where n is even, the ith node (0-indexed)
 * of the linked list is known as the twin of the (n-1-i)th node,
 * if 0 <= i <= (n / 2) - 1.
 *
 * For example, if n = 4, then node 0 is the twin of node 3, and node 1 is
 * the twin of node 2. These are the only nodes with twins for n = 4.
 * The twin sum is defined as the sum of a node and its twin.
 *
 * Given the head of a linked list with even length,
 * return the maximum twin sum of the linked list.
 */

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        if (head->next->next == NULL)
        {
            return head->val + head->next->val;
        }
        ListNode *h1 = head, *h2 = head->next;

        while (h2 && h2->next && h2->next->next)
        {
            h1 = h1->next;
            if (h2->next)
                h2 = h2->next->next;
        }
        ListNode *temp = NULL, *next = NULL, *half = h1, *x = head;
        h1 = h1->next;
        while (h1)
        {
            next = h1->next;
            h1->next = temp;
            temp = h1;
            h1 = next;
        }
        half->next = temp;
        half = half->next;
        int res = 0;
        while (half)
        {
            int sum = x->val + half->val;
            res = max(res, sum);
            x = x->next;
            half = half->next;
        }
        return res;
    }
};