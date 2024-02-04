#include"../header/define.h" 

/*----------------
 | �T�E���h�N���X |
  ----------------*/
/*�����o�ϐ�������*/
void SoundClass::VarInit(){
	PlayFlag    = STOP;
	NowPlayCode = 0;
}

/*���ʃZ�b�g*/
void SoundClass::SetVol(UserClass &User){
	BGMVol = User.GetBGMVol();
	SEVol  = User.GetSEVol();
}


/*------------------------
 | �^�C�g���T�E���h�N���X |
  ------------------------*/
/*������*/
TitleSoundClass::TitleSoundClass(){
	VarInit();	//�����o�ϐ�������
	Load();		//���y�f�[�^���[�h
}

/*���y���[�h*/
void TitleSoundClass::Load(){
	//���y�f�[�^���[�h
	TitleBGM  = LoadSoundMem("./resource/sound/bgm/TitleBGM.ogg");
}

/*���y�Đ�*/
void TitleSoundClass::PlayMusic(UserClass &User){
	ChangeVolumeSoundMem(BGMVol,TitleBGM);
	//�Đ��t���O�������Ă��Ȃ��Ȃ�΁A���y�Đ�
	if( PlayFlag == STOP ){
		PlayFlag = PLAY;
		//���ʕύX
		PlaySoundMem(TitleBGM,DX_PLAYTYPE_LOOP);
	}
}

/*���y��~*/
void TitleSoundClass::StopBGM(){
	StopSoundMem(TitleBGM);
	PlayFlag = STOP;
}


/*----------------------
 | �Q�[���T�E���h�N���X |
  ----------------------*/
/*������*/
GameSoundClass::GameSoundClass(){
	VarInit();
	Load();
}

/*���y���[�h*/
void GameSoundClass::Load(){
	//���y�f�[�^���[�h
	GameBGM.push_back( LoadSoundMem("./resource/sound/bgm/kaisou.ogg") );
	GameBGM.push_back( LoadSoundMem("./resource/sound/bgm/kaisou2.ogg") );
	GameBGM.push_back( LoadSoundMem("./resource/sound/bgm/deai.ogg") );
	GameBGM.push_back( LoadSoundMem("./resource/sound/bgm/wakare.ogg") );	
	GameBGM.push_back( LoadSoundMem("./resource/sound/bgm/TitleBGM.ogg") );
}

/*���y�Đ�*/
void GameSoundClass::PlayMusic(UserClass &User){
	static bool KaisouFlag = FALSE;

	//���ʐݒ�
	for( int i=0 ; i<5 ; i++ ) ChangeVolumeSoundMem(BGMVol,GameBGM[i]);


	//�Ȃ��ς����
	if( NowPlayCode != User.GetBGMCode() ){
		for( int i=0 ; i<5 ; i++ ) StopSoundMem(GameBGM[i]);
		NowPlayCode = User.GetBGMCode();
		PlayFlag    = STOP;
		KaisouFlag  = FALSE;
	}

	//�Đ��t���O�������Ă��Ȃ���΁A���y�Đ�
	if( PlayFlag == STOP ){

		PlayFlag = PLAY;	//�Đ��t���O�𗧂Ă�

		switch( NowPlayCode ){
			//��z1���[�v��
			case GAME_BGM::KAISOU1:
				PlaySoundMem(GameBGM[GAME_BGM::KAISOU1],DX_PLAYTYPE_BACK);
				KaisouFlag = TRUE;
			break;

			//��z2���[�v�ڈȍ~
			case GAME_BGM::KAISOU2:
				PlaySoundMem(GameBGM[GAME_BGM::KAISOU2],DX_PLAYTYPE_LOOP);
			break;

			//�o�
			case GAME_BGM::DEAI:
				PlaySoundMem(GameBGM[GAME_BGM::DEAI],DX_PLAYTYPE_LOOP);
			break;

			//�ʂ�
			case GAME_BGM::WAKARE:
				PlaySoundMem(GameBGM[GAME_BGM::WAKARE],DX_PLAYTYPE_LOOP);
			break;

			//�c��
			case GAME_BGM::TITLE:
				PlaySoundMem(GameBGM[GAME_BGM::TITLE],DX_PLAYTYPE_LOOP);
			break;

			//���y��~
			case GAME_BGM::STOP:
			break;

		}
	}

	//��z1���[�v�ڂ��I�������2���[�v�ڂɃ`�F���W
	if( NowPlayCode == GAME_BGM::KAISOU1 && CheckSoundMem( GameBGM[GAME_BGM::KAISOU1] ) == 0 && KaisouFlag == TRUE ){
		PlaySoundMem(GameBGM[GAME_BGM::KAISOU2],DX_PLAYTYPE_LOOP);
		KaisouFlag = FALSE;
	}

}

