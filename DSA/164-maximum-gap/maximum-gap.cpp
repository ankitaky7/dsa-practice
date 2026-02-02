class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        int gap;
        if(nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        for(int i=1;i<n;i++){
            gap = nums[i] - nums[i-1];
            maxi = max(gap, maxi);
        }
        return maxi;
    }
};