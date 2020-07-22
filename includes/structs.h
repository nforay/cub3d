/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:31:35 by nforay            #+#    #+#             */
/*   Updated: 2020/07/10 16:19:50 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_vars {
	void			*mlx;
	void			*win;
}					t_vars;

typedef struct		s_image {
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				bpp;
	int				line_length;
	int				endian;
	int				padding;
}					t_image;

typedef struct		s_icoord {
	int				x;
	int				y;
}					t_icoord;

typedef struct		s_coord {
	double			x;
	double			y;
}					t_coord;

typedef struct		s_dblcolor {
	double			r;
	double			g;
	double			b;
}					t_dblcolor;

typedef struct		s_color {
	int				a;
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_wall
{
	int				color;
	int				tex_x;
	int				tex_y;
	char			padding[4];
	double			step;
	double			texpos;
}					t_wall;

typedef struct		s_floor
{
	t_image			*img;
	float			raydirx0;
	float			raydiry0;
	float			raydirx1;
	float			raydiry1;
	float			posz;
	float			rowdistance;
	float			stepx;
	float			stepy;
	float			floorx;
	float			floory;
	double			dist;
	int				cellx;
	int				celly;
	int				tx;
	int				ty;
	int				p;
	int				color;
}					t_floor;

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			spritex;
	double			spritey;
	double			transformx;
	double			transformy;
	int				texture;
	int				health;
	int				hit;
	int				active;
	int				spritescreenx;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	char			padding[4];
}					t_sprite;

typedef struct		s_spr_cast
{
	t_sprite		*curr;
	t_image			*img;
	t_icoord		tex;
	double			dist;
}					t_spr_cast;

typedef struct		s_frame {
	t_coord			raydir;
	t_coord			center;
	t_coord			intersect;
	t_coord			point;
	t_coord			line;
	double			camerax;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				raytex;
	int				angleside;
	double			wallx;
	double			skyx;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	double			wallxoffset;
	double			wallyoffset;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				color;
}					t_frame;

typedef struct		s_map {
	int				*s_order;
	char			**tab;
	char			**tmp;
	double			*s_dist;
	double			*d_offset;
	t_icoord		size;
	t_icoord		start;
	t_sprite		*sprite;
	char			*d_state;
	int				n_sprite;
	char			padding[4];
}					t_map;

typedef struct		s_params {
	t_vars			vars;
	t_map			map;
	t_image			img;
	t_image			north;
	t_image			south;
	t_image			east;
	t_image			west;
	t_image			crosshair;
	t_image			walltex;
	t_image			limitstex;
	t_image			floortex;
	t_image			infloortex;
	t_image			pushwall;
	t_image			cylindtex;
	t_image			doortex;
	t_image			doortex_y;
	t_image			doortex_r;
	t_image			doorframetex;
	t_image			doorframetex_y;
	t_image			doorframetex_r;
	t_image			weap;
	t_image			weapf;
	t_image			skybox;
	t_image			sprite;
	t_image			spritelive;
	t_image			spriteexp;
	t_image			spritedead;
	t_image			spritesolid;
	t_image			ammob;
	t_image			ammos;
	t_image			healthb;
	t_image			healths;
	t_image			gunspr;
	t_image			nightv;
	t_image			key_y;
	t_image			key_r;
	t_image			hud;
	t_image			font;
	t_color			floor;
	t_color			ceil;
	t_dblcolor		shadecol;
	t_dblcolor		baseshadecol;
	t_coord			dir;
	t_coord			pos;
	t_coord			plane;
	t_icoord		mouse;
	int				local_endian;
	int				move;
	int				interlace;
	int				alternate;
	int				debug;
	int				greyscale;
	int				firing;
	int				equiped;
	int				weaponcd;
	int				weaponbasecd;
	int				w;
	int				h;
	int				health;
	int				ammo;
	double			shadedist;
	double			shadefiring;
	double			sinr;
	double			sinmr;
	double			cosr;
	double			cosmr;
	double			movespeed;
	int				framecount;
	int				parser;
	int				captureframe;
	char			padding[4];
	int				*mapwidth;
	int				*mapheight;
	double			*zbuffer;
	char			*spritebuffer;
}					t_params;

typedef struct		s_bitmap
{
	unsigned int	filesize;
	unsigned short	reserved1;
	unsigned short	reserved2;
	unsigned int	pixeldataoffset;
	unsigned int	headersize;
	unsigned int	imagewidth;
	unsigned int	imageheight;
	unsigned short	planes;
	unsigned short	bitsperpixel;
	unsigned int	compression;
	unsigned int	imagesize;
	unsigned int	xpixelspermeter;
	unsigned int	ypixelspermeter;
	unsigned int	totalcolors;
	unsigned int	importantcolors;
}					t_bitmap;
#endif
