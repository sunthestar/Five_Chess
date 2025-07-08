#include "stdio.h"
#include "string.h"

#include "Map.h"
#include "Show.h"
#include "Key.h"
#include "Login.h"


int main() {

	Map_Init();

	//memcpy(Map[31] + 2, "¡ñ", 2);		//1+1
	//memcpy(Map[29] + 10, "¡ñ", 2);		//6+1+3
	//memcpy(Map[27] + 18, "¡ñ", 2);		//11+1+3+3    x+1+(3*(x-1)/5)
	//memcpy(Map[25] + 26, "¡ñ", 2);		//16+10
	//memcpy(Map[23] + 34, "¡ñ", 2);		//21+13
	//memcpy(Map[21] + 42, "¡ñ", 2);		//26+16
	//memcpy(Map[19] + 50, "¡ñ", 2);		//31+19
	//memcpy(Map[17] + 58, "¡ñ", 2);
	//memcpy(Map[15] + 66, "¡ñ", 2);
	//memcpy(Map[13] + 74, "¡ñ", 2);
	//memcpy(Map[11] + 82, "¡ñ", 2);
	//memcpy(Map[9] + 90, "¡ñ", 2);
	//memcpy(Map[7] + 98, "¡ñ", 2);
	//memcpy(Map[5] + 106, "¡ñ", 2);
	//memcpy(Map[3] + 114, "¡ñ", 2);
	//memcpy(Map[1] + 122, "¡ñ", 2);

	show();
	
	//Chess_Falling(focus);

	while (1) {
		Key_Scan();
		//show();
	}
	return 0;
}