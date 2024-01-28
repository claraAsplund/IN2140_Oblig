
void add(int tall1, int tall2, int *sum) {
  *sum = tall1 + tall2;
  return;
}

int main(void) {
  int a, b, res;
  a = 1;
  b = 2;
  res = 0;

  add(a, b, &res);

  return 0;
}

/*
STACK

MAIN:
-------------
0x00    -   a       -   1
0x01    -   b       -   2
0x02    -   res     -   0
-------------

ADD:
-------------
0x03    -   tall1   -   1
0x04    -   tall2   -   2
0x05    -   sum     -   0x02
-------------
*/
