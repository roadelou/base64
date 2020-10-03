/********************************** METADATA **********************************/

/*
 * Contributors: roadelou
 * Contacts:
 * Creation Date: 2020-10-03
 * Language: C Source
 */

/********************************** INCLUDES **********************************/

/* The header of the implmeentation we are using. */
#include "base64.h"
/* For printf */
#include <stdio.h>

/********************************* PROTOYPES **********************************/

/* The prototypes of your functions go here. */

/************************************ BODY ************************************/

int main(int argc, const char **argv) {
  /* The string that we are tying to encode. */
  char *original = "Ow!";
  /* The buffer where our encoded string will go. */
  char encoded[30];

  /* We run the encoding. */
  base64((char *)encoded, original, 3);

  /* We print the result. */
  printf("Original %s, Encoded %s.\n", original, encoded);

  /* Other tests that require padding. */
  original = "a:a";
  base64((char *)encoded, original, 3);
  printf("Original %s, Encoded %s.\n", original, encoded);

  original = "a:aa";
  base64((char *)encoded, original, 4);
  printf("Original %s, Encoded %s.\n", original, encoded);

  original = "a:aaa";
  base64((char *)encoded, original, 5);
  printf("Original %s, Encoded %s.\n", original, encoded);

  original = "a:aaaa";
  base64((char *)encoded, original, 6);
  printf("Original %s, Encoded %s.\n", original, encoded);

  return 0;
}

/********************************* FUNCTIONS **********************************/

/* The functions for your code go here. */

/************************************ EOF *************************************/
