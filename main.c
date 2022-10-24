#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void GenerateSquare();
bool TestSquare(int square[3][3]);

int main(void) {
  srand(time(0));
  
  int test[3][3] = {{4, 9 , 2}, {3, 5, 7}, {8, 1, 6}};
  int test2[3][3] = {{4, 0 , 2}, {3, 5, 7}, {8, 1, 6}};

  if (TestSquare(test)){
    printf("This is a magic squre\n");
  }
  else{
    printf("This is not a magic squre\n");
  }

  if (TestSquare(test2)){
    printf("This is a magic squre\n");
  }
  else{
    printf("This is not a magic squre\n");
  }

  GenerateSquare();
  
  return 0;
}

//random square function
void GenerateSquare(){
  int array[3][3];
  int count = 0;
  int usedNumbers[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  int index = 0;
  int randCheck;
  int used = false;

  while (1){
    count++;
    
    for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
        /*while (1){
          randCheck = ((rand() % 9) + 1);
      
          for (int k = 0; k < 9; k++){
            if (randCheck == usedNumbers[k]){
              used = true;
              break;
            }
          }

          //printf("Index: %d\n", index);

          usleep(100000);

          if (!used){
            usedNumbers[index] = randCheck;
            index++;

            array[i][j] = randCheck;
          
            break;
          }

          used = false;
        }*/

        array[i][j] = ((rand() % 9) + 1);
      }
    }

    for(int i = 0; i < 9; i++){
      usedNumbers[i] = 0;
    }

    index = 0;
    used = false;

    if (TestSquare(array)){
      printf("Magic square created\n");

      for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j ++){
          printf("%d", array[i][j]);
        }
        printf("\n");
      }

      printf("%d attempts\n", count);

      return;
    }
  }
  
}
//test square function
bool TestSquare(int square[3][3]){
  bool squareValid = true;
  
  for (int i = 0; i < 3; i++){
    if ((square[i][0] + square[i][1] + square[i][2]) != 15){
      squareValid = false;
    }
  }
  
  for (int j = 0; j < 3; j++){
    if ((square[0][j] + square[1][j] + square[2][j]) != 15){
      squareValid = false;
    }
  }

  if (((square[0][0] + square[1][1] + square[2][2]) != 15) || ((square[0][2] + square[1][1] + square[2][0]) != 15)){
    squareValid = false;
  }

  return squareValid;
}