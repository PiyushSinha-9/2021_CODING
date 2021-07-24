//https://leetcode.com/problems/arranging-coins/submissions/

class Solution {
public:
    int arrangeCoins(int n) {
        int ans=0;
        long x=n;
        for(long i=1;i<=n;i++){
            if(i*(i+1)==(2*x)){
                return i;
            }
            if(i*(i+1)>(2*x)){
                ans=i-1;
                break;
            }
        }
        return ans;
    }
};