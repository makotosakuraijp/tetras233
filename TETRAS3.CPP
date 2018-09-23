#include <tetras.h>

int menu2 (void)
{
	extern GRAPHIC it;
	int a = RED;
	int b = WHITE;
	int key_a;
	int key_b;

	do
	{
		it._color (WHITE);
		gotoxy (36, 6);
		printf ("Choose your type.");
		it._color (a);
		gotoxy (36, 7);
		printf ("1 Player exercise");
		it._color (b);
		gotoxy (36, 8);
		printf ("Record");
		it._box (274, 77, 490, 128, LIGHTBLUE);
		it._box (275, 78, 489, 127, LIGHTGREEN);

		//it._cursor (OFF);
		text_cursor_hide (); // master.lib _text_cursor_off (); //gr.lib
		it._key (&key_a, &key_b);

		if (key_a == ES)
		{
			it.__txtclear ();
			it._clear ();
			exit (1);
		}

		if (key_a == CR && a == 4)
		{
			break;
		}

		if (key_a == SITA)
		{
			a = WHITE;
			b = RED;
		}

		if (key_a == UE)
		{
			a = RED;
			b = WHITE;
		}
	}
	while (1);

	return (a);
}