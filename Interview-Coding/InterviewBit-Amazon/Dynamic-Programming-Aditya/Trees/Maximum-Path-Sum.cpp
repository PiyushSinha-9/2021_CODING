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
    
    int helper(TreeNode* root, int &value){
        if(!root){
            return 0;
        }
        
        int l = helper(root->left, value);
        int r = helper(root->right, value);
        
        
        int temp= max(max(l,r)+root->val , root->val);
        int ans = max(temp,l+r+root->val);
        value = max(value,  ans);
        
        
        return temp;
        
    }
    
    
    int maxPathSum(TreeNode* root) {
        
        int value = INT_MIN;
        helper(root, value);
        return value;
        
    }
};