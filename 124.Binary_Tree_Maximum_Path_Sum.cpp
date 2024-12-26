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
    int Sum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        solver(root);
        return Sum;  
    }
private:
    int solver(TreeNode* node){
        if(!node) return 0;

        int LeftMax = max(solver(node->left),0);
        int RightMax = max(solver(node->right),0);
        
        int ans = node->val+LeftMax+RightMax;
        Sum = max(Sum,ans);

        return node->val + max(LeftMax,RightMax);
    }
};