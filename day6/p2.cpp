#include<bits/stdc++.h>
using namespace std;

int main(){

    ifstream in("input.txt");

    long long int arr[2];
    string str;
    int row = 0;

    while(getline(in,str)){
        
        long long int number = 0;
        for(int i = 0 ; str[i]!='\0'; i++){

            if(str[i]>= 48 && str[i]<=57){
                number = number*10 + (str[i]- '0');
                
            }

        }
        arr[row] = number;
        row++;
    }

        int count = 0;
        for(long long int j = arr[0] ; j>= 0 ; j-- ){
            if(arr[1]<(arr[0]-j)*j){
                count++;
            }
            
        }
        cout<<count<<" ";
        

    return 0;
}