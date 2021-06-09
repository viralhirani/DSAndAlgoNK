#include<iostream>
using namespace std;

int fectorial(int n)
{
    if(n==1) {
        return 1;
    }
    else {
        return n*fectorial(n-1);
    }
}
int main()
{
    cout<< fectorial(4)<<endl;

    return 0;
}