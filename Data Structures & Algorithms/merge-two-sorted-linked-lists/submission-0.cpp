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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* i=list1;
        ListNode* j=list2;
        ListNode* head=NULL;
        ListNode* t=new ListNode(-1);
        head=t;
        while(i && j){
            if(i->val<j->val){
                t->next=i;
                i=i->next;
                t=t->next;
            }else{
                t->next=j;
                j=j->next;
                t=t->next;
            }
        }
        if(i)
        t->next=i;
        if(j)
        t->next=j;
        return head->next;
    }
};
