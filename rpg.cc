// Dave's attempt at an RPG
///putting linux terminal into raw mode
/////in order to read keystrokes without pressing enter

/*v57 -- MiniGame cont'd
 - minigame is not 100% perfect, but the bugs are not game breaking,
     the minigame is able to be completed, and every game comes out with initial bugs ;]
 - enemies render correctly, can be killed, or kill character
 - completion renders a new level:
     still have to add character to new level render
*/


#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <random>
#include <map>
#include <cstdio>
#include <thread>
using namespace std;

struct termios orig_termios;

void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode);

  struct termios raw = orig_termios;
  raw.c_lflag &= ~(ECHO | ICANON);

  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 1;

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void enableRawMode2() {
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode);

  struct termios raw = orig_termios;
  raw.c_lflag &= ~(ECHO | ICANON);

  raw.c_cc[VMIN] > 0;
  raw.c_cc[VTIME] > 0;

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}


string ifOK(string strOK) {
 // This detects when player types ok to continue to next screen
 while(strOK != "ok") {
  cout << "\nType ok to continue...\n";
  cin >> strOK;
  string ifOK(strOK);
 }
 return strOK;
}


string ifFour(string fourChoices, string choicesOffered) {
  fourChoices = '\0';
  while(
      fourChoices != "1" &&
      fourChoices != "2" &&
      fourChoices != "3" &&
      fourChoices != "4"){
    cout << choicesOffered;
    cin >> fourChoices;
  }
return fourChoices;
}


string ifThree(string threeChoices, string choicesOffered3) {
  threeChoices = '\0';
  do{
    cout << choicesOffered3;
    cin >> threeChoices;
  }
  while(
      threeChoices != "1" &&
      threeChoices != "2" &&
      threeChoices != "3");
  return threeChoices;
}


int beginGame(int ewInt) {
// check to see if game was played before
ifstream gameFile;
gameFile.open("exists.drp");
if(gameFile) {
// cout << "file exists\n";
 ewInt = 1;
 return ewInt;
} else {
// cout << "file does not exist\n";
 ewInt = 0;
 return ewInt;
}
}


void newpause()
{
  std::cout << std::endl << "Press any key to continue...";
  getchar();
}


class My_class
{
public:
string myPlayArea[36][102];
int playerLevel=1;
int playerLife = 100, playerPower = 1, playerDefense = 1, playerMagic = 1;
int charX = 32;
int charY = 51;
string whichWay;
void makeTheLevel();
void printTheLevel();
void itsNancei();
void aBush();
void aWeapon();
void swapWeapons();
void swapSuccess();
void noSwap();
void aBattle();
void runFight();
void abilityFight();
void openBag();
void weaponFight();
void initialBattlePrint();
void makeBattleArray(string nMonster, int nMonsterLevel);
void printBattleArray();
void attackWithWeapon();
void enemyTurn();
void aPotion();
void anAbility();
string weaponFightArray[34][9];
int nDaggers = 0;
int nSwords = 0;
int nStars = 0;
int nFlails = 0;
int nHammers = 0;
int nBows = 0;
int nWeapons = 0;
string wOne;
string wOnes;
int wOneAttack = 0;
int wOneSpeed = 0;
string wTwo;
string wTwos;
int wTwoSpeed = 0;
int wTwoAttack = 0;
string wThree;
string wThrees;
int wThreeAttack = 0;
int wThreeSpeed = 0;
string wNew;
string wNews;
int wNewAttack = 0;
int wNewSpeed = 0;
string swapArray[34][102];
string tempvar2;
int lWeapons = 0; //how many weapons in the level during gen
string battleArray[34][7];
string nEnemy;
int nEnemyLevel;
string nEnemyIcon = "👹";
string nEnemyHealth = "■■■■■■■■■■";
string nPlayerHealth = "■■■■■■■■■■";
int nEnemyHealthi;
string nMonster1 = "Poppie";
int nMonster1Level = playerLevel;
int wOfChoice = 0;
int wOfChoicer = 0;
int willitland = 0;
int willitlandr = 0;
int amtdamage = 0;
int wfl=0;
int ax = 29;
int ay = 1;
char cvx;
int potion2x = 0;
int potion2xa=0;
int potion2xan=0;
int healthelixir = 0;
int speedpotion = 0;
int speedpotiona=0;
int bagslot1 = 0;
int bagslot2 = 0;
int bagslot3 = 0;
string openBagArray[34][9];
int wfl2=0;
int willweRun=0;
int playerExp = 1;
void gainExp();
char fromthe;
int abilityUsed=0;
int aOfChoice=0;
int doorUnlocked=0;
int foundNancei=0;
string nameChar = "\033[0;32mCharacter\033[0m";
void openedDoor();
void miniGameLoop();
int isitd=0;
int isitw=0;
char mgc;
string myMiniGameArray[34][102];
int positiontemp=12;
char lastcharor;
int samecharor=0;
int jumpphase = 0;
int renderBottom = 0;
int makeagap = 0;
int gapphase = 0;
char c;
int jumpphase2=0;
void miniGameJump();
void miniGameDeath();
void miniGameDeath2();
int deathfactor = 0;
int firestage=0;
int lastenemy=0;
int renderEnemy=0;
int miniGameStep = 0;
void finishedMiniGame();
int passphase=0;

//ifok2
string ifOK2(string strOK2) {
 while(strOK2 != "ok") {
  cout << "\nType ok to continue...\n";
  cin >> strOK2;
  string ifOK2(strOK2);
 }
whenMove(strOK2);
 return strOK2;
}

///// moving character /////
string whenMove(string whichWay) {

      std::system("clear");
      printTheLevel();

  enableRawMode2();
//  char c;

    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {
      switch(c){

///* case a = left *///

        case 'a':

    if(myPlayArea[charX][charY-1]==" "){
      myPlayArea[35][0]=" ";
      myPlayArea[charX][charY]=" ";
      charY--;
      myPlayArea[charX][charY]="¤";
      std::system("clear");
      printTheLevel();
      break;
    }
    if(myPlayArea[charX][charY-1]=="═"){
      myPlayArea[35][0]=" That's a wall! Ouch.  ||  ";
    //myPlayArea[35][0]=" ";
      std::system("clear");
      printTheLevel();
      break;
    }
    if(myPlayArea[charX][charY-1]=="N"){
      whichWay="z";
      c='q';
      itsNancei();
      break;
    }
    if(myPlayArea[charX][charY-1]=="Ø"){
      c='q';
      aBush();
      break;
    }
    if(myPlayArea[charX][charY-1]=="‡"){
      c='q';
      aWeapon();
//gainExp();
      break;
    }
    if(myPlayArea[charX][charY-1]=="░"){
      c='q';
fromthe='l';
/*
      myPlayArea[charX][charY]=" ";
      charY--;
      myPlayArea[charX][charY]="¤";
*/
      std::system("clear");
      aBattle();
      break;
    }
    if(myPlayArea[charX][charY-1]=="§"){
      c='q';
//      aPotion();
anAbility();
      break;
    }
    if(myPlayArea[charX][charY-1]=="×"){
      c='q';
      aPotion();
      break;
    }
    if(myPlayArea[charX][charY-1]=="="){
      c='q';
      doorUnlocked=1;
      myPlayArea[35][0]=" You've found a key!  ||  ";
      std::system("clear");
      printTheLevel();
    }
    if(myPlayArea[charX][charY-1]=="█"){
      myPlayArea[charX][charY]=" ";
      charY--;
      myPlayArea[charX][charY]="¤";
      openedDoor();
      break;
    }

/*
2 ░ is level1fiend [0-2]
3 ▒ is level2fiend [0-2] only if char is lvl..
4 ▓ is bossfight [0-2] only if char is lvl..
*/


continue;

////////////////////////
///* case d = right *///

        case 'd':
    if(myPlayArea[charX][charY+1]==" "){
      myPlayArea[35][0]=" ";
      myPlayArea[charX][charY]=" ";
      charY++;
      myPlayArea[charX][charY]="¤";
      std::system("clear");
      printTheLevel();
break;
    }
    if(myPlayArea[charX][charY+1]=="═"){
      myPlayArea[35][0]=" That's a wall! Ouch.  ||  ";
      std::system("clear");
      printTheLevel();
break;
    }
    if(myPlayArea[charX][charY+1]=="N"){
whichWay="z";
c='q';
      itsNancei();
break;
    }
    if(myPlayArea[charX][charY+1]=="Ø"){
      c='q';
      aBush();
      break;
    }
    if(myPlayArea[charX][charY+1]=="‡"){
      c='q';
      aWeapon();
      break;
    }
    if(myPlayArea[charX][charY+1]=="░"){
      c='q';
fromthe='d';
      aBattle();
      break;
    }
    if(myPlayArea[charX][charY+1]=="§"){
      c='q';
      anAbility();
      break;
    }
    if(myPlayArea[charX][charY+1]=="×"){
      c='q';
      aPotion();
      break;
    }
    if(myPlayArea[charX][charY+1]=="="){
      c='q';
      doorUnlocked=1;
      myPlayArea[35][0]=" You've found a key!  ||  ";
      std::system("clear");
      printTheLevel();
    }



          continue;

/////////////////////
///* case w = up *///

        case 'w':
    if(myPlayArea[charX-1][charY]==" "){
      myPlayArea[35][0]=" ";
      myPlayArea[charX][charY]=" ";
      charX--;
      myPlayArea[charX][charY]="¤";
      std::system("clear");
      printTheLevel();
break;
    }
    if(myPlayArea[charX-1][charY]=="═"){
      myPlayArea[35][0]=" That's a wall! Ouch.  ||  ";
      std::system("clear");
      printTheLevel();
break;
    }
    if(myPlayArea[charX-1][charY]=="N"){
whichWay="z";
c='q';
      itsNancei();
break;
    }
    if(myPlayArea[charX-1][charY]=="Ø"){
      c='q';
      aBush();
      break;
    }
    if(myPlayArea[charX-1][charY]=="‡"){
      c='q';
      aWeapon();
      break;
    }
    if(myPlayArea[charX-1][charY]=="░"){
      c='q';
fromthe='w';
      aBattle();
      break;
    }
    if(myPlayArea[charX-1][charY]=="§"){
      c='q';
      anAbility();
      break;
    }
    if(myPlayArea[charX-1][charY]=="×"){
      c='q';
      aPotion();
      break;
    }
    if(myPlayArea[charX-1][charY]=="="){
      c='q';
      doorUnlocked=1;
      myPlayArea[35][0]=" You've found a key!  ||  ";
      std::system("clear");
      printTheLevel();
    }



continue;

///////////////////////
///* case s = down *///

        case 's':
    if(myPlayArea[charX+1][charY]==" "){
      myPlayArea[35][0]=" ";
      myPlayArea[charX][charY]=" ";
      charX++;
      myPlayArea[charX][charY]="¤";
      std::system("clear");
      printTheLevel();
break;
    }
    if(myPlayArea[charX+1][charY]=="═"){
      myPlayArea[35][0]=" That's a wall! Ouch.  ||  ";
      std::system("clear");
      printTheLevel();
break;
    }
    if(myPlayArea[charX+1][charY]=="N"){
whichWay="z";
c='q';
      itsNancei();
break;
    }
    if(myPlayArea[charX+1][charY]=="Ø"){
      c='q';
      aBush();
      break;
    }
    if(myPlayArea[charX+1][charY]=="‡"){
      c='q';
      aWeapon();
      break;
    }
    if(myPlayArea[charX+1][charY]=="░"){
      c='q';
fromthe='s';
      aBattle();
      break;
    }
    if(myPlayArea[charX+1][charY]=="§"){
      c='q';
      anAbility();
      break;
    }
    if(myPlayArea[charX+1][charY]=="×"){
      c='q';
      aPotion();
      break;
    }
    if(myPlayArea[charX+1][charY]=="="){
      c='q';
      doorUnlocked=1;
      myPlayArea[35][0]=" You've found a key!  ||  ";
      std::system("clear");
      printTheLevel();
    }



continue;

/////////////////////////////
///* finally the default *///

        default:
     //     cout << c << endl;
          continue;
      }
continue;
    }

return whichWay;
}
///// end moving character /////

};
void My_class::aWeapon(){
  std::system("clear");
  int cUpgrade;

  std::random_device rd;
  std::mt19937 e{rd()};
  std::uniform_int_distribution<int> dist{0, 6};
  int randoWeapon = dist(e);
  switch(randoWeapon){
    case 0:
    //a basic dagger
      // if we have not obtained this weapon yet
      switch(nDaggers){
        case 0:

std::system("clear");
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::║\n";
cout << "║:::::::::::::::::::::::::..::::::::..................:::::::::::::::::::::::::::::::::::::::::::::::║\n";
cout << "║:::::::::::::::::::::::....:::::::.....................:::::::::::::::::::::::::::::::::::::::::::::║\n";
cout << "║::::::::::::::::::::::.....................................................:::::::::::::::::::::::::║\n";
cout << "║::::::::::::::::::..................................................................::::::::::::::::║\n";
cout << "║::::::::::::::...........................................................................:::::::::::║\n";
cout << "║::::::::::::::..............................................................................::::::::║\n";
cout << "║:::::::::::::......................................................................::^!77~:.....::::║\n";
cout << "║:::::::::::..................................................................:^~!?YPGB#BBBG~.....:::║\n";
cout << "║::::::::::......................................................::......:~!?YPGBBGGGGBGPGB#5....::..║\n";
cout << "║:::::::::.....................................................^YPP5!~7Y5PGGGBBBBBBBBBBGGBBG~:.......║\n";
cout << "║:::::::..............................................:^!7?JJYJJ##BBBGGGGPP5PGB#BBBBBBG5Y?!::::.:....║\n";
cout << "║::::..........................................:^~7?YPG#BP5555JY#&BBGGPGGGPPGBBG5YJ77!~^::::::::.....║\n";
cout << "║::......................................:^!?J5BGGGPPGG5PP55JJYG##BGGGP5P5YJ?7~^^::::::::::::::......║\n";
cout << "║..................................:^!7JY5PGGG55PPPPPYJYYYY5PPPPG#BGGGJ~^::::::::::::::..............║\n";
cout << "║.............................:^7?5PPPPPPPPPGBPP5YJYYJY55PPPYJ?!~7?--!:::::::........................║\n";
cout << "║........................^!7Y5PPGGBBPGGGGGPPP5YY5Y5PPP5J7!^^:........................................║\n";
cout << "║...................:^!JP##BGGGPPG##BGBGP5Y5P55JJJ7!~::..............................................║\n";
cout << "║...............:~7J5PY5GPPGGGGGPPPGP555YJJ7!~::.....................................................║\n";
cout << "║............^J5GGGGGGGGGGGPGPPP5J??7~^^:............................................................║\n";
cout << "║........:~JPG#BGGGGG5555YJ?7!~^::...................................................................║\n";
cout << "║.......:^????JJ?77!~~^^::...........................................................................║\n";
cout << "║......:::::::::.....................................................................................║\n";
cout << "║....................................................................................................║\n";
cout << "║....................................................................................................║\n";
cout << "║....................................................................................................║\n";
cout << "║....................................................................................................║\n";
cout << "║....................................................................................................║\n";
cout << "║....................................................................................................║\n";
cout << "║....................................You've stumbled on a dagger!....................................║\n";
cout << "║....................................................................................................║\n";
cout << "║....................................................................................................║\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
          
          cout << " ... Press Enter To Continue ... ";
          getchar();
          std::system("clear");



cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                          ==============                                            ║\n";
cout << "║                                         || The Dagger ||                                           ║\n";
cout << "║                                          ==============                                            ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  This old, wooden dagger is pointy enough to leave a good splinter.                                ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  Damage: 1                                                                                         ║\n";
cout << "║  Speed: 1                                                                                          ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                      ^^^^^^^^^^^^^^::^^^^^^^^^^^^^^^^^^^^^^^^~~~~~~~!!!!7777                       ║\n";
cout << "║                      ^^^^^^^^^^^^::::::::^:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^~~~                       ║\n";
cout << "║                      ^^^^^^^:::::::::::::::::::::::::::::::::::::::^^^^^^^^^                       ║\n";
cout << "║                      ^^^^^::::::::::::::::::::::::::::::::::::::::::::::::^^                       ║\n";
cout << "║                      ^^::::::::::::::::::::::::::::::::::::::::::::^^~~:::::                       ║\n";
cout << "║                      :::::::::::::::::::::::::::::::::::::::::^!7JYPGGGY::::                       ║\n";
cout << "║                      :::::::::::::::::::::::::::::::^^~!55??Y5PGBBBBGPP?^:::                       ║\n";
cout << "║                      ::::::::::::::::::::::::^~!7J5P55Y5#BGGGPPGPYJ?7~^:::::                       ║\n";
cout << "║                      ::::::::::::::::::^~!7J5PPPPP55555PBGGY7!~~^^::::::::::                       ║\n";
cout << "║                      :::::::::::::^~7J5PPGGPPP5555YJ?7!~~!~^::::::::::::::::                       ║\n";
cout << "║                      :::::::::^!?5GGGGGBGGP5YJ77!~^:::::::::::::::::::::::::                       ║\n";
cout << "║                      :::::~75PGGPGPP5YJ7!~^^::::::::::::::::::::::::::::::::                       ║\n";
cout << "║                      ::::!JYYJ?7!~~^::::::::::::::::::::::::::::::::::::::::                       ║\n";
cout << "║                      :::::::::::::::::::::::::::::::::::::::::::::::::::::::                       ║\n";
cout << "║                      :::::::::::::::::::::::::::::::::::::::::::::::::::::::                       ║\n";
cout << "║                      :::::::::::::::::::::::::::::::::::::::::::::::::::::::                       ║\n";
cout << "║                      :::::::::::::::::::::::::::::::::::::::::::::::::::::::                       ║\n";
cout << "║                      :::::::::::::::::::::::::::::::::::::::::::::::::::::::                       ║\n";
cout << "║                      ::::::::::::::::::::::::::::::::::::::::::^:^^^^^^^^^^^                       ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
wNew="dagger 🗡️  ";
wNews="dagger";
wNewAttack=1;
wNewSpeed=1;
if(nWeapons==0){
  wOne="dagger 🗡️     ";
  wOnes="dagger";
  wOneAttack=1;
  wOneSpeed=1;
}
if(nWeapons==1){
  wTwo="dagger 🗡️     ";
  wTwos="dagger";
  wTwoAttack=1;
  wTwoSpeed=1;
}
if(nWeapons==2){
  wThree="dagger 🗡️     ";
  wThrees="dagger";
  wThreeAttack=1;
  wThreeSpeed=1;
}


          cout << " ... Press Enter To Continue ... ";
          getchar();
          std::system("clear");

          if(nWeapons>2){
            nDaggers++;
            swapWeapons();
            break;
          }
            nDaggers++;
            nWeapons++;
            tempvar2="ok";
            ifOK2(tempvar2);
            break;

        case 1:

          cUpgrade = dist(e);
          if(cUpgrade>3){

          std::system("clear");

cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                          ==============                                            ║\n";
cout << "║                                         || The Dagger ||                                           ║\n";
cout << "║                                          ==============                                            ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  You decide to carve some ridges in the blade, and reinforce the handle.                           ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  Damage: 1 +1 = 2                                                                                  ║\n";
cout << "║  Speed: 1                                                                                          ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                            !J7!~.                                  ║\n";
cout << "║                                                         .7GBGBBB5~                                 ║\n";
cout << "║                                                       ^5B#&&BJ~.                                   ║\n";
cout << "║                                                     ~PB#&#5~                                       ║\n";
cout << "║                                                   .Y##&#5.                                         ║\n";
cout << "║                                              .7J5?J5P#!.                                           ║\n";
cout << "║                                             .7JJYY5Y?                                              ║\n";
cout << "║                                           .7Y?7^~~^~?.                                             ║\n";
cout << "║                                          ^YY7!^    ^!7                                             ║\n";
cout << "║                                        ^!!77~..                                                    ║\n";
cout << "║                                      ^~:~!!?J~.                                                    ║\n";
cout << "║                                     !~::~?^.                                                       ║\n";
cout << "║                                   .!~.:^~~                                                         ║\n";
cout << "║                                  :?7^!^.                                                           ║\n";
cout << "║                               ...!J?^:                                                             ║\n";
cout << "║                              :7!?JJ!                                                               ║\n";
cout << "║                             :J~!Y^                                                                 ║\n";
cout << "║                            ^?7~.                                                                   ║\n";
cout << "║                           :7:                                                                      ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

if(wOne=="dagger 🗡️     "){wOneAttack=2;wOneSpeed=1;}
if(wTwo=="dagger 🗡️     "){wTwoAttack=2;wTwoSpeed=1;}
if(wThree=="dagger 🗡️     "){wThreeAttack=2;wThreeSpeed=1;}

          nDaggers++;
          cout << " ... Press Enter To Continue ... ";
          getchar();
          std::system("clear");
          tempvar2="ok";
          ifOK2(tempvar2);
          }
          else
          {
          aWeapon(); //try again
          }
          break;


        case 2:
          aWeapon(); //try again
          break;


        default:
          cout << "error code 001\n"; // should never come up
      } //end switch of Daggers
break;
    case 1:
    //a basic sword
      // if we have not obtained this weapon yet
      switch(nSwords){
        case 0:
          std::system("clear");

cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::║\n";
cout << "║:::::::::::::::::::::::::..::::::::..................:::::::::::::::::::::::::::::::::::::::::::::::║\n";
cout << "║:::::::::::::::::::::::....:::::::.....................:::::::::::::::::::::::::::::::::::::::::::::║\n";
cout << "║::::::::::::::::::::::.....................................................:::::::::::::::::::::::::║\n";
cout << "║::::::::::::::::::..................................................................::::::::::::::::║\n";
cout << "║::::::::::::::...........................................................................:::::::::::║\n";
cout << "║::::::::::::::..............................................................................::::::::║\n";
cout << "║::::::::::::::.............................................                                         ║\n";
cout << "║::::::::::::::....................                                         :^                       ║\n";
cout << "║::::::::::::::...............                                               !:                 ..   ║\n";
cout << "║::::::::::::::.............                                                  7            .:^:~5G5. ║\n";
cout << "║::::::::::::::..........                                                     .7  .:~7J5G#&&&5JPGP~  ║\n";
cout << "║:::::::::::::.......                                                    ..:~7?J5G&&&&#G57^.         ║\n";
cout << "║:::::::::::.....                                                  .:^~!7?JJJYJ?GJ7~.                ║\n";
cout << "║:::::::::...                                              ..:^~!!777?7777!!~^:.~7                   ║\n";
cout << "║:::::::                                           ..:^~!!!!!!!~~~~^^:..         ?                   ║\n";
cout << "║::::                                      ..:^~!7??77!!~~^::..                  .~                  ║\n";
cout << "║:                                  ..:^!7?????7!!~^:..                           !                  ║\n";
cout << "║                            ..:~!7??J??7!~^:..                                                      ║\n";
cout << "║                     ..:~!77?77!~~^:..                                                              ║\n";
cout << "║              .:^^~77777!^:..                                   ....................................║\n";
cout << "║       .:^~!777!~^::.                                       ........................................║\n";
cout << "║   .^~~~^^:..                                           ............................................║\n";
cout << "║                                                    ................................................║\n";
cout << "║....................................................................................................║\n";
cout << "║....................................................................................................║\n";
cout << "║....................................................................................................║\n";
cout << "║....................................................................................................║\n";
cout << "║....................................................................................................║\n";
cout << "║....................................You've stumbled on a sword!.....................................║\n";
cout << "║....................................................................................................║\n";
cout << "║....................................................................................................║\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

        
        cout << " ... Press Enter To Continue ... ";
        getchar();
        std::system("clear");

cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                          ==============                                            ║\n";
cout << "║                                         || The Sword  ||                                           ║\n";
cout << "║                                          ==============                                            ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  This sharp steel is sure to inflict some pain.  There is some leftover blood painted on           ║\n";
cout << "║    the blade.                                                                                      ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  Damage: 2                                                                                         ║\n";
cout << "║  Speed: 2                                                                                          ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "║             *-----------------------------------------------------------------------*              ║\n";
cout << "║             |                                                                       |              ║\n";
cout << "║             |                                                  .                    |              ║\n";
cout << "║             |                                                   :          .:       |              ║\n";
cout << "║             |                                                    ~ .^~7J5Y75Y       |              ║\n";
cout << "║             |                                              ..:~7?J5P5?!:.           |              ║\n";
cout << "║             |                                       ..:^~!!!!~~^:.!                 |              ║\n";
cout << "║             |                               .::~!!!~~^:...         :                |              ║\n";
cout << "║             |                        .:^~!!!~~^:.                  .                |              ║\n";
cout << "║             |                ..:^~~~~^:..                                           |              ║\n";
cout << "║             |          .:^^^^::..                                                   |              ║\n";
cout << "║             |        ....                                                           |              ║\n";
cout << "║             |                                                                       |              ║\n";
cout << "║             |                                                                       |              ║\n";
cout << "║             *-----------------------------------------------------------------------*              ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
wNew="sword †   ";
wNews="sword ";
wNewAttack=2;
wNewSpeed=2;
if(nWeapons==0){
  wOne="sword †      ";
  wOnes="sword ";
  wOneAttack=2;
  wOneSpeed=2;
}
if(nWeapons==1){
  wTwo="sword †      ";
  wTwos="sword ";
  wTwoAttack=2;
  wTwoSpeed=2;
}
if(nWeapons==2){
  wThree="sword †      ";
  wThrees="sword ";
  wThreeAttack=2;
  wThreeSpeed=2;
}



          cout << " ... Press Enter To Continue ... ";
          getchar();
          std::system("clear");

          if(nWeapons>2){
            nSwords++;
            swapWeapons();
            break;
          }
            nSwords++;
            nWeapons++;
            tempvar2="ok";
            ifOK2(tempvar2);
            break;

        case 1:

          cUpgrade = dist(e);
          if(cUpgrade>3){

          std::system("clear");
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                          ==============                                            ║\n";
cout << "║                                         || The Sword  ||                                           ║\n";
cout << "║                                          ==============                                            ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  You've switched out your sword's blade for one that is twice as thick, and three times sturdy.    ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  Damage: 2 +1 = 3                                                                                  ║\n";
cout << "║  Speed: 2                                                                                          ║\n";
cout << "║                            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B57#                           ║\n";
cout << "║                            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#G5J!~^:.!@                           ║\n";
cout << "║                            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@G7~~^^^::..&@                           ║\n";
cout << "║                            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B?~~~^^::.. J@@                           ║\n";
cout << "║                            @@@@@@@@@@@@@@@@@@@@@@@@@@@@&J!~~^^::..  :@@@                           ║\n";
cout << "║                            @@@@@@@@@@@@@@@@@@@@@@@@@@&5!!~~^:...  .!&@@@                           ║\n";
cout << "║                            @@@@@@@@@@@@@@@@@@@@@@@@@P7!!~^...   ^5&@@@@@                           ║\n";
cout << "║                            @@@@@@@@@@@@@@@@@@@@@@@B?!!~:...  .7#@@@@@@@@                           ║\n";
cout << "║                            @@@@@@@@@@@@@@@@@@@@@#J!!~:..   ^P@@@@@@@@@@@                           ║\n";
cout << "║                            @@@@@@@@@@@@@@@@@@@&57!~:..  .J&@@@@@@@@@@@@@                           ║\n";
cout << "║                            @@@@@@@@@@@@@@@@@@P7!~:.  .~G@@@@@@@@@@@@@@@@                           ║\n";
cout << "║                            @@@@@@@@@@@@@@@@B?!~:.  :Y&@@@@@@@@@@@@@@@@@@                           ║\n";
cout << "║                            @@@@@@BY&@@@@@#J!^:. .!B@@@@@@@@@@@@@@@@@@@@@                           ║\n";
cout << "║                            @@@@@@@5~?&@&Y!^:. ^5&@@@@@@@@@@@@@@@@@@@@@@@                           ║\n";
cout << "║                            @@@@@@@@@G~7~^:..7#@@@@@@@@@@@@@@@@@@@@@@@@@@                           ║\n";
cout << "║                            @@@@@@@@&57:^:.5@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                           ║\n";
cout << "║                            @@@@@@#Y!:  JBJ7B@@@@@@@@@@@@@@@@@@@@@@@@@@@@                           ║\n";
cout << "║                            @@@@BJ~: .!#@@@&J7B@@@@@@@@@@@@@@@@@@@@@@@@@@                           ║\n";
cout << "║                            @@BJ~: .7&@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@                           ║\n";
cout << "║                            @#!:.:J&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                           ║\n";
cout << "║                            @@&PG&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                           ║\n";
cout << "║                                                                                                    ║\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

if(wOne=="sword †      "){wOneAttack=3;wOneSpeed=2;}
if(wTwo=="sword †      "){wTwoAttack=3;wTwoSpeed=2;}
if(wThree=="sword †      "){wThreeAttack=3;wThreeSpeed=2;}


          nSwords++;
          cout << " ... Press Enter To Continue ... ";
          getchar();
          std::system("clear");
          tempvar2="ok";
          ifOK2(tempvar2);
          }
          else
          {
          aWeapon(); //try again
          }
          break;


        case 2:
          aWeapon(); //try again
          break;


        default:
          cout << "error code 002\n"; //a case within a case
          break;
      } // end sword switch

break;
    case 2:
    //a throwing star
      // if we have not obtained this weapon yet
      switch(nStars){
        case 0:
          std::system("clear");

cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                  .:                                                ║\n";
cout << "║                                                 ..^.                                               ║\n";
cout << "║                                                 :. ^                                               ║\n";
cout << "║                                                ::. .^                                              ║\n";
cout << "║                                               .::.  :.                                             ║\n";
cout << "║                                               ::..   ^                                             ║\n";
cout << "║                                              ::....  .^                                            ║\n";
cout << "║                                             .::.....  ::                                           ║\n";
cout << "║                                             .:......  :.                                           ║\n";
cout << "║                                               .......~                                             ║\n";
cout << "║                                               .......~                                             ║\n";
cout << "║                    .:^^:............^.        ........:        ..................                  ║\n";
cout << "║                      .^!77~:...........     .............    ..........     ..                     ║\n";
cout << "║                         .^!?7~:.....................................     ..                        ║\n";
cout << "║                            .^!?7~:.............:.    ............     ..                           ║\n";
cout << "║                               .^~~:    .......^.     .........      .                              ║\n";
cout << "║                                          ......:     ......^                                       ║\n";
cout << "║                                          ......... .......~.                                       ║\n";
cout << "║                                          .................^.                                       ║\n";
cout << "║                                         ..........  .......:.                                      ║\n";
cout << "║                                    .^^.......::       .......   :                                  ║\n";
cout << "║                                    ~~^......::         ......   ::                                 ║\n";
cout << "║                                   :~^.....  ::         7~:. ..   ^                                 ║\n";
cout << "║                                  .~~...    ...         ^?J7~..   .^                                ║\n";
cout << "║                                  ~~^    ...              .~??7^.  :.                               ║\n";
cout << "║                                 :~:   ..                    :!??~  ^                               ║\n";
cout << "║                                .^. ..                          :!7..^                              ║\n";
cout << "║                                :..                               .^:^.                             ║\n";
cout << "║                                                                                                    ║\n";
cout << "║.................................You've stumbled on a throwing star!................................║\n";
cout << "║....................................................................................................║\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

        
        cout << " ... Press Enter To Continue ... ";
        getchar();
        std::system("clear");

cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                           ============                                             ║\n";
cout << "║                                          || The Star ||                                            ║\n";
cout << "║                                           ============                                             ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  This sharp ninja star is fast, prooving difficult to block or dodge.                              ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  Damage: 2                                                                                         ║\n";
cout << "║  Speed: 4                                                                                          ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                .:                                                  ║\n";
cout << "║                                               : ..                                                 ║\n";
cout << "║                                              .:  :                                                 ║\n";
cout << "║                                             .:..  :                                                ║\n";
cout << "║                                             ::..  ..                                               ║\n";
cout << "║                                             :.... ..                                               ║\n";
cout << "║                                              .....:                                                ║\n";
cout << "║                           ....   ......      .....:      ........                                  ║\n";
cout << "║                            .~!!^........    .........   .......   .                                ║\n";
cout << "║                               :~!~:............  ..........                                        ║\n";
cout << "║                                  :~!:   .....^    .......                                          ║\n";
cout << "║                                          ....:    ....:                                            ║\n";
cout << "║                                           ...........:.                                            ║\n";
cout << "║                                          ......  .....:                                            ║\n";
cout << "║                                      :^.....:.      .... ..                                        ║\n";
cout << "║                                     .~^... .:      ::. .  :                                        ║\n";
cout << "║                                     ^~.    ..      :77^..  :                                       ║\n";
cout << "║                                    :~.  ..           .~7!: ..                                      ║\n";
cout << "║                                    ^. .                 :!~.:                                      ║\n";
cout << "║                                   ..                       ::.                                     ║\n";
cout << "║                   The center of the star is said to hold the souls it has taken.                   ║\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
wNew="star ★    ";
wNews="star  ";
wNewAttack=2;
wNewSpeed=4;
if(nWeapons==0){
  wOne="star ★       ";
  wOnes="star  ";
  wOneAttack=2;
  wOneSpeed=4;
}
if(nWeapons==1){
  wTwo="star ★       ";
  wTwos="star  ";
  wTwoAttack=2;
  wTwoSpeed=4;
}
if(nWeapons==2){
  wThree="star ★       ";
  wThrees="star  ";
  wThreeAttack=2;
  wThreeSpeed=4;
}
          cout << " ... Press Enter To Continue ... ";
          getchar();
          std::system("clear");

          if(nWeapons>2){
            nStars++;
            swapWeapons();
            break;
          }
            nStars++;
            nWeapons++;
            tempvar2="ok";
            ifOK2(tempvar2);
            break;

        case 1:
          aWeapon(); //try again
          break;
        default:
          cout << "error code 003\n"; //a case within a case
          break;
      } // end star switch

break;
    case 3:
    //a flail
      // if we have not obtained this weapon yet
      switch(nFlails){
        case 0:
          std::system("clear");


cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║                                                                                                    ║\n";
cout << "║                                            .PJY?~~                                                 ║\n";
cout << "║                                            .5JYP#&BJ.             ..       .                       ║\n";
cout << "║                                            ~P5PB&&5~^             :G55PP5JY.                       ║\n";
cout << "║                                            ~B5G&&5:  .: .       .:?GBG5G#&&7                       ║\n";
cout << "║                                           .JGP#@5 ^.    ...^. :. ~B##P?G&@@B^                      ║\n";
cout << "║                                           .GBB&#. .:             :^JB&&@@&G!!~                     ║\n";
cout << "║                                           ^P5&G:   ..               .?&5!:                         ║\n";
cout << "║                                          .5PBG.    .:                .^                            ║\n";
cout << "║                                          J5G#^       ^.                                            ║\n";
cout << "║                                         !5PB?         .^                                           ║\n";
cout << "║                                        ~PGBG            .^.                                        ║\n";
cout << "║                                       :GGB&^             .5J!!~:..                                 ║\n";
cout << "║                                       YGG#?             .YBBB##&B^                                 ║\n";
cout << "║                                      7GPB5              ?#BYJG&@&5                                 ║\n";
cout << "║                                     :P5GG.             .?B#BB&@@&7                                 ║\n";
cout << "║                                    .Y5GB~                !#GBBB5Y?.                                ║\n";
cout << "║                                   .J5P#J                 .. ~~   ..                                ║\n";
cout << "║                                   7PJ#G.                                                           ║\n";
cout << "║                                  .5PBG.                                                            ║\n";
cout << "║                                 .5PG#~                                                             ║\n";
cout << "║                                .YY5GG.                                                             ║\n";
cout << "║                                YY?GB!                                                              ║\n";
cout << "║                               ^P^G&J                                                               ║\n";
cout << "║                               5PP&Y                                                                ║\n";
cout << "║                             .Y5P#P                                                                 ║\n";
cout << "║                             ~GP#B?                                                                 ║\n";
cout << "║                             JPB#~                                                                  ║\n";
cout << "║                           ~BB#BJ                                                                   ║\n";
cout << "║                            ^5BP~                                                                   ║\n";
cout << "║.....................................You've stumbled on a flail!....................................║\n";
cout << "║....................................................................................................║\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

        
        cout << " ... Press Enter To Continue ... ";
        getchar();
        std::system("clear");

cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                           =============                                            ║\n";
cout << "║                                          || The Flail ||                                           ║\n";
cout << "║                                           =============                                            ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  This two-ball flail can shred through thick defenses.                                             ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  Damage: 4                                                                                         ║\n";
cout << "║  Speed: 1                                                                                          ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                           7YJJ!.                                                   ║\n";
cout << "║                                           Y5B&P^        .?7??7:                                    ║\n";
cout << "║                                          .5P&P:  .. . ..7#B5&@P                                    ║\n";
cout << "║                                          ^G#B ..        ^JB&&#7^                                   ║\n";
cout << "║                                          ?GP   .          .?.                                      ║\n";
cout << "║                                         ~PG.    .                                                  ║\n";
cout << "║                                        ^PB~      ...                                               ║\n";
cout << "║                                       .PB5         JYJ?~                                           ║\n";
cout << "║                                       YGG.        ?#PB@&:                                          ║\n";
cout << "║                                      ~PB^         ~BB#&B:                                          ║\n";
cout << "║                                     ^5B?           ::~. .                                          ║\n";
cout << "║                                     YG5                                                            ║\n";
cout << "║                                    JGB.                                                            ║\n";
cout << "║                                   ?YB?                                                             ║\n";
cout << "║                                  ^YGP                                                              ║\n";
cout << "║                                 .5BB                                                               ║\n";
cout << "║                                 ?GB^                                                               ║\n";
cout << "║                                ?5B!                                                                ║\n";
cout << "║                                ~GB^                                                                ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                      The flail shows no mercy to those who stand in it's way.                      ║\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
wNew="flail /⍣  ";
wNews="flail ";
wNewAttack=4;
wNewSpeed=1;
if(nWeapons==0){
  wOne="flail /⍣     ";
  wOnes="flail ";
  wOneAttack=4;
  wOneSpeed=1;
}
if(nWeapons==1){
  wTwo="flail /⍣     ";
  wTwos="flail ";
  wTwoAttack=4;
  wTwoSpeed=1;
}
if(nWeapons==2){
  wThree="flail /⍣     ";
  wThrees="flail ";
  wThreeAttack=4;
  wThreeSpeed=1;
}

          cout << " ... Press Enter To Continue ... ";
          getchar();
          std::system("clear");

          if(nWeapons>2){
nFlails++;
            swapWeapons();
            break;
          }
            nFlails++;
            nWeapons++;
            tempvar2="ok";
            ifOK2(tempvar2);
            break;

        case 1:
          aWeapon(); //try again
          break;
        default:
          cout << "error code 004\n"; //a case within a case
          break;
      } // end flail switch

break;
    case 4:
    //a hammer
      // if we have not obtained this weapon yet
      switch(nHammers){
        case 0:
          std::system("clear");

cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                               ?5Y5~:                               ║\n";
cout << "║                                                             ^!7PP!!?7:    .::                      ║\n";
cout << "║                                                             :P#5:.7PB&J.J&&&&^                     ║\n";
cout << "║                                                           ~?B#J?~5@@&&@&##&&P                      ║\n";
cout << "║                                                         ^:^BG^:J&@@&&&@&##BJ                       ║\n";
cout << "║                                                          .5B5JB@@@&&&&&&#&&&#!:                    ║\n";
cout << "║                                                           .JB&@&&#&@&&&@@&&&B&&Y                   ║\n";
cout << "║                                                              7B#&@&&&@@@&#BGPGBG7                  ║\n";
cout << "║                                                             7PG&#&&&&#PPBBGB#P!JP                  ║\n";
cout << "║                                                          !Y#55GJ.^P5GYJY#&G~Y5                     ║\n";
cout << "║                                                        :5#B#&Y.    :JP#G^?Y                        ║\n";
cout << "║                                                      ~P####P~        .~J                           ║\n";
cout << "║                                                    ~P#&##J.                                        ║\n";
cout << "║                                                 .!GBG##J:                                          ║\n";
cout << "║                                                ^B&##&J.                                            ║\n";
cout << "║                                              ^5PP&#Y.                                              ║\n";
cout << "║                                            ~PGG#G~                                                 ║\n";
cout << "║                                          !PPPBP^                                                   ║\n";
cout << "║                                        !PPPB5:                                                     ║\n";
cout << "║                                      7PPGBY.                                                       ║\n";
cout << "║                                   .7PPPBJ.                                                         ║\n";
cout << "║                                 .?PPGB?.                                                           ║\n";
cout << "║                               .?PPBB7                                                              ║\n";
cout << "║                             .JP5BG!                                                                ║\n";
cout << "║                           :JPPBP^                                                                  ║\n";
cout << "║                         :Y5PBP^                                                                    ║\n";
cout << "║                       JP5YB5:                                                                      ║\n";
cout << "║                     .Y##&#:                                                                        ║\n";
cout << "║                   .YB&P~:.                                                                         ║\n";
cout << "║....................................You've stumbled on a hammer!....................................║\n";
cout << "║....................................................................................................║\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

        
        cout << " ... Press Enter To Continue ... ";
        getchar();
        std::system("clear");

cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                           ==============                                           ║\n";
cout << "║                                          || The Hammer ||                                          ║\n";
cout << "║                                           ==============                                           ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  This large hammer can knock more than a few nails loose.                                          ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  Damage: 3                                                                                         ║\n";
cout << "║  Speed: 2                                                                                          ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                            7P?^.                                   ║\n";
cout << "║                                                           ?G7^5B!~G#?                              ║\n";
cout << "║                                                         .YP!Y&@&@##B.                              ║\n";
cout << "║                                                         :G5G@&&&&&&#Y^                             ║\n";
cout << "║                                                          .J&&&&&&&#BB#?                            ║\n";
cout << "║                                                          :JGG#&#PB#PG~7                            ║\n";
cout << "║                                                        !B&G^  ~YGJ5..                              ║\n";
cout << "║                                                      !B&G!      :.                                 ║\n";
cout << "║                                                   .7G#G~                                           ║\n";
cout << "║                                                  ~G&B~                                             ║\n";
cout << "║                                                ~PBY:                                               ║\n";
cout << "║                                              !PGJ.                                                 ║\n";
cout << "║                                            !PG?.                                                   ║\n";
cout << "║                                         .!GG7.                                                     ║\n";
cout << "║                                       .7PG7.                                                       ║\n";
cout << "║                                     .7GP!                                                          ║\n";
cout << "║                                   ^?PP~                                                            ║\n";
cout << "║                                 .?#G?                                                              ║\n";
cout << "║                               .JBY.                                                                ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                    The handle of this brute smells like sweat mixed with death.                    ║\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
wNew="hammer 🔨 ";
wNews="hammer";
wNewAttack=3;
wNewSpeed=2;
if(nWeapons==0){
  wOne="hammer 🔨    ";
  wOnes="hammer";
  wOneAttack=3;
  wOneSpeed=2;
}
if(nWeapons==1){
  wTwo="hammer 🔨    ";
  wTwos="hammer";
  wTwoAttack=3;
  wTwoSpeed=2;
}
if(nWeapons==2){
  wThree="hammer 🔨    ";
  wThrees="hammer";
  wThreeAttack=3;
  wThreeSpeed=2;
}


          cout << " ... Press Enter To Continue ... ";
          getchar();
          std::system("clear");

          if(nWeapons>2){
            nHammers++;
            swapWeapons();
            break;
          }
            nHammers++;
            nWeapons++;
            tempvar2="ok";
            ifOK2(tempvar2);
            break;

        case 1:
          aWeapon(); //try again
          break;
        default:
          cout << "error code 005\n"; //a case within a case
          break;
      } // end hammer switch

break;
    case 5:
    //a bow and arrow
      // if we have not obtained this weapon yet
      switch(nBows){
        case 0:
          std::system("clear");

cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                :                                                   ║\n";
cout << "║                                                ^~                                                  ║\n";
cout << "║                                               .^~                                                  ║\n";
cout << "║                                             :^:. :.                                                ║\n";
cout << "║                                          .^~:     ..                                               ║\n";
cout << "║                                         ~!:        .:.                                             ║\n";
cout << "║                                       :J^            :.                                            ║\n";
cout << "║                                      :P.              ..                                           ║\n";
cout << "║                                      57                .:.                                         ║\n";
cout << "║                                      5Y                 ...                                        ║\n";
cout << "║                                      JB                   ..                                       ║\n";
cout << "║                                      7&.                   .:                                      ║\n";
cout << "║                                      ?&:                     :.                                    ║\n";
cout << "║                                      P@~                      ..                                   ║\n";
cout << "║                           :!YJ.......5G~...................?GGGBB?.                                ║\n";
cout << "║                                      P@~                      ..                                   ║\n";
cout << "║                                      ?&:                     :.                                    ║\n";
cout << "║                                      7&.                   .:                                      ║\n";
cout << "║                                      ?B                   ..                                       ║\n";
cout << "║                                      5J                 .:.                                        ║\n";
cout << "║                                      P7                .:.                                         ║\n";
cout << "║                                      :P.              ..                                           ║\n";
cout << "║                                       :J^            :.                                            ║\n";
cout << "║                                         ~!:        .:.                                             ║\n";
cout << "║                                          .^~:     ..                                               ║\n";
cout << "║                                             :^:. :.                                                ║\n";
cout << "║                                               .^~                                                  ║\n";
cout << "║                                                ^~                                                  ║\n";
cout << "║                                                :                                                   ║\n";
cout << "║................................You've stumbled on a bow and arrow!.................................║\n";
cout << "║....................................................................................................║\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

        
        cout << " ... Press Enter To Continue ... ";
        getchar();
        std::system("clear");

cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                       ===================                                          ║\n";
cout << "║                                      || The Bow & Arrow ||                                         ║\n";
cout << "║                                       ===================                                          ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  A bow made of the finest oak, with specially crafted bamboo arrows.                               ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  Damage: 2                                                                                         ║\n";
cout << "║  Speed: 3                                                                                          ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                  ^.                                                ║\n";
cout << "║                                                 .^:                                                ║\n";
cout << "║                                               ::.  ..                                              ║\n";
cout << "║                                             ^^.     ..                                             ║\n";
cout << "║                                           .7:        ..                                            ║\n";
cout << "║                                           7!           ..                                          ║\n";
cout << "║                                           7?            ..                                         ║\n";
cout << "║                                           ~P             ..                                        ║\n";
cout << "║                                           !B               .                                       ║\n";
cout << "║                                    :7^....?G.............:JY5?.                                    ║\n";
cout << "║                                           !#               .                                       ║\n";
cout << "║                                           ~P             ..                                        ║\n";
cout << "║                                           77            ..                                         ║\n";
cout << "║                                           7!          ...                                          ║\n";
cout << "║                                           .7:        ..                                            ║\n";
cout << "║                                             ^^.     ..                                             ║\n";
cout << "║                                               ::.  ..                                              ║\n";
cout << "║                                                 .^:                                                ║\n";
cout << "║                                                  ^.                                                ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                  Close one eye and pluck with might.                               ║\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
wNew="bow 🏹    ";
wNews="bow   ";
wNewAttack=2;
wNewSpeed=3;
if(nWeapons==0){
  wOne="bow 🏹       ";
  wOnes="bow   ";
  wOneAttack=2;
  wOneSpeed=3;
}
if(nWeapons==1){
  wTwo="bow 🏹       ";
  wTwos="bow   ";
  wTwoAttack=2;
  wTwoSpeed=3;
}
if(nWeapons==2){
  wThree="bow 🏹       ";
  wThrees="bow   ";
  wThreeAttack=2;
  wThreeSpeed=3;
}

          cout << " ... Press Enter To Continue ... ";
          getchar();
          std::system("clear");

          if(nWeapons>2){
            nBows++;
            swapWeapons();
            break;
          }
            nBows++;
            nWeapons++;
            tempvar2="ok";
            ifOK2(tempvar2);
            break;

        case 1:
          aWeapon(); //try again
          break;
        default:
          cout << "error code 006\n"; //a case within a case
          break;
      } // end bow switch

break;
  case 6:
    if (nSwords>1&&nHammers>0&&nStars>0&&nBows>0&&nFlails>0&&nDaggers>1){
      cout << "all is fin.\n";
          cout << " ... Press Enter To Continue ... ";
          getchar();
          std::system("clear");
          tempvar2="ok";
          ifOK2(tempvar2);
      }
      else
      {
        aWeapon();
      }
    break;

  } // end rando weapon switch


} //end void


