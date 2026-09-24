class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        int n = nums.size();
        int ans;
        if(n == 1) {
            ans = nums[0];
            return ans;
        }
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                ans = nums[i + 1];
            }
        }
        if(nums[n-1] > nums[0]) ans = nums[0];
        return ans;
    }
};