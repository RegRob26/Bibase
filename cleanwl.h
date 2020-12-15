#ifdef _WIN32
#include<windows.h>
#endif  

void limpiar_pantalla(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}
