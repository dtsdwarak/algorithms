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
    ListNode* reverseList(ListNode* head) {
        
        if (!head)
            return head;
        
        ListNode *prev = nullptr, *temp;
        
        while(head->next) {
            
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        
        head->next = prev;
        return head;
        
    }
};
