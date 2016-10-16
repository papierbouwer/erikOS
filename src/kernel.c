#include "../include/kb.h"
#include "../include/isr.h"
#include "../include/idt.h"
#include "../include/util.h"
#include "../include/shell.h"

void kmain()
{
	isrInstall();
	clearScreen();
	print("Welcome to erikOS\nPlease enter a command\n\n");
    launchShell(0);
    setScreenColorCode((BLACK << 4) | WHITE);
    clearScreen();
    printFromPositionColor("The computer can be safely turned off.", 20, 12, GREEN, BLACK);
}
