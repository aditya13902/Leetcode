// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    unordered_map<Node*,Node*>mp;
    Node* node;
    void traverse(Node* root,Node* par,int target){
        if(!root){
            return;
        }
        mp[root]=par;
        if(root->data==target){
            node=root;
        }
        traverse(root->left,root,target);
        traverse(root->right,root,target);
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        traverse(root,NULL,target);
        queue<Node*>q;
        // cout<<node->data<<endl;
        q.push(node);
        int cnt=0;
        unordered_map<Node*,int>vis;
        vis[node]=1;
        
        while(q.size()){
            int l=q.size();
            while(l--){
                auto top=q.front();
                q.pop();
                // if(vis[top]){
                //     continue;
                // }
                
                if(mp[top] && !vis[mp[top]]){
                    vis[top]=1;
                    q.push(mp[top]);
                }
                if(top->left && !vis[top->left]){
                    vis[top]=1;
                    q.push(top->left);
                }
                if(top->right && !vis[top->right]){
                    vis[top]=1;
                    q.push(top->right);
                }
            }
            if(q.size()){
                cnt++;
            }
            // cnt++;
            // cnt++;
        }
        return cnt;
        
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends