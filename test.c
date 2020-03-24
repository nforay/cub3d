#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

#define K_Z 122
#define K_S 115
#define K_Q 113
#define K_D 100
#define K_UP 65362
#define K_DOWN 65364
#define K_LEFT 65361
#define K_RIGHT 65363

#define M_UP 0x00001
#define M_DOWN 0x00002
#define M_LEFT 0x00004
#define M_RIGHT 0x00008

#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define BLUE 0x000000FF
#define WHITE 0x00FFFFFF
#define YELLOW 0x00FFFF00
#define GREY 0x00BEBEBE
#define PURPLE 0x009900CC

int			worldMap[mapWidth][mapHeight]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

typedef struct  s_vars {
	void        *mlx;
	void        *win;
}               t_vars;

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_data;

typedef struct	s_coord {
	double		X;
	double		Y;
}				t_coord;

typedef struct	s_params {
	t_vars		vars;
	t_data		img;
	int			move;
	int			alternate;
	int			w;
	int			h;
	double		sinr;
	double		sinmr;
	double		cosr;
	double		cosmr;
	t_coord		dir;
	t_coord		pos;
	t_coord		plane;
}				t_params;

int	event_mouse(int button,int x,int y, t_params *params)
{
	printf("Mouse event - x:%d y:%d button:%d\n", x, y, button);
}

int	event_kbd_press(int keycode, t_params *params)
{
	//printf("Keyboard press event - keycode: %d\n", keycode);
	if (keycode == K_UP || keycode == K_Z)
		params->move |= M_UP;
	else if (keycode == K_DOWN || keycode == K_S)
		params->move |= M_DOWN;
	else if (keycode == K_LEFT || keycode == K_Q)
		params->move |= M_LEFT;
	else if (keycode == K_RIGHT || keycode == K_D)
		params->move |= M_RIGHT;
}

