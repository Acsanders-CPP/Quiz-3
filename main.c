#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ChangeMaxNumber();
void MainMenu();
void PlayMatch(int maxNumber);

int main(void) {
  srand(time(0));
  
  MainMenu();
  
  return 0;
}

int ChangeMaxNumber(){
  int input = -1;
  
  while ((input < 1) || (input > INT_MAX)){
    printf("Enter the max number:\n");

    scanf("%d", &input);
  }

  printf("Current max is now %d\n", input);

  return input;
}

void MainMenu(){
  int input = 0;
  int maxNumber = 10;


  while (1){
    input = 0;
    
    // make menu
    printf("-------------------------\nGuessing Game\n\n1.) Play Game\n2.) Change Max Number\n3.) Exit\n-------------------------\n");

    while ((input > 3) || (input < 1)){
      printf("Enter a number:\n");

      scanf("%d", &input);
    }

    switch (input){
      case 1:
        PlayMatch(maxNumber);
        break;
      case 2:
        maxNumber = ChangeMaxNumber();
        break;
      case 3:
        return;
      default:
        printf("Invalid input\n");
        break;
    }
  }
}

// write functions for guessing
void PlayMatch(int maxNumber){
  int input;
  int correctNumber = (rand() % maxNumber) + 1;

  while (1){
    printf("Guess a number (Current max is %d):\n", maxNumber);

    scanf("%d", &input);
    
    if (input > correctNumber){
      printf("Lower\n");
    }
    else if (input < correctNumber){
      printf("Higher\n");
    }
    else{
      printf("You win\n");

      return;
    }
  }
}
//return to main menu