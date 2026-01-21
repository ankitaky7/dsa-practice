class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long m1 = LLONG_MIN; // third max
        long long m2 = LLONG_MIN; // second max
        long long m3 = LLONG_MIN; // third max
        for(int i=0;i<nums.size();i++){
            if(nums[i] == m1 || nums[i] == m2 || nums[i] == m3) continue;
            if(nums[i] > m3){
                m1 = m2;
                m2 = m3;
                m3 = nums[i];
            }else if(nums[i] > m2){
                m1 = m2;
                m2 = nums[i];
            }else if(nums[i] > m1){
                m1 = nums[i];
            }
        }
        if(m1 == LLONG_MIN) return m3;
        return m1;
    }
};