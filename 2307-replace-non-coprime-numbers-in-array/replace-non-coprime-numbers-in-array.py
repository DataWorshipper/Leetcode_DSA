class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        def gcd(a, b):
            if b == 0:
                return a
            return gcd(b, a % b)

        st = []
        n = len(nums)

        for i in range(n):
            if len(st) == 0:
                st.append(nums[i])
                continue

            while len(st) > 0:
                top = st[-1]

                if gcd(top, nums[i]) != 1:
                    st.pop()
                    nums[i] = (top * nums[i]) // gcd(top, nums[i])
                else:
                    break

            st.append(nums[i])

        return st