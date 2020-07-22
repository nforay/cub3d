/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 15:39:28 by nforay            #+#    #+#             */
/*   Updated: 2020/07/19 02:09:25 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	load_missing_textures_next(t_params *p)
{
	if (!(p->doorframetex_r.width))
		if (!(load_xpm("./textures/defaults/frame.xpm", &p->doorframetex_r, p)))
			exit_msg(p, "Can't load texture.");
	if (!(p->cylindtex.width))
		if (!(load_xpm("./textures/defaults/cub3d.xpm", &p->cylindtex, p)))
			exit_msg(p, "Can't load texture.");
	if (!(p->spritelive.width))
		if (!(load_xpm("./textures/defaults/corona.xpm", &p->spritelive, p)))
			exit_msg(p, "Can't load texture.");
	if (!(p->spritesolid.width))
		if (!(load_xpm("./textures/defaults/corona.xpm", &p->spritesolid, p)))
			exit_msg(p, "Can't load texture.");
	if (!(p->key_y.width))
		if (!(load_xpm("./textures/defaults/sprites/key_y.xpm", &p->key_y, p)))
			exit_msg(p, "Can't load texture.");
	if (!(p->key_r.width))
		if (!(load_xpm("./textures/defaults/sprites/key_r.xpm", &p->key_r, p)))
			exit_msg(p, "Can't load texture.");
}

static void	load_missing_textures(t_params *p)
{
	if (!(p->walltex.width))
		if (!(load_xpm("./textures/defaults/stone.xpm", &p->walltex, p)))
			exit_msg(p, "Can't load texture.");
	if (!(p->floortex.width))
		if (!(load_xpm("./textures/defaults/flat.xpm", &p->floortex, p)))
			exit_msg(p, "Can't load texture.");
	if (!(p->doortex.width))
		if (!(load_xpm("./textures/defaults/door.xpm", &p->doortex, p)))
			exit_msg(p, "Can't load texture.");
	if (!(p->doortex_y.width))
		if (!(load_xpm("./textures/defaults/door.xpm", &p->doortex_y, p)))
			exit_msg(p, "Can't load texture.");
	if (!(p->doortex_r.width))
		if (!(load_xpm("./textures/defaults/door.xpm", &p->doortex_r, p)))
			exit_msg(p, "Can't load texture.");
	if (!(p->doorframetex.width))
		if (!(load_xpm("./textures/defaults/frame.xpm", &p->doorframetex, p)))
			exit_msg(p, "Can't load texture.");
	if (!(p->doorframetex_y.width))
		if (!(load_xpm("./textures/defaults/frame.xpm", &p->doorframetex_y, p)))
			exit_msg(p, "Can't load texture.");
	load_missing_textures_next(p);
}

static void	load_default_textures(t_params *p)
{
	if (!(load_xpm("./textures/defaults/limits.xpm", &p->limitstex, p)))
		exit_msg(p, "Can't load texture.");
	if (!(load_xpm("./textures/defaults/HUD/HUD.xpm", &p->hud, p)))
		exit_msg(p, "Can't load texture.");
	if (!(load_xpm("./textures/defaults/HUD/font.xpm", &p->font, p)))
		exit_msg(p, "Can't load texture.");
	if (!(load_xpm("./textures/defaults/sprites/weap_spr.xpm", &p->gunspr, p)))
		exit_msg(p, "Can't load texture.");
	if (!(load_xpm("./textures/defaults/sprites/ammo_b.xpm", &p->ammob, p)))
		exit_msg(p, "Can't load texture.");
	if (!(load_xpm("./textures/defaults/sprites/ammo_s.xpm", &p->ammos, p)))
		exit_msg(p, "Can't load texture.");
	if (!(load_xpm("./textures/defaults/sprites/health_b.xpm", &p->healthb, p)))
		exit_msg(p, "Can't load texture.");
	if (!(load_xpm("./textures/defaults/sprites/health_s.xpm", &p->healths, p)))
		exit_msg(p, "Can't load texture.");
	if (!(load_xpm("./textures/defaults/sprites/nightv.xpm", &p->nightv, p)))
		exit_msg(p, "Can't load texture.");
	if (!(load_xpm("./textures/defaults/HUD/crosshair.xpm", &p->crosshair, p)))
		exit_msg(p, "Can't load texture.");
	if (!(load_xpm("./textures/defaults/HUD/M2GFA0.xpm", &p->weapf, p)))
		exit_msg(p, "Can't load texture.");
	if (!(load_xpm("./textures/defaults/HUD/M2GFC0.xpm", &p->weap, p)))
		exit_msg(p, "Can't load texture.");
	load_missing_textures(p);
}

int			main_loop(t_params *p)
{
	if (BONUS)
		load_default_textures(p);
	if (!(p->img.img = mlx_new_image(p->vars.mlx, p->w, p->h)))
		quit_msg(p, "mlx_new_image returned NULL.");
	p->parser |= PARSER_IMG;
	if (!(p->img.addr = mlx_get_data_addr(p->img.img,
		&(p->img.bpp), &(p->img.line_length), &(p->img.endian))))
		return (0);
	if (p->captureframe)
		return (render_single_frame(p));
	if (!(p->vars.win = mlx_new_window(p->vars.mlx, p->w, p->h, "cub3d")))
		quit_msg(p, "mlx_new_window returned NULL.");
	p->parser |= PARSER_WIN;
	set_mlx_hooks(p);
	if (BONUS)
		initmap(p);
	mlx_loop_hook(p->vars.mlx, render_frame, p);
	mlx_loop(p->vars.mlx);
	return (1);
}

int			main(int argc, char **argv)
{
	int			fd;
	char		*path;
	t_params	tmp;

	if (argc > 3 || argc == 1)
		return (parse_error("Wrong number of arguments."));
	ft_memset(&tmp, 0, sizeof(t_params));
	path = argv[1];
	fd = open_fd(&tmp, path);
	if (argc == 3 && !(ft_strncmp(argv[2], "--save", 6)) &&
			ft_strlen(argv[2]) == 6)
		tmp.captureframe = 1;
	if (!(tmp.vars.mlx = mlx_init()))
		return (parse_error("Can't connect to mlx."));
	parse_fd(&tmp, fd);
	if (tmp.parser == 0)
		exit_msg(&tmp, "Empty .cub File");
	prepare_map(&tmp);
	main_loop(&tmp);
	quit(&tmp);
	return (0);
}
