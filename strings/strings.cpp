#include "strings.h"
#include <string.h>
#include <malloc.h>
#pragma warning(disable : 4996)

#define END 126
#define false 0
#define true 1

//@brief This function converts our string to \0 terminated string
//@param
//char *str - pointer to string
//@return pointer to converted string
char *convertStr(char * str)
{
	if (str != NULL)
	{
		const char * begin = str;
		str = str + my_strlen(str);
		*str = '\0';
		return (char*)begin;
	}
	return NULL;
}

//@brief This function prints a string
//@param
//char *str - pointer to string
//@return void
void print(const char *str)
{
	if (str != NULL)
	{
		printf("%s", str);
	}
	else
		printf("(null)");
}

//@brief This function prints string with '\n' in the end
//@param
//char *str - pointer to string
//@return void
void printn(const char *str)
{

	if (str != NULL)
	{
		printf("%s\n", str);
	}
	else
		printf("(null)\n");
}

//@brief This function reads string from keyboard and set last character as END
//@return void
char *getstring()
{
	fflush(stdin);

	char* buf = (char*)malloc(127);

	fgets(buf, 127, stdin);	

	size_t i = 0;
	while (*(buf + i) != '\0')
		++i;

	*(buf + i - 1) = END;	
	return buf;
}

//@brief This function cheaks if array "accept" contains character "chr"
//@param char *chr - some character
//@param const char *accept - array of characters
//@return 1 if character was found in "accept", or 0 otherwise
short contain(char chr, const char *accept)
{
	for (size_t i = 0; accept[i] != END; ++i)
		if (accept[i] == chr)
		{
			return 1;
		}
	return 0;
}

//@brief This function copies one memory region to the another region
//@param pointer to destination
//@param pointer to source
//@param number of bytes to copy
//@return void
void *my_memcpy(char *dest, const char *src, size_t bytes)
{
	if (dest == src)
		return NULL;

	while (bytes--)
	{
		*dest = *src;
		++dest;
		++src;
	}
}

//@brief Fills a buffer with a character
//@param
//char *buf - buffer to fill
//int chr - chr to fill the buffer
//size_t bytes - number of bytes to fill
//@return void
void *my_memset(char *buf, int chr, size_t bytes)
{
	for (size_t i = 0; i < bytes; ++i)
		*(buf + i) = chr;						//filling buffer with chr
	return buf;
}

//@brief This function finds the first occurrence of a character in a buffer
//@param 
//const char *str - pointer to buffer
//int - number of character in ASCII table we are looking for
//@return pointer to character position or NULL
void *my_memchr(const char *buf, char chr, size_t bytes)
{
	for (size_t i = 0; i < bytes; ++i)
		if (*(buf + i) == chr)
			return (void*)(buf + i);
	return NULL;
}

//@brief This function compares no more then n bytes of two buffers of memory
//@param 
//const char *buf1 - pointer to first region of memory
//const char *buf2 - pointer to second region of memory
//@return buf1==buf2 => 0, buf1>buf2 => 1, buf2<buf1 => -1
int my_memcmp(const char *buf1, const char *buf2, size_t bytes)
{
	for (size_t i = 0; i < bytes, (*buf1 == *buf2); ++i)
	{
		++buf1; ++buf2;
	}
	if (*buf1 == *buf2)
		return 0;
	else
		return (*buf1 < *buf2) ? -1 : 1;
}

//@brief This function appends one string to another
//@param
//char *dest - destination string
//char *src - source string
//@return pointer to destination string
char *my_strcat(char *dest, const char *src)
{
	//memcopy will not copy data from pointer to the same pointer, so we need temp variable
	//if dest==src nothing will happen
	//so we need temp variable
	char *tDest = dest;

	//begin copying from the end of tDest
	my_memcpy(tDest + my_strlen(tDest), src, my_strlen(src)+1);
	return tDest;
}

//@brief This function appends no more then n bytes from one string to another
//@param
//char *dest - destination string
//char *src - source string
//size_t bytes - number of bytes to append
//@return pointer to destination string
char *my_strncat(char *dest, const char *src, size_t bytes) 
{
	//we will call strlen once insted of 3 times
	const size_t srcLength = my_strlen(src);
	const size_t destLength = my_strlen(dest);

	//there is no sense to copy something after "end of the line symbol"
	if (bytes > srcLength)
		bytes = srcLength + 1;

	//memcopy will not copy data from pointer to the same pointer, so we need temp variable
	//if dest==src nothing will happen
	//so we need temp variable
	char *tDest = dest;
	my_memcpy(tDest + my_strlen(tDest), src, bytes);

	//we should set last character as END
	if (bytes < srcLength + 1)
		*(tDest + destLength + bytes) = END;
	return tDest;
}

