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
class Score
{
    int total;
    string username;
public:
    Score(){};
    Score(int t, const string u);
    void printranking();
};
Score::Score(int t, const string u)
{
    total = t;
    username = u;
}
void Score::printranking()
{
    cout << "================================================" << endl;
    cout << "              Highest Score Ranking             " << endl;
    cout << "================================================" << endl;
    cout << "|Rank\t\t|Username\t\t|Score\t\t|" << endl;

    cout << "|1\t\t|" << username <<"\t\t|"<< total << endl;

    cout << "================================================" << endl;
}
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
    Score* s1 = new Score[9];
    string choice;
    string ans;
    string username;
    int num;
    int score=0;
    int i = 0;
    int j = 0;
    int streak = 0;
    int next = 0;
    while (next != 1)
    {
    cout<< "select difficulty:(1-3) ";
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
        cout<<"position(P) \t Value(V) \t Not Match(M)"<<endl;
        cin>>choice;
        if (choice == ans){
            score++;
            score = score + streak;
            cout << "correct! Your current score is: " << score;
            streak++;
        }
        else{
            cout << "Oops! Your current score is: " << score;
            streak = 0;
        }
        cout<<endl;
        i++;
    }
    cout<<"Congraturation, Score: "<<score<<endl;
    cout << "Please enter ur name: ";
    cin >> username;
    s1[j] = Score(score, username);
    s1[j].printranking();
    cout << "would u like to try again?(yes[0] or no[1]): ";
    cin >> next;
    j++;
    delete [] b1;
    Board* b1  = new  Board[20];
    i=0;
    }
    return 0;
}
