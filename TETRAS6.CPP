#include <tetras.h>

extern GRAPHIC it;

int X (int a, int b)
{
	switch (a * 10 + b)
	{
		case 111:return 3;
	 	case 112:return 3;
	 	case 113:return 3;
		case 114:return 3;
		case 121:return 2;
		case 122:return 3;
		case 123:return 4;
		case 124:return 5;
		case 131:return 3;
		case 132:return 3;
		case 133:return 3;
		case 134:return 3;
		case 141:return 1;
		case 142:return 2;
		case 143:return 3;
		case 144:return 4;
		case 211:return 3;
		case 212:return 3;
		case 213:return 3;
		case 214:return 4;
		case 221:return 2;
		case 222:return 3;
		case 223:return 4;
		case 224:return 4;
		case 231:return 3;
		case 232:return 3;
		case 233:return 3;
		case 234:return 2;
		case 241:return 4;
		case 242:return 3;
		case 243:return 2;
		case 244:return 2;
		case 311:return 3;
		case 312:return 3;
		case 313:return 3;
		case 314:return 4;
		case 321:return 2;
		case 322:return 3;
		case 323:return 4;
		case 324:return 3;
		case 331:return 3;
		case 332:return 3;
		case 333:return 3;
		case 334:return 2;
		case 341:return 4;
		case 342:return 3;
		case 343:return 2;
		case 344:return 3;
		case 411:return 3;
		case 412:return 3;
		case 413:return 3;
		case 414:return 4;
		case 421:return 2;
		case 422:return 3;
		case 423:return 4;
		case 424:return 2;
		case 431:return 3;
		case 432:return 3;
		case 433:return 3;
		case 434:return 2;
		case 441:return 4;
		case 442:return 3;
		case 443:return 2;
		case 444:return 4;
		case 511:return 2;
		case 512:return 2;
		case 513:return 3;
		case 514:return 3;
		case 521:return 3;
		case 522:return 4;
		case 523:return 2;
		case 524:return 3;
		case 531:return 2;
		case 532:return 2;
		case 533:return 3;
		case 534:return 3;
		case 541:return 3;
		case 542:return 4;
		case 543:return 2;
		case 544:return 3;
		case 611:return 2;
		case 612:return 2;
		case 613:return 3;
		case 614:return 3;
		case 621:return 2;
		case 622:return 3;
		case 623:return 3;
		case 624:return 4;
		case 631:return 2;
		case 632:return 2;
		case 633:return 3;
		case 634:return 3;
		case 641:return 2;
		case 642:return 3;
		case 643:return 3;
		case 644:return 4;
		case 711:return 3;
		case 712:return 3;
		case 713:return 4;
		case 714:return 4;
		case 721:return 3;
		case 722:return 3;
		case 723:return 4;
		case 724:return 4;
		case 731:return 3;
		case 732:return 3;
		case 733:return 4;
		case 734:return 4;
		case 741:return 3;
		case 742:return 3;
		case 743:return 4;
		case 744:return 4;
	}
};

