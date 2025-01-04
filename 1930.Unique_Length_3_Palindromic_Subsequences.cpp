class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        //parse 1: first and last occurance of char
        unordered_map<char,pair<int,int>> first_last;
        for(int i=0;i<n;i++){
            if(!first_last.count(s[i])){
                first_last[s[i]].first=first_last[s[i]].second=i;
            }else{
                first_last[s[i]].second=i;
            }
        }
        //parse 2: unique char in i+1 nad j-1
        int cnt=0;
        for(auto[c,se]:first_last){
            if(se.first==se.second) continue;
            cnt+=unordered_set<char>(s.begin()+se.first+1,s.begin()+se.second).size();
        }
        return cnt;
    }
};