#include "hangmanproject.h"

int main(){
    srand(time(0));
    Word A1("A1.txt");
    Word A2("A2.txt");
    Word B1("B1.txt");
    Word B2("B2.txt");
    Word C1("C1.txt");
    Word C2("C2.txt");

    showfirst();

    string name;    
    getline(cin,name);
    Unit Nname(name);
    system("CLS");

    Nname.welcome();

    Word wordlevel();

    int tier = 1;
    cout<<"\nThis word are in level "<< tier;
    cout<<"  >> " << "/3 to next level"<<endl;
    cout<<"The word you have to guess is :"<<"\n\n";
    cout<<"Guess a letter : ";
    return 0;
}