int Y (int a, int b)
{
	switch (a * 10 + b)
	{
		case 111:return 4;
		case 112:return 3;
		case 113:return 2;
		case 114:return 1;
		case 121:return 3;
		case 122:return 3;
		case 123:return 3;
		case 124:return 3;
		case 131:return 2;
		case 132:return 3;
		case 133:return 4;
		case 134:return 5;
		case 141:return 3;
		case 142:return 3;
		case 143:return 3;
		case 144:return 3;
		case 211:return 4;
		case 212:return 3;
		case 213:return 2;
		case 214:return 2;
		case 221:return 3;
		case 222:return 3;
		case 223:return 3;
		case 224:return 4;
		case 231:return 2;
		case 232:return 3;
		case 233:return 4;
		case 234:return 4;
		case 241:return 3;
		case 242:return 3;
		case 243:return 3;
		case 244:return 2;
		case 311:return 4;
		case 312:return 3;
		case 313:return 2;
		case 314:return 3;
		case 321:return 3;
		case 322:return 3;
		case 323:return 3;
		case 324:return 4;
		case 331:return 2;
		case 332:return 3;
		case 333:return 4;
		case 334:return 3;
		case 341:return 3;
		case 342:return 3;
		case 343:return 3;
		case 344:return 2;
		case 411:return 4;
		case 412:return 3;
		case 413:return 2;
		case 414:return 4;
		case 421:return 3;
		case 422:return 3;
		case 423:return 3;
		case 424:return 4;
		case 431:return 2;
		case 432:return 3;
		case 433:return 4;
		case 434:return 2;
		case 441:return 3;
		case 442:return 3;
		case 443:return 3;
		case 444:return 2;
		case 511:return 3;
		case 512:return 2;
		case 513:return 4;
		case 514:return 3;
		case 521:return 2;
		case 522:return 2;
		case 523:return 3;
		case 524:return 3;
		case 531:return 3;
		case 532:return 2;
		case 533:return 4;
		case 534:return 3;
		case 541:return 2;
		case 542:return 2;
		case 543:return 3;
		case 544:return 3;
		case 611:return 4;
		case 612:return 3;
		case 613:return 3;
		case 614:return 2;
		case 621:return 2;
		case 622:return 2;
		case 623:return 3;
		case 624:return 3;
		case 631:return 4;
		case 632:return 3;
		case 633:return 3;
		case 634:return 2;
		case 641:return 2;
		case 642:return 2;
		case 643:return 3;
		case 644:return 3;
		case 711:return 3;
		case 712:return 2;
		case 713:return 3;
		case 714:return 2;
		case 721:return 3;
		case 722:return 2;
		case 723:return 3;
		case 724:return 2;
		case 731:return 3;
		case 732:return 2;
		case 733:return 3;
		case 734:return 2;
		case 741:return 3;
		case 742:return 2;
		case 743:return 3;
		case 744:return 2;
	}
};

void turn (MOVEBLOCK *a, BLOCK block [13] [22], int mode)
{
	int b = (*a)._att () - 1;

	if (b - ((int) b / 10) * 10 == 0)
	{
		b = ((int) b / 10) * 10 + 4;
	}

	if (block [X (b, 1) + (*a)._x ()]
		[Y (b, 1) + (*a)._y ()]._attribute () != 1 &&
    	block [X (b, 1) + (*a)._x ()]
			[Y (b, 1) + (*a)._y ()]._attribute () != 3 &&
	    block [X (b, 2) + (*a)._x ()]
			[Y (b, 2) + (*a)._y ()]._attribute () != 1 &&
	    block [X (b, 2) + (*a)._x ()]
			[Y (b, 2) + (*a)._y ()]._attribute () != 3 &&
	    block [X (b, 3) + (*a)._x ()]
			[Y (b, 3) + (*a)._y ()]._attribute () != 1 &&
	    block [X (b, 3) + (*a)._x ()]
			[Y (b, 3) + (*a)._y ()]._attribute () != 3 &&
	    block [X (b, 4) + (*a)._x ()]
			[Y (b, 4) + (*a)._y ()]._attribute () != 1 &&
	    block [X (b, 4) + (*a)._x ()]
			[Y (b, 4) + (*a)._y ()]._attribute () != 3
	)
	{
		put (X ((*a)._att (), 1) + (*a)._x (),
			Y ((*a)._att (), 1) + (*a)._y (), BLACK, mode);
		put (X ((*a)._att (), 2) + (*a)._x (),
			Y ((*a)._att (), 2) + (*a)._y (), BLACK, mode);
		put (X ((*a)._att (), 3) + (*a)._x (),
			Y ((*a)._att (), 3) + (*a)._y (), BLACK, mode);
		put (X ((*a)._att (), 4) + (*a)._x (),
			Y ((*a)._att (), 4) + (*a)._y (), BLACK, mode);

		if (Y (b, 1) + (*a)._y () >= 2)
		{
			put (X (b, 1) + (*a)._x (),
				Y (b, 1) + (*a)._y (), (*a)._color (), mode);
		}
		if (Y (b, 2) + (*a)._y () >= 2)
		{
			put (X (b, 2) + (*a)._x (),
				Y (b, 2) + (*a)._y (), (*a)._color (), mode);
		}
		if (Y (b, 3) + (*a)._y () >= 2)
		{
			put (X (b, 3) + (*a)._x (),
				Y (b, 3) + (*a)._y (), (*a)._color (), mode);
		}
		if (Y (b, 4) + (*a)._y () >= 2)
		{
			put (X (b, 4) + (*a)._x (),
				Y (b, 4) + (*a)._y (), (*a)._color (), mode);
		}

		(*a)._att (b);
   }
}

