class Node{
    public:

    int val;
    Node* prev;
    Node* next;
    int key;
    Node(int val){
        this->val=val;
        prev=NULL;
        next=NULL;
        key=0;
    }
    Node(int val,Node* l,Node* r){
        this->val=val;
        this->prev=l;
        this->next=r;
    }
};
class LRUCache {
    private:
    int cap;
    Node* head;
    Node* tail;

    unordered_map<int ,Node*>umap;

    void remove(Node* n){
        
        n->prev->next=n->next;
        n->next->prev=n->prev;
        
    }
    void insert(Node* n){
        n->next=head->next;
        n->next->prev=n;
        head->next=n;
        n->prev=head;
    }
    
public:
    
    LRUCache(int capacity) {
        head=new Node(-1);
        tail=new Node(-1);
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(umap.find(key)!=umap.end()){
            Node* t=umap[key];
            remove(t);
            insert(t);
        return umap[key]->val;
        }
        else
        return -1;
    }
    
    void put(int key, int value) {
        Node* n=new Node(value);
        n->key=key;
        if(umap.find(key)!=umap.end()){
            
            Node* t=umap[key];
            remove(t);
            insert(n);
            umap[key]=n;
        }
        else if(umap.size()<cap){
            insert(n);
            umap[key]=n;
        }else{
            umap.erase(tail->prev->key);
            remove(tail->prev);
            insert(n);
           
            umap[key]=n;
        }
        
    }
};
