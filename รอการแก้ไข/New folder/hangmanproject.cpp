#include "hangmanproject.h"

int main(){
    srand(time(0));

    showfirst();

    string name;    
    getline(cin,name);
    Unit START(name, "word.txt");
    system("CLS");

    START.welcome();
    START.ReadWord();
    // START.test();
    START.STARTGAME();

    return 0;
}
