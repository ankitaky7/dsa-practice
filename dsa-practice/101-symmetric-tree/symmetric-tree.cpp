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
    bool symm(TreeNode* lh, TreeNode* rh){
        if(lh == NULL && rh == NULL) return true;
        if(lh == NULL || rh == NULL) return false;

        if(lh->val != rh->val) return false;

        return symm(lh->left, rh->right) && symm(lh->right, rh->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return NULL;
        return symm(root->left, root->right);
    }
};