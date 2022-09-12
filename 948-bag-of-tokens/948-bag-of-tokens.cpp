class Solution {
public:
    
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0;
        int j=tokens.size()-1;
        int score=0;
        int ans=0;
        while(i<=j){
            if(power>=tokens[i]){
                // cout<<i<<endl;
                
                score++;
                power-=tokens[i];
                i++;
                
                // cout<<power<<endl;
            }
            else if(score>0){
                // cout<<j<<endl;
                power+=tokens[j];
                j--;
                score--;
                // cout<<power<<endl;
            }
            else{
                // cout<<"yes"<<endl;
                break;
            }
            ans=max(ans,score);
        }
        return ans;
        
    }
};