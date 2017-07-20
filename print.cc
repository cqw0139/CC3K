//
//  print.cpp
//  cc3kbonus
//
//  Created by ChengQiwei on 2016-12-02.
//  Copyright © 2016 ChengQiwei. All rights reserved.
//

#include "print.h"
#include "ncurses.h"
#include <iostream>
#include <unistd.h>
#define DELAY 100000
using namespace std;
void printLogo(){
    clear();
    printw("             .                                                         \n");
    refresh();
    usleep(DELAY);
    printw("           b   A                                                       \n");
    refresh();
    usleep(DELAY);
    printw("           $b  Vb.                                                     \n");
    refresh();
    usleep(DELAY);
    printw("           '$b  V$b.                                                   \n");
    refresh();
    usleep(DELAY);
    printw("            $$b  V$$b.                                                 \n");
    refresh();
    usleep(DELAY);
    printw("            '$$b. V$$$$oooooooo.         ..                             \n");
    refresh();
    usleep(DELAY);
    printw("             '$$P* V$$$$$\"\"**$$$b.    .o$$P                             \n");
    refresh();
    usleep(DELAY);
    printw("              \" .oooZ$$$$b..o$$$$$$$$$$$$C                             \n");
    refresh();
    usleep(DELAY);
    printw("              .$$$$$$$$$$$$$$$$$$$$$$$$$$$b.                           \n");
    refresh();
    usleep(DELAY);
    printw("              $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$                           \n");
    refresh();
    usleep(DELAY);
    printw("        .o$$$o$$$$$$$$P\"\"*$$$$$$$$$P\"\"\"*$$$P                           \n");
    refresh();
    usleep(DELAY);
    printw("       .$$$**$$$$P\"q$C    \"$$$b        .$$P                             \n");
    refresh();
    usleep(DELAY);
    printw("       $$P   \"$$$b  \"$ . .$$$$$b.      *\"                               \n");
    refresh();
    usleep(DELAY);
    printw("       $$      $$$.     \"***$$$$$$$b. A.                               \n");
    refresh();
    usleep(DELAY);
    printw("       V$b   . Z$$b.  .       \"*$$$$$b$$:                               \n");
    refresh();
    usleep(DELAY);
    printw("        V$$.  \"*$$$b.  b.         \"$$$$$                               \n");
    refresh();
    usleep(DELAY);
    printw("         \"$$b     \"*$.  *b.         \"$$$b                               \n");
    refresh();
    usleep(DELAY);
    printw("           \"$$b.     \"L  \"$$o.        \"*\"     .ooo..                   \n");
    refresh();
    usleep(DELAY);
    printw("             \"*$$o.        \"*$$o.          .o$$$$$$$$b.                 \n");
    refresh();
    usleep(DELAY);
    printw("                 \"*$$b.       \"$$b.       .$$$$$*\"   \"\"*.               \n");
    refresh();
    usleep(DELAY);
    printw("                    \"*$$o.      \"$$$o.    $$$$$'                       \n");
    refresh();
    usleep(DELAY);
    printw("                       \"$$o       \"$$$b.  \"$$$$   ...oo..               \n");
    refresh();
    usleep(DELAY);
    printw("                         \"$b.      \"$$$$b. \"$$$$$$$P*\"\"\"\"\"             \n");
    refresh();
    usleep(DELAY);
    printw("                        . \"$$       \"$$$$b  \"$$$$P\"                     \n");
    refresh();
    usleep(DELAY);
    printw("                         L.\"$.      .$$$$$.  $$$$                       \n");
    refresh();
    usleep(DELAY);
    printw("                          $$$;      o$$$$$$  $$$$                       \n");
    refresh();
    usleep(DELAY);
    printw("                          \"$$'    .$$$$$$$P  $$$P                       \n");
    refresh();
    usleep(DELAY);
    printw("                            \"P   .P*\"\"*$$$$;  $$$                       \n");
    refresh();
    usleep(DELAY);
    printw("                             \" .\"      $$$$   $$;                       \n");
    refresh();
    usleep(DELAY);
    printw("                             '       o$$$P  .$P                         \n");
    refresh();
    usleep(DELAY);
    clear();
    refresh();
    usleep(DELAY);
    clear();
    printw("             .                                                         \n");
    printw("           b   A                                                       \n");
    printw("           $b  Vb.                                                     \n");
    printw("           '$b  V$b.                                                   \n");
    printw("            $$b  V$$b.                                                 \n");
    printw("            '$$b. V$$$$oooooooo.         ..                             \n");
    printw("             '$$P* V$$$$$\"\"**$$$b.    .o$$P                             \n");
    printw("              \" .oooZ$$$$b..o$$$$$$$$$$$$C                             \n");
    printw("              .$$$$$$$$$$$$$$$$$$$$$$$$$$$b.                           \n");
    printw("              $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$                           \n");
    printw("        .o$$$o$$$$$$$$P\"\"*$$$$$$$$$P\"\"\"*$$$P                           \n");
    printw("       .$$$**$$$$P\"q$C    \"$$$b        .$$P                             \n");
    printw("       $$P   \"$$$b  \"$ . .$$$$$b.      *\"                               \n");
    printw("       $$      $$$.     \"***$$$$$$$b. A.                               \n");
    printw("       V$b   . Z$$b.  .       \"*$$$$$b$$:                               \n");
    printw("        V$$.  \"*$$$b.  b.         \"$$$$$                               \n");
    printw("         \"$$b     \"*$.  *b.         \"$$$b                               \n");
    printw("           \"$$b.     \"L  \"$$o.        \"*\"     .ooo..                   \n");
    printw("             \"*$$o.        \"*$$o.          .o$$$$$$$$b.                 \n");
    printw("                 \"*$$b.       \"$$b.       .$$$$$*\"   \"\"*.               \n");
    printw("                    \"*$$o.      \"$$$o.    $$$$$'                       \n");
    printw("                       \"$$o       \"$$$b.  \"$$$$   ...oo..               \n");
    printw("                         \"$b.      \"$$$$b. \"$$$$$$$P*\"\"\"\"\"             \n");
    printw("                        . \"$$       \"$$$$b  \"$$$$P\"                     \n");
    printw("                         L.\"$.      .$$$$$.  $$$$                       \n");
    printw("                          $$$;      o$$$$$$  $$$$                       \n");
    printw("                          \"$$'    .$$$$$$$P  $$$P                       \n");
    printw("                            \"P   .P*\"\"*$$$$;  $$$                       \n");
    printw("                             \" .\"      $$$$   $$;                       \n");
    printw("                             '       o$$$P  .$P                         \n");
    clear();
    refresh();
    usleep(DELAY);
    clear();
    printw("             .                                                         \n");
    printw("           b   A                                                       \n");
    printw("           $b  Vb.                                                     \n");
    printw("           '$b  V$b.                                                   \n");
    printw("            $$b  V$$b.                                                 \n");
    printw("            '$$b. V$$$$oooooooo.         ..                             \n");
    printw("             '$$P* V$$$$$\"\"**$$$b.    .o$$P                             \n");
    printw("              \" .oooZ$$$$b..o$$$$$$$$$$$$C                             \n");
    printw("              .$$$$$$$$$$$$$$$$$$$$$$$$$$$b.                           \n");
    printw("              $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$                           \n");
    printw("        .o$$$o$$$$$$$$P\"\"*$$$$$$$$$P\"\"\"*$$$P                           \n");
    printw("       .$$$**$$$$P\"q$C    \"$$$b        .$$P                             \n");
    printw("       $$P   \"$$$b  \"$ . .$$$$$b.      *\"                               \n");
    printw("       $$      $$$.     \"***$$$$$$$b. A.                               \n");
    printw("       V$b   . Z$$b.  .       \"*$$$$$b$$:                               \n");
    printw("        V$$.  \"*$$$b.  b.         \"$$$$$                               \n");
    printw("         \"$$b     \"*$.  *b.         \"$$$b                               \n");
    printw("           \"$$b.     \"L  \"$$o.        \"*\"     .ooo..                   \n");
    printw("             \"*$$o.        \"*$$o.          .o$$$$$$$$b.                 \n");
    printw("                 \"*$$b.       \"$$b.       .$$$$$*\"   \"\"*.               \n");
    printw("                    \"*$$o.      \"$$$o.    $$$$$'                       \n");
    printw("                       \"$$o       \"$$$b.  \"$$$$   ...oo..               \n");
    printw("                         \"$b.      \"$$$$b. \"$$$$$$$P*\"\"\"\"\"             \n");
    printw("                        . \"$$       \"$$$$b  \"$$$$P\"                     \n");
    printw("                         L.\"$.      .$$$$$.  $$$$                       \n");
    printw("                          $$$;      o$$$$$$  $$$$                       \n");
    printw("                          \"$$'    .$$$$$$$P  $$$P                       \n");
    printw("                            \"P   .P*\"\"*$$$$;  $$$                       \n");
    printw("                             \" .\"      $$$$   $$;                       \n");
    printw("                             '       o$$$P  .$P                         \n");
    printw("\n");
    printw("enter anything to continue\n");
    char ch;
    ch = getch();
}

