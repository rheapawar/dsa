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
        //need to have some way of mapping the new nodes we create with the old ones so that as we create and copy we prevent from needing new one, can have multiple nodes with the same value as well
        if(!head) return nullptr;
        Node* dummy = new Node(0);
        Node* c = new Node(head->val);
        Node* r;
        Node* n;
        dummy->next = c;

        unordered_map<int, vector<pair<Node*, Node*>>> m;
        m[head->val].push_back({head, c});
        while(head){
            r = nullptr;
            n = nullptr;
            if(head->next){
                auto v = m[head->next->val];
                for(auto it = v.begin(); it != v.end(); it++){
                    if(it->first == head->next){
                        n = it->second;
                        break;
                    }
                }
                if(!n){
                    n = new Node(head->next->val);
                    m[n->val].push_back({head->next, n});
                }
            }

            if(head->random){
                auto v = m[head->random->val];
                for(auto it = v.begin(); it != v.end(); it++){
                    if(it->first == head->random){
                        r = it->second;
                        break;
                    }
                }
                if(!r){
                    r = new Node(head->random->val);
                    m[r->val].push_back({head->random, r});
                }
            }
            c->next = n;
            c->random = r;
            c = c->next;
            head = head->next;
        }
        return dummy->next;

    }
};