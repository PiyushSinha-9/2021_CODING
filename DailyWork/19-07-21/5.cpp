//https://leetcode.com/problems/container-with-most-water/discuss/1345531/C%2B%2B-or-Container-With-Most-Water-Simple-Solution-Using-Two-Pointers-O(n)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int temp = 0;
        int prod = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while(left < right) {
            if (height[left] <= height[right]) {
                temp = height[left] * (right - left);
                left++;
            }
            else {
                temp = height[right] * (right - left);
                right--;
            }
            
            prod = max(temp, prod);
        }
        return prod;
    } 
};