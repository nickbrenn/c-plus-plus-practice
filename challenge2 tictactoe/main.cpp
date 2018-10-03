#include <iostream>
#include <string>

using namespace std;

int main()
{
    const int numItems = 6;
    string shopItemNames[numItems] = {"Boots", "Sword", "Helmet", "Kitten", "Poleaxe", "Leggings"};

    cout << "*** Welcome to the item shop! ***\n";

    for (int i = 0; i < numItems; i++)
    {
        cout << shopItemNames[i] << endl;
    }

    cout << "*********\n\n";
    cout << "What would you like to buy?";

    return 0;
}