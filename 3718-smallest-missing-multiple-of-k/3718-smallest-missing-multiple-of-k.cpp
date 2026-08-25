class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int small = k;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(small==nums[i]) small += k;
        }
        return small;
    }
};