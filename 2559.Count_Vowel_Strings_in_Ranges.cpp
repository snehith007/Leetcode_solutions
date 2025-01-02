class Solution {
    bool isVowel(char& c){
        return(c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        int n= words.size();
        vector<int>prefix_sum(n+1,0);

        for(int i=0;i<n;i++){
            char start = words[i][0];
            char end = words[i].back();

            if(isVowel(start) && isVowel(end)) prefix_sum[i+1]=1+prefix_sum[i];
            else prefix_sum[i+1]=prefix_sum[i];
        }

        vector<int>ans;
        for(auto it:queries){
            int cnt = prefix_sum[it[1]+1] - prefix_sum[it[0]];
            ans.push_back(cnt);
        }
        return ans;
    }
};