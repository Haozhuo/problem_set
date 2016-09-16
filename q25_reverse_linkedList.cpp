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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        for(int i = 0; i < k; i++){
            //less than k nodes
            if(p==NULL)
                return head;
            
            p = p->next;
        }
        
        ListNode* new_list_head = reverse_firstK(head,p);
        ListNode* rest_head = reverseKGroup(p,k);
        head->next=rest_head;
        
        return new_list_head;
        
    }
private:
    ListNode* reverse_firstK(ListNode* b, ListNode* e){
        ListNode* prev = e;
        while(b != e){
            ListNode* temp = b->next;
            b->next = prev;
            prev=b;
            b=temp;
        }
        
        return prev;
    }
   
};