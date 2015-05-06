#include <stdio.h>
#include <stdlib.h>
/*#pragma warning(disable : 4996) //disabling warnings about using "unsafe functions" like strcpy instead of strcpy_s
#include <string.h>*/
#include "strings.h"

int main(int argc, char *argv[])
{

	char p[40] = " ,.hello fdfdf. sdsdsd, dsds.~";
	char c[5] = ", .~";
	printn(convertStr(my_strtok(p, c)));
	printn(convertStr(my_strtok(NULL, c)));
	printn(convertStr(my_strtok(NULL, c)));
	printn(convertStr(my_strtok(NULL, c)));	
	printn(convertStr(my_strtok(NULL, c)));
	system("pause");
}