void My_class::swapWeapons(){
  std::system("clear");
  for(int i=0;i<34;i++){
    for(int r=0;r<102;r++){
      swapArray[i][r] = myPlayArea[i][r];
    }
  }

  for(int k=7;k<27;k++){
    for(int l=9;l<94;l++){
      swapArray[k][l]="\0";
    }
  }

int swapOptions = 1;

swapArray[7][9]="════════════════════════════════════════════════════════════════════════════════════ ";
swapArray[8][9]="║                                                                                  ║░";
swapArray[9][9]="║      Uh oh!  It looks like you have hit your max weapon carrying capacity.       ║░";
swapArray[10][9]="║     Are you interested in swapping out one of your weapons for this new one?     ║░";
swapArray[11][9]="║                                                                                  ║░";
swapArray[12][9]="║   ‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗      ‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗       ║░";
swapArray[13][9]="║   │ Current Weapon │ Attack │ Speed │      │ New Weapon │ Attack │ Speed │       ║░";
swapArray[14][9]="║   ├════════════════╬════════╬═══════┤      ├════════════╬════════╬═══════┤       ║░";

swapArray[15][9]="║   │   "+wOne+"│   "+to_string(wOneAttack)+"    │   "+to_string(wOneSpeed)+"   │      │  "+wNew+"│   "+to_string(wNewAttack)+"    │   "+to_string(wNewSpeed)+"   │       ║░";
//swapArray[15][9]="║   │   123456789....│...12...│...12..│      │..123456789.│...12...│...12..│       ║░";

swapArray[16][9]="║   │   "+wTwo+"│   "+to_string(wTwoAttack)+"    │   "+to_string(wTwoSpeed)+"   │      └────────────┴────────┴───────┘       ║░";
//swapArray[16][9]="║   │   123456789....│...12...│...12..│      └────────────┴────────┴───────┘       ║░";

swapArray[17][9]="║   │   "+wThree+"│   "+to_string(wThreeAttack)+"    │   "+to_string(wThreeSpeed)+"   │                                            ║░";
//swapArray[17][9]="║   │   123456789....│...12...│...12..│                                            ║░";
swapArray[18][9]="║   └────────────────┴────────┴───────┘                                            ║░";
swapArray[19][9]="║                                                                                  ║░";
swapArray[20][9]="║                      ";swapArray[20][10]=">";swapArray[20][11]="[1] ─ swap "+wNews+" for "+wOnes+"                               ║░";
swapArray[21][9]="║                      ";swapArray[21][10]=" ";swapArray[21][11]="[2] ─ swap "+wNews+" for "+wTwos+"                               ║░";
swapArray[22][9]="║                      ";swapArray[22][10]=" ";swapArray[22][11]="[3] ─ swap "+wNews+" for "+wThrees+"                               ║░";
swapArray[23][9]="║                      ";swapArray[23][10]=" ";swapArray[23][11]="[4] ─ keep current weapons                                 ║░";
swapArray[24][9]="║                                                                                  ║░";
swapArray[25][9]="════════════════════════════════════════════════════════════════════════════════════░";

swapArray[26][9]=" ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░";

  for(int n=0;n<34;n++){
    for(int m=0;m<102;m++){
      cout << swapArray[n][m];
    }
    cout << endl;
  }
string whatchyaDo;
cout << "What would you like to do?\n ";

char cws;

    while (read(STDIN_FILENO, &cws, 1) == 1 && cws != 'q') {
      switch(cws){


        case 'w':
        {
          if(swapArray[20][10]==">"){break;}
          if(swapArray[21][10]==">"){
            std::system("clear");
            swapArray[21][10]=" ";
            swapArray[20][10]=">";
              for(int n=0;n<34;n++){
                for(int m=0;m<102;m++){
                  cout << swapArray[n][m];
                }
              cout << endl;
              }
            break;
          }
          if(swapArray[22][10]==">"){
             std::system("clear");
            swapArray[22][10]=" ";
            swapArray[21][10]=">";
              for(int n=0;n<34;n++){
                for(int m=0;m<102;m++){
                  cout << swapArray[n][m];
                }
              cout << endl;
              }
            break;
          }
          if(swapArray[23][10]==">"){
             std::system("clear");
            swapArray[23][10]=" ";
            swapArray[22][10]=">";
              for(int n=0;n<34;n++){
                for(int m=0;m<102;m++){
                  cout << swapArray[n][m];
                }
              cout << endl;
              }
            break;
          }
        }//case w
        case 's':
        {
          if(swapArray[20][10]==">"){
            std::system("clear");
            swapArray[20][10]=" ";
            swapArray[21][10]=">";
              for(int n=0;n<34;n++){
                for(int m=0;m<102;m++){
                  cout << swapArray[n][m];
                }
              cout << endl;
              }
            break;
          }
          if(swapArray[21][10]==">"){
            std::system("clear");
            swapArray[21][10]=" ";
            swapArray[22][10]=">";
              for(int n=0;n<34;n++){
                for(int m=0;m<102;m++){
                  cout << swapArray[n][m];
                }
              cout << endl;
              }
            break;
          }
          if(swapArray[22][10]==">"){
            std::system("clear");
            swapArray[22][10]=" ";
            swapArray[23][10]=">";
              for(int n=0;n<34;n++){
                for(int m=0;m<102;m++){
                  cout << swapArray[n][m];
                }
              cout << endl;
              }
            break;
          }
          if(swapArray[23][10]==">"){break;}
        }//end case s
        case '\n':
        {
          if(swapArray[20][10]==">"){
            wOne=wNew+"   ";
            wOnes=wNews;
            wOneAttack=wNewAttack;
            wOneSpeed=wNewSpeed;
            swapSuccess();
            break;
          }
          if(swapArray[21][10]==">"){
            wTwo=wNew+"   ";
            wTwos=wNews;
            wTwoAttack=wNewAttack;
            wTwoSpeed=wNewSpeed;
            swapSuccess();
            break;
          }
          if(swapArray[22][10]==">"){
            wThree=wNew+"   ";
            wThrees=wNews;
            wThreeAttack=wNewAttack;
            wThreeSpeed=wNewSpeed;
            swapSuccess();
            break;
          }
          if(swapArray[23][10]==">"){
            noSwap();
            break;
          }
        }//end case enter
        default:
        {
        //  cout << cws << endl;
          cout << "error code 007\n";
          break;
        }//end default
      }//end switch
continue;
    }

}

void My_class::swapSuccess(){
std::system("clear");
swapArray[7][9]="════════════════════════════════════════════════════════════════════════════════════ ";
swapArray[8][9]="║                                                                                  ║░";
swapArray[9][9]="║                      You have successfully swapped weapons.                      ║░";
swapArray[10][9]="║                                                                                  ║░";
swapArray[11][9]="║                                                                                  ║░";
swapArray[12][9]="║   ‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗                                            ║░";
swapArray[13][9]="║   │ Current Weapon │ Attack │ Speed │                                            ║░";
swapArray[14][9]="║   ├════════════════╬════════╬═══════┤                                            ║░";

swapArray[15][9]="║   │   "+wOne+"│   "+to_string(wOneAttack)+"    │   "+to_string(wOneSpeed)+"   │                                            ║░";
//swapArray[15][9]="║   │   123456789....│...12...│...12..│      │..123456789.│...12...│...12..│       ║░";

swapArray[16][9]="║   │   "+wTwo+"│   "+to_string(wTwoAttack)+"    │   "+to_string(wTwoSpeed)+"   │                                            ║░";
//swapArray[16][9]="║   │   123456789....│...12...│...12..│      └────────────┴────────┴───────┘       ║░";

swapArray[17][9]="║   │   "+wThree+"│   "+to_string(wThreeAttack)+"    │   "+to_string(wThreeSpeed)+"   │                                            ║░";
//swapArray[17][9]="║   │   123456789....│...12...│...12..│                                            ║░";
swapArray[18][9]="║   └────────────────┴────────┴───────┘                                            ║░";
swapArray[19][9]="║                                                                                  ║░";
swapArray[20][9]="║                      ";swapArray[20][10]=" ";swapArray[20][11]="[1] ─ swap "+wNews+" for "+wOnes+"                               ║░";
swapArray[21][9]="║                      ";swapArray[21][10]=" ";swapArray[21][11]="[2] ─ swap "+wNews+" for "+wTwos+"                               ║░";
swapArray[22][9]="║                      ";swapArray[22][10]=" ";swapArray[22][11]="[3] ─ swap "+wNews+" for "+wThrees+"                               ║░";
swapArray[23][9]="║                      ";swapArray[23][10]=" ";swapArray[23][11]="[4] ─ keep current weapons                                 ║░";
swapArray[24][9]="║                                                                                  ║░";
swapArray[25][9]="════════════════════════════════════════════════════════════════════════════════════░";

swapArray[26][9]=" ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░";

  for(int n=0;n<34;n++){
    for(int m=0;m<102;m++){
      cout << swapArray[n][m];
    }
    cout << endl;
  }
          cout << " ... Press Enter To Continue ... \n";
          getchar();
          std::system("clear");
          tempvar2="ok";
          ifOK2(tempvar2);
}

void My_class::noSwap(){
std::system("clear");
swapArray[7][9]="════════════════════════════════════════════════════════════════════════════════════ ";
swapArray[8][9]="║                                                                                  ║░";
swapArray[9][9]="║                      You leave the new weapon laying behind.                     ║░";
swapArray[10][9]="║                                                                                  ║░";
swapArray[11][9]="║                                                                                  ║░";
swapArray[12][9]="║   ‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗                                            ║░";
swapArray[13][9]="║   │ Current Weapon │ Attack │ Speed │                                            ║░";
swapArray[14][9]="║   ├════════════════╬════════╬═══════┤                                            ║░";

swapArray[15][9]="║   │   "+wOne+"│   "+to_string(wOneAttack)+"    │   "+to_string(wOneSpeed)+"   │                                            ║░";
//swapArray[15][9]="║   │   123456789....│...12...│...12..│      │..123456789.│...12...│...12..│       ║░";

swapArray[16][9]="║   │   "+wTwo+"│   "+to_string(wTwoAttack)+"    │   "+to_string(wTwoSpeed)+"   │                                            ║░";
//swapArray[16][9]="║   │   123456789....│...12...│...12..│      └────────────┴────────┴───────┘       ║░";

swapArray[17][9]="║   │   "+wThree+"│   "+to_string(wThreeAttack)+"    │   "+to_string(wThreeSpeed)+"   │                                            ║░";
//swapArray[17][9]="║   │   123456789....│...12...│...12..│                                            ║░";
swapArray[18][9]="║   └────────────────┴────────┴───────┘                                            ║░";
swapArray[19][9]="║                                                                                  ║░";
swapArray[20][9]="║                                                                                  ║░";
swapArray[20][10]="\0";swapArray[20][11]="\0";
swapArray[21][9]="║                                                                                  ║░";
swapArray[21][10]="\0";swapArray[21][11]="\0";
swapArray[22][9]="║                                                                                  ║░";
swapArray[22][10]="\0";swapArray[22][11]="\0";
swapArray[23][9]="║                                                                                  ║░";
swapArray[23][10]="\0";swapArray[23][11]="\0";
swapArray[24][9]="║                                                                                  ║░";
swapArray[25][9]="════════════════════════════════════════════════════════════════════════════════════░";

swapArray[26][9]=" ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░";



  for(int n=0;n<34;n++){
    for(int m=0;m<102;m++){
      cout << swapArray[n][m];
    }
    cout << endl;
  }
          cout << " ... Press Enter To Continue ... ";
getchar();
          getchar();
          std::system("clear");
          tempvar2="ok";
          ifOK2(tempvar2);
}

void My_class::aBattle(){
  std::system("clear");
/*
  int ax = 29;
  int ay = 1;
  char cx;
*/
ax = 29;
ay = 1;
char cx;
  std::system("clear");
  std::random_device rd;
  std::mt19937 f{rd()};
  std::uniform_int_distribution<int> dist{0, 1};
  int randoEnemy = dist(f);
  switch(randoEnemy){
    case 0:  //POPPIE
    {      //cout enemy here
      nMonster1 = "Poppie";
      nMonster1Level = playerLevel;

      makeBattleArray(nMonster1, nMonster1Level);
      initialBattlePrint();

if(nWeapons>0&&foundNancei==1){
      printBattleArray();
}//end if
if(nWeapons<1){
whenMove(whichWay);
}
//new here:
whenMove(whichWay);
///////////////////////////////
/*
══════════════════════════════════════════════════════════════════════════════════════════════════════
║ ┌─────────────────────┐                                   JY55YJ??JJJ77?J777???J5G#BBBG7!!7??      ║
║ │Poppie      Lv. 1    │                                   J??JJJ?777?7!!777?5GGGBBBBBGGG7777!      ║
║ │ 👹     💗■■■■■■■■■■ │                                   JJ?77777?7?J?JY55PGGB#BBB##B##Y~~~~      ║
║ └─────────────────────┘                                   GP55Y5PGBGGPPGGPGGP?!~YB&##BB#5:^^~      ║
║                                                           P#BBBB#B####BPGB##. !..B#P@#PB7::::      ║
║         ❤️  ■                                              ?G&BBBB####7:! ^#&BYJ5G#G5@&PG:..::      ║
║                                                           7?#&##&&#B#~.J:J#GGPPYB5#&&P#?....:      ║
║                                                           ?7?G&&#GG&PG5YGBB!#&Y~@@@PGBB::::::      ║
║                                                           7!!~7G&BG#5B&Y&@@@@@&&@@&BG#7::::::      ║
║                                                           ?7!!~~?G##PB#BJBJ@@@@@#YPP#?^^^^^^^      ║
║       ^#&~     :75B#&&@@&&BP?^     !&#^                   7!!~~^^:^!YB#&GYG#P5#G5PB&P~^^^^^::      ║
║      7@@@@&7~G&@@@@@@@@@@@@@@@@B!!&@@@@!                  ?7!~~^!??^::~?5P&&####&&&#&&B5YJ~::      ║
║       .5@@@@@@@@@#P?!~^^~7YG&@@@@@@@@Y.                   ?777!5#G!75GY!!G##&&&&&&&######BP57      ║
║         P@@@@@G~             :Y&@@@@&.                    ?J#5P#&JP#&!~5#&#&&&&&&&&&###&##BBB      ║
║        #@@@@G.                  ?@@@@@^                                                            ║
║       B@@@@7                     .&@@@@.                                                           ║
║      ~@@@@P                       ^@@@@P                                                           ║
║      5@@@@:                        &@@@&                                                           ║
║      5@@@@:                        &@@@&                                                           ║
║      ^@@@@Y                       ^@@@@5                                                           ║
║       G@@@@!                     .&@@@&.                                                           ║
║        B@@@@5.                  7@@@@&:                                                            ║
║         5@@@@@P^             .?&@@@@#                                     ┌─────────────────────┐  ║
║       .Y&@@@@@@@@BY!^^::^~?P&@@@@@@@@G:                                   │You         Lv. 1    │  ║
║      ~@@@@B^~G&@@@@@@@@@@@@@@@@B7~B@@@@?                                  │ ¤      💗■■■■■■■■■■ │  ║
║       :BB:     :?P#&@@@@@&#GJ^.    ^#&^                                   └─────────────────────┘  ║
║            ╔════════════════════════╗         ╔═══════════════════════════════════╗                ║
║            ║                        ║         ║                  │                ║                ║
║            ║   What will            ║         ║   → W[E]APON 🗡️   │  → [B]AG 🛍 ️    ║                ║
║            ║    You do?             ║         ║───────────────────────────────────║                ║
║            ║                        ║         ║   → [M]AGIC ✨   │  → [R]UN 🏃    ║                ║
║            ╚════════════════════════╝         ╚═══════════════════════════════════╝                ║
══════════════════════════════════════════════════════════════════════════════════════════════════════
*/

      break;
}
    case 1:
{       aBattle();
break;
//cout << "case 1";
}
//continue;
      default:
{cout << "error code 008\n";break;}
//      aBattle();
//continue;
  }//end randoEnemy switch
//}//end if nWeapons>0
}//end aBattle void


void My_class::printBattleArray(){
//battleArray[29][1]="→";
std::random_device rd;
std::mt19937 wwr{rd()};
    std::uniform_int_distribution<int> dist{0, 9};
std::system("clear");
for (int gx=0;gx<34;gx++){
  for (int bx=0; bx<7; bx++){
    cout << battleArray[gx][bx];
  }
  cout << endl;
}
cout << "Choose your option and press ENTER\n";

      while (read(STDIN_FILENO, &cvx, 1) == 1 && cvx != 'q') {
        switch(cvx){
          case '\n':  // ENTER KEY
          {
            switch(ax){
              case 29:
              {
                if(ay==1){battleArray[29][1]=" ";weaponFight();break;} //weapon
                if(ay==3){openBag();break;} //bag
               // break;
              }
              case 31:
              {
                if(ay==1){
if(abilityUsed!=1&&aOfChoice!=0){abilityFight();break;}
else{
  std::system("clear");
  for (int gx=0;gx<34;gx++){
    for (int bx=0; bx<7; bx++){
      cout << battleArray[gx][bx];
    }
    cout << endl;
  }
  cout << "You don't have an ability available.  Press ENTER to continue...\n";
getchar();
printBattleArray();
break;
}//else
} //ability

if(ay==3){
if(playerLevel>=1){
  willweRun = dist(wwr);
  if(willweRun>(1+(playerLevel*2))){
string nEnemyHealth = "■■■■■■■■■■";
abilityUsed=0;
    whenMove(whichWay);return;
  }//end >1
  if(willweRun<=(1+(playerLevel*2))){
    battleArray[31][4]=" failed      ║                ║";
            if (nPlayerHealth=="■■■■■■■■■■"){nPlayerHealth="■■■■■■■■■ ";playerLife=90;goto webegoinghere;}
        if (nPlayerHealth=="■■■■■■■■■ "){nPlayerHealth="■■■■■■■■  ";playerLife=80;goto webegoinghere;}
        if (nPlayerHealth=="■■■■■■■■  "){nPlayerHealth="■■■■■■■   ";playerLife=70;goto webegoinghere;}
        if (nPlayerHealth=="■■■■■■■   "){nPlayerHealth="■■■■■■    ";playerLife=60;goto webegoinghere;}
        if (nPlayerHealth=="■■■■■■    "){nPlayerHealth="■■■■■     ";playerLife=50;goto webegoinghere;}
        if (nPlayerHealth=="■■■■■     "){nPlayerHealth="■■■■      ";playerLife=40;goto webegoinghere;}
        if (nPlayerHealth=="■■■■      "){nPlayerHealth="■■■       ";playerLife=30;goto webegoinghere;}
        if (nPlayerHealth=="■■■       "){nPlayerHealth="■■        ";playerLife=20;goto webegoinghere;}
        if (nPlayerHealth=="■■        "){nPlayerHealth="■         ";playerLife=10;goto webegoinghere;}

        if (nPlayerHealth=="■         "){
wfl=0;
weaponFightArray[29][3]=wOnes;
weaponFightArray[29][7]=wTwos;
weaponFightArray[31][3]=wThrees;
if(nWeapons<2){weaponFightArray[29][7]="      ";}
if(nWeapons<3){weaponFightArray[31][3]="      ";}

battleArray[29][1]="→";
battleArray[29][3]=" ";
battleArray[31][1]=" ";
battleArray[31][3]=" ";
ax=29;
ay=1;

battleArray[25][1] = nPlayerHealth;
weaponFightArray[25][1] = nPlayerHealth;
battleArray[3][3] = weaponFightArray[3][3];
//
    std::system("clear");
    for (int gx=0;gx<34;gx++){
      for (int bx=0; bx<7; bx++){
        cout << battleArray[gx][bx];
      }
      cout << endl;
    }
cout << "You failed to escape. "<<nEnemy<<" has attacked you, and you have been defeated. Press ENTER to continue...\n";

          getchar();
          std::system("clear");
          //endGame();     gotta make this void
          break;
        }
webegoinghere:
wfl=0;
weaponFightArray[29][3]=wOnes;
weaponFightArray[29][7]=wTwos;
weaponFightArray[31][3]=wThrees;
if(nWeapons<2){weaponFightArray[29][7]="      ";}
if(nWeapons<3){weaponFightArray[31][3]="      ";}
battleArray[29][1]="→";
battleArray[29][3]=" ";
battleArray[31][1]=" ";
battleArray[31][3]=" ";
ax=29;
ay=1;
battleArray[25][1] = nPlayerHealth;
weaponFightArray[25][1] = nPlayerHealth;

    std::system("clear");
    for (int gx=0;gx<34;gx++){
      for (int bx=0; bx<7; bx++){
        cout << battleArray[gx][bx];
      }
      cout << endl;
    }
cout << "You failed to escape. "<<nEnemy<<" attacked you for "<<(2+(playerLevel-playerDefense))<<" damage.  Press ENTER to continue...\n";
getchar();
battleArray[31][4]=" [R]UN 🏃    ║                ║";
printBattleArray();
break;
  }//end <=1
}//end if lvl1
        
}//end if ay==3

              }
              default:
              {
                cout << "error code 009\n";
cout << "ax = " << ax << " . ay = " << ay << "\n";
return;
              }
            }
          } //enter key

          case 'a':  ///* case a = left *///
          {
            if(battleArray[29][1]=="→"){break;}
            if(battleArray[29][3]=="→"){
              battleArray[29][1]="→";battleArray[29][3]=" ";
              ax=29;
              ay=1;
              printBattleArray();
              break;
            }
            if(battleArray[31][1]=="→"){break;}
            if(battleArray[31][3]=="→"){
              battleArray[31][3]=" ";
              battleArray[31][1]="→";
              ax=31;
              ay=1;
              printBattleArray();
              break;
            }
          } //left key (a)

          case 'd':
          {
            if(battleArray[29][1]=="→"){
              battleArray[29][3]="→";
              battleArray[29][1]=" ";
              ax=29;
              ay=3;
              printBattleArray();
              break;
            }
            if(battleArray[29][3]=="→"){break;}
            if(battleArray[31][1]=="→"){
              battleArray[31][1]=" ";
              battleArray[31][3]="→";
              ax=31;
              ay=3;
              printBattleArray();
              break;
            }
            if(battleArray[31][3]=="→"){break;}
          } //right key (d)

          case 'w':
          {
            if(battleArray[29][1]=="→"){break;}
            if(battleArray[29][3]=="→"){break;}
            if(battleArray[31][1]=="→"){
              battleArray[29][1]="→";
              battleArray[31][1]=" ";
              ax=29;
              ay=1;
              printBattleArray();
              break;
            }
            if(battleArray[31][3]=="→"){
              battleArray[29][3]="→";
              battleArray[31][3]=" ";
              ax=29;
              ay=3;
              printBattleArray();
              break;
            }
          }

          case 's':
          {
            if(battleArray[29][1]=="→"){
              battleArray[29][1]=" ";
              battleArray[31][1]="→";
              ax=31;
              ay=1;
              printBattleArray();
              break;
            }
            if(battleArray[29][3]=="→"){
              battleArray[29][3]=" ";
              battleArray[31][3]="→";
              ax=31;
              ay=3;
              printBattleArray();
              break;
            }
            if(battleArray[31][1]=="→"){break;}
            if(battleArray[31][3]=="→"){break;}
          }//case s

          case 'e':
          {
            battleArray[29][1]=" ";weaponFight();break;
          }
          case 'm':
          {
            if(abilityUsed!=1&&aOfChoice!=0){abilityFight();break;}
            else{
              std::system("clear");
              for (int gx=0;gx<34;gx++){
                for (int bx=0; bx<7; bx++){
                  cout << battleArray[gx][bx];
                }
                cout << endl;
              }
              cout << "You don't have an ability available.  Press ENTER to continue...\n";
              getchar();
              printBattleArray();
              break;
            }//else if
          }//case m
          case 'b':
          {
            openBag();break;
          }
          case 'r':
          {
            if(playerLevel>=1){
              willweRun = dist(wwr);
              if(willweRun>(1+(playerLevel*2))){
                string nEnemyHealth = "■■■■■■■■■■";
                abilityUsed=0;
                whenMove(whichWay);return;
              }//end >1
              if(willweRun<=(1+(playerLevel*2))){
                battleArray[31][4]=" failed      ║                ║";
                if (nPlayerHealth=="■■■■■■■■■■"){nPlayerHealth="■■■■■■■■■ ";playerLife=90;goto webegoinghere2;}
                if (nPlayerHealth=="■■■■■■■■■ "){nPlayerHealth="■■■■■■■■  ";playerLife=80;goto webegoinghere2;}
                if (nPlayerHealth=="■■■■■■■■  "){nPlayerHealth="■■■■■■■   ";playerLife=70;goto webegoinghere2;}
                if (nPlayerHealth=="■■■■■■■   "){nPlayerHealth="■■■■■■    ";playerLife=60;goto webegoinghere2;}
                if (nPlayerHealth=="■■■■■■    "){nPlayerHealth="■■■■■     ";playerLife=50;goto webegoinghere2;}
                if (nPlayerHealth=="■■■■■     "){nPlayerHealth="■■■■      ";playerLife=40;goto webegoinghere2;}
                if (nPlayerHealth=="■■■■      "){nPlayerHealth="■■■       ";playerLife=30;goto webegoinghere2;}
                if (nPlayerHealth=="■■■       "){nPlayerHealth="■■        ";playerLife=20;goto webegoinghere2;}
                if (nPlayerHealth=="■■        "){nPlayerHealth="■         ";playerLife=10;goto webegoinghere2;}
                if (nPlayerHealth=="■         "){
                  wfl=0;
                  weaponFightArray[29][3]=wOnes;
                  weaponFightArray[29][7]=wTwos;
                  weaponFightArray[31][3]=wThrees;
                  if(nWeapons<2){weaponFightArray[29][7]="      ";}
                  if(nWeapons<3){weaponFightArray[31][3]="      ";}
                  battleArray[29][1]="→";
                  battleArray[29][3]=" ";
                  battleArray[31][1]=" ";
                  battleArray[31][3]=" ";
                  ax=29;
                  ay=1;
                  battleArray[25][1] = nPlayerHealth;
                  weaponFightArray[25][1] = nPlayerHealth;
                  battleArray[3][3] = weaponFightArray[3][3];
                  std::system("clear");
                  for (int gx=0;gx<34;gx++){
                    for (int bx=0; bx<7; bx++){
                      cout << battleArray[gx][bx];
                    }
                    cout << endl;
                  }
                  cout << "You failed to escape. "<<nEnemy<<" has attacked you, and you have been defeated. Press ENTER to continue...\n";
                  getchar();
                  std::system("clear");
                  //endGame();     gotta make this void
                  break;
                }
                webegoinghere2:
                  wfl=0;
                  weaponFightArray[29][3]=wOnes;
                  weaponFightArray[29][7]=wTwos;
                  weaponFightArray[31][3]=wThrees;
                  if(nWeapons<2){weaponFightArray[29][7]="      ";}
                  if(nWeapons<3){weaponFightArray[31][3]="      ";}
                  battleArray[29][1]="→";
                  battleArray[29][3]=" ";
                  battleArray[31][1]=" ";
                  battleArray[31][3]=" ";
                  ax=29;
                  ay=1;
                  battleArray[25][1] = nPlayerHealth;
                  weaponFightArray[25][1] = nPlayerHealth;
                  std::system("clear");
                  for (int gx=0;gx<34;gx++){
                    for (int bx=0; bx<7; bx++){
                      cout << battleArray[gx][bx];
                    }
                    cout << endl;
                  }
                  cout << "You failed to escape. "<<nEnemy<<" attacked you for "<<(2+(playerLevel-playerDefense))<<" damage.  Press ENTER to continue...\n";
                  getchar();
                  battleArray[31][4]=" [R]UN 🏃    ║                ║";
                  printBattleArray();
                  break;
              }//end <=1
            }//end if lvl1
          }//case r

          default:
          {
            printBattleArray();
            cout << "error code 011\n";
          }
        }//switch cx
continue;
      }//while

return;
}//end printbattlearray void

