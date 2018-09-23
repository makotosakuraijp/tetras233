#include <tetras.h>

void twoplay (int *level, unsigned long *points)
{
	extern BLOCK block [3] [13] [22];
	extern LINES lines;
	extern GRAPHIC it;
	extern MOVEBLOCK blocks [3];
	extern MOVEBLOCK nextblocks [3];

	int for_a;
	int i, i2;
	// int count [2] = {1, 1};  //Not dealing with an over clock.
	long count [2] = {1, 1};
	int key_a, key_b;
	time_t t1;

	int reservation [750];
	//int quickness; // Not dealing with an over clock.
	unsigned long quickness;
	int reser_pointer [2] = {0, 0};
	int erased_lines [2] = {0, 0};
	// int ENDCOUNT [2]; // Not dealing with an over clock.
	unsigned long ENDCOUNT [2];
	int quit = 0;
	int next = 0;
	int erase_lines = 0;
	int erasing_line [4];
	int tmp_int = 0;
	int tetris_hole [2];
	int damaged [2] = {0, 0};
	int damaged_lines [2] = {0, 0};
	// unsigned lastkey [120]; //Not dealing with an over clock.
	unsigned long lastkey [120];
	unsigned key [120];
	// int WAIT = 0;  // Not dealing with an over clock.
	int first = 0;

	// int wait_letters = 0;  // Not dealing with an over clock.
	// int wait_tmp = 0;  // Not dealing with an over clock.
	long wait_letters = 0, wait_tmp = 0, WAIT = 0;

	for (i = 0; i <= 1; i++)
	{
		tetris_hole [i] = 2 + random (10);
		ENDCOUNT [i] = ending_count (*(level + i), quickness);
		count [i] = ENDCOUNT [i];
	}

	for (i = 0; i <= 3; i++)
	{
		erasing_line [i] = -1;
	}
	
	it._keyclear (lastkey);
	it._keyclear (key);

	it.__box (379, 29, 539, 333, BLACK, BLACK);
	it.__box (379, 29, 539, 333, LIGHTBLUE); 

	for (for_a = 0; for_a <= 749; for_a++)
	{
		reservation [for_a] = random (7) * 10 + 11;
	}

	for (i = 0; i <= 1; i++)
	{
		nextblocks [i]._att (reservation [reser_pointer [i] - (((int) (reser_pointer [i] / 750)) * 750)]);
		nextblocks [i]._x (4);
		nextblocks [i]._y (-1);
		nextblocks [i]._color (nextblocks [i]._att ());
		reser_pointer [i]++;
	}

	t1 = time(NULL);
	//for (quickness = 1; difftime(time(NULL), t1) <= 5; quickness++){it._quick_key (&key_a, &key_b);}
	// Changed to be more speedy.
	for (quickness = 1; difftime(time(NULL), t1) <= 2; quickness++){it._quick_key (&key_a, &key_b);}
	//WAIT = 60;
	// WAIT = ((int) (quickness / 22)) + 4; // Not dealing with an over clock.
	WAIT = ((long) (quickness / 22)) + 4;

	randomize();

	for ( ; quit == 0; )
	{
		if (first != 0)
		{
			for (i = 0; i <= 1; i++)
			{
				ENDCOUNT [i] = ending_count (*(level + i), quickness);
			}
		}
		else
		{
			first = 1;
		}

		for (i = 0; i <= 3; i++)
		{
			erasing_line [i] = -1;
		}

		erase_lines = 0;
		tmp_int = 0;

		gotoxy (29, 6);
		printf ("Lines %d versus %d", erased_lines [0], erased_lines [1]);
		gotoxy (29, 7);
		printf ("Level %d versus %d", *level, *(level + 1));
		gotoxy (29, 8);
		printf ("Point %ld versus %ld", *points, *(points + 1));

		for (i = 0; i <= 1; i++)
		{
			if (count [i] >= ENDCOUNT [i] && damaged_lines [i] > 0 && damaged [i] == 1)
			{
				kougeki (i + 1, damaged_lines [i], tetris_hole [i], block [i]);
				damaged_lines [i] = 0;
				damaged [i] = 0;
			}
		}

		for (i = 1; i <= 4; i++)
		{
			put (X (nextblocks [0]._att (), i) + 16,
				Y (nextblocks [0]._att (), i) + 10, BLACK, 1);
			put (X (nextblocks [1]._att (), i) + 16,
				Y (nextblocks [1]._att (), i) + 15, BLACK, 1);
		}

		for (i = 0; i <= 1; i++)
		{
			if (count [i] >= ENDCOUNT [i])
			{
				blocks [i]._att (nextblocks [i]._att());
				blocks [i]._x (4);
				blocks [i]._y (-1);
				blocks [i]._color (blocks [i]._att ());
				nextblocks [i]._att (reservation [reser_pointer [i]
					- (((int) (reser_pointer [i] / 750)) * 750)]);
				nextblocks [i]._x (4);
				nextblocks [i]._y (-1);
				nextblocks [i]._color (nextblocks [i]._att ());
				reser_pointer [i]++;
			}
		}

		for (i = 0; i <= 1; i++)
		{
			ENDCOUNT [i] = ending_count (*(level + i), quickness);
		}

		if (next == 0)
		{
			for (i = 1; i <= 4; i++)
			{
				put (X (nextblocks [0]._att (), i) + 16,
					Y (nextblocks [0]._att (), i) + 10,
					nextblocks [0]._color (), 1);
				put (X (nextblocks [1]._att (), i) + 16,
					Y (nextblocks [1]._att (), i) + 15,
					nextblocks [1]._color (), 1);
			}
		}

		for (i = 0; i <= 1; i++)
		{
			for (i2 = 1; i2 <= 4; i2++)
			{
				if (Y (blocks [i]._att (), i2) + blocks [i]._y () >= 2)
				{
					put (X (blocks [i]._att (), i2) + blocks [i]._x (),
						Y (blocks [i]._att (), i2) + blocks [i]._y (),
						blocks [i]._color (), i + 1);
				}
			}
		}

		if (
			block [0] [X (blocks [0]._att (), 1) + blocks [0]._x ()]
				[Y (blocks [0]._att (), 1) + blocks [0]._y ()]._attribute ()
				== 0 &&
			block [0] [X (blocks [0]._att (), 2) + blocks [0]._x ()]
				[Y (blocks [0]._att (), 2) + blocks [0]._y ()]._attribute ()
				== 0 &&
			block [0] [X (blocks [0]._att (), 3) + blocks [0]._x ()]
				[Y (blocks [0]._att (), 3) + blocks [0]._y ()]._attribute ()
				== 0 &&
			block [0] [X (blocks [0]._att (), 4) + blocks [0]._x ()]
				[Y (blocks [0]._att (), 4) + blocks [0]._y ()]._attribute ()
				== 0 &&
			block [1] [X (blocks [1]._att (), 1) + blocks [1]._x ()]
				[Y (blocks [1]._att (), 1) + blocks [1]._y ()]._attribute ()
				== 0 &&
			block [1] [X (blocks [1]._att (), 2) + blocks [1]._x ()]
				[Y (blocks [1]._att (), 2) + blocks [1]._y ()]._attribute ()
				== 0 &&
			block [1] [X (blocks [1]._att (), 3) + blocks [1]._x ()]
				[Y (blocks [1]._att (), 3) + blocks [1]._y ()]._attribute ()
				== 0 &&
			block [1] [X (blocks [1]._att (), 4) + blocks [1]._x ()]
				[Y (blocks [1]._att (), 4) + blocks [1]._y ()]._attribute ()
				== 0
		)
		{
			for (i = 0; i <= 1; i++)
			{
				if (count [i] >= ENDCOUNT [i])
				{
					count [i] = 1;
				}
			}

			for (; count [0] <= ENDCOUNT [0] && count [1] <= ENDCOUNT [1]; )
			{
				it._key (key);
				//it._cursor (OFF);
				text_cursor_hide (); // master.lib _text_cursor_off (); //gr.lib

				// Changing the key wait.
				if (key [KEY_1] == 1 && lastkey [KEY_1] == 0)
				{
					it._active (1);
					//setactivepage (1); //BGI
					//grVPage (1);//裏画面を表示ページにする。
					it._visual (1);
					//setvisualpage (1); //BGI
					//grAPage (1);//裏画面を作業ページにする
					it.__txtclear ();
					it._clear ();

					gotoxy (1, 1);
					printf ("Your PC speed index is %ld.\n", quickness);
					printf ("Type your key wait index within 4 digits.");
					printf ("(Ref. value:%ld)\n", (long) (quickness / 20) + 4);
					gotoxy (wait_letters + 1, 3);
					//it._cursor (ON);
					text_cursor_show ();
					// master.lib _text_cursor_on (); //gr.lib

					while (key_a != CR || wait_letters > 4)
					{
						it._key (&key_a, &key_b);

						if (key_a == KEY_0 || key_a == KEY_1 || key_a == KEY_2
						||	key_a == KEY_3 || key_a == KEY_4 || key_a == KEY_5
						||	key_a == KEY_6 || key_a == KEY_7 || key_a == KEY_8
						||	key_a == KEY_9 ||
							key_a == TEN_0 || key_a == TEN_1 || key_a == TEN_2
						||	key_a == TEN_3 || key_a == TEN_4 || key_a == TEN_5
						||	key_a == TEN_6 || key_a == TEN_7 || key_a == TEN_8
						||	key_a == TEN_9 || key_a == BS    || key_a == CR)
						{
							switch (key_a)
							{
								case CR:
								break;

								case TEN_0:
								case KEY_0:
								if (wait_letters < 4 && wait_tmp != 0)
								{
									wait_letters++;
									wait_tmp = wait_tmp * 10;
								}
								break;

								case TEN_1:
								case KEY_1:
								if (wait_letters < 4)
								{
									wait_letters++;
									wait_tmp = wait_tmp * 10 + 1;
								}
								break;

								case TEN_2:
								case KEY_2:
								if (wait_letters < 4)
								{
									wait_letters++;
									wait_tmp = wait_tmp * 10 + 2;
								}
								break;

								case TEN_3:
								case KEY_3:
								if (wait_letters < 4)
								{
									wait_letters++;
									wait_tmp = wait_tmp * 10 + 3;
								}
								break;

								case TEN_4:
								case KEY_4:
								if (wait_letters < 4)
								{
									wait_letters++;
									wait_tmp = wait_tmp * 10 + 4;
								}
								break;

								case TEN_5:
								case KEY_5:
								if (wait_letters < 4)
								{
									wait_letters++;
									wait_tmp = wait_tmp * 10 + 5;
								}
								break;

								case TEN_6:
								case KEY_6:
								if (wait_letters < 4)
								{
									wait_letters++;
									wait_tmp = wait_tmp * 10 + 6;
								}
								break;

								case TEN_7:
								case KEY_7:
								if (wait_letters < 4)
								{
									wait_letters++;
									wait_tmp = wait_tmp * 10 + 7;
								}
								break;

								case TEN_8:
								case KEY_8:
								if (wait_letters < 4)
								{
									wait_letters++;
									wait_tmp = wait_tmp * 10 + 8;
								}
								break;

								case TEN_9:
								case KEY_9:
								if (wait_letters < 4)
								{
									wait_letters++;
									wait_tmp = wait_tmp * 10 + 9;
								}
								break;

								case BS:
								if (wait_letters > 0)
								{
									wait_letters--;
									// wait_tmp = (int) (wait_tmp / 10);
									// Not dealing with an over clock.
									wait_tmp = (long) (wait_tmp / 10);
								}
								break;
							}

							it.__txtclear (3);

							gotoxy (1, 3);
							printf ("%d ", wait_tmp);
							gotoxy (wait_letters + 1, 3);
							//it._cursor (ON);
							text_cursor_show ();
							// master.lib _text_cursor_on (); //gr.lib
						}
					}

					it._active (1);
					//setactivepage (1); //BGI
					//grVPage (0);//表画面を表示ページにする。
					it._visual (1);
					//setvisualpage (1); //BGI
					//grAPage (0);//表画面を作業ページにする。
					it.__txtclear ();//テキスト画面を消す。

					it._color (LIGHTBLUE);
					gotoxy (69, 1);
					printf ("TETRAS");
					gotoxy (69, 2);
					printf ("Copy-right");
					gotoxy (69, 3);
					printf ("Ruler-soft");
					it._color (WHITE);
					gotoxy (39, 10);
					printf ("Next");
					gotoxy (29, 6);
					printf ("Lines %d versus %d",
						erased_lines [0], erased_lines [1]);
					gotoxy (29, 7);
					printf ("Level %d versus %d", *level, *(level + 1));
					gotoxy (29, 8);
					printf ("Point %ld vs %ld", *points, *(points + 1));

					WAIT = wait_tmp;
					key_a = 0;
					wait_tmp = 0;
					wait_letters = 0;
					//it._cursor (OFF);
					text_cursor_hide ();
					// master.lib _text_cursor_off (); //gr.lib
					lastkey [KEY_1] = WAIT;
				}// The key wait was changed

				// Pause
				if (key [F1] == 1 && lastkey [F1] == 0)
				{
					gotoxy (29, 5);
					it._color (RED);
					printf ("Pause");
					it._key (&key_a, &key_b);
					for ( ; key_a != F1; )
					{
						//it._cursor (OFF);
						text_cursor_hide ();
						// master.lib _text_cursor_off (); //gr.lib
						it._key (&key_a, &key_b);
					}
					gotoxy (29, 5);
					it._color (BLACK);
					printf ("Pause");
					it._color (WHITE);
					lastkey [F1] = WAIT;
				}

				// Right-1
				if (key [COLON] == 1 || key [KEY_D] == 1)
				{
					if (lastkey [COLON] == 0 && lastkey [KEY_D] == 0)
					{
						move (blocks, 1, 0, block [0], 1);
						it._keyclear ();
						lastkey [COLON] = WAIT;
						lastkey [KEY_D] = WAIT;
					}
				}

				// Right-2
				if (key [TEN_6] == 1 || key [MIGI] == 1)
				{
					if (lastkey [TEN_6] == 0 && lastkey [MIGI] == 0)
					{
						move (blocks + 1, 1, 0, block [1], 2);
						it._keyclear ();
						lastkey [TEN_6] = WAIT;
						lastkey [MIGI] = WAIT;
					}
				}

				// Left-1
				if (key [KEY_L] == 1 || key [KEY_A] == 1)
				{
					if (lastkey [KEY_L] == 0 && lastkey [KEY_A] == 0)
					{
						move (blocks, -1, 0, block [0], 1);
						it._keyclear ();
						lastkey [KEY_L] = WAIT;
						lastkey [KEY_A] = WAIT;
					}
				}

				// Left-2
				if (key [TEN_4] == 1 || key [HIDARI] == 1)
				{
					if (lastkey [TEN_4] == 0 && lastkey [HIDARI] == 0)
					{
						move (blocks + 1, -1, 0, block [1], 2);
						it._keyclear ();
						lastkey [TEN_4] = WAIT;
						lastkey [HIDARI] = WAIT;
					}
				}

				// Down-1
				if (key [SLASH] == 1 || key [KEY_X] == 1)
				{
					if (lastkey [SLASH] == 0 && lastkey [KEY_X] == 0)
					{
						*points = *points + *level;
						if (move (blocks, 0, 1, block [0], 1) == -1)
						{
							count [0] = ENDCOUNT [0] * 2;
						}
						else
						{
							count [0] = 0;
						}
						it._keyclear ();
						if (key [CTRL] == 0 && key [SPACE] == 0)
						{
							// Dealing with an over clock.
							lastkey [SLASH] = (long) (WAIT / 2);
							lastkey [KEY_X] = (long) (WAIT / 2);
						}
						else
						{
							lastkey [SLASH] = WAIT * 2;
							lastkey [KEY_X] = WAIT * 2;
						}
					}
				}

				// Down-2
				if (key [TEN_2] == 1 || key [SITA] == 1)
				{
					if (lastkey [TEN_2] == 0 && lastkey [SITA] == 0)
					{
						*(points + 1) = *(points + 1) + *(level + 1);
						if (move (blocks + 1, 0, 1, block [1], 2) == -1)
						{
							count [1] = ENDCOUNT [1] * 2;
						}
						else
						{
							count [1] = 0;
						}
						it._keyclear ();
						if (key [SHIFT] == 0)
						{
							// Dealing with an over clock.
							lastkey [TEN_2] = (long) (WAIT / 2);
							lastkey [SITA] = (long) (WAIT / 2);
						}
						else
						{
							lastkey [TEN_2] = WAIT * 2;
							lastkey [SITA] = WAIT * 2;
						}
					}
				}
			
				// Rotation-1
				if (key [SEMI_C] == 1 || key [KEY_S] == 1)
				{
					if (lastkey [SEMI_C] == 0 && lastkey [KEY_S] == 0)
					{
						turn (blocks, block [0], 1);
						it._keyclear ();
						lastkey [SEMI_C] = WAIT * 2;
						lastkey [KEY_S] = WAIT * 2;
					}
				}

				// Rotation-2
				if (key [TEN_5] == 1 || key [CR] == 1)
				{
					if (lastkey [TEN_5] == 0 && lastkey [CR] == 0)
					{
						turn (blocks + 1, block [1], 2);
						it._keyclear ();
						lastkey [TEN_5] = WAIT * 2;
						lastkey [CR] = WAIT * 2;
					}
				}
			
				// Termination.
				if (key [BS] == 1)
				{
					count [0] = ENDCOUNT [0] * 3;
					count [1] = ENDCOUNT [1] * 3;
					quit = 1; // Exiting the game.
				}
			
				// Displaying Next
				if (key [HOME] == 1)
				{
					if (lastkey [HOME] == 0)
					{
						if (next == 0)
						{
							for (i = 1; i <= 4; i++)
							{
								put (X (nextblocks [0]._att (), i) + 16,
									Y (nextblocks [0]._att (), i) + 10,
									BLACK, 1);
								put (X (nextblocks [1]._att (), i) + 16,
									Y (nextblocks [1]._att (), i) + 15,
									BLACK, 1);
						}
						next = 1;
						}
						else
						{
							for (i = 0; i <= 4; i++)
							{
								put (X (nextblocks [0]._att (), i) + 16,
									Y (nextblocks [0]._att (), i) + 10,
									nextblocks [0]._color (), 1);
								put (X (nextblocks [1]._att (), i) + 16,
									Y (nextblocks [1]._att (), i) + 15,
									nextblocks [1]._color (), 1);
							}
						next = 0;
						}
					lastkey [HOME] = WAIT;
					}
				}
	
				for (for_a = 0; for_a <= 119; for_a++)
				{
					if (lastkey [for_a] != 0)
					{
						lastkey [for_a]--;
				     }
				}

				it._keyclear (key);

				for (i = 0; i <= 1; i++)
				{
					if (count [i] == ENDCOUNT [i] - 1)
					{
						if (move (&(blocks [i]), 0, 1, block [i], i + 1) == -1)
						{
							count [i] =  ENDCOUNT [i] * 2;
						}
						else
						{
							count [i] = 0;
						}
					}
				}
				count [0]++;
				count [1]++;
			} // Finishing the NEXT Display.

			for (i = 0; i <= 1; i++)
			{
				for (for_a = 0; for_a <= 20; for_a++)
				{
					if (lines.howmany (for_a, *(block + i)) == 10)
					{
						erase_lines++;
					}
				}
				
				if (erase_lines != 0)
				{
					for (for_a = 0; for_a <= 20; for_a++)
					{
						if (lines.howmany (for_a, *(block + i)) == 10)
						{
							erasing_line [tmp_int] = for_a;
							tmp_int++;
						}
					}
					erase (erase_lines, erasing_line, i + 1, *(block + i));
					points [i] += erase_lines * (int) ((level [i] / 3) + 1);
					erased_lines [i] += erase_lines;
			
					if (erased_lines [i] >= level [i] * 10)
					{
						(*(level + i))++;
						//level_up_sound ();
					}
		
					if (erase_lines >= 2)
					{
						damaged [1 - i] = 1;//iが1の時は2，iが2の時は1に攻撃する
						switch (erase_lines)
						{
							case 2:
							damaged_lines [1 - i] += 1;
							break;
				
							case 3:
							damaged_lines [1 - i] += 2;
							break;
						
							case 4:
							damaged_lines [1 - i] += 4;
							break;
						}
					}
				}
				erase_lines = 0;
			}
		}
		else
		{
			quit = 2; // Gameover.
		}
	}

	for (for_a = 0; for_a <= 1; for_a++)
	{
		death (for_a);
	}

	it.__txtclear ();
	if (
	block [0] [X (blocks [0]._att (), 1) + blocks [0]._x ()]
		[Y (blocks [0]._att (), 1) + blocks [0]._y ()]._attribute () != 0 ||
	block [0] [X (blocks [0]._att (), 2) + blocks [0]._x ()]
		[Y (blocks [0]._att (), 2) + blocks [0]._y ()]._attribute () != 0 ||
	block [0] [X (blocks [0]._att (), 3) + blocks [0]._x ()]
		[Y (blocks [0]._att (), 3) + blocks [0]._y ()]._attribute () != 0 ||
	block [0] [X (blocks [0]._att (), 4) + blocks [0]._x ()]
		[Y (blocks [0]._att (), 4) + blocks [0]._y ()]._attribute () != 0)
	{
		it._color (RED);
		gotoxy (27, 25);
		printf ("The 2nd player wins.");
		it._color (WHITE);
	}
	else
	//1playerが負けたときは，無条件で1playerの負け。つまり，2playerの方が有利。
	{
		if (
		block [1] [X (blocks [1]._att (), 1) + blocks [1]._x ()]
			[Y (blocks [1]._att (), 1) + blocks [1]._y ()]._attribute () != 0 ||
		block [1] [X (blocks [1]._att (), 2) + blocks [1]._x ()]
			[Y (blocks [1]._att (), 2) + blocks [1]._y ()]._attribute () != 0 ||
		block [1] [X (blocks [1]._att (), 3) + blocks [1]._x ()]
			[Y (blocks [1]._att (), 3) + blocks [1]._y ()]._attribute () != 0 ||
		block [1] [X (blocks [1]._att (), 4) + blocks [1]._x ()]
			[Y (blocks [1]._att (), 4) + blocks [1]._y ()]._attribute () != 0
		)
		{
			it._color (RED);
			gotoxy (27, 25);
			printf ("The 1st player wins.");
			it._color (WHITE);
		}
	}
	it._color (LIGHTBLUE);
	gotoxy (69, 1);
	printf ("TETRAS");
	gotoxy (69, 2);
	printf ("Copy-right");
	gotoxy (69, 3);
	printf ("Ruler-soft");
	it._color (WHITE);
	gotoxy (39, 10);
	printf ("Next");
	gotoxy (29, 6);
	printf ("Lines %d VS %d", erased_lines [0], erased_lines [1]);
	gotoxy (29, 7);
	printf ("Level %d VS %d", *level, *(level + 1));
	gotoxy (29, 8);
	printf ("Point %ld VS %ld", *points, *(points + 1));

	it._key (&key_a, &key_b);
	delay (200);
}
