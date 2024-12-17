class Solution {
public:
    string multiply(string num1, string num2) {

       /* long long ans1 = stoi(num1);
        long long ans2 = stoi(num2);
        long long ans = ans1*ans2;

        string res = to_string(ans);
        return res;*/

        int n=num1.length(),m=num2.length();
        vector<int> ans(n+m, 0);

        if(num1=="0" || num2=="0") return "0";
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int temp= (num1[i]-'0') * (num2[j]-'0');
                int sum= temp +ans[i+j+1];
                
                ans[i+j+1] =sum%10;
                ans[i+j] +=sum/10;
            }
        }
        string s="";
        for(int a:ans){
            if(!(s.empty() && a==0)) s.push_back(a+'0');
        }
        return s.empty() ? "0":s;
        
    }
};