//@brief This function copies one string to another
//@param
//char *dest - destination string
//char *src - source string
//@return pointer to destination string
char *my_strcpy(char *dest, const char *src)
{
	//there is no sense to copy data like this
	if (dest == src)
		return dest;

	my_memcpy(dest, src, my_strlen(src) + 1);
	return dest;
}

//@brief This function copies no more then n bytes from one string to another
//@param
//char *dest - destination string
//char *src - source string
//size_t bytes - number of bytes to copy
//@return pointer to destination string
char *my_strncpy(char *dest, const char *src, size_t bytes)
{
	//there is no sense to copy data like this
	if (dest == src)
		return dest;

	//we will call strlen once insted of 3 times
	const size_t srcLength = my_strlen(src);

	//there is no sense to copy something after "end of the line symbol"
	if (bytes > srcLength)
		bytes = srcLength + 1;

	my_memcpy(dest, src, bytes);

	//setting last character
	if (bytes <= srcLength + 1)
		*(dest + bytes) = END;
	return dest;
}

//@brief This function returns length of the string
//@param 
//const char *str - pointer to string
//@return integer number of symbols
size_t my_strlen(const char *str)
{
	size_t symbCounter = 0;
	while (*(str + symbCounter) != END)
	{
		++symbCounter;
	}
	return symbCounter;
}

//@brief lexicographical comparison of two strings
//@param 
//const char *str1 - pointer to first string
//const char *str2 - pointer to second string
//@return str1==str2 => 0, str1>str2 => 1, str2>str1 => -1
int my_strcmp(const char *str1, const char *str2)
{
	//stop comparing if here is the end of str 1 or some symbols doesn't match
	while (*str1 != END && (*str1 == *str2))
	{
		++str1; ++str2;	
	}

	if (*str1 == *str2)							
		return 0;
	else
		return (*str1 < *str2) ? -1 : 1;
}

//@brief lexicographical comparison no more then n bytes from two strings
//@param 
//const char *str1 - pointer to first string
//const char *str2 - pointer to second string
//@return str1==str2 => 0, str1>str2 => 1, str2<str1 => -1
int my_strncmp(const char *str1, const char *str2, size_t bytes)
{ 
	//we will call strlen once insted of 3 times
	const size_t str1Length = my_strlen(str1);
	const size_t str2Length = my_strlen(str2);
	//we will not compare more then "minimal string length" bytes
	if (bytes > str1Length || bytes > str2Length)
	{
		if (str1Length < str2Length)
			bytes = str1Length;
		else
			bytes = str2Length;
	}

	size_t bytesCompared = 0;
	//stop comparing if symbols does not match, or we campared enough bytes
	while ((*str1 == *str2) && (bytesCompared < bytes))
	{
		++str1; ++str2; ++bytesCompared;
	}
	if (*str1 == *str2)
		return 0;
	else
		return (*str1 < *str2) ? -1 : 1;
}

//@brief This function looking for FIRST char which is equal to second parameter
//@param 
//const char *str - pointer to string
//int chr - number of character in ASCII table we are looking for
//@return pointer to character position or NULL
char *my_strchr(const char *str, int chr)
{
	//looking for character while not end of string or character is found
	while (*str != chr && *str != END)
		++str;

	//if end of line was reached and symbol is not found
	if (*str == END)
		return NULL;
	else
		return (char*)str;
}

//@brief This function looking for LAST char which is equal to second parameter
//@param 
//const char *str - pointer to string
//int chr - number of character in ASCII table we are looking for
//@return pointer to character position or NULL
char *my_strrchr(const char *str, int chr)
{
	//we will start from the end of string
	const char *begin = str;
	str = str + my_strlen(str);
	for (; *str != chr && str != begin; --str);
	
	//first symbol means end of the cycle but it can be equal to "chr"
	if (str == begin && *begin != chr)
		return NULL;
	else
	if (str == begin && *begin == chr)
		return (char*)str;
	else
	return (char*)str;
}

