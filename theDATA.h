#ifndef THEDATA_H_INCLUDED
#define THEDATA_H_INCLUDED
#include<iostream>
#include<cstdio>
#include <vector>
using namespace std;
class data{
public:
    data();
    void putin(int n1,int n2,unsigned long long int n3, int n4, int n5,int n6,int n7,int n8,int n9,int n10,int n11,int n12);
    void print();
 //       unsigned long long url;
private:
    short int click;
    short int impression;
    unsigned long long url;
    unsigned int AdId;
    unsigned int AderId;
    short int depth;
    short int position;
    unsigned int query;
    unsigned int keyword;
    unsigned int title;
    unsigned int description;
    unsigned int userID;
friend class UserTree;
friend class AdTree;
friend void printall(vector<class data*> &v);
friend void get(vector<class data *> &u,int a,int q,int p,int d);
friend void clicked(vector<class data *> &u);
friend void impressed(vector<class data *> &u1,vector<class data *> &u2);
friend bool ptrcompare(class data* a,class data* b);
friend void profit(vector<class data *> &a,double sida);

};


#endif // THEDATA_H_INCLUDED
