#include<iostream>
#include<cmath>
using namespace std;
int main_loop(int * , int );
int ret_det(int * a , int s , int y){
    int i_ar = 0  , j_ar = 0 ;
    int * arr_in = new int[(s-1)*(s-1)];
    for (int i = 1 ; i < s ; i++){
        for(int j = 0 ; j < s ; j++){
            if (j != y){
                if(j_ar == s-1){
                    ++i_ar;
                    j_ar = 0 ;
                }
                arr_in[(i_ar*(s-1)) + j_ar] = a[(i*s) + j];
                ++j_ar ;
            }
        }
        }
    if(s == 3){
        return (arr_in[0]*arr_in[3] - arr_in[1]*arr_in[2]);
    }
    else
        return main_loop(arr_in , s-1);
}
int main_loop(int * a , int s){
    int determinant = 0 ;
    for ( int j = 0 ; j < s ; j++)
            determinant += a[j] * pow(-1 , j+2) * ret_det(a , s , j);
    return determinant;
}
int main(){
    int s ;
    int * arr ;
    cin>>s ;
    arr = new int[s * s];
    for (int i = 0 ; i < s ; i++){
        for ( int j = 0 ; j < s ; j++)
            cin>>arr[i*s + j];
    }
    cout<< "-------------------" <<endl ;
    for (int i = 0 ; i < s ; i++){
        for ( int j = 0 ; j < s ; j++)
            cout<<arr[i*s + j];
        cout<< endl;
    }
    cout<< main_loop(arr , s);
    cin.get();
}
