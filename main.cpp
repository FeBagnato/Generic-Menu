#include<iostream>
#include<ncurses.h>
#include <sys/ioctl.h>
#include <unistd.h>
using namespace std;

int main(){
  int c;
  int optionsConf[4] = {0,0,0,0};
  int optionLocation = 1;

  // Get the number of rows in the terminal
  struct winsize size;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
  int terminalRow = size.ws_row;

  // Start the functions to manipulate the screen
  initscr();
  start_color();
  use_default_colors();
  init_pair(1, COLOR_WHITE, -1);
  init_pair(2, COLOR_GREEN, -1);
  init_pair(3, COLOR_WHITE, COLOR_BLUE);

  // Menu loop
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

    // Show the option keys
    attron(COLOR_PAIR(3));
    for(int i = terminalRow - 5; i > 0; i--) printw("\n");
    printw("Arrows[move]  Q[exit]  Enter[turn on/off]\n");
    c = getch();
    clear();

    // Compare the keys with the options
    if(c == 'A' && optionLocation != 1) optionLocation--;
    else if(c == 'B' && optionLocation != 4) optionLocation++;
    else if(c == '\n'){
      switch(optionLocation){
        case 1:
          if(optionsConf[0] == 0) optionsConf[0] = 1;
          else optionsConf[0] = 0;
          break;
        case 2:
          if(optionsConf[1] == 0) optionsConf[1] = 1;
          else optionsConf[1] = 0;
          break;
        case 3:
          if(optionsConf[2] == 0) optionsConf[2] = 1;
          else optionsConf[2] = 0;
          break;
        case 4:
          if(optionsConf[3] == 0) optionsConf[3] = 1;
          else optionsConf[3] = 0;
          break;
      }
    }
  } while(c != 'q');
  endwin();
  return 0;
}
