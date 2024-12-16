class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> Set;
        int r=0,l=0,ans =0;
        

        while(r<s.size()){
            auto it = Set.find(s[r]);
            if(it == Set.end()){
                if(r - l + 1 > ans){
                    ans = r - l + 1;
                }
                Set.insert(s[r]);
                r++;
            }
            else{
                Set.erase(s[l]);
                l++;
            }
        }
        return ans;
        
    }
};