void printPowerUp(){
    clear();
    printw(" _______  _______  _     _  _______  ______        __   __  _______ \n");
    refresh();
    usleep(DELAY);
    printw("|       ||       || | _ | ||       ||    _ |      |  | |  ||       |\n");
    refresh();
    usleep(DELAY);
    printw("|    _  ||   _   || || || ||    ___||   | ||      |  | |  ||    _  |\n");
    refresh();
    usleep(DELAY);
    printw("|   |_| ||  | |  ||       ||   |___ |   |_||_     |  |_|  ||   |_| |\n");
    refresh();
    usleep(DELAY);
    printw("|    ___||  |_|  ||       ||    ___||    __  |    |       ||    ___|\n");
    refresh();
    usleep(DELAY);
    printw("|   |    |       ||   _   ||   |___ |   |  | |    |       ||   |    \n");
    refresh();
    usleep(DELAY);
    printw("|___|    |_______||__| |__||_______||___|  |_|    |_______||___|    \n");
    refresh();
    usleep(DELAY);
    clear();
    refresh();
    usleep(DELAY);
    clear();
    printw(" _______  _______  _     _  _______  ______        __   __  _______ \n");
    printw("|       ||       || | _ | ||       ||    _ |      |  | |  ||       |\n");
    printw("|    _  ||   _   || || || ||    ___||   | ||      |  | |  ||    _  |\n");
    printw("|   |_| ||  | |  ||       ||   |___ |   |_||_     |  |_|  ||   |_| |\n");
    printw("|    ___||  |_|  ||       ||    ___||    __  |    |       ||    ___|\n");
    printw("|   |    |       ||   _   ||   |___ |   |  | |    |       ||   |    \n");
    printw("|___|    |_______||__| |__||_______||___|  |_|    |_______||___|    \n");
    clear();
    refresh();
    usleep(DELAY);
    clear();
    printw(" _______  _______  _     _  _______  ______        __   __  _______ \n");
    printw("|       ||       || | _ | ||       ||    _ |      |  | |  ||       |\n");
    printw("|    _  ||   _   || || || ||    ___||   | ||      |  | |  ||    _  |\n");
    printw("|   |_| ||  | |  ||       ||   |___ |   |_||_     |  |_|  ||   |_| |\n");
    printw("|    ___||  |_|  ||       ||    ___||    __  |    |       ||    ___|\n");
    printw("|   |    |       ||   _   ||   |___ |   |  | |    |       ||   |    \n");
    printw("|___|    |_______||__| |__||_______||___|  |_|    |_______||___|    \n");
    printw("\n");
    printw("enter any key to continue\n");
    char ch;
    ch = getch();
}

