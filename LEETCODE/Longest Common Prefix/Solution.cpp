#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
 
        sort(strs.begin(), strs.end());
        
        string first = strs.front();
        string last = strs.back();
        string result = "";
         
        for (int i = 0; i < min(first.size(), last.size()); i++) {
            if (first[i] != last[i]) {
                break;
            }
            result += first[i];
        }
        
        return result;
    }
};
