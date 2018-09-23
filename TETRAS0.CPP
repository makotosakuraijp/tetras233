#include <tetras.h>

int BLOCK::_color (void)
{
	return color;
}

int BLOCK::_attribute (void)
{
	return attribute;
}

void BLOCK::_color (int a)
{
	color = a;
}

void BLOCK::_attribute (int a)
{
	attribute = a;
}

BLOCK::BLOCK (void)
{
	color = BLACK;
	attribute = 0;
}

int LINES::howmany (int a, BLOCK block [13] [22])
{
	int b = 0;
	int c = 0;

	for (b = 0; b <= 12; b++)
	{
		if (block [b] [a]._attribute () == 1)
		{
			c++;
		}
	}
	return c;
}

void MOVEBLOCK::_att (int a)
{
	attribute = a;
}

void MOVEBLOCK::_x (int a)
{
	x = a;
}

void MOVEBLOCK::_y (int a)
{
	y = a;
}

int MOVEBLOCK::_att (void)
{
	return attribute;
}

int MOVEBLOCK::_x (void)
{
	return x;
}

int MOVEBLOCK::_y (void)
{
	return y;
}

void MOVEBLOCK::_color (int a)
{
	switch ((int) (a / 10))
	{
	case 1:
	color = LIGHTBLUE;
	break;

	case 2:
	color = LIGHTGREEN;
	break;

	case 3:
	color = LIGHTCYAN;
	break;

	case 4:
	color = LIGHTRED;
	break;

	case 5:
	color = LIGHTMAGENTA;
	break;

	case 6:
	color = YELLOW;
	break;

	case 7:
	color = LIGHTGRAY;
	break;
	}
}

int MOVEBLOCK::_color (void){return color;}

GRAPHIC::GRAPHIC (void)
{
	//glioInit (); //gr.lib starts

	/* 自動検出を要求 */
	int gdriver = DETECT, gmode, errorcode;

	/* グラフィックスライブラリに追加されたドライバを登録 */
	errorcode = registerbgidriver (PC98_driver);
	//BGI interface

	/* 登録エラーの表示 */
	if (errorcode < 0) //BGI
	{
	   printf ("Graphics error: %s\n", grapherrormsg(errorcode));
	   printf ("Press any key to halt:");
	   getch ();
	   exit (1); /* エラーとして終了 */
	}

	/* グラフィックスシステムの初期化 */
	initgraph (&gdriver, &gmode, ""); //BGI

	/* 初期化の結果を取得 */
	errorcode = graphresult (); //BGI
	if (errorcode != grOk)  /* エラーが発生したか？ */
	{
	   printf ("Graphics error: %s\n", grapherrormsg (errorcode));
	   printf ("Press any key to halt:");
	   getch ();
	   exit (1); /* エラーとして終了 */
	}

	getpalette (&first_pal); //BGI: preserves the first palette colors.

	cleardevice (); //BGI
	key_beep_off (); //Master.lib  DisableKeyBeep (); //gr.lib
	dos_setbreak (0); //master.lib DisableCtrlC (); //gr.lib

	setpalette (0, BLACK); //BGI: customize the default colour.
	setpalette (1, BLUE);
	setpalette (2, GREEN);
	setpalette (3, CYAN);
	setpalette (4, RED);
	setpalette (5, MAGENTA);
	setpalette (6, BROWN);
	setpalette (7, LIGHTGRAY);
	setpalette (8, DARKGRAY);
	setpalette (9, LIGHTBLUE);
	setpalette (10, LIGHTGREEN);
	setpalette (11, LIGHTCYAN);
	setpalette (12, LIGHTRED);
	setpalette (13, LIGHTMAGENTA);
	setpalette (14, YELLOW);
	setpalette (15, WHITE);
	getpalette (&pal); //BGI

	palette_set (BLACK,     0, 0, 0);  // master.lib grPal1 (BLACK, 0, 0, 0);//gr.lib
	palette_set (BLUE,      0, 0, 7);  // master.lib grPal1 (BLUE, 0, 0,7);
	palette_set (GREEN,     7, 0, 0);  // master.lib grPal1 (GREEN, 7, 0, 0);
	palette_set (CYAN,      7, 7, 0);  // master.lib grPal1 (CYAN, 7, 7, 0);
	palette_set (RED,       0, 7, 0);  // master.lib grPal1 (RED, 0, 7, 0);
	palette_set (MAGENTA,   0, 7, 7);  // master.lib grPal1 (MAGENTA, 0, 7, 7);
	palette_set (BROWN,     7, 0, 7);  // master.lib grPal1 (BROWN, 7, 0, 7);
	palette_set (LIGHTGRAY, 7, 7, 7);  // master.lib grPal1 (LIGHTGRAY, 7, 7, 7);
	palette_set (DARKGRAY,  3, 3, 3);  // master.lib grPal1 (DARKGRAY, 3, 3, 3);
	palette_set (LIGHTBLUE, 0, 0, 15); // master.lib grPal1 (LIGHTBLUE, 0, 0, 15);
	palette_set (LIGHTGREEN,15,0, 0);  // master.lib grPal1 (LIGHTGREEN, 15, 0, 0);
	palette_set (LIGHTCYAN, 0,15,15);  // master.lib grPal1 (LIGHTCYAN, 0, 15, 15);
	palette_set (LIGHTRED, 0, 15, 0);  // master.lib grPal1 (LIGHTRED, 0, 15, 0);
	palette_set (LIGHTMAGENTA,15,0,15);// master.lib grPal1 (LIGHTMAGENTA, 15,0, 15);
	palette_set (YELLOW,  15, 15, 0);  // master.lib grPal1 (YELLOW, 15, 15, 0);
	palette_set (WHITE,   15, 15,15);  // master.lib grPal1 (WHITE, 15, 15, 15);

	graph_start (); //master.lib grOn (); //gr.lib
}
//gr.lib
//----------------------------------------------------------------
//int     glioInit( void );
//    glioルーチンを使用可能にする(GLIO 関数を使う場合は、必ず最初
//    に呼び出しておく)。
//
//    return.
//        OK          成功
//        MEMORY_ER   失敗 (メモリが足りない)
//
//    ※実行すると、テキスト画面がクリアされるので注意
//----------------------------------------------------------------
//void    DisableKeyBeep( void );
//    キーボードリピート時 (キーを押しっぱなしにした時) にビープが
//    鳴り、速度が低下するのを防ぐ。
//    ※getch()等の MS-DOSの標準入力を使っていては効果がないので、
//      int 21h function 06h や、BIOS やキー直接読取りによるキー入
//      力ルーチンと併用すること。(joy.lib は OK)
//----------------------------------------------------------------
//void    DisableCtrlC( void );
//    getch(), puts() 等、MS-DOS の機能使用時に STOPキー、^C  で終
//    了してしまうのを防ぐ。
//    ※^C割り込み処理ベクタ(int 23h) を書き換える。
//----------------------------------------------------------------
//void    grPal( char pal[16][3] );
//    16色一括パレット設定。
//    ・並び順は { R,G,B }
//----------------------------------------------------------------
//void    grPal1( int color, int r, int g, int b );
//    1色だけパレットを変える。

//void	grStart( void );
//void	grEnd( void );
//void	grOn( void );
//void	grOff( void );
//void	grPal( void *pal );
//void	grPalTone( void *pal, int tone );
//void	grPal1( int color, int r, int g, int b );

//----------------------------------------------------------------
//void    grOn( void );
//    グラフィック画面の表示開始。
//    (400ライン - アナログモードに設定)

