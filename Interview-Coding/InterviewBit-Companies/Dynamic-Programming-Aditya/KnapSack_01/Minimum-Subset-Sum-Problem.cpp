class Solution{
    
   int totalSum;
    void subset(int arr[], int n, bool **dp){
        for(int i=0;i<n+1;i++){
            for(int j=0;j<totalSum+1;j++){
                if(i==0 and j==0){
                    dp[i][j] = true;
                    continue;
                }
                
                if(i==0){
                    dp[i][j]=false;
                    continue;
                }
                if(j==0){
                    dp[i][j]=true;
                    continue;
                }
                
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    if(n==1){
	        return arr[0];
	    }
	    
	    totalSum = 0;
	    for(int i=0;i<n;i++)
	        totalSum += arr[i];
	    
	    int total = totalSum;
	    totalSum/=2;
	    
	    bool **dp = new bool*[n+1];
	    for(int i=0;i<n+1;i++){
	        dp[i]= new bool[totalSum+1];
	        for(int j=0;j<totalSum+1;j++){
	            dp[i][j]=false;
	        }
	    }
	 //   memset(dp,false,sizeof(dp));
	    
	    subset(arr, n, dp);
	    int res = INT_MAX;
	    
	    for(int i=1;i<=totalSum ;i++){
	        if(dp[n][i]){
	            res = min(res, total - 2*i);
	        }
	    }
	    
	    
	    return res;
	    
	} 
};