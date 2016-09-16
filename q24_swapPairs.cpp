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
    ListNode* swapPairs(ListNode* head) {
        ListNode* p = head;
        int counter = 0;
        for(;p!=NULL;p=p->next){
            counter++;
        }
        
        if(counter<2)
            return head;
        //swap the first two    
        p = head;
        ListNode* l1 = new ListNode(p->val);
        p = p->next;
        ListNode* l2 = new ListNode(p->val);
        p = p->next;
        //the rest is already swapped
        ListNode* l3 = swapPairs(p);
          
        l2->next = l1;
        l1->next = l3;
        
        return l2;
    }
};