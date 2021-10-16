lass Solution{
    
	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int inf = 1e9+7;
	    vector<int> dp(V+1, inf);
	    
	    dp[0] = 0;
	    
	    for(int i=0;i<M;i++){
	        for(int j=coins[i]; j<V+1;j++){
	            dp[j] = min(dp[j], 1+dp[j-coins[i]]);
	        }
	    }
	    
	    if(dp[V]>=inf){
	        return -1;
	    }
	    
	    return dp[V];
	} 
	  
};