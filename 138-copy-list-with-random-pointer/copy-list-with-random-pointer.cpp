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
        if(!head) return nullptr;
        unordered_map<Node*, Node*> map; 
        Node *h = head;     
        while(h){ 
            map[h] = new Node(h->val);
            h = h->next;
        }
        h = head;
        while(h){
            map[h]->next = map[h->next];
            Node *n = (h->random) ? map[h->random] : nullptr;
            map[h]->random = n;
            h = h->next;
        }
        return map[head];
    }
};