void printWin(){
    initscr();
    clear();
    printw(" __   __  _______  __   __      _     _  ___   __    _ \n");
    refresh();
    usleep(DELAY);
    printw("|  | |  ||       ||  | |  |    | | _ | ||   | |  |  | |\n");
    refresh();
    usleep(DELAY);
    printw("|  |_|  ||   _   ||  | |  |    | || || ||   | |   |_| |\n");
    refresh();
    usleep(DELAY);
    printw("|       ||  | |  ||  |_|  |    |       ||   | |       |\n");
    refresh();
    usleep(DELAY);
    printw("|_     _||  |_|  ||       |    |       ||   | |  _    |\n");
    refresh();
    usleep(DELAY);
    printw("  |   |  |       ||       |    |   _   ||   | | | |   |\n");
    refresh();
    usleep(DELAY);
    printw("  |___|  |_______||_______|    |__| |__||___| |_|  |__|\n");
    refresh();
    usleep(DELAY);
    clear();
    refresh();
    usleep(DELAY);
    clear();
    printw(" __   __  _______  __   __      _     _  ___   __    _ \n");
    printw("|  | |  ||       ||  | |  |    | | _ | ||   | |  |  | |\n");
    printw("|  |_|  ||   _   ||  | |  |    | || || ||   | |   |_| |\n");
    printw("|       ||  | |  ||  |_|  |    |       ||   | |       |\n");
    printw("|_     _||  |_|  ||       |    |       ||   | |  _    |\n");
    printw("  |   |  |       ||       |    |   _   ||   | | | |   |\n");
    printw("  |___|  |_______||_______|    |__| |__||___| |_|  |__|\n");
    clear();
    refresh();
    usleep(DELAY);
    clear();
    printw(" __   __  _______  __   __      _     _  ___   __    _ \n");
    printw("|  | |  ||       ||  | |  |    | | _ | ||   | |  |  | |\n");
    printw("|  |_|  ||   _   ||  | |  |    | || || ||   | |   |_| |\n");
    printw("|       ||  | |  ||  |_|  |    |       ||   | |       |\n");
    printw("|_     _||  |_|  ||       |    |       ||   | |  _    |\n");
    printw("  |   |  |       ||       |    |   _   ||   | | | |   |\n");
    printw("  |___|  |_______||_______|    |__| |__||___| |_|  |__|\n");
    printw("\n");
    printw("enter any key to quit\n");
    char ch;
    ch = getch();
    endwin();
}

