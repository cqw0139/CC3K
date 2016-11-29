//
//  print.cpp
//  cc3k
//
//  Created by ChengQiwei on 2016-11-28.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#include "print.h"
#include"ncurses.h"
#include<iostream>
#include <unistd.h>
#define DELAY 50000
using namespace std;
void printLogo(){
    clear();
    printw("$$$$$$$$$$$$$$$$\"\"$o$o$o$o$o$oo$$\"\"$$$$$$$$$$$$$$$\n");
    refresh();
    usleep(DELAY);
    printw("$$$$$$$$$$$$\"\"o$$$$$$$$$$\"$\"$$$$$$$o$\"$$$$$$$$$$$$\n");
    refresh();
    usleep(DELAY);
    printw("$$$$$$$$$\"$o$$$$\"\"$oo $ \"\"      \"\"\"$$$oo\"$$$$$$$$$\n");
    refresh();
    usleep(DELAY);
    printw("$$$$$$$\"o$$$$\"   \"\"o  $oo o o       \"\"$$$o\"$$$$$$$\n");
    refresh();
    usleep(DELAY);
    printw("$$$$$\"o$$$\"       oo$$$$$$$$$$o        \"$$$o\"$$$$$\n");
    refresh();
    usleep(DELAY);
    printw("$$$$\"o$$$  $  o$$$$$$$$$$$$$$\"$$oo       \"$$$ $$$$\n");
    refresh();
    usleep(DELAY);
    printw("$$$\"$$$\"   \"$$$$$$$$$$$$$$$$o$o$$$\"        $$$o$$$\n");
    refresh();
    usleep(DELAY);
    printw("$$ $$$    o$$$$$$$$$$$$$$$$$$$$$$$$o o   o  \"$$o\"$\n");
    refresh();
    usleep(DELAY);
    printw("$\"$$$\"    o$$$$$$$$$\"$$$$$$\"\" \"$$$$$$\"$$$$$  $$$\"$\n");
    refresh();
    usleep(DELAY);
    printw("$o$$\"    o$$$$$$$$$$o\"\"$$$\"\"\"\"ooo\"$$$$$$$$\"   $$$\"\n");
    refresh();
    usleep(DELAY);
    printw("$o$$\"    o$$$$$$$$$$            \"\"oo\"$\"$o\"\"   $$$o\n");
    refresh();
    usleep(DELAY);
    printw("o$$$     o$$$$$$$$$$                \"\"\"\"\"$    o$$o\n");
    refresh();
    usleep(DELAY);
    printw("o$$$    o$$$$$$$$$$$$o                   \"o \"oo$$o\n");
    refresh();
    usleep(DELAY);
    printw("o$$$  oo$$$$$$$$$$$$$$$$ooooooo$$$$$oo    $\"$ \"$$o\n");
    refresh();
    usleep(DELAY);
    printw("o$$$\"  \"\"  $$$$$$$$$$$$$$$$$$$$$$$$$$$$o    \" $$$\n");
    refresh();
    usleep(DELAY);
    printw("$ $$$       \"$$$$$$$$$$$$$$$$$$$$$$$$$$$o    o$$\"$\n");
    refresh();
    usleep(DELAY);
    printw("$$\"$$o       \"$$$$$$$$$$$$$$$$$$$$$$$$$$$o   $$$o$\n");
    refresh();
    usleep(DELAY);
    printw("$$o$$$o       $$\"\"$$$$$$$$$$$$$$$$$$$$$$$o  $$$ $$\n");
    refresh();
    usleep(DELAY);
    printw("$$$o\"$$o    \"$\"\"  \"$\"\"$$$$$$$$$$$$$$$$$$$oo$$$\"$$$\n");
    refresh();
    usleep(DELAY);
    printw("$$$$o\"$$$o        \"     $$$$$$$$$$$$$$$$$o$$\"o$$$$\n");
    refresh();
    usleep(DELAY);
    printw("$$$$$$o\"$$$o         oo$$$$$$$$$$$$$$$$$$$$\"o$$$$$\n");
    refresh();
    usleep(DELAY);
    printw("$$$$$$$$o\"$$$$ooooo$$$$$$$$$$$$$$$$$$$$$$\"o$$$$$$$\n");
    refresh();
    usleep(DELAY);
    printw("$$$$$$$$$$o\"\"$$$$$$$$$$$$$$$$$$$$$$$$$\"oo$$$$$$$$$\n");
    refresh();
    usleep(DELAY);
    printw("$$$$$$$$$$$$$o$\"\"$$$$$$$$$$$$$$$$$\"\"oo$$$$$$$$$$$$\n");
    refresh();
    usleep(DELAY);
    printw("$$$$$$$$$$$$$$$$$$o$o$\"$\"$\"$\"$oo$o$$$$$$$$$$$$$$$$\n");    
    refresh();
    usleep(DELAY);
    clear();
    refresh();
    usleep(DELAY);
    clear();
    printw("$$$$$$$$$$$$$$$$\"\"$o$o$o$o$o$oo$$\"\"$$$$$$$$$$$$$$$\n");
    printw("$$$$$$$$$$$$\"\"o$$$$$$$$$$\"$\"$$$$$$$o$\"$$$$$$$$$$$$\n");
    printw("$$$$$$$$$\"$o$$$$\"\"$oo $ \"\"      \"\"\"$$$oo\"$$$$$$$$$\n");
    printw("$$$$$$$\"o$$$$\"   \"\"o  $oo o o       \"\"$$$o\"$$$$$$$\n");
    printw("$$$$$\"o$$$\"       oo$$$$$$$$$$o        \"$$$o\"$$$$$\n");
    printw("$$$$\"o$$$  $  o$$$$$$$$$$$$$$\"$$oo       \"$$$ $$$$\n");
    printw("$$$\"$$$\"   \"$$$$$$$$$$$$$$$$o$o$$$\"        $$$o$$$\n");
    printw("$$ $$$    o$$$$$$$$$$$$$$$$$$$$$$$$o o   o  \"$$o\"$\n");
    printw("$\"$$$\"    o$$$$$$$$$\"$$$$$$\"\" \"$$$$$$\"$$$$$  $$$\"$\n");
    printw("$o$$\"    o$$$$$$$$$$o\"\"$$$\"\"\"\"ooo\"$$$$$$$$\"   $$$\"\n");
    printw("$o$$\"    o$$$$$$$$$$            \"\"oo\"$\"$o\"\"   $$$o\n");
    printw("o$$$     o$$$$$$$$$$                \"\"\"\"\"$    o$$o\n");
    printw("o$$$    o$$$$$$$$$$$$o                   \"o \"oo$$o\n");
    printw("o$$$  oo$$$$$$$$$$$$$$$$ooooooo$$$$$oo    $\"$ \"$$o\n");
    printw("o$$$\"  \"\"  $$$$$$$$$$$$$$$$$$$$$$$$$$$$o    \" $$$\n");
    printw("$ $$$       \"$$$$$$$$$$$$$$$$$$$$$$$$$$$o    o$$\"$\n");
    printw("$$\"$$o       \"$$$$$$$$$$$$$$$$$$$$$$$$$$$o   $$$o$\n");
    printw("$$o$$$o       $$\"\"$$$$$$$$$$$$$$$$$$$$$$$o  $$$ $$\n");
    printw("$$$o\"$$o    \"$\"\"  \"$\"\"$$$$$$$$$$$$$$$$$$$oo$$$\"$$$\n");
    printw("$$$$o\"$$$o        \"     $$$$$$$$$$$$$$$$$o$$\"o$$$$\n");
    printw("$$$$$$o\"$$$o         oo$$$$$$$$$$$$$$$$$$$$\"o$$$$$\n");
    printw("$$$$$$$$o\"$$$$ooooo$$$$$$$$$$$$$$$$$$$$$$\"o$$$$$$$\n");
    printw("$$$$$$$$$$o\"\"$$$$$$$$$$$$$$$$$$$$$$$$$\"oo$$$$$$$$$\n");
    printw("$$$$$$$$$$$$$o$\"\"$$$$$$$$$$$$$$$$$\"\"oo$$$$$$$$$$$$\n");
    printw("$$$$$$$$$$$$$$$$$$o$o$\"$\"$\"$\"$oo$o$$$$$$$$$$$$$$$$\n");
    refresh();
    usleep(DELAY);
    clear();
    refresh();
    usleep(DELAY);
    clear();
    printw("$$$$$$$$$$$$$$$$\"\"$o$o$o$o$o$oo$$\"\"$$$$$$$$$$$$$$$\n");
    printw("$$$$$$$$$$$$\"\"o$$$$$$$$$$\"$\"$$$$$$$o$\"$$$$$$$$$$$$\n");
    printw("$$$$$$$$$\"$o$$$$\"\"$oo $ \"\"      \"\"\"$$$oo\"$$$$$$$$$\n");
    printw("$$$$$$$\"o$$$$\"   \"\"o  $oo o o       \"\"$$$o\"$$$$$$$\n");
    printw("$$$$$\"o$$$\"       oo$$$$$$$$$$o        \"$$$o\"$$$$$\n");
    printw("$$$$\"o$$$  $  o$$$$$$$$$$$$$$\"$$oo       \"$$$ $$$$\n");
    printw("$$$\"$$$\"   \"$$$$$$$$$$$$$$$$o$o$$$\"        $$$o$$$\n");
    printw("$$ $$$    o$$$$$$$$$$$$$$$$$$$$$$$$o o   o  \"$$o\"$\n");
    printw("$\"$$$\"    o$$$$$$$$$\"$$$$$$\"\" \"$$$$$$\"$$$$$  $$$\"$\n");
    printw("$o$$\"    o$$$$$$$$$$o\"\"$$$\"\"\"\"ooo\"$$$$$$$$\"   $$$\"\n");
    printw("$o$$\"    o$$$$$$$$$$            \"\"oo\"$\"$o\"\"   $$$o\n");
    printw("o$$$     o$$$$$$$$$$                \"\"\"\"\"$    o$$o\n");
    printw("o$$$    o$$$$$$$$$$$$o                   \"o \"oo$$o\n");
    printw("o$$$  oo$$$$$$$$$$$$$$$$ooooooo$$$$$oo    $\"$ \"$$o\n");
    printw("o$$$\"  \"\"  $$$$$$$$$$$$$$$$$$$$$$$$$$$$o    \" $$$\n");
    printw("$ $$$       \"$$$$$$$$$$$$$$$$$$$$$$$$$$$o    o$$\"$\n");
    printw("$$\"$$o       \"$$$$$$$$$$$$$$$$$$$$$$$$$$$o   $$$o$\n");
    printw("$$o$$$o       $$\"\"$$$$$$$$$$$$$$$$$$$$$$$o  $$$ $$\n");
    printw("$$$o\"$$o    \"$\"\"  \"$\"\"$$$$$$$$$$$$$$$$$$$oo$$$\"$$$\n");
    printw("$$$$o\"$$$o        \"     $$$$$$$$$$$$$$$$$o$$\"o$$$$\n");
    printw("$$$$$$o\"$$$o         oo$$$$$$$$$$$$$$$$$$$$\"o$$$$$\n");
    printw("$$$$$$$$o\"$$$$ooooo$$$$$$$$$$$$$$$$$$$$$$\"o$$$$$$$\n");
    printw("$$$$$$$$$$o\"\"$$$$$$$$$$$$$$$$$$$$$$$$$\"oo$$$$$$$$$\n");
    printw("$$$$$$$$$$$$$o$\"\"$$$$$$$$$$$$$$$$$\"\"oo$$$$$$$$$$$$\n");
    printw("$$$$$$$$$$$$$$$$$$o$o$\"$\"$\"$\"$oo$o$$$$$$$$$$$$$$$$\n"); 
    printw("\n");
    printw("enter anything to continue\n");
}
