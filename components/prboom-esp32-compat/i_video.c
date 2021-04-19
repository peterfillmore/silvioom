/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2006 by
 *  Jess Haas, Nicolas Kalkhof, Colin Phipps, Florian Schulze
 *  Copyright 2005, 2006 by
 *  Florian Schulze, Colin Phipps, Neil Stevens, Andrey Budko
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *  02111-1307, USA.
 *
 * DESCRIPTION:
 *  DOOM graphics stuff for SDL
 *
 *-----------------------------------------------------------------------------
 */
//#include <esp_log.h>

#include "config.h"
#include <stdlib.h>
#include <unistd.h>
#include "m_argv.h"
#include "doomstat.h"
#include "doomdef.h"
#include "doomtype.h"
#include "v_video.h"
#include "r_draw.h"
#include "d_main.h"
#include "d_event.h"
#include "gamepad.h"
#include "i_video.h"
#include "z_zone.h"
#include "s_sound.h"
#include "sounds.h"
#include "w_wad.h"
#include "st_stuff.h"
#include "lprintf.h"
#include "badge.h"
#include "badge_base.h"
#include "badge_eink_dev.h"
#include "badge_eink.h"
#include "badge_eink_fb.h"
#include "badge_eink_lut.h"
#include "badge_eink_types.h"

#include "badge_nvs.h"

#include "esp32/rom/ets_sys.h"

//#include "spi_lcd.h"

//#include "esp_heap_alloc_caps.h"

#include "esp_heap_caps.h"

static const char *TAG = "badge";

int use_fullscreen=0;
int use_doublebuffer=0;


void I_StartTic (void)
{
	gamepadPoll();
}


static void I_InitInputs(void)
{
}



static void I_UploadNewPalette(int pal)
{
}

//////////////////////////////////////////////////////////////////////////////
// Graphics API

void I_ShutdownGraphics(void)
{
}

//
// I_UpdateNoBlit
//
void I_UpdateNoBlit (void)
{
}


void I_StartFrame (void)
{
}


int I_StartDisplay(void)
{
    //const char *TAG = "badge";
    //static esp_err_t;
 
    // configure eink display
    uint8_t eink_type = BADGE_EINK_DEFAULT;
    badge_init();
    //badge_nvs_get_u8("badge", "eink.dev.type", &eink_type);
    badge_eink_init(eink_type);
    badge_eink_fb_init();
//    if (err != ESP_OK)
//    {
//        ESP_LOGE(TAG, "badge_eink_init failed: %d", err);
//    }
//
    //badge_init_done = true;

    //ESP_LOGD(TAG, "init done");
     
    //badge_init();
        //badge_eink_fb_init();
        //assert( err == ESP_OK );  
  // configure eink display
    //uint8_t eink_type = BADGE_EINK_DEPG0290B1;
    //badge_nvs_get_u8("badge", "eink.dev.type", &eink_type);
    //esp_err_t err = badge_eink_init(eink_type);
    //if (err != ESP_OK)
    //{
    //    //ESP_LOGE(TAG, "badge_eink_init failed: %d", err);
    //}
    //	
    ////spi_lcd_wait_finish();
  return true;
}

void I_EndDisplay(void)
{
}



static uint16_t *screena, *screenb;


//
// I_FinishUpdate
//

void I_FinishUpdate (void)
{
	//uint16_t *scr=(uint16_t*)screens[0].data;
	uint8_t *scr=(uint8_t*)screens[0].data;
#if 0 
	int x, y;
	char *chrs=" '.~+mM@";
	ets_printf("\033[1;1H");
	for (y=0; y<240; y+=4) {
		for (x=0; x<320; x+=2) {
			ets_printf("%c", chrs[(scr[x+y*320])>>13]);
		}
		ets_printf("\n");
	}
#endif
#if 1 
    uint32_t *tmpbuf = (uint32_t *) badge_eink_fb;
    int i;
    badge_eink_display_greyscale(scr, DISPLAY_FLAG_8BITPIXEL, 8); 
    //badge_eink_display(scr, DISPLAY_FLAG_8BITPIXEL); 
    //for (i = 0; i < 3; i++) {
    //    /* draw initial pattern */
    //    memset(tmpbuf, (i & 1) ? 0xff : 0x00, DISP_SIZE_X_B * DISP_SIZE_Y);

    //    struct badge_eink_update eink_upd = {
    //      .lut      = BADGE_EINK_LUT_DEFAULT,
    //      .reg_0x3a = 26,   // 26 dummy lines per gate
    //      .reg_0x3b = 0x08, // 62us per line
    //      .y_start  = 0,
    //      .y_end    = 295,
    //    };
    //    badge_eink_update(tmpbuf, &eink_upd);
    //}
    //for (int y = 0; y < DISP_SIZE_Y; y++) {
    //      for (int x = 0; x < DISP_SIZE_X; x++) {
    //        *tmpbuf++ = (uint32_t) *scr++; 
    //      }
    //    }
    //   
    //struct badge_eink_lut_entry lut[] = {
    //  { .length = 16, .voltages = 0x18, },
    //  { .length = 0 }
    //};

    //    struct badge_eink_update eink_upd = {
    //      .lut      = BADGE_EINK_LUT_DEFAULT,
    //      .reg_0x3a = 0,   // 26 dummy lines per gate
    //      .reg_0x3b = 0, // 62us per line
    //      .y_start  = 0,
    //      .y_end    = 295,
    //    };
 
    //struct badge_eink_update eink_upd = {
    //  .lut      = BADGE_EINK_LUT_CUSTOM,
    //  .lut_custom = lut,
    //  .reg_0x3a = 0,  // no dummy lines per gate
    //  .reg_0x3b = 0,  // 30us per line
    //  .y_start  = 0,
    //  .y_end    = 295,
    //};
    //badge_eink_update(tmpbuf, &eink_upd);
   
     
    //for (i = 0; i < 16; i++) {
    //    // curved
    //    const uint8_t lvl_buf[16] = {
    //        //  0,32,61,87,110,131,150,167,182,196,209,220,230,239,248,255
    //        //// 0.21
    //        0,   36,  67,  95,  119, 141, 160, 176,
    //        191, 204, 215, 225, 234, 242, 249, 255 // 0.15
    //    };
    //    uint8_t lvl = lvl_buf[i];
    //    int x, y;
    //    const uint8_t *ptr = scr;
    //    uint32_t *dptr = tmpbuf;
    //    for (y = 0; y < DISP_SIZE_Y; y++) {
    //      uint32_t res = 0;
    //      for (x = 0; x < DISP_SIZE_X; x++) {
    //        res <<= 1;
    //        if (*ptr++ <= lvl)
    //          res++;
    //        if ((x & 31) == 31)
    //          *dptr++ = res;
    //      }
    //    }

    ///* update LUT */
    //struct badge_eink_lut_entry lut[] = {
    //  { .length = i, .voltages = 0x18, },
    //  { .length = 0 }
    //};

    //struct badge_eink_update eink_upd = {
    //  .lut      = BADGE_EINK_LUT_CUSTOM,
    //  .lut_custom = lut,
    //  .reg_0x3a = 0,  // no dummy lines per gate
    //  .reg_0x3b = 0,  // 30us per line
    //  .y_start  = 0,
    //  .y_end    = 295,
    //};
    //badge_eink_update(tmpbuf, &eink_upd);
    //} 
	//spi_lcd_send(scr);
    
#endif
}
	//Flip framebuffers
