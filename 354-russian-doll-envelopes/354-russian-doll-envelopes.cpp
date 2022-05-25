class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& A) {

        int n=A.size();
        if(n==0)
            return 0;


        sort(A.begin(),A.end(),cmp);

        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            auto it=lower_bound(ans.begin(),ans.end(),A[i][1]);
                if(it==ans.end()) ans.push_back(A[i][1]);
            else
                *it=A[i][1];
        }
        return ans.size();

    }
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return (a[0]<b[0]||(a[0]==b[0] && a[1]>b[1]));
    }
};