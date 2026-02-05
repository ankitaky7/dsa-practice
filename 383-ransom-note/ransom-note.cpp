class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;
        for(auto it: magazine){
            freq[it]++;
        }
        for(auto it: ransomNote){
            if(freq[it] > 0){
                freq[it]--;
            }else{
                return false;
            }
        }
        return true;
    }
};