#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "fptc.h"

/*
 * Usage:
 * echo "    55.44 -8.5 -.1 adada .345 -.00a04 55.6  " | ./test
 * echo "    55.44 -8.5 -.1  .345 -.0004 55.6  " | ./test
 */

int main(void) {
  
  int arr[1000], length = 0, c, bytesread, ret[1000];
  char input[1000];
  fgets(input, sizeof(input), stdin);
  char* input1 = input;
  while ((ret[length] = fpt_scan(input1, &c, &bytesread)) > 0) {
      arr[length++] = c;
      input1 += bytesread;
  }
  
  for ( int i = 0; i < length; i++ ) {
      fpt_str(arr[i], input, -2);
      printf("ret:\t%d\nfpt:\t%x\nBack:\t%s\n\n", ret[i], arr[i], input);
  }
  
  return 0;
  
}