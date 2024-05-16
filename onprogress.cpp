#include <iostream>
#include <time.h>
#include <string>

using namespace std;

class Sequence{
    int random_p= rand() % 9;
    int random_n= rand() % 10;
    string arr[9];
public:
    Sequence(){dseq();};
    int getrandom_p(){return random_p;};
    int getrandom_n(){return random_n;};
    string *getarr(){return &arr[0];};
    void dseq();
};
class Board{
    int square=3;
    char *parr;
    Sequence s1;
public:
    Board(){}
    string compare(Board b2);
    void printboard();
};
void Sequence::dseq()
{
    string c1 = to_string(getrandom_n());
        for(int k = 0; k<9; k++)
    {
        if (k==getrandom_p())
        {
            arr[k]=c1;
        }
        else
        {
            arr[k]=' ';
        }
    }
}
string Board::compare(Board b2){
     if ((s1.getrandom_p() == b2.s1.getrandom_p())&&(s1.getrandom_n() == b2.s1.getrandom_n())){
        return "N";
     }
     else if(s1.getrandom_p() == b2.s1.getrandom_p()){
        return "P";
     }
    else if(s1.getrandom_p() == b2.s1.getrandom_p()){
        return "PN";
     }
     else {return "F";}
}
void Board::printboard(){
    string *parr = s1.getarr();
    s1.dseq();
    int n = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j<3;j++)
        {
            cout<<"     |";
        }
        cout<< endl;
        for(int j = 0; j<3;j++)
        {
            cout<< "  "<<*(parr+n) <<"  |";
            n++;
        }
        cout<< endl;
        for(int j = 0; j<3;j++)
        {
            cout<<"_____|";
        }
        cout<< endl;
    }
}
int main(){
    srand(time(0));
    Board* b1  = new  Board[20];
    string choice;
    string ans;
    int num;
    int score=0;
    int i = 0;
    cout<< "select difficulty: ";
    cin>> num;
    while(i < num){
        b1[i].printboard();
        cout<<endl;
        i++;
    }
    cout<<endl;
    while (i<20){
        b1[i].printboard();
        ans = b1[i].compare(b1[i-num]);
        cout<<"position(P) \t Number(N)"<<endl;
        cin>>choice;
        if (choice == ans){
            score++;
        }
        else{
            score--;
        }
        cout<<endl;
        i++;
    }
    cout<<"Congraturation, Score: "<<score<<endl;
}


