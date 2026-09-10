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
    bool isSame(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL || root2==NULL) return false;
        if(root1 -> val != root2 -> val) return false;

        bool x = isSame(root1 -> left, root2 -> right);
        bool y = isSame(root1 -> right, root2 -> left);

        if(x==true && y==true) return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return isSame(root -> left, root -> right);
    }
};

// T.C = O(n);
// S.C = O(n);