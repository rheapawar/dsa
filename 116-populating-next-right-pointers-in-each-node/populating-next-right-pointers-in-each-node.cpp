/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            Node *x;
            for(int i = 0; i < s -1; i++){
                x = q.front();
                q.pop();
                x->next = q.front();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            x = q.front();
            x->next = nullptr;
            q.pop();
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
        }
        return root;
    }
};