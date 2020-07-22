/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 15:42:04 by nforay            #+#    #+#             */
/*   Updated: 2020/07/19 23:45:45 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "structs.h"
# include "keycodes.h"
# include <math.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>

# ifndef BONUS
#  define BONUS 0
# endif
# define STRBONUS " 0123456789ABCDGHIJKLMOPQRTUVXYZ"

# define M_UP 0x00001
# define M_DOWN 0x00002
# define M_LEFT 0x00004
# define M_RIGHT 0x00008
# define M_STRLE 0x00010
# define M_STRRI 0x00020
# define M_SPRINT 0x00040
# define M_CTRL 0x00080
# define M_QUIT 0x00100
# define M_FIRE 0x00200

# define PARSER_R 0x00001
# define PARSER_NO 0x00002
# define PARSER_SO 0x00004
# define PARSER_EA 0x00008
# define PARSER_WE 0x00010
# define PARSER_S 0x00020
# define PARSER_F 0x00040
# define PARSER_C 0x00080
# define PARSER_MAP 0x00100
# define PARSER_SPR 0x00200
# define PARSER_BUF 0x00400
# define PARSER_DOOR 0x00800
# define PARSER_IMG 0x01000
# define PARSER_WIN 0x02000

# define INV_GUN	0x00001
# define INV_KEY_Y	0x00002
# define INV_KEY_R	0x00004

# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00
# define SKY 0x00E0FF

void	add_door_offset(t_map *map, int x, int y, double offset);
int		build_sprite_tables(t_params *tmp, t_map *map);
int		char_in_str(const char *s, int c);
t_coord	check_collision(t_params *params, double speed);
t_coord	check_collision_back(t_params *params, double speed);
void	check_column_hit(t_params *params, t_frame *f);
void	check_corner_wall_hit(t_params *params, t_frame *f);
void	check_door_hit(t_params *params, t_frame *f);
void	check_pushwall_hit(t_params *params, t_frame *f);
void	check_rounded_angle_hit(t_params *params, t_frame *f);
int		check_surroundings(char **a, t_icoord s, t_icoord p);
t_coord	collision_bot_left(t_params *p, t_coord pos, double radius);
t_coord	collision_bot_right(t_params *p, t_coord pos, double radius);
t_coord	collision_top_left(t_params *p, t_coord pos, double radius);
t_coord	collision_top_right(t_params *p, t_coord pos, double radius);
void	count_sprites(t_map *map);
void	destroy_bonus_images(t_params *params);
void	destroy_images(t_params *tmp);
void	door_hit_x(t_params *params, t_frame *f);
void	door_hit_y(t_params *params, t_frame *f);
double	door_offset(t_map *map, int x, int y);
int		door_state(t_params *params, int x, int y);
void	draw_bonus_to_img(t_params *params);
void	draw_circle(t_image *img, int x, int y, int r);
void	draw_floor(t_params *params, int x, int drawend);
void	draw_sky(t_params *p, int x, int drawstart, t_frame f);
void	draw_sprite_bis(t_params *p, int x);
void	draw_square(t_params *params, int x, int y, int len);
void	draw_stripe(t_params *params, t_frame *f, int x);
void	draw_wall(t_params *params, int x, t_frame *f);
int		duplicate_map(t_map *map, t_icoord size);
int		event_kbd_press(int keycode, t_params *params);
void	event_kbd_press_bonus(int keycode, t_params *params);
void	event_kbd_press_editor(int keycode, t_params *params);
void	event_kbd_press_editor_next(int keycode, t_params *params);
int		event_kbd_release(int keycode, t_params *params);
int		event_mouse_move(int x, int y, t_params *params);
int		event_mouse_press(int button, int x, int y, t_params *params);
int		event_mouse_release(int button, int x, int y, t_params *params);
void	exit_free(t_params *tmp, int quit);
int		exit_hook(t_params *params);
void	exit_msg(t_params *tmp, char *msg);
void	fill_sprite_table(t_map *map);
int		fix_map(char **a, t_icoord size, int i, int j);
void	flood_fill(t_params *tmp, int x, int y);
void	free_allocated_tables(t_params *params);
void	free_tab(char **tab, int size);
int		ft_atoi_basic(const char *str);
int		ft_bufferstate(t_params *params, int x, int y);
void	ft_dblswap(double *a, double *b);
int		ft_get_bloc_id(t_params *params);
void	ft_printnbr(int nbr, int x, int y, t_params *params);
void	ft_printnbr_rtl(unsigned int nbr, int x, int y, t_params *params);
void	ft_set_bloc_id(t_params *params, int id);
char	**ft_tab_join(char **tab, const char *str, int size);
void	ft_swap(int *a, int *b);
void	ft_writebuffer(t_params *params, int x, int y);
t_coord	getangle(t_coord a, t_coord b);
int		getcolor(t_color color);
void	get_floor_data(t_params *params, t_floor *f, int x, int y);
void	get_floor_tex(t_params *params, t_floor *f);
int		get_intlen(int n, int len);
t_image	*get_side_tex(t_params *params, t_frame *f);
t_image	*get_sprite_img(t_params *p, t_sprite *sprite);
t_image	*get_sprite_img_bonus(t_params *p, t_sprite *sprite);
int		getwallpixelcolor(t_params *p, t_image *img, t_frame *f, t_wall *w);
t_image	*get_wall_tex(t_params *params, t_frame *f);
t_image	*get_wall_tex_next(t_params *params, t_frame *f);
void	get_sprite_dist(t_params *p);
void	get_sprite_pos(t_params *p);
void	get_step_and_sidedist(t_params *params, t_frame *f);
void	get_wall_data(t_params *params, t_frame *f, int x);
void	get_wall_values(t_wall *w, t_image *img, t_frame *f, t_params *params);
int		getpixelcolor(t_image *img, int x, int y);
int		greyscale(t_params *p, int color);
void	init_game(t_params *params);
void	init_player(t_params *tmp);
void	init_sprite(t_sprite *sprite, int i, int j, int tex);
void	initmap(t_params *params);
int		isblocking(t_params *params, int x, int y);
int		is_interactible(char c);
int		is_interior(int c);
t_coord	lineintersect(t_params *params, t_coord raydir, t_coord map, int side);
int		load_texture(t_params *tmp, t_image *img, char *path, int parser);
int		load_xpm(char *path, t_image *img, t_params *params);
int		main_loop(t_params *params);
void	make_buffers(t_params *tmp);
void	make_doors_table(t_params *tmp, t_map *map);
void	merge_doorframe(t_params *params, t_frame *f);
void	mouse_move_left(t_params *params, int diff, int x, int y);
void	mouse_move_right(t_params *params, int diff, int x, int y);
void	move_player(t_params *params);
void	move_sprite_toward_player(t_params *params, t_sprite *this);
void	movedoor(int i, int j, t_params *params);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
void	my_mlx_pixel_put_bl(t_image *img, int x, int y, int color);
void	newframe_init_sprite(t_params *params);
int		open_fd(t_params *tmp, char *path);
void	optimize_tab(t_map *map, t_icoord size);
int		parse_bonus(t_params *tmp, char *line);
int		parse_color(t_params *tmp, char *line);
int		parse_error(char *msg);
int		parse_error_detail(t_params *tmp, char *line);
void	parse_fd(t_params *tmp, int fd);
int		parse_line(t_params *tmp, char *line);
int		parse_map(t_params *tmp, char *line);
int		parse_resolution(t_params *tmp, char *line);
int		parse_texture(t_params *tmp, char *line);
void	perform_digital_differential_analysis(t_params *params, t_frame *f);
void	perform_sprites_interactions(t_params *params, int i);
void	player_rotate_left(t_params *params);
void	player_rotate_right(t_params *params);
void	prepare_map(t_params *tmp);
void	prepare_new_ray(t_params *params, t_frame *f, int x);
void	print_tab(char **a, t_icoord size);
void	pushwall(int i, int j, t_params *params);
void	put_sprite_to_img(t_params *p, t_spr_cast *s, int x, int y);
void	quit(t_params *params);
void	quit_msg(t_params *params, char *str);
int		raycircle(t_coord p1, t_coord dp, t_coord sc, t_coord *intersect);
int		raycircleangle(t_coord p1, t_coord dp, t_coord sc, t_coord *intersect);
int		reachable(char **tab, int y, int x);
void	refreshmap(t_params *params);
int		render_frame(t_params *p);
int		render_single_frame(t_params *p);
int		rgb_string_to_int(char **str);
void	rounded_bot_left_hit(t_params *params, t_frame *f);
void	rounded_bot_right_hit(t_params *params, t_frame *f);
void	rounded_top_left_hit(t_params *params, t_frame *f);
void	rounded_top_right_hit(t_params *params, t_frame *f);
int		save_screenshot(t_params *params);
void	set_door_offset(t_map *map, int x, int y, double offset);
void	set_door_state(t_params *params, int x, int y, int state);
void	set_mlx_hooks(t_params *p);
void	set_player_dir(t_params *tmp, char c);
void	shade_and_draw_floor(t_params *params, t_floor f, int x, int y);
int		shade_sprite_color(t_params *p, t_spr_cast s, int color);
void	shade_wall_color(t_params *params, t_wall *w, t_frame f, int x);
int		shadecolor(t_params *p, double dist, int color);
int		shadecolor_nodist(t_params *p, int color);
int		shadedamagecolor(t_params *p, double dist, int color);
int		shadefiringcolor(t_params *p, double dist, int color);
void	sortsprites(int *order, double *distance, int number);
t_coord	spr_col_bot_left(t_params *p, t_coord pos, t_coord orig,
		double radius);
t_coord	spr_col_bot_right(t_params *p, t_coord pos, t_coord orig,
		double radius);
t_coord	spr_col_top_left(t_params *p, t_coord pos, t_coord orig,
		double radius);
t_coord	spr_col_top_right(t_params *p, t_coord pos, t_coord orig,
		double radius);
t_coord	spr_colision(t_params *params, t_coord orig, t_coord dir, double s);
int		spr_delta(t_coord *delta, t_coord *pos, int x, int y);
int		sprite_hitscan(t_params *p, int x, int y);
int		tile_has_ceiling(t_params *params, t_floor *f, int x, int y);
int		validate_map_line(t_map *map, char *line);
void	verline(t_params *params, int x, t_frame f);
void	verline_ceil(t_params *p, int x, int y, int drawend);
void	verline_floor(t_params *p, int x, int y, int drawend);

#endif