void printLose(){
    initscr();
    clear();
    printw(" __   __  _______  __   __      ___      _______  _______  _______ \n");
    refresh();
    usleep(DELAY);
    printw("|  | |  ||       ||  | |  |    |   |    |       ||       ||       |\n");
    refresh();
    usleep(DELAY);
    printw("|  |_|  ||   _   ||  | |  |    |   |    |   _   ||  _____||    ___|\n");
    refresh();
    usleep(DELAY);
    printw("|       ||  | |  ||  |_|  |    |   |    |  | |  || |_____ |   |___ \n");
    refresh();
    usleep(DELAY);
    printw("|_     _||  |_|  ||       |    |   |___ |  |_|  ||_____  ||    ___|\n");
    refresh();
    usleep(DELAY);
    printw("  |   |  |       ||       |    |       ||       | _____| ||   |___ \n");
    refresh();
    usleep(DELAY);
    printw("  |___|  |_______||_______|    |_______||_______||_______||_______|\n");
    refresh();
    usleep(DELAY);
    clear();
    refresh();
    usleep(DELAY);
    clear();
    printw(" __   __  _______  __   __      ___      _______  _______  _______ \n");
    printw("|  | |  ||       ||  | |  |    |   |    |       ||       ||       |\n");
    printw("|  |_|  ||   _   ||  | |  |    |   |    |   _   ||  _____||    ___|\n");
    printw("|       ||  | |  ||  |_|  |    |   |    |  | |  || |_____ |   |___ \n");
    printw("|_     _||  |_|  ||       |    |   |___ |  |_|  ||_____  ||    ___|\n");
    printw("  |   |  |       ||       |    |       ||       | _____| ||   |___ \n");
    printw("  |___|  |_______||_______|    |_______||_______||_______||_______|\n");
    clear();
    refresh();
    usleep(DELAY);
    clear();
    printw(" __   __  _______  __   __      ___      _______  _______  _______ \n");
    printw("|  | |  ||       ||  | |  |    |   |    |       ||       ||       |\n");
    printw("|  |_|  ||   _   ||  | |  |    |   |    |   _   ||  _____||    ___|\n");
    printw("|       ||  | |  ||  |_|  |    |   |    |  | |  || |_____ |   |___ \n");
    printw("|_     _||  |_|  ||       |    |   |___ |  |_|  ||_____  ||    ___|\n");
    printw("  |   |  |       ||       |    |       ||       | _____| ||   |___ \n");
    printw("  |___|  |_______||_______|    |_______||_______||_______||_______|\n");
    printw("\n");
    printw("enter any key to quit\n");
    char ch;
    ch = getch();
    endwin();
}

