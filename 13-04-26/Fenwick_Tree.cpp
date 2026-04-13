#include<bits/stdc++.h>
using namespace std;
vector<int>bit;
int n;

int sum(int i){
    int ans=0;
    for(;i>0;i-=(i&-i)){
        ans+=bit[i];
    }
    return ans;
}
void update(int i,int x){
    for(;i<=n;i+=(i&-i)){
        bit[i]+=x;
    }
}
int main(){
    n=5;
    bit.resize(n+1);
    vector<int>arr={0,1,2,3,4,5};
    for(int i=1;i<=n;i++){
        update(i,arr[i]);

    }
    cout<<sum(3)<<endl;
    cout<<sum(5)<<endl;
    update(3,2);
    cout<<"After Update:"<<endl;
    cout<<sum(3)<<endl;
    cout<<sum(4)-sum(1)<<endl;
    
    return 0;
}
