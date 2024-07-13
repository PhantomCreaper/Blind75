// 230. Kth Smallest Element In BST
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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = -1;
        inorderTraversal(root, k, count, result);
        return result;
    }

private:
    void inorderTraversal(TreeNode* node, int k, int &count, int &result) {
        if (node == nullptr) {
            return;
        }
        
        inorderTraversal(node->left, k, count, result);
        
        // Increment count and check if current node is the kth smallest
        count++;
        if (count == k) {
            result = node->val;
            return;
        }
        
        inorderTraversal(node->right, k, count, result);
    }
};