// +----------------------+
// | registerbgidriver,   |         <GRAPHICS.H>
// | registerfarbgidriver |
// +----------------------+
// ユーザがロードまたはリンクしたグラフィックスドライバを
// グラフィックスシステムに登録します。
//
// 宣言:
//  ･ int registerbgidriver(void (*driver)(void));
//  ･ int far registerfarbgidriver(void far *driver);
//
// 説明:
//･ registerbgidriver を使うと，ユーザはドライバファイルをロードして，そのドラ
//イバを登録できます。
//
//･ registerfarbgidriver は，far ドライバを登録するのに使用されます。
//
//そのメモリ位置が registerbgidriver に渡されると，initgraph は登録されたドラ
//イバを使います。
//
//ユーザが登録したドライバは，ディスクからヒープメモリにロードされるか，
//BGIOBJ.EXE を使って.OBJ ファイルに変換して，実行ファイルにリンクできます。
//
//registerbgidriver を呼び出すと，driver が指すドライバがリンク時に インクルー
//ドされていることがグラフィックスシステムに通知されます。
//
//registerbgidriver は，指定されたドライバにリンクされたコードをチェックしま
//す。コードが有効であれば，内部テーブルにコードを登録します。
//
//リンクされたドライバについては，UTIL.DOC を参照してください。
//
//registerbgidriver を呼び出すときに，リンクされたドライバの名前を使うと，その
//パブリック名でオブジェクトファイルにリンクするように，コンパイラ（およびリン
//カ）に指定することになります。
//
// Far ドライバ
// ------------
//Far ドライバは，BGIOBJ ユーティリティを使って，/F オプションを指定することに
//よって作成できます。このオプションについては，UTIL.DOC（Turbo C++ のマスター
//ディスクに入っています）に説明されています。
//
//
// 戻り値:
//  ･ 指定されたドライバまたはフォントが正しくない場合は，負の
//    グラフィックスエラーコードを返します。
//  ･ そうでなければ，ドライバ番号を返します。
//
//ユーザが与えたドライバを登録する場合は，使用するドライブ番号として，
//registerbgidriver の結果をinitgraph に渡さなければなりません。
//
// 移植性:
// + DOS + UNIX + Windows + ANSI C + C++ のみ + PC-98 & DOS/V +
// |     |      |         |        |          |      ○       |
// +-----+------+---------+--------+----------+---------------+
//
// 参照:
//   graphresult
//   initgraph
//   installuserdriver
//   registerbgifont
//
// 例 (registerbgidriver のみ):
//
// #include <graphics.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <conio.h>
//
// int main(void)
// {
//    /* 自動検出を要求 */
//    int gdriver = DETECT, gmode, errorcode;
//
//    /* グラフィックスライブラリに追加されたドライバを登録 */
//    errorcode = registerbgidriver(PC98_driver);
//
//    /* 登録エラーの表示 */
//    if (errorcode < 0)
//    {
//       printf("Graphics error: %s\n", grapherrormsg(errorcode));
//       printf("Press any key to halt:");
//       getch();
//       exit(1); /* エラーとして終了 */
//    }
//
//    /* グラフィックスシステムの初期化 */
//    initgraph(&gdriver, &gmode, "");
//
//    /* 初期化の結果を取得 */
//    errorcode = graphresult();
//    if (errorcode != grOk)  /* エラーが発生したか？ */
//    {
//       printf("Graphics error: %s\n", grapherrormsg(errorcode));
//       printf("Press any key to halt:");
//       getch();
//       exit(1); /* エラーとして終了 */
//    }
//
//	/* ラインの描画 */
//    line(0, 0, getmaxx(), getmaxy());
//
//	/* 終了 */
//    getch();
//    closegraph();
//    return 0;
// }

// +---------------------------+
// | getdefaultpalette,        |
// | getpalette, setallpalette |<GRAPHICS.H>
// +---------------------------+
//  ･ getdefaultpalette はパレット定義の構造体を返します。
//  ･ getpalette は現在のパレットに関する情報を取得します。
//  ･ setallpalette は全てのパレット色を，指定の色に変更します。
//
// 宣言:
//  ･ struct palettetype *far getdefaultpalette(void);
//  ･ void far getpalette(struct palettetype far *palette);
//  ･ void far setallpalette(struct palettetype far *palette);
//
// 説明:
// ･ getdefaultpalette は，initgraph の呼び出し
// 中にドライバが初期化したパレットを持っている
// palettetype 構造体を見つけます。
//
// ･ getpalette は，現在のパレットの大きさと色に
// 関する情報を palette が指す palettetype 型の
// 構造体に格納します。IBM-8514 ドライバでは使用
// できません。
//
// ･ setallpalette は，現在のパレットを，palette が
// 指す palettetype 構造体の内容に従ってセット
// します。
//   EGA/VGA のパレットの色は，setallpalette で部分的
//　にも全体的にも変えられます。
//
//DOS/V では，使用できる色は，現在のグラフィックスドライバとグラフィックスモー
//ドによります。setallpalette は，IBM-8514 ドライバでは使用できません。
//
//パレットを変更すると，ただちに画面に反映されます。パレット色が変更されるたび
//に，画面上に表示される色はすべて新しい色に変更されます。
//
// 戻り値:
//  ･ getdefaultpalette は，現在のドライバが初期化された
//    ときにそのドライバがセットした，デフォルトパレットを
//    指すポインタを返します。
//  ･ getpalette と setallpalette には戻り値はありません。
//
//setallpalette に正しくない入力が与えられると，graphresult は -11 (grError)
//を返し，パレットは変更されません。
//
// 移植性:
// + DOS + UNIX + Windows + ANSI C + C++ のみ + PC-98 & DOS/V +
// |     |      |         |        |          |      ○       |
// +-----+------+---------+--------+----------+---------------+
//
// 参照:
//   getbkcolor
//   getcolor
//   getmaxcolor
//   getpalettesize
//   graphresult
//   setbkcolor
//   setcolor
//
// 例:
//   getdefaultpalette のサンプル
//   getpalette のサンプル
//   setallpalette のサンプル

// +-------------+
// | cleardevice |                  <GRAPHICS.H>
// +-------------+
// グラフィックス画面をクリアします。
//
// 宣言:  void far cleardevice(void);
//
// 説明:
//cleardevice は，グラフィックス画面全体をクリアして（つまり，バックグラウンド
//色で塗りつぶして），CP（現在位置）をホームポジション（0，0）に移します。
//
// 戻り値:  なし
//
// 移植性:
// + DOS + UNIX + Windows + ANSI C + C++ のみ + PC-98 & DOS/V +
// |     |      |         |        |          |      ○       |
// +-----+------+---------+--------+----------+---------------+
//
// 参照:
//   clearviewport
//
// 例:
//
// #include <graphics.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <conio.h>
//
//	int main(void)
//	{
//	/* 自動検出を要求 */
//	int gdriver = DETECT, gmode, errorcode;
//	int midx, midy;
//
//	/* グラフィックスシステムの初期化 */
//	initgraph(&gdriver, &gmode, "");
//
//	/* 初期化の結果を取得 */
//	errorcode = graphresult();
//	if (errorcode != grOk)  /* エラーが発生したか？ */
//	{
//		printf("Graphics error: %s\n", grapherrormsg(errorcode));
//		printf("Press any key to halt:");
//		getch();
//		exit(1); /* エラーとして終了 */
//	}
//
//	midx = getmaxx() / 2;
//	midy = getmaxy() / 2;
//	setcolor(getmaxcolor());
//
//	/* メッセージのセンタリング */
//	settextjustify(CENTER_TEXT, CENTER_TEXT);
//
//    /* 画面に文字列を出力 */
//    outtextxy(midx, midy, "press any key to clear the screen:");
//
//    /* キー入力待ち */
//    getch();
//
//    /* 画面のクリア */
//    cleardevice();
//
//    /* もう一度，文字列を出力 */
//    outtextxy(midx, midy, "press any key to quit:");
//
//    /* 終了 */
//    getch();
//    closegraph();
//    return 0;
// }

