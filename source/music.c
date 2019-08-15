/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:46:31 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/14 14:15:02 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				music(int keycode, t_fractol *f)
{
	int				song;

	srand(time(NULL));
	song = rand() % 3;
	if (keycode == PLAY_SONG)
	{
		if (f->song_key == 1)
		{
			system("killall afplay");
			f->song_key = 0;
		}
		if (song == 0)
			system("afplay ./music/Eiffel_65_Blue.mp3 &");
		if (song == 1)
			system("afplay ./music/Haddaway_What_Is_Love.mp3 &");
		if (song == 2)
			system("afplay ./music/Bee_Gees_Stayin_Alive.mp3 &");
		f->song_key = 1;
	}
	if (keycode == STOP_SONG && f->song_key == 1)
	{
		system("killall afplay");
		f->song_key = 0;
	}
}
