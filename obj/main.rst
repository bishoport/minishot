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
                             18 	.globl _cpct_waitVSYNC
                             19 	.globl _cpct_setVideoMode
                             20 	.globl _cpct_drawSprite
                             21 	.globl _cpct_disableFirmware
                             22 ;--------------------------------------------------------
                             23 ; special function registers
                             24 ;--------------------------------------------------------
                             25 ;--------------------------------------------------------
                             26 ; ram data
                             27 ;--------------------------------------------------------
                             28 	.area _DATA
                             29 ;--------------------------------------------------------
                             30 ; ram data
                             31 ;--------------------------------------------------------
                             32 	.area _INITIALIZED
                             33 ;--------------------------------------------------------
                             34 ; absolute external ram data
                             35 ;--------------------------------------------------------
                             36 	.area _DABS (ABS)
                             37 ;--------------------------------------------------------
                             38 ; global & static initialisations
                             39 ;--------------------------------------------------------
                             40 	.area _HOME
                             41 	.area _GSINIT
                             42 	.area _GSFINAL
                             43 	.area _GSINIT
                             44 ;--------------------------------------------------------
                             45 ; Home
                             46 ;--------------------------------------------------------
                             47 	.area _HOME
                             48 	.area _HOME
                             49 ;--------------------------------------------------------
                             50 ; code
                             51 ;--------------------------------------------------------
                             52 	.area _CODE
                             53 ;src/main.c:23: void drawPlayer(){
                             54 ;	---------------------------------
                             55 ; Function drawPlayer
                             56 ; ---------------------------------
   4190                      57 _drawPlayer::
                             58 ;src/main.c:24: u8 *pvmen = cpct_getScreenPtr(CPCT_VMEM_START,PLAYER_X,PLAYER_Y);
   4190 21 25 B8      [10]   59 	ld	hl, #0xb825
   4193 E5            [11]   60 	push	hl
   4194 21 00 C0      [10]   61 	ld	hl, #0xc000
   4197 E5            [11]   62 	push	hl
   4198 CD 08 43      [17]   63 	call	_cpct_getScreenPtr
                             64 ;src/main.c:25: cpct_drawSprite(sp_player_ship,pvmen,SP_PLAYER_SHIP_W,SP_PLAYER_SHIP_H);
   419B 01 00 41      [10]   65 	ld	bc, #_sp_player_ship+0
   419E 11 08 10      [10]   66 	ld	de, #0x1008
   41A1 D5            [11]   67 	push	de
   41A2 E5            [11]   68 	push	hl
   41A3 C5            [11]   69 	push	bc
   41A4 CD 3C 42      [17]   70 	call	_cpct_drawSprite
   41A7 C9            [10]   71 	ret
                             72 ;src/main.c:28: void drawEnemy(u8 x){
                             73 ;	---------------------------------
                             74 ; Function drawEnemy
                             75 ; ---------------------------------
   41A8                      76 _drawEnemy::
   41A8 DD E5         [15]   77 	push	ix
   41AA DD 21 00 00   [14]   78 	ld	ix,#0
   41AE DD 39         [15]   79 	add	ix,sp
                             80 ;src/main.c:29: u8 *pvmen = cpct_getScreenPtr(CPCT_VMEM_START,x,ENEMY_Y);
   41B0 3E 0A         [ 7]   81 	ld	a, #0x0a
   41B2 F5            [11]   82 	push	af
   41B3 33            [ 6]   83 	inc	sp
   41B4 DD 7E 04      [19]   84 	ld	a, 4 (ix)
   41B7 F5            [11]   85 	push	af
   41B8 33            [ 6]   86 	inc	sp
   41B9 21 00 C0      [10]   87 	ld	hl, #0xc000
   41BC E5            [11]   88 	push	hl
   41BD CD 08 43      [17]   89 	call	_cpct_getScreenPtr
                             90 ;src/main.c:30: cpct_drawSprite(sp_enemy_ship,pvmen,SP_ENEMY_SHIP_W,SP_ENEMY_SHIP_H);
   41C0 01 80 40      [10]   91 	ld	bc, #_sp_enemy_ship+0
   41C3 11 08 10      [10]   92 	ld	de, #0x1008
   41C6 D5            [11]   93 	push	de
   41C7 E5            [11]   94 	push	hl
   41C8 C5            [11]   95 	push	bc
   41C9 CD 3C 42      [17]   96 	call	_cpct_drawSprite
   41CC DD E1         [14]   97 	pop	ix
   41CE C9            [10]   98 	ret
                             99 ;src/main.c:33: void drawShoot(){
                            100 ;	---------------------------------
                            101 ; Function drawShoot
                            102 ; ---------------------------------
   41CF                     103 _drawShoot::
                            104 ;src/main.c:34: u8 *pvmen = cpct_getScreenPtr(CPCT_VMEM_START,SHOT_X,SHOT_Y);
   41CF 21 25 A8      [10]  105 	ld	hl, #0xa825
   41D2 E5            [11]  106 	push	hl
   41D3 21 00 C0      [10]  107 	ld	hl, #0xc000
   41D6 E5            [11]  108 	push	hl
   41D7 CD 08 43      [17]  109 	call	_cpct_getScreenPtr
                            110 ;src/main.c:35: cpct_drawSprite(sp_shoot,pvmen,SP_SHOOT_W,SP_SHOOT_H);
   41DA 01 00 40      [10]  111 	ld	bc, #_sp_shoot+0
   41DD 11 08 10      [10]  112 	ld	de, #0x1008
   41E0 D5            [11]  113 	push	de
   41E1 E5            [11]  114 	push	hl
   41E2 C5            [11]  115 	push	bc
   41E3 CD 3C 42      [17]  116 	call	_cpct_drawSprite
   41E6 C9            [10]  117 	ret
                            118 ;src/main.c:39: void main(void) {
                            119 ;	---------------------------------
                            120 ; Function main
                            121 ; ---------------------------------
   41E7                     122 _main::
                            123 ;src/main.c:51: cpct_disableFirmware(); //Dejamos de ejecutar el Firmware default del Amstrad (todo bajo nuestro control)
   41E7 CD F7 42      [17]  124 	call	_cpct_disableFirmware
                            125 ;src/main.c:52: cpct_setVideoMode(0); //Ponemos el Modo de video 0 (4 colores)
   41EA 2E 00         [ 7]  126 	ld	l, #0x00
   41EC CD E9 42      [17]  127 	call	_cpct_setVideoMode
                            128 ;src/main.c:53: cpct_setPalette(g_palette,16);
   41EF 21 10 00      [10]  129 	ld	hl, #0x0010
   41F2 E5            [11]  130 	push	hl
   41F3 21 80 41      [10]  131 	ld	hl, #_g_palette
   41F6 E5            [11]  132 	push	hl
   41F7 CD 19 42      [17]  133 	call	_cpct_setPalette
                            134 ;src/main.c:54: cpct_setBorder(HW_BLACK); //Colores por defecto del sistema
   41FA 21 10 14      [10]  135 	ld	hl, #0x1410
   41FD E5            [11]  136 	push	hl
   41FE CD 30 42      [17]  137 	call	_cpct_setPALColour
                            138 ;src/main.c:61: while (TRUE)
   4201 06 48         [ 7]  139 	ld	b, #0x48
   4203                     140 00102$:
                            141 ;src/main.c:64: posEnemyX = posEnemyX - 1;
   4203 05            [ 4]  142 	dec	b
                            143 ;src/main.c:66: drawPlayer();
   4204 C5            [11]  144 	push	bc
   4205 CD 90 41      [17]  145 	call	_drawPlayer
   4208 C1            [10]  146 	pop	bc
                            147 ;src/main.c:67: drawEnemy(posEnemyX);
   4209 C5            [11]  148 	push	bc
   420A C5            [11]  149 	push	bc
   420B 33            [ 6]  150 	inc	sp
   420C CD A8 41      [17]  151 	call	_drawEnemy
   420F 33            [ 6]  152 	inc	sp
   4210 CD CF 41      [17]  153 	call	_drawShoot
   4213 CD E1 42      [17]  154 	call	_cpct_waitVSYNC
   4216 C1            [10]  155 	pop	bc
   4217 18 EA         [12]  156 	jr	00102$
                            157 	.area _CODE
                            158 	.area _INITIALIZER
                            159 	.area _CABS (ABS)
