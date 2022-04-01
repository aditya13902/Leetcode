class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int>vec;
        if(mat.size()==0){
            return vec;;
        }
        int rowb=0;
        int rowe=mat.size()-1;
        int colb=0;
        int cole=mat[0].size()-1;
        while(rowb<=rowe && colb<=cole){
            for(int i=colb;i<=cole;i++){
                vec.push_back(mat[rowb][i]);
            }
            rowb++;
            for(int i=rowb;i<=rowe;i++){
                vec.push_back(mat[i][cole]);
            }
            cole--;
            if(rowb<=rowe){
                for(int i=cole;i>=colb;i--){
                    vec.push_back(mat[rowe][i]);
                }
                rowe--;
            }
            if(colb<=cole){
                for(int i=rowe;i>=rowb;i--){
                    vec.push_back(mat[i][colb]);
                } 
                colb++;
            }
        }
        return vec;
    }
};