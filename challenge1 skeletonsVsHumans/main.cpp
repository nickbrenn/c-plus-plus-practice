#include <iostream>
#include <string>
#include <random>
#include <ctime>
// #include <typeinfo>

using namespace std;

int main()
{
  default_random_engine randomGenerator(time(0));
  uniform_real_distribution<float> roll(0.0f, 1.0f);

  float outcome;

  int humans;
  float humanDamage = 5.0f;
  int humanHealth = 10;
  int skeletons;
  float skeletonDamage = 2.5f;
  int skeletonHealth = 3;

  int humanDeaths = 0;
  int skeletonDeaths = 0;

  cout << "Input the number of humans: ";
  cin >> humans;
  cout << "Input the number of skeletons: ";
  cin >> skeletons;

  float humanAttack;
  float skeletonAttack;

  float curHumanHealth = humanHealth;
  float curSkeletonHealth = skeletonHealth;

  while (humans > 0 && skeletons > 0)
  {
    humanAttack = roll(randomGenerator) * humanDamage;
    skeletonAttack = roll(randomGenerator) * skeletonDamage;
    curHumanHealth -= skeletonAttack;
    curSkeletonHealth -= humanAttack;
    // cout << curHumanHealth << endl;
    // cout << curSkeletonHealth << endl;
    if (curHumanHealth <= 0)
    {
      humans--;
      humanDeaths++;
      // cout << "Human dies!" << endl;
      curHumanHealth = humanHealth;
    }
    if (curSkeletonHealth <= 0)
    {
      skeletons--;
      skeletonDeaths++;
      // cout << "Skeleton dies!" << endl;
      curSkeletonHealth = skeletonHealth;
    }
  }

  if (skeletons == 0)
  {
    cout << "Humans win with " << humans << " humans left!\n";
  }
  else
  {
    cout << "Skeletons win with " << skeletons << " skeletons left!\n";
  }
  cout << endl
       << humanDeaths << " humans died and " << skeletonDeaths << " skeletons died";

  return 0;
}

// int findtype(void num)
// {
//   cout << typeid(num).name() << endl;
// }

int gameInit()
{
  string playerName = "Ben";
  int age;
  cout << "What is your name sir knight? ";
  cin >> playerName;
  cout << "Hello Sir " << playerName << ".\n";
  cout << "How old are you? ";
  cin >> age;
  cout << "You are " << age << " years old.\n";

  return 0;
}