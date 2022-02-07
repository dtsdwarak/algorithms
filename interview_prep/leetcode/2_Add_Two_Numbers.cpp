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
        
        ListNode *head = new ListNode, *prev, *res = head; 
        int carry = 0;
        
        while(l1 && l2) {
            
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            
            head->val = sum % 10;
            head->next = new ListNode;
            prev = head;
            head = head->next; 
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        l1 = !l1 ? l2 : l1;
        
        while(l1) {
            
            int sum = l1->val + carry;
            carry = sum/10;
            
            head->val = sum % 10;
            head->next = new ListNode;
            prev = head;
            head = head->next; 
            
            l1 = l1->next;
            
        }
        
        if (carry > 0)
            head->val = carry;
        else
            prev->next = nullptr;
        
        return res;
        
    }
};
