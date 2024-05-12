#include"../header/define.h"
/*----------------
 | アイテムクラス |
  ----------------*/
/*初期化*/
ItemClass::ItemClass()
{
	Select = -1;
	//アイテムアイコン
	ItemHandle.push_back(LoadGraph("./resource/graph/item_play.png"));
	ItemHandle.push_back(LoadGraph("./resource/graph/item_eye.png"));
	ItemHandle.push_back(LoadGraph("./resource/graph/item_drop.png"));
	ItemHandle.push_back(LoadGraph("./resource/graph/item_jail.png"));
	ItemHandle.push_back(LoadGraph("./resource/graph/item_memo.png"));
	ItemHandle.push_back(LoadGraph("./resource/graph/item_flute.png"));
	ItemHandle.push_back(LoadGraph("./resource/graph/item_sheet.png"));
	ItemHandle.push_back(LoadGraph("./resource/graph/item_ID.png"));
}
/*メイン関数*/
void ItemClass::Main(UserClass& User, int& ChangeFlag)
{
	//定数宣言
	const int Speed = 60;	//フェードイン速度

	//モードチェンジしたとき、初期化
	if (ChangeFlag == TRUE) {
		for (int i = 0; i < MAX_FLAG; ++i)//ユーザークラスのフラグ情報をコピー
		{
			flags[i] = User.CheckFlag(i);
		}
		SetMenuParam();
		ChangeFlag = FALSE;					//モードチェンジフラグを折る
		FadeFlag = FALSE;					//フェード完了フラグを折る
		Graph.Anime.Reset();				//アニメーションリセット
	}

	//フェードイン
	FadeFlag = Graph.Anime.FadeIn(Speed);
	Draw();
}


void ItemClass::ModeChange(int& ModeFlag, int& ChangeFlag, UserClass& User)
{
	//インスタンス化
	MouseClass* Mouse = MouseClass::GetInstance();
	static DialogClass Dialog;

	//定数定義
	enum { BACK = 8};

	//ダイアログ描画フラグを取得
	MenuDialogFlag = Dialog.GetDrawFlag();

	//左クリックされて、フェードも終わってる
	if (Mouse->GetState(MOUSE::LEFT) == TRUE && FadeFlag == TRUE && MenuDialogFlag == FALSE) {
		switch (Select) {
			//前に戻る
		case BACK:
			ModeFlag = MODE::MAIN;
			ChangeFlag = TRUE;
			break;

			//タイトルに戻る
		//case TITLEBACK:
		//	Dialog.SetSelectNo(Select, "タイトルに戻りますか？");
		//	break;
		}
	}

	if (MenuDialogFlag == TRUE) {
		//ダイアログ描画
		Dialog.Draw(User);

		//Yesなら処理
		if (Dialog.GetSelectFlag() == DIALOG::YES) {

			//選択番号受け取り
			Select = Dialog.GetSelectNo();

			//タイトルならば
			//if (Select == TITLEBACK) {
			//	ModeFlag = MODE::OTHER;
			//	User.SetPage(PAGE::TITLE);
			//	Dialog.Clear();
			//}
		}

		//Noならダイアログ削除
		if (Dialog.GetSelectFlag() == DIALOG::NO) 	Dialog.Clear();
	}
}
void ItemClass::SetMenuParam()
{
	UpperItemParam.DrawX = 60;
	UpperItemParam.DrawY = 80;
	UpperItemParam.Interval = 150;
	UpperItemParam.Width = 150;
	UpperItemParam.Height = 150;
	UpperItemParam.ListMin = 0;
	UpperItemParam.ListMax = 4;
	UpperItemParam.AtherNo = -1;
	UpperItemParam.AlphaNo = 100;
	UpperItemParam.DrawFlag = MENU::IMAGE;
	UpperItemParam.DirectionFlag = MENU::ROW;

	UnderItemParam.DrawX = 60;
	UnderItemParam.DrawY = 370;
	UnderItemParam.Interval = 150;
	UnderItemParam.Width = 150;
	UnderItemParam.Height = 150;
	UnderItemParam.ListMin = 4;
	UnderItemParam.ListMax = 8;
	UnderItemParam.AtherNo = -1;
	UnderItemParam.AlphaNo = 100;
	UnderItemParam.DrawFlag = MENU::IMAGE;
	UnderItemParam.DirectionFlag = MENU::ROW;
	ItemLoad(flags);
	//右下メニュー
	ItemNaviParam.DrawX =windowX-300;
	ItemNaviParam.DrawY =windowY-60;
	ItemNaviParam.Interval =0;
	ItemNaviParam.Width = 320;
	ItemNaviParam.Height = 56;
	ItemNaviParam.ListMin = 8;
	ItemNaviParam.ListMax =	9;
	ItemNaviParam.AtherNo = -1;
	ItemNaviParam.AlphaNo = 200;
	ItemNaviParam.DrawFlag = MENU::IMAGE;
	ItemNaviParam.DirectionFlag = MENU::ROW;
	ItemNaviParam.DrawHandle[0] = LoadGraph("./resource/graph/BackGo.png");
}

void ItemClass::ItemLoad(bool flags[32])
{
	for (int i = 0; i < MAX_ITEM/2; ++i)
	{
		if (flags[i] == true)
		{
			UpperItemParam.DrawHandle[i]=ItemHandle[i];
		}
		else { UpperItemParam.DrawHandle[i] = (LoadGraph("./resource/graph/item_question.png")); }
	}
	int j = 0;
	for (int i = MAX_ITEM / 2; i <MAX_ITEM ; ++i)
	{
		
		if (flags[i] == true)
		{
			UnderItemParam.DrawHandle[j] = ItemHandle[i];
		}
		else { UnderItemParam.DrawHandle[j] = (LoadGraph("./resource/graph/item_question.png")); }
		++j;
	}
}

void ItemClass::Draw()
{
	const int AtherSelect = -1;
	//各種メニュー宣言
	ItemMenuClass UpperItemMenu(UpperItemParam);
	ItemMenuClass UnderItemMenu(UnderItemParam);
	MenuClass NaviMenu(ItemNaviParam);

	 if (MenuDialogFlag == FALSE && ItemDialogFlag == FALSE) {
		 UpperItemMenu.Select();
		 UnderItemMenu.Select();
		 NaviMenu.Select();
	 }
	 /*背景描画*/
	 Graph.Draw();

	 /*メニュー描画*/
	 UpperItemMenu.Draw();
	 UnderItemMenu.Draw();
	 NaviMenu.Draw();
	 Select = NaviMenu.GetSelectNo();
	 if (Select == AtherSelect) Select = UpperItemMenu.GetSelectNo();
	 if (Select == AtherSelect) Select = UnderItemMenu.GetSelectNo();
}



