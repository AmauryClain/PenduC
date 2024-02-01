#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int D;

  struct coord {
    int x;
    int y;
  };

  struct coord A;
  struct coord B;

  printf("Choisissez un point A : x: ");
  scanf("%d y: %d", &A.x, &A.y);
  printf("\nChoisissez un point B : x: ");
  scanf("%d y: %d", &B.x, &B.y);

  D = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));

  printf("\n%d", D);

  return 0;
}