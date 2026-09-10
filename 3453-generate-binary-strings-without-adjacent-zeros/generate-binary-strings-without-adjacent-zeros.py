class Solution:
    def validStrings(self, n: int) -> List[str]:
        ans = []

        def rec(idx, prev, s):
            if idx == n:
                ans.append("".join(s))
                return

            if prev == '0':
                s.append('1')
                rec(idx + 1, '1', s)
                s.pop()
            else:
                s.append('0')
                rec(idx + 1, '0', s)
                s.pop()

                s.append('1')
                rec(idx + 1, '1', s)
                s.pop()

        rec(0, '1', [])
        return ans