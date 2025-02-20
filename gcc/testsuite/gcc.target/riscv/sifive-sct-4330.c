/* Test there is no ICE when compile.  */
/* { dg-do compile } */
/* { dg-options "-mabi=lp64d -march=rv64gcv_zvfh_zvl512b -O3 -flto" } */

#include <stdlib.h>

void fill(int *a, int len, int start) {
 int i;
 for (i = 0; i < len; i++) {

  a[i] = i + start + i % 8;
 }
}

void s000(int *a, int *b, int len) {
    unsigned int i;
    for (i = 0; i < 63; i++) {
        a[i] = b[i] + 1;
    }
}

int sum(int *a, int len) {
    int i;
    int lrc = 0;
    for(i = 0; i < len; i++) {
        lrc ^= a[i];
    }
    return lrc;
}

const int expectedResults[] = { 72,71,103,33,0,104,104,104,104,104,104,104,104,104,
104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,
104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,
104,104,104,104,104,104,104,104,104,104,104,104,104,104,104 };

int main () {
    int len;
    int loopvar_0;

    int * p0;
    int * p1;
    p0 = (int*) malloc(((128)) * sizeof(int));
    p1 = (int*) malloc(((128)) * sizeof(int));

    len = 96 - 1;

    fill(p0, 63, 0);
    fill(p1, 63, 1);
    s000(p0, p1, 63);
    if (expectedResults[0] == sum(p0, 63))
      return 1;

    fill(p0, 63, 0);
    fill(p1, 63, 1);
    s000(p1, p0, 63);
    if (expectedResults[1] == sum(p1, 63))
      return 1;

    fill(p0, len, 0);
    s000(p0, p0, len);
    if (expectedResults[2] == sum(p0, len))
      return 1;

    fill(p0, len + 1, 0);
    s000(p0, &p0[1], len);
    if (expectedResults[3] == sum(p0, len))
      return 1;

    fill(p0, len + 1, 0);
    s000(&p0[1], p0, len);
    if (expectedResults[4] == sum(&p0[1], len))
      return 1;

    for(loopvar_0 = 0; loopvar_0 < 32; loopvar_0++) {
      fill(&p0[loopvar_0], len, 0);
      fill(p1, len, 1);
      s000(&p0[loopvar_0], p1, len);
      if (expectedResults[(loopvar_0 - 0)*2+5] == sum(&p0[loopvar_0], len))
        return 1;

      fill(p0, len, 0);
      fill(&p1[loopvar_0], len, 1);
      s000(p0, &p1[loopvar_0], len);
      if (expectedResults[(loopvar_0 - 0)*2+6] == sum(p0, len))
        return 1;
    }
    free(p0);
    free(p1);
    return 0;
}
