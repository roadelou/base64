/********************************** METADATA **********************************/

/*
 * Contributors: roadelou
 * Contacts:
 * Creation Date: 2020-10-03
 * Language: C Source
 */

/********************************** INCLUDES **********************************/

/* The interface that we are trying to implement. */
#include "base64.h"

/********************************* PROTOYPES **********************************/

/* We define the base64 table of values in a global buffer, which should be
 * simpler and more efficient. */
static char base64_table[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

/************************************ BODY ************************************/

/* The main function of your code goes here. */

/********************************* FUNCTIONS **********************************/

int base64_24bit(char *buffer, const char *input) {
  /* The index that we should look up in the base64 table. */
  int cursor;
  /* We use bitwise operations to extract the 6 bit blocks we are looking for.
   * The masks were found by translating the binary to hexadecimal. */
  /* 0 - 5 bits */
  cursor = (*input & 0xFC) >> 2;
  *buffer = base64_table[cursor];
  /* 6 - 11 bits */
  cursor = ((*input & 0x3) << 4) | ((*(input + 1) & 0xF0) >> 4);
  *(buffer + 1) = base64_table[cursor];
  /* 12 - 17 bits */
  cursor = (*(input + 1) & 0xF) << 2 | (*(input + 2) & 0xC0) >> 6;
  *(buffer + 2) = base64_table[cursor];
  /* 18 - 25 bits */
  cursor = *(input + 2) & 0x3F;
  *(buffer + 3) = base64_table[cursor];
  /* Execution is a success. */
  return SUCCESS;
}

int base64(char *buffer, const char *input, const int length) {
  /* Cursor use to keep track of our location in the input. */
  int cursor;
  /* A small buffer use to complete our last 24 bits with padding. */
  char padding[3] = {0, 0, 0};
  /* We start by taking care of the easy 24 bit blocks. */
  for (cursor = 0; cursor < length / 3; cursor++) {
    /* We take our next 24bits. For each 3 bytes that we read, we write 4. */
    base64_24bit(buffer + cursor * 4, input + cursor * 3);
  }
  /* We test if there is some input remaining that has to be padded. */
  switch (length - cursor * 3) {
  case 2:
    /* We need to pad a single bytes. */
    *padding = *(input + cursor * 3);
    *(padding + 1) = *(input + cursor * 3 + 1);
    /* We encode the padded input. */
    base64_24bit(buffer + cursor * 4, padding);
    /* We overwrite the last byte, which is entirely padding, with a special
     * character. */
    *(buffer + cursor * 4 + 3) = '=';
    /* Adding null-terminating byte. */
    *(buffer + cursor * 4 + 4) = '\0';
    break;
  case 1:
    /* We need to pad two bytes. */
    *padding = *(input + cursor * 3);
    /* We encode the padded input. */
    base64_24bit(buffer + cursor * 4, padding);
    /* We overwrite the last two bytes. */
    *(buffer + cursor * 4 + 2) = '=';
    *(buffer + cursor * 4 + 3) = '=';
    /* Adding null-terminating byte. */
    *(buffer + cursor * 4 + 4) = '\0';
    break;
  default:
    /* Simply adding the terminating null byte. */
    *(buffer + cursor * 4) = '\0';
  }
  /* The encoding is complete. */
  return SUCCESS;
}

/************************************ EOF *************************************/
