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
    int Maxdepth = 0;

    int fun(TreeNode* root, int depth) {
        if(root==NULL) return depth;
        int left = fun(root -> left, depth + 1);
        int right = fun(root -> right, depth + 1);

        if(left == right) {
            if(left >= Maxdepth) {
                Maxdepth = left;
                ans = root;
            }
        }
        return max(left, right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        fun(root, 0);
        return ans;
    }
};