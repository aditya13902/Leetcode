class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) {
        int s=0,e=1;
        vector<string>ans;
        while(s<a.size())
        {    e=s+1;
            while(e<a.size() && a[e]==a[e-1]+1)
            e++;      
            if(e==s+1)
             ans.push_back(to_string(a[s]));
            else
                ans.push_back(to_string(a[s])+"->"+to_string(a[e-1]));
            s=e;     
        }
        return ans;  
    }
};