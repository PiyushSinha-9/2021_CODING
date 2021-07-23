//https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }
        int rem, old = x;
        long rev = 0;
        while (x != 0) {
            rem = x % 10;
            rev = rev * 10 + rem;
            x/=10;
        }
        if (old == rev) {
            return true;
        } else {
            return false;
        }
    }
};