//https://leetcode.com/problems/sqrtx/submissions/

class Solution {
public:
    int mySqrt(int x) {
        
        long long  low=0;
        long long high=INT_MAX,ans=0;
        
        while(low<=high){
            
        long long mid=low+(high-low)/2;
            if(mid*mid<=x){
                ans=mid; 
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        
    }
        return ans;
    }
};