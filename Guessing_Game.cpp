#include <iostream>

using namespace std;
int guessCorrect(char);
int alphabetRandom();

const int MAX = 26;

int main(void)
{
    char letter;
    int guess_count = 26;
    while(guess_count != 0)
    {
        cout << "\nEnter The Guessing letter: ";
        cin >> letter;

        if(guessCorrect(letter))
        {
            cout << "\nYour Answer Was correct !";
            break;
        }
        else
            cout << "\nSorry Your answer was incorrect !";
        
        guess_count--;
        cout << "\nThe Number of Guess: " << guess_count;
    }
}

int guessCorrect(char guess)
{
    bool True = 1, False = 0;

    if(alphabetRandom() == guess)
        return True;
    
    return False;
}

int alphabetRandom()
{
    char alphabet[MAX] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n', 
        'o', 'p', 'q', 'r', 's', 't', 'u', 
        'v', 'w', 'x', 'y', 'z'
    };

    char res;

    for(int i = 0; i < 2; i++)
        res = alphabet[rand() % MAX];
    
    return res;
}
