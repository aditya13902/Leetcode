class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int>mask(words.size());
        for(int i=0;i<words.size();i++){
            int num=0;
            for(auto ch:words[i]){
                num=num|(1<<(ch-'a'));
            }
            mask[i]=num;
        }
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(!(mask[i]& mask[j])){
                    int l1=words[i].size();
                    int l2=words[j].size();
                    ans=max(ans,l1*l2);
                }
            }
        }
        return ans;
        
    }
};