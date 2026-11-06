class Solution:
    def taskSchedulerII(self, tasks: List[int], space: int) -> int:
        mpp = defaultdict(int)
        mpp[tasks[0]] = 1
        n = len(tasks)
        days = 1

        for i in range(1, n):
            if mpp[tasks[i]] == 0:
                days += 1
            else:
                diff = days - mpp[tasks[i]]

                if diff >= space + 1:
                    days += 1
                else:
                    days += space + 1 - diff

            mpp[tasks[i]] = days

        return days