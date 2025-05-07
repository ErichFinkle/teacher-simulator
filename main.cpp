#include <iostream>  // For all input/output.
#include <string>    // For string variables.
#include "Teacher.h" // Holds data for the Teacher and provides actions.
#include "Event.h"   // Provides info for random Events that can occur.
using namespace std;

int main() {
  cout << "Welcome to the Teacher Simulator!\n";
  cout << "Become a new teacher trying to survive their first year!\n";
  cout << "Watch your teacher stats as you play; it's Game Over if Morale or Reputation reach 0!\n";
  cout << "The school year is a grueling 180 days long... will you make it?!\n\n";
  
  string lastName = "";
  cout << "Enter your last name:\n";
  getline(cin >> ws, lastName); // getline prevents issues with spaces in last names.
  
  Teacher teacher("M. " + lastName); // Initializes the teacher object using the given name.
  int currentDay = 0;
  
  // GAME LOOP: Two cycles per day (AM & PM)
  // Loop continues until Day 180 has been completed, then ends automatically.
  while (true) {
    teacher.changeFatigue(-10);
    currentDay++;
    bool skipPM = false;
    cout << "\n----- Day " << currentDay << " -----\n";
    teacher.display();
    bool actionChoiceMade = false;
        
    // AM Phase
    int actionChoice; // Declare integer to be used in selection of activities for the day.
    while (actionChoiceMade == false) {
      
      // Check for fatigue reaching 100. If so, automatically call a sub and skip the PM phase.
      if (teacher.isBurnedOut()) {
        cout << "You are completely exhausted! Calling substitute...\n";
        teacher.callSubstitute(true);
        skipPM = true;
        actionChoiceMade = true;
        break;
      }
      
      // If fatigue isn't 100, allow an action to be chosen.
      cout << "\nAM Action - Choose an action:\n";
      cout << " 1. Take a Nap\n 2. Call Substitute\n 3. Lecture\n 4. Give Quiz\n"
           << " 5. Host Fun Activity\n 6. Grade Papers\n 7. Drink Coffee\n 8. View Status\n";
      cin >> actionChoice;
      
      // If an invalid input, force input again.
      if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid choice. Input must be a number 1-8.\n";
        continue;
      }
      
      // Uses a switch case to call the appropriate method from the Teacher class. 
      if (actionChoice < 1 || actionChoice > 8) { cout << "Invalid choice. Input must be a number 1-8.\n"; }
      else if (actionChoice == 8) { teacher.display(); }
      else {
        switch (actionChoice) {
          case 1: teacher.takeNap(); break;
          case 2:
            teacher.callSubstitute(true); // Handles AM-specific call
            skipPM = true;
            break; 
          case 3: teacher.lecture(); break;
          case 4: teacher.giveQuiz(); break;
          case 5: teacher.hostFunActivity(); break;
          case 6: teacher.gradePapers(); break;
          case 7: teacher.drinkCoffee(); break;
          default: cout << "Invalid choice.\n"; continue;
        }
        actionChoiceMade = true;
      }
    }

    // Check for fatigue reaching 100. If so, automatically call a sub for PM.
    if (teacher.isBurnedOut()) {
      cout << "You are completely exhausted! Calling substitute...\n";
      teacher.callSubstitute(false);
      skipPM = true;
    }

    // Handle events possibly occuring after the AM action
    if (rand() % 100 < 40) {  // 40% chance of an event
      Event event = getRandomEvent(); 
      event.trigger(teacher);
    }

    // Check for game over conditions after AM
    if (teacher.hasQuit() || teacher.isFired()) {
      cout << "\nGAME OVER! You can no longer continue...\n";
      if (teacher.hasQuit()) { cout << "You quit due to low morale.\n"; }
      if (teacher.isFired()) { cout << "Your bad reputation got you fired.\n"; }
      break;
    }

    // PM Phase
    actionChoiceMade = false;
    if (skipPM) {
      cout << "You took the rest of the day off with a substitute.\n";
    } else {

      // Perform selected action
      while (actionChoiceMade == false) {
        
        // Check for fatigue reaching 100
        if (teacher.isBurnedOut()) {
          cout << "You are completely exhausted! Calling substitute...\n";
          teacher.callSubstitute(false);
          skipPM = false;
          actionChoiceMade = true;
          break;
        }
        
        // If fatigue isn't 100, allow an action to be chosen.
        cout << "\nPM Action - Choose an action:\n";
        cout << " 1. Take a Nap\n 2. Call Substitute\n 3. Lecture\n 4. Give Quiz\n"
             << " 5. Host Fun Activity\n 6. Grade Papers\n 7. Drink Coffee\n 8. View Status\n";
        
        cin >> actionChoice;
        
        if (cin.fail()) {
          cin.clear();
          cin.ignore(1000, '\n');
          cout << "Invalid choice. Input must be a number 1-8.\n";
          continue;
        }
        
        if (actionChoice < 1 || actionChoice > 8) { 
          cout << "Invalid choice. Input must be a number 1-8.\n"; 
        } else if (actionChoice == 8) { 
          teacher.display(); 
        } else {
          switch (actionChoice) {
            case 1: teacher.takeNap(); break;
            case 2:
              teacher.callSubstitute(false); // Handles PM-specific call
              skipPM = false;
              break; 
            case 3: teacher.lecture(); break;
            case 4: teacher.giveQuiz(); break;
            case 5: teacher.hostFunActivity(); break;
            case 6: teacher.gradePapers(); break;
            case 7: teacher.drinkCoffee(); break;
            default: cout << "Invalid choice.\n"; continue;
          }
          actionChoiceMade = true;
        }
      }

      // Handle events after PM action
      if (rand() % 100 < 40) {  // 40% chance of an event
        Event event = getRandomEvent();
        event.trigger(teacher);
      }

      // Check for game over conditions after PM
      if (teacher.hasQuit() || teacher.isFired()) {
        cout << "\nGAME OVER! You can no longer continue...\n";
        if (teacher.hasQuit()) { cout << "Your low morale caused you to quit..."; }
        if (teacher.isFired()) { cout << "You were fired due to a bad reputation..."; }
        break;
      }
      // Display stats for the end of the day
      cout << "You've completed Day " << currentDay << " of teaching!\n" << endl;
    }
  
    if (currentDay >= 180) {
      cout << "\nCONGRATULATIONS!\n";
      cout << "You've survived all 180 days of your first year teaching!\n";
      cout << "You managed to balance the chaos, grade the papers, and keep your sanity.\n";
      cout << "Well done, " << teacher.getName() << "!\n";
      break;
    }
  }

    return 0;
}
