#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MainMenu(int maxNumber);
void PlayMatch(int maxNumber);

int main(void) {
  srand(time(0));
  
  MainMenu();
  
  return 0;
}

void MainMenu(){
  int input = 0;
  int maxNumber = 10;
  
  // make menu
  printf("-------------------------\nGuessing Game\n\n1.) Play Game\n2.) Change Max Number\n3.) Exit\n-------------------------\n");

  while ((input > 3) && (input < 1)){
    printf("Enter a number:\n");

    scanf("%d", &input);
  }

  switch (input){
    case 1:
      PlayMatch(maxNumber);
      break;
    default:
      printf("Invalid input\n");
      break;
  }
}

// write functions for guessing
void PlayMatch(int maxNumber){
  int input;
  int correctNumber = (rand() % maxNumber) + 1;
  
  printf("Guess a number (Current max is %d):\n", maxNumber);

  scanf("%d", &input);

  if (input == correctNumber){
    printf("You win\n");

    return;
  }
}
//return to main menu