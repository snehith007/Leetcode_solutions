class Solution {
    void calculateLPSArray(vector<string>& strings, vector<vector<int>>& lpsArray) {
        for (string currentString : strings) {
            int length = currentString.size();
            vector<int> lps(length);

            // Two-pointer technique
            int pointer1 = 1, pointer2 = 0;
            while (pointer1 < length) {
                if (currentString[pointer1] == currentString[pointer2]) {
                    lps[pointer1] = pointer2 + 1;
                    pointer1++;
                    pointer2++;
                } else if (pointer2 > 0) {
                    pointer2 = lps[pointer2 - 1];
                } else {
                    pointer1++;
                }
            }
            lpsArray.push_back(lps);
        }
    }

    bool matchSubstring(string& subPattern, vector<int>& lpsArray, string& targetText) {
        int subLength = subPattern.size();
        int targetLength = targetText.size();
        int subIdx = 0; // for pattern
        int targetIdx = 0; //  for text

        while (subIdx < subLength && targetIdx < targetLength) {
            if (subPattern[subIdx] == targetText[targetIdx]) {
                subIdx++;
                targetIdx++;
            }
            if (subIdx == subLength)
                return true;

            if (targetIdx < targetLength && subPattern[subIdx] != targetText[targetIdx]) {
                if (subIdx > 0) {
                    subIdx = lpsArray[subIdx - 1];
                } else {
                    targetIdx++;
                }
            }
        }
        return false;
    }

    static bool sizeComparator(string& firstWord, string& secondWord) {
        return firstWord.size() <= secondWord.size();
    }

public:
    vector<string> stringMatching(vector<string>& words) {
        int wordCount = words.size();

        //Sort words by length (smaller word acts as pattern)
        sort(words.begin(), words.end(), sizeComparator);

        //Compute LPS for all words
        vector<vector<int>> lpsArray;
        calculateLPSArray(words, lpsArray);

        // Check all combinations of words for substring match
        vector<string> result;
        for (int i = 0; i < wordCount - 1; ++i) {
            for (int j = i + 1; j < wordCount; ++j) {
                if (matchSubstring(words[i], lpsArray[i], words[j])) {
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        return result;
    }
};
