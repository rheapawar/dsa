class LRUCache {
public:

    struct Node{
            int k;
            Node* prev;
            Node* next;
        };
    Node* first;
    Node* last;
    unordered_map<int, pair<int, Node*>> a;
    int max;

    LRUCache(int capacity) {
        first = nullptr;
        last = nullptr;
        max = capacity;
        a.reserve(capacity);
    }
    
    int get(int key) {
        if(a.find(key) == a.end()) return -1;
        Node *n = a[key].second;
        if(a.size() != 1){
            if(n != last){
                if(n->prev) n->prev->next = n->next;
                else first = n->next;
                if(n->next) n->next->prev = n->prev;
           
                last->next = n;
                n->prev = last;
                n->next = nullptr;
                last = n;
            
            }
           
           
            
        }
            
        return a[key].first;
        
       
    }
    
    void put(int key, int value) {
        if(a.find(key) != a.end()){
            get(key);
            a[key] = {value, last};
            return;
        }
        if(a.size() == 0){
            first = new Node{key, nullptr, nullptr};
            last = first;
            a[key] = {value, first};
            return;
        }
    
        Node *n = new Node(key, last, nullptr);
        last->next = n;
        last = n;
        
        if(a.size() != max){
            a[key] = {value, n};
            return;
        }
        
        a.erase(first->k);
        a[key] = {value, n};
        Node *x = first->next;
        x->prev = nullptr;
        delete first;
        first = x;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */