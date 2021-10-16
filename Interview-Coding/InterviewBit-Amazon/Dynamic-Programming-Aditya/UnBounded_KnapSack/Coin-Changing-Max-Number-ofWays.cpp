class Solution {
  public:
    long long int count(int S[], int m, int n) {

        // code here.
        // Similar to SubSet Sum Problem
        
        
        long long  dp[m+1][n+1];
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 and j==0){
                    dp[i][j] = 1;
                    continue;
                }
                
                if(i==0){
                    dp[i][j] =  0;
                    continue;
                }
                
                if(j==0){
                    dp[i][j] =  1;
                    continue;
                }
                
                if(S[i-1]<=j){
                    dp[i][j] =  dp[i][j-S[i-1]] + dp[i-1][j];
                }else{
                    dp[i][j] =  dp[i-1][j];
                }
                
            }
        }
        
        
        return dp[m][n];
        
        
        
    }
};