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
        Node* t1=head;

        while(t1){
            Node* nn=new Node(t1->val);
            nn->next=t1->next;
            t1->next=nn;
            t1=t1->next->next;
        }

        t1=head;
        while(t1){
            if(t1->random)
            t1->next->random=t1->random->next;
            t1=t1->next->next;
        }
        t1=head;
        Node* temp=new Node(-1);
        Node* res=temp;
        while(t1){
            Node* copy=t1->next;
            res->next=copy;
            res=res->next;
            t1->next=res->next;
            t1=t1->next;
        }
        return temp->next;
    }
};
