#include<iostream>
#include<ncurses.h>
using namespace std;

int main(){
  int c;
  int optionsConf[4] = {0,0,0,0};
  int optionLocation = 1;

  initscr();
  start_color();
  use_default_colors();
  init_pair(1, COLOR_WHITE, -1);
  init_pair(2, COLOR_GREEN, -1);
  init_pair(3, COLOR_WHITE, COLOR_BLUE);

  do{
    if(optionLocation == 1){
      attron(COLOR_PAIR(2));
      if(optionsConf[0] == 1) printw("OPTION 1  [ON]\n");
      else printw("OPTION 1  [OFF]\n");
    }
    else{
      attron(COLOR_PAIR(1));
      if(optionsConf[0] == 1) printw("OPTION 1  [ON]\n");
      else printw("OPTION 1  [OFF]\n");
    }
    if(optionLocation == 2){
      attron(COLOR_PAIR(2));
      if(optionsConf[1] == 1) printw("OPTION 2  [ON]\n");
      else printw("OPTION 2  [OFF]\n");
    }
    else{
      attron(COLOR_PAIR(1));
      if(optionsConf[1] == 1) printw("OPTION 2  [ON]\n");
      else printw("OPTION 2  [OFF]\n");
    }
    if(optionLocation == 3){
      attron(COLOR_PAIR(2));
      if(optionsConf[2] == 1) printw("OPTION 3  [ON]\n");
      else printw("OPTION 3  [OFF]\n");
    }
    else{
      attron(COLOR_PAIR(1));
      if(optionsConf[2] == 1) printw("OPTION 3  [ON]\n");
      else printw("OPTION 3  [OFF]\n");
    }
    if(optionLocation == 4){
      attron(COLOR_PAIR(2));
      if(optionsConf[3] == 1) printw("OPTION 4  [ON]\n");
      else printw("OPTION 4  [OFF]\n");
    }
    else{
      attron(COLOR_PAIR(1));
      if(optionsConf[3] == 1) printw("OPTION 4  [ON]\n");
      else printw("OPTION 4  [OFF]\n");
    }

    attron(COLOR_PAIR(3));
    printw("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printw("Arrows[move]  Q[exit]  Enter[turn on/off]\n");
    c = getch();
    clear();

    if(c == 'q') break;
    else if(c == 'A' && optionLocation != 1) optionLocation--;
    else if(c == 'B' && optionLocation != 4) optionLocation++;
  } while(1);
  endwin();

  return 0;
}
