#include "main.h"
/**
 * stcpy - copy string
 * @dest: destination string
 * @src: source string
 * Return: destination string
 */
char *_stcpy(char *dest, char *src)
{
	int i = 0, j;

	while (src[i])
		++i;

	for (j = 0; j <= i; j++)
		dest[j] = src[j];

	return (dest);
}
