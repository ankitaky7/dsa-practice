class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        if(target > letters[n-1]) return letters[0];
        if(target == letters[n-1]) return letters[0];
        for(int i=0;i<letters.size();i++){
            if(target < letters[i]) return letters[i];
        }
        return 0;
    }
};