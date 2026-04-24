class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int>mp;
        for(int i=0;i<allowed.size();i++){
            mp[allowed[i]]++;
        }
        int cnt = 0;
        for(int i=0;i<words.size();i++){
            string word = words[i];
            int flag = 1;

            for(int j=0;j<word.size();j++){
                if(mp[word[j]] == 0){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                cnt++;
            }
        }
        return cnt;
    }
};