/*���y��~*/
void GameSoundClass::StopBGM(){
	for( int i=0 ; i<5 ; i++ ) StopSoundMem(GameBGM[i]);
	PlayFlag = STOP;
}

/*--------------------------
 | �V�X�e���G�t�F�N�g�N���X |
  --------------------------*/
/*������*/
SESoundClass::SESoundClass(){
	VarInit();
	Load();
}

/*���y���[�h*/
void SESoundClass::Load(){
	DialogSE  = LoadSoundMem("./resource/sound/se/dialog.ogg");
	EnterSE   = LoadSoundMem("./resource/sound/se/enter.ogg");
	CancelSE  = LoadSoundMem("./resource/sound/se/cancel.ogg");
}

/*���y�Đ�*/
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

/*�_�~�[����*/
void SESoundClass::PlayMusic(UserClass &User){
}

/*���y��~*/
void SESoundClass::StopBGM(){
}

/*----------------------------
 | �V�[�N���b�g�T�E���h�N���X |
  ----------------------------*/
/*������*/
SecretSoundClass::SecretSoundClass(){
	VarInit();
	Load();
}

/*���y���[�h*/
void SecretSoundClass::Load(){
	TitleBGM   = LoadSoundMem("./resource/sound/bgm/TitleBGM.ogg");
	kaisouBGM  = LoadSoundMem("./resource/sound/bgm/prologue.ogg");
	kaisou2BGM = LoadSoundMem("./resource/sound/bgm/kaisou2.ogg");
	DeaiBGM    = LoadSoundMem("./resource/sound/bgm/deai.ogg");
	WakareBGM  = LoadSoundMem("./resource/sound/bgm/wakare.ogg");
	EndingBGM  = LoadSoundMem("./resource/sound/bgm/Ending.ogg");
}

/*���y�Đ�(�_�~�[)*/
void SecretSoundClass::PlayMusic(UserClass &User){
}

/*���y�Đ�*/
void SecretSoundClass::PlayMusic(int Code){
	static bool KaisouFlag = TRUE;

	ChangeVolumeSoundMem(BGMVol,TitleBGM);
	ChangeVolumeSoundMem(BGMVol,kaisouBGM);
	ChangeVolumeSoundMem(BGMVol,kaisou2BGM);
	ChangeVolumeSoundMem(BGMVol,DeaiBGM);
	ChangeVolumeSoundMem(BGMVol,WakareBGM);
	ChangeVolumeSoundMem(BGMVol+50,EndingBGM);

	static int OldCode = -1;

	//�Ȃ��ς������Đ��t���O��܂�
	if( OldCode != Code ) PlayFlag = STOP;
	OldCode = Code;

	//�Ȃ�S�Ē�~������
	if( PlayFlag == STOP ) StopBGM();

	//�Đ��t���O�������Ă��Ȃ��Ȃ�΁A���y�Đ�
	if( PlayFlag == STOP ){
		if( Code == TITLE )  PlaySoundMem(TitleBGM,DX_PLAYTYPE_LOOP);
		if( Code == KAISOU ) PlaySoundMem(kaisouBGM,DX_PLAYTYPE_LOOP);
		if( Code == DEAI )   PlaySoundMem(DeaiBGM,DX_PLAYTYPE_LOOP);
		if( Code == WAKARE ) PlaySoundMem(WakareBGM,DX_PLAYTYPE_LOOP);
		if( Code == ENDING ) PlaySoundMem(EndingBGM,DX_PLAYTYPE_LOOP);

		PlayFlag = PLAY;
	}

	//if( CheckSoundMem( kaisouBGM ) == 0 && Code == KAISOU ){
	//	PlaySoundMem(kaisou2BGM,DX_PLAYTYPE_LOOP);
	//}

}

/*���y��~*/
void SecretSoundClass::StopBGM(){
	StopSoundMem(TitleBGM);
	StopSoundMem(kaisouBGM);
	StopSoundMem(kaisou2BGM);
	StopSoundMem(DeaiBGM);
	StopSoundMem(WakareBGM);
	StopSoundMem(EndingBGM);
}
