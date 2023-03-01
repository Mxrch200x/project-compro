#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;
void showhangman(int ); //case 0-6 to show different hangman 

int main(){
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
    string name;    
    getline(cin,name);
    cout<<"=================================================="<<endl<<endl;
    cout<<"# "<<"WELCOME > "<<name<<" < FOR OUR GAME #"<<endl<<endl;
    cout<<"=================================================="<<endl;

    string wordforguess;
    string textline; 
    string wordlist[120]={}; 
    ifstream source;
    source.open("engwords.txt");
    int i=0;                            //0-119 split 0-19a1 20-39a2 40-59b1 60-79b2 80-99c1 100-119c2
    while(getline(source,textline)){
      if(i<120)
        {
            wordlist[i]=textline;
            i++;
        }
    }
    source.close();

    srand(time(0));       
    int tries=6;
    char Guess; // char letter'
    bool CorrectGuess=false;
    int k=0,level=0;  //k=+20 40 60 80 เพื่อแยกคำ 
    while(level<=15){
        int randNum=rand()%20; //0-19
        switch(level){ //ถ้าตอบถูก 3 ครั้งถึงจะไปเวลถัดไป
            case 0: //a1
            {
                k=20*level/3;
                break;
            }
            case 3: //a2
            {
                k=20*level/3;
                break;
            }
            case 6: //b1
            {
                k=20*level/3;
                break;
            }
            case 9: //b2
            {
                k=20*level/3;
                break;
            }
            case 12: //c1
            {
                k=20*level/3;
                break;
            }
            case 15: //c2
            {
                k=20*level/3;
                break;
            }
        }
        //start level=0=a1 +1 when guess correct word level 3,6,9,12,15 = a1,a2,b1,b2,c1,c2;
        wordforguess=wordlist[randNum+k];
        string MysteryWord(wordforguess.length(),'*');
        //cout<<MysteryWord<<endl;
        string tier[6]={"A1","A2","B1","B2","C1","C2"};

        while(tries>=0)
        {
            if(true){
                if(tries==0)
                break;
                CorrectGuess=false;
                cout<<"\nThis word are in level _ "<<tier[level/3];
                cout<<"  >> "<<level%3+1<<"/3 to next level"<<endl;
                cout<<"The word you have to guess is :"<<"\n\n";
                cout<<randNum+k+1<<endl;  // for show ลำดับ ที่จะไปสุ่มคำศัพท์
                cout<<level<<endl;  //for show level 
                cout<<MysteryWord<<"    meaning: "<<"something to hint"<<endl;
                cout<<"\nThere are "<<MysteryWord.length() <<" letter in the word\n";
                cout<< "You have "<<tries <<" guess left\n";
                cout<<"Guess a letter : ";
                cin>>Guess;

                for(int i=0;i < MysteryWord.length();i++)          //check and change * to char that correct
                {
                    if(wordforguess[i]==Guess)  //check ทีละตัวจากคำที่เป็นโจทย์
                    {
                        MysteryWord[i]=Guess;   // เปลี่ยนจาก * เป็นตัวอักษร ปกติ
                        cout<<"Congratulation ! :> "<<Guess<<" <: is one of the letters"<<endl;
                        CorrectGuess = true;
                    }

                }
                if(wordforguess==MysteryWord)   //ถ้าเดาจนถูกหมดเหมือนโจทย์ ก็จะสรุปว่าคำนั้นคืออะไร
                {
                    cout<<"  ::Congratulation ! You've got the word correct: >> "<<MysteryWord<<" <<"<<endl;
                    cout<<"_________________________________________________________________"<<endl<<endl;
                    level++;
                    break;
                }
                if(CorrectGuess==false){
                    tries--;
                    cout<<"Sorry, :> "<<Guess<<" <: is not part of the word";
                }
            }

            switch(tries){ 
                case 6://normal floor+pole
                {
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
                    break;
                }
                case 5://add เชือก
                {
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
                    break;
                }
                case 4://add head
                {
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
                    break;
                }
                case 3://add body
                {
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
                    break;
                }
                case 2://add couple arm
                {
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
                    break;
                }
                case 1://add a leg
                {
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
                    break;
                }
                case 0://add the other leg
                {
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
                    cout<<endl;
                    cout<<"**************************************************"<<endl;
                    cout<<"                   GAME OVER!!"<<endl;
                    cout<<"**************************************************"<<endl;
                    cout<<"\n>."<<name<<".< Your English are in level : "<<tier[level/3];
                    cout<<"\n\n"<<"################\n"<<"  Leader board"<<endl<<"################\n";   //รอเก็บชื่อลงไฟล์ แล้วค่อยเอามาเรียงแล้วนับว่าใครเก่งกว่ากัน
                    cout<<"\nNo.1 : "<<"name no1";
                    cout<<"\nNo.2 : "<<"name no2";
                    cout<<"\nNo.3 : "<<"name no3";
                    cout<<"\n----------------";

                    level=100; // for leave loop
                    break;
                }
                default: 
                    cout<<"If you are seeing this line,There is an error!!";
            }
        }
    }  
    return 0;
}
