# ECM2433 The C Family Courswork

This project contains 3 folders labelled questions 1 to 3. Each represent the questions detailed in the specification.
Question 1 being Pig Latin, Question 2 being Shuffle and Question 3 Beggar your neighbour. Within each of these directories 
are files for the components of these questions and a Makefile. 

## Instructions for use of Q1, Q2 and Q3
- Since each question directory contains a Makefile, inorder to execute the program simply run make followed by a rule
- The Rules for each question are as follows: 
  - Question 1:
    - make piglatin - Which will create an executable allowing you to enter sentences to convert to pigLatin
    - make test_pig - Which will create an executable which will run all word defined in the specification. 
  - Question 2:
    - make demo_shuffle - Which will create an executable that runs all tests to show the riffle work 
    - make quality - Which will create an executable that runs quality checks over the riffle function
  - Question 3:
    - make single - Which will create an executable that allows you to run a single game of beggar
                    your neighbour with a specified amount of players, entered in the terminal, i.e. single 2. This will
                    also output the steps of the game. 
    - make byn - Which will create an executable that outputs the statistics of games with player
                 2-Nplayers over trials amount. All is entered in the CMD like this, byn 10 100

- To execute the files run these commands in the terminal: 
  - piglatin
  - test_pig 
  - demo_shuffle
  - quality 
  - single (amount of players)
  - byn (amount of players) (amount of trials)
