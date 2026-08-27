class Solution {
public:
    TreeNode* solve(vector<int>& pre, int ps, int pe,
                    vector<int>& in, int ins, int ine,
                    unordered_map<int, int>& umap) {

        if (ps > pe || ins > ine)
            return NULL;

        TreeNode* root = new TreeNode(pre[ps]);

        int rootIndex = umap[root->val];

        // Number of nodes in left subtree
        int leftSize = rootIndex - ins;

        root->left = solve(
            pre,
            ps + 1,
            ps + leftSize,
            in,
            ins,
            rootIndex - 1,
            umap
        );

        root->right = solve(
            pre,
            ps + leftSize + 1,
            pe,
            in,
            rootIndex + 1,
            ine,
            umap
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int, int> umap;

        for (int i = 0; i < inorder.size(); i++)
            umap[inorder[i]] = i;

        return solve(
            preorder,
            0,
            preorder.size() - 1,
            inorder,
            0,
            inorder.size() - 1,
            umap
        );
    }
};