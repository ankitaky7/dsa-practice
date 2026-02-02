class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(m < n) intersection(nums2, nums1);
        unordered_set<int>set1(nums1.begin(),nums1.end());
        unordered_set<int>common;
        for(auto el: nums2){
            if(set1.contains(el)) common.insert(el);
        }
        vector<int>ans(common.begin(),common.end());
        return ans;
    }
};