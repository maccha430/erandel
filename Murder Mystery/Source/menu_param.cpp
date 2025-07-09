#define _CRT_SECURE_NO_WARNINGS
#include"../header/define.h"

/*メニューパラメータセット　―タイトル画面―*/
void SetMenuParam_Title(MenuArg_rec &MenuArg,bool SecretFlag){
	char TmpText[5][32] = {
		"最初から始める","続きから始める","？？？","設定","ばいばい"
	};
	
	if( SecretFlag == TRUE ) strcpy(TmpText[2],"おまけ");

	MenuArg.DrawX			= 950;
	MenuArg.DrawY			= 125;
	MenuArg.Interval		= 70;
	MenuArg.Width			= 30;
	MenuArg.Height			= 30;
	MenuArg.ListMin			= 1;
	MenuArg.ListMax			= 6;
	MenuArg.AtherNo			= 0;
	MenuArg.AlphaNo			= 50;
	MenuArg.DrawFlag		= MENU::TEXT;
	MenuArg.DirectionFlag	= MENU::COL;
	
	for( int i=0 ; i<5 ; i++ ) {
		strcpy(MenuArg.DrawText[i],TmpText[i]);
	}

	MenuArg.TextColor  = GetColor(0,0,0);
	MenuArg.FontFamily = MENU::GOSIC;

}

/*メニューパラメータセット　―ゲーム画面―*/
void SetMenuParam_GameRight(MenuArg_rec &MenuArg){
	char TmpText[6][32] = {
		"Save","Load","Auto","Backlog","Config","Items"
	};
	
	MenuArg.DrawX			= windowX-100;
	MenuArg.DrawY			= windowY-200;
	MenuArg.Interval		= 5;
	MenuArg.Width			= 28;
	MenuArg.Height			= 28;
	MenuArg.ListMin			= 0;
	MenuArg.ListMax			= 6;
	MenuArg.AtherNo			= 6;
	MenuArg.AlphaNo			= 100;
	MenuArg.DrawFlag		= MENU::TEXT;
	MenuArg.DirectionFlag	= MENU::COL;
	
	for( int i=0 ; i<6 ; i++ ) {
		strcpy(MenuArg.DrawText[i],TmpText[i]);
	}

	MenuArg.TextColor  = GetColor(255,255,255);
	MenuArg.FontFamily = MENU::GOSIC;

}
/*メニューパラメータセット　―選択肢―*/
 void SetMenuParam_Select(MenuArg_rec& MenuArg,vector<std::string> Option,int ListMin,int ListMax) {

	MenuArg.DrawX = 150;
	MenuArg.DrawY = 150;
	for (int i = 0; i < ListMax; i++) {
		strcpy(MenuArg.DrawText[i], Option[i].c_str());
	}
	MenuArg.Interval = 70;
	MenuArg.Width = 30;
	MenuArg.Height = 30;
	MenuArg.ListMin = ListMin;
	MenuArg.ListMax = ListMax;
	MenuArg.AtherNo = -1;
	MenuArg.AlphaNo = 50;
	MenuArg.DrawFlag = MENU::TEXT;
	MenuArg.DirectionFlag = MENU::COL;
	MenuArg.TextColor = GetColor(255, 255, 255);
	MenuArg.FontFamily = MENU::GOSIC;

}

 void SetMenuParam_SelectLR(MenuArg_rec& MenuArgLeft, MenuArg_rec& MenuArgRight,vector<std::string> Option, int ListMin, int ListMax) {
	 
	 int SplitNumber = ListMax-ListMin;
	 int j= 0;
	 if ((SplitNumber % 2) == 1)
	 {
		 SplitNumber++;
		 SplitNumber /= 2;
	 }
	 else { SplitNumber /= 2; }
	 MenuArgLeft.DrawX = 150;
	 MenuArgLeft.DrawY = 150;
	 MenuArgLeft.Interval = 70;
	 MenuArgLeft.Width = 30;
	 MenuArgLeft.Height = 30;
	 MenuArgLeft.ListMin = ListMin;
	 MenuArgLeft.ListMax = SplitNumber;
	 MenuArgLeft.AtherNo = -1;
	 MenuArgLeft.AlphaNo = 50;
	 MenuArgLeft.DrawFlag = MENU::TEXT;
	 MenuArgLeft.DirectionFlag = MENU::COL;
	 MenuArgLeft.TextColor = GetColor(255, 255, 255);
	 MenuArgLeft.FontFamily = MENU::GOSIC;

	 MenuArgRight.DrawX = 500;
	 MenuArgRight.DrawY = 150;
	 MenuArgRight.Interval = 70;
	 MenuArgRight.Width = 30;
	 MenuArgRight.Height = 30;
	 MenuArgRight.ListMin = SplitNumber;
	 MenuArgRight.ListMax = ListMax;
	 MenuArgRight.AtherNo = -1;
	 MenuArgRight.AlphaNo = 50;
	 MenuArgRight.DrawFlag = MENU::TEXT;
	 MenuArgRight.DirectionFlag = MENU::COL;
	 MenuArgRight.TextColor = GetColor(255, 255, 255);
	 MenuArgRight.FontFamily = MENU::GOSIC;
	 for (int i = 0; i < SplitNumber; ++i)
	 {
		 strcpy(MenuArgLeft.DrawText[i], Option[i].c_str());
	 }
	 for (int i = SplitNumber; i < ListMax; ++i)
	 {
		 strcpy(MenuArgRight.DrawText[j], Option[i].c_str());
		 ++j;
	 }

 }