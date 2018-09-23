#include <tetras.h>

void put (int a, int b, int color, int mode)
{
	extern GRAPHIC it;
	if (mode == 2)
	{
		a = a + 20;
	}

	if (mode == 3)
	{
		a = a + 10;
	}

//222222222222222
//211111111111113
//211111111111113
//211111111111113
//211111111111113
//211111111111113
//211111111111113
//211111111111113
//211111111111113
//211111111111113
//211111111111113
//211111111111113
//211111111111113
//211111111111113
//333333333333333

//for ( ; a < 0; ){}
//for ( ; a >= 35; ){}
//for ( ; b < 0; ){}
//for ( ; b >= 22; ){}

//   2        3        4          5          6          7          8          9          10         11         12         13         14         15         16         17         18         19         20
//[60, 74] [76, 90] [92, 106] [108, 122] [124, 138] [140, 154] [156, 170] [172, 186] [188, 202] [204, 218]
//[30, 44] [46, 60] [62, 76]  [78, 92]   [94, 108]  [110, 124] [126, 140] [142, 156] [158, 172] [174, 188] [190, 204] [206, 220] [222, 236] [238, 252] [254, 268] [270, 284] [286, 300] [302, 316] [318, 332]

	if (color == BLACK)
	{
		it.__box (a * 16 + 28, b * 16 - 2, a * 16 + 42, b * 16 + 12, BLACK, BLACK);
	}
	else
	{
		it.__line (a * 16 + 28, b * 16 - 2, a * 16 + 28, b * 16 + 11, WHITE);
		it.__line (a * 16 + 42, b * 16 - 1, a * 16 + 42, b * 16 + 12, BLACK);
		it.__line (a * 16 + 29, b * 16 - 2, a * 16 + 42, b * 16 - 2, WHITE);
		it.__line (a * 16 + 28, b * 16 + 12, a * 16 + 41, b * 16 + 12, BLACK);
		it.__box (a * 16 + 29, b * 16 - 1, a * 16 + 41, b * 16 + 11, color, color);
	}
}

// int ending_count (int level , int quickness); // Not dealing with an over clock.
unsigned long ending_count (int level, unsigned long quickness)
{
	unsigned long ENDCOUNT;

	switch (level)
	{
		case  1:ENDCOUNT = quickness * 1    + 1;  break;
		case  2:ENDCOUNT = quickness * 0.9  + 1;  break;
		case  3:ENDCOUNT = quickness * 0.82 + 1;  break;
		case  4:ENDCOUNT = quickness * 0.79 + 1;  break;
		case  5:ENDCOUNT = quickness * 0.7  + 1;  break;
		case  6:ENDCOUNT = quickness * 0.64 + 1; break;
		case  7:ENDCOUNT = quickness * 0.58 + 1; break;
		case  8:ENDCOUNT = quickness * 0.52 + 1; break;
		case  9:ENDCOUNT = quickness * 0.45 + 1; break;
		case 10:ENDCOUNT = quickness * 0.4  + 1; break;
		case 11:ENDCOUNT = quickness * 0.34 + 1; break;
		case 12:ENDCOUNT = quickness * 0.3  + 1; break;
		case 13:ENDCOUNT = quickness * 0.27 + 1; break;
		case 14:ENDCOUNT = quickness * 0.24 + 1; break;
		case 15:ENDCOUNT = quickness * 0.21 + 1; break;
		case 16:ENDCOUNT = quickness * 0.17 + 1; break;
		case 17:ENDCOUNT = quickness * 0.13 + 1; break;
		case 18:ENDCOUNT = quickness * 0.1  + 1; break;
		case 19:ENDCOUNT = quickness * 0.04 + 1; break;
		case 20:ENDCOUNT = quickness * 0.02 + 1; break;
		default:ENDCOUNT = quickness * 0.01 + 1; break;
		/*case  1:ENDCOUNT = quickness * 1.8 + 1;  break;
		case  2:ENDCOUNT = quickness * 1.5 + 1;  break;
		case  3:ENDCOUNT = quickness * 1.2 + 1;  break;
		case  4:ENDCOUNT = quickness * 0.9 + 1;  break;
		case  5:ENDCOUNT = quickness * 0.8 + 1;  break;
		case  6:ENDCOUNT = quickness * 0.77 + 1; break;
		case  7:ENDCOUNT = quickness * 0.69 + 1; break;
		case  8:ENDCOUNT = quickness * 0.61 + 1; break;
		case  9:ENDCOUNT = quickness * 0.53 + 1; break;
		case 10:ENDCOUNT = quickness * 0.45 + 1; break;
		case 11:ENDCOUNT = quickness * 0.37 + 1; break;
		case 12:ENDCOUNT = quickness * 0.29 + 1; break;
		case 13:ENDCOUNT = quickness * 0.22 + 1; break;
		case 14:ENDCOUNT = quickness * 0.17 + 1; break;
		case 15:ENDCOUNT = quickness * 0.15 + 1; break;
		case 16:ENDCOUNT = quickness * 0.14 + 1; break;
		case 17:ENDCOUNT = quickness * 0.12 + 1; break;
		case 18:ENDCOUNT = quickness * 0.08 + 1; break;
		case 19:ENDCOUNT = quickness * 0.04 + 1; break;
		case 20:ENDCOUNT = quickness * 0.02 + 1; break;
		default:ENDCOUNT = quickness * 0.01 + 1; break;*/
	}
	return ENDCOUNT;
}