int	event_kbd_release(int keycode, t_params *params)
{
	//printf("Keyboard release event - keycode: %d\n", keycode);
	if (keycode == K_UP || keycode == K_Z)
		params->move &= ~M_UP;
	else if (keycode == K_DOWN || keycode == K_S)
		params->move &= ~M_DOWN;
	else if (keycode == K_LEFT || keycode == K_Q)
		params->move &= ~M_LEFT;
	else if (keycode == K_RIGHT || keycode == K_D)
		params->move &= ~M_RIGHT;
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char    *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	verLine(t_data *img, int x, int drawStart, int drawEnd, int color)
{
	while (drawStart < drawEnd)
		my_mlx_pixel_put(img, x, drawStart++, color);
	return (1);
}

double	dbl_abs(double nbr)
{
	return(nbr < 0 ? -nbr : nbr);
}

int		render_frame(t_params *params)
{
	params->alternate = !params->alternate;
	int x = params->alternate;
	//printf("%d\n", x);
	//params->img.img = mlx_new_image(params->vars.mlx, screenWidth, screenHeight);
	for(x; x < params->w; x += 2)
	{
		//calculate ray position and direction
		double cameraX = (2 * x) / ((double)(params->w) - 1); //x-coordinate in camera space
		double rayDirX = params->dir.X + params->plane.X * cameraX;
		double rayDirY = params->dir.Y + params->plane.Y * cameraX;
		//which box of the map we're in
		int mapX = (int)params->pos.X;
		int mapY = (int)params->pos.Y;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = dbl_abs(1 / rayDirX);
		double deltaDistY = dbl_abs(1 / rayDirY);
		//if (x <= 1 && params->move > 0)
		//printf("Movement: %u\nPlayerDirX: %f\nPlayerDirY: %f\nrayDirX: %f\nrayDirY: %f\ndeltDistX: %f\ndeltDistY: %f\nPlaneX: %f\nPlaneY: %f\nCameraX: %f\n------\n", params->move, params->dir.X, params->dir.Y, rayDirX, rayDirY, deltaDistX, deltaDistY, params->plane.X, params->plane.Y, cameraX);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (params->pos.X - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - params->pos.X) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (params->pos.Y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - params->pos.Y) * deltaDistY;
		}
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if(worldMap[mapX][mapY] > 0) hit = 1;
		}
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if(side == 0) perpWallDist = (mapX - params->pos.X + (1 - stepX) / 2) / rayDirX;
		else          perpWallDist = (mapY - params->pos.Y + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(params->h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + params->h / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + params->h / 2;
		if(drawEnd >= params->h)drawEnd = params->h - 1;

		//choose wall color
		int color;
		switch(worldMap[mapX][mapY])
		{
			case 1:  color = RED;    break; //red
			case 2:  color = GREEN;  break; //green
			case 3:  color = BLUE;   break; //blue
			case 4:  color = WHITE;  break; //white
			default: color = YELLOW; break; //yellow
		}

		//give x and y sides different brightness
		if(side == 1) {color = color / 2;}

		//draw the pixels of the stripe as a vertical line
		verLine(&params->img, x, 0, drawStart, PURPLE); //			Draw ceil
		verLine(&params->img, x, drawEnd, params->h, GREY);	//	Draw floor
		verLine(&params->img, x, drawStart, drawEnd, color);	//	Draw walls
	}

	mlx_put_image_to_window(params->vars.mlx, params->vars.win, params->img.img, 0, 0);
	//mlx_destroy_image(params->vars.mlx, params->img.img);
	//speed modifiers
	double moveSpeed = 0.002; //squares/frame

	if(params->move & M_UP)
	{
		if(worldMap[(int)(params->pos.X + params->dir.X * moveSpeed)][(int)(params->pos.Y)] == 0) params->pos.X += params->dir.X * moveSpeed;
		if(worldMap[(int)(params->pos.X)][(int)(params->pos.Y + params->dir.Y * moveSpeed)] == 0) params->pos.Y += params->dir.Y * moveSpeed;
	}
	if(params->move & M_DOWN)
	{
		if(worldMap[(int)(params->pos.X - params->dir.X * moveSpeed)][(int)(params->pos.Y)] == 0) params->pos.X -= params->dir.X * moveSpeed;
		if(worldMap[(int)(params->pos.X)][(int)(params->pos.Y - params->dir.Y * moveSpeed)] == 0) params->pos.Y -= params->dir.Y * moveSpeed;
	}
	if(params->move & M_RIGHT)
	{
		double oldDirX = params->dir.X;
		params->dir.X = (params->dir.X * params->cosmr) - (params->dir.Y * params->sinmr);
		params->dir.Y = (oldDirX * params->sinmr) + (params->dir.Y * params->cosmr);
		double oldPlaneX = params->plane.X;
		params->plane.X = params->plane.X * params->cosmr - params->plane.Y * params->sinmr;
		params->plane.Y = oldPlaneX * params->sinmr + params->plane.Y * params->cosmr;
	}
	if(params->move & M_LEFT)
	{
		double oldDirX = params->dir.X;
		params->dir.X = params->dir.X * params->cosr - params->dir.Y * params->sinr;
		params->dir.Y = oldDirX * params->sinr + params->dir.Y * params->cosr;
		double oldPlaneX = params->plane.X;
		params->plane.X = params->plane.X * params->cosr - params->plane.Y * params->sinr;
		params->plane.Y = oldPlaneX * params->sinr + params->plane.Y * params->cosr;
	}
	return (1);
}

int	exit_hook(t_params *params)
{
	mlx_destroy_image(params->vars.mlx, params->img.img);
	return (1);
}

int main()
{
	t_vars		vars;
	t_params	params;

	params.pos.X = 12.0;
	params.pos.Y = 10.0;  //x - y start position
	params.dir.X = -1.0;
	params.dir.Y = 0.0; //vecteur direction initial
	params.alternate = 0;
	params.move = 0;
	params.plane.X = 0.0;
	params.plane.Y = 0.66; //plan 2D camera raycaster
	params.w = screenWidth;
	params.h = screenHeight;
	params.cosr = cos(0.002);
	params.cosmr = cos(-0.002);
	params.sinr = sin(0.002);
	params.sinmr = sin(-0.002);
	params.vars.mlx = mlx_init();
	params.vars.win = mlx_new_window(params.vars.mlx,screenWidth, screenHeight,"cub3d");
	mlx_do_key_autorepeaton(params.vars.mlx);
	mlx_hook(params.vars.win, 2, 0x1, event_kbd_press, &params);
	mlx_hook(params.vars.win, 3, 0x2, event_kbd_release, &params);
	mlx_hook(params.vars.win, 4, 0x4, event_mouse, &params);
	mlx_hook(params.vars.win, 5, 0x8, event_mouse, &params);
	mlx_hook(params.vars.win, 6, 0x40, event_mouse, &params);
	//mlx_hook(v->window, 12, 0, expose_hook, v);
	mlx_hook(params.vars.win, 17, 0, exit_hook, &params);
	//mlx_mouse_hook(params.vars.win, event_mouse, &params.vars);
	params.img.img = mlx_new_image(params.vars.mlx, screenWidth, screenHeight);
	params.img.addr = mlx_get_data_addr(params.img.img, &params.img.bits_per_pixel,
			&params.img.line_length, &params.img.endian);
	mlx_loop_hook(params.vars.mlx, render_frame, &params);
	//mlx_put_image_to_window(params.vars.mlx, params.vars.win, params.img.img, 0, 0);
	mlx_loop(params.vars.mlx);
	mlx_destroy_image(params.vars.mlx, params.img.img);
}

