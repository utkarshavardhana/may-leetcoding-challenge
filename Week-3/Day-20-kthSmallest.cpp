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
    int count = 1;
    void iterate(TreeNode* root, int &t, int &res) {
        if(!root)   return;
        iterate(root->left, t, res);
        if(t == count) {
            res = root->val;
            count++;
            return;
        } else {
            count++;
        }  
        iterate(root->right, t, res);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)   return -1;
        int t = k, res = 0;
        iterate(root, t, res);
        return res;
    }
};
