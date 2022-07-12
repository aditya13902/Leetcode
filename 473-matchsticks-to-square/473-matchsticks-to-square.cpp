class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(auto ele:matchsticks) sum+=ele;
        if (matchsticks.size() < 4 || sum % 4) return false;
        
        vector<int>visited(matchsticks.size(), false);
        return backtrack(matchsticks, visited, sum / 4, 0, 0, 4);
    }
    
    bool backtrack(vector<int>& matchsticks,vector<int>&visited, int target, int curr_sum, int i, int k) {
        if (k == 1)
            return true;
        
        if (curr_sum == target) 
            return backtrack(matchsticks, visited, target, 0, 0, k-1);
        
        for (int j = i; j < matchsticks.size(); j++) {
            if (visited[j] || curr_sum + matchsticks[j] > target) continue;
            visited[j] = true;
            if (backtrack(matchsticks, visited, target, curr_sum + matchsticks[j], j+1, k)) return true;
            visited[j] = false;
        }
        
        return false;
    }
};