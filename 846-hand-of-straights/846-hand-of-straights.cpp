class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       unordered_map<int,int>mp;
        // priority_queue
       sort(hand.begin(),hand.end());
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        for(auto ele:hand){
            if(mp[ele]==0){
                continue;
            }
            for(int j=0;j<groupSize;j++){
                if(mp[ele+j]>0){
                    mp[ele+j]--;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};