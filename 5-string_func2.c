#include "main.h"
/**
 * _stcpy - copy string
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
/**
 * _atoi - change numbers in string to integers
 * @s: string containing numbers
 * Return: integer number
 */
int _atoi(char *s)
{
	int sign = 1, res = 0;
	unsigned int num = 0;

	for (; *s != '\0'; s++)
	{
		if (*s == '-')
			sign *= -1;
		else if (*s >= 48 && *s <= 57)
			break;
	}
	while (*s >= 48 && *s <= 57)
	{
		num *= 10;
		num = num + *s - 48;
		s++;
	}
	if (sign == -1)
		res = num * -1;
	else
		res = num;
	return (res);
}
/**
 * num_to_char - change an int to string
 * @n: number to be converted
 * Return: number string
 */
char *num_to_char(int n)
{
	int len = 0, num = n, i, j;
	char *s;
	char r;

	while (num != 0)
	{
		num /= 10;
		len++;
	}
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	*s = '\0';
	for (i = 0; (n / 10); i++)
	{
		s[i] = (n % 10) + 48;
		n /= 10;
	}
	s[i] = (n % 10) + 48;
	for (j = 0; j < (len / 2); j++)
	{
		r = s[j];
		s[j] = s[len - 1 - j];
		s[len - 1 - j] = r;
	}
	s[j + 1] = '\0';
	return (s);
}
