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
    ListNode* reverseKGroup(ListNode* head, int k) {
        /*make separate reverse helper function, then go thru create a prev curr next in outer method as well, keeps track of where the flipped curr node needs to connect to*/
        int i;
        ListNode dummy(0);
        ListNode *p = &dummy;
        ListNode *c = head;
        ListNode *n = head;
        while(c){
            i = 0;
            while(i < k && n){
                n = n->next;
                i++;
            }
            if (i < k) break;
            else{
                ListNode *tmp = reverse(c, n);
                c->next = n;
                p->next = tmp;
                p = c;
                c = n;
            }
        }
        return dummy.next;
    }

    ListNode* reverse(ListNode* head, ListNode *end){
        ListNode* p = nullptr; 
        ListNode *c = head;
        ListNode *n = head->next;
        while(c != end){
            c->next = p;
            p = c;
            c = n;
            if(n) n = n->next;
        }
        return p;

    }
};