//
// graphics_drivers              <GRAPHICS.H>
//------------------
//
//列挙型: グラフィックスドライバ。
//
// 定数     |   値
//----------+---------------------------------------------------------
// DETECT   |   0 (自動検出の要求)
// CGA      |   1
// MCGA     |   2
// EGA      |   3
// EGA64    |   4
// EGAMONO  |   5
// IBM8514  |   6
// HERCMONO |   7
// ATT400   |   8
// VGA      |   9
// PC3270   |  10
// DOSVGA   |  11
// PC98     |  12 (PC-9801 ノーマルモードグラフィックス)
// PC98HI   |  13 (PC-9801 ハイレゾリューションモードグラフィックス)
//
//参照:
//  graphics_modes
//  initgraph

// +-------------+
// | cleardevice |                  <GRAPHICS.H>
// +-------------+
// グラフィックス画面をクリアします。
//
// 宣言:  void far cleardevice(void);
//
// 説明:
//cleardevice は，グラフィックス画面全体をクリアして（つまり，バックグラウンド
//色で塗りつぶして），CP（現在位置）をホームポジション（0，0）に移します。
//
// 戻り値:  なし
//
// 移植性:
// + DOS + UNIX + Windows + ANSI C + C++ のみ + PC-98 & DOS/V +
// |     |      |         |        |          |      ○       |
// +-----+------+---------+--------+----------+---------------+
//
// 参照:
//   clearviewport
//
// 例:
//
// #include <graphics.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <conio.h>
//
// int main(void)
// {
//    /* 自動検出を要求 */
//    int gdriver = DETECT, gmode, errorcode;
//    int midx, midy;
//
//    /* グラフィックスシステムの初期化 */
//    initgraph(&gdriver, &gmode, "");
//
//	/* 初期化の結果を取得 */
//    errorcode = graphresult();
//    if (errorcode != grOk)  /* エラーが発生したか？ */
//    {
//       printf("Graphics error: %s\n", grapherrormsg(errorcode));
//       printf("Press any key to halt:");
//       getch();
//       exit(1); /* エラーとして終了 */
//    }
//
//    midx = getmaxx() / 2;
//    midy = getmaxy() / 2;
//    setcolor(getmaxcolor());
//
//    /* メッセージのセンタリング */
//    settextjustify(CENTER_TEXT, CENTER_TEXT);
//
//    /* 画面に文字列を出力 */
//    outtextxy(midx, midy, "press any key to clear the screen:");
//
//    /* キー入力待ち */
//    getch();
//
//    /* 画面のクリア */
//    cleardevice();
//
//    /* もう一度，文字列を出力 */
//    outtextxy(midx, midy, "press any key to quit:");
//
//    /* 終了 */
//    getch();
//    closegraph();
//    return 0;
// }

//master.lib
//------------------------------------------------------------------------
//□ graph_start, vga4_start - 16色グラフィック画面一括初期設定
//
//C:      void graph_start(void);
//C:      int vga4_start(int videomode, int xdots, int ydots);
//
//        ------------------------------------------98N 98H AT DOS-
//        graph_start                                Ｖ  × ＊
//        ------------------------------------------<grpstart.asm>-
//        vga4_start                                 ×  × ○
//        ------------------------------------------<vgcstart.asm>-
//
//                ● <98>開始のために、以下の処理を行います。
//                   graph_plasma
//                   palette_init
//                   graph_showpage(0)
//                   graph_accesspage(0)
//                   graph_400line
//                   graph_clear
//                   graph_show
//
//                   <AT>現在のビデオモードを記録し、ビデオモードを
//                   変更、グラフィック画面描画に関する変数を設定し、
//                   grc_setclip, dac_initを呼び出します。
//
//                → 1  成功
//                   0  ビデオモード変更に失敗
//
//                ○ <AT>現在までのビデオモードを内部に記録します。
//                ○ <AT>ビデオモード変更に成功した場合、設定する変
//                   数などは以下の通りです。
//                   graph_VramSeg   0xa000
//                   graph_VramWidth xdots/8         横一列のバイト
//                                                   数
//                   graph_VramWords xdots*ydots/16  全体のワード数
//                   graph_VramLines ydots           縦ドット数
//                   graph_VramZoom  0または1        ビデオモード
//                                                   0x0e(640x200)
//                                                   に指定した場合
//                                                   のみ、 1になり
//                                                   ます。
//                   grc_setclip(0,0,xdots-1,ydots-1)
//                   VTextState      0x8000をOR      グラフィックモ
//                                                   ード
//
//                例:
//                   ・通常の640x480x16colorの場合
//                       vga4_start(0x12,640,480);
//                   ・VESAの800x600x16colorの場合
//                       vga4_start(0x6a,800,600);
//                   ・640x200x16colorにしたい場合
//                       vga4_start(0x0e,640,200);
//                   ・全画面の640x400x16colorにしたい場合
//                       vga4_start(0x0e,640,400),vga_vzoom_off();
//
//                ○ 参照:  graph_end(), graph_enter(),
//                          graph_leave(), vgc_start()
//------------------------------------------------------------------------
//□ palette_init, dac_init - パレット変数の初期化
//
//C:      void palette_init(void);
//C:      void dac_init(void);
//
//        ------------------------------------------98N 98H AT DOS-
//        palette_init                               Ｖ     ＊
//        -------------------------------------------<palinit.asm>-
//        dac_init                                   ×  × ○
//        -------------------------------------------<dacinit.asm>-
//
//                ● アナログパレットを使用する準備をします。
//                   <98>   Palettes に、PalettesInit  の内容を複写
//                          し、graph_analog()を実行し、PaletteTone
//                          を  100にした後、palette_show()を実行し
//                          ます。
//                   <AT>   Palettesに PalettesInit の内容を設定し、
//                          トーンを100%にし、dac_showを実行します。
//                          また、パレットコード16を黒にし、 ボーダ
//                          ーカラーを16にします。
//
//------------------------------------------------------------------------
//□ palette_set - パレットを一つ設定する
//
//C:      void palette_set( int num, int r, int g, int b );  マクロ
//
//        ------------------------------------------98N 98H AT DOS-
//        palette_set
//        -----------------------------------------------------<->-
//
//                ● パレットに値を一つ設定します。表示は
//                   palette_showを使用してください。
//------------------------------------------------------------------------
//□ key_beep_off - キーバッファフル音の禁止
//
//C:      void key_beep_off(void);
//
//        ------------------------------------------98N 98H AT DOS-
//        key_beep_off                               ○  × ×
//        -------------------------------------------<keybeep.asm>-
//
//                ● BIOSでキーバッファが満杯の時にさらにキーが押さ
//                   れた時に鳴らす音を禁止(鳴らなく)します。
//                   通常は、鳴ります。
//
//------------------------------------------------------------------------
//□ key_beep_on - キーバッファフル音の許可
//
//C:      void key_beep_on(void);
//
//        ------------------------------------------98N 98H AT DOS-
//        key_beep_on                                ○  × ×
//        -------------------------------------------<keybeep.asm>-
//
//                ● BIOSでキーバッファが満杯の時にさらにキーが押さ
//                   れた時に鳴らす音を許可します。
//                   通常は、鳴ります。
//------------------------------------------------------------------------
//□ dos_setbreak - ブレーク検査フラグの読み取りと設定
//
//C:      int dos_setbreak( int breakon );
//
//        ------------------------------------------98N 98H AT DOS-
//        dos_setbreak                                         ５
//        -------------------------------------------<dosvect.asm>-
//
//                ● DOSファンクションコール呼び出し時点で   CTRL+C
//                   (STOP, Ctrl+Break)が押されていたらプログラムを
//                   強制終了させる機能の制御をします。
//
//                ← breakon   1  ブレーク検査をする
//                             0  ブレーク検査をしない
//
//                → 以前に設定されていたフラグ



