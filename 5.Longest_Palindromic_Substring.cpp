class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.size();
        // Transform the string s into t with separators, e.g. "abc" -> "^#a#b#c#$"
        string t = "^";
        for (int i = 0; i < n; i++) {
            t += "#" + s.substr(i, 1);
        }
        t += "#$";
        
        int m = t.size();
        vector<int> P(m, 0); // P[i] -> radius of palindrome centered at t[i]
        int C = 0, R = 0;    // C -> center, R -> right boundary of the current palindrome
        int maxLen = 0, centerIndex = 0;

        for (int i = 1; i < m - 1; i++) {
            int mirr = 2 * C - i; // Mirror of i around center C

            if (i < R)
                P[i] = min(R - i, P[mirr]);
            // expand palindrome centered at i
            while (t[i + P[i] + 1] == t[i - P[i] - 1])
                P[i]++;
            // If the palindrome centered at i expands past R, adjust C and R
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
            // Keep track of the longest palindrome
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }
        // Extract the longest palindromic substring from the original string
        int start = (centerIndex - maxLen) / 2; // Map back to original string
        return s.substr(start, maxLen);
    }
};