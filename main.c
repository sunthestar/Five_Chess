#include "stdio.h"
#include "string.h"

#include "Map.h"
#include "Show.h"
#include "Key.h"
#include "Login.h"


int main() {

	Map_Init();

	show();
	//Focus_Move(focus);
	while (1) {
		Key_Scan();
		//show();
	}
	return 0;
}