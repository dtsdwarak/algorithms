/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if (!head)
            return nullptr;
        
        unordered_map<Node*, Node*> newOldPointerMap;
        Node *prev = nullptr, *start = head, *copyStart;
        
        while(head) {
            Node *newNode = new Node(head->val);
            newOldPointerMap[head] = newNode;
            if (!prev)
                copyStart = newNode;
            else
                prev->next = newNode;
            prev = newNode;
            head = head->next;
        }
        
        while(start) {
            
            newOldPointerMap[start]->random = (start->random == nullptr) ? nullptr : newOldPointerMap[start->random];
            start = start->next;
            
        }
        
        return copyStart;
        
    }
};
