//extract max element
#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>&v,int idx){
    int l=2*idx+1;
    int r=2*idx+2;
    int largest=0;
    if(l<=v.size()&&v[l]>v[idx]){
        largest=l;
    }
    else{
        largest=idx;
    }
    if(r<=v.size()&&v[r]>v[largest]){
        largest=r;
    }
    if(largest!=idx){
        swap(v[idx],v[largest]);
        heapify(v,largest);
    }
}
int extraxtMax(vector<int>&v){
    int max=v[0];
    v[0]=v[v.size()-1];
    v.pop_back();
    heapify(v,0);
    return max;
}
//must maintain 1 based indexing for increasing key(key>v[idx] bcz increasing)
void heapIncreaseKey(vector<int>&v,int idx,int key){
    v[idx]=key;
    while(idx>1&&v[idx]>v[idx/2]){
        swap(v[idx],v[idx/2]);
        idx=idx/2;
    }
}
void heapDecreaseKey(vector<int>&v,int idx,int key){
    v[idx]=key;
    heapify(v,idx);
}
void insertElement(vector<int>&v,int val){
    v.push_back(val);
    int idx=v.size()-1;
    while(idx>0&&v[idx]>v[(idx-1)/2]){
        swap(v[idx],v[(idx-1)/2]);
        idx=(idx-1)/2;
    }
}
int main(){
     int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    // extraxtMax(v);
    //heapDecreaseKey(v,1,0);
    insertElement(v,100);
    for(int i=0;i<n+1;i++){
        cout<<v[i]<<" ";
    }
}