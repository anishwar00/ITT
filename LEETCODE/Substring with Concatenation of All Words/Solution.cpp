#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        
        if (s.length() < totalLen) return result;

        unordered_map<string, int> wordFreq;
        for (const string& w : words) wordFreq[w]++;

 
        for (int i = 0; i < wordLen; i++) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> currentWindow;

            while (right + wordLen <= s.length()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordFreq.count(word)) {
                    currentWindow[word]++;
                    count++;

                    while (currentWindow[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        currentWindow[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
           
                    currentWindow.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return result;
    }
};
