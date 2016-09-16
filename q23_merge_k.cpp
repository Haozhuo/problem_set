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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return sort(lists,0,lists.size()-1);
    }
private:
    ListNode* sort(vector<ListNode*>& lists, int b, int e){
        if(b>e)
            return nullptr;
        else if(b==e)
            return lists[b];
        else{
            int q = (b+e)/2;
            //first, sort and merge b to q and q to e
            ListNode* l1 = sort(lists,b,q);
            ListNode* l2 = sort(lists,q+1,e);
            //then merge them
            ListNode* result = mergeTwoLists(l1,l2);
            return result;
        }
    }

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