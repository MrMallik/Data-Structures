#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#define Max 10


  int st[Max], top = -1;

  void push(int x) { st[++top] = x; }

  void pop() { top--; }

  int main() {

    int N, x, type, max = INT_MIN;

    scanf("%d", &N);

    while (N != 1) {
      scanf("%d %d", &type, &x);

      if (type == 1) {
        if (x >= max)
          max = x;
        push(x);
      } else if (type == 2) {
        pop();
        if (top == -1)
          max = INT_MIN;
        else
          max = st[top];
      } else if (type == 3) {
        printf("\n%d", max);
      }

      N--;
    }

return 0;
  }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