GRAPHIC::~GRAPHIC ()
{
	setallpalette (&first_pal); //BGI: retrive the first colors (preserved)
	closegraph (); //BGI
	text_clear (); //Master.lib txtCls (); //gr.lib
	//pc98fkeyon ();/* Enables function keys*/
	key_beep_off (); //Master.lib EnableKeyBeep (); ///gr.lib
	dos_setbreak (1); //Master.lib EnableCtrlC (); //gr.lib
	printf ("\nThe TCC Graphic safely terminated.\n");
	graph_end (); //Master.lib grEnd (); //gr.lib
	printf ("The Master.lib Graphic safely terminated.\n");
}
//gr.lib
//----------------------------------------------------------------
//void    txtCls( void );
//    テキスト画面をクリアする。 (' '(space)で埋めつくす)
//----------------------------------------------------------------
//void    EnableKeyBeep( void );
//    DisableKeyBeep() で変更した BIOS制御フラグを元に戻す。
//    DisableKeyBeep() を実行した場合、 終了時には必ずこの関数を実
//    行すること。
//----------------------------------------------------------------
//void    EnableCtrlC( void );
//    DisableCtrlC() で書き換えた割り込みベクタを元に戻す。
//    DisableCtrlC() が実行されていなかった場合は、何もしない。
//    ※DisableCtrlC()   を実行した場合、   プログラム終了前に必ず
//      EnableCtrlC() を実行すること。
//----------------------------------------------------------------
//void    grEnd( void );
//    プログラムの終了時に使用する。
//    アナログパレット、デジタルパレット、 アクティブ/ビジュアルペ
//    ージその他を初期化する。

// +------------+
// | closegraph |                   <GRAPHICS.H>
// +------------+
// グラフィックスシステムの使用を終了します。
//
// 宣言:  void far closegraph(void);
//
// 説明:
//closegraph は，グラフィックスシステムが割り当てたすべてのメモリを解放しま
//す。
//
//そして，画面を initgraph を呼び出す前のモードに戻します。
//
//（グラフィックスシステムは，_graphfreemem を呼び出して，ドライバ，フォント，
//および内部バッファなどのメモリを解放します。）
//
// 戻り値:  なし
//
// 移植性:
// + DOS + UNIX + Windows + ANSI C + C++ のみ + PC-98 & DOS/V +
// |     |      |         |        |          |      ○       |
// +-----+------+---------+--------+----------+---------------+
//
// 参照:
//   initgraph
//   setgraphbufsize
//
// 例:
//
// #include <graphics.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <conio.h>
//
// int main(void)
// {
//    /* 自動検出を要求 */
//    int gdriver = DETECT, gmode, errorcode;
//    int x, y;
//
//    /* グラフィックスシステムの初期化 */
//    initgraph(&gdriver, &gmode, "");
//
//	/* 初期化の結果を取得 */
//    errorcode = graphresult();
//
//    if (errorcode != grOk)  /* エラーが発生したか？ */
//    {
//       printf("Graphics error: %s\n", grapherrormsg(errorcode));
//       printf("Press any key to halt:");
//       getch();
//       exit(1); /* エラーとして終了 */
//    }
//
//    x = getmaxx() / 2;
//    y = getmaxy() / 2;
//
//    /* 文字列の出力 */
//    settextjustify(CENTER_TEXT, CENTER_TEXT);
//    outtextxy(x, y, "Press a key to close the graphics system:");
//
//    /* キー入力待ち */
//    getch();
//
//    /* グラフィックスシステムの終了 */
//    closegraph();
//
//    printf("We're now back in text mode.\n");
//    printf("Press any key to halt:");
//    getch();
//    return 0;
// }

//master.lib
//------------------------------------------------------------------------
//□ text_clear, vtext_clear - テキスト画面の消去
//
//C:      void text_clear(void);
//C:      void vtext_clear(void);
//
//        ------------------------------------------98N 98H AT DOS-
//        text_clear                                        ＊ ○
//        -------------------------------------------<txclear.asm>-
//        vtext_clear                                ×  × ○
//        -------------------------------------------<vtclear.asm>-
//
//                ● テキスト画面を消去し、カーソル位置を左上に移動
//                   します。
//                   <98>高速コンソール出力(INT 29h)に、ANSI  ESCシ
//                   ーケンスの  ESC [2J を出力することによりテキス
//                   ト画面を消去します。
//                   <AT>テキスト画面を消去します。グラフィックモー
//                   ドになっていると何も行いません。
//
//                ○ <AT>事前に vtext_start(),  get_machine()が実行
//                   されている必要があります
//                ○ <AT>vtext_refresh_on()/vtext_refresh_off()に影
//                   響を受けます
//
//------------------------------------------------------------------------
//□ text_cursor_hide, vtext_cursor_hide - カーソルを消す
//
//C:      void text_cursor_hide(void);
//C:      void vtext_cursor_hide(void);                      マクロ
//
//        ------------------------------------------98N 98H AT DOS-
//        text_cursor_hide                                  ＊ ○
//        ---------------------------------------------<txesc.asm>-
//        vtext_cursor_hide                          ×  × ○
//        -----------------------------------------------------<->-
//
//                ● テキストカーソルを消します。
//
//                ○ <98> int  29h(高速コンソール出力)にESCシーケン
//                   スを出力します。
//                ○ <AT> BIOSを使います。
//
//                ○ 参照:  text_cursor_show(), text_cursor_shown(),
//                          vtext_cursor_show(),
//                          vtext_cursor_shown()
//
//------------------------------------------------------------------------
//□ _text_cursor_off - BIOSを使用してカーソルを消す
//
//C:      void _text_cursor_off(void);
//
//        ------------------------------------------98N 98H AT DOS-
//        _text_cursor_off                           ○     ＊
//        ------------------------------------------<txcursor.asm>-
//
//                ● BIOS ( int 18h)  を利用してカーソル表示を  off
//                   にします。
//
//                ★ text_cursor_hide()などはint  29hを使用している
//                   ので  MEGDOSでは使えない、という場合にも使えま
//                   す。
//
//------------------------------------------------------------------------
//□ _text_cursor_on - BIOSを使用してカーソルを表示
//
//C:      void _text_cursor_on(void);
//
//        ------------------------------------------98N 98H AT DOS-
//        _text_cursor_on                            ○     ＊
//        ------------------------------------------<txcursor.asm>-
//
//                ● BIOS ( int 18h) を利用してカーソル表示を on に
//                   します。
//
//
//------------------------------------------------------------------------
//□ graph_end, vga4_end - グラフィック画面一括終了処理
//
//C:      void graph_end(void);
//C:      void vga4_end(void);
//
//        ------------------------------------------98N 98H AT DOS-
//        graph_end                                  Ｖ  × ＊
//        --------------------------------------------<grpend.asm>-
//        vga4_end                                   ×  × ○
//        ------------------------------------------<vgcstart.asm>-
//
//                ● <98>終了のために、以下の処理を行います。
//                   graph_hide
//                   graph_400line
//                   graph_clear
//
//                   <AT>ビデオモードを  vga4_startで記録した値に設
//                   定します。
//                   また、VTextState変数を 0x7fffでANDします。


