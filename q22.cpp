class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        if(lists.size()==1)
            return lists[0];
        
        ListNode* newList = mergeTwoLists(lists[0],lists[1]);
        
        for(int i = 2; i < lists.size(); i++){
            newList = mergeTwoLists(newList,lists[i]);
        }
        
        return newList;
        
    }
private:
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