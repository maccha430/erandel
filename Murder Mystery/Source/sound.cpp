#include"../header/define.h" 

/*----------------
 | サウンドクラス |
  ----------------*/
/*メンバ変数初期化*/
void SoundClass::VarInit(){
	PlayFlag    = STOP;
	NowPlayCode = 0;
}

/*音量セット*/
void SoundClass::SetVol(UserClass &User){
	BGMVol = User.GetBGMVol();
	SEVol  = User.GetSEVol();
}


/*------------------------
 | タイトルサウンドクラス |
  ------------------------*/
/*初期化*/
TitleSoundClass::TitleSoundClass(){
	VarInit();	//メンバ変数初期化
	Load();		//音楽データロード
}

/*音楽ロード*/
void TitleSoundClass::Load(){
	//音楽データロード
	TitleBGM  = LoadSoundMem("./resource/sound/bgm/TitleBGM.ogg");
}

/*音楽再生*/
void TitleSoundClass::PlayMusic(UserClass &User){
	ChangeVolumeSoundMem(BGMVol,TitleBGM);
	//再生フラグが立っていないならば、音楽再生
	if( PlayFlag == STOP ){
		PlayFlag = PLAY;
		//音量変更
		PlaySoundMem(TitleBGM,DX_PLAYTYPE_LOOP);
	}
}

/*音楽停止*/
void TitleSoundClass::StopBGM(){
	StopSoundMem(TitleBGM);
	PlayFlag = STOP;
}


/*----------------------
 | ゲームサウンドクラス |
  ----------------------*/
/*初期化*/
GameSoundClass::GameSoundClass(){
	VarInit();
	Load();
}

/*音楽ロード*/
void GameSoundClass::Load(){
	//音楽データロード
	GameBGM.push_back( LoadSoundMem("./resource/sound/bgm/battle.ogg") );
	GameBGM.push_back(LoadSoundMem("./resource/sound/bgm/erandel.ogg"));
	GameBGM.push_back( LoadSoundMem("./resource/sound/bgm/TitleBGM.ogg") );
	GameBGM.push_back(LoadSoundMem("./resource/sound/bgm/Warning.ogg"));
	
}

/*音楽再生*/
void GameSoundClass::PlayMusic(UserClass &User){
	static bool KaisouFlag = FALSE;

	//音量設定
	for( int i=0 ; i<4 ; i++ ) ChangeVolumeSoundMem(BGMVol,GameBGM[i]);


	//曲が変わった
	if( NowPlayCode != User.GetBGMCode() ){
		for( int i=0 ; i<4 ; i++ ) StopSoundMem(GameBGM[i]);
		NowPlayCode = User.GetBGMCode();
		PlayFlag    = STOP;
		KaisouFlag  = FALSE;
	}

	//再生フラグが立っていなければ、音楽再生
	if( PlayFlag == STOP ){

		PlayFlag = PLAY;	//再生フラグを立てる

		switch( NowPlayCode ){

			//戦闘
			case GAME_BGM::BATTLE:
				PlaySoundMem(GameBGM[GAME_BGM::BATTLE],DX_PLAYTYPE_LOOP);
			break;

			//白兎のワルツ
			case GAME_BGM::ERANDEL:
				PlaySoundMem(GameBGM[GAME_BGM::ERANDEL], DX_PLAYTYPE_LOOP);
				break;

			//夜風の花火
			case GAME_BGM::TITLE:
				PlaySoundMem(GameBGM[GAME_BGM::TITLE],DX_PLAYTYPE_LOOP);
			break;
			case GAME_BGM::WARNING:
				PlaySoundMem(GameBGM[GAME_BGM::WARNING], DX_PLAYTYPE_LOOP);
				break;
			

			//音楽停止
			case GAME_BGM::STOP:
			break;

		}
	}

}

/*音楽停止*/
void GameSoundClass::StopBGM(){
	for( int i=0 ; i<4 ; i++ ) StopSoundMem(GameBGM[i]);
	PlayFlag = STOP;
}

/*--------------------------
 | システムエフェクトクラス |
  --------------------------*/
/*初期化*/
SESoundClass::SESoundClass(){
	VarInit();
	Load();
}

/*音楽ロード*/
void SESoundClass::Load(){
	DialogSE  = LoadSoundMem("./resource/sound/se/dialog.ogg");
	EnterSE   = LoadSoundMem("./resource/sound/se/enter.ogg");
	CancelSE  = LoadSoundMem("./resource/sound/se/cancel.ogg");
}

/*音楽再生*/
void SESoundClass::PlayMusic(int Code){
	ChangeVolumeSoundMem(SEVol,DialogSE);
	ChangeVolumeSoundMem(SEVol,EnterSE);
	ChangeVolumeSoundMem(SEVol,CancelSE);
	if( Code == DIALOG ){
		PlaySoundMem(DialogSE,DX_PLAYTYPE_BACK);
	}
	if( Code == ENTER  ){
		PlaySoundMem(EnterSE,DX_PLAYTYPE_BACK);
	}
	if( Code == CANCEL ){
		PlaySoundMem(CancelSE,DX_PLAYTYPE_BACK);
	}
}

/*ダミー処理*/
void SESoundClass::PlayMusic(UserClass &User){
}

/*音楽停止*/
void SESoundClass::StopBGM(){
}

/*----------------------------
 | シークレットサウンドクラス |
  ----------------------------*/
/*初期化*/
SecretSoundClass::SecretSoundClass(){
	VarInit();
	Load();
}

/*音楽ロード*/
void SecretSoundClass::Load(){
	TitleBGM   = LoadSoundMem("./resource/sound/bgm/TitleBGM.ogg");
	ErandelBGM  = LoadSoundMem("./resource/sound/bgm/erandel.ogg");
	BattleBGM = LoadSoundMem("./resource/sound/bgm/battle.ogg");
}

/*音楽再生(ダミー)*/
void SecretSoundClass::PlayMusic(UserClass &User){
}

/*音楽再生*/
void SecretSoundClass::PlayMusic(int Code){
	static bool KaisouFlag = TRUE;

	ChangeVolumeSoundMem(BGMVol,TitleBGM);
	ChangeVolumeSoundMem(BGMVol,ErandelBGM);
	ChangeVolumeSoundMem(BGMVol,BattleBGM);

	static int OldCode = -1;

	//曲が変わったら再生フラグを折る
	if( OldCode != Code ) PlayFlag = STOP;
	OldCode = Code;

	//曲を全て停止させる
	if( PlayFlag == STOP ) StopBGM();

	//再生フラグが立っていないならば、音楽再生
	if( PlayFlag == STOP ){
		if( Code == TITLE )  PlaySoundMem(TitleBGM,DX_PLAYTYPE_LOOP);
		if( Code == ERANDEL ) PlaySoundMem(ErandelBGM,DX_PLAYTYPE_LOOP);
		if( Code == BATTLE )   PlaySoundMem(BattleBGM,DX_PLAYTYPE_LOOP);

		PlayFlag = PLAY;
	}

	//if( CheckSoundMem( kaisouBGM ) == 0 && Code == KAISOU ){
	//	PlaySoundMem(kaisou2BGM,DX_PLAYTYPE_LOOP);
	//}

}

/*音楽停止*/
void SecretSoundClass::StopBGM(){
	StopSoundMem(TitleBGM);
	StopSoundMem(ErandelBGM);
	StopSoundMem(BattleBGM);
}
