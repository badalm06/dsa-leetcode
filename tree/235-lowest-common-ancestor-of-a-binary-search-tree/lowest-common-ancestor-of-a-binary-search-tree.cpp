/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// It's more optimized way T.C - O(h), S.C - o(h)

class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root == NULL) return 0;
            if(root -> val > p -> val && root -> val> q -> val) {
                return lowestCommonAncestor(root -> left, p, q);
            }
            if(root -> val < p -> val && root -> val < q -> val) {
                return lowestCommonAncestor(root -> right, p, q);
            }
        return root;
    }
};