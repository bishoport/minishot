                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.6.8 #9946 (Linux)
                              4 ;--------------------------------------------------------
                              5 	.module main
                              6 	.optsdcc -mz80
                              7 	
                              8 ;--------------------------------------------------------
                              9 ; Public variables in this module
                             10 ;--------------------------------------------------------
                             11 	.globl _main
                             12 	.globl _drawShoot
                             13 	.globl _drawEnemy
                             14 	.globl _drawPlayer
                             15 	.globl _cpct_getScreenPtr
                             16 	.globl _cpct_setPALColour
                             17 	.globl _cpct_setPalette
                             18 	.globl _cpct_setVideoMode
                             19 	.globl _cpct_drawSprite
                             20 	.globl _cpct_disableFirmware
                             21 ;--------------------------------------------------------
                             22 ; special function registers
                             23 ;--------------------------------------------------------
                             24 ;--------------------------------------------------------
                             25 ; ram data
                             26 ;--------------------------------------------------------
                             27 	.area _DATA
                             28 ;--------------------------------------------------------
                             29 ; ram data
                             30 ;--------------------------------------------------------
                             31 	.area _INITIALIZED
                             32 ;--------------------------------------------------------
                             33 ; absolute external ram data
                             34 ;--------------------------------------------------------
                             35 	.area _DABS (ABS)
                             36 ;--------------------------------------------------------
                             37 ; global & static initialisations
                             38 ;--------------------------------------------------------
                             39 	.area _HOME
                             40 	.area _GSINIT
                             41 	.area _GSFINAL
                             42 	.area _GSINIT
                             43 ;--------------------------------------------------------
                             44 ; Home
                             45 ;--------------------------------------------------------
                             46 	.area _HOME
                             47 	.area _HOME
                             48 ;--------------------------------------------------------
                             49 ; code
                             50 ;--------------------------------------------------------
                             51 	.area _CODE
                             52 ;src/main.c:23: void drawPlayer(){
                             53 ;	---------------------------------
                             54 ; Function drawPlayer
                             55 ; ---------------------------------
   4190                      56 _drawPlayer::
                             57 ;src/main.c:24: u8 *pvmen = cpct_getScreenPtr(CPCT_VMEM_START,PLAYER_X,PLAYER_Y);
   4190 21 25 B8      [10]   58 	ld	hl, #0xb825
   4193 E5            [11]   59 	push	hl
   4194 21 00 C0      [10]   60 	ld	hl, #0xc000
   4197 E5            [11]   61 	push	hl
   4198 CD E4 42      [17]   62 	call	_cpct_getScreenPtr
                             63 ;src/main.c:25: cpct_drawSprite(sp_player_ship,pvmen,SP_PLAYER_SHIP_W,SP_PLAYER_SHIP_H);
   419B 01 00 41      [10]   64 	ld	bc, #_sp_player_ship+0
   419E 11 08 10      [10]   65 	ld	de, #0x1008
   41A1 D5            [11]   66 	push	de
   41A2 E5            [11]   67 	push	hl
   41A3 C5            [11]   68 	push	bc
   41A4 CD 20 42      [17]   69 	call	_cpct_drawSprite
   41A7 C9            [10]   70 	ret
                             71 ;src/main.c:28: void drawEnemy(){
                             72 ;	---------------------------------
                             73 ; Function drawEnemy
                             74 ; ---------------------------------
   41A8                      75 _drawEnemy::
                             76 ;src/main.c:29: u8 *pvmen = cpct_getScreenPtr(CPCT_VMEM_START,ENEMY_X,ENEMY_Y);
   41A8 21 48 0A      [10]   77 	ld	hl, #0x0a48
   41AB E5            [11]   78 	push	hl
   41AC 21 00 C0      [10]   79 	ld	hl, #0xc000
   41AF E5            [11]   80 	push	hl
   41B0 CD E4 42      [17]   81 	call	_cpct_getScreenPtr
                             82 ;src/main.c:30: cpct_drawSprite(sp_enemy_ship,pvmen,SP_ENEMY_SHIP_W,SP_ENEMY_SHIP_H);
   41B3 01 80 40      [10]   83 	ld	bc, #_sp_enemy_ship+0
   41B6 11 08 10      [10]   84 	ld	de, #0x1008
   41B9 D5            [11]   85 	push	de
   41BA E5            [11]   86 	push	hl
   41BB C5            [11]   87 	push	bc
   41BC CD 20 42      [17]   88 	call	_cpct_drawSprite
   41BF C9            [10]   89 	ret
                             90 ;src/main.c:33: void drawShoot(){
                             91 ;	---------------------------------
                             92 ; Function drawShoot
                             93 ; ---------------------------------
   41C0                      94 _drawShoot::
                             95 ;src/main.c:34: u8 *pvmen = cpct_getScreenPtr(CPCT_VMEM_START,SHOT_X,SHOT_Y);
   41C0 21 25 A8      [10]   96 	ld	hl, #0xa825
   41C3 E5            [11]   97 	push	hl
   41C4 21 00 C0      [10]   98 	ld	hl, #0xc000
   41C7 E5            [11]   99 	push	hl
   41C8 CD E4 42      [17]  100 	call	_cpct_getScreenPtr
                            101 ;src/main.c:35: cpct_drawSprite(sp_shoot,pvmen,SP_SHOOT_W,SP_SHOOT_H);
   41CB 01 00 40      [10]  102 	ld	bc, #_sp_shoot+0
   41CE 11 08 10      [10]  103 	ld	de, #0x1008
   41D1 D5            [11]  104 	push	de
   41D2 E5            [11]  105 	push	hl
   41D3 C5            [11]  106 	push	bc
   41D4 CD 20 42      [17]  107 	call	_cpct_drawSprite
   41D7 C9            [10]  108 	ret
                            109 ;src/main.c:39: void main(void) {
                            110 ;	---------------------------------
                            111 ; Function main
                            112 ; ---------------------------------
   41D8                     113 _main::
                            114 ;src/main.c:41: cpct_disableFirmware(); //Dejamos de ejecutar el Firmware default del Amstrad (todo bajo nuestro control)
   41D8 CD D3 42      [17]  115 	call	_cpct_disableFirmware
                            116 ;src/main.c:42: cpct_setVideoMode(0); //Ponemos el Modo de video 0 (4 colores)
   41DB 2E 00         [ 7]  117 	ld	l, #0x00
   41DD CD C5 42      [17]  118 	call	_cpct_setVideoMode
                            119 ;src/main.c:43: cpct_setPalette(g_palette,16);
   41E0 21 10 00      [10]  120 	ld	hl, #0x0010
   41E3 E5            [11]  121 	push	hl
   41E4 21 80 41      [10]  122 	ld	hl, #_g_palette
   41E7 E5            [11]  123 	push	hl
   41E8 CD FD 41      [17]  124 	call	_cpct_setPalette
                            125 ;src/main.c:44: cpct_setBorder(HW_BLACK); //Colores por defecto del sistema
   41EB 21 10 14      [10]  126 	ld	hl, #0x1410
   41EE E5            [11]  127 	push	hl
   41EF CD 14 42      [17]  128 	call	_cpct_setPALColour
                            129 ;src/main.c:49: drawPlayer();
   41F2 CD 90 41      [17]  130 	call	_drawPlayer
                            131 ;src/main.c:50: drawEnemy();
   41F5 CD A8 41      [17]  132 	call	_drawEnemy
                            133 ;src/main.c:51: drawShoot();
   41F8 CD C0 41      [17]  134 	call	_drawShoot
                            135 ;src/main.c:53: while (TRUE);
   41FB                     136 00102$:
   41FB 18 FE         [12]  137 	jr	00102$
                            138 	.area _CODE
                            139 	.area _INITIALIZER
                            140 	.area _CABS (ABS)
