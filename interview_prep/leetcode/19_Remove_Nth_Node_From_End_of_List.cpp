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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (!head->next)
            return nullptr;
        
        ListNode *slow, *fast;
        slow = fast = head;
        int count = 0;
        
        while(fast && count<n) {
            fast = fast->next;
            count++;
        }
        
        if (!fast && count==n)
            return head->next;
        
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return head;
        
    }
};
