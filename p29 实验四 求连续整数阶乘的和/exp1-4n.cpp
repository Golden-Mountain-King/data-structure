#include<iostream>
using namespace std;
int main(){
    
    cout<<"������һ��������n:"<<endl;
    int n,i;
    cin>>n;
    long int s=1;
    long int sum=0;
    for(i=1;i<=n;i++){
        s*=i;
        sum+=s;
    }
    cout<<sum<<endl;
    
    return 0;
}