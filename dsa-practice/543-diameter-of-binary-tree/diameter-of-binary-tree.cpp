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
    int height(TreeNode* root){
        int lh, rh;
        if(root == NULL) return 0;
        lh = height(root->left);
        rh = height(root->right);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int leftHeight, rightHeight;
        leftHeight = height(root->left);
        rightHeight = height(root->right);

        int currentDiameter = leftHeight + rightHeight;

        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiamater = diameterOfBinaryTree(root->right);
        
        return max(currentDiameter, max(leftDiameter, rightDiamater));
    }
};