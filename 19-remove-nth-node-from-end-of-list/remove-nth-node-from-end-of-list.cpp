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
        /*use tortoise and hare approach, whenever the fast pointer has its nextptr pointing at nullptr, then the slow->next is the node to remove, must remember to delete the pointer - store in temp node, relink, and then delete*/
        ListNode *slow = head;
        ListNode *fast = head;
        int i = 0;
        while(i < n && fast->next){
            fast = fast->next;
            i++;
        }
        if(i < n) return head->next;
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = slow->next;
        if(slow->next) slow->next = slow->next->next;
        delete temp;
        return head;
    }
};