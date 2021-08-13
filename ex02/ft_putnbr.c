#include <unistd.h>
void	put_in_nbr(int *nbs, int nb, char *nbr)
{
	while (nbs[0])
	{
		nbs[0] /= 10;
		nbs[2]++;
	}
	nbs[0] = nb;
	nbs[4] = nbs[2];
	if (nbs[1])
	{
		nbr[0] = '-';
		nbs[2] += 1;
	}
	while (nbs[0])
	{
		nbs[3] = nbs[0] % 10;
		nbr[nbs[2] - 1] = nbs[3] + 48;
		nbs[0] /= 10;
		nbs[2]--;
	}
}

void	ft_putnbr(int nb)
{
	char	nbr[11];
	int		nbs[5];

	nbs[0] = 11;
	nbs[1] = 0;
	nbs[2] = 0;
	nbs[3] = 1;
	if (nb < 0)
	{
		nb *= -1;
		nbs[1] = 1;
	}
	nbs[0] = nb;
	put_in_nbr(nbs, nb, nbr);
	if (!nb)
		nbr[0] = '0';	
	write(1, nbr, nbs[4] + 1);
}

int main(void)
{
	int nb = 0;
	ft_putnbr(nb);
	return (0);
}