void My_class::makeBattleArray(string nMonster, int nMunsterLevel){
nEnemy = nMonster;
nEnemyLevel = nMunsterLevel;
nEnemyHealth="■■■■■■■■■■";
//
battleArray[0][0]="══════════════════════════════════════════════════════════════════════════════════════════════════════";
battleArray[1][0]="║ ┌─────────────────────┐                                   ";battleArray[1][1]="JY55YJ??JJJ77?J777???J5G#BBBG7!!7??";battleArray[1][2]="      \033[0m║";
battleArray[2][0]="║ │";battleArray[2][1]=nEnemy;battleArray[2][2]="      Lv. ";battleArray[2][3]=to_string(nMunsterLevel);battleArray[2][4]="    │                                   ";battleArray[2][5]="J??JJJ?777?7!!777?5GGGBBBBBGGG7777!";battleArray[2][6]="      \033[0m║";
battleArray[3][0]="║ │ ";battleArray[3][1]=nEnemyIcon;battleArray[3][2]="     💗";battleArray[3][3]=nEnemyHealth;battleArray[3][4]=" │                                   ";battleArray[3][5]="JJ?77777?7?J?JY55PGGB#BBB##B##Y~~~~";battleArray[3][6]="      \033[0m║";
battleArray[4][0]="║ └─────────────────────┘                                   ";battleArray[4][1]="GP55Y5PGBGGPPGGPGGP?!~YB&##BB#5:^^~";battleArray[4][2]="      \033[0m║";
battleArray[5][0]="║                                                           ";battleArray[5][1]="P#BBBB#B####BPGB##. !..B#P@#PB7::::";battleArray[5][2]="      \033[0m║";
battleArray[6][0]="║         ❤️  ■                                              ";battleArray[6][1]="?G&BBBB####7:! ^#&BYJ5G#G5@&PG:..::";battleArray[6][2]="      \033[0m║";
battleArray[7][0]="║                                                           ";battleArray[7][1]="7?#&##&&#B#~.J:J#GGPPYB5#&&P#?....:";battleArray[7][2]="      \033[0m║";
battleArray[8][0]="║                                                           ";battleArray[8][1]="?7?G&&#GG&PG5YGBB!#&Y~@@@PGBB::::::";battleArray[8][2]="      \033[0m║";
battleArray[9][0]="║                                                           ";battleArray[9][1]="7!!~7G&BG#5B&Y&@@@@@&&@@&BG#7::::::";battleArray[9][2]="      \033[0m║";
battleArray[10][0]="║                                                           ";battleArray[10][1]="?7!!~~?G##PB#BJBJ@@@@@#YPP#?^^^^^^^";battleArray[10][2]="      \033[0m║";
battleArray[11][0]="║       ^#&~     :75B#&&@@&&BP?^     !&#^                   ";battleArray[11][1]="7!!~~^^:^!YB#&GYG#P5#G5PB&P~^^^^^::";battleArray[11][2]="      \033[0m║";
battleArray[12][0]="║      7@@@@&7~G&@@@@@@@@@@@@@@@@B!!&@@@@!                  ";battleArray[12][1]="?7!~~^!??^::~?5P&&####&&&#&&B5YJ~::";battleArray[12][2]="      \033[0m║";
battleArray[13][0]="║       .5@@@@@@@@@#P?!~^^~7YG&@@@@@@@@Y.                   ";battleArray[13][1]="?777!5#G!75GY!!G##&&&&&&&######BP57";battleArray[13][2]="      \033[0m║";
battleArray[14][0]="║         P@@@@@G~             :Y&@@@@&.                    ";battleArray[14][1]="?J#5P#&JP#&!~5#&#&&&&&&&&&###&##BBB";battleArray[14][2]="      \033[0m║";
battleArray[15][0]="║        #@@@@G.                  ?@@@@@^                                                            ║";
battleArray[16][0]="║       B@@@@7                     .&@@@@.                                                           ║";
battleArray[17][0]="║      ~@@@@P                       ^@@@@P                                                           ║";
battleArray[18][0]="║      5@@@@:                        &@@@&                                                           ║";
battleArray[19][0]="║      5@@@@:                        &@@@&                                                           ║";
battleArray[20][0]="║      ^@@@@Y                       ^@@@@5                                                           ║";
battleArray[21][0]="║       G@@@@!                     .&@@@&.                                                           ║";
battleArray[22][0]="║        B@@@@5.                  7@@@@&:                                                            ║";
battleArray[23][0]="║         5@@@@@P^             .?&@@@@#                                     ┌─────────────────────┐  ║";
battleArray[24][0]="║       .Y&@@@@@@@@BY!^^::^~?P&@@@@@@@@G:                                   │You         ";battleArray[24][1]="Lv. ";battleArray[24][2]="1";battleArray[24][3]="    │  ║";
battleArray[25][0]="║      ~@@@@B^~G&@@@@@@@@@@@@@@@@B7~B@@@@?                                  │ ¤      💗";battleArray[25][1]=nPlayerHealth;battleArray[25][2]=" │  ║";
battleArray[26][0]="║       :BB:     :?P#&@@@@@&#GJ^.    ^#&^                                   └─────────────────────┘  ║";
battleArray[27][0]="║            ╔════════════════════════╗         ╔═══════════════════════════════════╗                ║";
battleArray[28][0]="║            ║                        ║         ║                  │                ║                ║";
battleArray[29][0]="║            ║   What will            ║         ║   ";battleArray[29][1]="→";battleArray[29][2]=" W[E]APON 🗡️   │  ";battleArray[29][3]=" ";battleArray[29][4]=" [B]AG 🛍 ️    ║                ║";
battleArray[30][0]="║            ║    You do?             ║         ║───────────────────────────────────║                ║";
battleArray[31][0]="║            ║                        ║         ║   ";battleArray[31][1]=" ";battleArray[31][2]=" [M]AGIC ✨   │  ";battleArray[31][3]=" ";battleArray[31][4]=" [R]UN 🏃    ║                ║";
battleArray[32][0]="║            ╚════════════════════════╝         ╚═══════════════════════════════════╝                ║";
battleArray[33][0]="══════════════════════════════════════════════════════════════════════════════════════════════════════";

//
if(nEnemy=="Poppie"){
battleArray[1][1]="\033[31mJY55YJ??JJJ77?J777???J5G#BBBG7!!7??";
battleArray[2][5]="\033[31mJ??JJJ?777?7!!777?5GGGBBBBBGGG7777!";
battleArray[3][5]="\033[31mJJ?77777?7?J?JY55PGGB#BBB##B##Y~~~~";
battleArray[4][1]="\033[31mGP55Y5PGBGGPPGGPGGP?!~YB&##BB#5:^^~";
battleArray[5][1]="\033[31mP#BBBB#B####BPGB##. \033[1;33m!\033[31m..B#P@#PB7::::";
battleArray[6][1]="\033[31m?G&BBBB####7:\033[1;33m! \033[31m^#&BYJ5G#G5@&PG:..::";
battleArray[7][1]="\033[31m7?#&##&&#B#~.J:J#GGPPYB5#&&P#?....:";
battleArray[8][1]="\033[31m?7?G&&#GG&PG5YGBB!#&Y~@@@PGBB::::::";
battleArray[9][1]="\033[31m7!!~7G&BG#5B&Y&@@@@@&&@@&BG#7::::::";
battleArray[10][1]="\033[31m?7!!~~?G##PB#BJBJ@@@@@#YPP#?^^^^^^^";
battleArray[11][1]="\033[31m7!!~~^^:^!YB#&GYG#P5#G5PB&P~^^^^^::";
battleArray[12][1]="\033[31m?7!~~^!??^::~?5P&&####&&&#&&B5YJ~::";
battleArray[13][1]="\033[31m?777!5#G!75GY!!G##&&&&&&&######BP57";
battleArray[14][1]="\033[31m?J#5P#&JP#&!~5#&#&&&&&&&&&###&##BBB";
}
//



/*
battleArray[29][1]="→";
battleArray[29][3]="→";
battleArray[31][1]="→";
battleArray[31][3]="→";
*/
return;
}


