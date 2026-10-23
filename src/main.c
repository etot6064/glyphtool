/* glyphtool
small tool to get all the characters in the default font
*/

#include <stdint.h>
#include <graphx.h>
#include <keypadc.h>

int main(void) {
	kb_SetMode(MODE_3_CONTINUOUS);
	gfx_Begin();
	gfx_palette[0] = 0xffff;
	gfx_palette[1] = 0x0000;
	gfx_palette[2] = 0x7C00;
	gfx_SetTextBGColor(0);
	gfx_SetTextFGColor(1);
	gfx_SetColor(2);
	gfx_ZeroScreen();
	gfx_FillRectangle_NoClip(0, 0, (9*16)+1, (9*8)+1);
	for (uint24_t y = 0; y < 8; y++) {
		for (uint24_t x = 0; x < 16; x++) {
			gfx_SetTextXY((9*x)+1, (9*y)+1);
			gfx_PrintChar(x+(16*y));
		}
	}
	while (true) {
		if ((kb_Data[6] & kb_Clear) || (kb_Data[1] & kb_Del)) {break;}
	}
	gfx_End();
	return 0;
}