char printpcinfo (){
    clear();
    printw("%s", "PC infomation: ");
    printw("%s", "\n");
    refresh();
    printw("%s", "Shade: ");
    printw("%s", "\n");
    refresh();
    printw("%s", "Passive: ");
    printw("%s", "\n");
    refresh();
    printw("%s", "  Shade native : Your final score is your current gold *1.5.");
    printw("%s", "\n");
    refresh();
    printw("%s", "  Lucky 7 : Your will have 1/7 chance to kill a npc immediately, your will have 1/7 chance to pick 7* value of gold.");
    printw("%s", "\n");
    printw("%s", "\n");
    refresh();
    printw("%s", "Drow: ");
    printw("%s", "\n");
    refresh();
    printw("%s", "Passive: ");
    printw("%s", "\n");
    refresh();
    printw("%s", "  Drow native : You will get 1.5* effect when you use potion. Elf will only attack you once.");
    printw("%s", "\n");
    refresh();
    printw("%s", "  Posion Body : When you be attacted, the attacker will get 5 point damage.");
    printw("%s", "\n");
    printw("%s", "\n");
    refresh();
    printw("%s", "Troll: ");
    printw("%s", "\n");
    refresh();
    printw("%s", "Passive: ");
    printw("%s", "\n");
    refresh();
    printw("%s", "  Troll native : You will gain 5 points HP per turn");
    printw("%s", "\n");
    refresh();
    printw("%s", "  Grow : After you kill a npc, you can randomly get 1-5 Atk or Def.");
    printw("%s", "\n");
    printw("%s", "\n");
    refresh();
    printw("%s", "Vampire: ");
    printw("%s", "\n");
    refresh();
    printw("%s", "Passive: ");
    printw("%s", "\n");
    refresh();
    printw("%s", "  Vampire native : You will gain 5 points HP when you attack, you will lose 5 points HP when you attack dwarf. You don't have max HP.");
    printw("%s", "\n");
    refresh();
    printw("%s", "  Blood Rage : You will restore the npc's 30%% max HP when you kill it. You will only restore max 50 HP at once.");
    printw("%s", "\n");
    printw("%s", "\n");
    refresh();
    printw("%s", "Goblin: ");
    printw("%s", "\n");
    refresh();
    printw("%s", "Passive: ");
    printw("%s", "\n");
    refresh();
    printw("%s", "  Goblin native : You will get 5 gold when you attack, you will receive 50%% more damage when orcs attack you.");
    printw("%s", "\n");
    refresh();
    printw("%s", "  Hand of Midas: When you pick gold, you will receive twice of the money by your creation.");
    printw("%s", "\n");
    printw("%s", "\n");
    refresh();
    printw("%s", "Saber: ");
    printw("%s", "\n");
    refresh();
    printw("%s", "Passive: ");
    printw("%s", "\n");
    refresh();
    printw("%s", "  Invisible Air : PC will reduce at most 5 Damages by the invisible air and PC will consume at least 1 Damage");
    printw("%s", "\n");
    refresh();
    printw("%s", "  Excalibur: 1/7 chance to deal a tripple damage to enemy an restore the amount of HP PC deals with enemy when PC use Excalibur");
    printw("%s", "\n");
    printw("%s", "\n");
    refresh();
    printw("%s", "DeathKnight: ");
    printw("%s", "\n");
    refresh();
    printw("%s", "Passive: ");
    printw("%s", "\n");
    refresh();
    printw("%s", "  Death Knight Talent : PC will resurgence when PC first died and restore 100 HP immediately");
    printw("%s", "\n");
    refresh();
    printw("%s", "  FrostMourne: PC will ignore the def when PC attack enemy, always treat enemy as 0 def.");
    printw("%s", "\n");
    printw("%s", "\n");
    refresh();
    printw("%s", "press anykey to continue ");
    printw("%s", "\n");
    refresh();
    char ch;
    ch = getch();
    clear();
    printw("%s", "Please enter one of s(Shade), d(Drow), v(Vampire), g(Goblin), t(Troll), a(Saber) or e(Deathknight) to choose a race.");
    printw("%s", "\n");
    refresh();
    char pctype;
    while (1){
        pctype = getch();
        if (pctype == 's' || pctype == 'd' || pctype == 'v' || pctype == 'g'
            || pctype == 't' || pctype == 'a' || pctype == 'e')
            return pctype;
        else {
            move(0, 0);
            printw("%s", "Please enter one of s(Shade), d(Drow), v(Vampire), g(Goblin), t(Troll), a(Saber) or e(Deathknight) to choose a race.");
            printw("%s", "\n");
            refresh();
        }
    }
}

