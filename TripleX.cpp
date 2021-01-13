#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    //This is the first welcome lines to the user:
    std::cout << R"( 
            /                                                \
           |    _________________________________________     |
           |   |                                         |    |
           |   |  C:\> Unauthorized User Detected -      |    |
           |   |                                         |    |
           |   |  Please enter the correct code          |    |
           |   |  Or the alarm will sound:               |    |
           |   |                                         |    |
           |   |       __          __           __       |    |
           |   |                                         |    |
           |   |                                         |    |
           |   |                                         |    |
           |   |                                         |    |
           |   |                                         |    |
           |   |                                         |    |
           |   |_________________________________________|    |
           |                                                  |
            \_________________________________________________/
                   \___________________________________/
                ___________________________________________
             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_
          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_
       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_
    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_
 _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_
:-------------------------------------------------------------------------:
`---._.-------------------------------------------------------------._.---')"<<"\n\n";
    std::cout << "You are a double agent breaking into your organizations secret vault...\n";
    std::cout << "Vault Security Level = " << Difficulty;
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    //Code variables:
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    //Calculating both the sum and product:
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Outputting instructions to the player:
    std::cout << "\n\n+ There are 3 numbers within the code.";
    std::cout << "\n+ The numbers add-up to: " << CodeSum;
    std::cout << "\n+ The numbers multiply to give: " << CodeProduct;
    std::cout << "\n\nEnter the correct code below:\n";

    //Prompt player to guess the secret code:
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if(CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "\nYou have entered the correct code. ***\n";
        std::cout << "You have successfully extracted a secret document! Keep going! ***\n\n";
        return true;
    }
    else
    {
        std::cout << "\nYou have entered the incorrect code. ***\n";
        std::cout << "They are getting suspicious! Be careful, and try again! ***\n\n";
        return false;
    }
}
 
int main() 
{
    srand(time(NULL)); // Create new random sequence based on time of day

    const int MaxLevel = 5;
    int LevelDifficulty = 1;

    while(LevelDifficulty <= MaxLevel) // Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if(bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    // End-game winning message:
    std::cout << "\n\n*** Great work! You have secured all of the secret documents! ***";
    std::cout << "\n*** Now, get out of there in one piece! ***\n";
    return 0;
}