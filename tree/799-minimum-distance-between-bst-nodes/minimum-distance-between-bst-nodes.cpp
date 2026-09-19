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
    int ans = INT_MAX;
    TreeNode* prev = NULL;

    void fun(TreeNode* root) {
        if(root == NULL) return;
        fun(root -> left);
        if(prev != NULL) {
            ans = min(ans, root -> val - prev -> val);
        }
        prev = root;
        fun(root -> right);
    }
    int minDiffInBST(TreeNode* root) {
        fun(root);
        return ans;
    }
};