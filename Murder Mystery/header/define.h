/*各種ライブラリインクルード*/
#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
// Windows ヘッダー ファイル
#include <windows.h>
// C ランタイム ヘッダー ファイル
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// C++のSTLを使えるようにする

#include <string>
#include <vector>
#include <list>
#include <utility>
#include <iostream>

#include<time.h>
#include<string>
#include<sstream>
#include<vector>
#include<map>

/*二次元配列のvectorを定義*/
using std::vector;
typedef vector< vector<int> > Dvector_i;
typedef vector< vector<std::string> > Dvector_s;

/*各種ヘッダインクルード*/
#include<DxLib.h>
#include"struct.h"
#include"user.h"
#include"mode.h"
#include"input.h"
#include"anime.h"
#include"graph.h"
#include"sound.h"
#include"menu.h"
#include"save.h"
#include"title.h"
#include"text.h"
#include"config_menu.h"
#include"config.h"
#include"secret.h"
#include"item.h"
#include"ending.h"
#include"page.h"
#include"function.h"
#include"scroll_bar.h"
#include"back_log.h"
#include"dialog.h"
#include"time.h"
#include"stdlib.h"


/*グローバル変数宣言 暇があれば消す*/
#ifdef GLOBAL_INSTANCE
RECT rect;					//ウィンドウサイズ格納
int  MenuFontHandle;		//メニューに使うフォントハンドル
int  TextFontHandle;		//テキスト全般に使うフォントハンドル
#else
extern RECT rect;
extern int MenuFontHandle;
extern int TextFontHandle;
#endif


/*----------
 | 定数定義 |
  ----------*/

//ウィンドウの縦横サイズ
#define windowX 1280
#define windowY 720

//フラグ数(save.h/struct.h/item.hは仕様上定数で書かれているのでフラグ数を増やす場合そこも書き換えること)
#define MAX_FLAG 32 
//アイテム数
#define MAX_ITEM 8
//メニュークラスで使う
namespace MENU{
	enum{IMAGE,TEXT,DATA};
	enum{COL,ROW};
	enum{GOSIC,MINTYO};
}

//マウスクラスで使う
namespace MOUSE{
	enum{LEFT,RIGHT};
}

//画像描画座標で使う
namespace GRAPH{
	 enum{X,Y};
}

//タイトル画面のメニューで使う
namespace TITLE{
 	enum{START=1,LOAD,SECRET,CONFIG,END};
}

//ゲーム画面のメニューで使う
namespace GAME_MENU{
	enum{SAVE,LOAD,AUTO,BACKLOG,CONFIG,ITEM};
}

//ページ一覧
namespace PAGE{
	enum{TITLE,GAME,END,SECRET};
 }

//モード一覧
namespace MODE{
	enum{MAIN,SAVE,LOAD,CONFIG,BACKLOG,SECRET,OTHER,END,ITEM};
}

//コンフィグで使う
namespace CONFIG{
	enum{INIT,SAVE,BACK};
}

//確認ダイアログで使う
namespace DIALOG{
	enum{YES,NO};
}

//ゲーム音楽コード
namespace GAME_BGM{
	enum{BATTLE,ERANDEL,TITLE,WARNING,STOP};
}

//ゲーム背景コード
namespace GAME_BACK{
	enum{CLASSROOM,ROUKA,GENKAN,SYOKUIN_MAE,SYOKUIN,HOKEN,RIKA,HOUSOU,ONGAKU,KAIGI,HIJOUKAIDAN,TAIIKUKAN,CHIKA,TUNNEL,JITAKU,KOKUBAN,BLACK};
}

//ゲームキャラクターコード
namespace GAME_CHAR{
	enum{AI,NOT};
}

//ゲームステータスコード
namespace GAME_STATUS {
	enum {STR,DEX,INT};
}

