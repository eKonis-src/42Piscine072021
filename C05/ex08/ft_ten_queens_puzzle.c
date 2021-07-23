#include <unistd.h>
#include <stdio.h>

void	ft_print_tab(int tab[10][10])
{
	int	i;
	int	j;

	i = 0;
	while (i <= 9)
	{
		j = 0;
		while (j <= 9)
		{
			if (tab[j][i] != 0)
			{
				j += '0';
				write(1, &(j), 1);
				j -= '0';
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	ft_check_piece(int tab[10][10], int col, int row)
{
	int	i;

	i = 1;
	while ((col - i) >= 0 && (row - i) >= 0)
	{
		if (tab[row - i][col - i] != 0)
			return (0);
		i++;
	}
	i = 1;
	while ((col - i) >= 0)
	{
		if (tab[row][col - i] != 0)
			return (0);
		i++;
	}
	i = 1;
	while ((col - i) >= 0 && (row + i) < 10)
	{
		if (tab[row + i][col - i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_q_puzzle_final(int tab[10][10], int col)
{
	int	r;
	int	i;

	r = -1;
	i = 0;
	while (++r < 10)
	{
		tab[r][col] = 1;
		if (ft_check_piece(tab, col, r))
		{
			ft_print_tab(tab);
			i++;
		}
		tab[r][col] = 0;
	}
	return (i);
}

int	ft_q_puzzle_r(int tab[10][10], int col)
{
	int	r;
	int	i;

	i = 0;
	r = -1;
	while (++r < 10)
	{
		tab[r][col] = 1;
		if (col != 0)
		{
			if (ft_check_piece(tab, col, r))
			{
				if (col == 8)
					i += ft_q_puzzle_final(tab, 9);
				else
					i += ft_q_puzzle_r(tab, col + 1);
			}
		}
		else
			i += ft_q_puzzle_r(tab, col + 1);
		tab[r][col] = 0;
	}
	return (i);
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	j;
	int	tab[10][10];

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			tab[i][j] = 0;
	}
	return (ft_q_puzzle_r(tab, 0));
}

int	main(void)
{
	printf("%d", ft_ten_queens_puzzle());
}
