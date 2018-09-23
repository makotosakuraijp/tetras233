#include <tetras.h>

void func1 (void)
{
	extern GRAPHIC it;

	// Frame of "T"
	it._line (57, 27, 147, 27, LIGHTGREEN);
	it._line (57, 27, 57, 57, LIGHTGREEN);
	it._line (57, 57, 87, 57, LIGHTGREEN);
	it._line (87, 57, 87, 132, LIGHTGREEN);
	it._line (87, 132, 117, 132, LIGHTGREEN);
	it._line (117, 132, 117, 57, LIGHTGREEN);
	it._line (117, 57, 147, 57, LIGHTGREEN);
	it._line (147, 57, 147, 27, LIGHTGREEN);

	// Coating of "T"
	it._paint (58, 28, LIGHTBLUE, LIGHTGREEN);

	// Frame of "E"
	it._line (152, 27, 152, 132, LIGHTGREEN);
	it._line (152, 27, 227, 27, LIGHTGREEN);
	it._line (177, 48, 227, 48, LIGHTGREEN);
	it._line (227, 27, 227, 48, LIGHTGREEN);
	it._line (177, 69, 202, 69, LIGHTGREEN);
	it._line (177, 48, 177, 69, LIGHTGREEN);
	it._line (202, 69, 202, 90, LIGHTGREEN);
	it._line (177, 90, 202, 90, LIGHTGREEN);
	it._line (177, 90, 177, 111, LIGHTGREEN);
	it._line (177, 111, 227, 111, LIGHTGREEN);
	it._line (227, 111, 227, 132, LIGHTGREEN);
	it._line (227, 132, 152, 132, LIGHTGREEN);

	// Coating of "E"
	it._paint (153, 28, LIGHTBLUE, LIGHTGREEN);

	// Frame of "T"
	it._line (232, 27, 322, 27, LIGHTGREEN);
	it._line (232, 27, 232, 57, LIGHTGREEN);
	it._line (232, 57, 262, 57, LIGHTGREEN);
	it._line (262, 57, 262, 132, LIGHTGREEN);
	it._line (262, 132, 292, 132, LIGHTGREEN);
	it._line (292, 132, 292, 57, LIGHTGREEN);
	it._line (292, 57, 322, 57, LIGHTGREEN);
	it._line (322, 57, 322, 27, LIGHTGREEN);

	// Coating of "T"
	it._paint (233, 28, LIGHTBLUE, LIGHTGREEN);

	// Frame of "R"
	it._line (327, 27, 327, 132, LIGHTGREEN);
	it._line (327, 27, 387, 27, LIGHTGREEN);
	it._circle (327, 52, 65, 65, LIGHTGREEN, 337, 23);
	it._line (387, 77, 365, 77, LIGHTGREEN);
	it._line (365, 77, 392, 132, LIGHTGREEN);
	it._line (392, 132, 367, 132, LIGHTGREEN);
	it._line (327, 132, 342, 132, LIGHTGREEN);
	it._line (342, 132, 342, 77, LIGHTGREEN);
	it._line (342, 77, 347, 77, LIGHTGREEN);
	it._line (347, 77, 367, 132, LIGHTGREEN);
	it._circle (357, 52, 20, 14, LIGHTGREEN, 0, 360);

	// Coating of "R"
	it._paint (328, 28, LIGHTBLUE, LIGHTGREEN);

	// Frame of "A"
	it._line (397, 132, 427, 27, LIGHTGREEN);
	it._line (427, 27, 442, 27, LIGHTGREEN);
	it._line (442, 27, 472, 132, LIGHTGREEN);
	it._line (397, 132, 412, 132, LIGHTGREEN);
	it._line (412, 132, 422, 87, LIGHTGREEN);
	it._line (472, 132, 457, 132, LIGHTGREEN);
	it._line (457, 132, 447, 87, LIGHTGREEN);
	it._line (422, 87, 447, 87, LIGHTGREEN);
	it._line (429, 42, 439, 42, LIGHTGREEN);
	it._line (425, 72, 429, 42, LIGHTGREEN);
	it._line (444, 72, 439, 42, LIGHTGREEN);
	it._line (425, 72, 444, 72, LIGHTGREEN);

	// Coating of "A"
	it._paint (428, 28, LIGHTBLUE, LIGHTGREEN);

	// Frame of "S"
	it._line (497, 132, 477, 117, LIGHTGREEN);
	it._line (497, 117, 483, 105, LIGHTGREEN);
	it._line (483, 105, 477, 117, LIGHTGREEN);
	it._circle (497, 102, 40, 30, LIGHTGREEN, 270, 90);
	it._circle (497, 102, 20, 15, LIGHTGREEN, 270, 90);
	it._circle (497, 57, 30, 30, LIGHTGREEN, 90, 270);
	it._circle (497, 57, 15, 15, LIGHTGREEN, 90, 270);
	it._line (497, 27, 517, 30, LIGHTGREEN);
	it._line (497, 42, 517, 45, LIGHTGREEN);
	it._line (517, 30 ,517, 45, LIGHTGREEN);

	// Coating of "S"
	it._paint (498, 28, LIGHTBLUE, LIGHTGREEN);
}
