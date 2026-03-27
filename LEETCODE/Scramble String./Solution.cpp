#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution {
    std::unordered_map<std::string, bool> memo;

public:
    bool isScramble(std::string s1, std::string s2) {
       
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;
        
       
        std::string key = s1 + "_" + s2;
        if (memo.count(key)) return memo[key];

        std::string temp1 = s1, temp2 = s2;
        std::sort(temp1.begin(), temp1.end());
        std::sort(temp2.begin(), temp2.end());
        if (temp1 != temp2) return memo[key] = false;

        int n = s1.length();
        for (int i = 1; i < n; i++) {
           
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                isScramble(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }

      
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) && 
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }
};
