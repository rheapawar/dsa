/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode *x = head->next;
        unordered_map<ListNode*, int> map;
        map[head] = -1;
        int idx = 1;
        while(x){
            if(map[x] == 0){
                map[x] = idx++;
                x = x->next;
            }
            else return (map[x] == -1) ? head : x;
        }
        return nullptr;
    }
};