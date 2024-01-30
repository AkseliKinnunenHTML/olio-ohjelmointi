#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomNumber;
int guess;
int numOfGuesses;

int game(int maxnum){
    srand(time(NULL));
    randomNumber = rand()%maxnum+1;


    do{
        cout<<"Arvaa luku 1- "<<maxnum<<"valilta"<<endl;
        cin>>guess;
        numOfGuesses++;
        if(guess<randomNumber){
            cout<<"Arvaus oli liian pieni"<<endl;
        }
        else if(guess>randomNumber){
            cout<<"Arvaus oli liian suuri"<<endl;

        }
    }
    while(guess!=randomNumber);
    cout<<"Arvaus meni oikein"<<endl;
    cout<<"Arvasit "<<numOfGuesses<<"kertaa"<<endl;
    return 0;
}
 int main()
{
     game(10);
}
