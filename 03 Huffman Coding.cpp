#include <bits/stdc++.h> 
class MinHeapNode
{
    public:
    int data;
    int freq;
    MinHeapNode *left, *right;
    MinHeapNode(int d,int f){
        data=d;
        freq=f;
        left=right=NULL;
    }
};
struct compare{
    bool operator()(MinHeapNode *l,MinHeapNode* r){
        return l->freq > r->freq;
    }
};
void giveCode(MinHeapNode* root, string s,vector<string> &ans){
    if(!root) return;
    if(root->left==NULL && root->right==NULL){
        ans[root->data]=s;
        return;
    }
    giveCode(root->left,s+"0",ans);
    giveCode(root->right, s+"1", ans);
}
vector<string> huffmanCode(vector<int> &arr)
{
    MinHeapNode *l, *r, *top;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    int n= arr.size();
    if(n==1) return {"0"};
    for(int i=0;i<n;i++){
        MinHeapNode * temp = new MinHeapNode(i, arr[i]);
        minHeap.push(temp);
    }
    while(minHeap.size()!=1){
        l = minHeap.top();
        minHeap.pop();

        r=minHeap.top(); 
        minHeap.pop();

        top= new MinHeapNode(-1,l->freq+ r->freq);
        top->left=l;
        top->right=r;
        minHeap.push(top);
    }
    vector<string> ans(n);
    giveCode(minHeap.top(),"",ans);
    return ans;
}
/*
Constraints:
1 <= T <= 10
1 <= N <= 10^4
1 <= ARR[i]  <= 10^4

Where 'T' denotes the number of test cases, 'N' denotes the elements in the array 'ARR', and 'ARR[i]' denotes the 'i'th' element of the array 'ARR'.

Time Limit: 1 sec
Sample Input 1:
2
3
5 7 6
2
4 3
*/
