#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <iomanip> 
// #include <vector>

using namespace std;

class Unit{
    string name;
    string type;
    int level;
    string wordforguess;
    string hint1forguess;
    string hint2forguess;
    string wordfile;
    string hint1file;
    string hint2file;
    string history;
    string textline;
    string wordlist[126] = {};
    string hint1list[126] = {};
    string hint2list[126] = {};
    ifstream source;
    int tries;
    char Guess;
    bool CorrectGuess;
    int randNum;
    int k;
    int score;
    int Protect;
    int Hint;
  public:
    Unit(string ,string ,string ,string , string);
    void welcome();
    void updatehangmanlevel();
    void ReadWord();
    void SWITCHK();
    void STARTGAME();
    void addProtect();
    void random();
    void Readhistory();
};

Unit::Unit(string n ,string filename ,string hint1 ,string hint2 ,string filehistory){
  name = n;
  wordfile = filename;
  hint1file = hint1;
  hint2file = hint2;
  history = filehistory;
  type = "START";
  tries = 6;
  CorrectGuess = false;
  k = 0;
  level = 0;
  score = 0;
  Hint = 0;
  Protect = 0 ;
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
  cout<<"\n\n==================================================\n\n" ;
  cout<<"##################################################\n\n" ;
  cout<<"==================================================\n\n" ;
  cout<<"   # "<<"WELCOME > "<< name <<" < TO OUR GAME #\n\n" ;
  cout<<"==================================================\n\n" ;
  cout<<"##################################################\n\n" ;
  cout<<"==================================================" ;
  Sleep(4000);
  system("CLS");
}

