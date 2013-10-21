/********************************************************************************/
/*!
	@file			ts.c
	@author         Nemui Trinomius (http://nemuisan.blog.bai.ne.jp)
    @version        11.00
    @date           2013.09.20
	@brief          Based on Chan's MCI_OLED@LPC23xx-demo thanks!

    @section HISTORY
		2010.12.31	V1.00	ReStart here.
		2011.03.10	V2.00	C++ Ready.
		2011.06.18  V3.00	Added SSD1963 Consideration 
							      and X clipper for some display's limitations
								  and Fixed Parent/Current Directory return bug.
		2011.10.14  V4.00   Added Chan's Tiny JPEG Decoder Support.
		2011.12.01  V5.00   Use FPU on IJG Decoding in use of STM32F4xx. 
		2012.01.31	V6.00	Fixed Pointer bugfix on IJG Decoding.
		2012.02.21	V7.00	Added Chan's Text Viewer Support.
		2012.03.12  V8.00   Added More FontSize.
							Fixed JPEG Decompress parameter@IJG.
		2012.04.01  V9.00   Separated to Filer & FileLoder Sections.
		2012.06.15 V10.00   Added External SRAM Support.
		2013.09.20 V11.00   Added more colour definitions.

    @section LICENSE
		BSD License. See Copyright.txt
*/
/********************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "ts.h"

/* Defines -------------------------------------------------------------------*/
#if  defined(EXT_SRAM_SUPPORT)
 #define _EXRAM  __attribute__ ((section(".extram")))
#else
 #define _EXRAM
#endif

/* Variables -----------------------------------------------------------------*/
/* Used for Cursor and Original Movies */
volatile uint8_t  CsrFlag, TmrCsr;
volatile int32_t  TmrFrm;
volatile uint16_t Attr _EXRAM;
volatile uint16_t Col _EXRAM;
volatile uint16_t Row _EXRAM;

/* Usec for SJIS 2Byte Charactor */
#if USE_FILER_FONTX
volatile uint8_t flg =0;
#endif

/* Used for STM32Primer2 */
#if defined(USE_STM32PRIMER2) || defined(USE_TIME_DISPLAY)
extern  volatile uint32_t on_filer=1;
#endif

/* Used for Filer VRAM */
uint16_t Vram[TS_HEIGHT][TS_WIDTH] _EXRAM;

/* Constants -----------------------------------------------------------------*/
#if !USE_FILER_FONTX
const uint8_t font[128][8] = {
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0xA8,0x54,0xA8,0x54,0xA8,0x54,0xA8,0x54},
	{0x00,0x20,0x10,0xF8,0x10,0x20,0x00,0x00},
	{0x00,0x20,0x40,0xF8,0x40,0x20,0x00,0x00},
	{0x20,0x70,0xA8,0x20,0x20,0x20,0x20,0x00},
	{0x20,0x20,0x20,0x20,0xA8,0x70,0x20,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x3C,0x20,0x20,0x20,0x20},
	{0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0xE0,0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0xFC,0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x3C,0x00,0x00,0x00,0x00},
	{0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0xE0,0x00,0x00,0x00,0x00},
	{0x20,0x20,0x20,0xFC,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0xFC,0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0xE0,0x20,0x20,0x20,0x20},
	{0x20,0x20,0x20,0x3C,0x20,0x20,0x20,0x20},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x20,0x20,0x20,0x20,0x20,0x00,0x20,0x00},
	{0x50,0x50,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x60,0x60,0xF0,0x60,0xF0,0x60,0x60,0x00},
	{0x20,0x70,0x80,0x60,0x10,0xE0,0x20,0x00},
	{0x00,0x90,0x90,0x20,0x40,0x90,0x90,0x00},
	{0x40,0xA0,0xA0,0x40,0xA0,0xA0,0xF0,0x00},
	{0x20,0x20,0x40,0x00,0x00,0x00,0x00,0x00},
	{0x20,0x40,0x40,0x40,0x40,0x40,0x20,0x00},
	{0x40,0x20,0x20,0x20,0x20,0x20,0x40,0x00},
	{0x00,0x20,0x70,0x20,0x50,0x00,0x00,0x00},
	{0x00,0x20,0x20,0x70,0x20,0x20,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x40},
	{0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00},
	{0x10,0x10,0x20,0x20,0x20,0x40,0x40,0x00},
	{0x60,0x90,0x90,0xB0,0xD0,0x90,0x60,0x00},
	{0x20,0x60,0x20,0x20,0x20,0x20,0x20,0x00},
	{0x60,0x90,0x10,0x20,0x40,0x80,0xF0,0x00},
	{0x60,0x90,0x10,0x20,0x10,0x90,0x60,0x00},
	{0x20,0x60,0x60,0xA0,0xF0,0x20,0x20,0x00},
	{0xF0,0x80,0xE0,0x10,0x10,0x90,0x60,0x00},
	{0x60,0x80,0x80,0xE0,0x90,0x90,0x60,0x00},
	{0xF0,0x90,0x10,0x20,0x20,0x20,0x20,0x00},
	{0x60,0x90,0x90,0x60,0x90,0x90,0x60,0x00},
	{0x60,0x90,0x90,0x70,0x10,0x10,0x60,0x00},
	{0x00,0x20,0x00,0x00,0x00,0x20,0x00,0x00},
	{0x00,0x20,0x00,0x00,0x00,0x20,0x40,0x00},
	{0x00,0x10,0x60,0x80,0x60,0x10,0x00,0x00},
	{0x00,0x00,0xF0,0x00,0xF0,0x00,0x00,0x00},
	{0x00,0x80,0x60,0x10,0x60,0x80,0x00,0x00},
	{0x60,0x90,0x10,0x20,0x20,0x00,0x20,0x00},
	{0x60,0x90,0x90,0xB0,0xB0,0xB0,0x50,0x00},
	{0x60,0x90,0x90,0x90,0xF0,0x90,0x90,0x00},
	{0xE0,0x90,0x90,0xE0,0x90,0x90,0xE0,0x00},
	{0x60,0x90,0x80,0x80,0x80,0x90,0x60,0x00},
	{0xE0,0x90,0x90,0x90,0x90,0x90,0xE0,0x00},
	{0xF0,0x80,0x80,0xE0,0x80,0x80,0xF0,0x00},
	{0xF0,0x80,0x80,0xE0,0x80,0x80,0x80,0x00},
	{0x60,0x90,0x80,0xB0,0x90,0x90,0x70,0x00},
	{0x90,0x90,0x90,0xF0,0x90,0x90,0x90,0x00},
	{0x70,0x20,0x20,0x20,0x20,0x20,0x70,0x00},
	{0x70,0x20,0x20,0x20,0x20,0x20,0x20,0xC0},
	{0x90,0x90,0xA0,0xC0,0xA0,0x90,0x90,0x00},
	{0x80,0x80,0x80,0x80,0x80,0x80,0xF0,0x00},
	{0x90,0xF0,0xF0,0x90,0x90,0x90,0x90,0x00},
	{0x90,0xD0,0xD0,0xB0,0xB0,0x90,0x90,0x00},
	{0x60,0x90,0x90,0x90,0x90,0x90,0x60,0x00},
	{0xE0,0x90,0x90,0xE0,0x80,0x80,0x80,0x00},
	{0x60,0x90,0x90,0x90,0xF0,0x90,0x70,0x00},
	{0xE0,0x90,0x90,0xE0,0xA0,0x90,0x90,0x00},
	{0x70,0x80,0x80,0x60,0x10,0x10,0xE0,0x00},
	{0xF0,0x20,0x20,0x20,0x20,0x20,0x20,0x00},
	{0x90,0x90,0x90,0x90,0x90,0x90,0x60,0x00},
	{0x90,0x90,0x90,0x90,0x60,0x60,0x60,0x00},
	{0x90,0x90,0x90,0xF0,0xF0,0xF0,0x90,0x00},
	{0x90,0x90,0x60,0x60,0x60,0x90,0x90,0x00},
	{0x90,0x90,0x50,0x20,0x20,0x20,0x20,0x00},
	{0xF0,0x10,0x20,0x20,0x40,0x80,0xF0,0x00},
	{0x70,0x40,0x40,0x40,0x40,0x40,0x70,0x00},
	{0x80,0x80,0x40,0x40,0x20,0x10,0x10,0x00},
	{0x70,0x10,0x10,0x10,0x10,0x10,0x70,0x00},
	{0x20,0x50,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00},
	{0x20,0x20,0x10,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x60,0x10,0x70,0x90,0x70,0x00},
	{0x80,0x80,0xA0,0xD0,0x90,0x90,0xE0,0x00},
	{0x00,0x00,0x70,0x80,0x80,0x80,0x70,0x00},
	{0x10,0x10,0x70,0x90,0x90,0x90,0x70,0x00},
	{0x00,0x00,0x60,0x90,0xF0,0x80,0x60,0x00},
	{0x10,0x20,0x20,0x70,0x20,0x20,0x20,0x00},
	{0x00,0x00,0x70,0x90,0x90,0x70,0x10,0x60},
	{0x80,0x80,0xA0,0xD0,0x90,0x90,0x90,0x00},
	{0x20,0x00,0x20,0x20,0x20,0x20,0x20,0x00},
	{0x10,0x00,0x10,0x10,0x10,0x10,0x90,0x60},
	{0x80,0x80,0x90,0xA0,0xE0,0x90,0x90,0x00},
	{0x60,0x20,0x20,0x20,0x20,0x20,0x20,0x00},
	{0x00,0x00,0xE0,0xF0,0xF0,0xF0,0xF0,0x00},
	{0x00,0x00,0xA0,0xD0,0x90,0x90,0x90,0x00},
	{0x00,0x00,0x60,0x90,0x90,0x90,0x60,0x00},
	{0x00,0x00,0xE0,0x90,0x90,0xE0,0x80,0x80},
	{0x00,0x00,0x70,0x90,0x90,0x70,0x10,0x10},
	{0x00,0x00,0xB0,0xC0,0x80,0x80,0x80,0x00},
	{0x00,0x00,0x70,0x80,0x60,0x10,0xE0,0x00},
	{0x20,0x20,0x70,0x20,0x20,0x20,0x10,0x00},
	{0x00,0x00,0x90,0x90,0x90,0xB0,0x50,0x00},
	{0x00,0x00,0x90,0x90,0x90,0x60,0x60,0x00},
	{0x00,0x00,0x90,0xF0,0xF0,0xF0,0x90,0x00},
	{0x00,0x00,0x90,0x90,0x60,0x90,0x90,0x00},
	{0x00,0x00,0x90,0x90,0x50,0x60,0x20,0xC0},
	{0x00,0x00,0xF0,0x10,0x60,0x80,0xF0,0x00},
	{0x10,0x20,0x20,0x40,0x20,0x20,0x10,0x00},
	{0x20,0x20,0x20,0x00,0x20,0x20,0x20,0x00},
	{0x40,0x20,0x20,0x10,0x20,0x20,0x40,0x00},
	{0x40,0xF0,0x20,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
};
#endif

