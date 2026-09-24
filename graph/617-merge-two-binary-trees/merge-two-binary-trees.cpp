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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root1, root2});

        while(!q.empty()) {
            TreeNode* t1 = q.front().first;
            TreeNode* t2 = q.front().second;
            q.pop();
            t1 -> val += t2 -> val;
            
            // Left check
            if(t1 -> left == NULL) t1 -> left = t2 -> left;
            else if(t2 -> left != NULL) q.push({t1 -> left, t2 -> left});

            // Right check
            if(t1 -> right == NULL) t1 -> right = t2 -> right;
            else if(t2 -> right != NULL) q.push({t1 -> right, t2 -> right});
        }
        return root1;
    }
};