//https://leetcode.com/problems/validate-binary-search-tree/

 bool isValidUtil(TreeNode *root, long long left, long long right)
    {
        if(root==NULL)
            return true;
        
        if(root->val >= left or root->val <= right ){
            return false;
        }
        
        if(!isValidUtil(root->left, root->val, right)){
            return false;
        }
        if(!isValidUtil(root->right, left, root->val)){
            return false;
        }
        
        return true;
    }
    
    
    bool isValidBST(TreeNode* root) {
        return isValidUtil(root,LLONG_MAX, LLONG_MIN);    
    }


////////////////////////////////////////////////////////////////

