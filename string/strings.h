#include <stdio.h>

//@brief This function converts our string to \0 terminated string
//@param pointer to string
//@return pointer to converted string
char *convertStr(char *);

//@brief This function prints a string
//@param pointer to string
//@return void
void print(const char *);

//@brief This function prints string with '\n' in the end
//@param pointer to string
//@return void
void printn(const char *);

//@brief This function reads string from keyboard and set last character as END
//@return void
char *getstring();

//@brief This function cheaks if array "accept" contains character "chr"
//@param some character
//@param array of characters
//@return 1 if character was found in "accept", or 0 otherwise
short contain(char, const char *);

//@brief This function copies one memory region to the another region
//@param pointer to destination
//@param pointer to source
//@param number of bytes to copy
//@return void
void *my_memcpy(char *, const char *, size_t);

//@brief Fills a buffer with a character
//@param buffer to fill
//@param chr to fill the buffer
//@param number of bytes to fill
//@return void
void *my_memset(char *, int z, size_t);

//@brief This function finds the first occurrence of a character in a buffer
//@param pointer to buffer
//@param number of character in ASCII table we are looking for
//@return pointer to character position or NULL
void *my_memchr(const char *memPtr, char chr, size_t bytes);

//@brief This function compares no more then n bytes of two buffers of memory
//@param pointer to first region of memory
//@param pointer to second region of memory
//@return buf1==buf2 => 0, buf1>buf2 => 1, buf2<buf1 => -1
int my_memcmp(const char *memPtr1, const char *memPtr2, size_t bytes);

//@brief This function appends one string to another
//@param destination string
//@param source string
//@return pointer to destination string
char *my_strcat(char *str1, const char *str2);

//@brief This function appends no more then n bytes from one string to another
//@param destination string
//@param source string
//@param number of bytes to append
//@return pointer to destination string
char *my_strncat(char *str1, const char *str2, size_t bytes);

//@brief This function copies one string to another
//@param destination string
//@param source string
//@return pointer to destination string
char *my_strcpy(char *dest, const char *src);

//@brief This function copies no more then n bytes from one string to another
//@param destination string
//@param source string
//@param number of bytes to copy
//@return pointer to destination string
char *my_strncpy(char *dest, const char *src, size_t bytes);

//@brief This function returns length of the string
//@param pointer to string
//@return integer number of symbols
size_t my_strlen(const char *str);

//@brief lexicographical comparison of two strings
//@param pointer to first string
//@param pointer to second string
//@return str1==str2 => 0, str1>str2 => 1, str2>str1 => -1
int my_strcmp(const char *str1, const char *str2);

//@brief lexicographical comparison no more then n bytes from two strings
//@param pointer to first string
//@param pointer to second string
//@return str1==str2 => 0, str1>str2 => 1, str2<str1 => -1
int my_strncmp(const char *str1, const char *str2, size_t bytes);

//@brief This function looking for FIRST char which is equal to second parameter
//@param pointer to string
//@param number of character in ASCII table we are looking for
//@return pointer to character position or NULL
char *my_strchr(const char *str, int chr);

//@brief This function looking for LAST char which is equal to second parameter
//@param pointer to string
//@param number of character in ASCII table we are looking for
//@return pointer to character position or NULL
char *my_strrchr(const char *str, int chr);

//@brief This function counting length of string which only consists of symbols from "accept"
//@param 
//@param pointer to string
//@param array of characters
//@return length of string which only consists of symbols from "accept"
size_t my_strspn(const char *str, const char *accept);

//@brief This function counting length of string which does not consist any symbol from "reject"
//@param pointer to string
//@param array of characters
//@return length of string which does not consist any symbol from "reject"
size_t my_strcspn(const char *str, const char *reject);

//@brief This function finds in a string the first occurrence of a character in a string
//@param pointer to string
//@param array of characters
//@return pointer to first occurrence of a character in a string
char *my_strpbrk(const char *str, const char *accept);

//@brief This function looking for occurrence of substring in a string
//@param pointer to string
//@param pointer to substring
//@return pointer to string
char *my_strstr(const char *str, const char *subStr);

//@brief This function splits string into tokens. Each function call returns one token. 
//		 but each next call for the same ftring requires NULL as first parameter.
//@param 
//@param pointer to string
//@param pointer to delimiters
//@return pointer to token
char *my_strtok(char *str, const char *delimiters);