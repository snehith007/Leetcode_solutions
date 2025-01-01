class Solution {
public:
    string convert(string s, int numRows) {

        //base case 
        if(numRows==1 || s.size()<= numRows) return s;

        vector<string>ans(numRows);
        //index to refer row
        int j=0;
        //pointer to move up or down
        int d=1;

        for(int i=0;i<s.size();i++){
            ans[j]+=s[i];
            if(j==numRows-1) d=-1;
            else if(j==0) d=1;

            j+=d;
        }
        return accumulate(ans.begin(),ans.end(),string{});
    }
};