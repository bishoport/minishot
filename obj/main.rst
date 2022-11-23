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
                             12 	.globl _cpct_getScreenPtr
                             13 	.globl _cpct_setPALColour
                             14 	.globl _cpct_setPalette
                             15 	.globl _cpct_setVideoMode
                             16 	.globl _cpct_drawSprite
                             17 	.globl _cpct_disableFirmware
                             18 ;--------------------------------------------------------
                             19 ; special function registers
                             20 ;--------------------------------------------------------
                             21 ;--------------------------------------------------------
                             22 ; ram data
                             23 ;--------------------------------------------------------
                             24 	.area _DATA
                             25 ;--------------------------------------------------------
                             26 ; ram data
                             27 ;--------------------------------------------------------
                             28 	.area _INITIALIZED
                             29 ;--------------------------------------------------------
                             30 ; absolute external ram data
                             31 ;--------------------------------------------------------
                             32 	.area _DABS (ABS)
                             33 ;--------------------------------------------------------
                             34 ; global & static initialisations
                             35 ;--------------------------------------------------------
                             36 	.area _HOME
                             37 	.area _GSINIT
                             38 	.area _GSFINAL
                             39 	.area _GSINIT
                             40 ;--------------------------------------------------------
                             41 ; Home
                             42 ;--------------------------------------------------------
                             43 	.area _HOME
                             44 	.area _HOME
                             45 ;--------------------------------------------------------
                             46 ; code
                             47 ;--------------------------------------------------------
                             48 	.area _CODE
                             49 ;src/main.c:24: void main(void) {
                             50 ;	---------------------------------
                             51 ; Function main
                             52 ; ---------------------------------
   4190                      53 _main::
                             54 ;src/main.c:26: cpct_disableFirmware(); //Dejamos de ejecutar el Firmware default del Amstrad (todo bajo nuestro control)
   4190 CD C7 42      [17]   55 	call	_cpct_disableFirmware
                             56 ;src/main.c:27: cpct_setVideoMode(0); //Ponemos el Modo de video 0 (4 colores)
   4193 2E 00         [ 7]   57 	ld	l, #0x00
   4195 CD B9 42      [17]   58 	call	_cpct_setVideoMode
                             59 ;src/main.c:28: cpct_setPalette(g_palette,16);
   4198 21 10 00      [10]   60 	ld	hl, #0x0010
   419B E5            [11]   61 	push	hl
   419C 21 80 41      [10]   62 	ld	hl, #_g_palette
   419F E5            [11]   63 	push	hl
   41A0 CD F1 41      [17]   64 	call	_cpct_setPalette
                             65 ;src/main.c:29: cpct_setBorder(HW_BLACK); //Colores por defecto del sistema
   41A3 21 10 14      [10]   66 	ld	hl, #0x1410
   41A6 E5            [11]   67 	push	hl
   41A7 CD 08 42      [17]   68 	call	_cpct_setPALColour
                             69 ;src/main.c:34: u8 *pvmen = cpct_getScreenPtr(CPCT_VMEM_START,PLAYER_X,PLAYER_Y);
   41AA 21 25 B8      [10]   70 	ld	hl, #0xb825
   41AD E5            [11]   71 	push	hl
   41AE 21 00 C0      [10]   72 	ld	hl, #0xc000
   41B1 E5            [11]   73 	push	hl
   41B2 CD D8 42      [17]   74 	call	_cpct_getScreenPtr
                             75 ;src/main.c:35: cpct_drawSprite(sp_player_ship,pvmen,SP_PLAYER_SHIP_W,SP_PLAYER_SHIP_H);
   41B5 01 00 41      [10]   76 	ld	bc, #_sp_player_ship+0
   41B8 11 08 10      [10]   77 	ld	de, #0x1008
   41BB D5            [11]   78 	push	de
   41BC E5            [11]   79 	push	hl
   41BD C5            [11]   80 	push	bc
   41BE CD 14 42      [17]   81 	call	_cpct_drawSprite
                             82 ;src/main.c:39: u8 *pvmen = cpct_getScreenPtr(CPCT_VMEM_START,ENEMY_X,ENEMY_Y);
   41C1 21 48 0A      [10]   83 	ld	hl, #0x0a48
   41C4 E5            [11]   84 	push	hl
   41C5 21 00 C0      [10]   85 	ld	hl, #0xc000
   41C8 E5            [11]   86 	push	hl
   41C9 CD D8 42      [17]   87 	call	_cpct_getScreenPtr
                             88 ;src/main.c:40: cpct_drawSprite(sp_enemy_ship,pvmen,SP_ENEMY_SHIP_W,SP_ENEMY_SHIP_H);
   41CC 01 80 40      [10]   89 	ld	bc, #_sp_enemy_ship+0
   41CF 11 08 10      [10]   90 	ld	de, #0x1008
   41D2 D5            [11]   91 	push	de
   41D3 E5            [11]   92 	push	hl
   41D4 C5            [11]   93 	push	bc
   41D5 CD 14 42      [17]   94 	call	_cpct_drawSprite
                             95 ;src/main.c:44: u8 *pvmen = cpct_getScreenPtr(CPCT_VMEM_START,SHOT_X,SHOT_Y);
   41D8 21 25 A8      [10]   96 	ld	hl, #0xa825
   41DB E5            [11]   97 	push	hl
   41DC 21 00 C0      [10]   98 	ld	hl, #0xc000
   41DF E5            [11]   99 	push	hl
   41E0 CD D8 42      [17]  100 	call	_cpct_getScreenPtr
                            101 ;src/main.c:45: cpct_drawSprite(sp_shoot,pvmen,SP_SHOOT_W,SP_SHOOT_H);
   41E3 01 00 40      [10]  102 	ld	bc, #_sp_shoot+0
   41E6 11 08 10      [10]  103 	ld	de, #0x1008
   41E9 D5            [11]  104 	push	de
   41EA E5            [11]  105 	push	hl
   41EB C5            [11]  106 	push	bc
   41EC CD 14 42      [17]  107 	call	_cpct_drawSprite
                            108 ;src/main.c:49: while (TRUE);
   41EF                     109 00102$:
   41EF 18 FE         [12]  110 	jr	00102$
                            111 	.area _CODE
                            112 	.area _INITIALIZER
                            113 	.area _CABS (ABS)
