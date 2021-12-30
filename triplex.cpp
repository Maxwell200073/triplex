#include <iostream>
#include <ctime>
using namespace std;


void PrintIntroduction(int Difficulty)
{
    cout << "\n\n888888888888        88             88               8b        d8\n";                                                                 
    cout << "     88                            88                Y8,    ,8P\n";
    cout << "     88                            88                 `8b  d8'\n";    
    cout << "     88 8b,dPPYba,  88 8b,dPPYba,  88  ,adPPYba,        Y88P\n";     
    cout << "     88 88P'    'Y8 88 88P'    '8a 88 a8P_____88        d88b\n";
    cout << "     88 88          88 88       d8 88 8PP              ,8P Y8,\n";
    cout << "     88 88          88 88b,   ,a8' 88 '8b,   ,aa     d8'    `8b\n";
    cout << "     88 88          88 88`YbbdP''  88  `'Ybbd8''    8P        Y8\n";
    cout << "                       88\n";
    cout << "                       88\n\n\n";
    cout << "Your a small time thief, but that's about to change.\n";
    cout << "You're breaking into a level " << Difficulty << " safe!\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    cout << "\nEnter the correct code to open it...\n\n";
    
    // Store correct answers
    const int CodeA = (rand() % Difficulty) +3;
    const int CodeB = (rand() % Difficulty) +4;
    const int CodeC = (rand() % Difficulty) +5;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product
    cout << "There's a note on the side!\n";
    cout << "- If you forget the code, it's three numbers!\n";
    cout << "- The digits add-up to: " << CodeSum << endl;
    cout << "- The digits multiplied equal: " << CodeProduct << endl;

    // Store players guess
    int GuessA, GuessB, GuessC;
    cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    char PressB;

    // Check if player guessed correctly and notify
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        cout << "\nYou guessed right! You're in!\n"; 
        cout << "Press any button..."; 
        cin >> PressB;
        return true;
    }
    else
    {
        cout << "\nYou took so long the police arrived! Guess you can try again in 6 months.\n";
        cout << "Press any button..."; 
        cin >> PressB;
        return false;
        
    }
}

int main()
{
    srand(time(NULL)); // Create new random based on time of day   MUST include time 
    int LevelDifficulty = 1;
    int MaxDifficulty = 5;
    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();  // Clears any errors
        cin.ignore(); // Discards the buffer

        if (bLevelComplete) 
        {
            ++LevelDifficulty;
        }

    }
    cout << "\nCongrats! You can retire now.";
    return 0;
}