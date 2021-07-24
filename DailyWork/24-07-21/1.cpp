// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> maxh;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                maxh.push(matrix[i][j]);
                if(maxh.size() > k){
                    maxh.pop();
                }
            }
        }
        
        return maxh.top();
    }
};