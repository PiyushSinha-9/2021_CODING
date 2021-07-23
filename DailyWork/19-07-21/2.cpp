// https://leetcode.com/problems/longest-palindromic-substring/submissions/


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> memo(n, vector<bool>(n,true)); 
        string res;
        for (int i=n-1; i>=0 ;i--) {
            for (int j=i; j<n;j++) {
                if (i == j) memo[i][j] = true;
                if (i < j && s[i] == s[j]) memo[i][j] = true && memo[i+1][j-1];
                if (s[i] != s[j]) memo[i][j] = false;
                if (memo[i][j] && j-i+1 > res.size()) res = s.substr(i, j-i+1);
            }
        }        
        return res;
    }
};