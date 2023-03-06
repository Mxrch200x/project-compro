#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <vector>

using namespace std;

class Unit{
    string name;
    string type;
    int level;
    string wordforguess;
    string wordfile;
    string textline;
    string wordlist[126] = {};
    ifstream source;
    int tries;
    char Guess;
    string tier[6];
    bool CorrectGuess;
    int randNum;
    int k;
  public:
    Unit(string ,string );
    void welcome();
    void updatehangmanlevel();
    void ReadWord();
    void SWITCHK();
    void STARTGAME();
    void test();
};

Unit::Unit(string n ,string filename){
  name = n;
  wordfile = filename;
  type = "START";
  tries = 6;
  vector<string> tier {"A1","A2","B1","B2","C1","C2"} ;
  CorrectGuess = false;
  randNum = rand()%20;
  k = 0;
  level = 0;
}

//โชว์ตอนเริ่ม
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
  cout<<"Name : "<<"> ";
}

//แสดงหลังจากใส่ชื่อเสร็จ
void Unit::welcome(){
  cout<<"==================================================\n\n" ;
  cout<<"# "<<"WELCOME > "<< name <<" < FOR OUR GAME #\n\n" ;
  cout<<"==================================================" ;
  Sleep(4000);
  system("CLS");
}

//อัพเดทตัว hangman
void Unit::updatehangmanlevel(){
  if(tries==6){
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
    }else if(tries==5){
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
    }else if(tries==4){
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
    }else if(tries==3){
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
    }else if(tries==2){
      cout<<"\n--------------------------------------------------"<<endl;     //15x50 
      cout<<"l                      __}__                      "<<endl;
      cout<<"l                      l_l_l__                    "<<endl;
      cout<<"l                     ( *.* )                     "<<endl;
      cout<<"l                       _l_                       "<<endl;
      cout<<"l                     /  l  \\                    "<<endl;
      cout<<"l                    /   l   \\                   "<<endl;
      cout<<"l                        l                        "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"__________________________________________________"<<endl;
    }else if(tries==1){
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

//อ่านไฟล์word.txt
void Unit::ReadWord(){
  source.open(wordfile);
  int i=0;                           
  while(getline(source,textline)){
    wordlist[i]=textline;
    i++;
  }
  source.close();
}

void Unit::SWITCHK(){
  if(level == 0){
    k = 20 * (level/3) + 1 ;
  }else if(level == 3){
    k = 20 * (level/3) + 2 ;
  }else if(level == 6){
    k = 20 * (level/3) + 3 ;
  }else if(level == 9){
    k = 20 * (level/3) + 4 ;
  }else if(level == 12){
    k = 20 * (level/3) + 5 ;
  }else if(level == 15){
    k = 20 * (level/3) + 6 ;
  }
}

void Unit::STARTGAME(){
  while(level <= 15){
    if(tries <= 0){
          break; }
    wordforguess = wordlist[randNum+k];
    string MysteryWord(wordforguess.length(),'*');
    while(tries >= 0){
      if(true){
        SWITCHK();
        updatehangmanlevel();
        if(tries == 0) break;
        CorrectGuess = false;
        cout<<"\nThis word are in level _ "<< tier[level/3];
        cout<<"  >> "<<level%3+1<<"/3 to next level"<<endl;
        cout<<"The word you have to guess is :"<<"\n\n";
        cout<<MysteryWord<<"    meaning: "<<"something to hint"<<endl;
        cout<<"\nThere are " << MysteryWord.length() <<" letter in the word\n";
        cout<< "You have "<<tries <<" guess left\n";
        cout<<"Guess a letter : ";
        cin>>Guess;

        for(int i=0;i < MysteryWord.length();i++){
          if(wordforguess[i] == Guess){
            MysteryWord[i]=Guess;   // เปลี่ยนจาก * เป็นตัวอักษร ปกติ
            cout<<"Congratulation ! :> "<<Guess<<" <: is one of the letters"<<endl;
            CorrectGuess = true;
            system("CLS");
          }
        }

        if(wordforguess==MysteryWord){
          cout<<"  ::Congratulation ! You've got the word correct: >> "<<MysteryWord<<" <<"<<endl;
          cout<<"_________________________________________________________________"<<endl<<endl;
          level++;
          system("CLS");
          break;
        }

        if(CorrectGuess==false){
          tries--;
          cout<<"Sorry, :> "<<Guess<<" <: is not part of the word";
          system("CLS");
        }

        cout << endl << wordforguess << endl;
      }
    }
  }
}

void Unit::test(){
}