void printinfo(string type, int level){
    clear();
    if (type == "shade"){
        printw("%s", "Shade:\n");
        printw("%s", "  Shade native : Your final score is your current gold *1.5.");
        printw("%s", "\n");
        refresh();
        printw("%s", "  You need to reach level 4 to learn the second skill.");
        printw("%s", "\n");
        refresh();
    }
    if (type == "Dark Mage"){
        printw("%s", "Dark Mage:\n");
        printw("%s", "  Shade native : Your final score is your current gold *1.5.");
        printw("%s", "\n");
        refresh();
        printw("%s", "  Lucky 7 : Your will have 1/7 chance to kill a npc immediately, your will have 1/7 chance to pick 7* value of gold.");
        printw("%s", "\n");
        refresh();
    }
    if (type == "drow"){
        printw("%s", "Drow:\n");
        printw("%s", "  Drow native : You will get 1.5* effect when you use potion. Elf will only attack you once.");
        printw("%s", "\n");
        refresh();
        printw("%s", "  You need to reach level 4 to learn the second skill.");
        printw("%s", "\n");
        refresh();
    }
    if (type == "Venomancer"){
        printw("%s", "Venomancer:\n");
        printw("%s", "  Drow native : You will get 1.5* effect when you use potion. Elf will only attack you once.");
        printw("%s", "\n");
        refresh();
        printw("%s", "  Posion Body : When you be attacted, the attacker will get 5 point damage.");
        printw("%s", "\n");
        refresh();
    }
    if (type == "troll"){
        printw("%s", "Troll:\n");
        printw("%s", "  Troll native : You will gain 5 points HP per turn");
        printw("%s", "\n");
        refresh();
        printw("%s", "  You need to reach level 4 to learn the second skill.");
        printw("%s", "\n");
        refresh();
    }
    if (type == "Devil"){
        printw("%s", "Devil:\n");
        printw("%s", "  Troll native : You will gain 5 points HP per turn");
        printw("%s", "\n");
        refresh();
        printw("%s", "  Grow : After you kill a npc, you can randomly get 1-5 Atk or Def.");
        printw("%s", "\n");
        refresh();
    }
    if (type == "vampire"){
        printw("%s", "Vampire:\n");
        printw("%s", "  Vampire native : You will gain 5 points HP when you attack, you will lose 5 points HP when you attack dwarf. You don't have max HP.");
        printw("%s", "\n");
        refresh();
        printw("%s", "  You need to reach level 4 to learn the second skill.");
        printw("%s", "\n");
        refresh();
    }
    if (type == "Bloodseeker"){
        printw("%s", "Bloodseeker:\n");
        printw("%s", "  Vampire native : You will gain 5 points HP when you attack, you will lose 5 points HP when you attack dwarf. You don't have max HP.");
        printw("%s", "\n");
        refresh();
        printw("%s", "  Blood Rage : You will restore the npc's 30%% max HP when you kill it. You will only restore max 50 HP at once.");
        printw("%s", "\n");
        refresh();
    }
    if (type == "goblin"){
        printw("%s", "Goblin:\n");
        printw("%s", "  Goblin native : You will get 5 gold when you attack, you will receive 50%% more damage when orcs attack you.");
        printw("%s", "\n");
        refresh();
        printw("%s", "  You need to reach level 4 to learn the second skill.");
        printw("%s", "\n");
        refresh();
    }
    if (type == "goblin"){
        printw("%s", "Alchemist:\n");
        printw("%s", "  Goblin native : You will get 5 gold when you attack, you will receive 50%% more damage when orcs attack you.");
        printw("%s", "\n");
        refresh();
        printw("%s", "  Hand of Midas: When you pick gold, you will receive twice of the money by your creation.");
        printw("%s", "\n");
        refresh();
    }
    if (type == "deathknight"){
        printw("%s", "DeathKnight:\n");
        printw("%s", "  Death Knight Talent : PC will resurgence when PC first died and restore 100 HP immediately");
        printw("%s", "\n");
        refresh();
        printw("%s", "  You need to reach level 4 to learn the second skill.");
        printw("%s", "\n");
        refresh();
    }
    if (type == "Lich King"){
        printw("%s", "Lich King:\n");
        printw("%s", "  Death Knight Talent : PC will resurgence when PC first died and restore 100 HP immediately");
        printw("%s", "\n");
        refresh();
        printw("%s", "  FrostMourne: PC will ignore the def when PC attack enemy, always treat enemy as 0 def.");
        printw("%s", "\n");
        refresh();
    }
    if (type == "saber"){
        printw("%s", "Saber:\n");
        printw("%s", "  Invisible Air : PC will reduce at most 5 Damages by the invisible air and PC will consume at least 1 Damage");
        printw("%s", "\n");
        refresh();
        printw("%s", "  You need to reach level 4 to learn the second skill.");
        printw("%s", "\n");
        refresh();
    }
    if (type == "Royal Saber"){
        printw("%s", "Lich King:\n");
        printw("%s", "  Invisible Air : PC will reduce at most 5 Damages by the invisible air and PC will consume at least 1 Damage");
        printw("%s", "\n");
        refresh();
        printw("%s", "  Excalibur: 1/7 chance to deal a tripple damage to enemy an restore the amount of HP PC deals with enemy when PC use Excalibur");
        printw("%s", "\n");
        refresh();
    }
    printw("%s", "press any key to continue.");
    printw("%s", "\n");
    char ch;
    ch = getch();
}

void printcontrol(){
    clear();
    printw("%s", "Control:");
    printw("%s", "\n");
    printw("%s", "  wasd: move / attack / use potion / pick gold");
    printw("%s", "\n");
    printw("%s", "  i: check ability.");
    printw("%s", "\n");
    printw("%s", "  press any key to continue");
    printw("%s", "\n");
    refresh();
    char ch = getch();
}
