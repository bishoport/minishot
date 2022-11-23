
#include <cpctelera.h>
#include <sprites/g_palette.h>
#include <sprites/nave.h>
#include <sprites/enemy.h>
#include <sprites/shoot.h>

//extern creamos este espacio (definimos 16 bytes en el bin) basicamente es una definicion
//extern const u8 g_palette[16]; //direccion de memoria con datos u8 (8 bits sin signo) y hay 16 enlaza con g_palette.c. Es const, solo lectura

enum{
   FALSE = 0
,  TRUE = 1
,  PLAYER_X = 37
,  PLAYER_Y = 200 - SP_PLAYER_SHIP_H
,  ENEMY_INIT_X = 80 - SP_ENEMY_SHIP_W
,  ENEMY_Y = 10
,  SHOT_X = PLAYER_X 
,  SHOT_Y = PLAYER_Y - SP_SHOOT_H
};


void drawPlayer(){
   u8 *pvmen = cpct_getScreenPtr(CPCT_VMEM_START,PLAYER_X,PLAYER_Y);
   cpct_drawSprite(sp_player_ship,pvmen,SP_PLAYER_SHIP_W,SP_PLAYER_SHIP_H);
}

void drawEnemy(u8 x){
   u8 *pvmen = cpct_getScreenPtr(CPCT_VMEM_START,x,ENEMY_Y);
   cpct_drawSprite(sp_enemy_ship,pvmen,SP_ENEMY_SHIP_W,SP_ENEMY_SHIP_H);
}

void drawShoot(){
   u8 *pvmen = cpct_getScreenPtr(CPCT_VMEM_START,SHOT_X,SHOT_Y);
   cpct_drawSprite(sp_shoot,pvmen,SP_SHOOT_W,SP_SHOOT_H);
}

//En el antiguo C no se pueden
void main(void) {

   u8 posEnemyX = ENEMY_INIT_X;

   //DEFINICION DE VARIABLES
  // i8 temperatura             = -8; //Para ir con signo -128 -> 127
  // u8 enemy_x                 = 80; //u8 es notacion de CPCTelera, en C es unsigned int
  // u32 potencia_arma_1        = 25910;//unsigned long en C
  // f32 porcentaje             = 0.43; // 10 E -27, 5*10^27, +6*2⁻15 Usa la notacion cientifica para almacenar decimales tochos //float
  // const char *mensaje_win[]  = "Has ganado!"; //Array de caracteres de solo lectura-> mensaje_win es la direccion de memoria donde empieza


   cpct_disableFirmware(); //Dejamos de ejecutar el Firmware default del Amstrad (todo bajo nuestro control)
   cpct_setVideoMode(0); //Ponemos el Modo de video 0 (4 colores)
   cpct_setPalette(g_palette,16);
   cpct_setBorder(HW_BLACK); //Colores por defecto del sistema

//En el antiguo C no se pueden crear variables a mitad de bloque de funcion. Pero se pueden definir subBloques
//Los bloques son necesarios para que el compidador tenga en cuenta las vriables al principio, son ambitos o scopes

   

   while (TRUE)
   {

      posEnemyX = posEnemyX - 1;

      drawPlayer();
      drawEnemy(posEnemyX);
      drawShoot();

      cpct_waitVSYNC();
   };
}
