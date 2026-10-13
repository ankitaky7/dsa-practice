class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        int n = nums.size();

        // finding pivot
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // agar pivot nhi mila (if all the elements of the array in descending order)
        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // finding element just greater than nums[pivot] from right
        for (int i = n - 1; i > pivot; i--) {
            if(nums[pivot] < nums[i]){
                swap(nums[pivot], nums[i]);
                break;
            }
        }

        // reverse the right half
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};