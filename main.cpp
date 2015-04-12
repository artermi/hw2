#include <map>
#include "theDATA.h"
#include "functions.h"
//#include <ctime>

using namespace std;
int main (int argc, char *argv[])
{
 //   time_t t1,t2;
    FILE *fp;
    fp = fopen(argv[1],"rb");
    int click;
    int impression;
    unsigned long long url;
    int AdId;
    int AderId;
    int depth;
    int position;
    int query;
    int keyword;
    int title;
    int description;
    int userID;
    map<int,vector<class data *> >forad;
    map<int,vector<class data *> >foruser;
   // t1 = time(NULL);
    while(fscanf(fp,"%d\t%d\t%llu\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",&click,&impression,&url,&AdId,
                 &AderId,&depth,&position,&query,&keyword,&title,&description,&userID) != EOF){
        data *newdata = new data();
        (*newdata).putin(click,impression,url,AdId,AderId,depth,position,query,keyword,title,description,userID);
        foruser[userID].push_back(newdata);
        forad[AdId].push_back(newdata);
                 }
  //  t2 = time(NULL);
   // printf("%d:%d\n",(t2 - t1) / 60, (t2 - t1) % 60);
    int u,a,p,q,d,u1,u2;
    double sida;
    string command;
    while(1){
        cin >> command;
        if(command == "quit")
            return 0;
        else if(command == "get"){
            cin >> u >> a >> q >> p >> d;
            cout << "********************" << endl;
            get(foruser[u],a,q,p,d);
            cout << "********************" << endl;

        }
        else if(command == "clicked"){
            cin >> u;;
            cout << "********************" << endl;
            clicked(foruser[u]);
            cout << "********************" << endl;
        }
        else if (command == "impressed"){
            cin >> u1 >> u2;
            cout << "********************" << endl;
            impressed(foruser[u1],foruser[u2]);
            cout << "********************" << endl;
        }
        else if(command == "profit"){
            cin >> a >> sida;
            cout << "********************" << endl;
            profit(forad[a],sida);
            cout << "********************" << endl;
        }
//
    }
    return 0;
}
