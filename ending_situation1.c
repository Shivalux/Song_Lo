#include "so_long.h"

void	sl_walking_animate(t_data *data);
void	sl_patroling_animate(t_data *data, int index, int xedni, int mode);

void	sl_ending_screen(t_data *data, int f)
{
	mlx_put_image_to_window(data->mlx, data->window, data->s[0].img, data->y * 32, data->x * 32);
	if (data->end == 1)
	{
		sl_ending_one(data, f);
	}
	else if (data->end == 2)
	{
		sl_ending_two(data);
	}
	else if (data->end == 3 && data->wk <= 5 && data->u[data->x][data->y].mv == 4)
	{
		sl_ending_three_one(data);

	}
	else if (data->end == 3 && data->wk <= 5 && data->u[data->x][data->y].mv != 4)
	{
		sl_ending_three_two(data);
	}
}

//     /* fucntion about ending of player */
// 		/* mode1: 'P' same position with 'E' | mode3: 'P' same position with
// 		  'M' | mode2: move and touching a Monster */
// int	sl_checkending(t_data *data, int mode)
// {
// 	if (mode == 1 && data->mmap[data->x][data->y] == 'E')
// 	{
// 		data->end = 1;
// 		//return (1);
// 	}
// 	else if (mode == 2 && data->mmap[data->x][data->y] == 'M') // && data->wk == 1;
// 	{
// 		if (data->u[data->x][data->y].mv == 2 && data->key == KEY_W)
// 			data->end = 2;
// 		else if (data->u[data->x][data->y].mv == 3 && data->key == KEY_A)
// 			data->end = 2;
// 		else if (data->u[data->x][data->y].mv == 0 && data->key == KEY_S)
// 			data->end = 2;
// 		else if (data->u[data->x][data->y].mv == 1 && data->key == KEY_D)
// 			data->end = 2;
// 		if (data->end == 2)
// 			data->u[data->x][data->y].kil = 1;
// 		// return (data->end);
// 	}
// 	else if (mode == 3 && data->mmap[data->x][data->y] == 'M')
// 	{
// 		data->end = 3;
// 		data->u[data->x][data->y].kil = 1;
// 		// return (3);
// 	}
// //	sl_ending_screen(data);
// 	// return (0);
// 	return (data->end);
// }

void	sl_ending_one(t_data *data, int f)
{
	mlx_put_image_to_window(data->mlx, data->window, data->e[5].img, data->y * 32, data->x * 32);
	if (data->wk <= 5)
		sl_walking_animate(data);
	else
		mlx_put_image_to_window(data->mlx, data->window, data->p[40 + (f % 5)].img, data->y * 32, data->x * 32);
	if (data->wk == 5)
		data->map[data->x][data->y] = '0';
}

void	sl_ending_two(t_data *data)
{
	if (data->wk == 1)
	{
		sl_walking_animate(data);
		sl_patroling_animate(data, data->x, data->y, 2);
	}
	if (data->wk > 1)
	{
		sl_ending_two_player(data);	
	}
	if (data->wk <= 2 && data->wk != 1)
	{
		sl_ending_two_monster(data);
	}
	else
		sl_patroling_animate(data, data->x, data->y, 2);	
	if (data->wk == 5)
		data->map[data->x][data->y] = '0';
}

void	sl_ending_two_player(t_data *data)
{
	if (data->key == KEY_A)
		mlx_put_image_to_window(data->mlx, data->window, \
			data->p[29 + data->wk].img, ((data->y + 1) * 32) - (6 * 2), data->x * 32);
	else if (data->key == KEY_S)
		mlx_put_image_to_window(data->mlx, data->window, \
			data->p[(29 + (data->pf / 2)) + data->wk].img, data->y * 32, ((data->x - 1) * 32) + (6 * 2));
	else if (data->key == KEY_D)
		mlx_put_image_to_window(data->mlx, data->window, \
			data->p[29 + data->wk].img, ((data->y - 1) * 32) + (6 * 2), data->x * 32);
	else if (data->key == KEY_W)
		mlx_put_image_to_window(data->mlx, data->window, \
			data->p[(29 + (data->pf / 2)) + data->wk].img, data->y * 32, ((data->x + 1) * 32) - (6 * 2));	
}

void	sl_ending_two_monster(t_data *data)
{
	if (data->u[data->x][data->y].mv == 1)
		mlx_put_image_to_window(data->mlx, data->window, \
			data->m[28 + data->wk].img, (data->y * 32) - 12, data->x * 32);
	else if (data->u[data->x][data->y].mv == 2)
		mlx_put_image_to_window(data->mlx, data->window, \
			data->m[(28 + (data->u[data->x + 1][data->y].pf / 2)) + data->wk].img, data->y * 32, (data->x * 32) + 12);
	else if (data->u[data->x][data->y].mv == 3)
		 mlx_put_image_to_window(data->mlx, data->window, \
		 	data->m[28 + data->wk].img, (data->y * 32) + 12, data->x * 32);
	else if (data->u[data->x][data->y].mv == 0)
		mlx_put_image_to_window(data->mlx, data->window, \
			data->m[(28 + (data->u[data->x - 1][data->y].pf / 2)) + data->wk].img, data->y * 32, (data->x * 32) - 12);
}

