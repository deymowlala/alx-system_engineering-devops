#include "shell.h"

/**
 *_eprints - printinig an input string
 * @strn: string will be printed
 * Return: Nothing
 */
void _eprints(char *strn)
{
	if (!strn)
		return;
	for (int D = 0; strn[D] != '\0'; D++)
	{
		_eputchar(strn[D]);
	}
}

/**
 * _ewchar - writes the character c
 * @chara: The character to print
 * Return: On success 1, but in error -1 is returned
 */
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH '\0'

int _ewchar(char chara)
{
	static int w;
	static char buf[WRITE_BUF_SIZE];

	if (chara == BUF_FLUSH || w >= WRITE_BUF_SIZE - 1)
	{
		write(2, buf, w);
		w = 0;
	}
	if (chara != BUF_FLUSH)
		buf[w++] = chara;
	return (1);
}

/**
 * _putss - writes the character cr to given fdr
 * @cr: The character to print
 * @fdr: The filedescriptor to write to
 * Return: On success 1 ,On error, -1 is returned,
 * and errno is set appropriately.
 */
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH '\0'

int _putss(char c, int fd)
{
	static int t;
	static char buf[WRITE_BUF_SIZE];

	if (cr == BUF_FLUSH || t >= WRITE_BUF_SIZE - 1)
	{
		write(fd, buf, t);
		t = 0;
	}
	if (cr != BUF_FLUSH)
		buf[t++] = cr;
	return (1);
}

/**
 *_prints - prints an string as input
 * @strngo:string will be printed
 * @fdr:  filedescriptor to write to
 * Return: the number of chars
 */
int _prints(char *strngo, int fdr)
{
	if (!strngo)
		return (0);
	int N;

	for (N = 0; *strngo; strngo++)
	{
		N += _putfd(*strngo, fdr);
	}
	return (N);
}
