class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int max = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>max) max = nums[i];
            
            int small = INT_MAX;
            for(int j=i;j<n;j++)
            {   
                if(nums[j]<small) small = nums[j];
            }
            if(max-small <= k) return i;
            
        }
        return -1;
    }
};