class Solution:
    def minDifficulty(self, arr: List[int], d: int) -> int:

        n = len(arr)

        if n < d:
            return -1

        dp = {}

        def f(job_no, day_num, curr_max):

            if job_no == n:
                if day_num == d:
                    return curr_max
                return float('inf')

            if (job_no, day_num, curr_max) in dp:
                return dp[(job_no, day_num, curr_max)]

            ans = float('inf')

          
            stay = f(
                job_no + 1,
                day_num,
                max(curr_max, arr[job_no])
            )

            ans = min(ans, stay)

           
            if day_num < d:
                next_day = curr_max + f(
                    job_no + 1,
                    day_num + 1,
                    arr[job_no]
                )

                ans = min(ans, next_day)

            dp[(job_no, day_num, curr_max)] = ans

            return ans

        return f(1, 1, arr[0])