//https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
     stack <int> st;
        int x;
        for(int i=0;i<s.length();i++){
            if(s[i]=='{' || s[i]=='[' || s[i]=='(') st.push(s[i]);
            
            else if((s[i]=='}' || s[i]==']' || s[i]==')') && st.empty()) return false;
            
            else{
                x = st.top();
                if(s[i] == '}'){
                if(x == '[' || x == '(') return false;
                }
                else if(s[i] == ']'){
                if(x == '{' || x == '(') return false;
                }
                else if(s[i] == ')'){
                if(x == '[' || x == '{') return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};