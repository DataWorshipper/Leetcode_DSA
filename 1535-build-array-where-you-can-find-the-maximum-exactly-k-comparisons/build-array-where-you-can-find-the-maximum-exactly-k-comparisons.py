class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        
        MOD = 10**9 + 7
        dp = {}

        def f(index, curr_max, search_cost):

            if index == n:
                if search_cost == k:
                    return 1
                return 0

            if (index, curr_max, search_cost) in dp:
                return dp[(index, curr_max, search_cost)]

            ans = 0

            for num in range(1, m + 1):

              
                if num > curr_max:
                    ans += f(index + 1, num, search_cost + 1)

                
                else:
                    ans += f(index + 1, curr_max, search_cost)

            dp[(index, curr_max, search_cost)] = ans % MOD
            return dp[(index, curr_max, search_cost)]

        return f(0, 0, 0)