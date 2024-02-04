#include"../header/define.h" 

/*--------------------
 | �V�[�N���b�g�N���X |
  --------------------*/
/*������*/
SecretClass::SecretClass(){
	Select = -1;
	SetNo  = 5;

	//�p�����[�^�Z�b�g
	SetMenuParam();
}

/*���j���[�p�����[�^�Z�b�g*/
void SecretClass::SetMenuParam(){
	char TmpText[6][32] = {
		"�^�C�g���̋�","��z�̋�","�o��̋�","�ʂ�̋�","�G���f�B���O","�߂�"
	};
	
	MusicListParam.DrawX			= 150;
	MusicListParam.DrawY			= 95;
	MusicListParam.Interval			= 70;
	MusicListParam.Width			= 30;
	MusicListParam.Height			= 30;
	MusicListParam.ListMin			= 0;
	MusicListParam.ListMax			= 6;
	MusicListParam.AtherNo			= -1;
	MusicListParam.AlphaNo			= 50;
	MusicListParam.DrawFlag			= MENU::TEXT;
	MusicListParam.DirectionFlag	= MENU::COL;
	
	for( int i=0 ; i<6 ; i++ ) {
		strcpy(MusicListParam.DrawText[i],TmpText[i]);
	}

	MusicListParam.TextColor  = GetColor(255,255,255);
	MusicListParam.FontFamily = MENU::GOSIC;
}

/*�`��e�L�X�g�Z�b�g*/
void SecretClass::SetText(){	
	int  FileHandle;
	int  TitleCount = 0;
	int  TextCount  = 0;
	char TmpBuf[256];
	
	const int TitleMax       = 6;
	const int TextMax        = 19;
	const int LoadTextLength = 256;

	//�z��̈�m��
	ShowText.resize(TitleMax);
	for( int i=0 ; i<TitleMax ; i++ ) ShowText[i].resize(TextMax);
	
	//�t�@�C���ǂݍ���
	FileHandle = FileRead_open("./resource/story/omake.txt");

	//�e�L�X�g�擾
	while( FileRead_eof(FileHandle) == 0 ){
		FileRead_gets(TmpBuf,LoadTextLength,FileHandle);
 		ShowText[TitleCount][TextCount] = TmpBuf;
		
		//�J�E���g�A�b�v
		TextCount++;
		if( TextCount > TextMax-1 ){
			TitleCount++;
			TextCount = 0;
		}
	}

}

/*���C���֐�*/
void SecretClass::Main(UserClass& User,int &ChangeFlag){
	auto *Mouse = MouseClass::GetInstance();
	static SecretMenuClass MusicList(MusicListParam);

	int TitleDrawY = 0;

	const int DrawStringX = 520;
	const int DrawStringY = 150;
	const int LineHeight  = 30;
	const int FontSize    = 22;

	//�`��e�L�X�g�Z�b�g
	SetText();

	//���[�h�`�F���W�����Ƃ��A������
	if( ChangeFlag == TRUE ){
		ChangeFlag = FALSE;					//���[�h�`�F���W�t���O��܂�
		FadeFlag   = FALSE;					//�t�F�[�h�����t���O��܂�
		Graph.Anime.Reset();				//�A�j���[�V�������Z�b�g
	}

	//�w�i�`��
	Graph.DrawBack();

	//�Ȉꗗ�`��
	MusicList.Select();
	MusicList.Draw(SetNo);


	//�I��ԍ��擾
	Select = MusicList.GetSelectNo();

	SetFontSize(22);

	//�������`��
	for( int i=0 ; i<19 ; i++ ){
		if( i == 0 ) TitleDrawY = -50;
		else		 TitleDrawY = 0;

		DrawStringShadow(DrawStringX,DrawStringY+LineHeight*i+TitleDrawY,ShowText[SetNo][i],GetColor(255,255,255),GetColor(0,0,0));
	}

	//�N���b�N���ꂽ�特�y�Đ�
	if( Mouse->GetState(MOUSE::LEFT) > 0  ){
		Sound.SetVol( User );
		Sound.PlayMusic( Select );
		SetNo = Select;

		if( Select == 5 ) User.SetPage( PAGE::TITLE );
	}

	if( SetNo < 0 ) SetNo = 5;
	//DrawStringShadow(DrawStringX,DrawStringY+200,"�P�Q�R�S�T�U�V�W�X�O�P�Q�R�S�T�U�V�W�X�O�P�Q�R�S�T�U�V�W�X�O",GetColor(255,255,255),GetColor(0,0,0));

	//DrawStringShadow(10,10,"�V�[�N���b�g���[�h�ւ悤���� �\",GetColor(0,0,0),GetColor(150,150,150));
}

