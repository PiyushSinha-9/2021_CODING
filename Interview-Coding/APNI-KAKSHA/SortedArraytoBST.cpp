// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

TreeNode* helper(vector<int> &nums,int low,int high){
        if(low>high){
            return NULL;
        }
        int mid=(low+high)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=helper(nums,low,mid-1);
        node->right=helper(nums,mid+1,high);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }