#ifndef __TETRAS_H
#define __TETRAS_H

#include <alloc.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <masterm.h> //1MB memory for code, 64KB for data
#include <pc98.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*const maxx = 639;
const maxy = 399;

const ON  = 1;
const OFF = 0;*/

inline int rotate (a, b)
{
return (a >> (b - 1)) - (a >> b) * 2;
}

class BLOCK
{
	int color;
	int attribute;
	//0の時は、何もブロックがないとき、
	//1の時は、固定ブロックがあるとき、
	//2の時は、移動ブロックがあるとき、
	//3の時は、特殊ブロックがあるとき。
	public:
	int _color (void);
	int _attribute (void);
	void _color (int);
	void _attribute (int);
	BLOCK (void);
};

class LINES
{
	public:
	int howmany (int, BLOCK block [13] [22]);
};

class MOVEBLOCK
{
	int x;
	int y;
	int attribute;
	int color;
	public:
	void _att (int);
	void _x (int);
	void _y (int);
	void _color (int);
	int _att (void);
	int _x (void);
	int _y (void);
	int _color (void);
};

class GRAPHIC
{
	palettetype first_pal; //for BGI to switch to master.lib.
	palettetype pal; //for BGI to switch to master.lib.
	public:
	GRAPHIC (void);
	~GRAPHIC ();
	void _switch (char *);
	void _circle (int, int, int, int, int, int, int);
	void _line (int, int, int, int, int);
	void _box (int, int, int, int, int);
	void _box (int, int, int, int, int, int); // Coating.
	void _paint (int, int, int, int);
	void _clear (void);
	void _color (int); // Colour of texts.

	void _key (int *, int *);
	void _keyclear (void);
	//void _key (unsigned key [120]); // Not dealing with an over clock.
	void _key (unsigned key [120]);
	void _keyclear (unsigned key [120]); // Not dealing witha an over clock.
	void _keyclear (unsigned long lastkey [120]);
	void _quick_key (int *, int *);
	void _star (void);

	// "__"は、master.libを使用するということ。
	void __line (int, int, int, int, int);
	void __box (int, int, int, int, int);
	void __box (int, int, int, int, int, int); // Coating.
	void __paint (int, int, int, int);
	void __txtclear (void);
	void __txtclear (int);

	void _copypage (int);
	void _active (int);
	void _visual (int);
};

const ESC = '\033';
const TRUE = 0;
const FALSE = -1;

/*英字キー*/
const KEY_A = 29;
const KEY_B = 45;
const KEY_C = 43;
const KEY_D = 31;
const KEY_E = 18;
const KEY_F = 32;
const KEY_G = 33;
const KEY_H = 34;
const KEY_I = 23;
const KEY_J = 35;
const KEY_K = 36;
const KEY_L = 37;
const KEY_M = 47;
const KEY_N = 46;
const KEY_O = 24;
const KEY_P = 25;
const KEY_Q = 16;
const KEY_R = 19;
const KEY_S = 30;
const KEY_T = 20;
const KEY_U = 22;
const KEY_V = 44;
const KEY_W = 17;
const KEY_X = 42;
const KEY_Y = 21;
const KEY_Z = 41;

/*テンキー*/
const TEN_0 = 78;
const TEN_1 = 74;
const TEN_2 = 75;
const TEN_3 = 76;
const TEN_4 = 70;
const TEN_5 = 71;
const TEN_6 = 72;
const TEN_7 = 66;
const TEN_8 = 67;
const TEN_9 = 68;
const TEN_SE = 64;
const TEN_SR = 65;
const TEN_KA = 69;
const TEN_PL = 73;
const TEN_I = 77;
const TEN_KO = 79;
const TEN_PI = 80;

/*ファンクションキー*/
const F1 = 98;
const F2 = 99;
const F3 = 100;
const F4 = 101;
const F5 = 102;
const F6 = 103;
const F7 = 104;
const F8 = 105;
const F9 = 106;
const F10 = 107;
const VF1 = 82;
const VF2 = 83;
const VF3 = 84;
const VF4 = 85;
const VF5 = 86;

/*特殊キー*/
const INS = 56;
const DEL = 57;
const UP = 54;
const DOWN = 55;
const HOME = 62;
const HELP = 63;
const CR = 28;
const SPACE = 52;
const XFER = 53;
const NFER = 81;
const TAB = 15;
const ES = 0;
const BS = 14;

const STOP = 96;
const COPY = 97;
const SHIFT = 112;
const CAPS = 113;
const KANA = 114;
const GRPH = 115;
const CTRL = 116;

/*矢印キー*/
const UE = 58;
const SITA = 61;
const HIDARI = 59;
const MIGI = 60;

/*その他*/
const KEY_1 = 1;
const KEY_2 = 2;
const KEY_3 = 3;
const KEY_4 = 4;
const KEY_5 = 5;
const KEY_6 = 6;
const KEY_7 = 7;
const KEY_8 = 8;
const KEY_9 = 9;
const KEY_0 = 10;
const BOU = 11;
const YAMA = 12;
const YEN = 13;
const ATTO = 26;
const HIDARIKAKU = 27;
const SEMI_C = 38;
const COLON = 39;
const MIGIKAKU = 40;
const TOUTEN = 48;
const KUTEN = 49;
const SLASH = 50;
const NASI = 51;

void func1 (void);
int menu1 (void);
int menu2 (void);
void oneplay (int *, unsigned long *);
void twoplay (int *, unsigned long *);
void threeplay (int *, unsigned long *);
void put (int a, int b, int color, int mode);
void turn (MOVEBLOCK * BLOCK, BLOCK block [13] [22], int mode);
int move (MOVEBLOCK *, int, int, BLOCK block [13] [22], int mode);
void erase (int, int b [4], int, BLOCK block [13] [22]);
int X (int, int);
int Y (int, int);
// int ending_count (int, int); // Not dealing with an over clock.
unsigned long ending_count (int, unsigned long);
void kougeki (int damaged, int damaged_lines, int tetris_ana, BLOCK block [13] [22]);
void death (int);
#endif
