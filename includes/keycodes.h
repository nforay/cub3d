/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:31:33 by nforay            #+#    #+#             */
/*   Updated: 2020/07/06 14:05:01 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# ifdef __linux__
#  define K_Z		122
#  define K_S		115
#  define K_Q		113
#  define K_D		100
#  define K_UP		65362
#  define K_DOWN	65364
#  define K_LEFT	65361
#  define K_RIGHT	65363
#  define K_SHIFT	65505
#  define K_CTRL	65507
#  define K_ESC		65307
#  define K_E		101
#  define K_1		38
#  define K_2		233
#  define K_3		34
#  define K_4		39
#  define K_5		40
#  define K_NUM1	65436
#  define K_NUM2	65433
#  define K_NUM3	65435
#  define K_NUM4	65430
#  define K_NUM5	65437
#  define K_NUM6	65432
#  define K_NUM7	65429
#  define K_NUM8	65431
# else
#  define K_Z		13
#  define K_S		1
#  define K_Q		0
#  define K_D		2
#  define K_UP		126
#  define K_DOWN	125
#  define K_LEFT	123
#  define K_RIGHT	124
#  define K_SHIFT	57
#  define K_CTRL	59
#  define K_ESC		53
#  define K_E		14
#  define K_1		18
#  define K_2		19
#  define K_3		20
#  define K_4		21
#  define K_5		23
#  define K_NUM1	83
#  define K_NUM2	84
#  define K_NUM3	85
#  define K_NUM4	86
#  define K_NUM5	87
#  define K_NUM6	88
#  define K_NUM7	89
#  define K_NUM8	91
# endif
#endif
