
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
,  ENEMY_X = 80 - SP_ENEMY_SHIP_W
,  ENEMY_Y = 10
,  SHOT_X = PLAYER_X 
,  SHOT_Y = PLAYER_Y - SP_SHOOT_H
};


//En el antiguo C no se pueden
void main(void) {

   cpct_disableFirmware(); //Dejamos de ejecutar el Firmware default del Amstrad (todo bajo nuestro control)
   cpct_setVideoMode(0); //Ponemos el Modo de video 0 (4 colores)
   cpct_setPalette(g_palette,16);
   cpct_setBorder(HW_BLACK); //Colores por defecto del sistema

//En el antiguo C no se pueden crear variables a mitad de bloque de funcion. Pero se pueden definir subBloques
//Los bloques son necesarios para que el compidador tenga en cuenta las vriables al principio, son ambitos o scopes
{
   u8 *pvmen = cpct_getScreenPtr(CPCT_VMEM_START,PLAYER_X,PLAYER_Y);
   cpct_drawSprite(sp_player_ship,pvmen,SP_PLAYER_SHIP_W,SP_PLAYER_SHIP_H);
}

{
   u8 *pvmen = cpct_getScreenPtr(CPCT_VMEM_START,ENEMY_X,ENEMY_Y);
   cpct_drawSprite(sp_enemy_ship,pvmen,SP_ENEMY_SHIP_W,SP_ENEMY_SHIP_H);
}

{
   u8 *pvmen = cpct_getScreenPtr(CPCT_VMEM_START,SHOT_X,SHOT_Y);
   cpct_drawSprite(sp_shoot,pvmen,SP_SHOOT_W,SP_SHOOT_H);
}
   
   
   while (TRUE);
}
