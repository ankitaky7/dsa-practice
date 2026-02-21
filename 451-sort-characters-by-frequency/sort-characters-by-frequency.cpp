class Solution {
public:

    static bool cmp(pair<char, int> &a, pair<char, int> &b){
        return a.second > b.second; //descending by frequency
    }
    string frequencySort(string s) {
        string ans="";
        map<char, int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }

        vector<pair<char, int>> vec(mpp.begin(), mpp.end());
        sort(vec.begin(), vec.end(), cmp);

        for(auto &p: vec){
            ans+= string(p.second, p.first);
        }
        return ans;
    }
};