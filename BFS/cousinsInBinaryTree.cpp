// https://leetcode.com/problems/cousins-in-binary-tree/description/

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
        int x_depth, y_depth;
        int x_parent, y_parent;
private:
    void dfs(TreeNode* root, int x, int y, int depth, int value)
    {
        if(root == NULL)
            return;

        if(root->val == x)
        {
            x_depth = depth;
            x_parent = value;
            return;
        }

        if(root->val == y)
        {
            y_depth = depth;
            y_parent = value;
        }

        dfs(root->left, x, y, depth+1, root->val);
        dfs(root->right, x, y, depth+1, root->val);
    }

public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y)
            return false;
        
        dfs(root, x, y, 0, root->val);
        if(x_depth == y_depth && x_parent != y_parent)
            return true;

        return false;
    }
};