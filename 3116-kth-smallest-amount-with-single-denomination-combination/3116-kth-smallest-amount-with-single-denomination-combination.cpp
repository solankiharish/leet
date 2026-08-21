class Solution {
    
    void countMultiples(int idx, long long current_lcm, int count_coins, 
                        long long mid, const vector<int>& coins, long long& total) {
        if (idx == coins.size()) {
            if (count_coins > 0) {
                if (count_coins % 2 == 1) {
                    total += mid / current_lcm;
                } else {
                    total -= mid / current_lcm;
                }
            }
            return;
        }

        countMultiples(idx + 1, current_lcm, count_coins, mid, coins, total);

        long long next_lcm = (current_lcm / std::gcd(current_lcm, (long long)coins[idx])) * coins[idx];
        if (next_lcm <= mid) {
            countMultiples(idx + 1, next_lcm, count_coins + 1, mid, coins, total);
        }
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // Binary search boundaries
        long long low = 1;
        long long high = (long long)coins[0] * k; // upper bound assumption
        for (int c : coins) high = min(high, (long long)c * k);

        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long total = 0;

            countMultiples(0, 1, 0, mid, coins, total);

            if (total >= k) {
                ans = mid;
                high = mid - 1; // Try to find a smaller answer
            } else {
                low = mid + 1;  // Need a larger value to reach k
            }
        }

        return ans;
    }
};