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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* dummyNode = new ListNode(0);
       dummyNode->next = head;

       ListNode* first = dummyNode;
       ListNode* second = dummyNode;

       for(int i = 0; i <= n; i++)
            first=first->next;

        while(first != NULL){
            first=first->next;
            second=second->next;
        }

        second->next=(second->next)->next;

        return dummyNode->next;
    }
};