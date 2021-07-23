//https://leetcode.com/problems/reverse-integer/


class Solution:
    def reverse(self, x: int) -> int:
        x_str = str(x)
        negative = '-' in x_str
        mirror = int(x_str.replace('-', '')[::-1])
		
        if mirror < 2**31-1:
            if negative:
                return mirror*-1
            else:
                return mirror
        else:
            return 0