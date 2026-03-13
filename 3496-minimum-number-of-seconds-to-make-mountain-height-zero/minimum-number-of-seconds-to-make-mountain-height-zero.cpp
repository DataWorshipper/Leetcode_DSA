class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0;
        long long high = 1LL * (*max_element(workerTimes.begin(), workerTimes.end()))
                         * mountainHeight * (mountainHeight + 1) / 2;

        long long ans = high;

        while (low <= high) {
            long long mid = (low + high) / 2;

            long long removed = 0;

            for (long long t : workerTimes) {
                long long k = (sqrt(1 + 8.0 * mid / t) - 1) / 2;

               
                while (t * k * (k + 1) / 2 > mid) k--;
                while (t * (k + 1) * (k + 2) / 2 <= mid) k++;

                removed += k;

                if (removed >= mountainHeight) break;
            }

            if (removed >= mountainHeight) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};