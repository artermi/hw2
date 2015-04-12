#include "theDATA.h"
data::data(){
    click = 0;
    impression = 0;
    url = 0;
    AdId = 0;
    AderId = 0;
    depth = 0;
    position = 0;
    query = 0;
    keyword = 0;
    title = 0;
    description = 0;
    userID = 0;
}
void data::putin(int n1,int n2,unsigned long long int n3, int n4, int n5,int n6,int n7,int n8,int n9,int n10,int n11,int n12){
    click = n1;
    impression = n2;
    url = n3;
    AdId = n4;
    AderId = n5;
    depth = n6;
    position = n7;
    query = n8;
    keyword = n9;
    title = n10;
    description = n11;
    userID = n12;
}
void data::print(){
    printf("%llu\n",url);
}
void printall(vector<class data* > &v){
    vector <class data* > :: iterator i;
    for(i = v.begin();i !=  v.end(); i++)
        printf("%u\n",(*i) -> userID);
}