// void	sl_ending_three_one(t_data *data)
// {
// 	if (data->key == KEY_A)
// 		data->u[data->x][data->y].pf = 0;
// 	if (data->key == KEY_D)
// 		data->u[data->x][data->y].pf = 10;
// 	if (data->wk < 2)
// 		sl_walking_animate(data);
// 	else if (data->key == KEY_A)
// 		mlx_put_image_to_window(data->mlx, data->window, \
// 			data->p[29 + data->wk].img, ((data->y + 1) * 32) - (6 * 3), data->x * 32);
// 	else if (data->key == KEY_S)
// 		mlx_put_image_to_window(data->mlx, data->window, \
// 			data->p[(29 + (data->pf / 2)) + data->wk].img, data->y * 32, ((data->x - 1) * 32) + (6 * 3));
// 	else if (data->key == KEY_D)
// 		mlx_put_image_to_window(data->mlx, data->window, \
// 			data->p[29 + data->wk].img, ((data->y - 1) * 32) + (6 * 3), data->x * 32);
// 	else if (data->key == KEY_W)
// 		mlx_put_image_to_window(data->mlx, data->window, \
// 			data->p[(29 + (data->pf / 2)) + data->wk].img, data->y * 32, ((data->x + 1) * 32) - (6 * 3));
// 	mlx_put_image_to_window(data->mlx, data->window, \
// 		data->m[29 + data->wk + (data->u[data->x][data->y].pf / 2)].img, data->y * 32, data->x * 32);
// 	if (data->wk == 5)
// 		data->map[data->x][data->y] = '0';
// }

// void	sl_ending_three_two(t_data *data)
// {
// 		if (data->wk <= 2)
// 		{
// 			sl_walking_animate(data);
// 			sl_patroling_animate(data, data->x, data->y, 2);
// 		}
// 		if (data->wk > 2)
// 		{
// 			sl_ending_three_two_player(data);	
// 		}
// 		if (data->wk >= 3 && data->wk != 5)
// 		{
// 			sl_ending_three_two_monster(data);
// 		}
// 		else
// 			sl_patroling_animate(data, data->x, data->y, 2);	
// 		if (data->wk == 5)
// 			data->map[data->x][data->y] = '0';
// }

// void	sl_ending_three_two_player(t_data *data)
// {
// 	if (data->key == KEY_A)
// 		mlx_put_image_to_window(data->mlx, data->window, \
// 			data->p[29 + data->wk].img, ((data->y + 1) * 32) - 20, data->x * 32);
// 	else if (data->key == KEY_S)
// 		mlx_put_image_to_window(data->mlx, data->window, \
// 			data->p[(29 + (data->pf / 2)) + data->wk].img, data->y * 32, ((data->x - 1) * 32) + 20);
// 	else if (data->key == KEY_D)
// 		mlx_put_image_to_window(data->mlx, data->window, \
// 			data->p[29 + data->wk].img, ((data->y - 1) * 32) + 20, data->x * 32);
// 	else if (data->key == KEY_W)
// 		mlx_put_image_to_window(data->mlx, data->window, \
// 			data->p[(29 + (data->pf / 2)) + data->wk].img, data->y * 32, ((data->x + 1) * 32) - 20);	
// }

// void	sl_ending_three_two_monster(t_data *data)
// {
// 	if (data->u[data->x][data->y].mv == 1)
// 		mlx_put_image_to_window(data->mlx, data->window, \
// 			data->m[33 + data->wk].img, ((data->y + 1) * 32) - 20, data->x * 32);
// 	else if (data->u[data->x][data->y].mv == 2)
// 		mlx_put_image_to_window(data->mlx, data->window, \
// 			data->m[(28 + (data->u[data->x][data->y].pf / 2)) + data->wk].img, data->y * 32, ((data->x - 1) * 32) + 20);
// 	else if (data->u[data->x][data->y].mv == 3)
// 		 mlx_put_image_to_window(data->mlx, data->window, \
// 		 	data->m[28 + data->wk].img, ((data->y - 1) * 32) + 20, data->x * 32);
// 	else if (data->u[data->x][data->y].mv == 0)
// 		mlx_put_image_to_window(data->mlx, data->window, \
// 			data->m[(28 + (data->u[data->x][data->y].pf / 2)) + data->wk].img, data->y * 32, ((data->x + 1) * 32) - 20);
// }