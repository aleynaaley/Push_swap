
#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_argfree(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	while (i >= 0)
		free(arg[i--]);
	free(arg);
}

static int	repeat(long tmp, char **arg, int i)
{
	i++;
	while (arg[i])
	{
		if (ft_atoi(arg[i]) == tmp)
			return (1);
		i++;
	}
	return (0);
}

void	check_arg(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**arg;

	i = 0;
	if (argc == 2)
		arg = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		arg = argv;
	}
	while (arg[i])
	{
		tmp = ft_atoi(arg[i]);
		if (!ft_isnum(arg[i]))
			error();
		if (repeat(tmp, arg, i))
			error();
		if (tmp < -2147483648 || tmp > 2147483647)
			error();
		i++;
	}
	if (argc == 2)
		ft_argfree(arg);
}
