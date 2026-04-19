
class Node{
public:
    int value;
    int key;
    Node* prev;
    Node* next;

    Node(int key, int value){
        this->key = key;
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};


class LRUCache {
public:
    unordered_map<int, Node*> address_map;
    int capacity;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
        
        this->capacity = capacity;
        
    }
    
    int get(int key) {
        if(address_map.find(key) == address_map.end()){
            return -1;
        }
        Node* node = address_map[key];
        removeNode(node);
        addNode(node);
        return node->value;
        
    }
    
    void put(int key, int value) {
        if(address_map.find(key) == address_map.end()){
            // not exist
            Node* newNode = new Node(key, value);
            addNode(newNode);
            address_map[key] = newNode;

            if(address_map.size() > capacity){
                address_map.erase(tail->prev->key);
                Node* temp = tail->prev;
                removeNode(tail->prev);
                delete temp;
            }
       
        }
        else{
            Node* node = address_map[key];
            node->value = value;
            removeNode(node);
            addNode(node);

        }

    }

    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNode(Node* node){
        Node* tmp = head->next;
        node->next = tmp;
        node->prev = head;

        tmp->prev = node;
        head->next = node;
    }
};