void GRAPHIC::_switch (char *a)
{
	if (stricmp (a, "GRLIB") == 0)
	{
		palette_set (BLACK,     0, 0, 0);
		// master.lib grPal1 (BLACK, 0, 0, 0);//gr.lib
		palette_set (BLUE,      0, 0, 7);
		// master.lib grPal1 (BLUE, 0, 0,7);
		palette_set (GREEN,     7, 0, 0);
		// master.lib grPal1 (GREEN, 7, 0, 0);
		palette_set (CYAN,      7, 7, 0);
		// master.lib grPal1 (CYAN, 7, 7, 0);
		palette_set (RED,       0, 7, 0);
		// master.lib grPal1 (RED, 0, 7, 0);
		palette_set (MAGENTA,   0, 7, 7);
		// master.lib grPal1 (MAGENTA, 0, 7, 7);
		palette_set (BROWN,     7, 0, 7);
		// master.lib grPal1 (BROWN, 7, 0, 7);
		palette_set (LIGHTGRAY, 7, 7, 7);
		// master.lib grPal1 (LIGHTGRAY, 7, 7, 7);
		palette_set (DARKGRAY,  3, 3, 3);
		// master.lib grPal1 (DARKGRAY, 3, 3, 3);
		palette_set (LIGHTBLUE, 0, 0, 15);
		// master.lib grPal1 (LIGHTBLUE, 0, 0, 15);
		palette_set (LIGHTGREEN,15,0, 0);
		// master.lib grPal1 (LIGHTGREEN, 15, 0, 0);
		palette_set (LIGHTCYAN, 0,15,15);
		// master.lib grPal1 (LIGHTCYAN, 0, 15, 15);
		palette_set (LIGHTRED, 0, 15, 0);
		// master.lib grPal1 (LIGHTRED, 0, 15, 0);
		palette_set (LIGHTMAGENTA,15,0,15);
		// master.lib grPal1 (LIGHTMAGENTA, 15,0, 15);
		palette_set (YELLOW,  15, 15, 0);
		// master.lib grPal1 (YELLOW, 15, 15, 0);
		palette_set (WHITE,   15, 15,15);
		// master.lib grPal1 (WHITE, 15, 15, 15);

		//grPal1 (BLACK, 0, 0, 0);
		//grPal1 (BLUE, 0, 0, 7);
		//grPal1 (GREEN, 0, 7, 0);
		//grPal1 (CYAN, 7, 7, 0);
		//grPal1 (RED, 7, 0, 0);
		//grPal1 (MAGENTA, 7, 0, 7);
		//grPal1 (BROWN, 0, 7, 7);
		//grPal1 (LIGHTGRAY, 7, 7, 7);
		//grPal1 (DARKGRAY, 3, 3, 3);
		//grPal1 (LIGHTBLUE, 0, 0, 15);
		//grPal1 (LIGHTGREEN, 0, 15, 0);
		//grPal1 (LIGHTCYAN, 15, 0, 15);
		//grPal1 (LIGHTRED, 15, 0, 0);
		//grPal1 (LIGHTMAGENTA, 0, 15, 15);
		//grPal1 (YELLOW, 15, 15, 0);
		//grPal1 (WHITE, 15, 15, 15);
	}
	else
	{
		if (stricmp (a, "TC++") == 0)
		{
	        	setallpalette (&pal); //BGI
		}
	}
}

void GRAPHIC::_circle (int x, int y, int xradius, int yradius, int color, int stangle, int endangle)
{
	_switch ("TC++");
	int a;
	a = getcolor ();
	setcolor (color);
	ellipse (x, y, stangle, endangle, xradius, yradius);
	setcolor (a);
}

void GRAPHIC::_line (int x1, int y1, int x2, int y2, int color)
{
	_switch ("TC++");
	int a;
	a = getcolor ();
	setcolor (color);
	line (x1, y1, x2, y2);
	setcolor (a);
}
// +--------------------+
// | getcolor, setcolor |           <GRAPHICS.H>
// +--------------------+
//  ･ getcolor returns the current drawing color
//  ･ setcolor は現在の描画色を設定します。
//
// 宣言:
//  ･ int far getcolor(void);
//  ･ void far setcolor(int color);
//
// 説明:
//getcolor は，現在の描画色を返します。
//
//setcolor は，現在の描画色を color にセットします。color には，0 から
//getmaxcolor までの範囲でセットできます。
//
//現在の描画色は，ラインなどが描かれるときにピクセルにセットされる値です。
//
//色番号あるいは同等のシンボル名を setcolor に渡して，描画色を選択します。たと
//えば CGAC0 モードでは，パレットには背景色，明るい緑色，明るい赤，黄色の４色
//があります。このモードで黄色の描画色を選択するには，setcolor(3) もしくは
//setcolor(CGA_YELLOW) とします。
//
// 戻り値:
//  ･ getcolor は，現在の描画色を返します。
//  ･ setcolor には戻り値はありません。
//
// 移植性:
// + DOS + UNIX + Windows + ANSI C + C++ のみ + PC-98 & DOS/V +
// |     |      |         |        |          |      ○       |
// +-----+------+---------+--------+----------+---------------+
//
// 参照:
//   getbkcolor
//   getmaxcolor
//   getpalette
//   graphresult
//   setallpalette
//   setbkcolor
//   setpalette
//
// 例:
//   getcolor のサンプル
//   setcolor のサンプル


void GRAPHIC::_box (int x1, int y1, int x2, int y2, int color)
{
	_switch ("TC++");
	int a;
	a = getcolor ();
	setcolor (color);
	rectangle (x1, y1, x2, y2);
	setcolor (a);
}

void GRAPHIC::_box (int x1, int y1, int x2, int y2, int color1, int color2)
{
	_switch ("TC++");
	int a;
	a = getcolor ();
	setcolor (color1);
	rectangle (x1, y1, x2, y2);
	setfillstyle (SOLID_FILL, color2);
	floodfill (x1 + 1, y1 + 1, color1);
	setcolor (a);
}

void GRAPHIC::_paint (int x, int y, int color1, int color2)
{
	_switch ("TC++");
	int a;
	a = getcolor ();
	setfillstyle (SOLID_FILL, color1);
	setcolor (color2);
	floodfill (x, y, color2);
	setcolor (a);
}

void GRAPHIC::_clear (void)
{
	//cleardevice ();
}
// +-------------+
// | cleardevice |                  <GRAPHICS.H>
// +-------------+
// グラフィックス画面をクリアします。
//
// 宣言:  void far cleardevice(void);
//
// 説明:
//cleardevice は，グラフィックス画面全体をクリアして（つまり，バックグラウンド
//色で塗りつぶして），CP（現在位置）をホームポジション（0，0）に移します。
//
// 戻り値:  なし
//
// 移植性:
// + DOS + UNIX + Windows + ANSI C + C++ のみ + PC-98 & DOS/V +
// |     |      |         |        |          |      ○       |
// +-----+------+---------+--------+----------+---------------+
//
// 参照:
//   clearviewport
//
// 例:
//
// #include <graphics.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <conio.h>
//
// int main(void)
// {
//    /* 自動検出を要求 */
//    int gdriver = DETECT, gmode, errorcode;
//    int midx, midy;
//
//    /* グラフィックスシステムの初期化 */
//    initgraph(&gdriver, &gmode, "");
//
//    /* 初期化の結果を取得 */
//    errorcode = graphresult();
//    if (errorcode != grOk)  /* エラーが発生したか？ */
//    {
//       printf("Graphics error: %s\n", grapherrormsg(errorcode));
//       printf("Press any key to halt:");
//       getch();
//       exit(1); /* エラーとして終了 */
//    }
//
//    midx = getmaxx() / 2;
//    midy = getmaxy() / 2;
//    setcolor(getmaxcolor());
//
//    /* メッセージのセンタリング */
//    settextjustify(CENTER_TEXT, CENTER_TEXT);
//
//    /* 画面に文字列を出力 */
//    outtextxy(midx, midy, "press any key to clear the screen:");
//
//    /* キー入力待ち */
//    getch();
//
//    /* 画面のクリア */
//    cleardevice();
//
//    /* もう一度，文字列を出力 */
//    outtextxy(midx, midy, "press any key to quit:");
//
//    /* 終了 */
//    getch();
//    closegraph();
//    return 0;
// }

