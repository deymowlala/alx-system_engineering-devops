#include "shell.h"

/**
 * _ourexit - leaves the shell
 * @item: Structure that has potential arguments which is used to maintain
 *          constant function prototype.
 * Return: leaves with an exit status
 *         (0) if info.argv[0] != "exit"
 */
int _ourexit(info_t *item)
{
	int exitTest;
	int i = 1;

	while (i < item->argc)
	{
		exitTest = _erratoi(item->argv[i]);
		if (exitTest == -1)
		{
			item->status = 2;
			_puts("Illegal number: ");
			_puts(item->argv[i]);
			_putchar('\n');
			return (1);
		}
		item->err_num = _erratoi(item->argv[i]);
		i++;
	}
	item->err_num = -1;
	return (-2);
}

/**
 * _ourcd - changes the current directory of the process
 * @item: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _ourcd(info_t *item)
{
	char *t, *direct, buffer[1024];
	int chdirect_ret;
	
	t = getcwd(buffer, 1024);
	if (!t)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	int i = 1; // Initialize index to 1
	
	while (i < item->argc)
	{
		if (!item->argv[i])
		{
			direct = _getenv(item, "HOME=");
			if (!direct)
				chdirect_ret = chdir((direct = _getenv(item, "PWD=")) ? direct : "/");
			else
				chdirect_ret = chdir(direct);
		}
		else if (_strcmp(item->argv[i], "-") == 0)
		{
			if (!_getenv(item, "OLDPWD="))
			{
				_puts(t);
				_putchar('\n');
				return (1);
			}
			_puts(_getenv(item, "OLDPWD="));
			_putchar('\n');
			chdirect_ret = chdir((direct = _getenv(item, "OLDPWD=")) ? direct : "/");
		}
		else
		{
			chdirect_ret = chdir(item->argv[i]);
		}
		if (chdirect_ret == -1)
		{
			_puts("cannot cd into ");
			_puts(item->argv[i]);
			_putchar('\n');
		}
		else
		{
			_setenv(item, "OLDPWD", _getenv(item, "PWD="));
			_setenv(item, "PWD", getcwd(buffer, 1024));
		}
		i++;
	}
	return (0);
}

/**
 * _ourhelp - changes the current directory of the process
 * @item: Structure contains potential arguments and it's used to maintain
 *          constant function prototype.
 *  Return: (0) Always
 */
int _myhelp(info_t *item)
{
	char **argu_arr;
	
	argu_arr = item->argv;
	_puts("help call works. Function not implemented yet \n");
	if (0)
		_puts(*argu_arr); /* temp att_unused workaround */
	return (0);
}
