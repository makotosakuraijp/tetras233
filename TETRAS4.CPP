#include <tetras.h>

void oneplay (int *level, unsigned long *points)
{
	extern BLOCK block [3] [13] [22];
	extern LINES lines;
	extern GRAPHIC it;
	extern MOVEBLOCK blocks [3];
	extern MOVEBLOCK nextblocks [3];
	int for_a;
	int i;
	// int count; //Not dealing with an over clock.
	long count;
	int key_a, key_b;
	time_t t1;
	//int quickness; // Not dealing with an over clock.
	unsigned long quickness;
	int erased_lines = 0;
	//int ENDCOUNT; // Not dealing with an over clock.
	unsigned long ENDCOUNT;
	int quit = 0;
	int next = 0;
	int erase_lines = 0;
	int erasing_line [4];
	int tmp_int = 0;
	// unsigned lastkey [120]; //Not dealing with an over clock.
	unsigned key [120];
	//int wait_letters = 0; // Not dealing with an over clock.
	//int wait_tmp = 0; // Not dealing with an over clock
	// int WAIT = 0; // Not dealing with an over clock.
	unsigned long lastkey [120];
	long wait_letters = 0, wait_tmp = 0, WAIT = 0;

	it._keyclear (lastkey);
	it._keyclear (key);

	erasing_line [0] = -1;
	erasing_line [1] = -1;
	erasing_line [2] = -1;
	erasing_line [3] = -1;

	nextblocks [0]._att (random (7) * 10 + 11);
	nextblocks [0]._x (4);
	nextblocks [0]._y (-1);
	nextblocks [0]._color (nextblocks [0]._att ());

	t1 = time (NULL);
	//gotoxy (1, 23); // Debug info.
	//cprintf ("t1 = time (NULL) = %d", t1);
	//for (quickness = 1; difftime (time (NULL), t1) <= 5; quickness++) // Changed to be more speedy.
	for (quickness = 1; difftime (time (NULL), t1) <= 2; quickness++)
	{
		it._quick_key (&key_a, &key_b);
	}
	//gotoxy (1, 24); // Debug info.
	//cprintf ("The quickness value is %ld", quickness);
	//WAIT = 60;
	//WAIT = ((int) (quickness / 22)) + 4; // Not dealing with an over clock.
	WAIT = ((long) (quickness / 22)) + 4;

	randomize();

	for ( ; quit == 0; )
	{
		ENDCOUNT = ending_count (*level, quickness);
		//gotoxy (1, 25); // Debug info.
		//cprintf ("count / ENDCOUNT = %ld / %ld", count, ENDCOUNT);

		erasing_line [0] = -1;
		erasing_line [1] = -1;
		erasing_line [2] = -1;
		erasing_line [3] = -1;
		erase_lines = 0;
		tmp_int = 0;

		gotoxy (41, 6);
		printf ("Lines       %d", erased_lines);
		gotoxy (41, 7);
		printf ("Level       %d", *level);
		gotoxy (41, 8);
		printf ("Point       %ld", *points);

		put (X (nextblocks [0]._att (), 1) + 16,
			Y (nextblocks [0]._att (), 1) + 10, BLACK, 1);
		put (X (nextblocks [0]._att (), 2) + 16,
			Y (nextblocks [0]._att (), 2) + 10, BLACK, 1);
		put (X (nextblocks [0]._att (), 3) + 16,
			Y (nextblocks [0]._att (), 3) + 10, BLACK, 1);
		put (X (nextblocks [0]._att (), 4) + 16,
			Y (nextblocks [0]._att (), 4) + 10, BLACK, 1);

		blocks [0]._att (nextblocks [0]._att());
		blocks [0]._x (4);
		blocks [0]._y (-1);
		blocks [0]._color (blocks [0]._att ());

		nextblocks [0]._att (random (7) * 10 + 11);
		nextblocks [0]._x (4);
		nextblocks [0]._y (-1);
		nextblocks [0]._color (nextblocks [0]._att ());

		if (next == 0)
		{
			put (X (nextblocks [0]._att (), 1) + 16,
				Y (nextblocks [0]._att (), 1) + 10,
				nextblocks [0]._color (), 1);
			put (X (nextblocks [0]._att (), 2) + 16,
				Y (nextblocks [0]._att (), 2) + 10,
				nextblocks [0]._color (), 1);
			put (X (nextblocks [0]._att (), 3) + 16,
				Y (nextblocks [0]._att (), 3) + 10,
				nextblocks [0]._color (), 1);
			put (X (nextblocks [0]._att (), 4) + 16,
				Y (nextblocks [0]._att (), 4) + 10,
				nextblocks [0]._color (), 1);
		}

		for (i = 1; i <= 4; i++)
		{
			if (Y (blocks [0]._att (), i) + blocks [0]._y () >= 2)
			{
				put (X (blocks [0]._att (), i) + blocks [0]._x (),
					Y (blocks [0]._att (), i) + blocks [0]._y (), blocks [0]._color (), 1);
			}
		}

		if (
			block [0] [X (blocks [0]._att (), 1) + blocks [0]._x ()]
				[Y (blocks [0]._att (), 1) + blocks [0]._y ()]._attribute () == 0 &&
			block [0] [X (blocks [0]._att (), 2) + blocks [0]._x ()]
				[Y (blocks [0]._att (), 2) + blocks [0]._y ()]._attribute () == 0 &&
			block [0] [X (blocks [0]._att (), 3) + blocks [0]._x ()]
				[Y (blocks [0]._att (), 3) + blocks [0]._y ()]._attribute () == 0 &&
			block [0] [X (blocks [0]._att (), 4) + blocks [0]._x ()]
				[Y (blocks [0]._att (), 4) + blocks [0]._y ()]._attribute () == 0
		)
		{
			// count > 0 for not dealing with an over clock.
			for (count = 1; count <= ENDCOUNT; count++)
			{
				it._key (key);
				//it._cursor (OFF);
				//	_text_cursor_off ();
				text_cursor_hide (); // master.lib _text_cursor_off (); //gr.lib
				//it._quick_key (&key_a, &key_b);

				// Changing the key wait.
				if (key [KEY_1] == 1 && lastkey [KEY_1] == 0)
				{
					it._active (1);
					//setactivepage (1); //BGI
					//grVPage (1);//裏画面を表示ページにする。
					it._visual (1);
					///setvisualpage (1); //BGI
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
						||	key_a == KEY_9
						||	key_a == TEN_0 || key_a == TEN_1 || key_a == TEN_2
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
						printf ("%ld", wait_tmp);
						gotoxy (wait_letters + 1, 3);
						//it._cursor (ON);
						text_cursor_show ();
						// master.lib _text_cursor_on (); //gr.lib
						}
					}

				it._active (0);
				//setactivepage (0); // BGI
				//grVPage (0);//表画面を表示ページにする。
				it._visual (0);
				// setvisualpage (0); // BGI
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
				printf ("NEXT");
				gotoxy (41, 6);
				printf ("Lines       %d", erased_lines);
				gotoxy (41, 7);
				printf ("Level       %d", *level);
				gotoxy (41, 8);
				printf ("Point       %ld", *points);

				WAIT = wait_tmp;
				key_a = 0;
				wait_tmp = 0;
				wait_letters = 0;
				//it._cursor (OFF);
				text_cursor_hide ();
				// master.lib _text_cursor_off (); //gr.lib
				lastkey [KEY_1] = WAIT;
				}

				// Pause
				if (key [F1] == 1 && lastkey [F1] == 0)
				{
					gotoxy (41, 5);
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
				gotoxy (41, 5);
				it._color (BLACK);
				printf ("Pause");
				it._color (WHITE);
				lastkey [F1] = WAIT;
				}

				// Right
				if (key [TEN_6] == 1 || key [MIGI] == 1 ||
					key [COLON] == 1 || key [KEY_D] == 1)
				{
					if (lastkey [TEN_6] == 0 && lastkey [MIGI] == 0 &&
						lastkey [COLON] == 0 && lastkey [KEY_D] == 0)
					{
						move (blocks, 1, 0, block [0], 1);
						it._keyclear ();
						lastkey [TEN_6] = WAIT;
						lastkey [MIGI] = WAIT;
						lastkey [COLON] = WAIT;
						lastkey [KEY_D] = WAIT;
					}
				}

				// Left
				if (key [TEN_4] == 1 || key [HIDARI] == 1 ||
					key [KEY_L] == 1 || key [KEY_A] == 1)
				{
					if (lastkey [TEN_4] == 0 && lastkey [HIDARI] == 0 &&
						lastkey [KEY_L] == 0 && lastkey [KEY_A] == 0)
					{
						move (blocks, -1, 0, block [0], 1);
						it._keyclear ();
						lastkey [TEN_4] = WAIT;
						lastkey [HIDARI] = WAIT;
						lastkey [KEY_L] = WAIT;
						lastkey [KEY_A] = WAIT;
					}
				}

				// Down
				if (key [TEN_2] == 1 || key [SITA] == 1 ||
					key [SLASH] == 1 || key [KEY_X] == 1)
				{
					if (lastkey [TEN_2] == 0 && lastkey [SITA] == 0 &&
						lastkey [SLASH] == 0 && lastkey [KEY_X] == 0)
					{
						(*points) += *level;
						if (move (blocks, 0, 1, block [0], 1) == -1)
						{
							count = ENDCOUNT * 2;
						}
						else
						{
							count = 0;
						}
						it._keyclear ();
						if (key [CTRL] == 0 && key [SPACE] == 0 &&
							key [SHIFT] == 0)
						{
							// Dealing with an over clock.
							lastkey [TEN_2] = (long) (WAIT / 2);
							lastkey [SITA]  = (long) (WAIT / 2);
							lastkey [SLASH] = (long) (WAIT / 2);
							lastkey [KEY_X] = (long) (WAIT / 2);
						}
						else
						{
							lastkey [TEN_2] = WAIT * 2;
							lastkey [SITA]  = WAIT * 2;
							lastkey [SLASH] = WAIT * 2;
							lastkey [KEY_X] = WAIT * 2;
						}
					}
				}

				// Rotation
				if (key [TEN_5] == 1 || key [CR] == 1 ||
					key [SEMI_C] == 1 || key [KEY_S] == 1)
				{
					if (lastkey [TEN_5] == 0 && lastkey [CR] == 0 ||
						lastkey [SEMI_C] == 0 && lastkey [KEY_S] == 0)
					{
						turn (blocks, block [0], 1);
						it._keyclear ();
						lastkey [TEN_5] = WAIT * 2;
						lastkey [CR] = WAIT * 2;
						lastkey [SEMI_C] = WAIT * 2;
						lastkey [KEY_S] = WAIT * 2;
					}
				}

				// Termination.
				if (key [BS] == 1)
				{
					count = ENDCOUNT * 3;
					quit = 1; // Exiting the game.
				}

				// Displaying the Next.
				if (key [HOME] == 1)
				{
					if (lastkey [HOME] == 0)
					{
						if (next == 0)
						{
							put (X (nextblocks [0]._att (), 1) + 16,
								Y (nextblocks [0]._att (), 1) + 10, BLACK, 1);
							put (X (nextblocks [0]._att (), 2) + 16,
								Y (nextblocks [0]._att (), 2) + 10, BLACK, 1);
							put (X (nextblocks [0]._att (), 3) + 16,
								Y (nextblocks [0]._att (), 3) + 10, BLACK, 1);
							put (X (nextblocks [0]._att (), 4) + 16,
								Y (nextblocks [0]._att (), 4) + 10, BLACK, 1);
							next = 1;
						}
						else
						{
							put (X (nextblocks [0]._att (), 1) + 16,
								Y (nextblocks [0]._att (), 1) + 10,
								nextblocks [0]._color (), 1);
							put (X (nextblocks [0]._att (), 2) + 16,
								Y (nextblocks [0]._att (), 2) + 10,
								nextblocks [0]._color (), 1);
							put (X (nextblocks [0]._att (), 3) + 16,
								Y (nextblocks [0]._att (), 3) + 10,
								nextblocks [0]._color (), 1);
							put (X (nextblocks [0]._att (), 4) + 16,
								Y (nextblocks [0]._att (), 4) + 10,
								nextblocks [0]._color (), 1);
							next = 0;
						}
						lastkey [HOME] = WAIT;
					}
				} // Finishing the NEXT display.

				if (count >= ENDCOUNT - 1)
				 // Changed to consider the over clock.
				//while (count >= ENDCOUNT - 1)
				{
					// Debug info.
					//gotoxy (1, 1);
					//printf ("Count %ld >= ENDCOUNT-1 %ld\n", count, ENDCOUNT-1);
					//getch ();
					//if (move (blocks, 0, 1, block [0], 1) == -1)
					//	count = -1;
					//else
					//	count -= ENDCOUNT;
					if (move (blocks, 0, 1, block [0], 1) == -1)
					{
						count =  ENDCOUNT * 2;
					}
					else
					{
						count = 0;
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
			}

			for (for_a = 0; for_a <= 20; for_a++)
			{
				if (lines.howmany (for_a, block [0]) == 10)
				{
					erase_lines++;
				}
			}

			if (erase_lines != 0)
			{
				for (for_a = 0; for_a <= 20; for_a++)
				{
					if (lines.howmany (for_a, block [0]) == 10)
					{
						erasing_line [tmp_int] = for_a;
						tmp_int++;
					}
				}
				erase (erase_lines, erasing_line, 1, block [0]);
				(*points) += erase_lines * (int) ((*level / 3) + 1);
				erased_lines += erase_lines;
				if (erased_lines >= *level * 10)
				{
					(*level)++;
					//level_up_sound ();
				}
			}
		}
		else
		{
			quit = 2; // Gameover
		}
	}

	death (0);

	it._key (&key_a, &key_b);
	delay (200);
}