void GRAPHIC::__line (int x1, int y1, int x2, int y2, int color)
{
	_switch ("GRLIB");
	// gr.lib cline (x1, y1, x2, y2, color);
	//master.lib
	grcg_setcolor (GC_RMW, color);
	grcg_line (x1, y1, x2, y2);
}
//master.lib
//------------------------------------------------------------------------
//□ grcg_line, vgc_line - 直線描画
//
//C:      void grcg_line(int x1,int y1,int x2,int y2);
//C:      void vgc_line(int x1,int y1,int x2,int y2);
//
//        ------------------------------------------98N 98H AT DOS-
//        grcg_line                                  Ｖ  × ＊
//        -------------------------------------------<gc_line.asm>-
//        vgc_line                                   ×  × ○
//        -------------------------------------------<vgcline.asm>-
//
//                ● 直線を描画します。
//
//                ← x1,y1  第1頂点の座標
//                   x2,y2  第2頂点の座標
//
//                ○ grc_setclip範囲でクリッピングします。
//                ○ 色は、grcg_setcolor または vgc_setcolor で指定
//                   します。
//------------------------------------------------------------------------
//□ grcg_setcolor - GRCGのモードおよび色設定
//
//C:      void grcg_setcolor( int mode, int color );
//
//        ------------------------------------------98N 98H AT DOS-
//        grcg_setcolor                              Ｖ  × ＊
//        ------------------------------------------<gc_setco.asm>-
//
//                ● GRCGのモードレジスタに modeを設定し、 タイルレ
//                   ジスタに color に相当する単色を設定します。
//                   mode に設定する値は、 grcg_setmodeを参照してく
//                   ださい。
//
//                例: grcg_setcolor( GC_RMW|GC_BG,0 );
//                        青と緑のプレーンにアクセスする。
//                        タイルレジスタは全て 00h。


void GRAPHIC::__box (int x1, int y1, int x2, int y2, int color)
{
	_switch ("GRLIB");
	//gr.lib grRectangle (x1, y1, x2, y2, color);
	//master.lib
	grcg_setcolor (GC_RMW, color);
	grcg_line (x1, y1, x2, y1);
	grcg_line (x2, y1, x2, y2);
	grcg_line (x2, y2, x1, y2);
	grcg_line (x1, y2, x1, y1);
}
//gr.lib
//----------------------------------------------------------------
//void    grRectangle( int x1, int y1, int x2, int y2, int color );
//    左上座標が(x1,y1), 右下が(x2,y2) の矩形枠を描く。　 内部を塗
//    りつぶさない grBox()
//
//----------------------------------------------------------------
//void    grBox( int x1,int y1,int x2,int y2,int color );
//    左上座標が(x1,y1), 右下が(x2,y2) の矩形を描く。

//master.lib
//------------------------------------------------------------------------
//□ grcg_polygon_c, vgc_polygon_c - 凸多角形描画
//
//C:      void grcg_polygon_c( const Point * pts, int npoint );
//C:      void vgc_polygon_c( const Point * pts, int npoint );
//
//        ------------------------------------------98N 98H AT DOS-
//        grcg_polygon_c                             Ｖ  × ＊
//        ------------------------------------------<gc_polgc.asm>-
//        vgc_polygon_c                              ×  × ○
//        ------------------------------------------<vgcpolgc.asm>-
//
//                ● pts[]に座標リストを渡して凸多角形を描画します。
//
//                ← npoint  点の数を指定。(3以上)
//
//                ○ 色は、grcg_setcolor または vgc_setcolor で指定
//                   します。
//                ○ grc_setclip範囲でクリッピングします。
//                ○ grcg_polygon_cx と grc_clip_polygon_n の組み合
//                   せを利用した方が高速です。
//
//                ★ 凸多角形にならないデータを渡されると、ゼロ除算
//                   エラーが発生することがあります。

void GRAPHIC::__box (int x1, int y1, int x2, int y2, int color1, int color2)
{
	_switch ("GRLIB");
	//grcg_setcolor (GC_RMW, color2); //master.lib
	__box (x1, y1, x2, y2, color2);
	// grRectangle (x1, y1, x2, y2, color1); //gr.lib
	//grcg_boxfill (x1, y1, x2, y2);

	grcg_setcolor (GC_RMW, color1); //master.lib
	// grBox (x1 + 1, y1 + 1, x2 - 1, y2 - 1, color2); //gr.lib
	grcg_boxfill (x1 + 1, y1 + 1, x2 - 1, y2 - 1);
}
//master.lib
//------------------------------------------------------------------------
//□ grcg_boxfill, vgc_boxfill - 長方形描画
//
//C:      void grcg_boxfill(int x1,int y1,int x2,int y2);
//C:      void vgc_boxfill(int x1,int y1,int x2,int y2);
//
//        ------------------------------------------98N 98H AT DOS-
//        grcg_boxfill                               Ｖ  × ＊
//        ------------------------------------------<gc_boxfi.asm>-
//        vgc_boxfill                                ×  × ○
//        ------------------------------------------<vgcboxfi.asm>-
//
//                ● 長方形を塗り潰します。
//
//                ← x1,y1  第1頂点の座標
//                   x2,y2  第2頂点の座標
//
//                ○ grc_setclip範囲でクリッピングします。
//                ○ 色は、grcg_setcolor または vgc_setcolor で指定
//                   します。

void GRAPHIC::__txtclear (void)
{
	text_clear (); //Master.lib txtCls (); //gr.lib
	//txtCls ();
}

void GRAPHIC::__txtclear (int a)
{
	gotoxy (1, a);
	printf ("          ");
	printf ("          ");
	printf ("          ");
	printf ("          ");
	printf ("          ");
	printf ("          ");
	printf ("          ");
	printf ("          ");
	//txtClearLine (a);
}

void GRAPHIC::_quick_key (int *a, int *b)
{
	int save_cbrk;
	int scan/*, code*/;
	unsigned c, shift;

	/* DOSファンクションとキーBIOSを併用する場合は，*/
	/* BREAKチェックをオフにすること */
	save_cbrk = getcbrk ();
	setcbrk (0);
	//c = pc98key (5);
	//scan = (unsigned char) (c >> 8);
	/*code = (unsigned char) c;*/
	//shift = (unsigned char) pc98key(2);
	setcbrk (save_cbrk);

	*a = scan;
	*b = (int) shift;
}

void GRAPHIC::_key (int *a, int *b)
{
	int save_cbrk;
	int scan/*, code*/;
	unsigned c, shift;

   /* DOSファンクションとキーBIOSを併用する場合は，*/
   /* BREAKチェックをオフにすること */
	save_cbrk = getcbrk ();
	setcbrk (0);
	//c = pc98key (0);
	//scan = (unsigned char) (c >> 8);
	/*code = (unsigned char) c;*/
	//shift = (unsigned char) pc98key (2);
	setcbrk (save_cbrk);

	*a = scan;
	*b = (int) shift;
}

