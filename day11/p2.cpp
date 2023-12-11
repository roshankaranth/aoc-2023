#include<bits/stdc++.h>
using namespace std;

int main(){

    ifstream in("input.txt");

    vector<pair<long long,long long>> galaxies; 
    vector<long long> rows;
    vector<long long> cols ;
    string str;
    long long l = 0 , b=0 ;
    while(getline(in,str)){
        if(b==0){b=str.length();}
        for(long long i = 0 ; str[i]!='\0'; i++){
            if(str[i]=='#'){
                galaxies.push_back({l,i});
            }
//177077874
            
        }
        l++;
    }
     

    
    for(long long i = 0 ; i < l-1 ; i++ ){
        long long flag  = 0 ;
            for(long long j = 0 ; j < galaxies.size() ; j++){
                if(galaxies[j].first==i){
                    flag=1;
                    
                }
            }

            if(flag==0){
                rows.push_back(i);
                
            }

    }
    
    for(long long i = 0 ; i < b ; i++ ){
        long long flag  = 0 ;
        
            for(long long j = 0 ; j < galaxies.size() ; j++){
                
                if(galaxies[j].second==i){
                    flag=1;
                    
                }
            }

            if(flag==0){
                cols.push_back(i);
                
            }

    }
    
    for(long long i = cols.size()-1 ; i >= 0 ; i--){
        for(long long j = 0 ; j < galaxies.size(); j++){
            if(cols[i]<galaxies[j].second){
                galaxies[j].second+=1;
            }
        }
    }

     for(long long i = rows.size()-1 ; i >= 0; i--){
        for(long long j = 0 ; j < galaxies.size(); j++){
            if(rows[i]<galaxies[j].first){
                galaxies[j].first+=1;
            }
        }
    }



    for(long long i = 0 ; i < galaxies.size(); i++){
        cout<<galaxies[i].first<<" "<<galaxies[i].second<<"\n";
    }

    long long sum = 0;
    for(long long i = 0 ; i < galaxies.size()-1; i++){
        long long track = -1;
        
        for(long long j = i+1 ; j < galaxies.size(); j++){
            long long dist = sqrt(pow((galaxies[i].first - galaxies[j].first),2)) + sqrt(pow((galaxies[i].second - galaxies[j].second),2));
            sum+=dist;
            cout<<"("<<galaxies[i].first<<","<<galaxies[i].second<<") "<<"("<<galaxies[j].first<<","<<galaxies[j].second<<") "<<dist<<"\n" ;

        }
        
    }

    cout<<sum;

    return 0;
}