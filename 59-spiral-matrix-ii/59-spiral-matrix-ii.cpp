class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rs = 0, re = n-1;
        int cs = 0, ce = n-1;
        int val = 0;
        vector<vector<int>> v(n, vector<int> (n));
        while(rs <= re && cs <= ce)
        {
            for(int i = cs; i <= ce; ++i)
                v[rs][i] = ++val;				

            rs++;
            for(int i = rs; i <= re; ++i)
                v[i][ce] = ++val;
            ce--;
            if(rs <= re && cs <= ce)
            {
                for(int i = ce; i>=cs; --i)
                    v[re][i] = ++val;
                re--;
				for(int i = re; i>=rs; --i) 
                    v[i][cs] = ++val;
                cs++;
            }
        }
        return v;
    }
};