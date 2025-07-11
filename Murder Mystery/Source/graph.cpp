#include"../header/define.h" 

/*----------------------------
 | タイトルグラフィッククラス |
  ----------------------------*/
/*初期化*/
TitleGraphClass::TitleGraphClass(){
	Load();
	SetPoint();
}

/*画像ロード*/
void TitleGraphClass::Load(){
	TitleBackHandle = LoadGraph("./resource/graph/Title3.png");
}

/*描画座標セット*/
void TitleGraphClass::SetPoint(){
	TitleBackPoint[GRAPH::X] = 0;
	TitleBackPoint[GRAPH::Y] = 0;
}

/*画像描画*/
void TitleGraphClass::Draw(){
	DrawGraph(TitleBackPoint[GRAPH::X],TitleBackPoint[GRAPH::Y],TitleBackHandle,TRUE);
}


/*--------------------------
 | セーブグラフィッククラス |
  --------------------------*/
/*初期化*/
SaveGraphClass::SaveGraphClass(){
	Load();			//画像読み込み
	SetPoint();		//描画座標セット
}
	
/*画像ロード*/
void SaveGraphClass::Load(){
	//背景画像
	BackgroundHandle = LoadGraph("./resource/graph/seimon.jpg");
}

/*描画座標セット*/
void SaveGraphClass::SetPoint(){
	//背景画像
	BackgroundPoint[GRAPH::X] = 0;
	BackgroundPoint[GRAPH::Y] = 0;
}

/*画像描画*/
void SaveGraphClass::Draw(){
	//背景描画
	DrawGraph(BackgroundPoint[GRAPH::X],BackgroundPoint[GRAPH::Y],BackgroundHandle,TRUE);
}


/*--------------------------
 | テキストグラフィッククラス |
  --------------------------*/
/*初期化*/
TextGraphClass::TextGraphClass(){
	Load();			//画像読み込み
	SetPoint();		//描画座標セット
}

/*画像ロード*/
void TextGraphClass::Load(){
	//背景ロード
	GameBackHandle.push_back( LoadGraph("./resource/graph/classroom.png") );
	GameBackHandle.push_back( LoadGraph("./resource/graph/rouka.jpg") );
	GameBackHandle.push_back(LoadGraph("./resource/graph/genkan.jpg"));
	GameBackHandle.push_back(LoadGraph("./resource/graph/syokuin_mae.jpg"));
	GameBackHandle.push_back(LoadGraph("./resource/graph/syokuin.jpg"));
	GameBackHandle.push_back(LoadGraph("./resource/graph/hoken.jpg"));
	GameBackHandle.push_back(LoadGraph("./resource/graph/rika.png"));
	GameBackHandle.push_back(LoadGraph("./resource/graph/housou.jpg"));
	GameBackHandle.push_back(LoadGraph("./resource/graph/ongaku.jpg"));
	GameBackHandle.push_back(LoadGraph("./resource/graph/kaigi.jpg"));
	GameBackHandle.push_back(LoadGraph("./resource/graph/hijoukaidan.jpg"));
	GameBackHandle.push_back(LoadGraph("./resource/graph/taiikukan.png"));
	GameBackHandle.push_back(LoadGraph("./resource/graph/chika.png"));
	GameBackHandle.push_back(LoadGraph("./resource/graph/tunnel.jpg"));
	GameBackHandle.push_back(LoadGraph("./resource/graph/jitaku.jpg"));
	GameBackHandle.push_back(LoadGraph("./resource/graph/background_chalkboard.png"));
	
	//キャラクタ描画
	CharacterHandle = LoadGraph("./resource/graph/character1.png");

	//テキストボックス
	TextBoxHandle	 = LoadGraph("./resource/graph/TextBox.png");

	//ダイス
	DiceHandle[0]=	LoadGraph("./resource/graph/saikoro-illust1.png");
	DiceHandle[1] = LoadGraph("./resource/graph/saikoro-illust2.png");
	DiceHandle[2] = LoadGraph("./resource/graph/saikoro-illust3.png");
	DiceHandle[3] = LoadGraph("./resource/graph/saikoro-illust4.png");
	DiceHandle[4] = LoadGraph("./resource/graph/saikoro-illust5.png");
	DiceHandle[5] = LoadGraph("./resource/graph/saikoro-illust6.png");
	
}

