class Solution:
    def largestInteger(self, n: int, s: int) -> int:
        if s <= 9 and n==1:
            return s
        if 9 * n < s:
            return -1

        q = s // 9
        rem = s % 9

        s1 = ""
        for i in range(q):
            s1 += '9'

        if rem:
            s1 += str(rem)

        remaining = n - q - (1 if rem else 0)
        for i in range(remaining):
            s1 += '0'

        return int(s1)