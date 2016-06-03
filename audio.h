/*
 * IPMic, The IP Microphone project
 * Copyright (C) 2016  Ricardo Biehl Pasquali <rbpoficial@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifdef _TINYALSA
#include	"tinyalsa.h"
#else
#include	<alsa/asoundlib.h>
#endif

#define AL_CAPTURE 0
#define AL_PLAYBACK 1

#define DEFAULT_CHANNELS 1
#define DEFAULT_RATE 22050

#ifdef _TINYALSA
typedef struct pcm audiolayer_t;
#else
typedef snd_pcm_t audiolayer_t;
#endif
typedef struct audiolayerparams_t audioparam_t;

struct audiolayerparams_t
{
	int type; /* playback or capture */
	int period_size; /* in frames */

/* internal defined: */
	unsigned int fsize_ib; /* frame size (in bytes) */
	unsigned int psize_ib; /* period size (in bytes) */
};

int
audiolayer_open(void);

int
audiolayer_close(void);

int
audiolayer_read(void*, unsigned int);

int
audiolayer_write(const void*, unsigned int);

inline void
audiolayer_prepare(void);
