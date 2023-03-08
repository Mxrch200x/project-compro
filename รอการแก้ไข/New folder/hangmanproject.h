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
    bool CorrectGuess;
    int randNum;
    int k;
    int score;
    bool Protect;
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
  CorrectGuess = false;
  k = 0;
  level = 0;
  score = 0;
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
  string A;
  A = (Protect) ? "Have" : "Not have" ;
  if(tries==6){
      cout<<"\n--------------------------------------------------"<<endl;     //15x50
      cout<<"l                                                 "<< "\t\tScore = " << score << endl;
      cout<<"l                                                 "<< "\t\tProtect = " << A << endl;
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
      cout<<"l                        }                        "<< "\t\tScore = " << score << endl;
      cout<<"l                                                 "<< "\t\tProtect = " << A << endl;
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
      cout<<"l                      __}__                      "<< "\t\tScore = " << score << endl;
      cout<<"l                      l_l_l__                    "<< "\t\tProtect = " << A << endl;
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
      cout<<"l                      __}__                      "<< "\t\tScore = " << score << endl;
      cout<<"l                      l_l_l__                    "<< "\t\tProtect = " << A << endl;
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
      cout<<"l                      __}__                      "<< "\t\tScore = " << score << endl;
      cout<<"l                      l_l_l__                    "<< "\t\tProtect = " << A << endl;
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
      cout<<"l                      __}__                      "<< "\t\tScore = " << score << endl;
      cout<<"l                      l_l_l__                    "<< "\t\tProtect = " << A << endl;
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
  if(level < 2){
    k = 20 * (level/3) + 1 ;
  }else if(level < 5){
    k = 20 * (level/3) + 2 ;
  }else if(level == 8){
    k = 20 * (level/3) + 3 ;
  }else if(level == 11){
    k = 20 * (level/3) + 4 ;
  }else if(level == 14){
    k = 20 * (level/3) + 5 ;
  }else if(level == 17){
    k = 20 * (level/3) + 6 ;
  }
}

void Unit::STARTGAME(){
  string tier[6] = {"A1","A2","B1","B2","C1","C2"};
  Protect = false;
  char ArkProtect;
  while(level <= 15){
    if(tries <= 0) break;

    if(level == 0) Protect = true;
    if(level == 3) Protect = true;
    if(level == 6) Protect = true;
    if(level == 9) Protect = true;
    if(level == 12) Protect = true;
    if(level == 15) Protect = true;

    randNum = rand()%20;
    wordforguess = wordlist[randNum+k];
    string MysteryWord(wordforguess.length(),'_');
    while(tries >= 0){
      if(true){
        cout << level ;
        cout << endl << wordforguess << endl;
        SWITCHK();
        updatehangmanlevel();
        if(tries == 0) break;
        CorrectGuess = false;

        // แสดงผล
        cout<<" This word are in level "<< tier[level/3];
        cout<<"  >> "<<level%3+1<<"/3 to next level"<<endl;
        cout<<"The word you have to guess is : "<<"\n\n";
        cout<<MysteryWord<<"    meaning: "<<"something to hint"<<endl;
        cout<<"\nThere are " << MysteryWord.length() <<" letter in the word\n";
        cout<< "You have "<<tries <<" guess left\n";
        cout<<"Guess a letter : ";
        cin>>Guess;

        // เปลี่ยนที่รับมาให้เป็นตัวเล็ก
        Guess = tolower(Guess);


        // เช็คว่าที่ได้รับมาถูก
        for(int i=0;i < MysteryWord.length();i++){
          if(wordforguess[i] == Guess){
            MysteryWord[i]=Guess;
            CorrectGuess = true;
            system("CLS");
          }
        }

        // เช็คว่าที่รับมาผิดไหม แล้วบอกว่าผิด
        if(CorrectGuess==false){
          tries--;
          cout<<"Sorry, :> "<<Guess<<" <: is not part of the word" << endl;
          Sleep(1000);
          if(Protect){
            cout << "You went use Protect?(y/n) : " ;
            cin >> ArkProtect ;
            if(ArkProtect == 'y'){
              Protect = false;
              tries++;
            }
          }
          system("CLS");
        }

        // ถ้าถูกทุกคำแล้วก็เปลี่ยน
        if(wordforguess==MysteryWord){

          //เพิ่ม score
          if(tier[level/3] == "A1") score += 10 ;
          else if(tier[level/3] == "A2") score += 20 ;
          else if(tier[level/3] == "B1") score += 30 ;
          else if(tier[level/3] == "B2") score += 40 ;
          else if(tier[level/3] == "C1") score += 50 ;
          else if(tier[level/3] == "C2") score += 60 ;

          cout<<"______________________________________________________________________"<<endl<<endl;
          cout<<"______________________________________________________________________"<<endl<<endl;
          cout<<"______________________________________________________________________"<<endl<<endl;
          cout<<"   ::Congratulation ! You've got the word correct: >> "<<MysteryWord<<" <<"<<endl;
          cout<<"______________________________________________________________________"<<endl<<endl;
          cout<<"______________________________________________________________________"<<endl<<endl;
          cout<<"______________________________________________________________________"<<endl<<endl;
          level++;
          Sleep(2000);
          system("CLS");
          break;
        }

        system("CLS");
      }
    }
  }
  //แสดงคะแนน
}

void Unit::test(){
}