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
        if(!head){return nullptr;}
        ListNode *h = new ListNode(0);
        h->next = head;
        ListNode *ptr1 = head;
        ListNode *ptr2 = h;
        int x = 1;
        while(x <= n){
            ptr1 = ptr1->next;
            x++;
        }
        while(ptr1){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        
        ListNode* remove = ptr2->next;
        ptr2->next = ptr2->next->next;
        delete remove;
        return h->next;


    }
};