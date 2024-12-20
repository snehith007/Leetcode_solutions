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
    TreeNode* reverseOddLevels(TreeNode* root) {
        ans(root->left,root->right,0);
        return root;
        
    }
private:
    void ans(TreeNode*leftchild,TreeNode*rightchild,int level){
        if(leftchild == nullptr||rightchild==nullptr){
            return;
        }
        if(level%2==0){
            int temp = leftchild->val;
            leftchild->val = rightchild->val;
            rightchild->val = temp;
        }
        ans(leftchild->left,rightchild->right,level+1);
        ans(leftchild->right,rightchild->left,level+1);
    
  }

};