#include <stdio.h>

void MainMenu();
void PlayMatch();

int main(void) {
  MainMenu();
  
  return 0;
}

void MainMenu(){
  int input = 0;
  
  // make menu
  printf("-------------------------\nGuessing Game\n\n1.) Play Game\n2.) Change Max Number\n3.) Exit\n-------------------------\n");

  while ((input > 3) && (input < 1)){
    printf("Enter a number:\n");

    scanf("%d", &input);
  }

  switch (input){
    case 1:
      PlayMatch();
  }
}

// write functions for guessing
void PlayMatch(){
  int input;
  
  printf("Guess a number:\n");

  scanf("%d", &input);

  if (input ==)
}
//return to main menu