int move (MOVEBLOCK *a, int x, int y, BLOCK block [13] [22], int mode)
{
	int errorlevel = 0;

	if (block [X ((*a)._att (), 1) + (*a)._x () + x]
		[Y ((*a)._att (), 1) + (*a)._y () + y]._attribute () != 1 &&
    	block [X ((*a)._att (), 1) + (*a)._x () + x]
			[Y ((*a)._att (), 1) + (*a)._y () + y]._attribute () != 3 &&
	    block [X ((*a)._att (), 2) + (*a)._x () + x]
			[Y ((*a)._att (), 2) + (*a)._y () + y]._attribute () != 1 &&
    	block [X ((*a)._att (), 2) + (*a)._x () + x]
			[Y ((*a)._att (), 2) + (*a)._y () + y]._attribute () != 3 &&
	    block [X ((*a)._att (), 3) + (*a)._x () + x]
			[Y ((*a)._att (), 3) + (*a)._y () + y]._attribute () != 1 &&
    	block [X ((*a)._att (), 3) + (*a)._x () + x]
			[Y ((*a)._att (), 3) + (*a)._y () + y]._attribute () != 3 &&
	    block [X ((*a)._att (), 4) + (*a)._x () + x]
			[Y ((*a)._att (), 4) + (*a)._y () + y]._attribute () != 1 &&
    	block [X ((*a)._att (), 4) + (*a)._x () + x]
			[Y ((*a)._att (), 4) + (*a)._y () + y]._attribute () != 3
	)
	{
		put (X ((*a)._att (), 1) + (*a)._x (),
			Y ((*a)._att (), 1) + (*a)._y (), BLACK, mode);
		put (X ((*a)._att (), 2) + (*a)._x (),
			Y ((*a)._att (), 2) + (*a)._y (), BLACK, mode);
		put (X ((*a)._att (), 3) + (*a)._x (),
			Y ((*a)._att (), 3) + (*a)._y (), BLACK, mode);
		put (X ((*a)._att (), 4) + (*a)._x (),
			Y ((*a)._att (), 4) + (*a)._y (), BLACK, mode);

		if (Y ((*a)._att (), 1) + (*a)._y () + y >= 2)
		{
			put (X ((*a)._att (), 1) + (*a)._x () + x,
				Y ((*a)._att (), 1) + (*a)._y () + y, (*a)._color (), mode);
		}
		if (Y ((*a)._att (), 2) + (*a)._y () + y >= 2)
		{
			put (X ((*a)._att (), 2) + (*a)._x () + x,
				Y ((*a)._att (), 2) + (*a)._y () + y, (*a)._color (), mode);
		}
		if (Y ((*a)._att (), 3) + (*a)._y () + y >= 2)
		{
			put (X ((*a)._att (), 3) + (*a)._x () + x,
				Y ((*a)._att (), 3) + (*a)._y () + y, (*a)._color (), mode);
		}
		if (Y ((*a)._att (), 4) + (*a)._y () + y >= 2)
		{
			put (X ((*a)._att (), 4) + (*a)._x () + x,
				Y ((*a)._att (), 4) + (*a)._y () + y, (*a)._color (), mode);
		}

		(*a)._x ((*a)._x () + x);
		(*a)._y ((*a)._y () + y);
		errorlevel = 1;
	}

	if (errorlevel == 0 && y == 1)//ブロックが動けない時＋下方向の移動の時
	{
		block [X ((*a)._att (), 1) + (*a)._x ()]
			[Y ((*a)._att (), 1) + (*a)._y ()]._attribute (1);
		block [X ((*a)._att (), 2) + (*a)._x ()]
			[Y ((*a)._att (), 2) + (*a)._y ()]._attribute (1);
		block [X ((*a)._att (), 3) + (*a)._x ()]
			[Y ((*a)._att (), 3) + (*a)._y ()]._attribute (1);
		block [X ((*a)._att (), 4) + (*a)._x ()]
			[Y ((*a)._att (), 4) + (*a)._y ()]._attribute (1);
		block [X ((*a)._att (), 1) + (*a)._x ()]
			[Y ((*a)._att (), 1) + (*a)._y ()]._color ((*a)._color ());
		block [X ((*a)._att (), 2) + (*a)._x ()]
			[Y ((*a)._att (), 2) + (*a)._y ()]._color ((*a)._color ());
		block [X ((*a)._att (), 3) + (*a)._x ()]
			[Y ((*a)._att (), 3) + (*a)._y ()]._color ((*a)._color ());
		block [X ((*a)._att (), 4) + (*a)._x ()]
			[Y ((*a)._att (), 4) + (*a)._y ()]._color ((*a)._color ());
		errorlevel = -1;
	}

	return errorlevel;
}

