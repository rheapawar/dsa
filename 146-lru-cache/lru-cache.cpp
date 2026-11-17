class LRUCache {
private:
    struct Node{
        int k;
        int v;
        Node *prev;
        Node *next;
    };
    Node *first;
    Node *last;
    unordered_map<int, pair<int, Node*>> a;
    int max; 
public:
    LRUCache(int capacity) {
        first = nullptr;
        last = nullptr;
        max = capacity;
        a.reserve(capacity);
    }
    
    int get(int key) {
        if(a.find(key) == a.end()) return -1;
        Node *n = a[key].second;
        if(n != last){
            if(n->prev) n->prev->next = n->next;
            else first = n->next;
            if(n->next) n->next->prev = n->prev;
            last->next = n;
            n->prev = last;
            n->next = nullptr;
            last = n;
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
            first = new Node{key, value, nullptr, nullptr};
            last = first;
            a[key] = {value, first};
            return;
        }

        Node *n = new Node(key, value, last,nullptr);
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

 /*okay so obviously use a map for the underlying get/puts for o(1) access onlything to check is how to remove an element when we reach capacity, could have a vector of the order of elements we have and then a counter for the key number we are on 
 
 wait no but its about the least recently used key, so need to be able to easily move it if the key is used again, so no pq because u would have to search and then pop, use doubly linked list, easy to access and easy to move around, so the unordered map needs to have the iterator??, okay so using a doubly linked list and when using the doubly linked list it has to be able to remove the left pointer from it each time, but when u are accessing some element, u are going to need to where in the linked list it is, so maybe do a map of the linked list node and the
 
 
 
   */