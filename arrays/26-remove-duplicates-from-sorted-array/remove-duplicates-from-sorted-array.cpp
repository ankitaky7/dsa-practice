class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int i = 0, j = 0;
        while(i < nums.size() && j < nums.size()){
            if(nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
                j++;
                k++;
            }else{
                j++;
            }
        }
        return k;
    }
};