/* glyphtool
small tool to get all the characters in the default font
*/

#include <stdint.h>
#include <graphx.h>
#include <keypadc.h>

char * hex = "0123456789ABCDEF";

int main(void) {
	kb_SetMode(MODE_3_CONTINUOUS);
	gfx_Begin();
	gfx_palette[0] = 0xffff;
	gfx_palette[1] = 0x0000;
	gfx_palette[2] = 0x7C00;
	gfx_SetColor(2);
	gfx_ZeroScreen();
	gfx_FillRectangle_NoClip(0, 0, (9*16)+18, (9*8)+10);
	gfx_SetTextFGColor(1);
	gfx_SetTextBGColor(2);
	for (uint24_t x = 0; x < 16; x++) {
		gfx_SetTextXY((9*x)+18, 1);
		gfx_PrintChar(hex[x]);
	}
	for (uint24_t y = 0; y < 8; y++) {
		gfx_SetTextXY(1, (9*y)+10);
		gfx_PrintChar(hex[y]);
		gfx_PrintChar('X');
	}
	gfx_SetTextBGColor(0);
	for (uint24_t y = 0; y < 8; y++) {
		for (uint24_t x = 0; x < 16; x++) {
			gfx_SetTextXY((9*x)+18, (9*y)+10);
			gfx_PrintChar(x+(16*y));
		}
	}
	while (true) {
		if ((kb_Data[6] & kb_Clear) || (kb_Data[1] & kb_Del)) {break;}
	}
	gfx_End();
	return 0;
}
