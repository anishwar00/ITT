#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> result;
        std::string current;
        backtrack(s, 0, 0, current, result);
        return result;
    }

private:
    void backtrack(const std::string& s, int index, int segmentCount, std::string current, std::vector<std::string>& result) {
        
        if (segmentCount == 4) {
            if (index == s.length()) {
                current.pop_back();  
                result.push_back(current);
            }
            return;
        }
 
        for (int len = 1; len <= 3; ++len) {
            if (index + len > s.length()) break;

            std::string part = s.substr(index, len);
            int val = std::stoi(part);

     
            if (val > 255 || (part.length() > 1 && part[0] == '0')) {
                break; 
            }

            backtrack(s, index + len, segmentCount + 1, current + part + ".", result);
        }
    }
};
