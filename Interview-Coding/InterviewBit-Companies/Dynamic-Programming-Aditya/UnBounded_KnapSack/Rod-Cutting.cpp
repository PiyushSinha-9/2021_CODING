
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



class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        
        int dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i <= j){
                    dp[i][j] = max(dp[i-1][j], price[i-1] + dp[i][j-i] ); 
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=n;j++){
        //       cout<<dp[i][j]<<" ";
        // }
        //     cout<<endl;
        // }
        
        
        return dp[n][n];
        
    }
};