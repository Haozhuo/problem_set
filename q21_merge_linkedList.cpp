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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;
        
        ListNode* p = l1;
        ListNode* q = l2;
        
        for(; p!=NULL && q!=NULL;node=node->next){
            if(p->val >= q->val){
                node->next = new ListNode(q->val);
                q = q->next;
            }else{
                node->next = new ListNode(p->val);
                p = p->next;
            }
        }
        
        if(p==NULL){
            for(;q!=NULL;q=q->next,node=node->next)
                node->next = new ListNode(q->val);
                
        }
        
        if(q==NULL)
            for(;p!=NULL;p=p->next,node=node->next)
                node->next = new ListNode(p->val);
                
        return dummy->next;
    }
};