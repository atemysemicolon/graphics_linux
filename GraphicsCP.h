#ifndef GRAPHICSCP_H_INCLUDED
#define GRAPHICSCP_H_INCLUDED
#include <string>


//DEFINITIONS
//===================================================================================
// Dimensions del finestra de la consola


//FUNCTION DECLARATIONS
void init_screen();
void refresh();
void setColour(int colour);
void writeString(std::string str, int x, int y,int len);
void writeChar(int c, int x, int y);
std::string keypress_str();
char keypress();
void clear_screen();
void pause_screen();
void sleep_screen(int ms);



//SPECIFIC-OS RELATED PART

#ifdef _WIN32
//ALL WINDOWS PART
    #include "Graphics_win.h"
    #include <conio.h>      /* getch */
    #include <stdio.h>      /* printf */

    extern HANDLE hScreen;

//END WINDOWS PART


#else
//LINUX PART
    #include <cstdlib>
    #include <unistd.h> //For Sleep

    #define BLACK 0
    #define BLUE 1
    #define GREEN 2
    #define CYAN 3
    #define RED 4
    #define MAGENTA 5
    #define BROWN 6
    #define LIGHTGREY 7
    #define DARKGREY 8
    #define LIGHTBLUE 9
    #define LIGHTGREEN 10
    #define LIGHTCYAN 11
    #define LIGHTRED 12
    #define LIGHTMAGENTA 13
    #define YELLOW 14
    #define WHITE 15
    #define BLINK 128

    #define UpArrow 37
    #define DownArrow 38
    #define RightArrow 39
    #define LeftArrow 40
    #define Space 32
    #define Escape 27

    #define DX 41
    #define DY 31
    #define INICI_X 4
    #define INICI_Y 6


    //========================================================================
    // Fi del taulell respecte la cantonada superior esquerre
    #define FI_X 36
    #define FI_Y 26


    //===================================================================================
    // Codi Bloc de disseny per parets
    #define GESPA 'o' // Codi simbol


    void createWindow(int width, int height);

#endif

#endif // GRAPHICSCP_H_INCLUDED
