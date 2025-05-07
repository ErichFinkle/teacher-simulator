#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>   // To use string variables.
#include <vector>   // To use vectors to store Event lists.
#include <cstdlib>  // Used for rand() to generate random numbers.
#include <ctime>    // Used for time() to seed RNG based on current time.
#include "Teacher.h" // Needs to access Teacher.h to correctly adjust stats.
using namespace std;

// EVENT BASE CLASS
class Event {
private:
  string description;
  int moraleChange;
  int fatigueChange;
  int reputationChange;

public:
  // This is the constructor that initializes an event and its effects.
  Event(string desc, int mChange, int fChange, int rChange)
    : description(desc),
      moraleChange(mChange), fatigueChange(fChange), reputationChange(rChange) {}

  // This method applies the event’s effects to the Teacher object.
  void trigger(Teacher& t) const {
    cout << "[Event] " << description << endl;
    t.changeMorale(moraleChange);
    t.changeFatigue(fatigueChange);
    t.changeReputation(reputationChange);
  }

  // This method simply returns the event's description.
  string getDescription() const { return description; }
};

// EVENT RANDOMIZER
Event getRandomEvent() {
    // Initializes the event pool. Static make ssure it only happens one time.
    static vector<Event> eventPool = {
      // Positive events that benefit the teacher.
      Event("Some free time lets everyone relax.", 10, -10, 0),
      Event("The principal praises your teaching.", 15, 0, 5),
      Event("A student thanks you after class.", 10, 0, 5),
      Event("A student aces a tough test — they thank you for preparing them.", 10, 0, 5),
      Event("The school provides free coffee in the staff lounge.", 5, -5, 0),
      Event("Your class spontaneously cleans up the room before the bell.", 8, -5, 5),
      Event("A parent sends a kind thank-you note.", 12, 0, 10),
      Event("Your lesson plan goes perfectly — every student was engaged.", 15, -5, 10),
      Event("A student actually read the syllabus. Miracles do happen.", 10, -5, 5),
      Event("Admin gave you a document camera that *almost* works. Truly blessed.", 5, -2, 3),
      Event("Your lesson only got interrupted by one announcement. New record!", 8, -3, 4),
      Event("You graded all your papers before midnight! You're tired, but happy.", 12, -8, 6),
      Event("Nobody asked, 'Can I use the restroom?' today. Are you dreaming?", 15, -5, 10),

      // Negative events that hurt the teacher.
      Event("A safety drill disrupts your lesson.", -10, 20, 0),
      Event("You get a harsh email from an angry parent.", -15, 0, -10),
      Event("Half your class didn't do the homework.", -12, 7, -8),
      Event("You forgot to submit attendance and got a warning.", -8, 0, -8),
      Event("A student crashes out during your lesson.", -12, 6, -6),
      Event("You spill coffee on your new Quiz — it’s ruined.", -8, 6, 0),
      Event("An internet outage ruins your digital lesson.", -10, 0, -7),
      Event("A fight breaks out in the hallway — your class gets disrupted.", -12, 15, 0),
      Event("A student brought their emotional support lizard. It bit someone.", -15, 8, -15),
      Event("The copier jammed again. You challenged it to a duel.", -10, 10, -6),
      Event("A fire alarm test occurs. During your test. Again.", -12, 12, -6),
      Event("A student turned in their essay — but it's all ChatGPT.", -12, 5, -6)
    };

    // Seeds the RNG for events. We use static again so it only happens once.
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(0)));
        seeded = true;
    }

    // Calls a random number and uses modulo to make it call one of the events.
    int index = rand() % eventPool.size(); // Calls a random number.
    return eventPool[index]; // Returns the event stored at the generated index.
}

#endif // EVENT_H
