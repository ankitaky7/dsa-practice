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
    bool isValidTree(TreeNode* root, long lBound, long uBound){
        if(root == NULL) return true;
        if(root->val <= lBound || root->val >= uBound) return false;
        return isValidTree(root->left, lBound, root->val) && isValidTree(root->right, root->val, uBound);
    }
    bool isValidBST(TreeNode* root) {
        return isValidTree(root, LONG_MIN, LONG_MAX);
    }
};