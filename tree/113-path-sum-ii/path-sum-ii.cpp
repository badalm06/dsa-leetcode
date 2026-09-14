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
    vector<vector<int>> res;
    void fun(TreeNode* root, int sum, int tSum, vector<int>& temp) {
        if(root == NULL) return;
        sum = sum + root -> val;
        temp.push_back(root -> val);
        if(root -> left == NULL && root -> right == NULL) {
            if(sum == tSum) {
                res.push_back(temp);
            }
            temp.pop_back();
            return;
        }
        fun(root -> left, sum, tSum, temp);
        fun(root -> right, sum, tSum, temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        fun(root, 0, targetSum, temp);
        return res;
    }
};