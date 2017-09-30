#include<iostream>
#include<time.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define CLOCKS_PRE_SEC 1000
//--------------����һ--------------
bool prime1(long int n){    //����һ:�ж�������n�Ƿ�Ϊ����
    long i;
    for(i=2;i<n;i++){
        if(n%i==0)
            return false;
    }
    return true;
} 
void Prime1Time(long int n){
    clock_t t;
    long sum=0,i;
    t=clock();
    for(i=2;i<=n;i++)
        if(prime1(i))
            sum++;
    t=clock()-t;
    cout<<"����2:"<<endl;
    cout<<"���:2~"<<n<<"����������:"<<sum<<endl;
    cout<<"��ʱ:"<<((float)t)/CLOCKS_PRE_SEC<<endl;
}              
//--------------������--------------
bool prime2(long int n){
    long i;
    for(i=2;i<=(int)sqrt(n);i++)
        if(n%i==0)
            return false;
    return true;
}
void Prime2Time(long int n){
    clock_t t;
    long sum=0,i;
    t=clock();
    for(i=2;i<=n;i++)
        if(prime2(i))
            sum++;
    t=clock()-t;
    cout<<"����2:"<<endl;
    cout<<"���:2~"<<n<<"����������:"<<sum<<endl;
    cout<<"��ʱ:"<<((float)t)/CLOCKS_PRE_SEC<<endl;
}
//-------------------------------------------------
int main(){
    long int n;
    cout<<"n(����100000):"<<endl;
    cin>>n;
    if(n<100000) 
        return 0;
    Prime1Time(n);
    Prime2Time(n);
    return 1;
}
