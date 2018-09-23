#include <tetras.h>

BLOCK block [3] [13] [22];
LINES lines;
GRAPHIC it;
MOVEBLOCK blocks [3];
MOVEBLOCK nextblocks [3];

int main (int com1, char **com2)
{
	int dummy_a, dummy_b;
	int for_a, for_b;
	int key_a, key_b;
	int i, i2;
	int level [3];
	unsigned long points [3];
	int play_mode;

	text_systemline_hide (); //Master.lib pc98fkeyoff (); /* pc98 Hide function keys. */

	if (com1 >= 2)
	{
		switch ((int) com2 [1] [0])
		{
			case '0':break;
			case '1':break;
			case '2':break;
			case '3':break;
			case '4':break;
			case '5':break;
			case '6':break;
			case '7':break;
			case '8':break;
			case '9':break;
		}
	}

	//for ( ; ; )
	//{
	//cleardevice (); //BGI
	it.__txtclear ();
	it._active (0);
	it._visual (0);

	for (i = 0; i <= 2; i++)
	{
		level [i] = 0;
		points [i] = 0;
	}

	for (for_a = 0; for_a <= 21; for_a++)
	{
		for (for_b = 0; for_b <= 12; for_b++)
		{
			block [0] [for_b] [for_a]._attribute (0);
			block [0] [for_b] [for_a]._color (0);
			block [1] [for_b] [for_a]._attribute (0);
			block [1] [for_b] [for_a]._color (0);
			block [2] [for_b] [for_a]._attribute (0);
			block [2] [for_b] [for_a]._color (0);
		}
	}

	it._star (); //BGI Background
	//getch ();

	//it._copypage (0, 1); //表画面を裏にコピーして，裏を作業ページにする。
	it._copypage (1); //表画面を裏にコピーして，裏を作業ページにする。
	it._active (0);
	it._visual (0);
    //getch ();

	func1 (); /* TETRAS Logo */
    //getch ();

	gotoxy (31, 12);
	it._color (LIGHTBLUE);
	printf ("Ver.2.33+patch\n");
	it._color (WHITE);

	play_mode = menu1 ();
	gotoxy (31, 12);
	it._color (LIGHTBLUE);
	printf ("\n%d Player(s)\n", play_mode);
	it._color (WHITE);
    //getch ();

	it.__txtclear ();
	it._clear ();

	//it._copypage (1, 0); //裏画面を表にコピーして，表を作業ページにする。
	it._copypage (0); //裏画面を表にコピーして，表を作業ページにする。
	it._visual (0);       //表画面を表示ページにする。
	it._active (0);

	it.__box (59, 29, 219, 333, BLACK, BLACK);
	it.__box (59, 29, 219, 333, LIGHTBLUE);

	it._color (LIGHTBLUE);
	gotoxy (69, 1);
	printf ("TETRAS\n");
	gotoxy (69, 2);
	printf ("Copy-right\n");
	gotoxy (69, 3);
	printf ("Ruler-Soft\n");
    //getch ();
	it._color (WHITE);

	menu2 ();

	it.__txtclear (6);
	it.__txtclear (7);
	it.__txtclear (8);

	gotoxy (36, 6);
	printf ("Type: each player\n");
	gotoxy (36, 7);
	printf ("Which level? (1 to 9)\n");
	gotoxy (36, 8);

		do
		{
			//it._cursor (OFF);
			text_cursor_hide (); // master.lib _text_cursor_off (); //gr.lib
			it._key (&key_a, &key_b);
			if (key_a == ES)
			{
				it.__txtclear ();
				it._clear ();
				exit (0);
			}
		}
		while (key_a != TEN_1 && key_a != TEN_2 && key_a != TEN_3 &&
			key_a != TEN_4 && key_a != TEN_5 && key_a != TEN_6 &&
			key_a != TEN_7 && key_a != TEN_8 && key_a != TEN_9 &&
			key_a != KEY_1 && key_a != KEY_2 && key_a != KEY_3 &&
			key_a != KEY_4 && key_a != KEY_5 && key_a != KEY_6 &&
			key_a != KEY_7 && key_a != KEY_8 && key_a != KEY_9);

		switch (key_a)
		{
		case TEN_1:
		case KEY_1:
		level [0] = 1;
		break;

		case TEN_2:
		case KEY_2:
		level [0] = 2;
		break;

		case TEN_3:
		case KEY_3:
		level [0] = 3;
		break;

		case TEN_4:
		case KEY_4:
		level [0] = 4;
		break;

		case TEN_5:
		case KEY_5:
		level [0] = 5;
		break;

		case TEN_6:
		case KEY_6:
		level [0] = 6;
		break;

		case TEN_7:
		case KEY_7:
		level [0] = 7;
		break;

		case TEN_8:
		case KEY_8:
		level [0] = 8;
		break;

		case TEN_9:
		case KEY_9:
		level [0] = 9;
		break;
		}

		level [1] = level [0];
		level [2] = level [0];

		for (i2 = 0; i2 <= 2; i2++)
		{
			for (i = 1; i <= 12; i++){block [i2] [i] [21]._attribute (3);}
			for (i = 1; i <= 20; i++){block [i2] [1] [i]._attribute (3);}
			for (i = 1; i <= 20; i++){block [i2] [12] [i]._attribute (3);}
		}

	it._box (274, 77, 491, 129, BLACK, BLACK);
    //getch ();

	it.__txtclear (5);
	it.__txtclear (6);
	it.__txtclear (7);
    //getch ();

	if (play_mode != 3)
	{
		gotoxy (39, 10);
		printf ("NEXT\n");
	}

	//ここから先は、Master.libを使うこと

	if (play_mode != 3)
	{
		it.__box (304, 166, 374, 241, LIGHTBLUE);
		//it.__box (305, 167, 373, 240, LIGHTGREEN);
		it.__box (305, 167, 373, 240, LIGHTRED);
		it.__box (306, 168, 372, 239, BLACK, BLACK);
	}
    //getch ();

		switch (play_mode)
		{
		case 1:
		oneplay (level, points);
		break;

		case 2:
		it.__box (304, 246, 374, 321, LIGHTBLUE);
		//it.__box (305, 247, 373, 320, LIGHTGREEN);
		it.__box (305, 247, 373, 320, LIGHTRED); // Not BGI palette.
		it.__box (306, 248, 372, 319, BLACK, BLACK);
		twoplay (level, points);
		break;

		case 3:
		it.__txtclear (10);
		threeplay (level, points);
		break;
		}
	//} // No infinite loop.

	it._key (&dummy_a, &dummy_b);

	//Master.lib pc98fkeyon (); /* pc98 Enables function keys*/
	text_systemline_show ();
	//getch ();

	return 0;
}
//master.lib
//------------------------------------------------------------------------
//□ text_systemline_hide, vtext_systemline_hide -  画面最下行のシステムラ
//   インの消去
//
//C:      void text_systemline_hide(void);
//C:      void vtext_systemline_hide(void);
//
//        ------------------------------------------98N 98H AT DOS-
//        text_systemline_hide                              ＊ ○
//        ---------------------------------------------<txesc.asm>-
//        vtext_systemline_hide                      ×  × ○
//        ------------------------------------------<vtsyslin.asm>-
//
//                ● <98>ESCシーケンスを利用してファンクションキー
//                   表示を消します。
//                   <AT>日本語入力ドライバのために最下行を予約して
//                   ある場合、それを消して全画面が使えるようにしま
//                   す。
//
//                ★ <98>int  29h(高速コンソール出力)を使用していま
//                   す。
//
//------------------------------------------------------------------------
//□ text_systemline_show, vtext_systemline_show -  画面最下行のシステムラ
//   インの表示
//
//C:      void text_systemline_show(void);
//C:      void vtext_systemline_show(void);
//
//        ------------------------------------------98N 98H AT DOS-
//        text_systemline_show                              ＊ ○
//        ---------------------------------------------<txesc.asm>-
//        vtext_systemline_show                      ×  × ○
//        ------------------------------------------<vtsyslin.asm>-
//
//                ● <98>ESCシーケンスを利用してファンクションキー
//                   表示を行います。
//                   <AT>日本語入力ドライバのために最下行を予約でき
//                   る場合、割り当てます。
//
//                ★ <98>int  29h(高速コンソール出力)を使用していま
//                   す。

