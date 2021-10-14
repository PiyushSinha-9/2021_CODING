// https://leetcode.com/problems/target-sum/

class Solution {
public:
    
    
    int countSubsetSum(vector<int> nums, int n, int sum){
        int dp[n+1][sum+1];
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0 and j==0){
                    dp[i][j]=1;
                    continue;
                }
                
                if(i==0){
                    dp[i][j] = 0; 
                    continue;
                }
                
                if(j==0){
                    dp[i][j] = 1;
                    continue;
                }
                
                if(nums[i-1]==0){
                     dp[i][j] = dp[i-1][j];
                    continue;
                }
                
                if(nums[i-1] <= j ){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
                
            }
        }
        
        return dp[n][sum];
        
    }
    
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n=nums.size();
        int totalSum = 0;
        int countZero = 0;
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
            if(nums[i]==0){
                countZero+=1;
            }
        }
        
        if(totalSum < abs(target) or (totalSum + target)%2 != 0){
            return 0;
        }
               
        int s1 = (target + totalSum)/2;
        // Find Number of ways to get s1
        return countSubsetSum(nums, n,s1) * pow(2,countZero);
        
    }
};