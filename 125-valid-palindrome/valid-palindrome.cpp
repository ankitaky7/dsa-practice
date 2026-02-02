class Solution {
public:
    bool isPalindrome(string s) {
       int n = s.size();
       int l = 0, r = n - 1;
       // ascii of a is 97 & ascii of A is 65
       if(n == 1) return true;
       while(l < r){
       if(s[l] >= 'A' && s[l] <= 'Z') s[l] = s[l] + 'a' - 'A';
       if(s[r] >= 'A' && s[r] <= 'Z') s[r] = s[r] + 'a' - 'A';

       if(!((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= '0' && s[l] <= '9'))){
        l++;
        continue;
       }
       if(!((s[r] >= 'a' && s[r] <= 'z') || (s[r] >= '0' && s[r] <= '9'))){
        r--;
        continue;
       }
       
       if(s[l] != s[r]) return false;
        l++;
        r--;
       }
       return true;
    }
};