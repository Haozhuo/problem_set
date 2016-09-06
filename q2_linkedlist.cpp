/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <string>
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(l1 != NULL && l2 != NULL){
      ListNode *dummy = new ListNode(0);
      ListNode * p = dummy;
      int n1 = 0;
      int n2 = 0;
      int carry = 0;

      while(true){
        if(l1==NULL && l2==NULL)
          break;

        n1 = (l1 != NULL) ? l1->val : 0;
        n2 = (l2 != NULL) ? l2->val : 0;

        int sum = carry + n1 + n2;
        carry = (sum) / 10;


        p->next = new ListNode(sum%10);
        p = p->next;

        if(l1 != NULL)
          l1 = l1->next;
        if(l2 != NULL)
          l2 = l2->next;

      }

      if(carry > 0){
        p->next = new ListNode(carry);
      }

      return dummy->next;
    }else{
      return NULL;
    }


  }
};
