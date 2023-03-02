#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <windows.h>

using namespace std;

class Unit{
    string name;
    string type;
  public:
    Unit(string );
    void welcome();
};

class Word{
    int level;
    string textline;
    string wordfile;
    string wordlist[120] = {};
    ifstream source;
    char getchar;
  public:
    Word(string );
    void wordlevel();
    void updatehangmanlevel();
};

Unit::Unit(string n){
  name = n;
  type = "Nname";
}

Word::Word(string filename){
  wordfile = "engwords.txt";
  level = 1;
}


void showfirst(){
  system("CLS");
  cout<<"##################################################"<<"\n#                                                #";
  cout<<"\n#       Hang-Man_English word tier test          #"<<"\n#                                                #";
  cout<<"\n##################################################"<<endl;
  cout<<"--------------------------------------------------"<<endl;     //15x50
  cout<<"l                      __}__            z               "<<endl;
  cout<<"l                      l_l_l__      Z             "<<endl;
  cout<<"l                     ( *.* )   z                 "<<endl;
  cout<<"l                       _l_                       "<<endl;
  cout<<"l                     /  l  \\                    "<<endl;
  cout<<"l                    /   l   \\                   "<<endl;
  cout<<"l         Hang           l            Man         "<<endl;
  cout<<"l                       / \\                      "<<endl;
  cout<<"l                      /   \\                     "<<endl;
  cout<<"l                    _/     \\_                   "<<endl;
  cout<<"l                                                 "<<endl;
  cout<<"l                English Word Test                "<<endl;
  cout<<"__________________________________________________"<<endl;   //first page to show any detail
  cout<<"Press Your Name (and enter) To Continue"<<endl;
  cout<<"Name : "<<">";
}

void Unit::welcome(){
  cout<<"==================================================\n\n" ;
  cout<<"# "<<"WELCOME > "<< name <<" < FOR OUR GAME #\n\n" ;
  cout<<"==================================================" ;
  Sleep(2000);
  system("CLS");
}

void Word::updatehangmanlevel(){
  if(level==1){
      cout<<"\n--------------------------------------------------"<<endl;     //15x50
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"__________________________________________________"<<endl;
    }else if(level==2){
      cout<<"\n--------------------------------------------------"<<endl;     //15x50
      cout<<"l                        }                        "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"__________________________________________________"<<endl;
    }else if(level==3){
      cout<<"\n--------------------------------------------------"<<endl;     //15x50
      cout<<"l                      __}__                      "<<endl;
      cout<<"l                      l_l_l__                    "<<endl;
      cout<<"l                     ( *.* )                     "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"__________________________________________________"<<endl;
    }else if(level==4){
      cout<<"\n--------------------------------------------------"<<endl;     //15x50
      cout<<"l                      __}__                      "<<endl;
      cout<<"l                      l_l_l__                    "<<endl;
      cout<<"l                     ( *.* )                     "<<endl;
      cout<<"l                        l                        "<<endl;
      cout<<"l                        l                        "<<endl;
      cout<<"l                        l                        "<<endl;
      cout<<"l                        l                        "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"__________________________________________________"<<endl;
    }else if(level==5){
      cout<<"\n--------------------------------------------------"<<endl;     //15x50
      cout<<"l                        }                        "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"__________________________________________________"<<endl;
    }else if(level==6){
      cout<<"\n--------------------------------------------------"<<endl;     //15x50
      cout<<"l                      __}__                      "<<endl;
      cout<<"l                      l_l_l__                    "<<endl;
      cout<<"l                     ( *.* )                     "<<endl;
      cout<<"l                       _l_                       "<<endl;
      cout<<"l                     /  l  \\                    "<<endl;
      cout<<"l                    /   l   \\                   "<<endl;
      cout<<"l                        l                        "<<endl;
      cout<<"l                       /                         "<<endl;
      cout<<"l                      /                          "<<endl;
      cout<<"l                    _/                           "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"__________________________________________________"<<endl;
    }else{
      cout<<"\n**************************************************"<<endl;
      cout<<"                   GAME OVER!!"<<endl;
      cout<<"**************************************************"<<endl;
      cout<<"\n--------------------------------------------------"<<endl;     //15x50
      cout<<"l                      __}__                      "<<endl;
      cout<<"l                      l_l_l__                    "<<endl;
      cout<<"l                     ( *.* )                     "<<endl;
      cout<<"l                       _l_                       "<<endl;
      cout<<"l                     /  l  \\                    "<<endl;
      cout<<"l       You          /   l   \\       Dead!       "<<endl;
      cout<<"l                        l                        "<<endl;
      cout<<"l                       / \\                      "<<endl;
      cout<<"l                      /   \\                     "<<endl;
      cout<<"l                    _/     \\_                   "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"__________________________________________________"<<endl;
    }
}

void Word::wordlevel(){
  source.open(wordfile);
  int i=0;                           
  while(getline(source,textline)){
    wordlist[i]=textline;
    i++;
  }
  source.close();
}


