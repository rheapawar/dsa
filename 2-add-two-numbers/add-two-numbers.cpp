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
        /*initial thoughts - do the numbers need to be extracted into ints first or can u parse simultaneously while adding, have a carry over and also an index so we know what factor of 10 to multiply by or rather just keep a multilier value and just multiply the new result before adding it on*/
        int curr = 0;
        int carry = 0;
        ListNode *dummy = new ListNode{0};
        ListNode *ans = dummy;

        while(l1 && l2){
            curr = l1->val + l2->val + carry;
            carry = curr / 10;
            curr %= 10;
            ans->next = new ListNode{curr};
            l1 = l1->next;
            l2 = l2->next;
            ans = ans->next;
        }
        while(l1){
            curr = l1->val + carry;
            carry = curr / 10;
            curr %= 10;
            ans->next = new ListNode{curr};
            l1 = l1->next;
            ans = ans->next;

        }
        while(l2){
            curr = l2->val + carry;
            carry = curr / 10;
            curr %= 10;
            ans->next = new ListNode{curr};
            l2 = l2->next;
            ans = ans->next;
        }
        if(carry != 0){
            ans->next = new ListNode{carry};
        }
        return dummy->next;
    }
};