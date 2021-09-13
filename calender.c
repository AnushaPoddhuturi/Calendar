#include<stdio.h>
#include<conio.h>

int year(int);
int spaces(int, int, int, int);
int months(int);
int n_days(int);
void main() {
  int d;
  printf("Enter required year:");
  scanf("%d", & d);
  year(d);
  getch();
}
int year(int d) {
  int i,
  fixed,
  a = 0,
  b = 0,
  sum,
  cnt,
  k,
  c,
  x;
  fixed = 1905;
  for (i = fixed; i < d; i++) {
    a++;
    if (i % 4 == 0) {
      b++;
    }
  }
  sum = a + b;
  cnt = sum;
  k = sum;
  if (sum > 7) {
    c = sum % 7;
    x = c;
    cnt = c;
    k = c;
  }
  else if(sum == 7) {
    x = 0;
  }
  else if(sum % 7 != 0) {
    x = sum;
  }
  spaces(cnt, k, d, x);
  return 0;
}
int spaces(int cnt, int k, int d, int x) {
  int i,
  j,
  t,
  y,
  n;
  for (i = 0; i < 12; i++) {
    months(i);
    if (i == 0) {
      for (y = 0; y < x; y++) {
        printf("\t");
      }
    } else {
      if (t % 7 != 0) {
        for (y = 0; y < t; y++) {
          printf("\t");
        }
      }
    }
    n = n_days(i);
    if (i == 1) {
      if (d % 4 == 0) {
        n = 29;
      }
    }
    for (j = 1; j <= n; j++) {
      if (j == 1) {
        if (cnt % 7 == 0) {
          k = 1;
        } else {
          k++;
        }
        printf("%d\t", j);
        cnt++;
      } else {
        if (cnt % 7 == 0) {
          printf("\n%d\t", j);
          if (k == 7) {
            k = 1;
          }
        } else {
          printf("%d\t", j);
          k++;
        }
        cnt++;
      }
    }
    t = k;
  }
  return 0;
}
int months(int i) {
  char ch[15][15] = {
    "January",
    "Feburary",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "Decenber "
  };
  printf("\n\t\t\t%s", ch[i]);
  printf("\nsun\tmon\ttues\twed\tthurs\tfri\tsat\n");
  return 0;
}
int n_days(int i) {
  int a[15] = {
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31
  };
  return a[i];
}