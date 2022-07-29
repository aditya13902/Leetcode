class Solution {
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        vector<string> result;
        for (string &word : words) {
            if (matches(pattern, word)) {
                result.push_back(word);
            }
        }
        return result;
    }
    
    bool matches(string &p, string &w) {
        unordered_map<char, char> wordMap, patternMap;
        for (int i = 0; i < w.size(); i++) {
            if (wordMap.find(w[i]) == wordMap.end()) {
                wordMap[w[i]] = p[i];
            }
            if (patternMap.find(p[i]) == patternMap.end()) {
                patternMap[p[i]] = w[i];
            }
            if (wordMap[w[i]] != p[i] || patternMap[p[i]] != w[i]) {
                return false;
            }
        }
        return true;
    }
};