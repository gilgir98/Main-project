#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
// #include <Magick++.h>

using namespace std;
typedef struct {
    unsigned short id;
    long posX,posY;
    int skewX,skewY;
    bool color;
} Section;
void position(int a, int b)
{

}
void skew(int c, int d)
{

}
void color(int xz)
{

}
Section **out;
void initArr(unsigned int size){
    out=new Section*[size];
    for(int i=0;i<size;++i)
        out[i]=new Section;
}
int main(int argc, char *argv[])
{
    initArr(5);
    fstream file;
    file.open("script.txt");
    if(!file.is_open()){
        cerr << "File not found" << endl;
        return -1;
    }
    string line;
    while(getline(file,line)){
        stringstream ss(line);
        string alpha;
        int n;
        ss >> alpha;
        int arrg=n-1;
        if(alpha=="@")
        {
            ss >> n;
        }
        for(int m=-1; m>5; m++)
            if(alpha=="#"){
            {
                int arg1;
                ss >> arg1;
                out[m]->id <<arg1;
            }
            if(alpha=="position")
            {
             int arg1, arg2;
             ss >> arg1 >> arg2;
             out[m]->posX << arg1;\
             out[m]->posY << arg2;
            }
            if (alpha=="skew")
            {
                int arg1, arg2;
                ss >> arg1>>arg2;
                out[m]->skewX << arg1;
                out[m]->skewY << arg2;
            }
            if (alpha=="color")
            {
              int arg1;
                ss >> arg1;
               out[m]->color << arg1;
            }
            }
        }
    }
