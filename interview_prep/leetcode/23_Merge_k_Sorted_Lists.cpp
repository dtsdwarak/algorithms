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

    ListNode* mergeLists(ListNode* list1, ListNode* list2) {

        ListNode *l1 = list1, *l2 = list2, *head, *start;

        if (!l1)
            return l2;
        if (!l2)
            return l1;

        if (l1->val < l2->val) {
            start = l1;
            l1 = l1->next;
        } else {
            start = l2;
            l2 = l2->next;
        }

        head = start;

        while(l1 && l2) {
            if (l1->val < l2->val) {
                head->next = l1;
                head = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                head = l2;
                l2 = l2->next;
            }
        }

        while(l1) {
            head->next = l1;
            head = l1;
            l1 = l1->next;
        }

        while(l2) {
            head->next = l2;
            head = l2;
            l2 = l2->next;
        }

        return start;

    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if (lists.size() == 0) {
            return nullptr;
        }

        if (lists.size() == 1) {
            return lists[0];
        }

        if (lists.size() > 2) {

            int i=0;
            vector<ListNode*> merged;
            for(; i+1 < lists.size(); i += 2) {
                vector<ListNode*> candidates = {lists[i], lists[i+1]};
                auto mergedList = mergeKLists(candidates);
                merged.push_back(mergedList);
            }

            if (i<lists.size())
                merged.push_back(lists[i]);

            return mergeKLists(merged);
        }

        return mergeLists(lists[0], lists[1]);

    }
};