void GRAPHIC::_keyclear (void)
{
	int a, b;
	_quick_key (&a, &b);
	_quick_key (&a, &b);
	_quick_key (&a, &b);
	_quick_key (&a, &b);
	_quick_key (&a, &b);

	for (;a != 0;){_quick_key (&a, &b);}
}

void GRAPHIC::_key (unsigned key [120])
{
//グループ  b0      b1      b2      b3      b4      b5      b6      b7
//
//   ０     ESC     1       2       3       4       5       6       7
//   １     8       9       0       -       ^       \       BS      TAB
//   ２     Q       W       E       R       T       Y       U       I
//   ３     O       P       ?       [       ﾘﾀｰﾝ    A       S       D
//   ４     F       G       H       J       K       L       ;       :
//   ５     ]       Z       X       C       V       B       N       M
//   ６     ,       .       /       _       ｽﾍﾟｰｽ   XFER    ROLLUP  ROLLDOWN
//   ７     INS     DEL     ↑      ←      →      ↓      HOMECLR HELP
//   ８     -       /       7       8       9       *       4       5
//   ９     6       +       1       2       3       =       0       ,
//   Ａ     .       NFER
//   Ｂ
//   Ｃ     [STOP]  [COPY]  [f･1]   [f･2]   [f･3]   [f･4]   [f･5]   [f･6]
//   Ｄ     [f･7]   [f･8]   [f･9]   [f･10]
//   Ｅ     [SHIFT] [CAPS]  [ｶﾅ]    [GRPH]  [CTRL]

	unsigned key_0 = pc98key (4, 0x00);
	unsigned key_1 = pc98key (4, 0x01);
	unsigned key_2 = pc98key (4, 0x02);
	unsigned key_3 = pc98key (4, 0x03);
	unsigned key_4 = pc98key (4, 0x04);
	unsigned key_5 = pc98key (4, 0x05);
	unsigned key_6 = pc98key (4, 0x06);
	unsigned key_7 = pc98key (4, 0x07);
	unsigned key_8 = pc98key (4, 0x08);
	unsigned key_9 = pc98key (4, 0x09);
	unsigned key_a = pc98key (4, 0x0a);
	unsigned key_c = pc98key (4, 0x0c);
	unsigned key_d = pc98key (4, 0x0d);
	unsigned key_e = pc98key (4, 0x0e);

	key [ES]         = rotate (key_0, 1);
	key [KEY_1]      = rotate (key_0, 2);
	key [BS]         = rotate (key_1, 7);
	key [CR]         = rotate (key_3, 5);
	key [KEY_A]      = rotate (key_3, 6);
	key [KEY_S]      = rotate (key_3, 7);
	key [KEY_D]      = rotate (key_3, 8);
	key [KEY_L]      = rotate (key_4, 6);
	key [SEMI_C]     = rotate (key_4, 7);
	key [COLON]      = rotate (key_4, 8);
	key [KEY_X]      = rotate (key_5, 3);
	key [SLASH]      = rotate (key_6, 3);
	key [SPACE]      = rotate (key_6, 5);
	key [HIDARI]     = rotate (key_7, 4);
	key [MIGI]       = rotate (key_7, 5);
	key [SITA]       = rotate (key_7, 6);
	key [HOME]       = rotate (key_7, 7);
	// key [HELP]       = rotate (key_7, 8); // obsolete pc98 keyboard.
	key [TEN_4]      = rotate (key_8, 7);
	key [TEN_5]      = rotate (key_8, 8);
	key [TEN_6]      = rotate (key_9, 1);
	key [TEN_2]      = rotate (key_9, 4);
	key [F1]         = rotate (key_c, 3); // obsolete pc98 keyboard. -> Function 1 key.
}
// +---------+
// | pc98key |             <PC98.H>
// +---------+
// PC-9801 のキーボード BIOS を制御します。
//
// 宣言:
//  cmd が 4以外のとき: unsigned pc98key(int cmd)
//
//  cmd が 4のとき: unsigned pc98key(int cmd, int group);
//
// 説明:
//pc98key は，PC9801 のキーボード BIOS（INT 18H）を呼び出します。
//
//cmd = 0; キーデータの入力(入力待ちあり)。
//   戻り値の上位バイトにスキャンコード，下位
//   バイトに内部コードを返します。
//
//cmd = 1; キーデータの非破壊入力(入力待ちなし)。
//   戻り値の上位バイトにスキャンコード，下位
//   バイトに内部コードを返します。読み込まれた
//   データはキーバッファに残ります。
//
//cmd = 2; シフトキーステータスの読み込み。
//   返される値の各ビットがシフトキーの押下状態を
//   表わします。キーが押されていれば 1 に，そう
//   でなければ 0 になります。
//
//   ビット| 意味
//   ------+-------
//     0   | SHIFT
//     1   | CAPS
//     2   | カナ
//     3   | Alt
//     4   | CTRL
//
//cmd = 3; キーボードを初期化します。
//
//cmd = 4; キー入力ステータスの読み込み。
//   group に与えられたキーコードグループの押下
//   状態を返します。キーが押されていればその
//   ビットは 1 に，そうでなければ 0 になります。
//
//   グループ| b0      b1      b2      b3      b4      b5      b6       b7
//   --------+----------------------------------------------------------------
//      0    | ESC     1       2       3       4       5       6        7
//      1    | 8       9       0       -       ^       \       BS       TAB
//      2    | Q       W       E       R       T       Y       U        I
//      3    | O       P       ~       [       ﾘﾀｰﾝ    A       S        D
//      4    | F       G       H       J       K       L       ;        :
//      5    | ]       Z       X       C       V       B       N        M
//      6    | ,       .       /       _       ｽﾍﾟｰｽ   XFER    PageDown PageUp
//      7    | INS     DEL     ↑      ←      →      ↓      Home     End
//      8    | -       /       7       8       9       *       4        5
//      9    | 6       +       1       2       3       =       0        ,
//      A    | .       NFER
//      B    |
//      C    | [STOP]  [COPY]  [f･1]   [f･2]   [f･3]   [f･4]   [f･5]   [f･6]
//      D    | [f･7]   [f･8]   [f･9]   [f･10]
//      E    | [SHIFT] [CAPS]  [ｶﾅ]    [Alt]  [CTRL]
//
//cmd = 5; キーデータの入力(入力待ちなし)。
//   cmd = 1; と同じですが，読み込まれたデータは
//   キーバッファに残りません。
//
//cmd = 6; バッファの初期化。
//   ハイレゾリューションモードのみ有効です。
//
//pc98key は,ハイレゾリューションモードのファンクション 7, 8, 9 をサポートして
//いません。これらのファンクションについては intr などを使用してください。引数
//の値は検査されません。pc98key の 2番目以降の引数についてはエラーチェックが行
//なわれません。引数が正しく与えられなかった場合の動作については未定義です。
//
// 移植性:
// + DOS + UNIX + Windows + ANSI C + C++ のみ + PC-98 + DOS/V +
// |     |      |         |        |          |  ○   |       |
// +-----+------+---------+--------+----------+-------+-------+
//
// 例:
//
// #include <stdio.h>
// #include <dos.h>
// #include <pc98.h>
//
// int save_cbrk;
//
// int main(void)
// {
//    int scan, code;
//    unsigned c, shift;
//
//    /* DOSファンクションとキーBIOSを併用する場合は，*/
//    /* BREAKチェックをオフにすること */
//    save_cbrk = getcbrk();
//    printf("ESC for abort.\n");
//    do {
//       c = pc98key(0);
//       scan = (unsigned char)(c >> 8);
//       code = (unsigned char)c;
//       shift = (unsigned char)pc98key(2);
//       printf("scan: %02X, code: %02X, shift: %02X\n", scan, code, shift);
//    } while (code != 27);
//    return 0;
// }

