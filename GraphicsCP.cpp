#include "GraphicsCP.h"

#ifdef _WIN32

HANDLE hScreen;

void init_screen()
{
    hScreen = GetStdHandle(STD_OUTPUT_HANDLE);
	InitScreen(hScreen);
}

void refresh()
{
    //Doing nothing, only for linux
    system("CLS");

}
void setColour(int color)
{
    TextColor(color,BLACK,hScreen);

}
void writeString(std::string str, int x, int y,int len)
{
    GotoXY(x,y,hScreen);
	printf(str.c_str());
}

void writeChar(int c, int x, int y)
{
    GotoXY(x,y,hScreen);
    printf("%c",c);
}

char keypress()
{
    char tecla = '0';
    if (_kbhit())
			tecla=_getch();
    return tecla;
}

std::string keypress_str()
{
    char c = keypress();
    std::string tecla = std::string(c, 1);
    return tecla;
}

void clear_screen()
{
	system("CLS");
}

void pause_screen()
{
    system("PAUSE");
}

void sleep_screen(int ms)
{
    Sleep(ms);
}


#else
#include <iostream>
#include <X11/Xlib.h>
#include <X11/keysymdef.h>
#include <assert.h>
#include <unistd.h>

#define NIL (0)

#define RED "#FF0000"

///Globals
Display *dpy;
Window w;
GC gc;
int blackColor;
int whiteColor;
XEvent e;
std::string key;
//void initialize();
void init_screen()
{
    dpy = XOpenDisplay(NIL);
    assert(dpy);
    blackColor = BlackPixel(dpy, DefaultScreen(dpy));
    whiteColor = WhitePixel(dpy, DefaultScreen(dpy));
    createWindow(DY*10,DX*10);
}

void createWindow(int width, int height)
{
    w = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 0, 0,
                 width, height, 0, blackColor, blackColor);
    XSelectInput(dpy, w, StructureNotifyMask | KeyPressMask );
    XMapWindow(dpy, w);
    gc = XCreateGC(dpy, w, 0, NIL);
    XSetForeground(dpy, gc, whiteColor);

    for(;;) {

	    XNextEvent(dpy, &e);
	    if (e.type == MapNotify)
		  break;
      }
}

std::string keypress_str()
{
    if (e.type == KeyPress)
            return XKeysymToString(XKeycodeToKeysym(dpy,e.xkey.keycode,0));
    return "0";

}

char keypress()
{
    std::string str_c = keypress_str();
    char tecla = str_c[0];
    if(str_c.compare("Up")==0)
        return 37;
    else if(str_c.compare("Down")==0)
        return 38;
    else if(str_c.compare("Right")==0)
        return 39;
    else if(str_c.compare("Left")==0)
        return 40;
    else if(str_c.compare("space")==0)
        return 32;
    else if(str_c.compare("Escape")==0)
        return 27;
    else
    return tecla;
}

void setColour_str(std::string color)
{

    XColor xcolour;
    Colormap colormap;
    colormap = DefaultColormap(dpy, 0);
    XParseColor(dpy, colormap, color.c_str(), &xcolour);
    XAllocColor(dpy, colormap, &xcolour);

    // I guess XParseColor will work here
    //xcolour.red = R; xcolour.green = G; xcolour.blue = B;
    //xcolour.flags = DoRed | DoGreen | DoBlue;
    XSetForeground(dpy, gc, xcolour.pixel);
}



void setColour(int colour)
{
    switch(colour)
    {
        case 0: setColour_str("#000000");
            break;
        case 1: setColour_str("#0000FF");
            break;
        case 2: setColour_str("#00FF00");
            break;
        case 3: setColour_str("#00FFFF");
            break;
        case 4: setColour_str("#FF0000");
            break;
        case 5: setColour_str("#FF00FF");
            break;
        case 6: setColour_str("#8B4513");
            break;
        case 7: setColour_str("#8B4513");
            break;
        case 8: setColour_str("#8B4513");
            break;
        case 9: setColour_str("#8B4513");
            break;
        case 10 : setColour_str("#90EE90");
                    break;
        case 11 : setColour_str("#E0FFFF");
                    break;
        case 12 : setColour_str("#FF4500");
                    break;
        case 13 : setColour_str("#EE82EE");
                    break;

        case 14 : setColour_str("#FFFF00");
                    break;
        case 15 : setColour_str("#FFFFFF");
                    break;


        default: setColour_str("#FFFFFF");
            break;



    }

}


void writeString(std::string word, int x, int y, int len)
{
    XDrawString(dpy,w, gc,x*10,y*10,word.c_str(),len);
    XFlush(dpy);
}

void writeChar(int c, int x, int y)
{
    std::string str_word = std::string(1,char(c));
    writeString(str_word, x,y, 1);
}



void refresh()
{
if(XPending(dpy))
        XNextEvent(dpy, &e);
    XFlush(dpy);
    XClearWindow(dpy,w);
}

void clear_screen()
{
    std::system ("clear");
}

void pause_screen()
{
    sleep(10);
}

void sleep_screen(int ms)
{
    usleep(ms*1000);
}



#endif
