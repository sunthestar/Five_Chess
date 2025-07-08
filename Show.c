#include "Show.h"
#include "Map.h"
#include "Login.h"

#include "stdio.h"
#include "stdlib.h"

void show() {
	system("cls");
	for (int i = 0; i < YLen; i++) {
		printf_s("%s", Map[i]);
		printf_s("\n");
	}
	
}