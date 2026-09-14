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
    stack<TreeNode*> asc;
    TreeNode* getSmall() {
        if(asc.empty()) return NULL;
        TreeNode* small = asc.top();
        asc.pop();
        TreeNode* rightChild = small -> right;
        while(rightChild) {
            asc.push(rightChild);
            rightChild = rightChild -> left;
        }
        return small;
    }

    int kthSmallest(TreeNode* root, int k) {
        TreeNode* t = root;
        while(t) {
            asc.push(t);
            t = t -> left;
        }
        while(k--) {
            t = getSmall();
        } 
        return t -> val;
    }
};