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
    int ans = INT_MIN;
    int fun(TreeNode* root) {
        if(root == NULL) return 0;

        int left = fun(root -> left);
        int right = fun(root -> right);

        left = max(0,left);
        right = max(0, right);

        int total = root -> val + left + right;

        ans = max(ans,total);

        return root -> val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        fun(root);
        return ans;
    }
};