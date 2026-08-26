/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* next=NULL;
        ListNode* cur=head;
        ListNode* prev=NULL;
        while(cur ){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;  
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* t1=head;
        ListNode* prev=NULL;
        while(t1){
            int i=1;
            ListNode* temp=t1;
            while(temp && i!=k){
                temp=temp->next;
                i++;
            }
            if(!temp){
                if(prev)
                prev->next=t1;
            break;
            }

            ListNode* next=temp->next;
            temp->next=NULL;
            ListNode* rev=reverseList(t1);
            if(!prev){
                head=rev;
            }else{
                prev->next=rev;
            }
            prev=t1;
            t1=next;
        }
        return head;
    }
};
