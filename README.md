# teacher-simulator
C++ project for CISPROG-2 at Chaffey College. Simple game simulating the daily life of a high school teacher.

## Class:
CISPROG-2, Chaffey College Spring 2025

## Project Title:
Teacher Simulator (Final Project)

## Authors:
 - Erich Finkle - Programmer
 - Christian De Loa - Bug Tester (and extremely patient listener to my venting)

## Description:
This project is a C++ text-based game where the player fills the role of a high school teacher, choosing actions each day that affect their morale, fatigue, and reputation.
To mix things up, random events can occur, which also affect fatigue, morale, and reputation.  The game ends if morale or reputation reaches zero, causing the teacher to quit or be fired, respectively.

## Creation process:
This project was built using OnlineGDB's C++ compiler and runtime environment. Once complete, I downloaded the files and uploaded them here to GitHub.
As an aside, I've never used GitHub before, so I'm sure it's very unprofessional, but hopefully everything works.
I confirmed that everything worked correctly on OnlineGDB and my friend was able to run it in VSC, so I figure that means we're all good!

## Files:
The game is composed of three files:
- main.cpp (The core game loop and user name input)
- Teacher.h (Header file containing all data for the Teacher)
- Event.h (Header file containing all data for the Events)

## Notes:
Since I'm still pretty new to coding, it took me a long time to figure out how to get some things to work while others went surprisingly smooth. 
I had to consult with Christian a couple times to figure out where I was getting weird errors that I couldn't figure out, like the first time with an error in my switch cases causing the Day/AM/PM cycle to not loop properly.
I later found out this was entirely due to me forgetting how switch worked, and using break and continue incorrectly, because of course it was.
It didn't help that I've also been teaching Python to my high school students this year, and my brain was struggling to differentiate on more than one occasion.

  That aside, on the whole the project went pretty quickly and I'm happy with how it turned out. It's not particularly complex, I suppose, but it's just complex enough for me to be proud of it.
  It also marks the last project for completing my AS in CIS Programming, so... hooray!

## Known issues:
As of now, the only problem I couldn't figure out how to fix was how to handle intentionally messed up input for the Day/AM/PM cycle. 

  If the user enters a hybrid input that starts with a number, like 3asd, the program reads the number, pulls the correct action, then automatically says they've made an invalid input for the next action.
  I tried a few things with getline, but wasn't able to figure it out. So, this still exists, but as long as the user enters a number that's intentional, it works fine.
