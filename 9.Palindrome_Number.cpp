class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        string s = to_string(x);
        int l=0;
        int r =s.length() -1;
        while(l<r){
            if(s[l] != s[r]){
                return false;
            }
                l++;
                r--;
            
        }
        return true;
        
    }
};