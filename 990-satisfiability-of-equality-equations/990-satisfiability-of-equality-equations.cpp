class Solution {
public:
    vector<int>parent;
    int find(int v){
        if(parent[v]==v){
            return v;
        }
        return parent[v]=find(parent[v]);
    }
    void Union(int a,int b){
        a=find(a);
        b=find(b);
        parent[b]=a;
    }
    bool equationsPossible(vector<string>& equations) {
        // parent.resize();
        // sort(equations.begin(),equations.end());
        for(int i=0;i<26;i++){
            parent.push_back(i);
        }
        for(auto str:equations){
            char ch1=str[0];
            char ch2=str[3];
            // cout<<ch1<<ch2<<endl;
            char var=str[1];
            if(var=='!'){
                
            }
            else{
                int n1=ch1-'a';
                int n2=ch2-'a';
                Union(n1,n2);
            }
        }
        for(auto str:equations){
            char ch1=str[0];
            char ch2=str[3];
            // cout<<ch1<<ch2<<endl;
            char var=str[1];
            if(var=='!'){
                int n1=ch1-'a';
                int n2=ch2-'a';
                n1=find(n1);
                n2=find(n2);
                if(n1==n2){
                    return false;
                }
            }
        }
        return true;
    }
};