void My_class::initialBattlePrint(){
if(nEnemy=="Poppie"){
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║     \033[31mJJJY5555555YJ????????JJJJJJ?777777?JJJJ?777777????7!!7JJJ5PGBB###GPBBBB#&G!?!!!!!!!7??????     \033[0m║\n";
cout << "║     \033[31mJJJJJJYYYYYYYYJ???7777?JJJJJ?777777?????7!!!!!777?J5GGPPGBBBB##BGGB##BB#B55Y!!!!!!7???????     \033[0m║\n";
cout << "║     \033[31mJJJ????JYYYYYJJJ?7777777?????7!!!!!!77777!!!!!?JPBBBP5PGGB##BBGGB#BBBGBBP5GPJ7!!!77777777!     \033[0m║\n";
cout << "║     \033[31m??????????JJJJJJJ?777!!!!77777!~~~~~!77!!?77YPGGGBG5PGGGBBBBBBB##BBGBGP5PGBB#5!!777777!!!!     \033[0m║\n";
cout << "║     \033[31mYJ??????777??J?????7!!!!!!!7!!!!~~!!!!!?YY55PGGGPPPGBBB#BGBBB##BBBBBBP5PB###&B!!!!!!!~~~~~     \033[0m║\n";
cout << "║     \033[31mYYYJ??777777777??7777!~~~~!?YJ?777J5P55PP5PP55GPPPGGBBB#BGB###BBBBB#GGBBB#B#&#!~!~~~~~~~~~     \033[0m║\n";
cout << "║     \033[31mYYJJJJ?77777!!!!!77?YPGG5YYY5PPGGPPPPPPPGP5PPPPPPGGGBBB#BB#B##BB#&&&&&#######GJ!^^^^^^^^~~     \033[0m║\n";
cout << "║     \033[31mYJJJJ????7!!~~7?J55PGGGGGGPPP55GP5GGGPPPPGPPPGBGB#BBBB######B##&@@&&&&#&&&####B?:^^^^^^~~~     \033[0m║\n";
cout << "║     \033[31m###BGGPP555YYPGGGGBBBBBGPGBGPPPPP55PGPPPPPPPGGB#G?\033[1;33m:.....:7\033[31mB#B#&&&#BBGPPGGB###&P^::::^^^^^~     \033[0m║\n";
cout << "║     \033[31mG##############&&#BBB###BGGBBBPPGGGPGBBGGBBBBBB\033[1;33m~   ^.     .P\033[31m#####5P&@BPPGGGB#B!:::^^^^^^^^     \033[0m║\n";
cout << "║     \033[31mJG#BGGBB#####BB######&&&######BBBBBB#BBGB#####\033[1;33m7    J@5    .?\033[31m&BB#GJG@@@#G5GGBBB~:::::::::::     \033[0m║\n";
cout << "║     \033[31m??G&#GGGGBGGGGBBBBGBBB#####&######GGBB##BB#&##\033[1;33m7     !&B  .^G\033[31m&BB#PJG@@@&BJGGB#B^:::::::::::     \033[0m║\n";
cout << "║     \033[31mJ??B&&BGGGBGGGBB##############BY\033[1;33m^:.   :Y\033[31m#####&#?\033[33m:.   .J!^\033[31mJB&BB##J5#@@@@#JPGB#Y:.......::::     \033[0m║\n";
cout << "║     \033[31mJJ?J#&&###BBBB#BBB#######B###\033[1;33m?   YY     :G\033[31m##&&@@&BP5YY5GB##B##GYY?~@@@&BYPG#B^........::::     \033[0m║\n";
cout << "║     \033[31m????G&&&##BB#############BB&\033[1;33mJ    &@.     5\033[31m@@@@@&&&&&##BBBB##BGYPP#J#@@#PPGB&!.......::::::     \033[0m║\n";
cout << "║     \033[31m77!!5&@&&###B######&&&&#####\033[1;33mJ    ?@^   .7\033[31m&&&&#BGGGGGGGGGGGGPY5&@@&@@@BPPPB&B:....:::::::::     \033[0m║\n";
cout << "║     \033[31m77!!!5&&&&&#####&@&&&&&######?\033[1;33m:.  J!.^?\033[31mG&&#GJJ??JY??5Y?JJPB#~.@@&@@@BGPPG&@Y:::...........     \033[0m║\n";
cout << "║     \033[31m777!!7P&&&#####&&&#BBP555GBBBB5JJ??YP#&&#B5JJ?5&&@^ &? .5&@@@J5@?J&#GPPP#&#^..............     \033[0m║\n";
cout << "║     \033[31m????777YB&&&###&&BGP5YB#B5YPGGBBBBBB#BBP5YPP~ ~@@@&7@^ :@&@@@@@@@ 7#GPPB&&7.....::::::::::     \033[0m║\n";
cout << "║     \033[31m????777!!JB&&&###BGP5G@@@@B~~G5Y5JJY5YJGB#@@G: &@@@@@. G@@&@@@@@@BPGPPB&&P::::::::::::::::     \033[0m║\n";
cout << "║     \033[31m777!!!!!~~~?G&&&#BGPP5G&@@@?^@BG@?.:&&G@@G@@@@PB@@@@@.J@@@@&@@@@BBBG5B#&&!::::::::::::::::     \033[0m║\n";
cout << "║     \033[31m7!!!!!~~~~~^^?B&&#BGPPYYPPPBG&&@@#.G@@@@@#@@@@@@@@@@@5@@@@@&B&##&BGPG&&&J:::::::::::::::::     \033[0m║\n";
cout << "║     \033[31m777!!!!~~~~~~~~5&&&&#BBP557.75&@@@&@@&B@@@#P@@@@@@@@@@@@@##@@&5!GP5P##&G!^^^^^^^^:::::::::     \033[0m║\n";
cout << "║     \033[31m???7777!!!!!!~~~JB&&&&&&###^PGP5PB&G?.P@@5 G@@@@@@@@@@@@@&7:?&@BP55B#&P~^^^^^^^^^^^^^^^^^^     \033[0m║\n";
cout << "║     \033[31mJ???777!!!~~~^^^^^~JG&&&&##GG&&#BG5Y7:7GB: @@@@GG@@@@@@@&@@?.?G5YYB#&P^:^::::::::^^^^^^^^^     \033[0m║\n";
cout << "║     \033[31m?77!!!~~~~^^^^^^^^::^~?5B&&&##B######Y:Y5YJ&@@@&:5@@@@@@~7&B55JJP##&G~^^^^^^^^::::::::::::     \033[0m║\n";
cout << "║     \033[31m77!!!!~~~~^^^^^^^^^^^^^:^~JG&&&&&&####~5#G5YYPG#Y^G@&&#BJJ??JYGB&&&&!:^^^^^^^^^^^^^:::::::     \033[0m║\n";
cout << "║     \033[31m77!!!!!!!~~~~~~~^^^^::::::::~7P#&&&&&#77##&&BP5JJJ???7??JYPB#&&&&&BB5J?7~^^:^^^^^^^^^^^:::     \033[0m║\n";
cout << "║     \033[31m???7777!!!~~~^^^^:::^^^~~^:::::^~?5B&&5:B#&&&&&&&##BB###&&&@&&&&&#B&@@@&#B5YJJJ?!~^:^^^^^^     \033[0m║\n";
cout << "║     \033[31mJJ???77!!~~^^^^^^!?5PGGY!::::::::::^7P##&@&&&&&&&&&@@@&&&&####BBB#&&&&&&&BBGGPPPP5?~:::::^     \033[0m║\n";
cout << "║     \033[31mJJ??7!!~~~^^^^!YPB###P!::::::^~~~~~^^^^~Y##&@&&&&&&@@&&@&&&&&@&&&#B####&##BGGBGGG555J7^:::     \033[0m║\n";
cout << "║            \"Hiii theeere, my name is Poppie!  Do you enjoy the sound of bones popping?\"            ║\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
}
      cout << " ... Press Enter To Continue ... ";
      getchar();
      std::system("clear");

      if(foundNancei==0){
        cout << "\n";
        cout << " \"" << nameChar << "! Wait!  Come see me first!\"\n";
        cout << "   - Nancei\n";
        cout << "You hear a lady calling you from a distance.\n";
        cout << "\n\n";
        cout << " ... Press Enter To Continue ... \n";
        getchar();
      }
      if(nWeapons<1){
        cout << "\n";
        cout << " \"Oh, I would just love to munch of your crunchy skeletal system!\"\n";
        cout << "   - Poppie, the bone-eating monster\n";
        cout << "\n";
        cout << " You realize that you do not yet own a weapon and will have no way of fighting this beast.\n";
        cout << " You run away as fast as your cowardly legs take you.\n";
        cout << "\n\n";
        cout << " ... Press Enter To Continue ... \n";
        getchar();
      }//end if nWeapons<1
      else if(nWeapons>0){
      
      }
return;
}//end void


void My_class::weaponFight(){
//int wfl=0; //which level in the menu are we
std::system("clear");

char cv;
nMonster1Level = playerLevel;

weaponFightArray[0][0]="══════════════════════════════════════════════════════════════════════════════════════════════════════";
weaponFightArray[1][0]="║ ┌─────────────────────┐                                   ";weaponFightArray[1][1]="JY55YJ??JJJ77?J777???J5G#BBBG7!!7??";weaponFightArray[1][2]="      \033[0m║";
weaponFightArray[2][0]="║ │";weaponFightArray[2][1]=nEnemy;weaponFightArray[2][2]="      Lv. ";weaponFightArray[2][3]=to_string(nMonster1Level);weaponFightArray[2][4]="    │                                   ";weaponFightArray[2][5]="J??JJJ?777?7!!777?5GGGBBBBBGGG7777!";weaponFightArray[2][6]="      \033[0m║";
weaponFightArray[3][0]="║ │ ";weaponFightArray[3][1]=nEnemyIcon;weaponFightArray[3][2]="     💗";weaponFightArray[3][3]=nEnemyHealth;weaponFightArray[3][4]=" │                                   ";weaponFightArray[3][5]="JJ?77777?7?J?JY55PGGB#BBB##B##Y~~~~";weaponFightArray[3][6]="      \033[0m║";
weaponFightArray[4][0]="║ └─────────────────────┘                                   ";weaponFightArray[4][1]="GP55Y5PGBGGPPGGPGGP?!~YB&##BB#5:^^~";weaponFightArray[4][2]="      \033[0m║";
weaponFightArray[5][0]="║                                                           ";weaponFightArray[5][1]="P#BBBB#B####BPGB##. !..B#P@#PB7::::";weaponFightArray[5][2]="      \033[0m║";
weaponFightArray[6][0]="║         ❤️  ■                                              ";weaponFightArray[6][1]="?G&BBBB####7:! ^#&BYJ5G#G5@&PG:..::";weaponFightArray[6][2]="      \033[0m║";
weaponFightArray[7][0]="║                                                           ";weaponFightArray[7][1]="7?#&##&&#B#~.J:J#GGPPYB5#&&P#?....:";weaponFightArray[7][2]="      \033[0m║";
weaponFightArray[8][0]="║                                                           ";weaponFightArray[8][1]="?7?G&&#GG&PG5YGBB!#&Y~@@@PGBB::::::";weaponFightArray[8][2]="      \033[0m║";
weaponFightArray[9][0]="║                                                           ";weaponFightArray[9][1]="7!!~7G&BG#5B&Y&@@@@@&&@@&BG#7::::::";weaponFightArray[9][2]="      \033[0m║";
weaponFightArray[10][0]="║                                                           ";weaponFightArray[10][1]="?7!!~~?G##PB#BJBJ@@@@@#YPP#?^^^^^^^";weaponFightArray[10][2]="      \033[0m║";
weaponFightArray[11][0]="║       ^#&~     :75B#&&@@&&BP?^     !&#^                   ";weaponFightArray[11][1]="7!!~~^^:^!YB#&GYG#P5#G5PB&P~^^^^^::";weaponFightArray[11][2]="      \033[0m║";
weaponFightArray[12][0]="║      7@@@@&7~G&@@@@@@@@@@@@@@@@B!!&@@@@!                  ";weaponFightArray[12][1]="?7!~~^!??^::~?5P&&####&&&#&&B5YJ~::";weaponFightArray[12][2]="      \033[0m║";
weaponFightArray[13][0]="║       .5@@@@@@@@@#P?!~^^~7YG&@@@@@@@@Y.                   ";weaponFightArray[13][1]="?777!5#G!75GY!!G##&&&&&&&######BP57";weaponFightArray[13][2]="      \033[0m║";
weaponFightArray[14][0]="║         P@@@@@G~             :Y&@@@@&.                    ";weaponFightArray[14][1]="?J#5P#&JP#&!~5#&#&&&&&&&&&###&##BBB";weaponFightArray[14][2]="      \033[0m║";
weaponFightArray[15][0]="║        #@@@@G.                  ?@@@@@^                                                            ║";
weaponFightArray[16][0]="║       B@@@@7                     .&@@@@.                                                           ║";
weaponFightArray[17][0]="║      ~@@@@P                       ^@@@@P                                                           ║";
weaponFightArray[18][0]="║      5@@@@:                        &@@@&                                                           ║";
weaponFightArray[19][0]="║      5@@@@:                        &@@@&                                                           ║";
weaponFightArray[20][0]="║      ^@@@@Y                       ^@@@@5                                                           ║";
weaponFightArray[21][0]="║       G@@@@!                     .&@@@&.                                                           ║";
weaponFightArray[22][0]="║        B@@@@5.                  7@@@@&:                                                            ║";
weaponFightArray[23][0]="║         5@@@@@P^             .?&@@@@#                                     ┌─────────────────────┐  ║";
weaponFightArray[24][0]="║       .Y&@@@@@@@@BY!^^::^~?P&@@@@@@@@G:                                   │You         ";weaponFightArray[24][1]="Lv. ";weaponFightArray[24][2]="1";weaponFightArray[24][3]="    │  ║";
weaponFightArray[25][0]="║      ~@@@@B^~G&@@@@@@@@@@@@@@@@B7~B@@@@?                                  │ ¤      💗";weaponFightArray[25][1]=nPlayerHealth;weaponFightArray[25][2]=" │  ║";
weaponFightArray[26][0]="║       :BB:     :?P#&@@@@@&#GJ^.    ^#&^                                   └─────────────────────┘  ║";
weaponFightArray[27][0]="║            ╔════════════════════════╗         ╔═══════════════════════════════════╗                ║";
weaponFightArray[28][0]="║            ║                        ║         ║                  │                ║                ║";
weaponFightArray[29][0]="║            ║   What will            ║         ║   ";weaponFightArray[29][1]="→";weaponFightArray[29][2]=" ";weaponFightArray[29][3]=wOnes;weaponFightArray[29][4]="       │  ";weaponFightArray[29][5]=" ";weaponFightArray[29][6]=" ";weaponFightArray[29][7]=wTwos;weaponFightArray[29][8]="      ║                ║";
weaponFightArray[30][0]="║            ║    You do?             ║         ║───────────────────────────────────║                ║";
weaponFightArray[31][0]="║            ║                        ║         ║   ";weaponFightArray[31][1]=" ";weaponFightArray[31][2]=" ";weaponFightArray[31][3]=wThrees;weaponFightArray[31][4]="       │  ";weaponFightArray[31][5]=" ";weaponFightArray[31][6]=" [R]UN 🏃";weaponFightArray[31][7]="    ║                ║";
weaponFightArray[32][0]="║            ╚════════════════════════╝         ╚═══════════════════════════════════╝                ║";
weaponFightArray[33][0]="══════════════════════════════════════════════════════════════════════════════════════════════════════";

//

weaponFightArray[1][1]=battleArray[1][1]; //="\033[31mJY55YJ??JJJ77?J777???J5G#BBBG7!!7??";
weaponFightArray[2][5]=battleArray[2][5];
weaponFightArray[3][5]=battleArray[3][5];
weaponFightArray[4][1]=battleArray[4][1];
weaponFightArray[5][1]=battleArray[5][1];
weaponFightArray[6][1]=battleArray[6][1];
weaponFightArray[7][1]=battleArray[7][1];
weaponFightArray[8][1]=battleArray[8][1];
weaponFightArray[9][1]=battleArray[9][1];
weaponFightArray[10][1]=battleArray[10][1];
weaponFightArray[11][1]=battleArray[11][1];
weaponFightArray[12][1]=battleArray[12][1];
weaponFightArray[13][1]=battleArray[13][1];
weaponFightArray[14][1]=battleArray[14][1];
//weaponFightArray[31][6]=" [R]UN 🏃";
//                        "123456789"
weaponFightArray[31][6]=" GO BACK ";

if(nWeapons<2){weaponFightArray[29][7]="      ";}
if(nWeapons<3){weaponFightArray[31][3]="      ";}

for(int tx=0;tx<34;tx++){
  for(int yx=0;yx<9;yx++){
    cout << weaponFightArray[tx][yx];
  }
  cout << endl;
}
cout << "end\n";

      while (read(STDIN_FILENO, &cv, 1) == 1 && cv != 'q') {
        switch(cv){
          case 's':
          {
            wfl=0;
            weaponFightArray[29][3]=wOnes;
            weaponFightArray[29][7]=wTwos;
            weaponFightArray[31][3]=wThrees;
            if(nWeapons<2){weaponFightArray[29][7]="      ";}
            if(nWeapons<3){weaponFightArray[31][3]="      ";}
            if(weaponFightArray[29][1]=="→"){
              weaponFightArray[29][1]=" ";
              weaponFightArray[31][1]="→";
              std::system("clear");
              for(int tx=0;tx<34;tx++){
                for(int yx=0;yx<9;yx++){
                  cout << weaponFightArray[tx][yx];
                }
                cout << endl;
              }
              cout << "end\n";
              break;
            }//end if
            if(weaponFightArray[31][1]=="→"){}
            if(weaponFightArray[31][5]=="→"){}
            if(weaponFightArray[29][5]=="→"){
              weaponFightArray[29][5]=" ";
              weaponFightArray[31][5]="→";
              std::system("clear");
              for(int tx=0;tx<34;tx++){
                for(int yx=0;yx<9;yx++){
                  cout << weaponFightArray[tx][yx];
                }
                cout << endl;
              }
              cout << "end\n";
              break;
            }//end if
          }//case
          case 'w':
          {
            wfl=0;
            weaponFightArray[29][3]=wOnes;
            weaponFightArray[29][7]=wTwos;
            weaponFightArray[31][3]=wThrees;
            if(nWeapons<2){weaponFightArray[29][7]="      ";}
            if(nWeapons<3){weaponFightArray[31][3]="      ";}

            if(weaponFightArray[31][1]=="→"){
              weaponFightArray[31][1]=" ";
              weaponFightArray[29][1]="→";
              std::system("clear");
              for(int tx=0;tx<34;tx++){
                for(int yx=0;yx<9;yx++){
                  cout << weaponFightArray[tx][yx];
                }
                cout << endl;
              }
              cout << "end\n";
              break;
            }//end if
            if(weaponFightArray[31][5]=="→"){
              weaponFightArray[31][5]=" ";
              weaponFightArray[29][5]="→";
              std::system("clear");
              for(int tx=0;tx<34;tx++){
                for(int yx=0;yx<9;yx++){
                  cout << weaponFightArray[tx][yx];
                }
                cout << endl;
              }
              cout << "end\n";
              break;
            }//end if
            if(weaponFightArray[29][1]=="→"){}
            if(weaponFightArray[29][5]=="→"){}
          }//case

          case 'a':
          {
            wfl=0;
            weaponFightArray[29][3]=wOnes;
            weaponFightArray[29][7]=wTwos;
            weaponFightArray[31][3]=wThrees;
            if(nWeapons<2){weaponFightArray[29][7]="      ";}
            if(nWeapons<3){weaponFightArray[31][3]="      ";}
            if(weaponFightArray[31][1]=="→"){}
            if(weaponFightArray[29][1]=="→"){}
            if(weaponFightArray[31][5]=="→"){
              weaponFightArray[31][5]=" ";
              weaponFightArray[31][1]="→";
              std::system("clear");
              for(int tx=0;tx<34;tx++){
                for(int yx=0;yx<9;yx++){
                  cout << weaponFightArray[tx][yx];
                }
                cout << endl;
              }
              cout << "end\n";
              break;
            }//end if
            if(weaponFightArray[29][5]=="→"){
              weaponFightArray[29][5]=" ";
              weaponFightArray[29][1]="→";
              std::system("clear");
              for(int tx=0;tx<34;tx++){
                for(int yx=0;yx<9;yx++){
                  cout << weaponFightArray[tx][yx];
                }
                cout << endl;
              }
              cout << "end\n";
              break;
            }//end if

          }//case

          case '\n':
          {
if(wfl==0){
            if(weaponFightArray[29][1]=="→"){
              weaponFightArray[29][3]="atk. " + to_string(wOneAttack);
              wfl=1;
              std::system("clear");
              for(int tx=0;tx<34;tx++){
                for(int yx=0;yx<9;yx++){
                  cout << weaponFightArray[tx][yx];
                }
                cout << endl;
              }
              cout << "end\n";
              break;
            }//end if 29 1
            if(weaponFightArray[29][5]=="→"){
              if(nWeapons>1){
                weaponFightArray[29][7]="atk. " + to_string(wTwoAttack);
                wfl=1;
                std::system("clear");
                for(int tx=0;tx<34;tx++){
                  for(int yx=0;yx<9;yx++){
                    cout << weaponFightArray[tx][yx];
                  }
                  cout << endl;
                }
                cout << "end\n";
                break;
              }//end nweapons>1
            }//end if 29 5
            if(weaponFightArray[31][1]=="→"){
              if(nWeapons>2){
                weaponFightArray[31][3]="atk. " + to_string(wThreeAttack);
                wfl=1;
                std::system("clear");
                for(int tx=0;tx<34;tx++){
                  for(int yx=0;yx<9;yx++){
                    cout << weaponFightArray[tx][yx];
                  }
                  cout << endl;
                }
                cout << "end\n";
                break;
              }//if nweapon 2
            }//end if 31 1

            if(weaponFightArray[31][5]=="→"){
              ///
              wfl=0;
              weaponFightArray[29][3]=wOnes;
              weaponFightArray[29][7]=wTwos;
              weaponFightArray[31][3]=wThrees;
              if(nWeapons<2){weaponFightArray[29][7]="      ";}
              if(nWeapons<3){weaponFightArray[31][3]="      ";}
              battleArray[29][1]="→";
              battleArray[29][3]=" ";
              battleArray[31][1]=" ";
              battleArray[31][3]=" ";
              ax=29;
              ay=1;
              std::system("clear");
              printBattleArray();
              ///
              break;
            }

}//end wfl==0
if(wfl==1){
            if(weaponFightArray[29][1]=="→"){
              wOfChoice = 1;
              std::system("clear");
              attackWithWeapon();
             }
             if(weaponFightArray[29][5]=="→"){
               wOfChoice = 2;
               std::system("clear");
               attackWithWeapon();
             }
             if(weaponFightArray[31][1]=="→"){
               wOfChoice = 3;
               std::system("clear");
               attackWithWeapon();
             }
break;
}

          }//end enter case

          case 'd':
          {
            wfl=0;
            weaponFightArray[29][3]=wOnes;
            weaponFightArray[29][7]=wTwos;
            weaponFightArray[31][3]=wThrees;
            if(nWeapons<2){weaponFightArray[29][7]="      ";}
            if(nWeapons<3){weaponFightArray[31][3]="      ";}
            if(weaponFightArray[31][5]=="→"){}
            if(weaponFightArray[29][5]=="→"){}
            if(weaponFightArray[31][1]=="→"){
              weaponFightArray[31][1]=" ";
              weaponFightArray[31][5]="→";
              std::system("clear");
              for(int tx=0;tx<34;tx++){
                for(int yx=0;yx<9;yx++){
                  cout << weaponFightArray[tx][yx];
                }
                cout << endl;
              }
             // cout << "end\n";
              break;
            }//end if
            if(weaponFightArray[29][1]=="→"){
              weaponFightArray[29][1]=" ";
              weaponFightArray[29][5]="→";
              std::system("clear");
              for(int tx=0;tx<34;tx++){
                for(int yx=0;yx<9;yx++){
                  cout << weaponFightArray[tx][yx];
                }
                cout << endl;
              }
              //cout << "end\n";
              break;
            }//end if
break;
          }//case

break;

        }//switch
continue;
      }//while
return;
}//end void

void My_class::openBag(){
  std::system("clear");
openBagArray[0][0]="══════════════════════════════════════════════════════════════════════════════════════════════════════";
openBagArray[1][0]="║ ┌─────────────────────┐                                   ";openBagArray[1][1]="JY55YJ??JJJ77?J777???J5G#BBBG7!!7??";openBagArray[1][2]="      \033[0m║";
openBagArray[2][0]="║ │";openBagArray[2][1]=nEnemy;openBagArray[2][2]="      Lv. ";openBagArray[2][3]=to_string(nMonster1Level);openBagArray[2][4]="    │                                   ";openBagArray[2][5]="J??JJJ?777?7!!777?5GGGBBBBBGGG7777!";openBagArray[2][6]="      \033[0m║";
openBagArray[3][0]="║ │ ";openBagArray[3][1]=nEnemyIcon;openBagArray[3][2]="     💗";openBagArray[3][3]=nEnemyHealth;openBagArray[3][4]=" │                                   ";openBagArray[3][5]="JJ?77777?7?J?JY55PGGB#BBB##B##Y~~~~";openBagArray[3][6]="      \033[0m║";
openBagArray[4][0]="║ └─────────────────────┘                                   ";openBagArray[4][1]="GP55Y5PGBGGPPGGPGGP?!~YB&##BB#5:^^~";openBagArray[4][2]="      \033[0m║";
openBagArray[5][0]="║                                                           ";openBagArray[5][1]="P#BBBB#B####BPGB##. !..B#P@#PB7::::";openBagArray[5][2]="      \033[0m║";
openBagArray[6][0]="║         ❤️  ■                                              ";openBagArray[6][1]="?G&BBBB####7:! ^#&BYJ5G#G5@&PG:..::";openBagArray[6][2]="      \033[0m║";
openBagArray[7][0]="║                                                           ";openBagArray[7][1]="7?#&##&&#B#~.J:J#GGPPYB5#&&P#?....:";openBagArray[7][2]="      \033[0m║";
openBagArray[8][0]="║                                                           ";openBagArray[8][1]="?7?G&&#GG&PG5YGBB!#&Y~@@@PGBB::::::";openBagArray[8][2]="      \033[0m║";
openBagArray[9][0]="║                                                           ";openBagArray[9][1]="7!!~7G&BG#5B&Y&@@@@@&&@@&BG#7::::::";openBagArray[9][2]="      \033[0m║";
openBagArray[10][0]="║                                                           ";openBagArray[10][1]="?7!!~~?G##PB#BJBJ@@@@@#YPP#?^^^^^^^";openBagArray[10][2]="      \033[0m║";
openBagArray[11][0]="║       ^#&~     :75B#&&@@&&BP?^     !&#^                   ";openBagArray[11][1]="7!!~~^^:^!YB#&GYG#P5#G5PB&P~^^^^^::";openBagArray[11][2]="      \033[0m║";
openBagArray[12][0]="║      7@@@@&7~G&@@@@@@@@@@@@@@@@B!!&@@@@!                  ";openBagArray[12][1]="?7!~~^!??^::~?5P&&####&&&#&&B5YJ~::";openBagArray[12][2]="      \033[0m║";
openBagArray[13][0]="║       .5@@@@@@@@@#P?!~^^~7YG&@@@@@@@@Y.                   ";openBagArray[13][1]="?777!5#G!75GY!!G##&&&&&&&######BP57";openBagArray[13][2]="      \033[0m║";
openBagArray[14][0]="║         P@@@@@G~             :Y&@@@@&.                    ";openBagArray[14][1]="?J#5P#&JP#&!~5#&#&&&&&&&&&###&##BBB";openBagArray[14][2]="      \033[0m║";
openBagArray[15][0]="║        #@@@@G.                  ?@@@@@^                                                            ║";
openBagArray[16][0]="║       B@@@@7                     .&@@@@.                                                           ║";
openBagArray[17][0]="║      ~@@@@P                       ^@@@@P                                                           ║";
openBagArray[18][0]="║      5@@@@:                        &@@@&                                                           ║";
openBagArray[19][0]="║      5@@@@:                        &@@@&                                                           ║";
openBagArray[20][0]="║      ^@@@@Y                       ^@@@@5                                                           ║";
openBagArray[21][0]="║       G@@@@!                     .&@@@&.                                                           ║";
openBagArray[22][0]="║        B@@@@5.                  7@@@@&:                                                            ║";
openBagArray[23][0]="║         5@@@@@P^             .?&@@@@#                                     ┌─────────────────────┐  ║";
openBagArray[24][0]="║       .Y&@@@@@@@@BY!^^::^~?P&@@@@@@@@G:                                   │You         ";openBagArray[24][1]="Lv. ";openBagArray[24][2]="1";openBagArray[24][3]="    │  ║";
openBagArray[25][0]="║      ~@@@@B^~G&@@@@@@@@@@@@@@@@B7~B@@@@?                                  │ ¤      💗";openBagArray[25][1]=nPlayerHealth;openBagArray[25][2]=" │  ║";
openBagArray[26][0]="║       :BB:     :?P#&@@@@@&#GJ^.    ^#&^                                   └─────────────────────┘  ║";
openBagArray[27][0]="║            ╔════════════════════════╗         ╔═══════════════════════════════════╗                ║";
openBagArray[28][0]="║            ║                        ║         ║                  │                ║                ║";
openBagArray[29][0]="║            ║   What will            ║         ║   ";openBagArray[29][1]="→";openBagArray[29][2]=" ";openBagArray[29][3]=wOnes;openBagArray[29][4]="       │  ";openBagArray[29][5]=" ";openBagArray[29][6]=" ";openBagArray[29][7]=wTwos;openBagArray[29][8]="      ║                ║";
openBagArray[30][0]="║            ║    You do?             ║         ║───────────────────────────────────║                ║";
openBagArray[31][0]="║            ║                        ║         ║   ";openBagArray[31][1]=" ";openBagArray[31][2]=" ";openBagArray[31][3]=wThrees;openBagArray[31][4]="       │  ";openBagArray[31][5]=" ";openBagArray[31][6]=" [R]UN 🏃";openBagArray[31][7]="    ║                ║";
openBagArray[32][0]="║            ╚════════════════════════╝         ╚═══════════════════════════════════╝                ║";
openBagArray[33][0]="══════════════════════════════════════════════════════════════════════════════════════════════════════";

openBagArray[1][1]=battleArray[1][1]; //="\033[31mJY55YJ??JJJ77?J777???J5G#BBBG7!!7??";
openBagArray[2][5]=battleArray[2][5];
openBagArray[3][5]=battleArray[3][5];
openBagArray[4][1]=battleArray[4][1];
openBagArray[5][1]=battleArray[5][1];
openBagArray[6][1]=battleArray[6][1];
openBagArray[7][1]=battleArray[7][1];
openBagArray[8][1]=battleArray[8][1];
openBagArray[9][1]=battleArray[9][1];
openBagArray[10][1]=battleArray[10][1];
openBagArray[11][1]=battleArray[11][1];
openBagArray[12][1]=battleArray[12][1];
openBagArray[13][1]=battleArray[13][1];
openBagArray[14][1]=battleArray[14][1];

openBagArray[31][6]=" GO BACK ";

//openBagArray[29][3]=wOnes;
if(bagslot1==0){openBagArray[29][3]="      ";}
if(bagslot1==1){openBagArray[29][3]="2x dmg";}
if(bagslot1==2){openBagArray[29][3]="elixir";}
if(bagslot1==3){openBagArray[29][3]="speed+";}

//openBagArray[29][7]=wTwos;
if(bagslot2==0){openBagArray[29][7]="      ";}
if(bagslot2==1){openBagArray[29][7]="2x dmg";}
if(bagslot2==2){openBagArray[29][7]="elixir";}
if(bagslot2==3){openBagArray[29][7]="speed+";}

//openBagArray[31][3]=wThrees;
if(bagslot3==0){openBagArray[31][3]="      ";}
if(bagslot3==1){openBagArray[31][3]="2x dmg";}
if(bagslot3==2){openBagArray[31][3]="elixir";}
if(bagslot3==3){openBagArray[31][3]="speed+";}

for(int tx=0;tx<34;tx++){
  for(int yx=0;yx<9;yx++){
    cout << openBagArray[tx][yx];
  }
  cout << endl;
}
cout << "end\n";
char cbv;
      while (read(STDIN_FILENO, &cbv, 1) == 1 && cbv != 'q') {
        switch(cbv){
          case 's':
          {
            wfl2=0;
            if(bagslot1==0){openBagArray[29][3]="      ";}
            if(bagslot2==0){openBagArray[29][7]="      ";}
            if(openBagArray[29][1]=="→"){
              openBagArray[29][1]=" ";
              openBagArray[31][1]="→";
        //    ax=31;
        //    ay=1;
        //    printBattleArray();
              std::system("clear");
              for(int tx=0;tx<34;tx++){
                for(int yx=0;yx<9;yx++){
                  cout << openBagArray[tx][yx];
                }
                cout << endl;
              }
              cout << "end\n";
              break;
            }//end if
            if(openBagArray[31][1]=="→"){}
            if(openBagArray[31][5]=="→"){}
            if(openBagArray[29][5]=="→"){
              openBagArray[29][5]=" ";
              openBagArray[31][5]="→";
              std::system("clear");
              for(int tx=0;tx<34;tx++){
                for(int yx=0;yx<9;yx++){
                  cout << openBagArray[tx][yx];
                }
                cout << endl;
              }
              cout << "end\n";
              break;
            }//end if
          }//case s

          case 'w':
          {
            wfl2=0;
            if(bagslot1==0){openBagArray[29][3]="      ";}
            if(bagslot2==0){openBagArray[29][7]="      ";}
            if(openBagArray[31][1]=="→"){
              openBagArray[31][1]=" ";
              openBagArray[29][1]="→";
              std::system("clear");
              for(int tx=0;tx<34;tx++){
                for(int yx=0;yx<9;yx++){
                  cout << openBagArray[tx][yx];
                }
                cout << endl;
              }
              cout << "end\n";
              break;
            }//end if
            if(openBagArray[31][5]=="→"){
              openBagArray[31][5]=" ";
              openBagArray[29][5]="→";
              std::system("clear");
              for(int tx=0;tx<34;tx++){
                for(int yx=0;yx<9;yx++){
                  cout << openBagArray[tx][yx];
                }
                cout << endl;
              }
              cout << "end\n";
              break;
            }//end if
            if(openBagArray[29][1]=="→"){}
            if(openBagArray[29][5]=="→"){}
          }//case w

          case 'a':
          {
            wfl2=0;
            if(bagslot1==0){openBagArray[29][3]="      ";}
            if(bagslot2==0){openBagArray[29][7]="      ";}
            if(openBagArray[31][1]=="→"){}
            if(openBagArray[29][1]=="→"){}
            if(openBagArray[31][5]=="→"){
              openBagArray[31][5]=" ";
              openBagArray[31][1]="→";
              std::system("clear");
              for(int tx=0;tx<34;tx++){
                for(int yx=0;yx<9;yx++){
                  cout << openBagArray[tx][yx];
                }
                cout << endl;
              }
              cout << "end\n";
              break;
            }//end if
            if(openBagArray[29][5]=="→"){
              openBagArray[29][5]=" ";
              openBagArray[29][1]="→";
              std::system("clear");
              for(int tx=0;tx<34;tx++){
                for(int yx=0;yx<9;yx++){
                  cout << openBagArray[tx][yx];
                }
                cout << endl;
              }
              cout << "end\n";
              break;
            }//end if
          }//case a

          case 'd':
          {
            wfl2=0;
            if(bagslot1==0){openBagArray[29][3]="      ";}
            if(bagslot2==0){openBagArray[29][7]="      ";}
            if(openBagArray[31][5]=="→"){}
            if(openBagArray[29][5]=="→"){}
            if(openBagArray[31][1]=="→"){
              openBagArray[31][1]=" ";
              openBagArray[31][5]="→";
              std::system("clear");
              for(int tx=0;tx<34;tx++){
                for(int yx=0;yx<9;yx++){
                  cout << openBagArray[tx][yx];
                }
                cout << endl;
              }
             // cout << "end\n";
              break;
            }//end if
            if(openBagArray[29][1]=="→"){
              openBagArray[29][1]=" ";
              openBagArray[29][5]="→";
              std::system("clear");
              for(int tx=0;tx<34;tx++){
                for(int yx=0;yx<9;yx++){
                  cout << openBagArray[tx][yx];
                }
                cout << endl;
              }
              //cout << "end\n";
              break;
            }//end if
            break;
          }//case d

          case '\n':
          {
            if(wfl2==0){
              if(openBagArray[29][1]=="→"){
                if(openBagArray[29][3]=="      "){}
                if(openBagArray[29][3]=="2x dmg"){

                  potion2xa=3;
                  if(nWeapons>=1){wOneAttack=wOneAttack*2;}
                  if(nWeapons>=2){wTwoAttack=wTwoAttack*2;}
                  if(nWeapons==3){wThreeAttack=wThreeAttack*2;}
                  potion2x = 0;
                  std::system("clear");
                  potion2xan=1;
                  bagslot1=0;
                  if(bagslot2!=0){bagslot1=bagslot2;bagslot2=0;}
                  if(bagslot3!=0){bagslot2=bagslot3;bagslot3=0;}
                  openBagArray[29][3]="active";
                  for(int tx=0;tx<34;tx++){
                    for(int yx=0;yx<9;yx++){
                      cout << openBagArray[tx][yx];
                    }
                    cout << endl;
                  }
                  cout << "...Press Enter To Continue...\n";
                  getchar();
                  if(bagslot1==0){openBagArray[29][3]="      ";}
                  if(bagslot1==1){openBagArray[29][3]="2x dmg";}
                  if(bagslot1==2){openBagArray[29][3]="elixir";}
                  if(bagslot1==3){openBagArray[29][3]="speed+";}
                  if(bagslot2==0){openBagArray[29][7]="      ";}
                  if(bagslot2==1){openBagArray[29][7]="2x dmg";}
                  if(bagslot2==2){openBagArray[29][7]="elixir";}
                  if(bagslot2==3){openBagArray[29][7]="speed+";}
                  if(bagslot3==0){openBagArray[31][3]="      ";}
                  if(bagslot3==1){openBagArray[31][3]="2x dmg";}
                  if(bagslot3==2){openBagArray[31][3]="elixir";}
                  if(bagslot3==3){openBagArray[31][3]="speed+";}
                  return;
                }//end 2x damage
                if(openBagArray[29][3]=="elixir"){
                  if(playerLife==100){
                    openBagArray[29][3]="failed";
                    std::system("clear");

                    for(int tx=0;tx<34;tx++){
                      for(int yx=0;yx<9;yx++){
                        cout << openBagArray[tx][yx];
                      }
                      cout << endl;
                    }
                    cout << "You are already at full life...Press Enter To Continue...\n";
                    getchar();
                    return;
                  }//end if players aleady full life
                  healthelixir=0;
                  nPlayerHealth = "■■■■■■■■■■";
                  playerLife = 100;
                  battleArray[25][1]=nPlayerHealth;
                  bagslot1=0;
                  if(bagslot2!=0){bagslot1=bagslot2;bagslot2=0;}
                  if(bagslot3!=0){bagslot2=bagslot3;bagslot3=0;}
                  openBagArray[29][3]="active";
                  std::system("clear");
                  for(int tx=0;tx<34;tx++){
                    for(int yx=0;yx<9;yx++){
                      cout << openBagArray[tx][yx];
                    }
                    cout << endl;
                  }
                  cout << "...Press Enter To Continue...\n";
                  getchar();
                  if(bagslot1==0){openBagArray[29][3]="      ";}
                  if(bagslot1==1){openBagArray[29][3]="2x dmg";}
                  if(bagslot1==2){openBagArray[29][3]="elixir";}
                  if(bagslot1==3){openBagArray[29][3]="speed+";}
                  if(bagslot2==0){openBagArray[29][7]="      ";}
                  if(bagslot2==1){openBagArray[29][7]="2x dmg";}
                  if(bagslot2==2){openBagArray[29][7]="elixir";}
                  if(bagslot2==3){openBagArray[29][7]="speed+";}
                  if(bagslot3==0){openBagArray[31][3]="      ";}
                  if(bagslot3==1){openBagArray[31][3]="2x dmg";}
                  if(bagslot3==2){openBagArray[31][3]="elixir";}
                  if(bagslot3==3){openBagArray[31][3]="speed+";}
                  return;
                }//end elixir
                if(openBagArray[29][3]=="speed+"){
                  speedpotiona=3;
                  if(nWeapons>=1){wOneSpeed=wOneSpeed*2;}
                  if(nWeapons>=2){wTwoSpeed=wTwoSpeed*2;}
                  if(nWeapons==3){wThreeSpeed=wThreeSpeed*2;}
                  bagslot1=0;
                  if(bagslot2!=0){bagslot1=bagslot2;bagslot2=0;}
                  if(bagslot3!=0){bagslot2=bagslot3;bagslot3=0;}

                  openBagArray[29][3]="active";
                  std::system("clear");
                  for(int tx=0;tx<34;tx++){
                    for(int yx=0;yx<9;yx++){
                      cout << openBagArray[tx][yx];
                    }
                    cout << endl;
                  }
                  cout << "...Press Enter To Continue...\n";
                  getchar();
                  if(bagslot1==0){openBagArray[29][3]="      ";}
                  if(bagslot1==1){openBagArray[29][3]="2x dmg";}
                  if(bagslot1==2){openBagArray[29][3]="elixir";}
                  if(bagslot1==3){openBagArray[29][3]="speed+";}
                  if(bagslot2==0){openBagArray[29][7]="      ";}
                  if(bagslot2==1){openBagArray[29][7]="2x dmg";}
                  if(bagslot2==2){openBagArray[29][7]="elixir";}
                  if(bagslot2==3){openBagArray[29][7]="speed+";}
                  if(bagslot3==0){openBagArray[31][3]="      ";}
                  if(bagslot3==1){openBagArray[31][3]="2x dmg";}
                  if(bagslot3==2){openBagArray[31][3]="elixir";}
                  if(bagslot3==3){openBagArray[31][3]="speed+";}
                  return;
                }//end speed
              }//end [29][1]
              if(openBagArray[29][5]=="→"){
                if(openBagArray[29][7]=="      "){}
                if(openBagArray[29][7]=="2x dmg"){
                  potion2xa=3;
                  if(nWeapons>=1){wOneAttack=wOneAttack*2;}
                  if(nWeapons>=2){wTwoAttack=wTwoAttack*2;}
                  if(nWeapons==3){wThreeAttack=wThreeAttack*2;}
                  potion2x = 0;
                  std::system("clear");
                  potion2xan=1;

                  bagslot2=0;
                  if(bagslot3!=0){bagslot2=bagslot3;bagslot3=0;}
                  openBagArray[29][7]="active";
                  for(int tx=0;tx<34;tx++){
                    for(int yx=0;yx<9;yx++){
                      cout << openBagArray[tx][yx];
                    }
                    cout << endl;
                  }
                  cout << "...Press Enter To Continue...\n";
                  getchar();
                  if(bagslot1==0){openBagArray[29][3]="      ";}
                  if(bagslot1==1){openBagArray[29][3]="2x dmg";}
                  if(bagslot1==2){openBagArray[29][3]="elixir";}
                  if(bagslot1==3){openBagArray[29][3]="speed+";}
                  if(bagslot2==0){openBagArray[29][7]="      ";}
                  if(bagslot2==1){openBagArray[29][7]="2x dmg";}
                  if(bagslot2==2){openBagArray[29][7]="elixir";}
                  if(bagslot2==3){openBagArray[29][7]="speed+";}
                  if(bagslot3==0){openBagArray[31][3]="      ";}
                  if(bagslot3==1){openBagArray[31][3]="2x dmg";}
                  if(bagslot3==2){openBagArray[31][3]="elixir";}
                  if(bagslot3==3){openBagArray[31][3]="speed+";}
                  return;
                }//end 2x damage
                if(openBagArray[29][7]=="elixir"){
                  if(playerLife==100){
                    openBagArray[29][7]="failed";
                    std::system("clear");

                    for(int tx=0;tx<34;tx++){
                      for(int yx=0;yx<9;yx++){
                        cout << openBagArray[tx][yx];
                      }
                      cout << endl;
                    }
                    cout << "You are already at full life...Press Enter To Continue...\n";
                    getchar();
                    return;
                  }//end if players aleady full life
                  healthelixir=0;
                  nPlayerHealth = "■■■■■■■■■■";
                  playerLife = 100;
                  battleArray[25][1]=nPlayerHealth;
                  bagslot2=0;
                  if(bagslot3!=0){bagslot2=bagslot3;bagslot3=0;}
                  openBagArray[29][7]="active";
                  std::system("clear");
                  for(int tx=0;tx<34;tx++){
                    for(int yx=0;yx<9;yx++){
                      cout << openBagArray[tx][yx];
                    }
                    cout << endl;
                  }
                  cout << "...Press Enter To Continue...\n";
                  getchar();
                  if(bagslot1==0){openBagArray[29][3]="      ";}
                  if(bagslot1==1){openBagArray[29][3]="2x dmg";}
                  if(bagslot1==2){openBagArray[29][3]="elixir";}
                  if(bagslot1==3){openBagArray[29][3]="speed+";}
                  if(bagslot2==0){openBagArray[29][7]="      ";}
                  if(bagslot2==1){openBagArray[29][7]="2x dmg";}
                  if(bagslot2==2){openBagArray[29][7]="elixir";}
                  if(bagslot2==3){openBagArray[29][7]="speed+";}
                  if(bagslot3==0){openBagArray[31][3]="      ";}
                  if(bagslot3==1){openBagArray[31][3]="2x dmg";}
                  if(bagslot3==2){openBagArray[31][3]="elixir";}
                  if(bagslot3==3){openBagArray[31][3]="speed+";}
                  return;
                }//end elixir
                if(openBagArray[29][7]=="speed+"){
                  speedpotiona=3;
                  if(nWeapons>=1){wOneSpeed=wOneSpeed*2;}
                  if(nWeapons>=2){wTwoSpeed=wTwoSpeed*2;}
                  if(nWeapons==3){wThreeSpeed=wThreeSpeed*2;}
                  bagslot2=0;
                  if(bagslot3!=0){bagslot2=bagslot3;bagslot3=0;}
                  openBagArray[29][7]="active";
                  std::system("clear");
                  for(int tx=0;tx<34;tx++){
                    for(int yx=0;yx<9;yx++){
                      cout << openBagArray[tx][yx];
                    }
                    cout << endl;
                  }
                  cout << "...Press Enter To Continue...\n";
                  getchar();
                  if(bagslot1==0){openBagArray[29][3]="      ";}
                  if(bagslot1==1){openBagArray[29][3]="2x dmg";}
                  if(bagslot1==2){openBagArray[29][3]="elixir";}
                  if(bagslot1==3){openBagArray[29][3]="speed+";}
                  if(bagslot2==0){openBagArray[29][7]="      ";}
                  if(bagslot2==1){openBagArray[29][7]="2x dmg";}
                  if(bagslot2==2){openBagArray[29][7]="elixir";}
                  if(bagslot2==3){openBagArray[29][7]="speed+";}
                  if(bagslot3==0){openBagArray[31][3]="      ";}
                  if(bagslot3==1){openBagArray[31][3]="2x dmg";}
                  if(bagslot3==2){openBagArray[31][3]="elixir";}
                  if(bagslot3==3){openBagArray[31][3]="speed+";}
                  return;
                }//end speed
              }//end [29][5]
if(openBagArray[31][1]=="→"){
                if(openBagArray[31][3]=="      "){}
                if(openBagArray[31][3]=="2x dmg"){

                  potion2xa=3;
                  if(nWeapons>=1){wOneAttack=wOneAttack*2;}
                  if(nWeapons>=2){wTwoAttack=wTwoAttack*2;}
                  if(nWeapons==3){wThreeAttack=wThreeAttack*2;}
                  potion2x = 0;
                  std::system("clear");
                  potion2xan=1;
                  bagslot3=0;
                  openBagArray[31][3]="active";
                  for(int tx=0;tx<34;tx++){
                    for(int yx=0;yx<9;yx++){
                      cout << openBagArray[tx][yx];
                    }
                    cout << endl;
                  }
                  cout << "...Press Enter To Continue...\n";
                  getchar();
                  if(bagslot1==0){openBagArray[29][3]="      ";}
                  if(bagslot1==1){openBagArray[29][3]="2x dmg";}
                  if(bagslot1==2){openBagArray[29][3]="elixir";}
                  if(bagslot1==3){openBagArray[29][3]="speed+";}
                  if(bagslot2==0){openBagArray[29][7]="      ";}
                  if(bagslot2==1){openBagArray[29][7]="2x dmg";}
                  if(bagslot2==2){openBagArray[29][7]="elixir";}
                  if(bagslot2==3){openBagArray[29][7]="speed+";}
                  if(bagslot3==0){openBagArray[31][3]="      ";}
                  if(bagslot3==1){openBagArray[31][3]="2x dmg";}
                  if(bagslot3==2){openBagArray[31][3]="elixir";}
                  if(bagslot3==3){openBagArray[31][3]="speed+";}
                  return;
                }//end 2x damage
                if(openBagArray[31][3]=="elixir"){
                  if(playerLife==100){
                    openBagArray[31][3]="failed";
                    std::system("clear");

                    for(int tx=0;tx<34;tx++){
                      for(int yx=0;yx<9;yx++){
                        cout << openBagArray[tx][yx];
                      }
                      cout << endl;
                    }
                    cout << "You are already at full life...Press Enter To Continue...\n";
                    getchar();
                    return;
                  }//end if players aleady full life
                  healthelixir=0;
                  nPlayerHealth = "■■■■■■■■■■";
                  playerLife = 100;
                  battleArray[25][1]=nPlayerHealth;
                  bagslot3=0;
                  openBagArray[31][3]="active";
                  std::system("clear");
                  for(int tx=0;tx<34;tx++){
                    for(int yx=0;yx<9;yx++){
                      cout << openBagArray[tx][yx];
                    }
                    cout << endl;
                  }
                  cout << "...Press Enter To Continue...\n";
                  getchar();
                  if(bagslot1==0){openBagArray[29][3]="      ";}
                  if(bagslot1==1){openBagArray[29][3]="2x dmg";}
                  if(bagslot1==2){openBagArray[29][3]="elixir";}
                  if(bagslot1==3){openBagArray[29][3]="speed+";}
                  if(bagslot2==0){openBagArray[29][7]="      ";}
                  if(bagslot2==1){openBagArray[29][7]="2x dmg";}
                  if(bagslot2==2){openBagArray[29][7]="elixir";}
                  if(bagslot2==3){openBagArray[29][7]="speed+";}
                  if(bagslot3==0){openBagArray[31][3]="      ";}
                  if(bagslot3==1){openBagArray[31][3]="2x dmg";}
                  if(bagslot3==2){openBagArray[31][3]="elixir";}
                  if(bagslot3==3){openBagArray[31][3]="speed+";}
                  return;
                }//end elixir
                if(openBagArray[31][3]=="speed+"){
                  speedpotiona=3;
                  if(nWeapons>=1){wOneSpeed=wOneSpeed*2;}
                  if(nWeapons>=2){wTwoSpeed=wTwoSpeed*2;}
                  if(nWeapons==3){wThreeSpeed=wThreeSpeed*2;}
                  bagslot3=0;
                  openBagArray[31][3]="active";
                  std::system("clear");
                  for(int tx=0;tx<34;tx++){
                    for(int yx=0;yx<9;yx++){
                      cout << openBagArray[tx][yx];
                    }
                    cout << endl;
                  }
                  cout << "...Press Enter To Continue...\n";
                  getchar();
                  if(bagslot1==0){openBagArray[29][3]="      ";}
                  if(bagslot1==1){openBagArray[29][3]="2x dmg";}
                  if(bagslot1==2){openBagArray[29][3]="elixir";}
                  if(bagslot1==3){openBagArray[29][3]="speed+";}
                  if(bagslot2==0){openBagArray[29][7]="      ";}
                  if(bagslot2==1){openBagArray[29][7]="2x dmg";}
                  if(bagslot2==2){openBagArray[29][7]="elixir";}
                  if(bagslot2==3){openBagArray[29][7]="speed+";}
                  if(bagslot3==0){openBagArray[31][3]="      ";}
                  if(bagslot3==1){openBagArray[31][3]="2x dmg";}
                  if(bagslot3==2){openBagArray[31][3]="elixir";}
                  if(bagslot3==3){openBagArray[31][3]="speed+";}
                  return;
                }//end speed
              }//end [31][1]

if(openBagArray[31][5]=="→"){
              wfl=0;
              weaponFightArray[29][3]=wOnes;
              weaponFightArray[29][7]=wTwos;
              weaponFightArray[31][3]=wThrees;
              if(nWeapons<2){weaponFightArray[29][7]="      ";}
              if(nWeapons<3){weaponFightArray[31][3]="      ";}
              battleArray[29][1]="→";
              battleArray[29][3]=" ";
              battleArray[31][1]=" ";
              battleArray[31][3]=" ";
              ax=29;
              ay=1;
              std::system("clear");
              printBattleArray();
              return;
}//end [31][3]

            }//end wfl2 (useless for now)
          }//end enter
//break;
}//end switch
continue;
}//end while
}//end openBag void

void My_class::gainExp(){
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(200ms);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end-start;
std::system("clear");
//
cout << "dis true\n";
getchar();
switch(fromthe){
  case 'l':
  {
    myPlayArea[charX][charY]=" ";
    charY--;
    myPlayArea[charX][charY]="¤";
    break;
  }
  case 'd':
  {
    myPlayArea[charX][charY]=" ";
    charY++;
    myPlayArea[charX][charY]="¤";
    break;
  }
  case 'w':
  {
    myPlayArea[charX][charY]=" ";
    charX--;
    myPlayArea[charX][charY]="¤";
    break;
  }
  case 's':
  {
    myPlayArea[charX][charY]=" ";
    charX++;
    myPlayArea[charX][charY]="¤";
    break;
  }
}//switch

if(playerExp==1){

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");


std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::cout<<" You have earned 100 experience!  Press ENTER to continue...\n";
getchar();
playerExp=2;
tempvar2="ok";
ifOK2(tempvar2);
return;
}//playerExp==1

if(playerExp==2){

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B                                                       &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B                                                       &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!                                                       &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::cout<<" You have earned 100 experience!  Press ENTER to continue...\n";
getchar();
playerExp=3;
tempvar2="ok";
ifOK2(tempvar2);
return;
}//playerExp==2)

if(playerExp==3){

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");


std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7      ~5YYYYYYYYYYYYYYY!      &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7      ~5YYYYYYYYYYYYYYY!      &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#      G@@@@@@@@@@@@@@@@@G     &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7      ~5YYYYYYYYYYYYYYY!      &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#      G@@@@@@@@@@@@@@@@@G     &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");


std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7      ~5YYYYYYYYYYYYYYY!      &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#      G@@@@@@@@@@@@@@@@@G     &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");


std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7      ~5YYYYYYYYYYYYYYY!      &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#      G@@@@@@@@@@@@@@@@@G     &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7      ~5YYYYYYYYYYYYYYY!      &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#      G@@@@@@@@@@@@@@@@@G     &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7      ~5YYYYYYYYYYYYYYY!      &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#      G@@@@@@@@@@@@@@@@@G     &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7      ~5YYYYYYYYYYYYYYY!      &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#      G@@@@@@@@@@@@@@@@@G     &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7      ~5YYYYYYYYYYYYYYY!      &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#      G@@@@@@@@@@@@@@@@@G     &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7      ~5YYYYYYYYYYYYYYY!      &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#      G@@@@@@@@@@@@@@@@@G     &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7      ~5YYYYYYYYYYYYYYY!      &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#      G@@@@@@@@@@@@@@@@@G     &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7      ~5YYYYYYYYYYYYYYY!      &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#      G@@@@@@@@@@@@@@@@@G     &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7      ~5YYYYYYYYYYYYYYY!      &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#      G@@@@@@@@@@@@@@@@@G     &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7      ~5YYYYYYYYYYYYYYY!      &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#      G@@@@@@@@@@@@@@@@@G     &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7      ~5YYYYYYYYYYYYYYY!      &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#      G@@@@@@@@@@@@@@@@@G     &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B                              &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7      ~5YYYYYYYYYYYYYYY!      &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#      G@@@@@@@@@@@@@@@@@G     &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#                              &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

    std::this_thread::sleep_for(50ms);

std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7      ~5YYYYYYYYYYYYYYY!      &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#      G@@@@@@@@@@@@@@@@@G     &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#      G@@@@@@@@@@@@@@@@@G     &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

    std::this_thread::sleep_for(50ms);
std::system("clear");

std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║ \033[32m~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :JYYYYYYYYYYYYYYY!      !YYYYYYYYYYYYYYYYY7      ~5YYYYYYYYYYYYYYY!      &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#      G@@@@@@@@@@@@@@@@@G     &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@5       5@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@G.......G@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@@@\033[0m║\n";
std::cout<<"║\033[32m@@@@5    :@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@B      P@@@@@@@@@@@@@@@@@#     &@@@@@@@@@@@@@@&7\033[0m║\n";
std::cout<<"║\033[32m@@@@5    .@@@@@@@@@@@@@@@@@B      G@@@@@@@@@@@@@@@@@#      G@@@@@@@@@@@@@@@@@G     &@@@P            \033[0m║\n";
std::cout<<"║\033[32m@@@@5     :?YYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYYY!      ~YYYYYYYYYYYYYYYJ!      &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@5                                                                              &@@@5            \033[0m║\n";
std::cout<<"║\033[32m@@@@B:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^@@@@P            \033[0m║\n";
std::cout<<"║\033[32mP@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^            \033[0m║\n";
std::cout<<"║\033[32m ~B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.             \033[0m║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"║                                                                                                    ║\n";
std::cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
playerLevel++;
std::cout<<" Level up! You are now Level "<<playerLevel<<".  Press ENTER to continue...\n";
getchar();
playerExp=1;
tempvar2="ok";
ifOK2(tempvar2);
return;
}//if playerExp==3

return;
}

void My_class::anAbility(){
cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout<<"║                                                             \033[33m.^^::::::::::::::::::^~!^.             \033[0m║\n";
cout<<"║                                             \033[31m.::^~~~~~^:.. \033[33m.^^......::::::::::::^~!!^.              \033[0m║\n";
cout<<"║                                       \033[31m.~J5PPP5YYJJJJJJY5P!\033[33m:......::::::::::::^!!!^.                \033[0m║\n";
cout<<"║                                   \033[31m.7PBG5?!^^::::::::::^^\033[33m:.......::::::::::^~!!~:                   \033[0m║\n";
cout<<"║                                \033[31m.7B@&57!~!!!!!!!!!!!!!~\033[33m:........:::::::::^~!!~.                     \033[0m║\n";
cout<<"║                              \033[31m.5@@@G??JJJJJJJJJJJJJ7~\033[33m:.........::::::::^!!!^.                       \033[0m║\n";
cout<<"║                            \033[31m.P@@@@@PPPPPPPPPPPPP5J~\033[33m:..........:::::::\033[31m~Y&@G.                         \033[0m║\n";
cout<<"║                           \033[31m7@@@@@@@&BBBBBBBBB#BY~\033[33m............::::::\033[31m!P&@@@@&~                        \033[0m║\n";
cout<<"║                          \033[31mG@@@@@@@@@@&&&&&&&#5~\033[33m.............::::\033[31m^7B@@@@@@@@@Y                       \033[0m║\n";
cout<<"║                         \033[31m#@@@@@@@@@@@@@@@@&5~\033[33m..............:::\033[31m~Y&@@@@@@@@@@@@P                      \033[0m║\n";
cout<<"║                        \033[31mB@@@@@@@@@@@@@@@&5^\033[33m...............::\033[31m^!5B#BBBBBBBBBBB&@5                     \033[0m║\n";
cout<<"║                       \033[31m?@@@@@@@@@@@@@@&Y\033[33m:................::::::::::::::::\033[31m~JB@@@~                    \033[0m║\n";
cout<<"║                      \033[31m.@@@@@@@@@@@@@@\033[33mBY7777!!!!~~!~^:...::::::::::::::\033[31m^7G@@@@@@&                    \033[0m║\n";
cout<<"║                      \033[31m7@@@@@@@@@@@@@@@@@@@@@@@@@@\033[33mB7^...:::::::::::::\033[31m!5&@@@@@@@@@^                   \033[0m║\n";
cout<<"║                      \033[31mP@@@@@@@@@@@@@@@@@@@@@@@@\033[33mB7:...::::::::::::\033[31m~J#@@@@@@@@@@@@?                   \033[0m║\n";
cout<<"║                      \033[31mG@@@@@@@@@@@@@@@@@@@@@@\033[33mG!.....::::::::::\033[31m^7G@@@@@@@@@@@@@@@J                   \033[0m║\n";
cout<<"║                      \033[31m5@@@@@@@@@@@@@@@@@@@@\033[33mP~......:::::::::\033[31m!5&@@@@@@@@@@@@@@@@@7                   \033[0m║\n";
cout<<"║                      \033[31m~@@@@@@@@@@@@@@@@@&\033[33m5^.......:::::::\033[31m~J#@@@@@@@@@@@@@@@@@@@@:                   \033[0m║\n";
cout<<"║                       \033[31m&@@@@@@@@@@@@@@&\033[33mY^.........::::\033[31m^7G@@@@@@@@@@@@@@@@@@@@@@B                    \033[0m║\n";
cout<<"║                       \033[31m!@@@@@@@@@@@@&J\033[33m:...........::\033[31m!5&@@@@@@@@@@@@@@@@@@@@@@@@:                    \033[0m║\n";
cout<<"║                        \033[31m5@@@@@@@@@#?\033[33m:...........:\033[31m~Y#@@@@@@@@@@@@@@@@@@@@@@@@@@7                     \033[0m║\n";
cout<<"║                         \033[31m5@@@@@@B7\033[33m............:\033[31m~!5GBGGGGGPPPG&@@@@@@@@@@@@@@@?                      \033[0m║\n";
cout<<"║                          \033[31m?@@@G~\033[33m.............:::::::::::\033[31m^!JG&@@@@@@@@@@@@@@@!                       \033[0m║\n";
cout<<"║                           \033[31m:GG5YYYJYY7~\033[33m:....:::::::::\033[31m~JG&@@@@@@@@@@@@@@@@@B.                        \033[0m║\n";
cout<<"║                             \033[31m7&@@@@@P~\033[33m:....::::::\033[31m~?P&@@@@@@@@@@@@@@@@@@@#~                          \033[0m║\n";
cout<<"║                               \033[31m!#@P~\033[33m........:\033[31m^7P#@@@@@@@@@@@@@@@@@@@@@B~                            \033[0m║\n";
cout<<"║                                \033[33m:~......:\033[31m^75#@@@@@@@@@@@@@@@@@@@@@@#J.                              \033[0m║\n";
cout<<"║                              \033[33m:^:...::\033[31m^7B@@@@@@@@@@@@@@@@@@@@@@&P!.                                 \033[0m║\n";
cout<<"║                            \033[33m:^:..:^~!!~~^~?\033[31m5G#&@@@@@@@@&&#GY7^.                                     \033[0m║\n";
cout<<"║                          \033[33m.^::^~!!!^:.          \033[31m.......                                             \033[0m║\n";
cout<<"║                        \033[33m.~~^!7!~:.                                                                  \033[0m║\n";
cout<<"║                       \033[33m^^::~^.                                                                      \033[0m║\n";
cout<<"║════════════════════════════════════════════════════════════════════════════════════════════════════║\n";
cout<<"You have discovered the magic ability: Lightning Strike!  Press ENTER to continue...\n";
getchar();
aOfChoice=1;
tempvar2="ok";
ifOK2(tempvar2);
}//anAbility void

void My_class::abilityFight(){
std::system("clear");
    auto start2 = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(50ms);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end2-start2;
//cout << "abilityfight\n";
battleArray[31][2]=" [̶M̶]̶A̶G̶I̶C̶ ✨   │  ";

cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout<<"║7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777║\n";
cout<<"║7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777║\n";
cout<<"║7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777║\n";
cout<<"║7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777║\n";
cout<<"║7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777║\n";
cout<<"║7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777║\n";
cout<<"║7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777║\n";
cout<<"║7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777║\n";
cout<<"║7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777║\n";
cout<<"║7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777║\n";
cout<<"║7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777║\n";
cout<<"║7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777║\n";
cout<<"║7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777║\n";
cout<<"║77777777777777777777777777777777777!!!!!!!!!!!!!!!!!!!!!!!!!!!77777777777777777777777777777777777777║\n";
cout<<"║7777777777777777777777!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!77777777777777777777777777║\n";
cout<<"║777777777777777!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!77777777777777777║\n";
cout<<"║777777777!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!77777777777║\n";
cout<<"║7777!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!777777║\n";
cout<<"║!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!~~~!~!~~!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!777║\n";
cout<<"║!!!!!!!!!!!!!!!!!!!!!!!!!!!!!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!║\n";
cout<<"║!!!!!!!!!!!!!!!!!!!!!!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!!!!!!!!!!!!!!!!!!!!!!!!!║\n";
cout<<"║!!!!!!!!!!!!!!!!!!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!!!!!!!!!!!!!!!!!!!!║\n";
cout<<"║!!!!!!!!!!!!!!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!!!!!!!!!!!!!!!!!║\n";
cout<<"║!!!!!!!!!!!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!!!!!!!!!!!!!║\n";
cout<<"║!!!!!!!!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^^^^^:..:^^^^^^^^^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!!!!!!!!!!!║\n";
cout<<"║!!!!!!!~~~~~~~~~~~~~~~~~~~~~~~~~~^^^^^^^^^^^.   .:^^^^^^^^^^^^^^~~~~~~~~~~~~~~~~~~~~~~~~~~~!!!!!!!!!║\n";
cout<<"║!!!!!~~~~~~~~~~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^:... .:^^^^^^^^^^^^^^^^^~~~~~~~~~~~~~~~~~~~~~~~!!!!!!!!!║\n";
cout<<"║!!!!~~~~~~~~~~~~~~~~~~~~~~~^^^^^^^^^^^^:::^::..::..::::^^^^^^^^^^^^^^^~~~~~~~~~~~~~~~~~~~~~~~!!!!!!!║\n";
cout<<"║!!!!~~~~~~~~~~~~~~~~~~~~~^^^^^^^^^^^^^::.....  .............:::^^^^^^^^^^~~~~~~~~~~~~~~~~~~~~!!!!!!!║\n";
cout<<"║!!!!~~~~~~~~~~~~~~~~~~~~^^^^^^^^^:::::.....               ....::::::^^^^^^~~~~~~~~~~~~~~~~~~~~!!!!!!║\n";
cout<<"║!!!~~~~~~~~~~~~~~~~~~~~~~^^^^^^^^^^::::..... ..  ....     ...::::^^^^^^^^^~~~~~~~~~~~~~~~~~~~~!!!!!!║\n";
cout<<"║!!!~~~~~~~~~~~~~~~~~~~~~~~^^^^^^^^^^^^^::::::::::::::::::::::::^^^^^^^^~~~~~~~~~~~~~~~~~~~~~~!!!!!!!║\n";
cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(75ms);
std::system("clear");

cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout<<"║YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY║\n";
cout<<"║YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY║\n";
cout<<"║YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY║\n";
cout<<"║YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY║\n";
cout<<"║YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY║\n";
cout<<"║YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY║\n";
cout<<"║YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY║\n";
cout<<"║YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY║\n";
cout<<"║YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY║\n";
cout<<"║YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY║\n";
cout<<"║YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY║\n";
cout<<"║YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY║\n";
cout<<"║YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY║\n";
cout<<"║YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY║\n";
cout<<"║YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY║\n";
cout<<"║YYYYYYYYYYYYYYYYYYYYYYYYYYYJYYJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY║\n";
cout<<"║YYYYYYYYYYYYYYYYYYYYJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJYYYYYYYYYYYYYYYYYYYYYYYYY║\n";
cout<<"║YYYYYYYYYYYYYJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJYYYYYYYYYYYYYYYYY║\n";
cout<<"║YYYYYYYYYJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJYYYYYYYYYYYY║\n";
cout<<"║YYYYJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJYYYYYYYY║\n";
cout<<"║YJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ??JJJJ?J???JJJJJ?JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJYYYY║\n";
cout<<"║JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ???????????????????????????????????JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJY║\n";
cout<<"║JJJJJJJJJJJJJJJJJJJJJJJJJ?????????????????7~^!???????????????????????????JJJJJJJJJJJJJJJJJJJJJJJJJJJ║\n";
cout<<"║JJJJJJJJJJJJJJJJJJJJJ?????????????????????::~7?????????????????????????????J?JJJJJJJJJJJJJJJJJJJJJJJ║\n";
cout<<"║JJJJJJJJJJJJJJJJJ?????????????????????????7!!????77????????????????????????????JJJJJJJJJJJJJJJJJJJJJ║\n";
cout<<"║JJJJJJJJJJJJJJJ?????????????????????????????77???7!7???????????????????????????????JJJJJJJJJJJJJJJJJ║\n";
cout<<"║JJJJJJJJJJJJJJ????????????????????????????7?7!77777!7??7?????????????????????????????JJJJJJJJJJJJJJJ║\n";
cout<<"║JJJJJJJJJJJ?????????????????????????77777777!!77777!7!7777777????????????????????????JJJJJJJJJJJJJJJ║\n";
cout<<"║JJJJJJJJJJ????????????????????????7777777!~~:::^~!!^:::::^^~777???????????????????????JJJJJJJJJJJJJJ║\n";
cout<<"║JJJJJJJJJJ?????????????????????7777777777!~^^^:......:^^~!!7777777????????????????????JJJJJJJJJJJJJJ║\n";
cout<<"║JJJJJJJJJJ??????????????????????7777777777!!!!!!~^^~~~~~!!!777777????????????????????JJJJJJJJJJJJJJJ║\n";
cout<<"║JJJJJJJJJJ?????????????????????????7777777777777~!77777777777777??????????????????????JJJJJJJJJJJJJJ║\n";
cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(75ms);
std::system("clear");

cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5Y&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B~:5&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G.:P&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B~J#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&P:7#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B! 7#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@&P!~Y#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#BP?^!YYJJP&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#?. :!7?5#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#J!5#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&GY5Y#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G^ 7#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B~ .Y&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&#J  ~PB#&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&B?  :?PP&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&B!.. ^JB&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&BP5~  ^?P#&&&&#&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#5J~. .~!5PJP#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@║\n";
cout<<"║@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##GP?^    :JB#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##################BG5Y:  ^YB#######&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&#################B#####BGBG7  ~P###############&&&&&&&&&&&&&&&&&&&&&&&&&&&@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&#####################G?G###BPBB? :?G####################&&&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&&&&#######################BG5B##BPPY:7G########################&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&############################GB###B5^!GBB###########################&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&###############################BBBGG!.?Y?5B############################&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&#######################BBBBBGBBBBB5J?!!^?JPBBBBBGGB######################&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&####################BBBBBBBBGPY77??77~7Y?JJY55555YPBBBBBB##################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&#################BBBBBBGGGGPP5J!!~^:. .....:~7JY5PPPGGGGBBBBB##############&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&##################BBBBBBBBGGPP5YJJ???????7!!!7?Y5PGGBBBBBBB################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&######################BBBBBBBBBBBBBBBGJPGBBBGGGGGGGBBBB####################&&&&&&&&&&&&&&║\n";
cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(75ms);
std::system("clear");

cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#P?: :7!5&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#5Y7^  :?GP!5&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B?.   :JB&@#YJB&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5!.   ~G&@@@@&BJ#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&GGP^  !B&@@@@#P5&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&P^  !G&@##&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G~  ^P&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@&G~  ^G&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@&@@&G^  ?#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@G5B&@@&B~  ^B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G?G&&#?   :G&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@BYPBB?    !B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#GJ~     J#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#Y.^?: ^P&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&PP5^  :Y#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&@@&#GY^  ~5#&&@&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&#P:   ~JG&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#J.    :?G#&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#5^.~^. .^!JP#&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#B5BBG5!:  .~5B&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@║\n";
cout<<"║@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#G?.  .5#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&####################&&##B5:.^YB####&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&#########################B5Y?~~^~JG############&&&&&&&&&&&&&&&&&&&&&&&&&&&@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&########################BY!~!!^:~?55GB##################&&&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&&&&#########################BP: .^~JPB###BGPB##################&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&#############################GJ^.~PB###BPYYPB######################&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&#############################G55GGJ::?PBGPGBB##########################&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&######################BBBBGGGGP5Y5PG5~.?PGPY??YPPGBB#####################&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&##################BBBBBBBGGP5Y?~^~^^!77~7?7!!~!7?JYPGGBBBBBB###############&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&##############BBBBBGGGPP5JYJ?7!^:.          ..:^!7?JY55PPGGGBBBB###########&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&###############BBBBBGGGGPP5YJ?!~~^^^^^^^^^::::^~7JY5PPPGGGBBBB#############&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&####################BBBBBBBGGGGPPPPPP5555PPPPP555PPGBBBBB##################&&&&&&&&&&&&&&║\n";
cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(75ms);
std::system("clear");

cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#BBBBGPJ^ :JB&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#GGPJ!^   !G&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@BBG^  ^7YG&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#YBY  :P&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#??7 ~5&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G~:Y#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G::5#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&Y  .!P&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5.   .7B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#PY^.  ^5&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&YYY^  ^B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#YJ5~  :G&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&BYJ^  !B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&Y5Y. ~G&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&GJ~  7G#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&B?.  .7B&@@@@@&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&#Y~:..?B####&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BG7 :!J5G5G#&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#Y.  .^?55P55P#&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#GB##&##&&&&#BY^.   :?G#BYG&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@║\n";
cout<<"║@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#B7^~!?!~JG#&&#GJJ!.   :YGYB#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#####B?.     :?P###PYGY:   .!YB####&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&############BJ. .??: .!JYYPB5^     7B##########&&&&&&&&&&&&&&&&&&&&&&&&&&&@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&##################B7 :5GY?~. :!?!.  .^7YGB##############&&&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&&&&####################BY. :?55GP?~:::^7YPB#GPB################&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&########################GJ7!^.^?5BBBBBB#####B######################&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&##########################GPBBG5?~:~JGBB#B#############################&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&######################BBBBGGGGGGGGP57^!5PGGGGGPY5BBBB####################&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&#################BBBBBBGGGPPYJ!~~~~~!!~:^!!!!!!77?YPPGGGBBBBBB#############&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&##############BBBGGGPP55YJ?7!~^:.             .:^~!7?JY55PPGGBBBB##########&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&###############BBBBGGGPP55YJ7~^^.::::::::::...::^!?JY55PPGGGBBB############&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&###################BBBBBBBGGPPP5Y55YYYYYYYY5555YY5PPGBBBBB#################&&&&&&&&&&&&&&║\n";
cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(75ms);
std::system("clear");

cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@║\n";
cout<<"║@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##&##&#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###################################&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&###############################################&&&&&&&&&&&&&&&&&&&&&&&&&&&@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&#########################################BGB############&&&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&&&&###########################################GG###############&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&#######################B###########################################&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&#########################BB#BBBBBBBBBBBBBBBBB##########################&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&########################BBBBBBBBBBBBBBBBBBBBBBBBBGPG#####################&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&#######################BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB######################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&######################BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB#######################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&######################BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB######################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&#######################BBBBBBBBGBBBBBBBBBBBBBBBBBBB########################&&&&&&&&&&&&&&║\n";
cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(75ms);
std::system("clear");

cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G:.!P&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#GBPJ~7P&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@BYY?:^5&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&BY5?!Y#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#&#57^:?P&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B!!?^..^Y#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#?   ^JJB&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#?  !B#55#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&P: Y#&BJG##&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#? !B&B5P5?5&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G^.5&@@#PP&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#J ^G&&GB&@&BPYYYYPB&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G: 7B&@&PGY~:.    .7B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&Y~.JP5?7!!77!!!^.  7B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#57?JY5YB&&&&&#GY!:7B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@@@&&&&GY#&&@@@@@&&G?!P&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&#PGBGP#&&&&&&&P7P&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##5P&&&&&&&&G7G&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#Y5#&&&&&&&#Y!B&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#GJB#&&&&&&&#P~G#&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@║\n";
cout<<"║@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###&&&#BJG##B##&&#G77B#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##########BJJPB###YYBP~P###P~.5####&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&###############B55PYJGBPJPG7 !5P?..YB##########&&&&&&&&&&&&&&&&&&&&&&&&&&&@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&####################GJG##BGP?PBP^  .: ^5B##B############&&&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&&&&#######################BG####BY5P! :. .?G###################&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&#############################BGGGP?~:JGPYPB########################&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&##############################BBBBG57.YBB##############################&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&#######################BBBBBBBBBBBBBP~?GBBBBBBBBBBBBB####################&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&###################BBBBBBBGGP5YYJJJYYY?555555555PPGGBBBBBB#################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&###############BBBBBBGGGGGPP55Y?7^:........:^~7JY5PPPGGGGBBBBBB############&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&#################BBBBBBBBGGPP5YYJJJJJJJJ??7777?JY5PGGBBBBBBB###############&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&######################BBBBBBBBBBBBBBBBBBBBBBBBBGGGGBBBB####################&&&&&&&&&&&&&&║\n";
cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(75ms);
std::system("clear");

cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#7 J#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&BBP!J#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B5BP7B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&BY#@@##&&Y?#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G~!GGP5GGP~?#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B! .:.:..:!Y#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#J     :!JG#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B!   :JB&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#?  .5&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G~ :G&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G~ Y&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G:7#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#7!#&@@@B5BGJJP#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5:5GPPGY.::   !B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B7JGB5~.  :~~. JPGB#&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&5!GG! :75B##5:~GBGY5&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&B7!~^JG#&&&&#5^5&&#GB&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&#Y5B&&&&&&&&#PY#&&#PP#&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##&&&&B##&#GYP&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#P!Y#&&&#G7GY5B#&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@║\n";
cout<<"║@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BY:.5##&#B7:5JP#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##############BG7. .5####B7^P?5####&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&###################G!:    ~P###G!7YYB##########&&&&&&&&&&&&&&&&&&&&&&&&&&&@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&########################B7   :: ^PBG?!PB################&&&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&&&&##########################B5:  7J: ~JYPPB###################&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&#############################BBJ. JG5~  !JG########################&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&################################BG7 ?GBG5J5GB##########################&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&######################BBBBGGGGGGGGG5^~5PGGGGGBBBBBBBB####################&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&#################BBBBBBGGGPPYJ!~~~~~~~^!!!!!!!!7?J5PPGGGGBBBBB#############&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&##############BBBGGGPP55YJ?7!~^:.             .:^~!7?JY55PPGGBBBB##########&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&###############BBBBGGGPP55YJ7~^^:::::::::::...::^!?JY55PPGGGBBB############&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&###################BBBBBBBGGPPPP555YYYYYYYY5555YY5PPGBBBBB#################&&&&&&&&&&&&&&║\n";
cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(75ms);
std::system("clear");

cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G!?B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&P..P&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B~:G&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#&@&#5~Y#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#&#BPB#BP5B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@BP5#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&P5P#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&P^ 7#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B! :P&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#J.7#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B7.P&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G^ 5&@@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G:~B&@@@@@@@&&#GGGG55#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&B!5&&@&#B#&&&&&&BG##5JB&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&#YP##BPJ:^7B&&&&&&&&#?5&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&G7!~~^:^^5#&&&&&&&#P7P#&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&BPGGBB##&&&&&&&#B??Y5&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#G7 ?B#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@║\n";
cout<<"║@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#&&&&#&&#B? ?B#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##########B##############B7 :P#####&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&##############P?JJY555557G5B###GJ ~G###########&&&&&&&&&&&&&&&&&&&&&&&&&&&@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&###################B55GGGGPJ~.Y5?5P5?J:YB###############&&&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&&&&#######################G5G##BY. 7GG5J7P5YB##################&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&###########################GJBBB5:  :JBBB#B########################&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&#############################BJPBBBJ!~ .YBB############################&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&#######################BBBBGGGGP55PGGPY~J5GBBBBBBBBB#####################&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&##################BBBBBBBBGGP5J?7!!!7?J??JJJJJJJY5PGGBBBBBBB###############&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&###############BBBBBGGGPPP5YYJ?!^:.         .:~!?JY55PPPGGGBBBB############&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&################BBBBBBGGGGP5YJ?7!~~~~!!~~~^^^^~!?Y5PPGGGGBBBB##############&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&#####################BBBBBBGGGGGGGGGPPPPPPPPPPPPPPGGBBBB###################&&&&&&&&&&&&&&║\n";
cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(75ms);
std::system("clear");

cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#G&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#7!B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&P.~G&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&B7?#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&#P?5GGP#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&GGGPYG#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@BG@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5P&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&#?5&&&&&&&&&&&#BPPB&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&P#&&&&&&&&&&#5Y5J5&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&#GPG#&&&&&&&5YB&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&BY?7^75#&&&&&&&#PYG&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#GJJG#&&&&&&&&&&&G5#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@║\n";
cout<<"║@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#&##&#&&&&#PG#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&############################B######&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&################################BJJ############&&&&&&&&&&&&&&&&&&&&&&&&&&&@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&#####################################5:YB###############&&&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&&&&##############################B########G?P##################&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&###############################BG??PGB#BBB55B######################&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&##############################BBBBP:.7J5GJYBGB#########################&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&########################BBBBBBBBBBBBP!!7?Y5GB#BBBBB######################&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&######################BBBBBBBGGP5555PPPPGGGGGGGGGBBBB######################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&##################BBBBBBBBBBBGGGPYJ7~^^^^~!?Y5PGGGBBBBBBBB#################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&####################BBBBBBBBGGGPPP555555YYYYY55PGGBBBBBB###################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&#######################BBBBBBBBBBBBBBBBBBBBBBBBGGBBBB######################&&&&&&&&&&&&&&║\n";
cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(75ms);
std::system("clear");

cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@BB&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&P#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&PP#&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&#5#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&G5&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#GB###&&&&&&&&&BG&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#P?JYG#&&&&&&&&#P#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@║\n";
cout<<"║@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BGB#####&#&&&#PB#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#############&#############G#######&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&#################################B#############&&&&&&&&&&&&&&&&&&&&&&&&&&&@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&########################################################&&&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&&&&############################################################&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&###################################################################&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&############################BBBBBBBBBBBBBBBBB##########################&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&########################BBBBBBBBBBBBBBBBBBBBBBBBBB#######################&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&#######################BBBBBBBBGGGGGGGBBBBBBBBBBBBBBB######################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&####################BBBBBBBBBBBBGGP5YYJJJY5PGGBBBBBBBBB####################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&#####################BBBBBBBBBBGGGGGGGGGGGGGGGGGBBBBBB#####################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&#######################BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB######################&&&&&&&&&&&&&&║\n";
cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(75ms);
std::system("clear");

cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@G&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&P#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&GG&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&#P#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&GP&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&B#&&#&&&&&&&&&BG&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&GYYPG#&&&&&&&&#G#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@║\n";
cout<<"║@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BB##&&##&#&&&#BB#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#############&#############G#######&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&#################################B#############&&&&&&&&&&&&&&&&&&&&&&&&&&&@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&########################################################&&&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&&&&############################################################&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&###################################################################&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&###########################BBBBBBBBBBBBBBBBBB##########################&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&########################BBBBBBBBBBBBBBBBBBBBBBBBBB#######################&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&######################BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB#######################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&#####################BBBBBBBBBBBBGGGPPPPPPGGGBBBBBBBBB#####################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&######################BBBBBBBBBBBBBBGBGGGGGGBBBBBBBBBB#####################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&#######################BBBBBBBBBBBBBBBBBBBBBBBBBBBBB#######################&&&&&&&&&&&&&&║\n";
cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(75ms);
std::system("clear");

cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#P&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&PB@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@BJ#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&@@&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&G?B&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#G#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#GPG#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@║\n";
cout<<"║@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BPP##&##&#&&&#GG#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#############&&###########G5#######&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&################################GG#############&&&&&&&&&&&&&&&&&&&&&&&&&&&@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&########################################################&&&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&&&&############################################################&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&###################################################################&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&##########################BBBBBBBBBBBBBBBBBBB##########################&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&########################BBBBBBBBBBBBBBBBBBBBBBBBB########################&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&#######################BBBBBBBBBBBBBBBBBBBBBBBBBBBBB#######################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&######################BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB######################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&######################BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB######################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&#######################BBBBBBBBBBBBBBBBBBBBBBBBBBBB########################&&&&&&&&&&&&&&║\n";
cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(75ms);
std::system("clear");

cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#P&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&@&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&BY#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#B#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#GBB#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@║\n";
cout<<"║@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BBB#&&##&#&&&&BB&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##########################GP#######&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&################################BG#############&&&&&&&&&&&&&&&&&&&&&&&&&&&@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&########################################################&&&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&&&&############################################################&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&###################################################################&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&##########################BBBBBBBBBBBBBBBBBBB##########################&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&########################BBBBBBBBBBBBBBBBBBBBBBBBB########################&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&#######################BBBBBBBBBBBBBBBBBBBBBBBBBBBBB#######################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&######################BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB######################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&######################BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB######################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&#######################BBBBBBBBBBBBBBBBBBBBBBBBBBBB########################&&&&&&&&&&&&&&║\n";
cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

std::this_thread::sleep_for(75ms);
std::system("clear");

cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@║\n";
cout<<"║@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@@║\n";
cout<<"║@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##&##&#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###################################&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&&&&&&###############################################&&&&&&&&&&&&&&&&&&&&&&&&&&&@║\n";
cout<<"║&&&&&&&&&&&&&&&&&&&&########################################################&&&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&&&&############################################################&&&&&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&&&###################################################################&&&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&&##########################BBBBBBBBBBBBBBBBBBB##########################&&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&&########################BBBBBBBBBBBBBBBBBBBBBBBBB########################&&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&#######################BBBBBBBBBBBBBBBBBBBBBBBBBBBBB#######################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&######################BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB######################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&######################BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB######################&&&&&&&&&&&&&&║\n";
cout<<"║&&&&&&&&&&&#######################BBBBBBBBBBBBBBBBBBBBBBBBBBBB########################&&&&&&&&&&&&&&║\n";
cout<<"══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

switch(aOfChoice){
  case 0:
  {
    cout << "error on ability function\n";
    break;
  }
  case 1:
  //lightning attack
  {
    cout << "You've successfully striked " << nEnemy << " with the Lightning Attack.\n";
    if (nEnemyHealth == "■■■■■■■■■■"){nEnemyHealth="■■■■■     ";break;}
    if (nEnemyHealth == "■■■■■■■■■ "){nEnemyHealth="■■■■■     ";break;}
    if (nEnemyHealth == "■■■■■■■■  "){nEnemyHealth="■■■■      ";break;}
    if (nEnemyHealth == "■■■■■■■   "){nEnemyHealth="■■■■      ";break;}
    if (nEnemyHealth == "■■■■■■    "){nEnemyHealth="■■■       ";break;}
    if (nEnemyHealth == "■■■■■     "){nEnemyHealth="■■■       ";break;}
    if (nEnemyHealth == "■■■■      "){nEnemyHealth="■■        ";break;}
    if (nEnemyHealth == "■■■       "){nEnemyHealth="■■        ";break;}
    if (nEnemyHealth == "■■        "){nEnemyHealth="■         ";break;}
    if (nEnemyHealth == "■         "){
      cout << "...Press Enter To Continue...\n";
      getchar();
      std::system("clear");
      cout << " You have successfully defeated " << nEnemy << endl;
      cout << "...Press Enter To Continue...\n";
      getchar();
      std::system("clear");
      gainExp();
      break;
    }
  }//case 1
  default:
  {
    cout << "error on ability function default\n";
    break;
  }
}//switch
weaponFightArray[3][3]=nEnemyHealth;
battleArray[3][3]=nEnemyHealth;
abilityUsed=1;
cout << "...Press Enter To Continue...\n";
getchar();
enemyTurn();

}//abiilityFight void

void My_class::runFight(){
std::system("clear");
cout << "runfight\n";
}

void My_class::miniGameDeath2(){
system("clear");

if(deathfactor==5){
  disableRawMode();
  cout << endl;
  system("clear");
  enableRawMode2();
  cout << endl;
  std::system("clear");
cout << "u dead bruh\n";
}

while(deathfactor<5){

if(deathfactor==4){
myMiniGameArray[26][12]=".";
deathfactor++;
}

if(deathfactor==3){
myMiniGameArray[26][12]="*";
deathfactor++;
}
if(deathfactor==2){
myMiniGameArray[26][12]="#";
deathfactor++;
}
if(deathfactor==1){
myMiniGameArray[26][12]="¤";
deathfactor++;
}

for(int d1=0; d1<34; d1++){
  for(int d2=0; d2<102; d2++){
    cout << myMiniGameArray[d1][d2];
  }
  cout << endl;
}



std::this_thread::sleep_for(100ms);
miniGameDeath2();
}//while deathfactor>5
}//function miniGameDeath2


void My_class::miniGameDeath(){
system("clear");

if(deathfactor==5){
  disableRawMode();
  cout << endl;
  system("clear");
  enableRawMode2();
  cout << endl;
  std::system("clear");
cout << "u dead bruh\n";
}

while(deathfactor<5){

if(deathfactor==4){
myMiniGameArray[30][12]="¤";
myMiniGameArray[29][12]=" ";
myMiniGameArray[28][12]=" ";
myMiniGameArray[27][12]=" ";
//cout << "u dead bruh\n";
deathfactor++;
}

if(deathfactor==3){
myMiniGameArray[30][12]=" ";
myMiniGameArray[29][12]="¤";
myMiniGameArray[28][12]=" ";
myMiniGameArray[27][12]=" ";
deathfactor++;
}

if(deathfactor==2){
myMiniGameArray[30][12]=" ";
myMiniGameArray[29][12]=" ";
myMiniGameArray[28][12]="¤";
myMiniGameArray[27][12]=" ";
deathfactor++;
}
if(deathfactor==1){
myMiniGameArray[30][12]=" ";
myMiniGameArray[29][12]=" ";
myMiniGameArray[28][12]=" ";
myMiniGameArray[27][12]="¤";
myMiniGameArray[26][12]=" ";
deathfactor++;
}

for(int d1=0; d1<34; d1++){
  for(int d2=0; d2<102; d2++){
    cout << myMiniGameArray[d1][d2];
  }
  cout << endl;
}



std::this_thread::sleep_for(100ms);
miniGameDeath();
}//while deathfactor>5
}



void My_class::openedDoor(){
if(deathfactor==5){return;}

  std::system("clear");
  std::random_device rd;
  std::mt19937 mgt{rd()};
  std::mt19937 mgb{rd()};
  auto ministart = std::chrono::high_resolution_clock::now();
  auto miniend = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsed = miniend-ministart;
  int nextRenderTop=0;
  int nextRenderBottom=0;
  int miniLoop=1;
//  char mgc;
//  int positiontemp=12;
int innerswitch=0;

//string myMiniGameArray[34][102];

for(int a=0; a<34; a++){
  for(int b=0; b<102; b++){
    myMiniGameArray[a][b]=" ";
  }
}

myMiniGameArray[0][0]="═";
for(int a1=0; a1 < 102; a1++){
  myMiniGameArray[0][a1]="═";
}
for(int a2=0; a2<34; a2++){
  myMiniGameArray[a2][0]="║";
}
for(int a3=0; a3<34; a3++){
  myMiniGameArray[a3][101]="║";
}
myMiniGameArray[33][0]="║";
myMiniGameArray[33][101]="║";
for(int a4=1; a4<101; a4++){
  myMiniGameArray[33][a4]="═";
}
for(int a5=1; a5<18; a5++){
  for(int b5=1; b5<101; b5++){
    myMiniGameArray[a5][b5]="█";
  }
}

myMiniGameArray[4][12]="▒";myMiniGameArray[4][13]="▒";myMiniGameArray[4][14]="░";myMiniGameArray[4][15]="░";
myMiniGameArray[5][10]="▓";myMiniGameArray[5][11]="▓";myMiniGameArray[5][12]="▒";myMiniGameArray[5][13]="▒";myMiniGameArray[5][14]="▒";myMiniGameArray[5][15]="▒";myMiniGameArray[5][16]="░";myMiniGameArray[5][17]="░";

myMiniGameArray[6][46]="▒";myMiniGameArray[6][47]="▒";myMiniGameArray[6][48]=" ";myMiniGameArray[6][49]=" ";
myMiniGameArray[7][42]="▒";myMiniGameArray[7][43]="▒";myMiniGameArray[7][44]="▒";myMiniGameArray[7][45]="▒";myMiniGameArray[7][46]="░";myMiniGameArray[7][47]="░";myMiniGameArray[7][48]=" ";myMiniGameArray[7][49]=" ";myMiniGameArray[7][50]="░";myMiniGameArray[7][51]="░";
for(int a6=40; a6<51; a6++){
  myMiniGameArray[8][a6]="▒";
}
myMiniGameArray[8][51]="░";myMiniGameArray[8][52]="░";

myMiniGameArray[11][21]=" ";myMiniGameArray[11][22]=" ";myMiniGameArray[11][23]=" ";myMiniGameArray[11][24]=" ";
myMiniGameArray[12][19]="▒";myMiniGameArray[12][20]="▒";myMiniGameArray[12][21]=" ";myMiniGameArray[12][22]=" ";myMiniGameArray[12][23]=" ";myMiniGameArray[12][24]=" ";myMiniGameArray[12][25]="░";myMiniGameArray[12][26]="░";
myMiniGameArray[13][19]="▒";myMiniGameArray[13][20]="▒";myMiniGameArray[13][21]="▒";myMiniGameArray[13][22]="▒";myMiniGameArray[13][23]="▒";myMiniGameArray[13][24]="▒";myMiniGameArray[13][25]="▒";myMiniGameArray[13][26]="▒";
myMiniGameArray[11][64]="▒";myMiniGameArray[11][65]="▒";myMiniGameArray[11][66]=" ";myMiniGameArray[11][67]=" ";myMiniGameArray[11][68]=" ";myMiniGameArray[11][69]=" ";
myMiniGameArray[12][59]="▒";myMiniGameArray[12][60]="▒";myMiniGameArray[12][61]=" ";myMiniGameArray[12][62]=" ";myMiniGameArray[12][63]=" ";myMiniGameArray[12][64]=" ";myMiniGameArray[12][65]=" ";myMiniGameArray[12][66]=" ";myMiniGameArray[12][67]=" ";myMiniGameArray[12][68]=" ";myMiniGameArray[12][69]=" ";myMiniGameArray[12][70]=" ";
myMiniGameArray[13][51]="▒";myMiniGameArray[13][52]="▒";myMiniGameArray[13][53]="░";myMiniGameArray[13][53]="░";
myMiniGameArray[13][59]="▒";myMiniGameArray[13][60]="▒";myMiniGameArray[13][61]="▒";myMiniGameArray[13][62]="▒";myMiniGameArray[13][63]="▒";myMiniGameArray[13][64]="▒";myMiniGameArray[13][65]=" ";myMiniGameArray[13][66]=" ";myMiniGameArray[13][67]=" ";myMiniGameArray[13][68]=" ";myMiniGameArray[13][69]=" ";myMiniGameArray[13][70]=" ";myMiniGameArray[13][71]=" ";myMiniGameArray[13][72]=" ";
myMiniGameArray[14][49]="▓";myMiniGameArray[14][50]="▓";myMiniGameArray[14][51]="░";myMiniGameArray[14][52]="░";myMiniGameArray[14][53]=" ";myMiniGameArray[14][54]=" ";myMiniGameArray[14][55]="░";myMiniGameArray[14][56]="░";myMiniGameArray[14][57]="░";myMiniGameArray[14][58]="░";myMiniGameArray[14][59]="▒";myMiniGameArray[14][60]="▒";myMiniGameArray[14][61]="▒";myMiniGameArray[14][62]="▒";myMiniGameArray[14][62]="░";myMiniGameArray[14][63]="░";myMiniGameArray[14][64]=" ";myMiniGameArray[14][65]=" ";myMiniGameArray[14][66]=" ";myMiniGameArray[14][67]=" ";myMiniGameArray[14][68]=" ";myMiniGameArray[14][69]=" ";myMiniGameArray[14][70]="░";myMiniGameArray[14][71]="░";myMiniGameArray[14][72]="░";myMiniGameArray[14][73]="░";myMiniGameArray[14][74]="░";myMiniGameArray[14][75]="░";
myMiniGameArray[15][47]="▒";myMiniGameArray[15][48]="▒";myMiniGameArray[15][49]="▒";myMiniGameArray[15][50]="▒";myMiniGameArray[15][51]="░";myMiniGameArray[15][52]="░";myMiniGameArray[15][53]=" ";myMiniGameArray[15][54]=" ";myMiniGameArray[15][55]=" ";myMiniGameArray[15][56]=" ";myMiniGameArray[15][57]="▒";myMiniGameArray[15][58]="▒";myMiniGameArray[15][59]="▒";myMiniGameArray[15][60]="▒";myMiniGameArray[15][61]="░";myMiniGameArray[15][62]="░";myMiniGameArray[15][63]=" ";myMiniGameArray[15][64]=" ";myMiniGameArray[15][65]=" ";myMiniGameArray[15][66]=" ";myMiniGameArray[15][67]=" ";myMiniGameArray[15][68]=" ";myMiniGameArray[15][69]="▒";myMiniGameArray[15][70]="▒";myMiniGameArray[15][71]="▒";myMiniGameArray[15][72]="▒";myMiniGameArray[15][73]=" ";myMiniGameArray[15][74]=" ";myMiniGameArray[15][75]=" ";myMiniGameArray[15][76]=" ";myMiniGameArray[15][77]="░";myMiniGameArray[15][78]="░";
for(int a7=45; a7<80; a7++){
  myMiniGameArray[16][a7]="▒";
}

for(int a8=1;a8<101;a8++){
  myMiniGameArray[27][a8]="═";
}
myMiniGameArray[27][27]=" ";myMiniGameArray[27][28]=" ";myMiniGameArray[27][29]=" ";myMiniGameArray[27][30]=" ";myMiniGameArray[27][31]=" ";
myMiniGameArray[27][66]=" ";myMiniGameArray[27][67]=" ";myMiniGameArray[27][68]=" ";myMiniGameArray[27][69]=" ";myMiniGameArray[27][70]=" ";
myMiniGameArray[26][12]="¤";

for(int d1=0; d1<34; d1++){
  for(int d2=0; d2<102; d2++){
    cout << myMiniGameArray[d1][d2];
  }
  cout << endl;
}

int anotherloopy = 1;
while(anotherloopy==1){
miniGameLoop();
std::this_thread::sleep_for(500ms);
}

}//openedDoor

void My_class::miniGameJump(){
if(jumpphase2==0){return;}
if(deathfactor==5){return;}



system("clear");
  auto minijstart = std::chrono::high_resolution_clock::now();
  auto minijend = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsed = minijend-minijstart;
std::random_device mgjd;
std::mt19937 mgj{mgjd()};
std::mt19937 mgj2{mgjd()};
std::uniform_int_distribution<int> dist{0, 9};
int renderJ=dist(mgj);
//int jumpphase2=7;
//          renderJ=dist(mge);

if(firestage>0&&firestage<30){
  myMiniGameArray[26][((firestage*3)+11)]=" ";
 // if(myMiniGameArray[26][((firestage/2)-11)]=="-"){myMiniGameArray[25][((firestage/2)-11)]=" ";}
  firestage++;
  myMiniGameArray[26][((firestage*3)+11)]="-";
}//firestage>0
if(firestage==30){
  myMiniGameArray[26][101]="║";
  firestage=0;
}


      if(jumpphase2==1){
        myMiniGameArray[26][12]="¤";
        myMiniGameArray[25][12]=" ";
        myMiniGameArray[24][12]=" ";
        myMiniGameArray[23][12]=" ";
        myMiniGameArray[22][12]=" ";
        jumpphase2--;
      }
      if(jumpphase2==2){
        myMiniGameArray[26][12]=" ";
        myMiniGameArray[25][12]="¤";
        myMiniGameArray[24][12]=" ";
        myMiniGameArray[23][12]=" ";
        myMiniGameArray[22][12]=" ";
        jumpphase2--;
      }
      if(jumpphase2==3){
        myMiniGameArray[26][12]=" ";
        myMiniGameArray[25][12]=" ";
        myMiniGameArray[24][12]="¤";
        myMiniGameArray[23][12]=" ";
        myMiniGameArray[22][12]=" ";
        jumpphase2--;
      }
      if(jumpphase2==4){
        myMiniGameArray[26][12]=" ";
        myMiniGameArray[25][12]=" ";
        myMiniGameArray[24][12]=" ";
        myMiniGameArray[23][12]="¤";
        myMiniGameArray[22][12]=" ";
        jumpphase2--;
      }
      if(jumpphase2==5){
        myMiniGameArray[26][12]=" ";
        myMiniGameArray[25][12]=" ";
        myMiniGameArray[24][12]=" ";
        myMiniGameArray[23][12]=" ";
        myMiniGameArray[22][12]="¤";
        jumpphase2--;
      }
      if(jumpphase2==6){
        myMiniGameArray[26][12]=" ";
        myMiniGameArray[25][12]=" ";
        myMiniGameArray[24][12]=" ";
        myMiniGameArray[23][12]="¤";
        myMiniGameArray[22][12]=" ";
        jumpphase2--;
      }
      if(jumpphase2==7){
        myMiniGameArray[26][12]=" ";
        myMiniGameArray[25][12]=" ";
        myMiniGameArray[24][12]="¤";
        myMiniGameArray[23][12]=" ";
        myMiniGameArray[22][12]=" ";
        jumpphase2--;
      }
      if(jumpphase2==8){

if(myMiniGameArray[27][12]==" "){
  disableRawMode();
  cout << endl;
  system("clear");
  enableRawMode2();
  cout << endl;
  std::system("clear");
deathfactor=1;
//  anappel=1;
miniGameDeath();
//  goto thereturnline;
  return;
//break;
}

        myMiniGameArray[26][12]=" ";
        myMiniGameArray[25][12]="¤";
        myMiniGameArray[24][12]=" ";
        myMiniGameArray[23][12]=" ";
        myMiniGameArray[22][12]=" ";
        jumpphase2--;
      }

myMiniGameArray[26][100]=" ";
for(int gapa1=2; gapa1<101; gapa1++){
//  if(myMiniGameArray[26][gapa1]=="¤"){myMiniGameArray[26][gapa1-1]=" ";}else{myMiniGameArray[26][gapa1-1]=myMiniGameArray[26][gapa1];}
myMiniGameArray[26][gapa1-1]=myMiniGameArray[26][gapa1];
}


        if(gapphase==0){
          if(renderJ!=2){
system("clear");
            myMiniGameArray[27][100]="═";
          }//if renderJ!=2

if(myMiniGameArray[27][100]=="═"&&myMiniGameArray[27][99]=="═"&&myMiniGameArray[27][98]==" "){

system("clear");

            myMiniGameArray[27][100]="═";
            gapphase=0;
}


if(myMiniGameArray[27][100]=="═"&&myMiniGameArray[27][99]==" "){

system("clear");

            myMiniGameArray[27][100]="═";
            gapphase=0;
}

if(myMiniGameArray[27][100]!=" "){


          if(renderJ==2){
            myMiniGameArray[27][100]=" ";
            gapphase=5;
          }//renderJ==2

}//if !=" "
else if(myMiniGameArray[27][100]==" "){
            myMiniGameArray[27][100]="═";
            gapphase=0;

}//else if ==" "

//break; //new
        }//if gapphase==0
        if(gapphase>0){
          myMiniGameArray[27][100]=" ";
          gapphase--;
        }//gapphase>0
    
system("clear");
            for(int gapa1=2; gapa1<101; gapa1++){
              myMiniGameArray[27][gapa1-1]=myMiniGameArray[27][gapa1];
            }
            for(int d1=0; d1<34; d1++){
              for(int d2=0; d2<102; d2++){
                cout << myMiniGameArray[d1][d2];
              }
              cout << endl;
            }
    
std::this_thread::sleep_for(100ms);
jumpbackin:
miniGameJump();
}//miniGameJump function

void My_class::miniGameLoop(){
if(deathfactor==5){return;}

  disableRawMode();
  cout << endl;
  system("clear");
  enableRawMode();
  cout << endl;
  std::system("clear");

std::random_device mgrd;
std::mt19937 mge{mgrd()};
std::mt19937 mge2{mgrd()};
std::uniform_int_distribution<int> dist{0, 9};
int renderB=dist(mge);
//int renderEnemy=dist(mge2);
char mgc3;
char mgc4;
//char mgc2;
int anappel=0;


//  while (read(STDIN_FILENO, &mgc2, 1) == 1 && mgc2 != 'q'){
//while(1){
while(anappel==0){

/*
if(firestage>0&&firestage<30){
  myMiniGameArray[26][((firestage*3)+11)]=" ";
 // if(myMiniGameArray[26][((firestage/2)-11)]=="-"){myMiniGameArray[25][((firestage/2)-11)]=" ";}
  firestage++;
  myMiniGameArray[26][((firestage*3)+11)]="-";
}//firestage>0
if(firestage==30){
  myMiniGameArray[26][101]="║";
  firestage=0;
}
*/

//working old
if(firestage>0&&firestage<30){
  for(int killem=(firestage+11);killem<((firestage*3)+11);killem++){
    if(myMiniGameArray[26][killem]=="X"){myMiniGameArray[26][killem]=" ";}
  }
}
//end working old

if(myMiniGameArray[26][12]=="¤"&&myMiniGameArray[27][12]==" "){
  disableRawMode();
  cout << endl;
  system("clear");
  enableRawMode2();
  cout << endl;
  std::system("clear");
deathfactor=1;
  anappel=1;
miniGameDeath();
  goto thereturnline;
  return;
//break;
}

//working
if(myMiniGameArray[26][12]=="¤"&&myMiniGameArray[26][13]=="X"){
  disableRawMode();
  cout << endl;
  system("clear");
  enableRawMode2();
  cout << endl;
  std::system("clear");
deathfactor=1;
  anappel=1;
miniGameDeath2();
  goto thereturnline;
  return;
}
//end working

  char mgc2='\0';
  read(STDIN_FILENO, &mgc2, 1);
    switch(mgc2){

case 'f':
{
//fire!
firestage=1;
break;
}//fire

case 'q':
{
  disableRawMode();
  cout << endl;
  system("clear");
  enableRawMode2();
  cout << endl;
  std::system("clear");
  anappel=1;
  tempvar2="ok";
  ifOK2(tempvar2);
  goto thereturnline;
  return;
}

      case '\0':
      {
miniGameStep++;
if(miniGameStep==40){
  disableRawMode();
  cout << endl;
  system("clear");
  enableRawMode2();
  cout << endl;
  std::system("clear");
  anappel=1;
  passphase=12;
  finishedMiniGame();
  goto thereturnline;
  return;

}

        system("clear");
        renderB=dist(mge);
        if(gapphase==0){
          if(renderB!=2){
            if(lastenemy==1){
              myMiniGameArray[25][100]=" ";
              lastenemy=0;
              goto skiptheenemy;
            }
            if(lastenemy==0){
              renderEnemy=dist(mge2);
              if(renderEnemy==3){
//                myMiniGameArray[25][100]="X";
                lastenemy=1;
                //break;
              }
            }//lastenemy==0
skiptheenemy:
            system("clear");
            for(int gapa1=2; gapa1<101; gapa1++){
              myMiniGameArray[27][gapa1-1]=myMiniGameArray[27][gapa1];
              //myMiniGameArray[26][gapa1-1]=myMiniGameArray[26][gapa1];
              if(myMiniGameArray[26][gapa1]!="-"){myMiniGameArray[26][gapa1-1]=myMiniGameArray[26][gapa1];}
              if(myMiniGameArray[26][gapa1]=="-"){myMiniGameArray[26][gapa1-1]=" ";}
            }
myMiniGameArray[26][12]="¤";
            myMiniGameArray[27][100]="═";

for(int makeitwork=1; makeitwork<12; makeitwork++){
  if(myMiniGameArray[26][makeitwork]=="¤"){myMiniGameArray[26][makeitwork]=" ";}
}

if(firestage>0&&firestage<30){
  myMiniGameArray[26][((firestage*3)+11)]=" ";
 // if(myMiniGameArray[26][((firestage/2)-11)]=="-"){myMiniGameArray[25][((firestage/2)-11)]=" ";}
  firestage++;
  myMiniGameArray[26][((firestage*3)+11)]="-";
}//firestage>0
if(firestage==30){
  myMiniGameArray[26][101]="║";
  firestage=0;
}

            if(renderEnemy==3&&lastenemy==0){myMiniGameArray[26][100]="X";}else{myMiniGameArray[26][100]=" ";}

            for(int d1=0; d1<34; d1++){
              for(int d2=0; d2<102; d2++){
                cout << myMiniGameArray[d1][d2];
              }
              cout << endl;
            }
            break;
          }//if renderB!=2

          if(myMiniGameArray[27][100]=="═"&&myMiniGameArray[27][99]=="═"&&myMiniGameArray[27][98]==" "){
            system("clear");
            for(int gapa1=2; gapa1<101; gapa1++){
              myMiniGameArray[27][gapa1-1]=myMiniGameArray[27][gapa1];
//              myMiniGameArray[26][gapa1-1]=myMiniGameArray[26][gapa1];
              if(myMiniGameArray[26][gapa1]!="-"){myMiniGameArray[26][gapa1-1]=myMiniGameArray[26][gapa1];}
              if(myMiniGameArray[26][gapa1]=="-"){myMiniGameArray[26][gapa1-1]=" ";}
            }
myMiniGameArray[26][12]="¤";
            myMiniGameArray[27][100]="═";

            myMiniGameArray[26][100]=" ";

for(int makeitwork=1; makeitwork<12; makeitwork++){
  if(myMiniGameArray[26][makeitwork]=="¤"){myMiniGameArray[26][makeitwork]=" ";}
}

if(firestage>0&&firestage<30){
  myMiniGameArray[26][((firestage*3)+11)]=" ";
 // if(myMiniGameArray[26][((firestage/2)-11)]=="-"){myMiniGameArray[25][((firestage/2)-11)]=" ";}
  firestage++;
  myMiniGameArray[26][((firestage*3)+11)]="-";
}//firestage>0
if(firestage==30){
  myMiniGameArray[26][101]="║";
  firestage=0;
}

            gapphase=0;
            for(int d1=0; d1<34; d1++){
              for(int d2=0; d2<102; d2++){
                cout << myMiniGameArray[d1][d2];
              }
              cout << endl;
            }
            break;
          }

          if(myMiniGameArray[27][100]=="═"&&myMiniGameArray[27][99]==" "){
            system("clear");
            for(int gapa1=2; gapa1<101; gapa1++){
              myMiniGameArray[27][gapa1-1]=myMiniGameArray[27][gapa1];
//              myMiniGameArray[26][gapa1-1]=myMiniGameArray[26][gapa1];
              if(myMiniGameArray[26][gapa1]!="-"){myMiniGameArray[26][gapa1-1]=myMiniGameArray[26][gapa1];}
              if(myMiniGameArray[26][gapa1]=="-"){myMiniGameArray[26][gapa1-1]=" ";}
            }
myMiniGameArray[26][12]="¤";
            myMiniGameArray[27][100]="═";

            myMiniGameArray[26][100]=" ";

for(int makeitwork=1; makeitwork<12; makeitwork++){
  if(myMiniGameArray[26][makeitwork]=="¤"){myMiniGameArray[26][makeitwork]=" ";}
}

if(firestage>0&&firestage<30){
  myMiniGameArray[26][((firestage*3)+11)]=" ";
 // if(myMiniGameArray[26][((firestage/2)-11)]=="-"){myMiniGameArray[25][((firestage/2)-11)]=" ";}
  firestage++;
  myMiniGameArray[26][((firestage*3)+11)]="-";
}//firestage>0
if(firestage==30){
  myMiniGameArray[26][101]="║";
  firestage=0;
}

            gapphase=0;
            for(int d1=0; d1<34; d1++){
              for(int d2=0; d2<102; d2++){
                cout << myMiniGameArray[d1][d2];
              }
              cout << endl;
            }
            break;
          }

          if(myMiniGameArray[27][100]!=" "){
            if(renderB==2){
              system("clear");
              for(int gapa1=2; gapa1<101; gapa1++){
                myMiniGameArray[27][gapa1-1]=myMiniGameArray[27][gapa1];
//                myMiniGameArray[26][gapa1-1]=myMiniGameArray[26][gapa1];
              if(myMiniGameArray[26][gapa1]!="-"){myMiniGameArray[26][gapa1-1]=myMiniGameArray[26][gapa1];}
              if(myMiniGameArray[26][gapa1]=="-"){myMiniGameArray[26][gapa1-1]=" ";}
              }
myMiniGameArray[26][12]="¤";
              myMiniGameArray[27][100]=" ";

              myMiniGameArray[26][100]=" ";

for(int makeitwork=1; makeitwork<12; makeitwork++){
  if(myMiniGameArray[26][makeitwork]=="¤"){myMiniGameArray[26][makeitwork]=" ";}
}

if(firestage>0&&firestage<30){
  myMiniGameArray[26][((firestage*3)+11)]=" ";
 // if(myMiniGameArray[26][((firestage/2)-11)]=="-"){myMiniGameArray[25][((firestage/2)-11)]=" ";}
  firestage++;
  myMiniGameArray[26][((firestage*3)+11)]="-";
}//firestage>0
if(firestage==30){
  myMiniGameArray[26][101]="║";
  firestage=0;
}

              gapphase=5;
              for(int d1=0; d1<34; d1++){
                for(int d2=0; d2<102; d2++){
                  cout << myMiniGameArray[d1][d2];
                }
                cout << endl;
              }
            }//renderB==2
            break;
          }//if !=" "
          else if(myMiniGameArray[27][100]==" "){
            system("clear");
            for(int gapa1=2; gapa1<101; gapa1++){
              myMiniGameArray[27][gapa1-1]=myMiniGameArray[27][gapa1];
//              myMiniGameArray[26][gapa1-1]=myMiniGameArray[26][gapa1];
              if(myMiniGameArray[26][gapa1]!="-"){myMiniGameArray[26][gapa1-1]=myMiniGameArray[26][gapa1];}
              if(myMiniGameArray[26][gapa1]=="-"){myMiniGameArray[26][gapa1-1]=" ";}
            }
myMiniGameArray[26][12]="¤";
            myMiniGameArray[27][100]="═";

            myMiniGameArray[26][100]=" ";

for(int makeitwork=1; makeitwork<12; makeitwork++){
  if(myMiniGameArray[26][makeitwork]=="¤"){myMiniGameArray[26][makeitwork]=" ";}
}

if(firestage>0&&firestage<30){
  myMiniGameArray[26][((firestage*3)+11)]=" ";
 // if(myMiniGameArray[26][((firestage/2)-11)]=="-"){myMiniGameArray[25][((firestage/2)-11)]=" ";}
  firestage++;
  myMiniGameArray[26][((firestage*3)+11)]="-";
}//firestage>0
if(firestage==30){
  myMiniGameArray[26][101]="║";
  firestage=0;
}

            gapphase=0;
            for(int d1=0; d1<34; d1++){
              for(int d2=0; d2<102; d2++){
                cout << myMiniGameArray[d1][d2];
              }
              cout << endl;
            }
            break;
          }//else if ==" "
        }//if gapphase==0
        if(gapphase>0){
          system("clear");
          for(int gapa1=2; gapa1<101; gapa1++){
            myMiniGameArray[27][gapa1-1]=myMiniGameArray[27][gapa1];
//            myMiniGameArray[26][gapa1-1]=myMiniGameArray[26][gapa1];
              if(myMiniGameArray[26][gapa1]!="-"){myMiniGameArray[26][gapa1-1]=myMiniGameArray[26][gapa1];}
              if(myMiniGameArray[26][gapa1]=="-"){myMiniGameArray[26][gapa1-1]=" ";}
          }
myMiniGameArray[26][12]="¤";
          myMiniGameArray[27][100]=" ";

          myMiniGameArray[26][100]=" ";

for(int makeitwork=1; makeitwork<12; makeitwork++){
  if(myMiniGameArray[26][makeitwork]=="¤"){myMiniGameArray[26][makeitwork]=" ";}
}

if(firestage>0&&firestage<30){
  myMiniGameArray[26][((firestage*3)+11)]=" ";
 // if(myMiniGameArray[26][((firestage/2)-11)]=="-"){myMiniGameArray[25][((firestage/2)-11)]=" ";}
  firestage++;
  myMiniGameArray[26][((firestage*3)+11)]="-";
}//firestage>0
if(firestage==30){
  myMiniGameArray[26][101]="║";
  firestage=0;
}

          gapphase--;
          for(int d1=0; d1<34; d1++){
            for(int d2=0; d2<102; d2++){
              cout << myMiniGameArray[d1][d2];
            }
            cout << endl;
          }
          break;
        }//gapphase>0
        break;
      }//case null

      case 'w':
      {

if(myMiniGameArray[26][12]=="¤"&&myMiniGameArray[27][12]==" "){
  disableRawMode();
  cout << endl;
  system("clear");
  enableRawMode2();
  cout << endl;
  std::system("clear");
deathfactor=1;
  anappel=1;
miniGameDeath();
  goto thereturnline;
  return;
//break;
}

if(jumpphase2==0){jumpphase2=8;}
miniGameJump();
break;
      }//case w


      default:
      {
        cout << "default else \n";
        cout << "gapphase = " << gapphase << " renderB = " << renderB << "\n";
        cout << "mgc2 = " << mgc2 << " &mgc2 = " << &mgc2 << "\n";
        break;
      }
//goto makingthisloop2;
     // continue;
//break;
    }//switch
  continue;
  }//while
system("clear");

for(int d1=0; d1<34; d1++){
  for(int d2=0; d2<102; d2++){
    cout << myMiniGameArray[d1][d2];
  }
  cout << endl;
}


    
////
    
/*
std::random_device mgrd;
std::mt19937 mge{mgrd()};
std::mt19937 mge2{mgrd()};
std::uniform_int_distribution<int> dist{0, 9};
int renderB=dist(mge);

char mgc3;
char mgc4;
char mgc2;
int anappel=0;

int loopygo=1;
while (read(STDIN_FILENO, &mgc2, 1) == 1 && mgc2 != 'q'){

//while(loopygo==1){

  renderB=dist(mge);

  if(gapphase==0){

  if(renderB!=2){
    for(int gapa1=2; gapa1<101; gapa1++){
      myMiniGameArray[27][gapa1-1]=myMiniGameArray[27][gapa1];
    }
    myMiniGameArray[27][100]="═";
  }//if renderB==2
  if(renderB==2){
    for(int gapa1=2; gapa1<101; gapa1++){
      myMiniGameArray[27][gapa1-1]=myMiniGameArray[27][gapa1];
    }
    myMiniGameArray[27][100]=" ";
    gapphase=5;
  }//!=2
break;
  }//if gapphase==0
  if(gapphase>0){

    for(int gapa1=2; gapa1<101; gapa1++){
      myMiniGameArray[27][gapa1-1]=myMiniGameArray[27][gapa1];
    }
    myMiniGameArray[27][100]=" ";
    gapphase--;

break;;
  }//gapphase>0

system("clear");

for(int d1=0; d1<34; d1++){
  for(int d2=0; d2<102; d2++){
    cout << myMiniGameArray[d1][d2];
  }
  cout << endl;
}
cout << jumpphase << endl;
cout << lastcharor << endl;
cout << isitw << endl;
cout << isitd << endl;
cout << mgc2 << "\n";
cout << mgc3 << "\n";
cout << mgc4 << "\n";
cout << &mgc2 << "\n";
//cout << *mgc2 << "\n";
//mgc3=read(STDIN_FILENO, &mgc2, 1);
//mgc3=read(STDIN_FILENO, &mgc2, 1);
std::this_thread::sleep_for(500ms);
//mgc2=read(STDIN_FILENO, &mgc2, 1);
//mgc4=read(STDIN_FILENO, &mgc2, 1);
continue;
//}//while raw
mgc2='q';
break;
}//loopygo==1

/*

std::random_device mgrd;
std::mt19937 mge{mgrd()};
std::mt19937 mge2{mgrd()};
std::uniform_int_distribution<int> dist{0, 9};
//int renderTop = dist(mge);
//int renderBottom = dist(mge2);
int loopygo=1;
while(loopygo==1){
  while (read(STDIN_FILENO, &mgc, 1) == 1 && mgc != 'q') {
    switch(mgc){
      case 'w':
      {
        if(lastcharor==mgc){isitd=0;goto seeifrepeat;return;}
        else{
          samecharor=1;
          lastcharor=mgc;
          isitw=1;
          mgc='q';
          std::this_thread::sleep_for(10ms);
          goto seeifrepeat;
          return;
        }//else
      break;
      }//case w
      default:
      {
        isitw=0;
        lastcharor=mgc;
        mgc='q';
        std::this_thread::sleep_for(10ms);
        break;
      }//default
      mgc='q';
      std::this_thread::sleep_for(10ms);
    break;
    }//switch
  mgc='q';
  std::this_thread::sleep_for(10ms);
  break;
  }//while
  std::this_thread::sleep_for(10ms);

seeifrepeat:
if(isitw==1){
  std::system("clear");
  jumpphase=4;
  renderBottom = dist(mge);

  if(renderBottom==2){
    makeagap=1;
    if(gapphase==0){gapphase=5;}
  }//==2
  if(renderBottom!=2){
    makeagap=0;
  }

// renderTop = dist(mge2);
switch(makeagap){
  case 1:
  {
    if(gapphase>0){
      for(int gapa1=2; gapa1<100; gapa1++){
        myMiniGameArray[27][gapa1-1]=myMiniGameArray[27][gapa1];
      }
      myMiniGameArray[27][100]=" ";
      gapphase--;
      break;
    }//if gapphase>0
    if(gapphase==0){
      for(int gapa1=2; gapa1<100; gapa1++){
        myMiniGameArray[27][gapa1-1]=myMiniGameArray[27][gapa1];
      }
      myMiniGameArray[27][100]="═";
      break;
    }//if gapphase==0
  }//case 1
  default:
  {
        for(int gapa1=2; gapa1<100; gapa1++){
        myMiniGameArray[27][gapa1-1]=myMiniGameArray[27][gapa1];
      }
      myMiniGameArray[27][100]="═";
      break;

  }

}//makeagap switch

//  myMiniGameArray[26][positiontemp]=" ";
//  positiontemp++;
//  myMiniGameArray[26][positiontemp]="¤";
    for(int d1=0; d1<34; d1++){
      for(int d2=0; d2<102; d2++){
        cout << myMiniGameArray[d1][d2];
      }
      cout << endl;
    }
cout << "mgc = " << mgc << " . isitw " << isitd << " . lastcharor " << lastcharor << endl;
  isitw=0;
  std::this_thread::sleep_for(10ms);
  miniGameLoop();
}//if
else if(isitw==0){
miniGameLoop();
}//else
std::this_thread::sleep_for(10ms);

/*
////
  while (read(STDIN_FILENO, &mgc, 1) == 1 && mgc != 'q') {
    switch(mgc){
      case 'd':
      {
        if(lastcharor==mgc){isitd=0;goto thisistehline;return;}
        else{
          samecharor=1;
          lastcharor=mgc;
          isitd=1;
          mgc='q';
          std::this_thread::sleep_for(100ms);
goto thisistehline;
return;
        }
break;
}//end else if
      default:
      {
        isitd=0;
        lastcharor=mgc;
        mgc='q';
std::this_thread::sleep_for(100ms);

        break;
      }
break;
    }
    mgc='q';
std::this_thread::sleep_for(100ms);

    break;
  }
std::this_thread::sleep_for(100ms);

thisistehline:
if(isitd==1){
  std::system("clear");
  myMiniGameArray[26][positiontemp]=" ";
  positiontemp++;
  myMiniGameArray[26][positiontemp]="¤";
    for(int d1=0; d1<34; d1++){
      for(int d2=0; d2<102; d2++){
        cout << myMiniGameArray[d1][d2];
      }
      cout << endl;
    }
cout << "mgc = " << mgc << " . isitd " << isitd << " . lastcharor " << lastcharor << endl;
  isitd=0;
  std::this_thread::sleep_for(100ms);
  miniGameLoop();
}//if
else if(isitd==0){
miniGameLoop();
}//else
std::this_thread::sleep_for(100ms);

*/
//miniGameLoop();
//}//while loopygo=1

thereturnline:
return;

}//miniGameLoop function


void My_class::finishedMiniGame(){
  system("clear");

  if(passphase<100){
    myMiniGameArray[26][passphase]=" ";
    passphase++;
    myMiniGameArray[26][passphase]="¤";
  }
  else if(passphase==100){
    system("clear");
    makeTheLevel();
    whenMove(whichWay);
    return;
  }
  for(int d1=0; d1<34; d1++){
    for(int d2=0; d2<102; d2++){
      cout << myMiniGameArray[d1][d2];
    }
    cout << endl;
  }
  std::this_thread::sleep_for(50ms);
  finishedMiniGame();
}//end finishedMiniGame function


void My_class::aBush(){
//cout << "bush";
myPlayArea[35][0]=" A bush!  ||  ";
std::system("clear");
printTheLevel();
std::random_device rd;
std::mt19937 e{rd()};
    std::uniform_int_distribution<int> dist{0, 16};
  int randoBush = dist(e);
  if (randoBush>=8){
    myPlayArea[35][0]=" You find an apple!  ||  ";
    if (playerLife<=50){
      playerLife+=25;
    }
    if (playerLife>50&&playerLife<=75){
      playerLife+=10;
    }
    if (playerLife>75&&playerLife<=99){
      playerLife=100;
    }
    std::system("clear");
    printTheLevel();
  }

}

void My_class::itsNancei(){
whichWay="z";
myPlayArea[29][40]=" ";

/*****herreee comes Nancei!!!! *******/
//disableRawMode();
std::system("clear");
cout << "        .~P&&&&BPYJ?7777!!!!!!!!~~!~!~~~~~~^^^^^^^^^^^^^^~~~~~~~!!!!!!!!!!!7777?JYPB&&&&P~.        \n";
cout << "         .5@&&#GY?7!!~~~~~^^^^^^^^^^^^:::::.............:::::^^^^^^^^^^^^~~~~~~!!?YG#&&@5.         \n";
cout << "         .Y@&&#GY7!~~~~~~~^^^^^^^^^^^^::::..............::::^^^^^^^^^^^^^^~~~~~~!7YG#&&@Y.         \n";
cout << "        . J@&&B5?!!~~~~~^^^^^^^^:::::::::::.............::::::::::::^:^^^^^~~~~~!!?5B&#@J..        \n";
cout << "        ..!#&#P?!7!~~~~^^^^:::::::::::::::...::.:::::::.::::::::::::::::^^^^~~~~!!!?PB&&!          \n";
cout << "        . ~#&BY777!!~~~!!!!!~~^::::::.::::::::::::::::::::::::::::::^~~!!!!!~~~~!!77YG&#~          \n";
cout << "        ..!##G?77!!7?YYYYY5P555YJ?!!~^:::::::::::::::::::::::^~!7?JY555P5YYYYYJ7!777?G&&!          \n";
cout << "        .:^B#577!!??J?!~^~~!!7?Y55Y55YJ?7~^:::::::::::::^~7?JY55Y55Y?7!!~~^~!?J?7!7775#B^:.        \n";
cout << "        :77B&J77!!!!!!~~~~~~~~~~!7?7JYYJJ?!^:::::::::::^!?JJYYJ7?7!~~~~~~~~~~!!!!!!77J&B77:        \n";
cout << "        :J!G#J!!!!!!77777??7???7777??7777!~~^:::::::::^~~!77777?7777??7???77777!!!!!!?#G!?:        \n";
cout << "        ^P?BGJ!!!~!!7??JJYYYYP5P555YYJYJ7!!~^^::::::::^~!77?YJYY55Y55PYYJYJJ??7!!~~!!JGBJB~        \n";
cout << "        :7?PPJ!~~^~!77?YP5?^^PJPPYJ?!JYJ?7!!^^::::.::^^!!7?JJJ!?JYPPJP~^75PY?77!~^~~!?PGJ?:        \n";
cout << "        :!~J5?!~^^^~~!7JYJ7~:7???7?^^~?J7~~~~^^:::::^^~~~~!J?!^^?7???7:~7JYJ7!~~^^^~!7YY~!:        \n";
cout << "        :~~!57!~^^^^^~~!77???J?777?77!!~~^^~^^^::::^^^^~^^~~!777?777JJ?J?77!~^^^^^^~!75!~~:        \n";
cout << "        .^!!J7!~~~^^^^^^^^^~~!!~~~~~^^::^^^^^^^^^:^^^^^^^^^:^^^~~~~~!!~~~^^^^^^~~~~~!7Y!!^.        \n";
cout << "        .^~!J?!!~~~~^^^^^^:::::^:::::::^^^^^^^^^^^^^^^^^^^^^:::::::^::::::^^^^^~~~~!!?J!!^.        \n";
cout << "        .^^~!J!!!~~~^^^^^^^:::::::^::^^^^^^^^^^^^^^^^^^^^^^^^^::::::::^^^^^^^^^^~!!!!?!^^^.        \n";
cout << "         ::^~77!!!~~~^^^^^^^^^:^::::::^^^^:^^^^^^^^^^^^^^^^::^:::::::::^^^^^^^~~~!!!!7~^::.        \n";
cout << "         .^~^^7!!!~~~~^^^^^^^^^^^::^::::^::^~^^^^^^^^~~^^:^::^::^^^^^^^^^^^^~~~~!!!!7~:~~.         \n";
cout << "        ..:~^^!7!!~!~~^^^^^^^^^^^::::::::^~~^^^^:^:^^^^~~^::::::^:^^^^^^^^^^^~~~!~!7!^^~:.         \n";
cout << "        ...:^~~7!~~~~~~^^^^^^^^^::::::::^~~^^:::..::::^^~~^::::::::^:^^^^^^^~~~!!~!7~~^:...        \n";
cout << "        ......:~7!~~~~~~^^^^^^^^::::::::^^:::::::.::^::^^^^:::::::^^^^^^^^^~~~~~~!7~:.....         \n";
cout << "        .......:7!!~~~~~^^^^^^^^::::::::~^:^~!!^^^^^!!~^:^~::::::::^^^^^^^^~~~~~!!?:.......        \n";
cout << "         ....:..~7!~~~~~^^^^^^^^::::::::^~~~!~~~~~~~~~!!~~^::::::::^::^^^^^~~~~!~7~........        \n";
cout << "        ........^7!!~~~~~^^^^^::::::::::^:^^^^:::^^::^^^^:::::::::::^^^^^^~~~~!!!7^........        \n";
cout << "        .:....:.:!!!!~~~^^^^^^^::^:::::^^^^^^^:^^^^^:^^^^^^::::::::::^^^^^^~~~~!!!:.......         \n";
cout << "        .:....:..^7!~!~~^^^^^^^::^:::^^^^^^^~~~~~^~~~~~^^^^^^^^:::::^^^^^^^~~~!!7^.:.......        \n";
cout << "         ::.......~7~!~~~~^^^^^^^^^::^^~~!!!!!!!!!!!!!!!!~~~^^::^^^^^^^^^^~~~~!7!..........        \n";
cout << "        ...........~7!~~~~^^^^^^^^~7?JJYYJJJYYYJYYYJYYJJJYJYJJ?7~^^^^^^^~^~~~!!~..........         \n";
cout << "         ...........^7!~~~^^^^^^^^^~!??77777??JJJY?JJ??7!7777?!~^^^^^^^^^~~~!7^..........:.        \n";
cout << "         .........::.:~~~~~~^^^^^^^:^!7!!!!!!~~!!!!!~~!!!7777!^::^^^^^^~~~~!!^............         \n";
cout << "         .:.......:::..^~^^^^^^^^^^^^~~~!77?77777777777?77!!~^^^^^^^^^^~~~!~:::::..:......         \n";
cout << "         :......::......^!~^^:^^^^^^^^^^^~~!!!777?7?77!!~~^^^^^^^^^^^^~~~7~..::..........:.        \n";
cout << "         :...........::.^7!~^^^^:::^:^^^^^^::::::::::^^^^^^^^^:::^^^^~~!7?^..::::....:...:.        \n";
cout << " \"Hi!  I'm Nancei!  I'm so glad to see that you're feeling better, and walking around the room.\"\n ... Press Enter To Continue ...\n";
//  enableRawMode();
//  char c;
//while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
//ifOKraw();

getchar();
std::system("clear");

//cout << "success\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║                                                                                                    ║\n";
cout << "║ \"As you take a walk around the map, you'll notice several different things.                        ║\n";
cout << "║  First, be aware of the (░) guys on the level.  These are enemies!  And before you can             ║\n";
cout << "║   get into combat with one of those badies, you will need at least one weapon, or                  ║\n";
cout << "║   ability.  Look for either a weapon (‡) or an ability (§) before you get into a fight.            ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  (×) on the map marks a treasure!  Consider yourself lucky if you come apon one of these.          ║\n";
cout << "║   Often they grant a pwoerful potion that can assist you in battle.                                ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  Shrubbery Ø may offer health, so be on the lookout if you're wounded.                             ║\n";
cout << "║  Exits (<, >, ^, v) will take you to another level.                                                ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  (█) is a locked door, which may be mysteriously opened when you find the secret switch.           ║\n";
cout << "║  And speaking of mystery, that's exactly what (?) is.  Find one and you shall see!                 ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  Lastly, (ƒ) are other friends, like me.  Don't be shy, approach them and they can                 ║\n";
cout << "║   help you on your journey.                                                                        ║\n";
cout << "║                                                                                                    ║\n";
cout << "║  Press k to access the Key at any time.\"                                                           ║\n";
cout << "║____________________________________________________________________________________________________║\n";
cout << "║    - Nancei                                                                                        ║\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "\n";
cout << "\n";
cout << "Press ENTER to continue...\n ";
myPlayArea[34][0]=" Tip: Time to find a weapon (‡).                 || ";
foundNancei=1;
getchar();
tempvar2="ok";
ifOK2(tempvar2);
//cout << "success";

}


void My_class::attackWithWeapon(){

std::random_device rfd;
std::mt19937 e{rfd()}; // or std::default_random_engine e{rfd()};
std::uniform_int_distribution<int> dist{0, 9};

int delay;
delay = 1;

delay *= CLOCKS_PER_SEC;
clock_t now = clock();
while (clock() - now <delay);
std::system("clear");

//cout << "one\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║                      ???                                                                           ║\n";
cout << "║                      PGGY                                                                          ║\n";
cout << "║                   YYYBBB5YY                                                                        ║\n";
cout << "║                  Y###:..P&&P??                                                                     ║\n";
cout << "║                  Y#&#.  !??5BB5?                                                                   ║\n";
cout << "║                  Y#&#.  .:. BBPYYY                                                                 ║\n";
cout << "║                  Y#&#.  .:::::?&&B                                                                 ║\n";
cout << "║                  Y#&#.  .::::.?&&B                                                                 ║\n";
cout << "║                  Y#&#.  .::::.?&&B                                                                 ║\n";
cout << "║                  Y#&#.  .::::.?&&B                                                                 ║\n";
cout << "║                  Y#&#.  .::::.?&&B                                                                 ║\n";
cout << "║                  Y#&#.  .::::.?&&B                                                                 ║\n";
cout << "║                  Y#&#.  .::::.?&&B                                                                 ║\n";
cout << "║                  Y#&#.  .::::.?&&B                                                                 ║\n";
cout << "║                  Y#&#.  .::::.?&&B                                                                 ║\n";
cout << "║                  Y#&#.  .:::::?&&B                                                                 ║\n";
cout << "║             ??Y###&&#.  .::!?7P&&###B ?                                                            ║\n";
cout << "║            YPPPPPPPPP.  .::!Y 5BBBBBBPPP                                                           ║\n";
cout << "║           ?P&&B~~~~~~.  :::!  YYY555P#&#Y                                                          ║\n";
cout << "║             YY5##B~~~?  ??? 55?~~ ###YYY                                                           ║\n";
cout << "║               YGGGYYYPGGPPPPGG5YY5GGP                                                              ║\n";
cout << "║                ?? &&&#BBBBBBBB#&&B??                                                               ║\n";
cout << "║                  Y#&#BBBBBBBBB#&&B                                                                 ║\n";
cout << "║                  Y#&#BBBBBBBBB#&&B                                                                 ║\n";
cout << "║                  Y#&#BBBBBBBBB#&&B                                                                 ║\n";
cout << "║                  Y#&&BBBBBBBBB#&&B                                                                 ║\n";
cout << "║                   PPP####BB###BPP5                                                                 ║\n";
cout << "║                   ?? B###BB###P??                                                                  ║\n";
cout << "║                         B&&P                                                                       ║\n";
cout << "║                         5PPY                                                                       ║\n";
cout << "║                          ??                                                                        ║\n";
cout << "║                                                                                                    ║\n";
cout << "║════════════════════════════════════════════════════════════════════════════════════════════════════║\n";


clock_t now2 = clock();
while (clock() - now2 <delay);
std::system("clear");

//cout << "Two\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                    ?5BBBBBBBBBY                                    ║\n";
cout << "║                                                  Y5Y5GGGGGGGGG5Y5                                  ║\n";
cout << "║                                                 ?G&&5         G&&5                                 ║\n";
cout << "║                                              ?G## ^^:.........B&&5                                 ║\n";
cout << "║                                            555PPG!  .::::::!!!GBB5                                 ║\n";
cout << "║                                            #&&~  .::::::::^#&&Y                                    ║\n";
cout << "║                                         B##!:::..:::::.^GGG555                                     ║\n";
cout << "║                                      555555:  .:::::^77?BBB                                        ║\n";
cout << "║                                     Y#&#.  .::::::::7&&#                                           ║\n";
cout << "║                              ?P#####G::::..::::..?BBGYYY                                           ║\n";
cout << "║                            5PPPPPP55 ...:::^~~7?75BBP                                              ║\n";
cout << "║                            G&&5~~^.::::::::?Y B&&G?                                                ║\n";
cout << "║                           ?G&&5~~^:::??????B##PYY                                                  ║\n";
cout << "║                         5PPB##G Y?^^~YYYYYY#&&P?                                                   ║\n";
cout << "║                         B&&#BBB##P!!7555555B##5                                                    ║\n";
cout << "║                      B###BBBBBBBBBGGB######5 Y                                                     ║\n";
cout << "║                   PGG###BBBBBBBBB####GGGGGGY                                                       ║\n";
cout << "║                  Y#&&BBBBBBBBBBBB###B                                                              ║\n";
cout << "║                  Y#&#BBBBBBBBB#&&B                                                                 ║\n";
cout << "║                  Y#&&BBBBBB###BPP5                                                                 ║\n";
cout << "║                  Y####BBBBB###P?                                                                   ║\n";
cout << "║                      #&&&&&P                                                                       ║\n";
cout << "║                      5PPPPPY                                                                       ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "║                                                                                                    ║\n";
cout << "║════════════════════════════════════════════════════════════════════════════════════════════════════║\n";

clock_t now4 = clock();
while (clock() - now4 <delay);
std::system("clear");


cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║                                                       Y7XXXXXXXXXXXXXXXXXX.:::                     ║\n";
cout << "║                                                        7XXXXXXXXXXXXXXXXXX.::^                     ║\n";
cout << "║                                                        ?!!!...XXXXXXXXXXXXX...^^~?                 ║\n";
cout << "║                                                            :::.XXXXXXXXXXXXXXX:::?                 ║\n";
cout << "║                                                           ?:::.XXXXXXXXXXXXXX.:::?                 ║\n";
cout << "║                                                            777.XXXXXXXXXXXXXXX...^^^?              ║\n";
cout << "║                                                               .XXXXXXXXXXXXXXXXXX...7              ║\n";
cout << "║                                                               .XXXXXXXXXXXXXXXXXXXXX7              ║\n";
cout << "║                                                               .XXXXXXXXXXXXXXXXXXXXX7              ║\n";
cout << "║                      5PPPPPY                                  .XXXXXXXXXXXXXXXXXXXXX7              ║\n";
cout << "║                     Y#&&&&&P                                  .XXXXXXXXXXXXXXXXXXXXX7              ║\n";
cout << "║                  Y####BBBBB###P?                              .XXXXXXXXXXXXXXXXXXXXX7              ║\n";
cout << "║                  Y#&&BBBBBB###BPP5                         !!!.XXXXXXXXXXXXXXXXXX...7              ║\n";
cout << "║                  Y#&#BBBBBBBBB#&&B                        ?:.:.XXXXXXXXXXXXXXXXXX:::7              ║\n";
cout << "║                  Y#&&#BBBBBBBBBBB###B                     ?.XXXXXXXXXXXXXXXXXXXXX.::7              ║\n";
cout << "║                   PGG####BBBBBBBB####GGGGGGY           ?!!~XXXXXXXXXXXXXXXXXXX...~!!?              ║\n";
cout << "║                      B###BBBBBBBBBBBB######5YY    ?????7...XXXXXXXXXXXXXXXXXX.:::?                 ║\n";
cout << "║                         B&&#BBB##P!!!!!75PP#&&P Y!::::::XXXXXXXXXXXXXXXXXXXXX.:::?                 ║\n";
cout << "║                         5PPB##G Y 777^^^^^^!77~^^:......XXXXXXXXXXXXXXXXXXXXX.:::?                 ║\n";
cout << "║                           ?G&&5~~!  ?:::XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.:^^?                 ║\n";
cout << "║                            G&&P~~!  ?::::::.XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.?                    ║\n";
cout << "║                            5PPPPPGBBP::::::....XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.                     ║\n";
cout << "║                              ?P#####G~~~::::::...XXXXXXXXXXXXXXXXXXXXXXX.....:                     ║\n";
cout << "║                                     Y#&#^.:::::::.XXXXXXXXXXXXXXXXXXXXX.::^                        ║\n";
cout << "║                                      555PPP^.:::::...XXXXXXXXXXXXXXX...^777                        ║\n";
cout << "║                                         B##7~!^:::::....XXXXXXXXXXXX.::~Y                          ║\n";
cout << "║                                            #&&7.:::::::.XXXXXXXXXXXX.::~                           ║\n";
cout << "║                                            555PGG7.:::::...XXXXXX...~77?                           ║\n";
cout << "║                                               GB#5!!~::::::XXXXXX:~^7                              ║\n";
cout << "║                                                 ?G&&P::::::XXXXXX!Y                                ║\n";
cout << "║                                                  Y55PBGGGBGGGG?77?                                 ║\n";
cout << "║                                                     5BBBBBBBBBY                                    ║\n";
cout << "║════════════════════════════════════════════════════════════════════════════════════════════════════║\n";
int isitquick = 0;
switch(wOfChoice){
  case 0:
    {
    cout << "error\n";
    break;
    }
  case 1:
    {

    wOfChoicer = dist(e);
    if (wOfChoicer>(4+(playerLevel-(wOneSpeed+playerPower)))){
      cout << "You've successfully attacked " << nEnemy << " for " << wOneAttack << " damage.";
      if(wOneAttack>=5){cout << "...A critical hit!\n";}
      if(wOneAttack<5){cout << "\n";}
      if (nEnemyHealth == "■■■■■■■■■■"){
        if (wOneAttack <=2){nEnemyHealth = "■■■■■■■■■ ";break;}
        if (wOneAttack >2&& wOneAttack<5){nEnemyHealth = "■■■■■■■■  ";break;}
        if (wOneAttack >=5){nEnemyHealth = "■■■■■■■   ";break;}
      }
      if (nEnemyHealth == "■■■■■■■■■ "){
        if (wOneAttack <=2){nEnemyHealth = "■■■■■■■■  ";break;}
        if (wOneAttack >2&& wOneAttack<5){nEnemyHealth = "■■■■■■■   ";break;}
        if (wOneAttack >=5){nEnemyHealth = "■■■■■■    ";break;}
      }
      if (nEnemyHealth == "■■■■■■■■  "){
        if (wOneAttack <=2){nEnemyHealth = "■■■■■■■   ";break;}
        if (wOneAttack >2&& wOneAttack<5){nEnemyHealth = "■■■■■■    ";break;}
        if (wOneAttack >=5){nEnemyHealth = "■■■■■     ";break;}
      }
      if (nEnemyHealth == "■■■■■■■   "){
        if (wOneAttack <=2){nEnemyHealth = "■■■■■■    ";break;}
        if (wOneAttack >2&& wOneAttack<5){nEnemyHealth = "■■■■■     ";break;}
        if (wOneAttack >=5){nEnemyHealth = "■■■■      ";break;}
      }
      if (nEnemyHealth == "■■■■■■    "){
        if (wOneAttack <=2){nEnemyHealth = "■■■■■     ";break;}
        if (wOneAttack >2&& wOneAttack<5){nEnemyHealth = "■■■■      ";break;}
        if (wOneAttack >=5){nEnemyHealth = "■■■       ";break;}
      }
      if (nEnemyHealth == "■■■■■     "){
        if (wOneAttack <=2){nEnemyHealth = "■■■■      ";break;}
        if (wOneAttack >2&& wOneAttack<5){nEnemyHealth = "■■■       ";break;}
        if (wOneAttack >=5){nEnemyHealth = "■■        ";break;}
      }
      if (nEnemyHealth == "■■■■      "){
        if (wOneAttack <=2){nEnemyHealth = "■■■       ";break;}
        if (wOneAttack >2&& wOneAttack<5){nEnemyHealth = "■■        ";break;}
        if (wOneAttack >=5){nEnemyHealth = "■         ";break;}
      }
      if (nEnemyHealth == "■■■       "){
        if (wOneAttack <=2){nEnemyHealth = "■■        ";break;}
        if (wOneAttack >2&& wOneAttack<5){nEnemyHealth = "■         ";break;}
        if (wOneAttack >=5){
          cout << "...Press Enter To Continue...\n";
          getchar();
          std::system("clear");
          cout << " You have successfully defeated " << nEnemy << endl;
        //  cout << " You have gained 1 level and are now Level: ";
  //        playerLevel++;
    //      cout << playerLevel << endl;
      //    cout << "\n\n";
          cout << "...Press Enter To Continue...\n";
          getchar();
          std::system("clear");
gainExp();
          break;
//return;
        }//end if
      }
      if (nEnemyHealth == "■■        "){
        if (wOneAttack <=2){nEnemyHealth = "■         ";break;}
        if (wOneAttack >2){
          cout << "...Press Enter To Continue...\n";
          getchar();
          std::system("clear");
          cout << " You have successfully defeated " << nEnemy << endl;
//          playerLevel++;
   //       cout << playerLevel << endl;
     //     cout << "\n\n";
          cout << "...Press Enter To Continue...\n";
          getchar();
          std::system("clear");
          gainExp();
          break;
//return;
        }
      }
      if (nEnemyHealth == "■         "){
        cout << "...Press Enter To Continue...\n";
        getchar();
        std::system("clear");
        cout << " You have successfully defeated " << nEnemy << endl;
       // cout << " You have gained 1 level and are now Level: ";
       // playerLevel++;
       // cout << playerLevel << endl;
       // cout << "\n\n";
        cout << "...Press Enter To Continue...\n";
        getchar();
        std::system("clear");
       // tempvar2="ok";
       // ifOK2(tempvar2);
      //  break;
gainExp();
//return;
break;
      }
    break;
    }
    else if (wOfChoicer<=(4+(playerLevel-(wOneSpeed+playerPower)))){
      if(wOfChoicer<=4){
      cout << nEnemy << " quickly sidesteps your attack.\n";
      }
      if(wOfChoicer>4){
      cout << nEnemy << " was able to block your attack.\n";
      }
    }
    break;
    } //end case1

  case 2:
    {
    wOfChoicer = dist(e);
    if (wOfChoicer>(4+(playerLevel-(wOneSpeed+playerPower)))){
      cout << "You've successfully attacked " << nEnemy << " for " << wTwoAttack << " damage.";
      if(wTwoAttack>=5){cout << "...A critical hit!\n";}
      if(wTwoAttack<5){cout << "\n";}
      if (nEnemyHealth == "■■■■■■■■■■"){
        if (wTwoAttack <=2){nEnemyHealth = "■■■■■■■■■ ";break;}
        if (wTwoAttack >2&& wTwoAttack<5){nEnemyHealth = "■■■■■■■■  ";break;}
        if (wTwoAttack >=5){nEnemyHealth = "■■■■■■■   ";break;}
      }
      if (nEnemyHealth == "■■■■■■■■■ "){
        if (wTwoAttack <=2){nEnemyHealth = "■■■■■■■■  ";break;}
        if (wTwoAttack >2&& wTwoAttack<5){nEnemyHealth = "■■■■■■■   ";break;}
        if (wTwoAttack >=5){nEnemyHealth = "■■■■■■    ";break;}
      }
      if (nEnemyHealth == "■■■■■■■■  "){
        if (wTwoAttack <=2){nEnemyHealth = "■■■■■■■   ";break;}
        if (wTwoAttack >2&& wTwoAttack<5){nEnemyHealth = "■■■■■■    ";break;}
        if (wTwoAttack >=5){nEnemyHealth = "■■■■■■    ";break;}
      }
      if (nEnemyHealth == "■■■■■■■   "){
        if (wTwoAttack <=2){nEnemyHealth = "■■■■■■    ";break;}
        if (wTwoAttack >2&& wTwoAttack<5){nEnemyHealth = "■■■■■     ";break;}
        if (wTwoAttack >=5){nEnemyHealth = "■■■■      ";break;}
      }
      if (nEnemyHealth == "■■■■■■    "){
        if (wTwoAttack <=2){nEnemyHealth = "■■■■■     ";break;}
        if (wTwoAttack >2&& wTwoAttack<5){nEnemyHealth = "■■■■      ";break;}
        if (wTwoAttack >=5){nEnemyHealth = "■■■       ";break;}
      }
      if (nEnemyHealth == "■■■■■     "){
        if (wTwoAttack <=2){nEnemyHealth = "■■■■      ";break;}
        if (wTwoAttack >2&& wTwoAttack<5){nEnemyHealth = "■■■       ";break;}
        if (wTwoAttack >=5){nEnemyHealth = "■■        ";break;}
      }
      if (nEnemyHealth == "■■■■      "){
        if (wTwoAttack <=2){nEnemyHealth = "■■■       ";break;}
        if (wTwoAttack >2&& wTwoAttack<5){nEnemyHealth = "■■        "; break;}
        if (wTwoAttack >=5){nEnemyHealth = "■         ";break;}
      }
      if (nEnemyHealth == "■■■       "){
        if (wTwoAttack <=2){nEnemyHealth = "■■        ";break;}
        if (wTwoAttack >2&& wTwoAttack<5){nEnemyHealth = "■         ";break;}
        if (wTwoAttack >=5){
          cout << "...Press Enter To Continue...\n";
          getchar();
          std::system("clear");
          cout << " You have successfully defeated " << nEnemy << endl;
       //   cout << " You have gained 1 level and are now Level: ";
         // playerLevel++;
       //   cout << playerLevel << endl;
         // cout << "\n\n";
          cout << "...Press Enter To Continue...\n";
          getchar();
          std::system("clear");
    //      tempvar2="ok";
      //    ifOK2(tempvar2);
         // break;
gainExp();
//return;
break;
        }
      }
      if (nEnemyHealth == "■■        "){
        if (wTwoAttack <=2){nEnemyHealth = "■         ";break;}
        if (wTwoAttack >2){
          cout << "...Press Enter To Continue...\n";
          getchar();
          std::system("clear");
          cout << " You have successfully defeated " << nEnemy << endl;
        //  cout << " You have gained 1 level and are now Level: ";
       //   playerLevel++;
       //   cout << playerLevel << endl;
       //   cout << "\n\n";
          cout << "...Press Enter To Continue...\n";
          getchar();
          std::system("clear");
       //   tempvar2="ok";
       //   ifOK2(tempvar2);
        //  break;
gainExp();
//return;
break;
        }
      }
      if (nEnemyHealth == "■         "){
        cout << "...Press Enter To Continue...\n";
        getchar();
        std::system("clear");
        cout << " You have successfully defeated " << nEnemy << endl;
      //  cout << " You have gained 1 level and are now Level: ";
      //  playerLevel++;
     //   cout << playerLevel << endl;
     //   cout << "\n\n";
        cout << "...Press Enter To Continue...\n";
        getchar();
        std::system("clear");
     //   tempvar2="ok";
     //   ifOK2(tempvar2);
      //  break;
gainExp();
//return;
break;
      }
    break;
    }
    else if (wOfChoicer<=(4+(playerLevel-(wOneSpeed+playerPower)))){
      if(wOfChoicer<=4){
      cout << nEnemy << " quickly sidesteps your attack.\n";
      }
      if(wOfChoicer>4){
      cout << nEnemy << " was able to block your attack.\n";
      }
    }
    break;
    } //end case2

  case 3:
    {
    wOfChoicer = dist(e);
    if (wOfChoicer>(4+(playerLevel-(wOneSpeed+playerPower)))){
      cout << "You've successfully attacked " << nEnemy << " for " << wThreeAttack << " damage.\n";
      if (nEnemyHealth == "■■■■■■■■■■"){
        if (wThreeAttack <=2){nEnemyHealth = "■■■■■■■■■ ";break;}
        if (wThreeAttack >2&& wThreeAttack<5){nEnemyHealth = "■■■■■■■■  ";break;}
        if (wThreeAttack >=5){nEnemyHealth = "■■■■■■■   ";break;}
      }
      if (nEnemyHealth == "■■■■■■■■■ "){
        if (wThreeAttack <=2){nEnemyHealth = "■■■■■■■■  ";break;}
        if (wThreeAttack >2&& wThreeAttack<5){nEnemyHealth = "■■■■■■■   ";break;}
        if (wThreeAttack >=5){nEnemyHealth = "■■■■■■    ";break;}
      }
      if (nEnemyHealth == "■■■■■■■■  "){
        if (wThreeAttack <=2){nEnemyHealth = "■■■■■■■   ";break;}
        if (wThreeAttack >2&& wThreeAttack<5){nEnemyHealth = "■■■■■■    ";break;}
        if (wThreeAttack >=5){nEnemyHealth = "■■■■■     ";break;}
      }
      if (nEnemyHealth == "■■■■■■■   "){
        if (wThreeAttack <=2){nEnemyHealth = "■■■■■■    ";break;}
        if (wThreeAttack >2&& wThreeAttack<5){nEnemyHealth = "■■■■■     ";break;}
        if (wThreeAttack >=5){nEnemyHealth = "■■■■      ";break;}
      }
      if (nEnemyHealth == "■■■■■■    "){
        if (wThreeAttack <=2){nEnemyHealth = "■■■■■     ";break;}
        if (wThreeAttack >2&& wThreeAttack<5){nEnemyHealth = "■■■■      ";break;}
        if (wThreeAttack >=5){nEnemyHealth = "■■■       ";break;}
      }
      if (nEnemyHealth == "■■■■■     "){
        if (wThreeAttack <=2){nEnemyHealth = "■■■■      ";break;}
        if (wThreeAttack >2&& wThreeAttack<5){nEnemyHealth = "■■■       ";break;}
        if (wThreeAttack >=5){nEnemyHealth = "■■        ";break;}
      }
      if (nEnemyHealth == "■■■■      "){
        if (wThreeAttack <=2){nEnemyHealth = "■■■       ";break;}
        if (wThreeAttack >2&& wThreeAttack<5){nEnemyHealth = "■■        "; break;}
        if (wThreeAttack >=5){nEnemyHealth = "■         ";break;}
      }
      if (nEnemyHealth == "■■■       "){
        if (wThreeAttack <=2){nEnemyHealth = "■■        ";break;}
        if (wThreeAttack >2&& wThreeAttack<5){nEnemyHealth = "■         ";break;}
        if (wThreeAttack >=5){
          cout << "...Press Enter To Continue...\n";
          getchar();
          std::system("clear");
          cout << " You have successfully defeated " << nEnemy << endl;
    //      cout << " You have gained 1 level and are now Level: ";
     //     playerLevel++;
      //    cout << playerLevel << endl;
      //    cout << "\n\n";
          cout << "...Press Enter To Continue...\n";
          getchar();
          std::system("clear");
    //      tempvar2="ok";
      //    ifOK2(tempvar2);
       //   break;
gainExp();
//return;
break;
        }
      }
      if (nEnemyHealth == "■■        "){
        if (wThreeAttack <=2){nEnemyHealth = "■         ";break;}
        if (wThreeAttack >2){
          cout << "...Press Enter To Continue...\n";
          getchar();
          std::system("clear");
          cout << " You have successfully defeated " << nEnemy << endl;
    //      cout << " You have gained 1 level and are now Level: ";
      //    playerLevel++;
        //  cout << playerLevel << endl;
      //    cout << "\n\n";
          cout << "...Press Enter To Continue...\n";
          getchar();
          std::system("clear");
    //      tempvar2="ok";
      //    ifOK2(tempvar2);
         // break;
gainExp();
//return;
break;
        }
      }
      if (nEnemyHealth == "■         "){
        cout << "...Press Enter To Continue...\n";
        getchar();
        std::system("clear");
        cout << " You have successfully defeated " << nEnemy << endl;
     //   cout << " You have gained 1 level and are now Level: ";
    //    playerLevel++;
   //     cout << playerLevel << endl;
   //     cout << "\n\n";
        cout << "...Press Enter To Continue...\n";
        getchar();
        std::system("clear");
   //     tempvar2="ok";
     //   ifOK2(tempvar2);
       // break;
gainExp();
break;
      }
    break;
    }
    else if (wOfChoicer<=(4+(playerLevel-(wOneSpeed+playerPower)))){
      if(wOfChoicer<=4){
      cout << nEnemy << " quickly sidesteps your attack.\n";
      }
      if(wOfChoicer>4){
      cout << nEnemy << " was able to block your attack.\n";
      }
    }
    break;
    } //end case3
break;
}//end switch
weaponFightArray[3][3]=nEnemyHealth;
if(potion2xa==1){
  potion2xa=0;
  if(nWeapons==3){
    wOneAttack = wOneAttack/2;
    wTwoAttack = wTwoAttack/2;
    wThreeAttack = wThreeAttack/2;
  }
  if(nWeapons==2){
    wOneAttack = wOneAttack/2;
    wTwoAttack = wTwoAttack/2;
  }
  if(nWeapons==1){
    wOneAttack = wOneAttack/2;
  }
}
if(potion2xa>1&&potion2xa<=3){
  potion2xa--;
}
if(speedpotiona>0){
  speedpotiona--;
  if(speedpotiona==0){
    if(nWeapons>=1){wOneSpeed=(wOneSpeed/2);}
    if(nWeapons>=2){wTwoSpeed=(wTwoSpeed/2);}
    if(nWeapons==3){wThreeSpeed=(wThreeSpeed/2);}
  }
}

cout << "...Press Enter To Continue...\n";
getchar();
enemyTurn();

}//end void


void My_class::enemyTurn(){


  std::system("clear");
  std::random_device rfd;
  std::mt19937 e{rfd()};
  std::mt19937 f{rfd()};
  std::uniform_int_distribution<int> dist{0, 2};

  int delay;
  delay = 1;
  delay *= CLOCKS_PER_SEC;

  clock_t now = clock();
  while (clock() - now <delay);
  std::system("clear");
  cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
  cout << "║                                                                                                    ║\n";
  cout << "║                                                                                                    ║\n";
  cout << "║                                                                                                    ║\n";
  cout << "║\033[31m.........................................:!Y&@&Y7????7G@@&?77!......................................\033[0m║\n";
  cout << "║\033[31m  .........................................^JP57777777?PGY!~^. ...                                  \033[0m║\n";
  cout << "║\033[31m  .............................................:^^~~!!!~^:........... .                             \033[0m║\n";
  cout << "║\033[31m   .................................................................  .                             \033[0m║\n";
  cout << "║\033[31m   ..................................................................  ..                           \033[0m║\n";
  cout << "║\033[31m   .....................................................................                            \033[0m║\n";
  cout << "║\033[31m   ......................................................................                          \033[0m.║\n";
  cout << "║:\033[31m   .....................................................................                          \033[0m:║\n";
  cout << "║!\033[31m   ...................................................................... .  .                   \033[0m.^║\n";
  cout << "║?.\033[31m  ....................................                     .................. .  .              \033[0m.~║\n";
  cout << "║?~\033[31m   ..............................      .....::^^!!:..           ..............    ..            \033[0m^!║\n";
  cout << "║77.\033[31m  ...........................    .:~?P#B##&&&&&&&&##BGPYYGP~.      .............    .         \033[0m:!7║\n";
  cout << "║??~\033[31m   .......................  ^!!JP##&##BB####&&&&&&&&@&&&&##BG5?~.... .... .................. \033[0m.~!7║\n";
  cout << "║JJJ.\033[31m   ..................^!:  ^B&&&#BP5J????JJY5PBB##BBG5YJ???7?JPB#B#P.   ... ...........      \033[0m^!?7║\n";
  cout << "║JJJ!\033[31m   ................:!!!?YG&&#G5J?7!!!!!!!!!!!77Y5J77!!!!!!!!!!7YG#&B7..:~^. .............. \033[0m:!??7║\n";
  cout << "║JJJJ^\033[31m   ..............^7!!5#&&B57!!!!!!!!!!!!!!!!!!!77!!!!!!!!!!!!!!7JPG##BJ~!!:............. \033[0m.~7?77║\n";
  cout << "║YJJJJ.\033[31m  .............!?7?G&&B5?^ .!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!~^~!!7YPB&&Y~~!: ............\033[0m^7J777║\n";
  cout << "║YYYYY7.\033[31m  ...........!#GPBB#G557!~!~~~~~~~^^^^^^~~~!!!!!!!!!!~~~^^:~!!!!755PB&5?7Y!...........\033[0m:7J?777║\n";
  cout << "║YYYYYY!\033[31m   ..........YJ77775PPP5?!!!~~~~~!!!!!77777777!!!!~~~~~~~~!!!!?Y5555GB55YY5:..........\033[0m!J?7?77║\n";
  cout << "║55YYYYY!.\033[31m ..........:777777YPPPP5?JJYYY5555PPPPPPPPP555YYJ???????7?JJJ5P55PG?!!!!!..........\033[0m!?J?????║\n";
  cout << "║55555555!.\033[31m ..........:!??777JP57^:?Y!!7?JY5YJ??JJJ55JJJJJ?JY7!~~^~YY. .!JY?!!!!7~..........\033[0m!?J??????║\n";
  cout << "║555555555?.\033[31m ...........:!????:.    .      .       ..       .      .:    :777!!~:..........\033[0m!?J???????║\n";
  cout << "║5555555555J:\033[31m.............:^^~:...........................................:::............\033[0m^7JYJ?J?????║\n";
  cout << "║PPPPP55555P57:\033[31m........................................................................\033[0m^7JYYJJJJJJJJJ║\n";
  cout << "║PPPPPPPPPP55P5?^\033[31m...................................................................\033[0m:~?YYYJJJJJJJJJJJ║\n";
  cout << "║PPPPPPPPPPPPPPPPY!:\033[31m.............................................................\033[0m:~7J555YYYYYYYYYYYYY║\n";
  cout << "║                                                                                                    ║\n";
  cout << "║                                                                                                    ║\n";
  cout << "║                                                                                                    ║\n";
  cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

  clock_t now2 = clock();
  while (clock() - now2 <delay);
  std::system("clear");
  cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
  cout << "║                                                                                                    ║\n";
  cout << "║                                                                                                    ║\n";
  cout << "║                                                                                                    ║\n";
  cout << "║\033[31m...........................:::..........       ...~:....     .......................................\033[0m║\n";
  cout << "║\033[31m............................           ~J~~!7?JY5G&BP5YYJ?777Y^..           ..                      \033[0m║\n";
  cout << "║\033[31m.........................    ...:^!?YPB&&&&&&&&&&&&&&&&&&&&&&&&#BG5?!:..:.    ...                   \033[0m║\n";
  cout << "║\033[31m.......................     ~###&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##B#!      ..                  \033[0m║\n";
  cout << "║\033[31m...................:!^.   .J&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###&&&#!    .:~^.                \033[0m║\n";
  cout << "║\033[31m..................~!!!!^7?B&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#####J!7~~~~~~.               \033[0m║\n";
  cout << "║\033[31m................:!!!!!!5&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#####&&#J^~~~~~.              \033[0m║\n";
  cout << "║\033[31m...............^7!!!!!J&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######J~~~~~~.             \033[0m║\n";
  cout << "║\033[31m..............~7!!!!!J&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#####&J^~~^^^.            \033[0m║\n";
  cout << "║\033[31m.............^7!!!!!7B&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###&B!~~. .^            \033[0m║\n";
  cout << "║\033[31m.............7!!!!!!P&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&####&J~~~^^~:           \033[0m║\n";
  cout << "║\033[31m............~!!!!!!!G&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#&5~~~~~~~.          \033[0m║\n";
  cout << "║\033[31m............BP7!!!!!B&&&&&&&&&&&&&&&&&&&@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&5~~~~~!G~ .        \033[0m║\n";
  cout << "║\033[31m...........:#&#5Y5PG#&&&&&&&&&&&G##GPPPGBB#&&&@@@&&&&&&@@@@&&&&&#BGB#&&&&&&&&&&&&BY?77Y#&? ..       \033[0m║\n";
  cout << "║\033[31m...........:#&&&&&&&&&&&5^!#&&#GJ7!!!!!~~!!!7JYPB#&&@&&#BGPYJ?7!!!~!75B#&&&&&&&&&&&&##&&&? .....    \033[0m║\n";
  cout << "║\033[31m............#&&&&&&&&&&&P~?#BY7!!!!!!!!!!!!!!!~~!!?Y5J7!!~~~~~~!!!!!~!7YG#&&&&&&&&&&&&&&&! .........\033[0m║\n";
  cout << "║\033[31m............P&&&&&&&&&&&&&B?!!!!!!!!!!!!!!!!!!!!!!!!!77!!!!!!!!!!!!!!!~!J5P#&&&&&&&&&&&&#: .........\033[0m║\n";
  cout << "║\033[31m............!&&&&&&&&&&&BJ!!!!!!!!!!!!!!!!!!!!!!!!!!7777!!!!!!!!!!!!!!!!!7Y5G&&&&&&#&&&&J ..........\033[0m║\n";
  cout << "║\033[31m.............G&#YJY5PB&G7!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!7Y5P#&PJ?7JG&#:...........\033[0m║\n";
  cout << "║\033[31m.............^G?7777!5&G7777777!!!77!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Y55#&J~!!!!J?............\033[0m║\n";
  cout << "║\033[31m..............^????775&&P7777777!~~!!777777777!!!!!!!!!!!!!!!!!!!~^^~!!!!75P5B&&J!!!!!~.............\033[0m║\n";
  cout << "║\033[31m...............^??????G&&GJ7777777~^^^~~~~~!!!!!777777777777!!!~^^~!!!!7J5PP#&&5!!!!7!..............\033[0m║\n";
  cout << "║\033[31m7...:...........:?J????P&&BY?77????777777!!!!!!!!777777!!!!~~~~!!77777Y5PPB&&#Y77777!..............~\033[0m║\n";
  cout << "║\033[31mPJ...:::::.......:7JJJYJ?~.^Y5?????????????????77777777!!7777777777?J5PPBG~~5Y77777!..............!J\033[0m║\n";
  cout << "║\033[31mPPY^..::::::.......~JY!.  . .7GPJJ5YYYJJJJJ?????????????JJJJJJYYY5PPGGB&G.   .~77?^.............:7YY\033[0m║\n";
  cout << "║\033[31mPPPP!..::::::::::...:~....... :7^~?YPGGGGGGGGPPPPPPPPPGGGGGGGGGGGP5YJ?YP: ..   ~7:.............~JYYY\033[0m║\n";
  cout << "║                                                                                                    ║\n";
  cout << "║                                                                                                    ║\n";
  cout << "║                                                                                                    ║\n";
  cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

  clock_t now3 = clock();
  while (clock() - now3 <delay);
  std::system("clear");
  cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
  cout << "║                                                                                                    ║\n";
  cout << "║                                                                                                    ║\n";
  cout << "║                                                                                                    ║\n";
  cout << "║\033[31m.................::.....:YGPG#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BPYPP........................\033[0m║\n";
  cout << "║\033[31m................^.     :B&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##########Y      .:.              \033[0m║\n";
  cout << "║\033[31m..............^!!~:.. ^#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##########&5. ..^~~^:.            \033[0m║\n";
  cout << "║\033[31m.............~!!!!!?GB#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#########&BPG7^^^^^^.           \033[0m║\n";
  cout << "║\033[31m...........:!!!!!!?#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#############B!^^^^^^.          \033[0m║\n";
  cout << "║\033[31m..........^7!!!!?5#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#############BY!^^^^^:         \033[0m║\n";
  cout << "║\033[31m.........^7!!!!!5&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###############?^~~^^~:        \033[0m║\n";
  cout << "║\033[31m........^7!!!!!?#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###########G~~~~~^~:       \033[0m║\n";
  cout << "║\033[31m.......:7!!!!!7B&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&############Y~~~~~~~.      \033[0m║\n";
  cout << "║\033[31m.......!!!!!!!5&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###########!~~~~~~^      \033[0m║\n";
  cout << "║\033[31m......^Y!!!!!!Y&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##########!~~~~~~!.     \033[0m║\n";
  cout << "║\033[31m..... !&P!!!!!?#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##&&#&G~~~~~~J#^     \033[0m║\n";
  cout << "║\033[31m......!&&BYJJJY#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&B?777?P#&~     \033[0m║\n";
  cout << "║\033[31m......^&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###&&##^     \033[0m║\n";
  cout << "║\033[31m.......B&&&&&&&&&&&&&&&&&&&&&&###&&&@@@@@@&&&&&&&&&&&&&&&&&&&&@@@&&####&&&&&&&&&&&&&&&&&&&&&&B.   . \033[0m║\n";
  cout << "║\033[31m.......5&&&&&&&&&&&&&&&&&&&GY?7777?JY5PB##&&&@@@@&&&&&@@@@&&&#BP5J?7!!?YPB#&&&&&&&&&&&&&&&&&&5 .....\033[0m║\n";
  cout << "║\033[31m.......~&&&&&&&&&&&&&&&&#5?!!!!!!!!!!!!!!!7?Y5GB#&&@&&#BG5J?7!~~~~~!!!~!7J5G#&&&&&&&&&&&&&&&&~ .....\033[0m║\n";
  cout << "║\033[31m........G&&&&&&&&&&&&&#Y7!!!!!!!!!!!!!!!!!!!!!!!!7J5YJ7!!!!!!!!!!!!!!!!!!!7Y5G#&&&&&&&&&&&&&P.......\033[0m║\n";
  cout << "║\033[31m........^&&&G55GB#&&&P7!!!!!!!!!!!!!!!!!!!!!!!!!!!!77777!!!!!!!!!!!!!!!!!!!!J55B&&&#GP55G&&#: ......\033[0m║\n";
  cout << "║\033[31m.........J&5777775&#Y7777777777777!!!!!!!!!!!!!!!!!!!777!!!!!!!!!!!!!!!!!!!!!?55B&&?!!!!!5&7 .......\033[0m║\n";
  cout << "║\033[31m..........???????5&&J77777777!7777777777777777!!!!!!!!77777!!!!!!!!!!!!!!!!!!?55G&#7!!!!!7?.........\033[0m║\n";
  cout << "║\033[31m..........:?J????Y&&#J7??7777~^~777777777777777777777777777!!!!!!!!!7!!!!!7J?5PG&&#7!!!!!!..........\033[0m║\n";
  cout << "║\033[31m::.::::....:?JJJJJG&&#Y???????:::~!7?77777777777777777777777777777!~^^~!!7555PB&&&5777777:..........\033[0m║\n";
  cout << "║\033[31m::::::::::..:?JJJJJP&&B5????????:^^^~77????777777777777777777777!^::^!77J5PPG#&&#Y777777:...........\033[0m║\n";
  cout << "║\033[31m::::::::::::.:?YJYYJ!:.YBY??????J??7!~~~!777?????????????????7!^:^!7?7?YPGPB#Y:~!7?77?7:............\033[0m║\n";
  cout << "║\033[31m:::::::::::::::75J~.....?&GJJJJJJJJJJJ?777777?????????777!!!!~^~7????YPGGG##!    .~J?!..............\033[0m║\n";
  cout << "║                                                                                                    ║\n";
  cout << "║                                                                                                    ║\n";
  cout << "║                                                                                                    ║\n";
  cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "wOneAttack = " << wOneAttack << ". wOneSpeed = " << wOneSpeed << "\n";
  willitland = dist(e);
  switch(willitland){
    case 0:
    //will def land
    {
      amtdamage = 2+(playerLevel-playerDefense);
      cout << nEnemy << " attacked you for " << amtdamage << " damage\n";
      if (amtdamage<=3){
//      if (weaponFightArray[25][1]=="■■■■■■■■■■"){nPlayerHealth="■■■■■■■■■ ";playerLife=90;break;}
        if (nPlayerHealth=="■■■■■■■■■■"){nPlayerHealth="■■■■■■■■■ ";playerLife=90;break;}
        if (nPlayerHealth=="■■■■■■■■■ "){nPlayerHealth="■■■■■■■■  ";playerLife=80;break;}
        if (nPlayerHealth=="■■■■■■■■  "){nPlayerHealth="■■■■■■■   ";playerLife=70;break;}
        if (nPlayerHealth=="■■■■■■■   "){nPlayerHealth="■■■■■■    ";playerLife=60;break;}
        if (nPlayerHealth=="■■■■■■    "){nPlayerHealth="■■■■■     ";playerLife=50;break;}
        if (nPlayerHealth=="■■■■■     "){nPlayerHealth="■■■■      ";playerLife=40;break;}
        if (nPlayerHealth=="■■■■      "){nPlayerHealth="■■■       ";playerLife=30;break;}
        if (nPlayerHealth=="■■■       "){nPlayerHealth="■■        ";playerLife=20;break;}
        if (nPlayerHealth=="■■        "){nPlayerHealth="■         ";playerLife=10;break;}
        if (nPlayerHealth=="■         "){
          cout << "...Press Enter To Continue...\n";
          getchar();
          std::system("clear");
          cout << " You have been defeated...\n";
          //endGame();     gotta make this void
          break;
        }
      }
      if (amtdamage>3){
        if (nPlayerHealth=="■■■■■■■■■■"){nPlayerHealth="■■■■■■■■  ";playerLife=80;break;}
        if (nPlayerHealth=="■■■■■■■■■ "){nPlayerHealth="■■■■■■■   ";playerLife=70;break;}
        if (nPlayerHealth=="■■■■■■■■  "){nPlayerHealth="■■■■■■    ";playerLife=60;break;}
        if (nPlayerHealth=="■■■■■■■   "){nPlayerHealth="■■■■■     ";playerLife=50;break;}
        if (nPlayerHealth=="■■■■■■    "){nPlayerHealth="■■■■      ";playerLife=40;break;}
        if (nPlayerHealth=="■■■■■     "){nPlayerHealth="■■■       ";playerLife=30;break;}
        if (nPlayerHealth=="■■■■      "){nPlayerHealth="■■        ";playerLife=20;break;}
        if (nPlayerHealth=="■■■       "){nPlayerHealth="■         ";playerLife=10;break;}
        if (nPlayerHealth=="■■        " || nPlayerHealth=="■         "){
          cout << "...Press Enter To Continue...\n";
          getchar();
          std::system("clear");
          cout << " You have been defeated...\n";
          //endGame();     gotta make this void
          break;
        }
      }//end if amtdamage > 3      
    }//end case 0
      break;
    case 1:
    //give a chance, based on defense
    {
      amtdamage = 2+(playerLevel-playerDefense);
      willitlandr = dist(f);
      if(willitlandr >= (1+(playerLevel-playerDefense))){
        cout << nEnemy << " attacked you for " << amtdamage << " damage\n";

      if (amtdamage<=3){
//      if (weaponFightArray[25][1]=="■■■■■■■■■■"){nPlayerHealth="■■■■■■■■■ ";playerLife=90;break;}
        if (nPlayerHealth=="■■■■■■■■■■"){nPlayerHealth="■■■■■■■■■ ";playerLife=90;break;}
        if (nPlayerHealth=="■■■■■■■■■ "){nPlayerHealth="■■■■■■■■  ";playerLife=80;break;}
        if (nPlayerHealth=="■■■■■■■■  "){nPlayerHealth="■■■■■■■   ";playerLife=70;break;}
        if (nPlayerHealth=="■■■■■■■   "){nPlayerHealth="■■■■■■    ";playerLife=60;break;}
        if (nPlayerHealth=="■■■■■■    "){nPlayerHealth="■■■■■     ";playerLife=50;break;}
        if (nPlayerHealth=="■■■■■     "){nPlayerHealth="■■■■      ";playerLife=40;break;}
        if (nPlayerHealth=="■■■■      "){nPlayerHealth="■■■       ";playerLife=30;break;}
        if (nPlayerHealth=="■■■       "){nPlayerHealth="■■        ";playerLife=20;break;}
        if (nPlayerHealth=="■■        "){nPlayerHealth="■         ";playerLife=10;break;}
        if (nPlayerHealth=="■         "){
          cout << "...Press Enter To Continue...\n";
          getchar();
          std::system("clear");
          cout << " You have been defeated...\n";
          //endGame();     gotta make this void
          break;
        }
      }
      if (amtdamage>3){
        if (nPlayerHealth=="■■■■■■■■■■"){nPlayerHealth="■■■■■■■■  ";playerLife=80;break;}
        if (nPlayerHealth=="■■■■■■■■■ "){nPlayerHealth="■■■■■■■   ";playerLife=70;break;}
        if (nPlayerHealth=="■■■■■■■■  "){nPlayerHealth="■■■■■■    ";playerLife=60;break;}
        if (nPlayerHealth=="■■■■■■■   "){nPlayerHealth="■■■■■     ";playerLife=50;break;}
        if (nPlayerHealth=="■■■■■■    "){nPlayerHealth="■■■■      ";playerLife=40;break;}
        if (nPlayerHealth=="■■■■■     "){nPlayerHealth="■■■       ";playerLife=30;break;}
        if (nPlayerHealth=="■■■■      "){nPlayerHealth="■■        ";playerLife=20;break;}
        if (nPlayerHealth=="■■■       "){nPlayerHealth="■         ";playerLife=10;break;}
        if (nPlayerHealth=="■■        " || nPlayerHealth=="■         "){
          cout << "...Press Enter To Continue...\n";
          getchar();
          std::system("clear");
          cout << " You have been defeated...\n";
          //endGame();     gotta make this void
          break;
        }
      }//end if amtdamage > 3


        break;
      }
      if(willitlandr < (1+(playerLevel-playerDefense))){
        cout << " You have successfully defended yourself from " << nEnemy << "'s attack!\n";
        break;
      }
    }//end case 1
      break;
    default: 
    {
      cout << " You quickly dodge " << nEnemy << "'s attack!\n";
      break;
    }//end default
break;
  }//end switch

wfl=0;
weaponFightArray[29][3]=wOnes;
weaponFightArray[29][7]=wTwos;
weaponFightArray[31][3]=wThrees;
if(nWeapons<2){weaponFightArray[29][7]="      ";}
if(nWeapons<3){weaponFightArray[31][3]="      ";}

battleArray[29][1]="→";
battleArray[29][3]=" ";
battleArray[31][1]=" ";
battleArray[31][3]=" ";
ax=29;
ay=1;

battleArray[25][1] = nPlayerHealth;
weaponFightArray[25][1] = nPlayerHealth;
battleArray[3][3] = weaponFightArray[3][3];

cout << "...Press Enter To Continue...\n";
getchar();
std::system("clear");
printBattleArray();

}//end void


void My_class::printTheLevel(){
myPlayArea[34][2]=to_string(playerLevel);
myPlayArea[34][4]=to_string(playerLife);
myPlayArea[34][6]=to_string(playerPower);
myPlayArea[34][8]=to_string(playerDefense);
myPlayArea[34][10]=to_string(playerMagic);
for (int i = 0; i < 36; i++){
  for (int j = 0; j < 102; j++){
    cout<<myPlayArea[i][j];
  }
cout<<"\n";
}
}

void My_class::aPotion(){
  std::system("clear");
  std::random_device rd;
  std::mt19937 g{rd()};
  std::uniform_int_distribution<int> dist{0, 3};
  int randoPotion = dist(g);
  switch(randoPotion){
    case 0: 
    //2.5x damage potion
    {

if(potion2x==1){aPotion(); break;}

cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║                                         .GPGPJYJPG7^~~                                             ║\n";
cout << "║                                          .G&57B5JYYY5BPJ:                                          ║\n";
cout << "║          ╗  ╗  ╗  ╗  ╗  ╗  ╗  ╗  ╗        :##Y&BJY??YY5BJ                                          ║\n";
cout << "║        █▄█ █▀█ █░█  █▀▀ █ █▄░█ █▀▄       .!B&BBBPYJ???5P7.                                         ║\n";
cout << "║        ░█░ █▄█ █▄█  █▀░ █ █░▀█ █▄▀       ?##&&&##BGGGGPP5?.                                        ║\n";
cout << "║        ╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝       ^?7YP5Y5YJ?7!!J?^.                                        ║\n";
cout << "║                                     .:^:    ^^7~^::^:.^:                                           ║\n";
cout << "║                                   .^~~^^~~~:Y?@BP!~J?.J~                                           ║\n";
cout << "║                                        .^JY7Y?@@GJ!YY:7^                                           ║\n";
cout << "║                                           :~5?@@GG?YY:~~..     ▄▀█   █▀▄▀█ ▄▀█ █▀▀ █ █▀▀ ▄▀█ █░░   ║\n";
cout << "║                                            :!!#G5B5Y5^:~~^^    █▀█   █░▀░█ █▀█ █▄█ █ █▄▄ █▀█ █▄▄   ║\n";
cout << "║                                            ~:JG?!J7~~::~:.. ....     ░░░░░░░░░░░░░░░░░░░░░░░░░░░   ║\n";
cout << "║                                        .:!7?!YY?7!~^^^^:........                                   ║\n";
cout << "║                                      ^?J??7!7?J?777!~~^:^.                                         ║\n";
cout << "║                                     !5Y~~^.:^!77?JJ7^^:.7~     ███████████████████████████████████ ║\n";
cout << "║                                     .J7!Y::~~~!?J777~^:..J~    █▄─▄▄─█─▄▄─█─▄─▄─█▄─▄█─▄▄─█▄─▀█▄─▄█ ║\n";
cout << "║                                      755J:~!!!7?YJ?7!^::..7~.  ██─▄▄▄█─██─███─████─██─██─██─█▄▀─██ ║\n";
cout << "║                                      ~PY?J?!~???55Y?~~~^:..~7^ ▀▄▄▄▀▀▀▄▄▄▄▀▀▄▄▄▀▀▄▄▄▀▄▄▄▄▀▄▄▄▀▀▄▄▀ ║\n";
cout << "║                                    .~!GBG#Y~?JJJ5P5?77?7~^..^7!                                    ║\n";
cout << "║                                   .::~G@&&J~??J55PPYYYYJJ7~:..~7.                                  ║\n";
cout << "║                               .  ..^7B@@@B7???JY5GBP5YYPP57~:..^!.                                 ║\n";
cout << "║                              :Y.::!5#@@@&5JYJJPPG#BP5YJJPBP?!^..^~:                                ║\n";
cout << "║                              .P5~7J5&@@@#Y5PPPGB##BGPP5YJ5G5?7!^:~:^^                              ║\n";
cout << "║                              !J!!?!G@@@@B5B#BGB#&&&##BPGP5YJ7!!~..~.Y~                             ║\n";
cout << "║                             !7!!Y!?@@@@@BB@&####&&&&####BG5YJ7~^:.^^~Y:                            ║\n";
cout << "║                            7J!?J?~B@@@@&G&@@##&&&&&&#####BPY5J~:^:.^^~^.                           ║\n";
cout << "║                           .?7775!?&@@@@&#@@@&##&#&&######BGPP57^^^..:^:.                           ║\n";
cout << "║                           7??~~P?YB#&&&BBB#&#BBB####BBB##BBPYY5J!7~:.:!^                           ║\n";
cout << "║                           !7!7.7?~!!?J5J!!!!!!7!!!!!~^~!7~^:::^^.!::.?!^ .                         ║\n";
cout << "║                           ~J^!~~7!7??Y5J???JJJYYJJJJ?77YJ7~:::^^~~:..J7: .                         ║\n";
cout << "║                           77~^~Y7!?JY5?J5PPPGGGGGGGP555P5?!^^:^^7!..^!?.                           ║\n";
cout << "║                            :Y!7!^J7~YG5!!YGGGGGGGPP5YYYJ?7!~!!JY::..^^.                            ║\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
      cout << "...Press Enter To Continue...\n";
      getchar();
      std::system("clear");
      cout << " You pick up the potion.  It feels cold in your hands.  A thick green liquid resides within.\n";
      cout << " On observation you notice painted on the bottle:\n\n";
cout<<" ❝ ▄▀█ █▀█ █▀█ █░░ █▄█   █░░ █ █▄▄ █▀▀ █▀█ ▄▀█ █░░ █░░ █▄█   ▀█▀ █▀█   █░█░█ █▀▀ ▄▀█ █▀█ █▀█ █▄░█ █▀   \n";
cout<<"   █▀█ █▀▀ █▀▀ █▄▄ ░█░   █▄▄ █ █▄█ ██▄ █▀▄ █▀█ █▄▄ █▄▄ ░█░   ░█░ █▄█   ▀▄▀▄▀ ██▄ █▀█ █▀▀ █▄█ █░▀█ ▄█   \n";
cout<<"\n";
cout<<"                                          █▀▀ █▀█ █▀█  \n";
cout<<"                                          █▀░ █▄█ █▀▄  \n";
cout<<"\n";
cout<<"     ▀█ ▀▄▀   █▀▄ ▄▀█ █▀▄▀█ ▄▀█ █▀▀ █▀▀   █▀▀ █▀█ █▀█   ▀█▀ █░█ █▀█ █▀▀ █▀▀   ▀█▀ █░█ █▀█ █▄░█ █▀ ░\n";
cout<<"     █▄ █░█   █▄▀ █▀█ █░▀░█ █▀█ █▄█ ██▄   █▀░ █▄█ █▀▄   ░█░ █▀█ █▀▄ ██▄ ██▄   ░█░ █▄█ █▀▄ █░▀█ ▄█ ▄ ❞\n";
      cout << "\n\n";
      cout << "You may open this from your Bag during a battle.\n";
      cout << "\n\n";
      potion2x++;

      if(bagslot1!=0){
        if(bagslot2!=0){
          if(bagslot3!=0){
            std::system("clear");
            cout << "\n";
            cout << "Unfortunately, your bag is full.  \n";
            cout << "You leave the magic potion behind. \n";
            cout << "\n";
            cout << "...Press Enter To Continue...\n";
            getchar();
            std::system("clear");
            tempvar2="ok";
            ifOK2(tempvar2);
            break;
          }//end if 3 is full
          if(bagslot3==0){bagslot3=1;}
        }//end if 2 is full
        if(bagslot2==0){bagslot2=1;}
      }//end if 1 is full
      if(bagslot1==0){bagslot1=1;}
      cout << "...Press Enter To Continue...\n";
      getchar();
      std::system("clear");
      tempvar2="ok";
      ifOK2(tempvar2);
      break;
    }//end case 0
    case 1:
    {
      //cout << "case 1\n";
      aPotion();
      break;
    }//end case 1
    case 2:
    {
      //health potion
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║                      .777777777~~~~7777:                                                           ║\n";
cout << "║                      .######BBBPJJ5BBBB7                                                           ║\n";
cout << "║                      :######BBB5JJ5BBBB7             ▀▄    ▄ ████▄   ▄                             ║\n";
cout << "║                     PB#########GYJYB##BBB~             █  █  █   █    █                            ║\n";
cout << "║                     ^?PB#BBBBBBB5JJPBBB57.              ▀█   █   █ █   █                           ║\n";
cout << "║                        .5######GYYP##Y.                 █    ▀████ █   █  .▄▄ ·  ▄▄▄· ▄· ▄▌        ║\n";
cout << "║                         ?######PYYP##!                ▄▀           █▄ ▄█ ▐█ ▀. ▐█ ▄█▐█▪██▌         ║\n";
cout << "║                         ?######PYYP##7                              ▀▀▀  ▄▀▀▀█▄ ██▀·▐█▌▐█▪         ║\n";
cout << "║                         ?######PYYP##7                ▄▄▄·  ▐ ▄          ▐█▄▪▐█▐█▪·• ▐█▀·.         ║\n";
cout << "║                         ?######PYYP##7               ▐█ ▀█ •█▌▐█          ▀▀▀▀ .▀     ▀ •          ║\n";
cout << "║                         7######PYYP##7               ▄█▀▀█ ▐█▐▐▌                                   ║\n";
cout << "║                         7######PYYP##7               ▐█ ▪▐▌██▐█▌    ▄▄▄ .▄▄▌  ▪  ▐▄• ▄ ▪  ▄▄▄      ║\n";
cout << "║                        .P######PYYP##P:                       █▪    ▀▄.▀·██•  ██  █▌█▌▪██ ▀▄ █·    ║\n";
cout << "║                       :GBBBBBBBPJJJGBBB!                            ▐▀▀▪▄██▪  ▐█· ·██· ▐█·▐▀▀▄     ║\n";
cout << "║                      !BBBBBBBBBB5JJJPBBBY                           ▐█▄▄▌▐█▌▐▌▐█▌▪▐█·█▌▐█▌▐█•█▌    ║\n";
cout << "║                     JBBBBBBBBBBBBYJJJPBBBG:                          ▀▀▀ .▀▀▀ ▀▀▀•▀▀ ▀▀▀▀▀.▀  ▀    ║\n";
cout << "║                   .PBBBP5Y5PBBBBBGJ7!~75GBB7                                                       ║\n";
cout << "║                  ^B#BJ:..   .~PB5^       !BB5.                                                     ║\n";
cout << "║                 7##B5....      ?          PBBG^                                                    ║\n";
cout << "║               .5##BBJ....                 PBBBB?                                                   ║\n";
cout << "║              :G###BBB~...                ^YGBBB#P.                                                 ║\n";
cout << "║             !#####BBBB7.                ~YYYGBBB#B~                                                ║\n";
cout << "║            J######BBBBBP~.            ^J5YYYYPB####J                                               ║\n";
cout << "║           P&######BBBBBBBG?:       ^JGGYYYYYYYP#####G                                              ║\n";
cout << "║           J&######BBBBBBBBBBGJ~:!YGBBBB5Y555555G####~                                              ║\n";
cout << "║            ~B&####BBBBBBBBBBBBBBBBBBBBBP5555555B##Y.                                               ║\n";
cout << "║              !G&&####BBBBBBBBBBBBBBBBBBP555PPB#BJ:                                                 ║\n";
cout << "║                :Y#&##################BGPGGBBP?:                                                    ║\n";
cout << "║                  .B&###############BGGGB##&?                                                       ║\n";
cout << "║                   B&&&&&&&&&&&&&#BBB#&&&&&&7                                                       ║\n";
cout << "║                   ^P&&&&&&&&&&&&&B##&&&&&&?.                                                       ║\n";
cout << "║                     JB&&&&&&&&&&&&&&&&&#G!                                                         ║\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

      cout << "...Press Enter To Continue...\n";
      getchar();
      std::system("clear");
      cout << " You pick up the elixir.  It feels warm in your hands.  A sparkling red liquid resides within.\n";
      cout << " You see something painted on the bottle: \n";
      cout << "\n\n";

cout << "────────────────\n";
cout << "─██████──██████─\n";
cout << "─██░░██──██░░██─\n";
cout << "─██████──██████─\n";
cout << "─██──────██─────\n";
cout << "\n";
cout << "    ▓█████▄  ██▀███   ██▓ ███▄    █  ██ ▄█▀   ▄▄▄█████▓ ██░ ██  ██▓  ██████  \n";
cout << "    ▒██▀ ██▌▓██ ▒ ██▒▓██▒ ██ ▀█   █  ██▄█▒    ▓  ██▒ ▓▒▓██░ ██▒▓██▒▒██    ▒  \n";
cout << "    ░██   █▌▓██ ░▄█ ▒▒██▒▓██  ▀█ ██▒▓███▄░    ▒ ▓██░ ▒░▒██▀▀██░▒██▒░ ▓██▄    \n";
cout << "    ░▓█▄   ▌▒██▀▀█▄  ░██░▓██▒  ▐▌██▒▓██ █▄    ░ ▓██▓ ░ ░▓█ ░██ ░██░  ▒   ██▒ \n";
cout << "    ░▒████▓ ░██▓ ▒██▒░██░▒██░   ▓██░▒██▒ █▄     ▒██▒ ░ ░▓█▒░██▓░██░▒██████▒▒ \n";
cout << "     ▒▒▓  ▒ ░ ▒▓ ░▒▓░░▓  ░ ▒░   ▒ ▒ ▒ ▒▒ ▓▒     ▒ ░░    ▒ ░░▒░▒░▓  ▒ ▒▓▒ ▒ ░ \n";
cout << "     ░ ▒  ▒   ░▒ ░ ▒░ ▒ ░░ ░░   ░ ▒░░ ░▒ ▒░       ░     ▒ ░▒░ ░ ▒ ░░ ░▒  ░ ░ \n";
cout << "     ░ ░  ░   ░░   ░  ▒ ░   ░   ░ ░ ░ ░░ ░      ░       ░  ░░ ░ ▒ ░░  ░  ░   \n";
cout << "    ▓██░██  ██▓░    ██▓▒██   ██▒ ██▓░██░███      ▄▄▄    ░  ▓██░ ░  █ ▓███▓█▄ \n";
cout << "    ▓█   ▀ ▓██▒    ▓██▒▒▒ █ █ ▒░▓██▒▓██ ▒ ██▒   ▒████▄     ██ ▀█   █ ▒██▀ ██▌\n";
cout << "    ▒███   ▒██░    ▒██▒░░  █   ░▒██▒▓██ ░▄█ ▒   ▒██  ▀█▄  ▓██  ▀█ ██▒░██   █▌\n";
cout << "    ▒▓█  ▄ ▒██░    ░██░ ░ █ █ ▒ ░██░▒██▀▀█▄     ░██▄▄▄▄██ ▓██▒  ▐▌██▒░▓█▄   ▌\n";
cout << "    ░▒████▒░██████▒░██░▒██▒ ▒██▒░██░░██▓ ▒██▒    ▓█   ▓██▒▒██░   ▓██░░▒████▓ \n";
cout << "    ░░ ▒░ ░░ ▒░▓  ░░▓  ▒▒ ░ ░▓ ░░▓  ░ ▒▓ ░▒▓░    ▒▒   ▓▒█░░ ▒░   ▒ ▒  ▒▒▓  ▒ \n";
cout << "     ░ ░  ░░ ░ ▒  ░ ▒ ░░░   ░▒ ░ ▒ ░  ░▒ ░ ▒░     ▒   ▒▒ ░░ ░░   ░ ▒░ ░ ▒  ▒ \n";
cout << "       ░     ░ ░    ▒ ░ ░    ░   ▒ ░  ░░   ░      ░   ▒      ░   ░ ░  ░ ░  ░ \n";
cout << "     ██▓  ░  ██▓ ██▒░  █▓▓███▓█  ░  ▄▄▄░      ███▄    ▓ ▓█████  █  ░  █░░    \n";
cout << "    ▓██▒    ▓██▒▓██░   █▒▓█   ▀    ▒████▄     ██ ▀█   █ ▓█   ▀ ▓█░ █ ░█░     \n";
cout << "    ▒██░    ▒██▒ ▓██  █▒░▒███      ▒██  ▀█▄  ▓██  ▀█ ██▒▒███   ▒█░ █ ░█      \n";
cout << "    ▒██░    ░██░  ▒██ █░░▒▓█  ▄    ░██▄▄▄▄██ ▓██▒  ▐▌██▒▒▓█  ▄ ░█░ █ ░█      \n";
cout << "    ░██████▒░██░   ▒▀█░  ░▒████▒    ▓█   ▓██▒▒██░   ▓██░░▒████▒░░██▒██▓      \n";
cout << "    ░ ▒░▓  ░░▓     ░ ▐░  ░░ ▒░ ░    ▒▒   ▓▒█░░ ▒░   ▒ ▒ ░░ ▒░ ░░ ▓░▒ ▒       \n";
cout << "    ░ ░ ▒  ░ ▒ ░   ░ ░░   ░ ░  ░     ▒   ▒▒ ░░ ░░   ░ ▒░ ░ ░  ░  ▒ ░ ░       \n";
cout << "      ░ ░    ▒ ░     ░░     ░        ░   ▒      ░   ░ ░    ░     ░   ░       \n";
cout << "        ░  ░ ░        ░     ░  ░         ░  ░         ░    ░  ░    ░         \n";
cout << "                     ░                                                       \n";
cout << "                                                                 ─██████──██████─\n";
cout << "                    ┌─┐┬ ┬┬  ┬    ┬ ┬┌─┐┌─┐┬  ┌┬┐┬ ┬             ─██░░██──██░░██─\n";
cout << "                  + ├┤ │ ││  │    ├─┤├┤ ├─┤│   │ ├─┤             ─██████──██████─\n";
cout << "                    └  └─┘┴─┘┴─┘  ┴ ┴└─┘┴ ┴┴─┘ ┴ ┴ ┴             ─────██──────██─\n";
cout << "                                                                 ────────────────\n";
      cout << "\n\n";
      cout << "You may open this from your Bag during a battle.\n";
      cout << "\n";
      healthelixir++;
      if(bagslot1!=0){
        if(bagslot2!=0){
          if(bagslot3!=0){
            std::system("clear");
            cout << "\n";
            cout << "Unfortunately, your bag is full.  \n";
            cout << "You leave the magic potion behind. \n";
            cout << "\n";
            cout << "...Press Enter To Continue...\n";
            getchar();
            std::system("clear");
            tempvar2="ok";
            ifOK2(tempvar2);
            break;
          }//end if 3 is full
          if(bagslot3==0){bagslot3=2;}
        }//end if 2 is full
        if(bagslot2==0){bagslot2=2;}
      }//end if 1 is full
      if(bagslot1==0){bagslot1=2;}
      cout << "...Press Enter To Continue...\n";
      getchar();
      std::system("clear");
      tempvar2="ok";
      ifOK2(tempvar2);
      break;

    }//end case 2 health potion
    case 3:
    {
      //speed potion

if(speedpotion==1){aPotion();break;}

cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";
cout << "║                                                   .:^!!~~^:..                                      ║\n";
cout << "║ ───────────────────╔╝╚╗                          ?GGBBGGP5P5Y!.                                    ║\n";
cout << "║ ╔╗─╔╦══╦╗╔╗╔══╦══╦═╩╗╔╝                          G#BBP55YY55PB~                                    ║\n";
cout << "║ ║║─║║╔╗║║║║║══╣╔╗║╔╗║║                           P&&&#G555Y5#B.                                    ║\n";
cout << "║ ║╚═╝║╚╝║╚╝║╠══║╚╝║╚╝║╚╗                          P&&&&#BPP5G#P                                     ║\n";
cout << "║ ╚═╗╔╩══╩══╝╚══╣╔═╩══╩═╝                       .:!#&&&&##P55G#? .                                   ║\n";
cout << "║ ╔═╝║──────────║║                              ^~^Y#&&&##GGGBB: ..                                  ║\n";
cout << "║ ╚══╝──────────╚╝   ╔══╗╔══╦╗╔╦═╦╦══╦╗╔╦══╗   .5Y!^^~!777777~^:~~!.                                 ║\n";
cout << "║                    ║╔╗║║╔═╣║║║╔╬╣╔╗║║║║══╣    G##BGP5YJJJ?7!7?J5!                                  ║\n";
cout << "║                    ║╔╗║║╚═╣╚╝║║║║╚╝║╚╝╠══║    Y&#####GP55YJ??JJJ:                                  ║\n";
cout << "║                    ╚╝╚╝╚══╩══╩╝╚╩══╩══╩══╝   :B####BBBGPPY?7?JJJ?!.                                ║\n";
cout << "║                                              .~75#&&BP55PP55J???JJJ?.                              ║\n";
cout << "║         ⭐                               .:7?7JB&&##B?!!7!!7!~?77~^:..                             ║\n";
cout << "║    ╋╋╋╋┏┓┏┓                            .^?!!^J&&&#B##J^^^^~~^^~~~^^^::...                          ║\n";
cout << "║  ⭐┏━┳━┫┗╋╋━┳━┳┓⭐                   ^JJ7~^J&&&&BBB#Y^^~!!!7~:.^~!~^:::^.                          ║\n";
cout << "║    ┃╋┃╋┃┏┫┃╋┃┃┃┃                    .7Y?!~!J&&&&#BB#B7^^^^^^::^:  :!!!^:.::                        ║\n";
cout << "║  ⭐┃┏┻━┻━┻┻━┻┻━┛⭐                .?5?~!7?#&&&&&###5~~~^...^:.^!. .^~~!^:::                        ║\n";
cout << "║    ┗┛   ⭐                         !5?!~7JJG&&&@&&&#J!!!~:..~~. :~:  ^~~~^:~:                      ║\n";
cout << "║                                     .YJ7^7?J?J#&##G5??7777777^~!!..!!:  ^~~!::~.                   ║\n";
cout << "║                                  ~YJ!^?JY7J55YJYJJYY??7777~!77~~?7^. .~~~^:^:                      ║\n";
cout << "║                                  !YJ~~?J5JYYJ?!Y55J7J5J??JJ77777?7^. .~~~~:~^                      ║\n";
cout << "║                                  ~YJ!^?5GP5YYYY55YY?YP5YJJJJ???????. .!!~^:^:                      ║\n";
cout << "║                                  :YJ7^75PBP7!77?JJYYYYYJYPP5?!7JJ?!:..~!!^:^.                      ║\n";
cout << "║                                   !JJ~!JPGBY!~~~!!7777?YGBBG55PGP5!:.:!!~:::                       ║\n";
cout << "║                                   .7?7~?5PB#G???JJJJ5555PY?!?5PPPJ^.^!!~::^.                       ║\n";
cout << "║                                    .!7!~J5PB#PJ?!!!75PPP5YY77Y55Y::!J7~::^.                        ║\n";
cout << "║                                      ^7~^?5PG##BBJJPPY77PGPPG5???75G57:::.                         ║\n";
cout << "║                                       .~!^~?J5PB####BG5PB####BGGGBGY!::.                           ║\n";
cout << "║                                     ..::^!!!!77?JY5PGGGGGGGP5YY55J7!~^::.                          ║\n";
cout << "║                                     ..:^~!7??777??777????JJJJY55J??7!~~^:.                         ║\n";
cout << "║                                        ..^~!!7???????JJYYJJJJJ?77!~~^^:.                           ║\n";
cout << "║                                              .....:::::::.......                                   ║\n";
cout << "══════════════════════════════════════════════════════════════════════════════════════════════════════\n";

      cout << "...Press Enter To Continue...\n";
      getchar();
      std::system("clear");
      cout << " You pick up the bottle.  It is slightly vibrating in your hands.  A yellow liquid resides within.\n";
      cout << " You see something painted on the bottle: \n";
      cout << "\n\n";
cout << "‟   𝓗𝓮 𝔀𝓱𝓸 𝓼𝓲𝓹𝓼 𝓯𝓻𝓸𝓶 𝓽𝓱𝓲𝓼 𝓿𝓲𝓪𝓵,\n";
cout << "    𝓢𝓱𝓪𝓵𝓵 𝓯𝓲𝓷𝓭 𝓽𝓱𝓮𝓶𝓼𝓮𝓵𝓿𝓮𝓼 𝔀𝓮𝓲𝓰𝓱𝓽𝓵𝓮𝓼𝓼   ”\n";
cout << "    ⇝⇝⇝⇝⇝⇝⇝⇝⇝⇝⇝⇝⇝⇝⇝⇝⇝⇝⇝⇝⇝⇝⇝⇝⇝\n";
cout << "\n\n";
cout << " Drink this Speed Potion for unstopable speed for 3 turns. \n";
cout << "You may open this from your Bag during a battle.\n";
cout << "\n";
      speedpotion++;
      if(bagslot1!=0){
        if(bagslot2!=0){
          if(bagslot3!=0){
            std::system("clear");
            cout << "\n";
            cout << "Unfortunately, your bag is full.  \n";
            cout << "You leave the magic potion behind. \n";
            cout << "\n";
            cout << "...Press Enter To Continue...\n";
            getchar();
            std::system("clear");
            tempvar2="ok";
            ifOK2(tempvar2);
            break;
          }//end if 3 is full
          if(bagslot3==0){bagslot3=3;}
        }//end if 2 is full
        if(bagslot2==0){bagslot2=3;}
      }//end if 1 is full
      if(bagslot1==0){bagslot1=3;}
      cout << "...Press Enter To Continue...\n";
      getchar();
      std::system("clear");
      tempvar2="ok";
      ifOK2(tempvar2);
      break;
    }//end case 3 speed

    default:
    {
      cout << "error code 012\n";
      break;
    }//end default
  }//end switch
}//end aPotion void



void My_class::makeTheLevel(){

int finalNumber, randomNumber, randomNumber1, randomNumber2, randomNumber3, randomNumber4, randomNumber5, randomNumber6;
srand(time(NULL));


string inThisPlace;


std::random_device rd;
std::mt19937 e{rd()}; // or std::default_random_engine e{rd()};

for (int x = 0; x < 34; x++){
  for (int y = 0; y < 102; y++){

    std::uniform_int_distribution<int> dist{0, 16};
    randomNumber = dist(e);

    switch (randomNumber) {
      case 0:

randomNumber2 = dist(e);
randomNumber3 = dist(e);

if(randomNumber2==0&&randomNumber3==0)
{

        inThisPlace = "×"; // is treasure [0-2]

}
else
{
inThisPlace = " ";
}

        break;
      case 1:

randomNumber2 = dist(e);
randomNumber3 = dist(e);
if(randomNumber2==1&&randomNumber3<8)
{

        inThisPlace = "ƒ"; // is friend [1-5]
}
else
{
inThisPlace = " ";
}
        break;
      case 2:
randomNumber2 = dist(e);
randomNumber3 = dist(e);
if(randomNumber2==1&&randomNumber3<5)
{
        inThisPlace = "░"; // is level1fiend [0-2]
}else{inThisPlace=" ";}
        break;
      case 3:
        randomNumber2 = dist(e);
        randomNumber3 = dist(e);
        if(randomNumber2==1&&randomNumber3<5){
          if(playerLevel>=3){
            inThisPlace = "▒"; // is level2fiend [0-2] only if char is lvl..
          }else{inThisPlace=" ";}
        }else{inThisPlace=" ";}
        break;
      case 4:
randomNumber2 = dist(e);
randomNumber3 = dist(e);
if(randomNumber2==1&&randomNumber3<5)
{
if(playerLevel>=5){
        inThisPlace = "▓"; // is bossfight [0-2] only if char is lvl..
}else{inThisPlace=" ";}
}else{inThisPlace = " ";}
        break;
      case 5:
randomNumber2=dist(e);
randomNumber3=dist(e);

////////////////////////////////////////////////////////////////////////
if(lWeapons>8){inThisPlace=" ";break;}
////////////////////////////////////////////////////////////////////////

if(randomNumber2==5&&randomNumber3==5){
        inThisPlace = "‡"; // is weapon [1-3]

        lWeapons++;

}else{inThisPlace = " ";}
        break;
      case 6:
randomNumber2=dist(e);
randomNumber3=dist(e);
if(randomNumber2==5&&randomNumber3==5){
        inThisPlace = "§"; // is ability [0-2]
}else{inThisPlace=" ";}
        break;
      case 7:
        randomNumber2=dist(e);
        if(randomNumber2>=4){
          inThisPlace = "║"; // is wallv
        }
        else{inThisPlace=" ";}
        break;
      case 8:
        inThisPlace = "═"; // is wallh
        break;
      case 9:
randomNumber2=dist(e);
if(randomNumber2==9){
        inThisPlace = "Ø"; // is bush
}else{inThisPlace=" ";}
        break;
      case 10:
        randomNumber2=dist(e);
        if (randomNumber2>=8){
          inThisPlace = "^"; // is entranceup
        }
        else{inThisPlace=" ";}
        break;
      case 11:
        randomNumber2=dist(e);
        if (randomNumber2>=8){
          inThisPlace = "<"; // is entranceleft
        }
        else{inThisPlace=" ";}
        break;
      case 12:
        randomNumber2=dist(e);
        if (randomNumber2>=8){
          inThisPlace = ">"; // is entranceright
        }
        else{inThisPlace=" ";}
        break;
      case 13:
        randomNumber2=dist(e);
        if (randomNumber2>=8){
          inThisPlace = "v"; // is entrancedown
        }
        else{inThisPlace=" ";}
        break;
      case 14:
        randomNumber2=dist(e);
        randomNumber3=dist(e);
        if (randomNumber2==randomNumber3){
          inThisPlace = "█"; // is locked door
        }
        else{
          inThisPlace = "═";
        }
        break;
      case 15:
randomNumber2=dist(e);
randomNumber3=dist(e);
if(randomNumber2==15&&randomNumber3>13){
        inThisPlace = "?"; // is aMystery [5-8]
}else{inThisPlace=" ";}
        break;
      case 16:
        inThisPlace = " "; // is nothing there (null)
        break;
    }

    if (y >= 0) {
      if (myPlayArea[x][y-1] == inThisPlace){
       myPlayArea[x][y] = " ";
      }else{
        myPlayArea[x][y] = inThisPlace;
      }
    }
  }
}

//now, time to filter this to make more sense////////
//first filter arranges the inners

for (int l = 0; l < 34; l++){
  for (int k = 0; k < 102; k++){
    std::uniform_int_distribution<int> dist{0, 16};
    if (k >=0 && k <= 102) {

      //make sure locked doors exist in between walls
      if (myPlayArea[l][k] =="█"){
        if (l %2 == 0){
          if (myPlayArea[l][k-1] == "═"){
            myPlayArea[l][k+1]="═";
          }
          else if (myPlayArea[l][k+1] == "═"){
            myPlayArea[l][k-1]="═";
          }
          else{
            myPlayArea[l][k] = "═";
          }
        }
        else{
          myPlayArea[l][k] = " ";
        }
      }

      //make sure down exits exist on line 34
      else if(myPlayArea[l][k]=="v"){
        if(l==33){}
        else{myPlayArea[l][k]=" ";}
      }

      //make sure left exits exist on column 0
      else if(myPlayArea[l][k]=="<"){
        if(k==0){}
        else{myPlayArea[l][k]=" ";}
      }

      //make sure right exits exist on column 102
      else if(myPlayArea[l][k]==">"){
        if(k==101){}
        else{myPlayArea[l][k]=" ";}
      }

      //make sure up exits exist on line 0
      else if(myPlayArea[l][k]=="^"){
        if(l==0){}
        else{myPlayArea[l][k]=" ";}
      }

      //make sure horizontal walls don't exist on columns 0 or 102
      //put horizontal walls only on even lines(rows)
      else if(myPlayArea[l][k]=="═"){
        if(k==0||k==102){myPlayArea[l][k]="║";}
        if(l%2!=00){myPlayArea[l][k]=" ";}
        if(l%2==00){
          randomNumber2=dist(e);
          if (randomNumber2>=7){
            myPlayArea[l][k-1]="═";
            myPlayArea[l][k+1]="═";
          }
        }
      }

      //make sure vertical walls don't exist on rows 0 or 34
      //put vertical walls only on odd lines(rows)
      //(but add some back if it makes sense aesthetically)
      //also remove some duplicates
      else if(myPlayArea[l][k]=="║"){
        if(l==0||l==33){myPlayArea[l][k]=" ";}
        if(l%2==00){myPlayArea[l][k]=" ";}
        if(l%2!=00){
          randomNumber2=dist(e);
          if (randomNumber2>=8){
            if (l>=4&&l<=30){
              if (myPlayArea[l-2][k-1]!="║"&&myPlayArea[l-2][k+1]!="║"&&myPlayArea[l+2][k-1]!="║"&&myPlayArea[l+2][k+1]!="║"){
                myPlayArea[l-2][k]="║";
                myPlayArea[l+2][k]="║";
                if (myPlayArea[l-1][k]==" "){
                  myPlayArea[l-1][k]="║";
                }
                if (myPlayArea[l+1][k]==" "){
                  myPlayArea[l+1][k]="║";
                }
                if (myPlayArea[l][k-1]=="║"){
                  myPlayArea[l][k]=" ";
                }
              }
            }
          }
        }
      }
//end if and fors
    }
  }
}

/// end of first filter ///
//// next filter is to add outer edges

int nTreasures, nFriends, nLevel1fiends, nLevel2fiends, nBossfights, nWeapons, nAbilities = 0;
int nWallv, nWallh, nBush, nEntranceup, nEntranceleft, nEntranceright, nEntrancedown = 0;
int nLockeddoors, nMysteries, nNothingthere = 0;
int mDoor=0;

for (int d = 0; d < 34; d++){
  for (int h = 0; h < 102; h++){
    //line 0
    if (d==0){
      if (myPlayArea[d][h]=="^"){nEntranceup+=1;myPlayArea[d+1][h]=" ";}
      else if (myPlayArea[d][h]!="^"){myPlayArea[d][h]="═";}
    }
    if (d==1){
      if (nEntranceup>=1){}
      else if (nEntranceup<1){
        myPlayArea[0][51]="^";myPlayArea[1][51]=" ";
        nEntranceup=1;
      }
    }
    //line 33
    if (d==33){
      if (myPlayArea[d][h]=="v"){myPlayArea[d-1][h]=" ";}
      if (myPlayArea[d][h]!="v"){myPlayArea[d][h]="═";}
    }

    //column 0
    if (h==0&&d>0){
      if (myPlayArea[d][h]=="<"){myPlayArea[d][h+1]=" ";}
      if (myPlayArea[d][h]!="<"){myPlayArea[d][h]="║";}
    }
    //column 102
    if (h==101&&d>0){
      if (myPlayArea[d][h]==">"){myPlayArea[d][h-1]=" ";}
      if (myPlayArea[d][h]!=">"){myPlayArea[d][h]="║";}
    }


//fors
  }
}

//next filter: mystery door
for (int d2 = 0; d2 < 34; d2++){
  for (int h2 = 0; h2 < 102; h2++){
    if(myPlayArea[d2][h2]=="█"){mDoor++;}
  }
}
if(mDoor>0){
std::mt19937 e3{rd()};
std::uniform_int_distribution<int> dist{0, 33};
randomNumber2=dist(e3);
randomNumber3=dist(e3);
myPlayArea[randomNumber2][randomNumber3]="=";
}

/*
for (int i = 0; i < 34; i++){
  for (int j = 0; j < 102; j++){
      cout << myPlayArea[i][j];
  }
  cout << "\n";
}
*/
}


int main () {

// creating a string to hold options
string theOptions;

theOptions = " 1 : \"I'm okay. Just a little out of it.\"\n 2 : \"My leg is aching. I think I may have strained it.\"\n 3 : Sit there in silence.\n\n";

int caseOnes, caseTwos, caseThrees, caseFours, caseFives, caseSixes, caseSevens, caseEights, caseNines, case10s = 0;
int case11s, case12s, case13s, case14s, case15s, case16s = 0;
int case0s;
int finalNumber, randomNumber, randomNumber1, randomNumber2, randomNumber3, randomNumber4, randomNumber5, randomNumber6;
srand(time(NULL));


/* Got these numbers approx.
case 0: 0
case 1: 3
case 2: 0
case 3: 1
case 4: 0
case 5: 5
case 6: 1
case 7: 62
case 8: 33
case 9: 30
case 10: 107
case 11: 96
case 12: 91
case 13: 104
case 14: 100
case 15: 8
case 16: 2827
--
0 × is treasure [0-2]
1 ƒ is friend [1-5]
2 ░ is level1fiend [0-2]
3 ▒ is level2fiend [0-2] only if char is lvl..
4 ▓ is bossfight [0-2] only if char is lvl..
5 ‡ is weapon [1-3]
6 § is ability [0-2]
7 ║ is wallv
8 ═ is wallh
9 Ø is bush
10 ^ is entranceup
11 < is entranceleft
12 > is entranceright
13 v is entrancedown
14 █ is locked door
15 ? is aMystery [5-8]
16 0 is nothing there (null)
--
36 length (2 used for prompts/health/etc, so lets think 34)
102 width
102x34 = 3468 char
¤ is player
*/
// Copying off of the working model here


int playerLevel = 1;
int playerLife = 100, playerPower = 1, playerDefense = 1, playerMagic = 1;
string whichWay;
int charX, charY;


My_class obj;
obj.makeTheLevel();

obj.myPlayArea[34][0]=" Tip: Perhaps you (¤) should go find Nancei (N). || ";
obj.myPlayArea[34][1]=" Lvl: ";
obj.myPlayArea[34][2]=to_string(playerLevel);
obj.myPlayArea[34][3]=" | Life: ";
obj.myPlayArea[34][4]=to_string(playerLife);
obj.myPlayArea[34][5]=" | Pwr: ";
obj.myPlayArea[34][6]=to_string(playerPower);
obj.myPlayArea[34][7]=" | Def: ";
obj.myPlayArea[34][8]=to_string(playerDefense);
obj.myPlayArea[34][9]=" | Mag: ";
obj.myPlayArea[34][10]=to_string(playerMagic);
obj.myPlayArea[32][51]="¤";
obj.myPlayArea[32][50]=" ";
obj.myPlayArea[32][52]=" ";
obj.myPlayArea[31][51]=" ";
//temp
obj.myPlayArea[32][49]="‡";obj.myPlayArea[32][50]=" ";
obj.myPlayArea[31][49]="░";obj.myPlayArea[31][50]=" ";
obj.myPlayArea[30][49]="§";obj.myPlayArea[30][50]=" ";
obj.myPlayArea[29][49]="×";obj.myPlayArea[29][50]=" ";
obj.myPlayArea[28][49]="█";obj.myPlayArea[28][50]=" ";
//  printf("\033[31mred text\n");
//  printf("\033[33;44myellow on blue\n");
//  printf("\033[0mdefault colors\n");
//end temp
charX = 32;
charY = 51;
obj.myPlayArea[29][40]="N";
obj.myPlayArea[29][39]=" ";
obj.myPlayArea[29][41]=" ";
obj.myPlayArea[30][40]=" ";
obj.myPlayArea[28][40]=" ";
obj.myPlayArea[35][0]=" ";
obj.myPlayArea[35][1]="Which way? Up[w] Left[a] Down[s] Right[d]: ";

/*
obj.printTheLevel();

string choicesMove = "Which way? Up[w] Left[a] Down[s] Right[d]: ";
cout << choicesMove;
cin >> whichWay;
*/

obj.whenMove(whichWay);

/*
while(whichWay!="w"&&whichWay!="a"&&whichWay!="s"&&whichWay!="d")
{
  std::system("clear");
  obj.printTheLevel();
  cout << choicesMove;
  cin >> whichWay;
}


if(whichWay=="a"){
  if(obj.myPlayArea[charX][charY-1]==" "){
    obj.myPlayArea[charX][charY]=" ";
    charY--;
    obj.myPlayArea[charX][charY]="¤";
    std::system("clear");
    obj.printTheLevel();
    cout << choicesMove;
    cin >> whichWay;
  }
}
*/

/*

    cout << "Which way? Up[w] Left[a] Down[s] Right[d]: ";
    cin >> whichWay;
    string whenMove(whichWay);

cin >> whichWay;
*/

/*
for (int i = 0; i < 34; i++){
  for (int j = 0; j < 102; j++){
    cout<<obj.myPlayArea[i][j];
  }
cout<<"\n";
}
*/

return 0;
}
