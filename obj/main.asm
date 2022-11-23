;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.8 #9946 (Linux)
;--------------------------------------------------------
	.module main
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _drawShoot
	.globl _drawEnemy
	.globl _drawPlayer
	.globl _cpct_getScreenPtr
	.globl _cpct_setPALColour
	.globl _cpct_setPalette
	.globl _cpct_setVideoMode
	.globl _cpct_drawSprite
	.globl _cpct_disableFirmware
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;src/main.c:23: void drawPlayer(){
;	---------------------------------
; Function drawPlayer
; ---------------------------------
_drawPlayer::
;src/main.c:24: u8 *pvmen = cpct_getScreenPtr(CPCT_VMEM_START,PLAYER_X,PLAYER_Y);
	ld	hl, #0xb825
	push	hl
	ld	hl, #0xc000
	push	hl
	call	_cpct_getScreenPtr
;src/main.c:25: cpct_drawSprite(sp_player_ship,pvmen,SP_PLAYER_SHIP_W,SP_PLAYER_SHIP_H);
	ld	bc, #_sp_player_ship+0
	ld	de, #0x1008
	push	de
	push	hl
	push	bc
	call	_cpct_drawSprite
	ret
;src/main.c:28: void drawEnemy(){
;	---------------------------------
; Function drawEnemy
; ---------------------------------
_drawEnemy::
;src/main.c:29: u8 *pvmen = cpct_getScreenPtr(CPCT_VMEM_START,ENEMY_X,ENEMY_Y);
	ld	hl, #0x0a48
	push	hl
	ld	hl, #0xc000
	push	hl
	call	_cpct_getScreenPtr
;src/main.c:30: cpct_drawSprite(sp_enemy_ship,pvmen,SP_ENEMY_SHIP_W,SP_ENEMY_SHIP_H);
	ld	bc, #_sp_enemy_ship+0
	ld	de, #0x1008
	push	de
	push	hl
	push	bc
	call	_cpct_drawSprite
	ret
;src/main.c:33: void drawShoot(){
;	---------------------------------
; Function drawShoot
; ---------------------------------
_drawShoot::
;src/main.c:34: u8 *pvmen = cpct_getScreenPtr(CPCT_VMEM_START,SHOT_X,SHOT_Y);
	ld	hl, #0xa825
	push	hl
	ld	hl, #0xc000
	push	hl
	call	_cpct_getScreenPtr
;src/main.c:35: cpct_drawSprite(sp_shoot,pvmen,SP_SHOOT_W,SP_SHOOT_H);
	ld	bc, #_sp_shoot+0
	ld	de, #0x1008
	push	de
	push	hl
	push	bc
	call	_cpct_drawSprite
	ret
;src/main.c:39: void main(void) {
;	---------------------------------
; Function main
; ---------------------------------
_main::
;src/main.c:41: cpct_disableFirmware(); //Dejamos de ejecutar el Firmware default del Amstrad (todo bajo nuestro control)
	call	_cpct_disableFirmware
;src/main.c:42: cpct_setVideoMode(0); //Ponemos el Modo de video 0 (4 colores)
	ld	l, #0x00
	call	_cpct_setVideoMode
;src/main.c:43: cpct_setPalette(g_palette,16);
	ld	hl, #0x0010
	push	hl
	ld	hl, #_g_palette
	push	hl
	call	_cpct_setPalette
;src/main.c:44: cpct_setBorder(HW_BLACK); //Colores por defecto del sistema
	ld	hl, #0x1410
	push	hl
	call	_cpct_setPALColour
;src/main.c:49: drawPlayer();
	call	_drawPlayer
;src/main.c:50: drawEnemy();
	call	_drawEnemy
;src/main.c:51: drawShoot();
	call	_drawShoot
;src/main.c:53: while (TRUE);
00102$:
	jr	00102$
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
