#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int reachable = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            
            if (i > reachable) return false;
            
            
            reachable = std::max(reachable, i + nums[i]);
            
            
            if (reachable >= n - 1) return true;
        }
        
        return true;
    }
};
