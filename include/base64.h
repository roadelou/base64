/********************************** METADATA **********************************/

/*
 * Contributors: roadelou
 * Contacts:
 * Creation Date: 2020-10-03
 * Language: C Header
 */

/********************************** INCLUDES **********************************/

/* The includes for your header go here */

/*********************************** MACROS ***********************************/

/* Those two values are used as return codes for functions. */
#ifndef SUCCESS
#define SUCCESS 0
#endif

#ifndef FAILURE
#define FAILURE -1
#endif

/********************************** STRUCTS ***********************************/

/* The enums of your header go here */

/* The structs of your header go here */

/* The unions of your header go here */

/* The typedefs of your header go here */

/************************************ BODY ************************************/

/*
Description
===========
Serializes the given input according to the base64 encoding.

Arguments
=========
 - buffer: The buffer in which the output zill be written, should be big 4/3
        than the input and should leave room for the null-terminating byte.
 - input: The input that should be serialized.
 - length: The number of bytes in the provided input.

Returns
=======
SUCCESS once the call is over.
*/
int base64(char *buffer, const char *input, const int length);

/*
Description
===========
Serializes the given 3 bytes to their corresponding 4 base64 characters.

Arguments
=========
 - buffer: The buffer where the 4 new characters will be written. No null-byte
        will be added.
 - input: The 3 input bytes we are going to serialize.

Returns
=======
SUCCESS once the call is over.
*/
int base64_24bit(char *buffer, const char *input);

/************************************ EOF *************************************/
