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
        /*initial thoughts, when u come across a certain value, check for memory address and whether it has already been mapped to a new node in the new list - if so then point it at that, otherwise insert into hashmap. map from value into vector of pairs of new and old mem addresses?? space overhead tho, are there any alternates?
        
        cant do vector bc 10^4.
        --*/
        if(!head) return nullptr;
        unordered_map<int, vector<pair<Node*, Node*>>> map;
        Node *c = new Node{head->val};
        Node *new_head = c;
        Node *n;
        Node *r;
        map[head->val].push_back({head, c});
        while(head){
            n = nullptr;
            r = nullptr;
        if(head->next){
            auto it = map[head->next->val].begin();
            auto end = map[head->next->val].end();
            while(it != end){
                if(head->next == it->first){
                    n = it->second;
                    break;
                }
                it++;
            }
            if(!n){
                n = new Node{head->next->val};
                map[head->next->val].push_back({head->next, n});
            }
        }
        if(head->random){
            auto it2 = map[head->random->val].begin();
            auto end2 = map[head->random->val].end();
            while(it2 != end2){
                if(head->random == it2->first){
                    r = it2->second;
                    break;
                }
                it2++;
            }
            if(!r){
                r = new Node{head->random->val};
                map[head->random->val].push_back({head->random, r});
            }
        }
            c->next = n;
            c->random = r;
            c = n;
            head = head->next;
        }
        return new_head;
    }
};