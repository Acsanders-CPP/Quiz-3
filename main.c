#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "Item.h"

int main(int argc, char* argv[]) {
  extern Item MenuItems[];
  extern int MenuEntries;

  double taxPercent;
  double tipPercent;
  double tax;
  double tip;
  double totalMealCost;

  srand(time(0));

  double MealCost = MenuItems[rand() % 4].Price;

  if (argc > 3){
    printf("Too many arguments\n");

    return 0;
  }
  else if ((argc <= 3) && (argc > 1)){
    if (argv[1] == NULL){
      int results;
      
      printf("Enter tax:\n");
      results += scanf("%lf", &taxPercent);

      assert(results == 1);

      printf("Tax Percentage: %.0lf%%\n", taxPercent);
    }
    else if (argv[1] != NULL){
      taxPercent = strtod(argv[1], &argv[1]);

      printf("Tax Percentage: %.0lf%%\n", taxPercent);
    }
    
    if (argv[2] == NULL){
      int results;
      
      printf("Enter tip:\n");
      results += scanf("%lf", &tipPercent);

      assert(results == 1);

      printf("Tip Percentage: %.0lf%%\n", tipPercent);
    }
    else if (argv[2] != NULL){
      tipPercent = strtod(argv[2], &argv[2]);

      printf("Tip Percentage: %.0lf%%\n", tipPercent);
    }
  }
  else if (argc == 1){
    int results;
    
    printf("Enter tax:\n");
    results += scanf("%lf", &taxPercent);

    printf("Tax Percentage: %.0lf%%\n", taxPercent);

    printf("Enter tip:\n");
    results += scanf("%lf", &tipPercent);

    printf("Tip Percentage: %.0lf%%\n", tipPercent);

    assert(results == 2);
  }

  tax = MealCost * (taxPercent / 100.0);
  tip = MealCost * (tipPercent / 100.0);
  totalMealCost = MealCost + tax + tip;

  printf("Meal Price: %.2lf\nTax: %.2lf\nTip: %.2lf\nTotal: %.2lf\n", MealCost, tax, tip, totalMealCost);
  
  return 0;
}