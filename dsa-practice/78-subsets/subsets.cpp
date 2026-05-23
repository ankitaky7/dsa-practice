class Solution {
public:
    void f(vector<int>&temp, vector<int>&nums, vector<vector<int>>&ans, int index){
        // base case
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }

        //take
        temp.push_back(nums[index]);

        //recursive call
        f(temp, nums, ans, index + 1);

        //backtrack
        temp.pop_back();

        //not take
        f(temp, nums, ans, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        f(temp, nums, ans, 0);
        return ans;
    }
};