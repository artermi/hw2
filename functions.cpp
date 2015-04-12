#include "functions.h"
typedef struct ced{
        int adid;
        int quryid;
    } Ced;
typedef struct ied{
    unsigned long long int n1;
    int n2;
    int n3;
    int n4;
    int n5;
} Ied;
void get(vector<class data *> &u,int a,int q,int p,int d){
    int cli = 0,imp = 0;
    vector <class data* > :: iterator i;
    for(i = u.begin();i !=  u.end(); i++){
        if((*i) -> AdId == a && (*i) -> position == p && (*i) -> query == q && (*i) -> depth == d){
        cli += (*i) -> click;
        imp += (*i) -> impression;
        }
    }
    printf("%d %d\n",cli,imp);
};
bool clickcmp(const Ced &a,const Ced &b){
    if(a.adid != b.adid)
        return (a.adid < b.adid);
    else
        return(a.quryid < b.quryid);
}

void clicked(vector<class data *> &u){
    Ced ced;
    vector<Ced> ADnQry;
    vector<class data *>:: iterator i;
    for(i = u.begin(); i!= u.end(); i++){
        if((*i) -> click != 0){
        ced.adid = (*i) -> AdId;
        ced.quryid = (*i) -> query;
        ADnQry.push_back(ced);
        }
    }
    sort(ADnQry.begin(),ADnQry.end(),clickcmp);
    printf("%d %d\n",ADnQry[0].adid,ADnQry[0].quryid);
    int j;
    for(j = 1; j < ADnQry.size() ;j++){
        if(ADnQry[j].adid != ADnQry[j - 1].adid || ADnQry[j].quryid != ADnQry[j - 1].quryid)
            printf("%d %d\n",ADnQry[j].adid,ADnQry[j].quryid);
    }
};
bool impcmp(const Ied &a,const Ied &b){
    if(a.n5 != b.n5)
        return (a.n5 > b.n5);
    else if(a.n4 != b.n4)
        return(a.n4 > b.n4);
    else if(a.n3 != b.n3)
        return(a.n3 > b.n3);
    else if(a.n2 != b.n2)
        return(a.n2 > b.n2);
    else
        return(a.n1 > b.n1);
}

void impressed(vector<class data *> &u1,vector<class data *> &u2){
    vector<int> aderid;
    vector<class data *> :: iterator i,k;
    for(i = u1.begin(); i!= u1.end(); i++){
        if((*i) -> impression != 0)
            aderid.push_back((*i) -> AdId);
    }
    sort(aderid.begin(),aderid.end());
    vector<int>::iterator j;
    vector<Ied> imp;
    Ied ied;
    int x = -1;
    for(j = aderid.begin();j != aderid.end();j++){
        if(x == (*j))
            continue;
        bool toprint = false;
        for(i = u2.begin();i != u2.end();i++){
            if((*j) == (*i) -> AdId && (*i) -> impression != 0){
                toprint = true;
                ied.n1 = (*i) -> url; ied.n2 = (*i) -> AderId; ied.n3 =(*i) -> keyword;
                ied.n4 = (*i)-> title; ied.n5 = (*i) -> description;
                imp.push_back(ied);
            }
        }
        if(toprint){
            for(k = u1.begin(); k!= u1.end();k++){
                if((*k) -> AdId == (*j) ){
                    ied.n1 = (*k) -> url; ied.n2 = (*k) -> AderId; ied.n3 =(*k) -> keyword;
                    ied.n4 = (*k)-> title; ied.n5 = (*k) -> description;
                    imp.push_back(ied);
                }
            }
            sort(imp.begin(),imp.end(),impcmp);
            int m = 0;
            printf("%d\n",(*j));
            printf("\t%llu %d %d %d %d\n",imp[m].n1,imp[m].n2,imp[m].n3,imp[m].n4,imp[m].n5);
            for(m = 1; m < imp.size(); m++)
                if(imp[m].n1 != imp[m-1].n1 ||imp[m].n2 != imp[m-1].n2 ||imp[m].n3 != imp[m-1].n3||imp[m].n4 != imp[m-1].n4 ||imp[m].n5 != imp[m-1].n5)
                    printf("\t%llu %d %d %d %d\n", imp[m].n1,imp[m].n2,imp[m].n3,imp[m].n4,imp[m].n5);

        }
        imp.clear();
        x = (*j);
    }

};
bool ptrcompare(class data* a,class data* b){
    if(a -> userID < b -> userID)
        return true;
    else
        return false;
}
void profit(vector<class data *> &a,double sida){
    double pro;
    sort(a.begin(),a.end(),ptrcompare);
    unsigned int i;
    int cl =0,im = 0;
    for(i = 0; i < a.size(); i++){
        cl += a[i] -> click;
        im += a[i] -> impression;
        while((i + 1) < a.size() && (a[i] -> userID == a[i + 1] -> userID )){
            i++;
            cl += a[i] -> click;
            im += a[i] -> impression;
        }
        if(cl == 0)
            pro = 0;
        else
            pro = (double) cl / (double) im;
        if(pro >= sida)
            printf("%d\n",a[i] -> userID);
        cl =0;im = 0;
    }
};