/* Function prototypes -------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/
/**************************************************************************/
/*! 
    Display RTC Timeline.
*/
/**************************************************************************/
#if defined(USE_STM32PRIMER2) || defined(USE_TIME_DISPLAY)
inline void ts_rtc(void)
{
	if(on_filer && TimeDisplay)
	{
		ts_locate(TS_FILER_HEIGHT,0,0);
		rtc = Time_GetCalendarTime();
	#ifdef USE_STM32PRIMER2
		if(LOWBATT_ALARM)
		{
			xprintf("\33\x87 %04u/%02u/%02u %02u:%02u:%02u LOW  ",\
			rtc.tm_year, rtc.tm_mon+1, rtc.tm_mday, rtc.tm_hour, rtc.tm_min, rtc.tm_sec);
		}
		else
		{
	#endif
			xprintf("\33\x87 %04u/%02u/%02u %02u:%02u:%02u      ",\
			rtc.tm_year, rtc.tm_mon+1, rtc.tm_mday, rtc.tm_hour, rtc.tm_min, rtc.tm_sec);
	#ifdef USE_STM32PRIMER2
		}
	#endif
	
		TimeDisplay = 0;
	}
}
#endif



/**************************************************************************/
/*! 
    Terminal Screen Write Function Lowest Side.
*/
/**************************************************************************/
void ts_write(
	uint8_t row,
	uint8_t col,
	uint16_t chr
)
{
	uint16_t fg, bg, xclip;

#if USE_FILER_FONTX
	uint8_t ankode;
	static uint8_t col_r,row_r;
	static uint16_t unk;

#else
	int x, y;
	uint8_t pat;
	uint16_t wd;
	const uint8_t *fnt;

#endif

	static const uint16_t color[8] = {
		COL_BLACK, COL_BLUE, COL_RED, COL_MAGENTA, COL_GREEN, COL_AQUA, COL_YELLOW, COL_WHITE
	};


	if (row >= TS_HEIGHT || col >= TS_WIDTH) return;
	
	/* X clipper if U need */
	xclip = col * TS_FONTW + TS_FONTW - 1;
    if (xclip > MAX_X) xclip = MAX_X-1;

#if !USE_FILER_FONTX
	Display_rect_if(col * TS_FONTW, xclip, row * TS_FONTH, row * TS_FONTH + TS_FONTH - 1);
#endif

	fg = color[(chr >> 8) & 7];
	bg = color[(chr >> 12) & 7];


#if USE_FILER_FONTX
	ankode = chr & 0xFF;

	if(flg){
		unk |= (uint16_t)(ankode<<8);
		putkanji(col_r * TS_FONTW, row_r * TS_FONTH, (uint8_t*)&unk, fg, bg);
		flg=0;
	}
	else{
		if(((ankode >= 0x80)&&(ankode < 0xA0))||((ankode >= 0xE0)&&(ankode <= 0xFF))){
			unk = ankode;
			col_r = col;
			row_r =row;
			flg=1;
	  	}
		else{
			putank(col * TS_FONTW, row * TS_FONTH, &ankode, fg, bg);
			flg=0;
		}
	}

#else
	
	fnt = font[chr & 127];

	for (y = 0; y < TS_FONTH; y++) {
		pat = *fnt++;
		for (x = 0; x < TS_FONTW; x++) {
			wd = (pat & 0x80) ?  fg : bg;
			Display_wr_dat_if(wd);
			pat <<= 1;
		}
	}
#endif
}


