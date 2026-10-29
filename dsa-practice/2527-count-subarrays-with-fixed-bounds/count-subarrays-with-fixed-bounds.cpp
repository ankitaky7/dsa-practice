class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int mini = -1;
        int maxi = -1;
        int badi = -1;
        for(int i = 0;i < nums.size();i++){
            if(minK > nums[i] || maxK < nums[i]){
                badi = i;
            }
            if(nums[i] == minK){
                mini = i;
            }
            if(nums[i] == maxK){
                maxi = i;
            }
            long long temp = min(mini, maxi) - badi;
            
            if(temp > 0){
                ans += temp;
            }
        }
        return ans;
    }
};