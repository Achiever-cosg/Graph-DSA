// https://leetcode.com/problems/print-binary-tree/description/

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
private:
    int findHeight(TreeNode* p)
    {
        if(p == NULL)
            return 0;
        int left = findHeight(p->left);
        int right = findHeight(p->right);
        return max(left, right)+1;
    }

    int findWidth(TreeNode* p)
    {
        if(p == NULL)
            return 0;
        int left = findWidth(p->left);
        int right = findWidth(p->right);
        return max(left, right)*2 + 1;
    }

    void helper(vector<vector<string>>& ans, TreeNode* p, int level, int l, int r)
    {
        if(p == NULL)
            return;
        
        int mid = l+(r-l)/2;
        ans[level][mid] = to_string(p->val);
        helper(ans, p->left, level+1, l, mid-1);
        helper(ans, p->right,level+1, mid+1, r);
    }

public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = findHeight(root), w = findWidth(root);
        vector<vector<string>> ans(h, vector<string>(w, ""));
        helper(ans, root, 0, 0, w-1);
        return ans;
    }
};