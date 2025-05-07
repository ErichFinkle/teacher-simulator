#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
  string name;
  int morale;      // 0-100, game over if 0
  int fatigue;     // 0-100, forced to rest if 100
  int reputation;  // 0-100, fired if 0

public:
  Teacher(string n = "Teacher", int m = 90, int f = 20, int r = 40)
    : name(n), morale(m), fatigue(f), reputation(r) {}

  // STAT CHANGE METHODS
  void changeMorale(int change) {
    morale += change;
    if (morale > 100) morale = 100;
    if (morale < 0) morale = 0;
  }

  void changeFatigue(int change) {
    fatigue += change;
    if (fatigue > 100) fatigue = 100;
    if (fatigue < 0) fatigue = 0;
  }

  void changeReputation(int change) {
    reputation += change;
    if (reputation > 100) reputation = 100;
    if (reputation < 0) reputation = 0;
  }

  // TEACHER ACTIONS
  void takeNap() {
    cout << "[Action] You sneak in a quick nap behind your desk.\n";
    changeFatigue(-8);
    changeMorale(2);
    changeReputation(-5);
  } // Bad for reputation, good for mental health.

  void callSubstitute(bool isMorning) {
    cout << "[Action] You call in a substitute";
    if (isMorning) {
      cout << " for the whole day.\n";
      changeFatigue(-40);
      changeMorale(5);
      changeReputation(-15);
    } // When called in the AM
    else {
      cout << " for the afternoon.\n";
      changeFatigue(-20);
      changeMorale(3);
      changeReputation(-8);
    } // When called in the PM
  } // Great for health, bad for reputation.

  void lecture() {
    cout << "[Action] You deliver a long lecture with no breaks.\n";
    changeFatigue(18);
    changeMorale(-7);
    changeReputation(6);
  } // Tiresome, but good for reputation.

  void giveQuiz() {
    cout << "[Action] You surprise the class with a pop quiz.\n";
    changeFatigue(12);
    changeMorale(-6);
    changeReputation(4);
  } // Less taxing, but hard on morale.

  void hostFunActivity() {
    cout << "[Action] You lead a fun class activity.\n";
    changeFatigue(40);
    changeMorale(12);
    changeReputation(3);
  } // Super exhausting, but great for morale.

  void gradePapers() { 
    cout << "[Action] You stay late grading assignments.\n";
    changeFatigue(25);
    changeMorale(-12);
    changeReputation(12);
  } // Super taxing, but great for reputation.

  void drinkCoffee() { 
    cout << "[Action] You drink some questionable coffee from the teacher’s lounge.\n";
    changeFatigue(-3);
    changeMorale(2);
    changeReputation(-4);
  } // Mostly just for humor, to be honest.

  // GETTER FUNCTIONS
  string getName() const { return name; }
  int getMorale() const { return morale; }
  int getFatigue() const { return fatigue; }
  int getReputation() const { return reputation; }

  // DISPLAY STATS METHOD
  void display() const {
    cout << "Teacher: " << name
         << " | Morale: " << morale
         << " | Fatigue: " << fatigue
         << " | Reputation: " << reputation
         << endl;
  }

  // STATUS CHECKS
  // Checks to see if the teacher must call a sub, is fired, or has quit.
  // 100 Fatigue = Burnout, 0 Reputation = Fired, 0 Morale = Quit.
  bool isBurnedOut() const { return fatigue >= 100; }
  bool isFired() const { return reputation <= 0; }
  bool hasQuit() const { return morale <= 0; }
};

#endif // TEACHER_H
