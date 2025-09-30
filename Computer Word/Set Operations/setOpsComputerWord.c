#include <stdio.h>

typedef char SET;

SET setUnion(SET x, SET y);
SET setIntersection(SET x, SET y);
SET setDifference(SET x, SET y);
void displaySet(SET set);

int main() {
  SET x = 50;
  SET y = 100;

  SET a = setUnion(x, y); 
  SET b = setIntersection(x, y);
  SET c = setDifference(x, y);
  SET d = setDifference(x, y);

  printf("\nDisplaying bits for x: ");
  displaySet(x);
  printf("\nDisplaying bits for y: ");
  displaySet(y);
  printf("\nDisplaying Set X union Set Y: ");
  displaySet(a);
  printf("\nDisplaying Set X intersection Set Y: ");
  displaySet(b);
  printf("\nDisplaying Set X difference Set Y: ");
  displaySet(c);
  printf("\nDisplaying Set Y difference Set X: ");
  displaySet(d);

  printf("\n");
  return 0;
}

SET setUnion(SET x, SET y) {
  return x | y;
}

SET setIntersection(SET x, SET y) {
  return x & y;
}

SET setDifference(SET x, SET y) {
  return x & ~y;
}

void displaySet(SET set) {
  int masked = 0;

  for (masked = 1 << (sizeof(set) * 8 - 1); masked > 0; masked >>= 1) {
    printf("%d, ", (masked & set) ? 1 : 0);
  }
}
