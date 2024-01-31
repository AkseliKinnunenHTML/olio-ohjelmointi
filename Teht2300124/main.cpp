#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Game {
public:
    Game() {
        srand(time(0));
        randomNumber = rand() % (maxNumbers + 1);
        numOfGuesses = 0;
    }

    Game(int maxNum) : maxNumbers(maxNum) {
        srand(time(0));
        randomNumber = rand() % (maxNumbers + 1);
        numOfGuesses = 0;
    }

    ~Game() {
        cout << "Object cleared from stack memory" << endl;
    }

    void play() {
        cout << "Welcome to the guessing game! Guess a number between 0 and " << maxNumbers << endl;
        do {
            cout << "Enter your guess: ";
            cin >> playerGuess;
            numOfGuesses++;
            if (playerGuess == randomNumber) {
                cout << "Congratulations! You guessed the correct number." << endl;
                printGameResult();
                break;
            }
            else if (playerGuess < randomNumber) {
                cout << "Too low! Try again." << endl;
            }
            else {
                cout << "Too high! Try again." << endl;
            }
        } while (true);
    }

private:
    int maxNumbers = 100;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;

    void printGameResult() {
        cout << "Random number was: " << randomNumber << endl;
        cout << "You made " << numOfGuesses << " guesses." << endl;
    }
};

int main() {
    Game game(100);
    game.play();

    return 0;
}