void erase (int a, int b [4], int mode, BLOCK block [13] [22])
{
	int c;
	int d;
	int e;
	int for_a;
	int key_a, key_b;//ダミー

	it._copypage (1); //表画面を裏にコピーして，裏を作業ページにする。
	//it._copypage (0, 1); //表画面を裏にコピーして，裏を作業ページにする。
	it._visual (1);       //裏画面を表示ページにする。
	it._active (0);       //表画面を作業ページにする。

	for (c = 0; c <= 3; c++)
	{
		for (d = 2; d <= 11; d++)
		{
			put (d, b [c], BLACK, mode);
		}
	}

	for (e = 0; e <= 6; e++)
	{
		delay (30);
		it._visual (0);       //表画面を表示ページにする。
		delay (30);
		it._visual (1);       //裏画面を表示ページにする。
	}

	switch (a)
	{
		case 1:
		for (for_a = b [0] - 1; for_a >= 1; for_a--)
		{
			for (d = 2; d <= 11; d++)
			{
				put (d, for_a + 1, block [d] [for_a]._color (), mode);
				block [d] [for_a + 1]._attribute (block [d]
					[for_a]._attribute ());
				block [d] [for_a + 1]._color (block [d]
					[for_a]._color ());
			}
		}
		for (d = 2; d <= 11; d++)
		{
			//put (d, 0, BLACK, mode);
			block [d] [1]._attribute (0);
			block [d] [1]._color (0);
		}
		break;

		case 2:
		for (for_a = b [1] - 1; for_a >= b [0] + 1; for_a--)
		{
			for (d = 2; d <= 11; d++)
			{
				put (d, for_a + 1, block [d] [for_a]._color (), mode);
				block [d] [for_a + 1]._attribute (block [d]
					[for_a]._attribute ());
				block [d] [for_a + 1]._color (block [d]
					[for_a]._color ());
			}
		}
		for (for_a = b [0] - 1; for_a >= 0; for_a--)
		{
			for (d = 2; d <= 11; d++)
			{
				put (d, for_a + 2, block [d]
					[for_a]._color (), mode);
				block [d] [for_a + 2]._attribute (block [d]
					[for_a]._attribute ());
				block [d] [for_a + 2]._color (block [d]
					[for_a]._color ());
			}
		}
		for (for_a = 0; for_a <= 1; for_a++)
		{
			for (d = 2; d <= 11; d++)
			{
				put (d, for_a, BLACK, mode);
				block [d] [for_a]._attribute (0);
				block [d] [for_a]._color (0);
			}
		}
		break;

		case 3:
		if (b [2] - b [0] == 3)
		{
			if (b [2] - b [1] == 2)
			{
				for (for_a = b [2] - 1; for_a >= b [1] + 1; for_a--)
				{
					for (d = 2; d <= 11; d++)
						{
							put (d, for_a + 1, block [d]
								[for_a]._color (), mode);
							block [d] [for_a + 1]._attribute (block [d]
								[for_a]._attribute ());
							block [d] [for_a + 1]._color (block [d]
								[for_a]._color ());
						}
					}
				}
			else
			{
				for (for_a = b [1] - 1; for_a >= b [0] + 1; for_a--)
				{
					for (d = 2; d <= 11; d++)
					{
						put (d, for_a + 2, block [d]
							[for_a]._color (), mode);
						block [d] [for_a + 2]._attribute (block [d]
							[for_a]._attribute ());
						block [d] [for_a + 2]._color (block [d]
							[for_a]._color ());
					}
				}
			}
		}
		for (for_a = b [0] - 1; for_a >= 0; for_a--)
		{
			for (d = 2; d <= 11; d++)
			{
				put (d, for_a + 3, block [d]
					[for_a]._color (), mode);
				block [d] [for_a + 3]._attribute (block [d]
					[for_a]._attribute ());
				block [d] [for_a + 3]._color (block [d]
					[for_a]._color ());
				}
			}
			for (for_a = 0; for_a <= 2; for_a++)
			{
				for (d = 2; d <= 11; d++)
				{
					put (d, for_a, BLACK, mode);
					block [d] [for_a]._attribute (0);
					block [d] [for_a]._color (0);
				}
			}
		break;

		case 4:
		for (for_a = b [0] - 1; for_a >= 0; for_a--)
		{
			for (d = 2; d <= 11; d++)
			{
				put (d, for_a + 4, block [d]
					[for_a]._color (), mode);
				block [d] [for_a + 4]._attribute (block [d]
					[for_a]._attribute ());
				block [d] [for_a + 4]._color (block [d]
					[for_a]._color ());
			}
		}
		for (for_a = 0; for_a <= 3; for_a++)
		{
			for (d = 2; d <= 11; d++)
			{
				put (d, for_a, BLACK, mode);
				block [d] [for_a]._attribute (0);
				block [d] [for_a]._color (0);
			}
		}
		break;
	}

	it._visual (0);       //表画面を表示ページにする。
	it._keyclear ();
}

