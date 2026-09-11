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
    TreeNode* ans = NULL;
    void fun(TreeNode* root, int k) {
        if(root==NULL) return;

        if(root -> val == k) ans = root;

        if(root -> val > k) {
            fun(root -> left, k);
        }
        else {
            fun(root -> right, k);
        }
        return;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        fun(root,val);
        return ans;
    }
};