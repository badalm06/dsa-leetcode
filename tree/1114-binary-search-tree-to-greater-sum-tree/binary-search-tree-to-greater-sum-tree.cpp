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
    void fun(TreeNode* root, int& curSum) {
        if(root == NULL) return;

        fun(root -> right, curSum);
        root -> val += curSum;
        curSum = root -> val;
        fun(root -> left, curSum); 

    }
    TreeNode* bstToGst(TreeNode* root) {
        int curSum = 0;
        fun(root,curSum);
        return root;
    }
};