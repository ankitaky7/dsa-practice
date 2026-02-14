class Solution {
public:
    bool wordPattern(string pattern, string s) {

        // Step 1: manually split string using for loop
        vector<string> words;
        string temp = "";

        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                words.push_back(temp);
                temp = "";
            } 
            else{
                temp += s[i];
            }
        }
        words.push_back(temp); // last word

        // Step 2: length check
        if(pattern.size() != words.size())
            return false;

        // Step 3: maps
        map<char,string> mp1;
        map<string,char> mp2;

        // Step 4: check mapping
        for(int i = 0; i < pattern.size(); i++){

            char ch = pattern[i];
            string word = words[i];

            // char -> word mismatch
            if(mp1.count(ch) && mp1[ch] != word)
                return false;

            // word -> char mismatch
            if(mp2.count(word) && mp2[word] != ch)
                return false;

            // store mapping
            mp1[ch] = word;
            mp2[word] = ch;
        }

        return true;
    }
};
