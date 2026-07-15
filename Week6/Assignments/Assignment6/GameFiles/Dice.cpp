#include "Dice.h"
#include <cstdlib>
#include <ctime>
 
// TODO: 
// - Should return a random integer between 1 and 6, inclusive.
// - Think carefully about where to seed the random number generator.
//   If you seed it INSIDE this function, what happens every time it's called?
 
int RollDice() {
     // TODO: 
     static bool seeded = false; // static variable makes sure that the random number generator is only seeded once
     if (!seeded) { // if seeded is false
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // seeds the random number generator with the current time
    seeded = true; // sets seeded to true so that the random number generator is not seeded again
  }
  int roll_result = (std::rand() % 6) + 1; // generates a random number between 1 and 6
  return roll_result;
}