/*描画座標セット*/
void TextGraphClass::SetPoint(){
	//背景
	GameBackPoint[GRAPH::X] = 0;
	GameBackPoint[GRAPH::Y] = 0;

	//キャラクタ描画座標
	CharacterPoint[GRAPH::X] = windowX / 3;
	CharacterPoint[GRAPH::Y] = 0;

	//テキストボックス
	TextBoxPoint[GRAPH::X]  = 0;
	TextBoxPoint[GRAPH::Y]  = windowY - windowY / 3;

	//ダイス左
	LeftDicePoint[GRAPH::X] = 275;
	LeftDicePoint[GRAPH::Y] = 200;

	//ダイス右
	RightDicePoint[GRAPH::X] = 705;
	RightDicePoint[GRAPH::Y] = 200;

}

/*背景描画*/
void TextGraphClass::DrawBack(UserClass &User){
	//背景描画
	switch( User.GetBackCode() ){
	case GAME_BACK::CLASSROOM:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], GameBackHandle[GAME_BACK::CLASSROOM], TRUE);
		break;
	case GAME_BACK::ROUKA:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], GameBackHandle[GAME_BACK::ROUKA], TRUE);
		break;
	case GAME_BACK::GENKAN:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], GameBackHandle[GAME_BACK::GENKAN], TRUE);
		break;
	case GAME_BACK::SYOKUIN_MAE:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], GameBackHandle[GAME_BACK::SYOKUIN_MAE], TRUE);
		break;
	case GAME_BACK::SYOKUIN:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], GameBackHandle[GAME_BACK::SYOKUIN], TRUE);
		break;
	case GAME_BACK::HOKEN:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], GameBackHandle[GAME_BACK::HOKEN], TRUE);
		break;
	case GAME_BACK::RIKA:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], GameBackHandle[GAME_BACK::RIKA], TRUE);
		break;
	case GAME_BACK::HOUSOU:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], GameBackHandle[GAME_BACK::HOUSOU], TRUE);
		break;
	case GAME_BACK::ONGAKU:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], GameBackHandle[GAME_BACK::ONGAKU], TRUE);
		break;
	case GAME_BACK::KAIGI:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], GameBackHandle[GAME_BACK::KAIGI], TRUE);
		break;
	case GAME_BACK::HIJOUKAIDAN:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], GameBackHandle[GAME_BACK::HIJOUKAIDAN], TRUE);
		break;
	case GAME_BACK::TAIIKUKAN:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], GameBackHandle[GAME_BACK::TAIIKUKAN], TRUE);
		break;
	case GAME_BACK::CHIKA:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], GameBackHandle[GAME_BACK::CHIKA], TRUE);
		break;
	case GAME_BACK::TUNNEL:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], GameBackHandle[GAME_BACK::TUNNEL], TRUE);
		break;
	case GAME_BACK::JITAKU:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], GameBackHandle[GAME_BACK::JITAKU], TRUE);
		break;
	case GAME_BACK::KOKUBAN:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], GameBackHandle[GAME_BACK::KOKUBAN], TRUE);
		break;

	case GAME_BACK::BLACK:
		DrawBox(0, 0, windowX, windowY, GetColor(0, 0, 0), TRUE);
		break;
	}
}

/*キャラクタ描画*/
void TextGraphClass::DrawChar(UserClass &User){
	//キャラクタ描画
	switch( User.GetCharacterCode() ){
		case GAME_CHAR::AI:
			DrawGraph(CharacterPoint[GRAPH::X],CharacterPoint[GRAPH::Y],CharacterHandle,TRUE);
		break;

		case GAME_CHAR::NOT:
		break;
	}
}

