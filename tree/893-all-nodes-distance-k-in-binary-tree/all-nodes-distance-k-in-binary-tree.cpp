/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Given node se neeche exactly k distance par jo nodes hain, unhe find karna and ans m push krna
    void find(TreeNode* root, int k, vector<int>& ans) {
        if(root == NULL) return;

        if(k==0) {
            ans.push_back(root -> val);
            return;
        }
        find(root -> left, k-1, ans);
        find(root -> right, k-1, ans);
    }

    // Target ko find karna aur target se ancestors tak jaana.
    void search(TreeNode* root, TreeNode* target, int k, int& dist, bool& found, vector<int>& ans) {
        if(root == NULL) return;

        if(root == target) {
            found = true;
            dist = 0;
            find(root, k, ans);
            return;
        }

        search(root -> left, target, k, dist, found, ans);

        if(found) {
            dist++;
            if(dist == k) ans.push_back(root -> val);
            find(root -> right, k-dist-1,ans);
            return;
        }

        search(root -> right, target, k, dist, found, ans);
        if(found) {
            dist++;
            if(dist == k) ans.push_back(root -> val);
            find(root -> left, k-dist-1, ans);
            return;
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        bool found = false;
        vector<int> ans;
        int dist = 0;

        search(root,target,k,dist,found,ans);

        return ans;
    }
};