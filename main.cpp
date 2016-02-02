#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
//#include <Magick++.h>
using namespace std;
typedef struct {
    unsigned short id;
    long posX,posY;
    int skewX,skewY;
    bool color;
} Section;
void position(int,int){}
void skew(int,int){}
void color(int){}
Section **out;
void initArr(unsigned int size){
    out=new Section*[size];
    for(unsigned int i=0;i<size;++i)
        out[i]=new Section;
}
int main(int,char*[]){
    fstream file;
    file.open("script.txt");
    if(!file.is_open()){
        cerr<<"File not found"<<endl;
        return -1;
    }
    string line;
    bool firstIteration=true,inSection=false;
    int numberOfSections,currentSectionNumber=-1;
    while(getline(file,line)){
        stringstream ss(line);

        /* parsing the first line */
        if(firstIteration){
            char at;
            ss>>at;
            if(at=='@') ss >> numberOfSections;
            else continue;
            initArr(numberOfSections);
            firstIteration=false;
        }

        if(!inSection){
            char octothorp;
            ss>>octothorp;
            if(octothorp=='#'){
                ++currentSectionNumber;
                int sectionId;
                ss>>sectionId;
                out[currentSectionNumber]->id=sectionId;
                inSection=true;
            }
            else continue;
        }
        else{
            string keyword;
            ss>>keyword;
            if(keyword=="position"){
                int arg1,arg2;
                ss>>arg1>>arg2;
                out[currentSectionNumber]->posX=arg1;
                out[currentSectionNumber]->posY=arg2;
            }
            if(keyword=="skew"){
                int arg1,arg2;
                ss>>arg1>>arg2;
                out[currentSectionNumber]->skewX=arg1;
                out[currentSectionNumber]->skewY=arg2;
            }
            if(keyword=="color"){
                int arg;
                ss>>arg;
                out[currentSectionNumber]->color=arg;
            }
            if(!(inSection=keyword!="&end")
            && currentSectionNumber+1==numberOfSections) break;
        }
    }
    for(int i=0;i<numberOfSections; i++)
    {
        cout<<"Section #"<<out[i]->color<<":"<<endl;
        cout<<"id: "<<out[i]->id<<endl;
        cout<<"posX: "<<out[i]->posX<<endl;
        cout<<"posY: "<<out[i]->posY<<endl;
        cout<<"slewX: "<<out[i]->skewX<<endl;
        cout<<"skewY: "<<out[i]->skewY<<endl;
        cout<<endl;
    }
    return 0;
}

