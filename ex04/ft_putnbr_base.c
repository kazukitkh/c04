/*#include <unistd.h>
#include <stdio.h>*/
void	ft2_write(char *base, int nbr, int j, int i)
{
	int		k;
	int		a;
	int		b;

	while (i)
	{
		a = i - 1;
		k = nbr;
		while (a)
		{
			k /= j;
			a--;
		}
		b = k % j;
		write(1, &base[b], 1);
		i--;
	}
}

void	ft1_write(char *base, int nbr, int j)
{
	char	t[1];
	int		i;
	int		a;

	t[0] = '-';
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, t, 1);
	}
	i = 0;
	a = nbr;
	while (a)
	{
		a /= j;
		i++;
	}
	ft2_write(base, nbr, j, i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		j;
	int		a;

	i = 0;
	j = 0;
	a = 1;
	while (base[i])
	{
		j = i + 1;
		if (!(base[0] && base[1]) || base[i] == '+' || base[i] == '-')
			a = 0;
		while (base[j])
		{
			if (base[i] == base[j])
				a = 0;
			j++;
		}
		i++;
	}
	if (a)
		ft1_write(base, nbr, j);
}

/*int	main(void)
{
	int		n = 7;
	char	s[] = "abc";
	ft_putnbr_base(n, s);
	return (0);
}*/