/**************************************************************************/
/*! 
    Terminal Screen Cursor Hold.
*/
/**************************************************************************/
static void csr_hold(void)
{
	CsrFlag &= 0xFD;
	if (CsrFlag & 1) {
		CsrFlag &= 0xFE;
		ts_write(Row, Col, Vram[Row][Col]);
	}
}


/**************************************************************************/
/*! 
    Terminal Screen Cursor Release.
*/
/**************************************************************************/
static void csr_release(void)
{
	TmrCsr = 240;
	CsrFlag |= 0x02;
}


/**************************************************************************/
/*! 
    Terminal Screen Reflesh ALL.
*/
/**************************************************************************/
void ts_rfsh(
	uint8_t top,
	uint8_t left,
	uint8_t bottom,
	uint8_t right
)
{
	uint8_t x, y;


	csr_hold();

	for (y = top; y <= bottom; y++) {
		for (x = left; x <= right; x++)
			ts_write(y, x, Vram[y][x]);
	}

	csr_release();
}


/**************************************************************************/
/*! 
    Terminal Screen Rollup Row.
*/
/**************************************************************************/
void ts_rlup(
	uint8_t top,
	uint8_t left,
	uint8_t bottom,
	uint8_t right
)
{
	uint16_t c;
	uint8_t y, x;


	if (top > bottom || bottom >= TS_HEIGHT) return;
	if (left > right || right >= TS_WIDTH) return;

	for (y = top; y < bottom; y++) {
		for (x = left; x < right; x++) {
			c = Vram[y + 1][x];
			if (Vram[y][x] != c) {
				Vram[y][x] = c;
				ts_write(y, x, c);
			}
		}
	}
	c = ((uint16_t)Attr << 8) | 0x20;
	for (x = left; x < right; x++) {
		Vram[y][x] = c;
		ts_write(y, x, c);
	}
}


