//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        if(root==NULL){
            return sol; 
        }
        
        int curLev = 1;
        int nextLev = 0;
        queue<TreeNode*> que;
        que.push(root);
        

        vector<int> tempsol;
        int Level=0;
        
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
        
            tempsol.push_back(temp->val);
            if(temp->left != NULL){
                nextLev +=1;
                que.push(temp->left);
            }
            if(temp->right != NULL){
                nextLev +=1;
                que.push(temp->right);
            }
            
            curLev-=1;
            if(curLev==0){
                curLev = nextLev;
                nextLev = 0;
                
                if(Level%2!=0){
                    reverse(tempsol.begin(), tempsol.end());
                }
                
                sol.push_back(tempsol);
                tempsol.clear();
                Level+=1;
            }
            
            
        }
        
        return sol;
        
        
        
    }
};