
map<string, int> dp;
int helper(string A, string B)
{

    string key = A+' '+B;
    if(dp.find(key) != dp.end()){
        return dp[key];
    }
    

    if(A.compare(B)==0){
        return dp[key] = 1;
    }   

    if(A.size()==0){
        return dp[key] = 0;
    }

    int n=A.size();

    for(int k=1 ; k<n;k++){
 
        if(helper(A.substr(0,k),B.substr(n- k, k)) and 
            helper(A.substr(k), B.substr(0, n-k ))){
                return dp[key] = 1;
            }

        if(helper(A.substr(0,k),B.substr(0,k )) and 
            helper(A.substr(k), B.substr(k))){
                return dp[key] = 1;
            }
    }

    return dp[key] = 0;
}   




int Solution::isScramble(const string A, const string B) {
    
    dp.clear();
    if(A.size() != B.size())
        return 0;

    if(A.compare(B)==0){
        return 1;
    }   

    return helper(A, B);
}
