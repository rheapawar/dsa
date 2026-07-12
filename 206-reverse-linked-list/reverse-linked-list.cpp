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
        if(!head) return nullptr;
        ListNode *p = nullptr;
        ListNode *c = head;
        ListNode *n = head->next;

        while(c){
            c->next = p;
            if(!n) break;
            p = c;
            c = n;
            n = n->next;
        }
        return c;
    }
};