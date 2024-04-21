// 543. Diameter of a Binary Tree
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
private:
    int diameter = 0;
    int height(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int LH = height(root->left);
        int RH = height(root->right);

        diameter = max(diameter, LH + RH);
        return 1+max(LH, RH);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};
