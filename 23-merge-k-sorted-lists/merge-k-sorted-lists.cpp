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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*need to track state of every single list, how would u do this? not like i would have an array of iterartors??? one pointing to the current item in the list that we are on but then have to compare it to every single next iterator? wiould u want to add t to a pq?? like a min pq? but that would be o*n squared would it not - couple of ways to think about it */
        struct compare{
            bool operator()(const ListNode* a, const ListNode* b) const{
                return a->val > b->val;
            }
        };
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        ListNode *head = new ListNode();
        ListNode *curr = head;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]) pq.push(lists[i]);
        }
        while(!pq.empty()){
            curr->next = pq.top();
            if(pq.top()->next) pq.push(pq.top()->next);
            pq.pop();
            curr = curr->next;
        }
        return head->next;
    }
};