void kougeki (int damaged, int damaged_lines, int tetris_ana, BLOCK block [13] [22])
{
	//damagedは，攻撃を食らった側 1-左 2-右
	int for_a;
	int d;

	if (damaged_lines >= 20)
	{
		damaged_lines = 20;
	}

	for (for_a = 0; for_a <= 20 - damaged_lines; for_a++)
	{
		for (d = 2; d <= 11; d++)
		{
			block [d] [for_a]._attribute (block [d]
				[for_a + damaged_lines]._attribute ());
			block [d] [for_a]._color (block [d]
				[for_a + damaged_lines]._color ());
		}
	}

	for (for_a = 20; for_a > 20 - damaged_lines; for_a--)
	{
		for (d = 2; d <= 11; d++)
		{
			if (d != tetris_ana)
			{
				block [d] [for_a]._attribute (1);
				block [d] [for_a]._color (LIGHTGRAY);
			}
			else
			{
				block [d] [for_a]._attribute (0);
				block [d] [for_a]._color (BLACK);
			}
		}
	}

	//it._copypage (0, 1); //表画面を裏にコピーして，裏を作業ページにする。
	it._copypage (1); //表画面を裏にコピーして，裏を作業ページにする。
	it._active (0);       //表画面を作業ページにする。

	for (for_a = 21; for_a >= 2; for_a--)
	{
		for (d = 2; d <= 11; d++)
		{
			put (d, for_a, block [d] [for_a]._color (), damaged);
		}
	}
	it._visual (0);       //表画面を表示ページにする。
}

void death (int a)
{
	int i;
	int x;

	switch (a)
	{
		case 0:
		x = 2;
		break;

		case 1:
		x = 22;
		break;

		case 2:
		x = 12;
		break;
	}

	for (i = 2; i <= 20; i++)
	{
		put (x, i, YELLOW, 1);
		put (x + 1, i, LIGHTGRAY, 1);
		put (x + 2, i, LIGHTBLUE, 1);
		put (x + 3, i, LIGHTGREEN, 1);
		put (x + 4, i, LIGHTCYAN, 1);
		put (x + 5, i, LIGHTRED, 1);
		put (x + 6, i, LIGHTMAGENTA, 1);
		put (x + 7, i, YELLOW, 1);
		put (x + 8, i, LIGHTGRAY, 1);
		put (x + 9, i, LIGHTBLUE, 1);
	}
}