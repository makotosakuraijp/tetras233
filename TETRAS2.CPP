#include <tetras.h>

int menu1 (void)
{
	extern GRAPHIC it;

	int kaso = 15;
	int key_scan;
	int key_shift;

	gotoxy (29, 15);
	printf ("1 Player");
	gotoxy (29, 17);
	printf ("2 Players");
	gotoxy (29, 19);
	printf ("3 Players");

	it._color (WHITE);
	gotoxy (27, kaso);
	printf ("->");
    //getch ();
	it._color (WHITE);

	do
	{
		//it._cursor (OFF);
		text_cursor_hide (); // master.lib _text_cursor_off (); //gr.lib
		//_text_cursor_off ();
		it._key (&key_scan, &key_shift);

		switch (key_scan)
		{
			case ES:
			exit (1);
			break;

			case SITA:
			it._color (BLACK);
			gotoxy (27, kaso);
			printf ("->");
			it._color (WHITE);
			kaso = kaso + 2;
			if (kaso > 19)
			{
				kaso = 19;
			}
			gotoxy (27, kaso);
			it._color (WHITE);
			printf ("->");
			it._color (BLACK);
			break;

			case UE:
			it._color (BLACK);
			gotoxy (27, kaso);
			printf ("->");
			it._color (WHITE);
			kaso = kaso - 2;
			if (kaso < 15)
			{
				kaso = 15;
			}
			gotoxy (27, kaso);
			it._color (WHITE);
			printf ("->");
			it._color (BLACK);
			break;
		}
	}
	while (key_scan != CR);

	return ((kaso - 13) / 2);
}