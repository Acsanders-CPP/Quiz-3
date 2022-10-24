#include <stdio.h>
#include <stdbool.h>

void TestSquare(int square[3][3]);

int main(void) {

  int test[3][3] = {{4, 9 , 2}, {3, 5, 7}, {8, 1, 6}};
  TestSquare(test);
  return 0;
}

//random square function

//test square function
void TestSquare(int square[3][3]){
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

  if (squareValid){
    printf("This is a magic square\n");
  }
  else{
    printf("This is not a magic square\n");
  }
}