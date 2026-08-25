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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head ||!head->next) return NULL;
        int len=0;
        for(ListNode *t=head;t;t=t->next){
            len++;
        }
        //cout<<"len="<<len<<endl;
        int k=len-n;
        if(k==0){
            return head->next;
        }
        ListNode* t=head;
        for(int i=1;i<k;i++){
            t=t->next;

        }
        //cout<<"t="<<t->val<<endl;
        t->next=t->next->next;
        return head;
    }
};
