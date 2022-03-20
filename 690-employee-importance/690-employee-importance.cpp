/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int,int>mp;
    int dfs(vector<Employee*> employees,int v){
        int ans=employees[v]->importance;
        for(auto ele:employees[v]->subordinates){
            ans+=dfs(employees,mp[ele]);
        }
        return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {
        int ans=0;
        for(int i=0;i<employees.size();i++){
            mp[employees[i]->id]=i;
        }
        return dfs(employees,mp[id]);
        
    }
};