//อัพเดทตัว hangman
void Unit::updatehangmanlevel(){
  if(level == 18){
      cout<<"\n**************************************************"<<endl;
      cout<<"                   WIN!!"<<endl;
      cout<<"**************************************************"<<endl;
      cout<<"\n--------------------------------------------------"<<endl;     //15x50
      cout<<"l                      __}__                      "<<endl;
      cout<<"l                      l_l_l__                    "<<endl;
      cout<<"l                     ( *.* )                     "<<endl;
      cout<<"l                       _l_                       "<<endl;
      cout<<"l                     /  l  \\                    "<<endl;
      cout<<"l       You          /   l   \\       WIN!       "<<endl;
      cout<<"l                        l                        "<<endl;
      cout<<"l                       / \\                      "<<endl;
      cout<<"l                      /   \\                     "<<endl;
      cout<<"l                    _/     \\_                   "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"l                                                 "<<endl;
      cout<<"__________________________________________________"<<endl;
  }else if(tries==6){
      cout<<"\n--------------------------------------------------"<<endl;     //15x50
      cout<<"l                                                 "<< "\t\tScore = " << score << endl;
      cout<<"l                                                 "<< "\t\tProtect = " << Protect << endl;
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
      cout<<"l                                                 "<< "\t\tProtect = " << Protect << endl;
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
      cout<<"l                      l_l_l__                    "<< "\t\tProtect = " << Protect << endl;
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
      cout<<"l                      l_l_l__                    "<< "\t\tProtect = " << Protect << endl;
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
      cout<<"l                      l_l_l__                    "<< "\t\tProtect = " << Protect << endl;
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
      cout<<"l                      l_l_l__                    "<< "\t\tProtect = " << Protect << endl;
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
    }else if(tries == 0){
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

//อ่านไฟล์word.txt hint1.txt hint2.txt
void Unit::ReadWord(){
  source.open(wordfile);
  int i=0;                           
  while(getline(source,textline)){
    wordlist[i]=textline;
    i++;
  }
  source.close();
  source.open(hint1file);
  int j=0;                           
  while(getline(source,textline)){
    hint1list[j]=textline;
    j++;
  }
  source.close();
  source.open(hint2file);
  int l=0;                           
  while(getline(source,textline)){
    hint2list[l]=textline;
    l++;
  }
  source.close();
}

//แสดงประวัติของผู้เล่นโดยแสดงชื่อและคะแนน(เรียงจากคนที่เล่นเป็นคนแรกไปยังล่าสุด)
void Unit::Readhistory(){
  int i=1 ;
  ofstream dest(history,ios::app);
  dest << setw(15) << name << setw(20) << score << endl;
  dest.close();
  source.open(history);
  cout << "-----------------Playerboard------------------\n";
  cout << setw(21)<<"name" << setw(21) <<"score\n";
  while(getline(source,textline))
  {
    cout <<setw(5)<< i<< "." << textline <<"\n";
    i++;
  }
  cout <<"-----------------------------------------------";
  source.close();
}

//ช่วงการสุ่มคำ
void Unit::SWITCHK(){
  if(level == 0) k = 1;
  if(level == 1) k = 8;
  if(level == 2) k = 15;
  if(level == 3) k = 22;
  if(level == 4) k = 29;
  if(level == 5) k = 36;
  if(level == 6) k = 43;
  if(level == 7) k = 50;
  if(level == 8) k = 57;
  if(level == 9) k = 64;
  if(level == 10) k = 71;
  if(level == 11) k = 78;
  if(level == 12) k = 85;
  if(level == 13) k = 92;
  if(level == 14) k = 99;
  if(level == 15) k = 106;
  if(level == 16) k = 113;
  if(level == 17) k = 120;
}

//การได้รับโล่ป้องกัน
void Unit::addProtect(){
  if(level == 0) Protect++;
  if(level == 3) Protect++;
  if(level == 6) Protect++;
  if(level == 9) Protect++;
  if(level == 12) Protect++;
  if(level == 15) Protect++;
}

//random ตัวเลขในช่วง
void Unit::random(){
  if( (level == 0) or (level == 1) or (level == 3) or (level == 4) or (level == 6) or (level == 7) or (level == 9) or (level == 10) or (level == 12) or (level == 13) or (level == 15) or (level == 16) ) randNum = rand()%7;
  if( (level == 2) or (level == 5) or (level == 8) or (level == 11) or (level == 14) or (level == 17)) randNum = rand()%6;
}



void Unit::STARTGAME(){
  string tier[7] = {"A1","A2","B1","B2","C1","C2"};

  Protect = false;
  char ArkProtect;
  while(level < 18){
    if(tries <= 0) break;
    SWITCHK();
    addProtect();
    random();
    wordforguess = wordlist[randNum+k];
    hint1forguess = hint1list[randNum+k];
    hint2forguess = hint2list[randNum+k];

    string MysteryWord(wordforguess.length(),'_');
    while(tries >= 0){
      if(true){

        cout << endl << level << " " << Hint;
        cout << endl << wordforguess << endl;
        updatehangmanlevel();

        if(tries == 0) break;
        CorrectGuess = false;

        // แสดงผล
        cout<<" This word are in level "<< tier[level/3];
        cout<<"  >> "<<level%3+1<<"/3 to next level"<<endl;
        cout<<"The word you have to guess is : "<<"\n\n";
        cout<<MysteryWord<< endl;

        //show hint
        cout << "\nmeaning: "<<hint1forguess <<endl;
        if(Hint >= 2) cout << "         "<<hint2forguess <<endl;

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
          Hint++;
          tries--;
          cout<<"Sorry, :> "<<Guess<<" <: is not part of the word" << endl;
          Sleep(1000);
          //ถามว่าป้องกันมั้ย
          if(Protect > 0){
            cout << "You want use Protect?(y/n) : " ;
            cin >> ArkProtect ;
            if(ArkProtect == 'y'){
              Protect--;
              tries++;
            }
          }
          system("CLS");
        }

        // ถ้าถูกทุกคำแล้วก็เปลี่ยน
        if(wordforguess==MysteryWord){
          Hint = 0;
          //เพิ่ม score
          if(tier[level/3] == "A1") score += 10 ;
          else if(tier[level/3] == "A2") score += 20 ;
          else if(tier[level/3] == "B1") score += 30 ;
          else if(tier[level/3] == "B2") score += 40 ;
          else if(tier[level/3] == "C1") score += 50 ;
          else if(tier[level/3] == "C2") score += 60 ;

          cout<<"\n\n______________________________________________________________________"<<endl<<endl;
          cout<<"______________________________________________________________________"<<endl<<endl;
          cout<<"______________________________________________________________________"<<endl<<endl;
          cout<<"   ::Congratulation ! You've got the word correct: >> "<<MysteryWord<<" <<"<<endl;
          cout<<"______________________________________________________________________"<<endl<<endl;
          cout<<"______________________________________________________________________"<<endl<<endl;
          cout<<"______________________________________________________________________"<<endl<<endl;
          level++;
          // Sleep(2000);
          system("CLS");
          break;
        }

        system("CLS");
      }
    }
  }
  //ใส่ตอนจบ
  if(level == 18) updatehangmanlevel();
  Readhistory();
}
