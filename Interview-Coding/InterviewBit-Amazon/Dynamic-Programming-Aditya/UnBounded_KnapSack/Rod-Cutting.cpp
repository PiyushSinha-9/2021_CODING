
//////////////////////////////////////////////////////////////  in 1D table
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        
        int dp[n];
        memset(dp, -1, sizeof(dp));
        
        dp[0] = price[0];
        
        for(int i=1;i<n;i++){
            int res = price[i] ; 
            for(int j=0;j<i;j++){    
                   res = max(res, dp[i-1-j] + dp[j]);
            }
            dp[i] =res;
        }
        
        
        return dp[n-1];
        
    }
};


//////////////////////////////////////////////////////////////////  in 2D matrix