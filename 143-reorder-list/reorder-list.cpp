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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast =  fast->next->next;
        }

        ListNode* p = nullptr;
        ListNode* n = slow->next;
        while(slow){
            slow->next = p;
            p = slow;
            slow = n;
            if(n) n = n->next;
            
        }

        ListNode *curr = p;
        ListNode *first;
        ListNode* second;
        while(curr && head != curr){
            first = head->next;
            second = curr->next;
            head->next = curr;
            if(curr != first) curr->next = first;
            head = first;
            curr = second;
        }

         

    }
};