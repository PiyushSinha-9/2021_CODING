//https://leetcode.com/problems/search-a-2d-matrix/submissions/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low =  0;
        int n = matrix.size();
        int m = matrix[0].size();
        int high = m * n-1;
        while(low<=high){
            int mid = floor((low+high)/2);
            int val = matrix[floor(mid/m)][floor(mid%m)];
            if(val == target){
                return true;
            }else if(val<target){
                low = mid+1;
            }else{
                high= mid-1;
            }
        }
        return false;
    }
};