void TextGraphClass::DrawLeftDice(int dice)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	DrawGraph(LeftDicePoint[GRAPH::X], LeftDicePoint[GRAPH::Y], DiceHandle[dice], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void TextGraphClass::DrawRightDice(int dice)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	DrawGraph(RightDicePoint[GRAPH::X], RightDicePoint[GRAPH::Y], DiceHandle[dice-1], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

/*テキストウィンドウ描画*/
void TextGraphClass::DrawWindow(){
	//テキストボックス描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,255);
	DrawGraph(TextBoxPoint[GRAPH::X],TextBoxPoint[GRAPH::Y],TextBoxHandle,TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
}


/*デバッグ用*/
void TextGraphClass::Draw(){}

/*------------------------------
 | コンフィググラフィッククラス |
  ------------------------------*/
/*初期化*/
ConfigGraphClass::ConfigGraphClass(){
	Load();
	SetPoint();

	/*戻るとか決定のメニューパラメータ*/
	MenuParam.DrawX			= 640;
	MenuParam.DrawY			= 576;
	MenuParam.Interval		= 0;
	MenuParam.Width			= 160;
	MenuParam.Height		= 144;
	MenuParam.ListMin		= 0;
	MenuParam.ListMax		= 4;
	MenuParam.AtherNo		= -1;
	MenuParam.AlphaNo		= 200;
	MenuParam.DrawFlag		= MENU::IMAGE;
	MenuParam.DirectionFlag	= MENU::ROW;

	MenuParam.DrawHandle[0]	= LoadGraph("./resource/graph/conf_init.jpg");
	MenuParam.DrawHandle[1]	= LoadGraph("./resource/graph/conf_save.jpg");
	MenuParam.DrawHandle[2] = LoadGraph("./resource/graph/conf_back.jpg");
	MenuParam.DrawHandle[3] = LoadGraph("./resource/graph/conf_title.jpg");
}

/*画像ロード*/
void ConfigGraphClass::Load(){
	//背景画像
	BackgroundHandle = LoadGraph("./resource/graph/seimon.jpg");
}

/*描画座標セット*/
void ConfigGraphClass::SetPoint(){
	//背景画像
	BackgroundPoint[GRAPH::X] = 0;
	BackgroundPoint[GRAPH::Y] = 0;
}

/*選択されたメニューのナンバーを返す*/
int ConfigGraphClass::GetSelectNo(){ return SelectNo; }

/*現在設定されている項目を貰う*/
void ConfigGraphClass::SetConfigData(ConfigData_rec &ConfigData){
	this->ConfigData = ConfigData; 
}

/*現在設定された項目を返す*/
ConfigData_rec ConfigGraphClass::GetConfigData(){
	return ConfigData; 
}

/*パラメータをセット*/
void ConfigGraphClass::SetMenuParam(){

	/*コンフィグメニューのパラメータセット*/

	ConfigParam[TEXTSPEED].Title  = "テキスト表示速度";
	ConfigParam[TEXTSPEED].DrawX  = 10;
	ConfigParam[TEXTSPEED].DrawY  = 144;
	ConfigParam[TEXTSPEED].Width  = 640;
	ConfigParam[TEXTSPEED].Height = 144;
	ConfigParam[TEXTSPEED].ListNo = 5;
	ConfigParam[TEXTSPEED].SetNo  = ConfigData.TextSpeed;

	ConfigParam[AUTOSPEED].Title  = "オートモード表示速度";
	ConfigParam[AUTOSPEED].DrawX  = 10;
	ConfigParam[AUTOSPEED].DrawY  = 144*2;
	ConfigParam[AUTOSPEED].Width  = 640;
	ConfigParam[AUTOSPEED].Height = 144;
	ConfigParam[AUTOSPEED].ListNo = 5;
	ConfigParam[AUTOSPEED].SetNo  = ConfigData.AutoSpeed;

	/*ConfigParam[SKIP].Title  = "未読スキップするか";
	ConfigParam[SKIP].DrawX  = 10;
	ConfigParam[SKIP].DrawY  = 144*3;
	ConfigParam[SKIP].Width  = 640;
	ConfigParam[SKIP].Height = 144;
	ConfigParam[SKIP].ListNo = 2;
	ConfigParam[SKIP].SetNo  = ConfigData.SkipFlag;
	*/

	ConfigParam[ALLVOL].Title  = "全体音量";
	ConfigParam[ALLVOL].DrawX  = 650;
	ConfigParam[ALLVOL].DrawY  = 144;
	ConfigParam[ALLVOL].Width  = 640;
	ConfigParam[ALLVOL].Height = 144;
	ConfigParam[ALLVOL].ListNo = 5;
	ConfigParam[ALLVOL].SetNo  = ConfigData.AllBolume;

	ConfigParam[BGMVOL].Title  = "BGM音量";
	ConfigParam[BGMVOL].DrawX  = 650;
	ConfigParam[BGMVOL].DrawY  = 144*2;
	ConfigParam[BGMVOL].Width  = 640;
	ConfigParam[BGMVOL].Height = 144;
	ConfigParam[BGMVOL].ListNo = 5;
	ConfigParam[BGMVOL].SetNo  = ConfigData.BGMBolume;

	
	ConfigParam[SEVOL].Title  = "SE音量";
	ConfigParam[SEVOL].DrawX  = 650;
	ConfigParam[SEVOL].DrawY  = 144*3;
	ConfigParam[SEVOL].Width  = 640;
	ConfigParam[SEVOL].Height = 144;
	ConfigParam[SEVOL].ListNo = 5;
	ConfigParam[SEVOL].SetNo  = ConfigData.SEBolume;
}

/*画面描画*/
void ConfigGraphClass::Draw(){
	//マウスインスタンス受け取り
	auto *Mouse = MouseClass::GetInstance();
	
	//変数宣言
	ConfigMenuClass *Menu[5];

	//パラメータセット
	SetMenuParam();

	//インスタンス変数定義
	for( int i=0 ; i<5 ; i++ ){ Menu[i] = new ConfigMenuClass(ConfigParam[i]); }
	MenuClass GlobalMenu(MenuParam);

	//背景描画
	DrawGraph(BackgroundPoint[GRAPH::X],BackgroundPoint[GRAPH::Y],BackgroundHandle,TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,100);
	DrawBox(50,100,windowX-50,windowY-144,GetColor(0,0,0),TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);

	//画面タイトル
	DrawString(10,10,"― コンフィグ画面 ―",GetColor(255,255,255));

	//コンフィグ・グローバルメニュー描画
	for( int i=0 ; i<5 ; i++ ) Menu[i]->Draw();
	GlobalMenu.Create();

	//選択番号取得
	if( Mouse->GetState(MOUSE::LEFT) > 0 ){
		//コンフィグメニューの番号取得
		for( int i=0 ; i<5 ; i++ ){
			if( ConfigParam[i].ListNo != Menu[i]->GetSelectNo() ){
				if( i == 0 ) ConfigData.TextSpeed = Menu[i]->GetSelectNo();
				if( i == 1 ) ConfigData.AutoSpeed = Menu[i]->GetSelectNo();
				//if( i == 2 ) ConfigData.SkipFlag  = Menu[i]->GetSelectNo();
				if( i == 2 ) ConfigData.AllBolume = Menu[i]->GetSelectNo();
				if( i == 3 ) ConfigData.BGMBolume = Menu[i]->GetSelectNo();
				if( i == 4 ) ConfigData.SEBolume  = Menu[i]->GetSelectNo();
			}
		}

		//グローバルメニューの番号取得
		SelectNo = GlobalMenu.GetSelectNo();
	}

	
	
	//オブジェクト開放
	for( int i=0 ; i<5 ; i++ ) delete Menu[i];
}

/*--------------------------------
 |アイテムグラフィッククラス 　　 |
  --------------------------------*/
ItemGraphClass::ItemGraphClass() {
	Load();			//画像読み込み
	SetPoint();		//描画座標セット
}
void ItemGraphClass::Load() {
	//背景ロード
	BackgroundHandle = LoadGraph("./resource/graph/seimon.jpg");
}


/*描画座標セット*/
void ItemGraphClass::SetPoint() {
	//背景
	GameBackPoint[GRAPH::X] = 0;
	GameBackPoint[GRAPH::Y] = 0;
}



/*画像描画*/
void ItemGraphClass::Draw() {
	//背景描画
	DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], BackgroundHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(40, 50, windowX - 40, windowY - 70, GetColor(0, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//画面タイトル
	DrawString(10, 10, "― アイテム一覧 ―", GetColor(255, 255, 255));
}


/*--------------------------------
 | シークレットグラフィッククラス |
  --------------------------------*/
/*初期化*/
SecretGraphClass::SecretGraphClass(){
	Load();			//画像読み込み
	SetPoint();		//描画座標セット
}
	
/*画像ロード*/
void SecretGraphClass::Load(){
	BackgroundHandle = LoadGraph("./resource/graph/seimon.jpg");
	PlayButtonHandle = LoadGraph("./resource/graph/play_button.jpg");
}

/*描画座標セット*/
void SecretGraphClass::SetPoint(){
	//背景画像
	BackgroundPoint[GRAPH::X] = 0;
	BackgroundPoint[GRAPH::Y] = 0;
}

/*画像描画*/
void SecretGraphClass::Draw(){
	DrawBack();
}

/*背景描画*/
void SecretGraphClass::DrawBack(){
	DrawGraph(BackgroundPoint[GRAPH::X],BackgroundPoint[GRAPH::Y],BackgroundHandle,TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,120);
	DrawBox(50,50,windowX-50,windowY-50,GetColor(0,0,0),TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	DrawLine(500,100,500,windowY-100,GetColor(0,0,0));
}

