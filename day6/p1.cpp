#include<bits/stdc++.h>
using namespace std;

int main(){

    ifstream in("input.txt");

    int arr[2][4];
    string str;
    int row = 0;
    while(getline(in,str)){
        
        int number = 0;
        int col = 0;
        for(int i = 0 ; str[i]!='\0'; i++){

            if(str[i]>= 48 && str[i]<=57){
                number = number*10 + (str[i]- '0');
 
            }

             if((str[i+1]==' ' || str[i+1]=='\0') && number!=0){
                arr[row][col] = number;
                number = 0;
                col++;
            }

           
        }
        
        row++;
    }
    int ans =1;

    for(int i = 0 ; i< 4 ; i++ ){
        int count = 0;
        for(int j = arr[0][i] ; j>= 0 ; j-- ){
            if(arr[1][i]<(arr[0][i]-j)*j){
                count++;
            }
            
        }
        cout<<count<<" ";
        ans = ans*count;
    }

  
    cout<<ans;
    return 0;
}