//@brief This function counting length of string which only consists of symbols from "accept"
//@param 
//const char *str - pointer to string
//const char *accept - array of characters
//@return length of string which only consists of symbols from "accept"
size_t my_strspn(const char *str, const char *accept)
{
	size_t curStrChr, curAcceptChr;
	for (curStrChr = 0; str[curStrChr] != END; ++curStrChr)
	{
		for (curAcceptChr = 0; accept[curAcceptChr] != END; ++curAcceptChr)
		{
			if (accept[curAcceptChr] == str[curStrChr])
				break;
		}

		//if the end of "accept" is reached -> there is no any symbol from "accept" in the string
		if (accept [curAcceptChr] == END)
			break;
	}
	return curStrChr;
}

//@brief This function counting length of string which does not consist any symbol from "reject"
//@param 
//const char *str - pointer to string
//const char *accept - array of characters
//@return length of string which does not consist any symbol from "reject"
size_t my_strcspn(const char *str, const char *reject)
{
	size_t curStrChr, curRejectChr;
	
	for (curStrChr = 0; str[curStrChr] != END; ++curStrChr)
	{
		for (curRejectChr = 0; reject[curRejectChr] != END; ++curRejectChr)
		{
			//if character is found in array "reject" => return length
			if (reject[curRejectChr] == str[curStrChr])
				return curStrChr;
		}
	}
	return curStrChr;
}

//@brief This function finds in a string the first occurrence of a character in a string
//@param 
//const char *str - pointer to string
//const char *accept - array of characters
//@return pointer to first occurrence of a character in a string
char *my_strpbrk(const char *str, const char *accept)
{
	size_t curStrChr, curAcceptChr;
	for (curStrChr = 0; str[curStrChr] != END; ++curStrChr)
	{
		for (curAcceptChr = 0; accept[curAcceptChr] != END; ++curAcceptChr)
		{
			//if characters matches
			if (accept[curAcceptChr] == str[curStrChr])
				return (char*)(str + curStrChr);
		}
	}
	return NULL;
}

//@brief This function looking for occurrence of substring in a string
//@param 
//const char *str - pointer to string
//const char *substr - pointer to substring
//@return pointer to string
char *my_strstr(const char *str, const char *substr)
{
	//substr pointer will be modified so we should save the beginning of substr
	const char *subStrBegin = substr;
	size_t matchesCounter;
	const size_t substrSize = my_strlen(subStrBegin);
	for (; *str != END; ++str)
	{
		//each time we start comparing from the beginning of substring
		substr = subStrBegin;
		for (matchesCounter = 0; *substr != END; ++matchesCounter)
		{
			if (*substr != *(str + matchesCounter))
				break;
			++substr;
		}
		
		//if all symbols of str part and substring are equal => return pointer to this part
		if (matchesCounter == substrSize)
			return (char*)str;																
	}
	return NULL;
}

//@brief This function splits string into tokens. Each function call returns one token. 
//		 but each next call for the same ftring requires NULL as first parameter.
//@param 
//char *str - pointer to string
//const char *delims - pointer to delimiters
//@return pointer to token
char *my_strtok(char *str, const char *delims)
{
	static char *strToSplit;
	size_t tokenSize = 0;
	size_t delimitersToPass = 0;
	char *token = NULL;
	short lastToken = false;

	//new str to split
	if (str != NULL)
	{
		strToSplit = str;
		delimitersToPass = my_strspn(strToSplit, delims);
		strToSplit = strToSplit + delimitersToPass;
	}

	//strcspn will return length of string before next delimiter
	tokenSize = my_strcspn(strToSplit, delims);

	//if there is no more characters to split a token
	if (tokenSize == 0)
		return NULL;

	//checking if token is last
	if (*(strToSplit + tokenSize) == END)
		lastToken = true;
	//set end of line symbol to return a token instead of whole string
	*(strToSplit + tokenSize) = END;
	//strToSplit will be modified for next function call, so we should save pointer to the token
	token = strToSplit;
	//Now strToSplit will point to next character after the token and end of line symbol
	strToSplit = strToSplit + tokenSize;
	//if token is not last pointer will point to the next symbol after END
	if (!lastToken)
		++strToSplit;

	//counting delimiters to pass if we there are few delimiters in sequence
	delimitersToPass = my_strspn(strToSplit, delims);
	//strToSplit now points to the next token or end of line
	strToSplit = strToSplit + delimitersToPass;

	return token;
}