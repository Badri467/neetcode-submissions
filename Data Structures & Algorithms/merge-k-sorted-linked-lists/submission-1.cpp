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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        ListNode* h=new ListNode(-1);
        ListNode* temp=h;
        for(auto it: lists){
            if(it)
        pq.push({it->val,it});
        }

        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            if(x.second->next)
            pq.push({x.second->next->val,x.second->next});
            temp->next=x.second;
            temp=temp->next;
        }
        return h->next;
    }
};
