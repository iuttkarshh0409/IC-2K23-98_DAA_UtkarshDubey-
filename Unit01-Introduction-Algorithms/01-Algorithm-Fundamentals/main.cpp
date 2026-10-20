#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;

    if(n>0){
        int i,A[n];
        

        cout<<"Enter "<<n<<" elements->"<<endl;

        int max=A[0];

        for(i=0; i<n; i++){
            cin>>A[i];

            if(A[i]>max){
            max=A[i];
        }
            }
        cout<<"Largest element: "<<max;
    }
    else{
        cout<<"size of array is invalid; re-run the program";
    }
    return 0;
}