void GRAPHIC::_star (void)
{
	int a;
	int color;
	int x;
	int y;

	randomize();

	for (a = 1; a <= 900; a++)
	{
		color = random (7) + 7;
		x = random (640);
		y = random (400);
		//_line (x, y, x, y, color);
		//_line (x, y, x, y, color);
		__line (x, y, x, y, color);
	}
}

void GRAPHIC::_color (int a)/*テキストカラー*/
{
	putchar (ESC);

	switch (a)
	{
		case BLACK:
		printf ("[30;;30m");
        //printf ("Black\n");
		break;

		case BLUE:
		printf ("[18;;18m");
        //printf ("Blue\n");
		break;

		case RED:
		printf ("[17;;17m");
        //printf ("Red\n");
		break;

		case GREEN:
		printf ("[20;;20m");
        //printf ("Green\n");
		break;

		case LIGHTBLUE:
		printf ("[22;;22m");
        //printf ("Lightblue");
		break;

		case YELLOW:
		printf ("[21;;21m");
        //printf ("Yellow\n");
		break;

		case WHITE:
		printf ("[23;;23m");
        //printf ("White\n");
		break;
	}
}

void GRAPHIC::_copypage (int to_page)
{
//Master.lib 98
//	switch (m.machine)
//	{
//		case PC9801:
			graph_copy_page (to_page);	
//			break;
//
//		case PC_AT:
//			at_copypage (to_page);
//			break;
//
//		case FMR:
//			break;
//	}
}
//master.lib
//------------------------------------------------------------------------
//□ graph_copy_page - グラフィック画面の内容を他のページから複写する
//
//C:      int graph_copy_page( int to_page );
//
//        ------------------------------------------98N 98H AT DOS-
//        graph_copy_page                            ○  × ＊ ○
//        -------------------------------------------<grpcppg.asm>-
//
//                ● グラフィック画面の指定ページへ、反対のページの
//                   内容を転写し、アクセスページを  コピー先の頁に
//                   設定します。
//
//                ← to_page   コピー先の頁(0または1)
//
//                → 1  成功
//                   0  <98>失敗(smem_wget()によって 32KBのメモリが
//                      確保できなかった)
//
//                △MEMORY: <98>この関数の内部で、一時的に VRAM 1プ
//                  レーン分(640x400時、32KB)の領域を確保し、開放し
//                  ます。
//
//                AT欄:
//                        　IBM PS/55, PC/AT互換機,  J3100系で使え
//                        るかどうかを表します。
//                        　○ならば、いずれかの機種に対応していま
//                            す。詳しくは関数説明を読んで下さい。
//                        　×ならば、いずれにも対応していません。
//                        　Ｖならば、VGAが必要です。
//                        　＊ならば、MASTER98=0とマクロ定義してコ
//                            ンパイルした場合に、AT互換機用の相当
//                            する処理に自動的に置き変わります。
//                        　空欄ならば、 きっと動くでしょう(おいお
//                        い)


//# if !MASTER98
//#  define graph_accesspage(p) at98_accesspage(p)
//#  define graph_copy_page(to)	(graph_accesspage(0),\
//				vga4_byte_move(0,(to)?0:400,79,(to)?399:799,0,(to)?400:0),\
//								graph_accesspage(to),1)
//void MASTER_RET at98_accesspage( int page );

void GRAPHIC::_active (int page)
{
//Master.lib 98
//	switch (m.machine)
//	{
//		case PC9801:
			graph_accesspage (page);
//			break;
//
//		case PC_AT:
//			at98_accesspage (page);
//			break;
//
//		case FMR:
//			break;
//	}
}
//master.lib
//------------------------------------------------------------------------
//□ graph_accesspage, at98_accesspage - グラフィック画面CPUアクセスページ
//   設定
//
//C:      void graph_accesspage( int page );                 マクロ
//C:      void at98_accesspage( int page );
//
//        ------------------------------------------98N 98H AT DOS-
//        graph_accesspage                           ○  × ＊
//        -----------------------------------------------------<->-
//        at98_accesspage                            ×  × ○
//        ------------------------------------------<at98scrl.asm>-
//
//                ● CPUがアクセスするページを指定します。
//                   pageには、0 または 1 が指定できます。
//
//                ○ <AT> graph_VramSeg, ClipYT_seg  変数を操作しま
//                   す。


void GRAPHIC::_visual (int page)
{
//Master.lib 98
//	switch (m.machine)
//	{
//		case PC9801:
			graph_showpage (page);
//			break;
//
//		case PC_AT:
//			at98_showpage (page);
//			break;
//
//		case FMR:
//			break;
//	}
}
//master.lib
//------------------------------------------------------------------------
//□ graph_showpage, at98_showpage - グラフィック画面表示ページ設定
//
//C:      void graph_showpage( int page );                   マクロ
//C:      void at98_showpage( int page );
//
//        ------------------------------------------98N 98H AT DOS-
//        graph_showpage                             ○  × ＊
//        -----------------------------------------------------<->-
//        at98_showpage                              ×  × ○
//        ------------------------------------------<at98scrl.asm>-
//
//                ● 表示ページを指定します。
//                   pageには、0 または 1 が指定できます。
//
//                ○ <AT> graph_400line()などによって、640x400(以下)
//                   になっている場合専用です。ハードウェアスクロー
//                   ルによって、page切り替えをエミュレーションしま
//                   す。この際、 at98_scroll()によるスクロール設定
//                   を継承します。 また、VSYNC外に呼び出されると内
//                   部でVSYNC内になるまで待ってから作業しているの
//                   でかなり時間がかかります。

void GRAPHIC::_keyclear (unsigned key [120]) // Not dealing with an over clock.
{
	int a;

	for (a = 0; a <= 119; a++)
	{
		key [a] = 0;
	}

/*key [HOME] = 0;
key [HELP] = 0;
key [KORON] = 0;
key [KEY_D] = 0;
key [TEN_6] = 0;
key [MIGI] = 0;
key [KEY_L] = 0;
key [KEY_A] = 0;
key [TEN_4] = 0;
key [HIDARI] = 0;
key [SURUSH] = 0;
key [KEY_X] = 0;
key [TEN_2] = 0;
key [SITA] = 0;
key [SEMI_K] = 0;
key [KEY_S] = 0;
key [TEN_5] = 0;
key [CR] = 0;
key [BS] = 0;*/
}

void GRAPHIC::_keyclear (unsigned long lastkey [120]) // For dealing with an over clock.
{
	int a;

	for (a = 0; a <= 119; a++)
	{
		lastkey [a] = 0;
	}

/*key [HOME] = 0;
key [HELP] = 0;
key [KORON] = 0;
key [KEY_D] = 0;
key [TEN_6] = 0;
key [MIGI] = 0;
key [KEY_L] = 0;
key [KEY_A] = 0;
key [TEN_4] = 0;
key [HIDARI] = 0;
key [SURUSH] = 0;
key [KEY_X] = 0;
key [TEN_2] = 0;
key [SITA] = 0;
key [SEMI_K] = 0;
key [KEY_S] = 0;
key [TEN_5] = 0;
key [CR] = 0;
key [BS] = 0;*/
}
