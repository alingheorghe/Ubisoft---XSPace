#include "Display.h"
#include <Windows.h>
int main(){
	RECT desktop;
   const HWND hDesktop = GetDesktopWindow();
   GetWindowRect(hDesktop, &desktop);

   std::cout <<desktop.bottom << " " << desktop.right << std::endl;

	Display display(desktop.right - 5, desktop.bottom - 60, "XSpace");
	display.Update();
	return 1;
}