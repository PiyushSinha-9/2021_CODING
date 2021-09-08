// https://leetcode.com/problems/bitwise-and-of-numbers-range/submissions/


class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int val=0;
        int counter=0;
        
        while(left!=right){
            left>>=1;
            right>>=1;
            counter+=1;
        }
        
        val=left;
        val<<=counter;
        
        return val;
    }
};