//	if (scr==screena) screens[0].data=screenb; else screens[0].data=screena;


int16_t lcdpal[256];

void I_SetPalette (int pal)
{
	int i, r, g, b, v;
	int pplump = W_GetNumForName("PLAYPAL");
	const byte * palette = W_CacheLumpNum(pplump);
	palette+=pal*(3*256);
	for (i=0; i<255 ; i++) {
		v=((palette[0]>>3)<<11)+((palette[1]>>2)<<5)+(palette[2]>>3);
		lcdpal[i]=(v>>8)+(v<<8);
//		lcdpal[i]=v;
		palette += 3;
	}
	W_UnlockLumpNum(pplump);
}


unsigned char *screenbuf;

#define INTERNAL_MEM_FB


void I_PreInitGraphics(void)
{
	lprintf(LO_INFO, "preinitgfx");
#ifdef INTERNAL_MEM_FB
	//screenbuf=pvPortMallocCaps(320*240, MALLOC_CAP_INTERNAL|MALLOC_CAP_8BIT);
	//screenbuf=heap_caps_malloc(320*240, MALLOC_CAP_INTERNAL|MALLOC_CAP_8BIT);
	//screenbuf=malloc(320*240);
	screenbuf=malloc(BADGE_EINK_WIDTH*BADGE_EINK_HEIGHT);
	assert(screenbuf);
#endif
}


// CPhipps -
// I_SetRes
// Sets the screen resolution
void I_SetRes(void)
{
  int i;

//  I_CalculateRes(SCREENWIDTH, SCREENHEIGHT);

  // set first three to standard values
  for (i=0; i<3; i++) {
    screens[i].width = SCREENWIDTH;
    screens[i].height = SCREENHEIGHT;
    screens[i].byte_pitch = SCREENPITCH;
    screens[i].short_pitch = SCREENPITCH / V_GetModePixelDepth(VID_MODE16);
    screens[i].int_pitch = SCREENPITCH / V_GetModePixelDepth(VID_MODE32);
  }

  // statusbar
  screens[4].width = SCREENWIDTH;
  screens[4].height = (ST_SCALED_HEIGHT+1);
  screens[4].byte_pitch = SCREENPITCH;
  screens[4].short_pitch = SCREENPITCH / V_GetModePixelDepth(VID_MODE16);
  screens[4].int_pitch = SCREENPITCH / V_GetModePixelDepth(VID_MODE32);

//Attempt at double-buffering. Does not work.
//  free(screena);
//  free(screenb);
//  screena=malloc(SCREENPITCH*SCREENHEIGHT);
//  screenb=malloc(SCREENPITCH*SCREENHEIGHT);


#ifdef INTERNAL_MEM_FB
  screens[0].not_on_heap=true;
  screens[0].data=screenbuf;
  assert(screens[0].data);
#endif

//  spi_lcd_init();

  lprintf(LO_INFO,"I_SetRes: Using resolution %dx%d\n", SCREENWIDTH, SCREENHEIGHT);
}

void I_InitGraphics(void)
{
  char titlebuffer[2048];
  static int    firsttime=1;

  if (firsttime)
  {
    firsttime = 0;

    atexit(I_ShutdownGraphics);
    lprintf(LO_INFO, "I_InitGraphics: %dx%d\n", SCREENWIDTH, SCREENHEIGHT);

    /* Set the video mode */
    I_UpdateVideoMode();

    /* Initialize the input system */
    I_InitInputs();
	gamepadInit();

  }
}


void I_UpdateVideoMode(void)
{
  int init_flags;
  int i;
  video_mode_t mode;

  lprintf(LO_INFO, "I_UpdateVideoMode: %dx%d\n", SCREENWIDTH, SCREENHEIGHT);

//    mode = VID_MODE16;
    mode = VID_MODE8;

  V_InitMode(mode);
  V_DestroyUnusedTrueColorPalettes();
  V_FreeScreens();

  I_SetRes();

  V_AllocScreens();

  R_InitBuffer(SCREENWIDTH, SCREENHEIGHT);

}
