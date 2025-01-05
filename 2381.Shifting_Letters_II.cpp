class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>v(s.length(),0);
        for(auto it:shifts){
            int l = it[0];
            int r = it[1];
            int dir = it[2];
            int sign =-1;

            if(dir==0) sign =-1;
            else sign =1;

            v[l]+= 1*sign;

            if(r+1<s.length()) v[r+1]-=1*sign;
        }  
        string ans ="";
        int prefix_sum=0;
        for(int i=0;i<s.size();i++) {
            prefix_sum+=v[i];
            prefix_sum%=26;
            ans += (s[i]-'a'+prefix_sum+26)%26 +'a';
        }
        return ans;
    }
};