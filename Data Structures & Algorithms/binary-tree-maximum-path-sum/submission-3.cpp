class Solution {
public:
    int ans = INT_MIN;

    int solve(TreeNode* root) {
        if (!root)
            return 0;

        int left = max(0, solve(root->left));
        int right = max(0, solve(root->right));

        // Best path whose highest/turning node is root
        int currentPath = root->val + left + right;

        // Update global answer
        ans = max(ans, currentPath);

        // Path returned to parent can use only ONE child
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};