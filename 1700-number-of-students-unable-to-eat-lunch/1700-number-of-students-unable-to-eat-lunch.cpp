class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        int i=0;
        for(auto ele:students) q.push(ele);
        int cnt=0;
        int n=students.size();
        while(i<sandwiches.size()){
            if(cnt==n-i) return n-i;
            if(q.front()==sandwiches[i]){
                i++;
                q.pop();
                cnt=0;
            }
            else{
                cnt++;
                q.push(q.front());
                q.pop();
            }
        }
        return 0;
    }
};