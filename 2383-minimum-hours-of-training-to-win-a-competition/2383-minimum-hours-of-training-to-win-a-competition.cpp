class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int sum_energy=1;
        for(auto ele:energy){
            sum_energy+=ele;
        }
        int mx=0;
        for(auto ele:experience){
            mx=max(mx,(ele+1)-initialExperience);
            initialExperience+=ele;
        }
        // if(mx>0) mx++;
        // cout<<sum_energy<<endl;
        return max(0,sum_energy-initialEnergy)+mx;
    }
};