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
    
    void _bstFromPreorder(TreeNode* node, vector<int> leftie, vector<int> rightie) {
        if(leftie.size()) {
            node->left = new TreeNode(leftie[0]);
            vector<int> leftT, rightT;
            for(int i : leftie) {
                if(i == node->left->val) continue;
                if(i < node->left->val) leftT.push_back(i);
                if(i > node->left->val) rightT.push_back(i);
            }            
            _bstFromPreorder(node->left, leftT, rightT);
        }
        if(rightie.size()) {
            node->right = new  TreeNode(rightie[0]);
            vector<int> leftT, rightT;
            for(int i : rightie) {
                if(i == node->right->val) continue;
                if(i < node->right->val) leftT.push_back(i);
                if(i > node->right->val) rightT.push_back(i);
            }
            _bstFromPreorder(node->right, leftT, rightT);
        }
    }
        
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *node = new TreeNode(0);
        if(preorder.size()==0) return NULL;
        vector<int> left, right;
        node->val = preorder[0];
        for(int i : preorder) {
            if(i == node->val) continue;
            if(i < node->val) left.push_back(i);
            if(i > node->val) right.push_back(i);
        }
        _bstFromPreorder(node, left, right);
        return node;
    }
};
