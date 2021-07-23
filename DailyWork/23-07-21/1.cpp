// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string res = "";
        for(int i = 0; i < strs[0].size(); i++){
            for(int j = 1; j < n; j++){
                if(strs[j][i] != strs[0][i]){
                    return res;
                } 
            }
            res += strs[0][i];
        }
        return res;
    }
};