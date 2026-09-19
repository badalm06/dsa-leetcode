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
    int leftHeight(TreeNode* root) {
        int dep = 0;
        while(root != NULL) {
            root = root -> left;
            dep++;
        }
        return dep;
    }

    int rightHeight(TreeNode* root) {
        int dep = 0;
        while(root != NULL) {
            root = root -> right;
            dep++;
        }
        return dep;
    }

    int countNodes(TreeNode* root) {

        if(root == NULL) return 0;
        int lh = leftHeight(root -> left);
        int rh = rightHeight(root -> right);

        if(lh == rh) {
            return pow(2, lh+1)-1;
        }
        else {
            return 1 + countNodes(root -> left) + countNodes(root -> right);
        }
    }
};