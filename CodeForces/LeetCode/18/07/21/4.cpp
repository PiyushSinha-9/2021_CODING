// https://leetcode.com/problems/string-to-integer-atoi/submissions/

class Solution {
public:
    int myAtoi(string s) {
        string num;
        int ind = 0, n = s.length(), sgn = 1;
        // skip white spaces
        while (ind < n && s[ind] == ' ') ind++;
        // extract sign
        if (s[ind] == '-') sgn = -1;
        if (s[ind] == '-' || s[ind] == '+') ind++;
        // if digit can't be read
        if (!isdigit(s[ind])) return 0;
        // skip trailing zeros
        while (ind < n && s[ind] == '0') ind++;
        // extract digits
        while (ind < n && isdigit(s[ind])) 
            num.push_back(s[ind++]);
        // build the number
        n = ind = num.length();
        long res = 0;
        if (n <= 11) {  // length of signed INT_MAX/ INT_MAX string is 11
            while (--ind >= 0) {
                res += (long) (num[ind] - '0') * (long) (pow(10, n - 1 - ind) + 0.5);
                if (res >= INT_MAX) break;
            }
        }
        else res = (long) INT_MAX + 1;
        // clamp the number and adjust the sign
        if (res >= INT_MAX)
            res = sgn == 1 ? INT_MAX : res == INT_MAX ? INT_MIN + 1 : INT_MIN;
        else res *= sgn;
        return (int) res;   
    }
};