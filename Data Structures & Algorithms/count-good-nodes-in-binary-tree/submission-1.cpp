/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int solve(TreeNode* root,int ma){
        if(!root) return 0;
        int count=0;
        if(root->val>=ma)
         count++;
         ma=max(root->val,ma);
        count+=solve(root->left,ma);
        count+=solve(root->right,ma);
       return count;
    }
    int goodNodes(TreeNode* root) {
        return solve(root,INT_MIN);
    }
};
