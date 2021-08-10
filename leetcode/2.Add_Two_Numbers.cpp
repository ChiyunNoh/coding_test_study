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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* l3 = new ListNode(0);
        
        ListNode* head= l3;
        int carry=0;
        
        //While both the lists are present
        while(l1!=NULL && l2!=NULL){
            int value = l1->val+l2->val + carry;
            carry = value>=10 ? 1: 0;
            value = carry==0 ? value : value-10;

            head->next = new ListNode(value);
            head=head->next;
            
            l1=l1->next;l2=l2->next;
        }
        
        //When one of the list has finished
        while(l1!=NULL){
            int value = l1->val+carry;
            carry = value>=10 ? 1: 0;
            value = carry==0 ? value : value-10;
            
            
            head->next = new ListNode(value);
            head=head->next;
            l1=l1->next;
        }
        
        while(l2!=NULL){
            int value = l2->val + carry;
            carry = value>=10 ? 1: 0;
            value = carry==0 ? value : value-10;
            
            
            head->next = new ListNode(value);
            head=head->next;
            l2=l2->next;
        }
        
        //If carry is left in the end
        if(carry)
        {
            head->next = new ListNode(carry);
        }
        
        return l3->next;
    }
};