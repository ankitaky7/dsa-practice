class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int ls;
        int rs;
        for(int i=0;i<nums.size();i++){
            sum +=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(i == 0){
                ls = 0;
            }else {
                ls = ls + nums[i-1];
            }
            rs = sum - ls - nums[i];
            if(rs == ls) return i;
        }
        return -1;
    }
};