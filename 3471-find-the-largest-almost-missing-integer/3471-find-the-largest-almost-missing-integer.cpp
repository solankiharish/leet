class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size(), res = -1, edge = -1, mx = -1;
        unordered_map<int,int> mp;
        for (int x : nums) mp[x]++;

        for (auto [x, cnt] : mp) {
            mx = max(mx, x);
            if (cnt == 1) {
                res = max(res, x);
                if (x == nums[0] || x == nums[n-1])  edge = max(edge, x);
            }
        }

        if (k == 1) return res;
        if (k == n) return mx;
        return edge;
    }
};