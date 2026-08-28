class Solution:
    def transformStr(self, s: str, strs: List[str]) -> List[bool]:
        def query(s1, s2):
            n = len(s1)

            pref = [0] * n
            suff = [0] * n

            pref[0] = int(s1[0] == '1' and s2[0] == '?')
            suff[0] = int(s1[0] == '0' and s2[0] == '?')

            for i in range(1, n):
                pref[i] = pref[i - 1] + int(s1[i] == '1' and s2[i] == '?')
                suff[i] = suff[i - 1] + int(s1[i] == '0' and s2[i] == '?')

            a = 0
            b = 0

            for i in range(n):
                if s1[i] == '0' and s2[i] == '1':
                    b += 1
                elif s1[i] == '1' and s2[i] == '0':
                    a += 1

                if b > a + pref[i]:
                    return False

            a = 0
            b = 0

            for i in range(n - 1, -1, -1):
                if s1[i] == '1' and s2[i] == '0':
                    b += 1
                elif s1[i] == '0' and s2[i] == '1':
                    a += 1

                if b > a + suff[n - 1] - suff[i]:
                    return False

            return True

        return [query(s, x) for x in strs]