/**************************************************************************/
/*! 
    Terminal Screen Rolludown Row.
*/
/**************************************************************************/
void ts_rldown(
	uint8_t top,
	uint8_t left,
	uint8_t bottom,
	uint8_t right
)
{
	uint16_t c;
	uint8_t y, x;


	if (top > bottom || bottom >= TS_HEIGHT) return;
	if (left > right || right >= TS_WIDTH) return;

	for (y = bottom; y != top; y--) {
		for (x = left; x < right; x++) {
			c = Vram[y - 1][x];
			if (Vram[y][x] != c) {
				Vram[y][x] = c;
				ts_write(y, x, c);
			}
		}
	}
	c = ((uint16_t)Attr << 8) | 0x20;
	for (x = left; x < right; x++) {
		Vram[y][x] = c;
		ts_write(y, x, c);
	}
}


/**************************************************************************/
/*! 
    Terminal Screen Set Charactor location.
*/
/**************************************************************************/
void ts_locate(
	uint8_t row,
	uint8_t col,
	uint8_t csr
)
{
	csr_hold();

	if (row < TS_HEIGHT) Row = row;
	if (col < TS_WIDTH) Col = col;
	if (csr)
		CsrFlag |= 0x04;
	else
		CsrFlag &= 0xFB;

	csr_release();
}


/**************************************************************************/
/*! 
    Put a character into TTY screen
*/
/**************************************************************************/
void ts_putc(
	uint8_t chr
)
{
	int x, y;
	static char esc;


	csr_hold();

	if (esc) {
		if ((uint8_t)chr & 0x80) {
			Attr = chr & 0x77;
			esc = 0;
			csr_release();
			return;
		}
	}
	if (chr == '\33') {
		esc = 1;
		csr_release();
		return;
	}
	esc = 0;
#if !(USE_FILER_FONTX) || !(defined(USE_KANJIFONT))
	if ((uint8_t)chr & 0x80) {
		chr = 1;
	}
#endif
	if (chr == '\r') {
		Col = 0;
		csr_release();
		return;
	}
	if (chr == '\b') {
		if (Col) Col--;
		csr_release();
		return;
	}
	if (chr == '\n') {
		if (++Row >= TS_HEIGHT) {
			Row = TS_HEIGHT - 1;
			ts_rlup(0, 0, TS_WIDTH - 1, TS_HEIGHT - 1);
		}
		Col = 0;
		csr_release();
		return;
	}
	if (chr == '\f') {
		for (y = 0; y < TS_HEIGHT; y++) {
			for (x = 0; x < TS_WIDTH; x++) {
				Vram[y][x] = ((uint16_t)Attr << 8) | 0x20;
				ts_write(y, x, ((uint16_t)Attr << 8) | 0x20);
			}
		}
		Row = 0; Col = 0;
		csr_release();
		return;
	}

	Vram[Row][Col] = ((uint16_t)Attr << 8) | chr;
	ts_write(Row, Col, ((uint16_t)Attr << 8) | chr);

	if (++Col >= TS_WIDTH) {
		if (++Row >= TS_HEIGHT) {
			Row = TS_HEIGHT - 1;
			ts_rlup(0, 0, TS_WIDTH - 1, TS_HEIGHT - 1);
		}
		Col = 0;
	}

	csr_release();
}

/**************************************************************************/
/*! 
    MUST Execute 1mSec Every.
*/
/**************************************************************************/
void ts_timer(void)
{
	uint8_t f;
	uint16_t c;


	TmrFrm += 1000;

	f = CsrFlag;
	if (((f & 6) == 6) && ++TmrCsr >= 250) {
		TmrCsr = 0;
		f ^= 1;
		CsrFlag = f;
		c = Vram[Row][Col];
		if (f & 1) c ^= 0x7700;
		ts_write(Row, Col, c);
	}

}


/* End Of File ---------------------------------------------------------------*/
