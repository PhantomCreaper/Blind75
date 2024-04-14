// 98. Validate Binary Search Tree
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
    bool isValidBSTUtil(TreeNode* node, long long minVal, long long maxVal) {
        if (node == nullptr) return true;
        if (node->val <= minVal || node->val >= maxVal) return false;
        
        return isValidBSTUtil(node->left, minVal, node->val) && 
            isValidBSTUtil(node->right, node->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBSTUtil(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
    }
};
