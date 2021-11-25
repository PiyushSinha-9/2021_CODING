vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string curr=strs[i];
            sort(curr.begin(),curr.end());
            mp[curr].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto e:mp){
            ans.push_back(e.second);
        }
        return ans;
    }