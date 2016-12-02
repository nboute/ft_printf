#include <stdio.h>
#include <stdarg.h>

void	ft_a(int x, ...)
{
	va_list a;
	char	*str;
	int		i;
	va_start(a, x);

	str = NULL;
	i = 0;
	while (i < x)
	{
		str = va_arg(a, char*);
		printf("%s\n", str);
		i++;
	}
}

int		main()
{
	ft_a(7, "aaaa", "bb", "ccccc", "dddd", "eeeee", "ffffffffff", "ggggggg");
}
