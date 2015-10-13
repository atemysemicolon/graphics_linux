#include <iostream>
#include "GraphicsCP.h"
using namespace std;






int main() {
int i  = 10;


///Initialize
std::string        key = "0";
        init_screen();


///Important




std::string c="0";
std::string bla1 = "Hello";
std::string bla2 = "World";
char boo;
//Drawing Loop
while(boo!=27)//while(boo!=Space)
{


    refresh();


    i=i+1;
    //Refresh

     boo = keypress();



    c = std::string(1,boo);

    if(c.compare("0")!=0)
    {

        bla1 = "Hello"+c;
        bla2 = "World"+c;
        c="0";
    }

    setColour(RED);
    writeString(bla1,i,6,bla1.length());
    //XDrawString(dpy,w, gc,10+i,60,bla.c_str(),bla.length());



    //setColour("#0000FF");
    writeString(bla2,i,8, bla2.length());
    //XDrawString(dpy,w, gc,10+i,80,bla.c_str(),bla.length());
    //XFlush(dpy);

    sleep_screen(1000);
    //Sleep(1000);

}

   return 0;
}

