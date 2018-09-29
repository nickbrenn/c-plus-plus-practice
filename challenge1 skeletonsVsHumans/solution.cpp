#include <iostream>
#include <random>
#include <ctime>

using namespace std;

// these are called "forward declarations"
// also called "function prototypes"
int getNumHumans();
int getNumSkeletons();
void printResults(int numHumans, int numSkeletons, int startHumans, int startSkeletons);
void simulateBattle(int &numHumans, int &numSkeletons);

int main()
{
    int numHumans;
    int numSkeletons;

    cout << "=== Skeletons vs. Humans! ===\n\n";

    // Get the number of humans and skeletons with user input
    numHumans = getNumHumans();
    numSkeletons = getNumSkeletons();

    int startHumans = numHumans;
    int startSkeletons = numSkeletons;

    simulateBattle(numHumans, numSkeletons);

    printResults(numHumans, numSkeletons, startHumans, startSkeletons);

    return 0;
}

int getNumHumans()
{
    int numHumans;
    cout << "Enter the number of humans: ";
    cin >> numHumans;
    return numHumans;
}

int getNumSkeletons()
{
    int numSkeletons;
    cout << "Enter the number of skeletons: ";
    cin >> numSkeletons;
    return numSkeletons;
}

void printResults(int numHumans, int numSkeletons, int startHumans, int startSkeletons)
{
    if (numSkeletons == 0)
    {
        cout << "\nHumans win with " << numHumans << " humans left!\n";
    }
    else
    {
        cout << "Skeletons win with " << numSkeletons << " skeletons left!\n";
    }
    cout << endl
         << startHumans - numHumans << " humans died and " << startSkeletons - numSkeletons << " skeletons died." << endl;
}

void simulateBattle(int &numHumans, int &numSkeletons)
{
    // Don't forget to seed your random generator with time!
    static default_random_engine randomGenerator(time(NULL));
    uniform_real_distribution<float> attack(0.0f, 1.0f);

    // Human properties
    float humanAttack = 0.6f;
    float humanHealth = 250.0f;
    float humanDamage = 200.0f;
    float currentHumanHealth = humanHealth;

    // Skeleton properties
    float skeletonAttack = 0.2f;
    float skeletonHealth = 50.0f;
    float skeletonDamage = 40.0f;
    float currentSkeletonHealth = skeletonHealth;

    float attackResult;
    char turn = 'H';

    cout << "\nBeginning combat!\n\n";

    while (numHumans > 0 && numSkeletons > 0)
    {
        attackResult = attack(randomGenerator);
        if (turn == 'H')
        {
            if (attackResult <= humanAttack)
            {
                currentSkeletonHealth -= humanDamage;
                if (currentSkeletonHealth <= 0)
                {
                    numSkeletons--;
                    currentSkeletonHealth = skeletonHealth;
                }
            }

            turn = 'S';
        }
        else if (turn == 'S')
        {
            if (attackResult <= skeletonAttack)
            {
                currentHumanHealth -= skeletonDamage;
                if (currentHumanHealth <= 0)
                {
                    numHumans--;
                    currentHumanHealth = humanHealth;
                }
            }

            turn = 'H';
        }
    }
}