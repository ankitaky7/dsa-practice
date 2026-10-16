class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int j = 0;
            cnt = 0;
            while (j < nums.size()) {
                if (nums[i] > nums[j] && nums[i] != nums[j]) {
                    cnt++;
                }
                j++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};