#include"../header/define.h" 

/*----------------
 | �e�L�X�g�N���X |
  ----------------*/
/*����������*/
TextClass::TextClass(){
	InitVar();		//�ϐ�������
	LoadStory();	//�X�g�[���ǂݍ���
}

/*�ϐ�������*/
void TextClass::InitVar(){
	//�����o�ϐ�������
	SelectFlag = 1;
	Select = -1;
	AutoFlag = -1;
	TextCount = 0;
	SceneCount = 0;
	SerifCount = 0;
	SelectFlag = 0;
	WriteMode  = NORMAL;
	TextGraphEndFlag=0;
	memset(LineMax,0,sizeof(LineMax));
	memset(LineNo,0,sizeof(LineNo));
	memset(Text,'\0',sizeof(Text));
	memset(Name,'\0',sizeof(Name));
}

/*�X�g�[���[���[�h*/
void TextClass::LoadStory(){
	//�^�̕ϐ�
	int							FileHandle;			//�t�@�C���n���h��
	char						TmpBuf[128];		//�e�L�X�g�擾�p�ꎞ�ϐ�
	char						FileName[64];		//�t�@�C�����i�[
	std::string					TmpText;			//�e�L�X�g�擾�㑀��p�ꎞ�I�u�W�F�N�g 
	std::vector<std::string>	SplitTextArray;		//�������ꂽ�������i�[����z��

	//�J�E���^
	int	Count = 0;									//�J�E���^
	int	Scene = 0;									//�V�[���J�E���^

	//�s���Ǘ�
	int SerifNo = -1;								//�Z���t�̃i���o�[���i�[(�ŏ��͕K�����Z�����̂ŁA�����l�͕��̐��ɂ��Ă���)

	//�萔
	const int LoadTextLen = 128;					//�ǂݍ��ރe�L�X�g�̕�����
	const int NAME		  = 0;						//�������ꂽ��������i�[����z��Ɋւ������
	const int TEXT		  = 1;						//�������ꂽ��������i�[����z��Ɋւ������


	//SceneMax(�萔)�܂Ń��[�h
	while( Scene <= SceneMax ){ 

		//�t�@�C�������擾
		sprintf(FileName,"./resource/story/zankyo scene%d.txt",Scene);
		
		//�t�@�C���I�[�v��
		FileHandle = FileRead_open(FileName);

		//�t�@�C���I�[�܂Ń��[�v
		while( FileRead_eof(FileHandle) == 0 ){
			//�t�@�C�������s�擾
			FileRead_gets(TmpBuf,LoadTextLen,FileHandle);
			
			//�ꕶ���ڂ� '\0' �Ȃ��s�Ɣ��f���X�L�b�v
			if( TmpBuf[0] == '\0'  ) continue;

			//char�^�z���TmpBuf��String�I�u�W�F�N�g��TmpText�ɕϊ�
			TmpText = TmpBuf;
				
			//TmpText�̈ꕶ���ڂ�'\0'�Ȃ�΋�s�Ɣ��f���X�L�b�v
			if( TmpText[0] == NULL ) continue;

			//�S�p����p�X�y�[�X������
			CutSpace(TmpText);

			//TmpText�̈ꕶ���ڂ�'\0'�Ȃ�΋�s�Ɣ��f���X�L�b�v
			if( TmpText[0] == '\0' ) continue;

			//TmpText��Name��Text�ɕ���
			SplitTextArray = StringSplit(TmpText,':');

			//�������ꂽ�������Name��Text�ɑ��
			Name[Scene][Count] = SplitTextArray[NAME];
			Text[Scene][Count] = SplitTextArray[TEXT];

			//Name��"�R�����g"�Ȃ�R�����g�Ɣ��f���X�L�b�v
			if( Name[Scene][Count] == "�R�����g" ) continue;

			//�ꎞ�����AName��"�w�i"�Ȃ�Ƃ�܃X�L�b�v
			//if( Name[Scene][Count] == "�w�i" ) continue;

			//Text��'\0'�Ȃ�O�̃e�L�X�g�̑����Ɣ��f���AName�ɑ����Ƒ�����AText��Name(��s�S�ē����Ă�)�̓��e���R�s�[ �� �s�����Z
			//����ȊO�Ȃ�Ύ��̃e�L�X�g�Ɣ��f���ASerifNo�����Z���A�s�����Z
			if( Text[Scene][Count] == "\0" ){
				Text[Scene][Count] = Name[Scene][Count];
				Name[Scene][Count] = "����";
				LineNo[Scene][SerifNo]++;
			}else{
				SerifNo++;
				LineNo[Scene][SerifNo]++;
			}

			//�ő�s�����Z
			LineMax[Scene]++;

			//�J�E���g��i�߂�
			Count++;
		}

		//�V�[���J�E���g��i�߂�
		Scene++;

		//�J�E���g������
		Count=0;
		SerifNo=-1;

	}
	
}

/*�����񕪊�*/
std::vector<std::string> TextClass::StringSplit(const std::string &Str,char Sep){
	//���낢��錾
	std::vector<std::string> V;
	std::stringstream Ss(Str);
	std::string Buffer;

	const std::string EndOfText = "\0";

	//�����񕪊�
	while( std::getline(Ss,Buffer,Sep) ) V.push_back(Buffer);

	//�I�[���� '\0' ��}��
	V.push_back(EndOfText);

	return V;
}

/*�e�L�X�g����X�y�[�X����菜��*/
int TextClass::CutSpace(std::string &TmpText){
	//�ϐ��錾
	int  i = 0;				//�󔒏��������Ɏg���J�E���^
	char TmpStr[3];		   	//�󔒏��������ɂ����ꎞ�ϐ�

	const int BigSpaceSize = 2; //�S�p�X�y�[�X�̃T�C�Y

	//�S�p�󔒂���菜������
	if( TmpText.length() >= BigSpaceSize ){
		do{
			if( TmpText.length() <= i ){
				TmpText[0] = '\0';
				return 0;
			}
			TmpStr[0] = TmpText[i];
			TmpStr[1] = TmpText[i+1];
			TmpStr[2] = '\0';
			i+=2;
		}while( strcmp(TmpStr,"�@") == 0 );
		TmpText = &TmpText[i-2];
	}
	
	//���p�X�y�[�X����菜������
	i=0;
	while( TmpText[i] == ' ' ){
		//�������𒴂��Ȃ��悤�ȃR�[�f�B���O������(��Q��)

		i++;
		if( TmpText.length() <= i ){
			TmpText[0] = '\0';
			return 0;
		}
	}
	TmpText = &TmpText[i];

}

/*���C���֐�*/
void TextClass::Main(UserClass &User){
	//���j���[�p�����[�^�Z�b�g
	static struct MenuArg_rec MenuRightParam;
	SetMenuParam_GameRight(MenuRightParam);
	static MenuClass GameRightMenu(MenuRightParam);

	//�萔
	const int OtherSelect = 6;


	//�Q�[���J�E���g�̏�����
	InitGameCount(User);

	//�e�L�X�g�`�F�b�N
	CheckText(User);	

	//����R�[�h�`�F�b�N
	if( WriteMode != EYECATCH ) CheckCotrolCode(User);

	//�w�i�`��
	Graph.DrawBack(User);

	//�L�����N�^�`��
	Graph.DrawChar(User);

	//�e�L�X�g�{�b�N�X�`��
	if( WriteMode != NOTWINDOW ) Graph.DrawWindow();

	//�`�惂�[�h�擾
	//WriteMode = GetWriteMode();

	//�R���t�B�O�Ŗ��ǃX�L�b�v���ݒ�
	ReadUpdate(User);

	//���ǃ`�F�b�N
	CheckRead();
	
	//�f�o�b�O�p���Ǒ���
	ControlRead();

	//���j���[�ݒu�����
	if( WriteMode == NORMAL ){
		GameRightMenu.Create();
		Select = GameRightMenu.GetSelectNo();
	}
	
	//�e�L�X�g�`��
	if( WriteMode == NORMAL    ) NormalWrite(User);	//�ʏ�e�L�X�g�`��
	if( WriteMode == EYECATCH  ) EyeCatching(User);	//�A�C�L���b�`
	if( WriteMode == BACKLOG   ) BackLogMain(User);	//�o�b�N���O
	if( WriteMode == NOTWINDOW ) NotWindow();		//�E�B���h�E��\��
	if( WriteMode == END	   ) GameEnd(User);		//�Q�[���I��

	//���j���[��I�����Ă��Ȃ���΁A�e�L�X�g��i�߂饃X�L�b�v��I�[�g
	if( Select == OtherSelect && WriteMode == NORMAL){
		PutNextLine(User);
		//SkipFunction(User);
		AutoFunction(User);
	}
	
	//���݂̃J�E���g���Z�b�g
	SetGameData(User);
}

/*���[�h�`�F���W*/
void TextClass::ModeChange(int &ModeFlag,int &ChangeFlag,UserClass &User){
	//�C���X�^���X��
	MouseClass* Mouse = MouseClass::GetInstance();
	AnimeClass Anime;

	static int Count = 0;

	const int AtherSelect = -1;

	//�^�C�}�[
	static int Timer = 0;
	if( WriteMode != NOTWINDOW ) Timer++;

	//���[�h�`�F���W
	if( Mouse->GetState(MOUSE::LEFT) == TRUE ){
		if( Select == GAME_MENU::SAVE )    ModeFlag  = MODE::SAVE;
		if( Select == GAME_MENU::LOAD )    ModeFlag  = MODE::LOAD;
		if( Select == GAME_MENU::BACKLOG ) WriteMode = BACKLOG;
		if( Select == GAME_MENU::CONFIG  ) ModeFlag  = MODE::CONFIG;
		if( Select == GAME_MENU::AUTO )    AutoFlag *= -1;
		ChangeFlag = TRUE;
	}

	//�E�B���h�E��\��
	/*
	if( Mouse->GetState( MOUSE::RIGHT) > 0 && WriteMode == NORMAL && Timer > 20 ){
		WriteMode = NOTWINDOW;
		Timer = 0;
	}
	*/

	//�o�b�N���O
	if( Mouse->GetWheel() > 0 && WriteMode == NORMAL ) WriteMode = BACKLOG;

	//�G���f�B���O���[�h��
	if( WriteMode == END ){ //&& Mouse->GetState(MOUSE::LEFT) > 10 ){
		Select    = AtherSelect;
		WriteMode = NORMAL;
		ModeFlag = MODE::END;
		//ModeFlag = MODE::OTHER;
		//User.SetPage( PAGE::TITLE );
	}

	//�^�C�g����ʂ�
	if( WriteMode == TITLE ){
		Count++;
		DrawBox(0,0,windowX,windowY,GetColor(0,0,0),TRUE);
		SetFontSize(100);
		ChangeFont("�l�r ����");
		DrawString(windowX/3,windowY/3,"- FIN - ",GetColor(255,255,255));
		User.SetBGMCode( GAME_BGM::STOP );
		if( Count > 200 ){
			WriteMode = NORMAL;
			ModeFlag = MODE::OTHER;
			User.SetPage( PAGE::TITLE );
			Count = 0;
		}
		
	}
}

/*�Q�[���J�E���g������*/
void TextClass::InitGameCount(UserClass& User){
	//�Q�[���J�E���g�擾
	SaveData   = User.GetSaveData();
	SceneCount = SaveData.SceneCount;
	TextCount  = SaveData.TextCount;
	SerifCount = SaveData.SerifCount;
	User.SetBGMCode ( SaveData.BGMCode  );
	User.SetBackCode( SaveData.BackCode );
	User.SetCharacterCode( SaveData.CharCode );
}

/*�l�X�ȃe�L�X�g�`�F�b�N*/
void TextClass::CheckText(UserClass &User){
	//���j���[����t���O��܂��Ă���
	MenuEnterFlag = 0;

	const int AtherSelect = -1;

	//���ڃt���O
	static bool FirstFlag = FALSE;

	//�V�[���̏I���Ȃ�A���̃V�[����(�J�E���g�X�V)
	if( TextCount >= LineMax[SceneCount] ){
		SceneCount++;
		TextCount  = 0;
		SerifCount = 0;

		//���[�U�[�N���X�ɓn��
		SaveData.SceneCount = SceneCount;
		SaveData.TextCount  = TextCount;
		SaveData.SerifCount = SerifCount;
		User.SetSaveData(SaveData);
		
		//�A�C�L���b�`�𓮍삳����
		WriteMode = EYECATCH;
	}

	//�V�[���̂͂��߂ɃA�C�L���b�`�𓮍삳����
	if( SceneCount == 0 && TextCount == 0 && FirstFlag == FALSE ){
		Select    = AtherSelect;
		WriteMode = EYECATCH;
		FirstFlag = TRUE;
	}
	if( TextCount > 0 ) FirstFlag = FALSE;
	

}

/*�e�L�X�g�ʏ�`��*/
void TextClass::NormalWrite(UserClass &User){
	//�C���X�^���X�擾
	KeyClass* Key = KeyClass::GetInstance();
	MouseClass* Mouse = MouseClass::GetInstance();

	//�e�L�X�g�`��
	WriteText(User);	

	//���O�`��
	WriteName();

 	//�Q�[���J�E���g�X�V
	//User.SetSaveData(SceneCount,TextCount,SerifCount);
}

/*�e�L�X�g�`��*/
void TextClass::WriteText(UserClass &User){
	//�ϐ��錾
	static int  WriteCount  = 0;					//�������ݎ��J�E���g
	static int  WriteIndex[3] = {0,0,0};			//���݉������ڂ�
	static int  WriteX = 0;							//��������X�����W
	static int  WriteY = 0;							//��������Y���W
	static int  OldTextCount;						//�O�̃e�L�X�g�J�E���g���擾
	static int  WriteLine;							//�`�悷��s
	int  Length;									//������
	int  TmpCount  = 0;								//�ꎞ�J�E���^
	int  LoopCount = 0;								//���[�v�p�J�E���^
	char WriteText[3];								//�������ݕ���

	//�萔��`	
	const int DrawX		= 250;							//�`���w���W						
	const int DrawY		= windowY - windowY / 3 + 50;	//�`���x���W
	const int TextSpace = 14;							//�����ƕ����̊Ԋu
	const int LineSpace = 40;							//�s�ƍs�̊Ԋu
	const int FontSize  = 28;							//�t�H���g�T�C�Y
	int DrawSpeed;										//�����̕`�摬�x
	

	//�����̕`�摬�x���擾
	if( AutoFlag == 1 ) DrawSpeed = User.GetAutoTextSpeed();
	else				DrawSpeed = User.GetTextSpeed();


	//�e�L�X�g���i�񂾂�ϐ�������
	if( TextCount != OldTextCount ){
		memset(WriteIndex,0,sizeof(WriteIndex));
		WriteCount = 0;
		WriteX     = 0;
		WriteY     = 0;
		WriteLine   = 0;
	}
	//�O�̃e�L�X�g�J�E���g���擾(��̏������̂���)
	OldTextCount = TextCount;

	//�t�H���g�T�C�Y
	//SetFontSize(FontSize);

	//���ݕ\������Ă��镶���������\������(Line�͍s���������A�ő�s�������[�v����)
	for( int Line=0 ; Line<LineNo[SceneCount][SerifCount] ; Line++ ){

		//�`�悪�������Ă���s�܂ŕ`��
		if( Line <= WriteLine ){
			LoopCount = 0;																								//���[�v�J�E���^������
			while( LoopCount <= WriteIndex[Line] ){																		//�������݉\�������ȉ��Ȃ�
				WriteX = LoopCount * TextSpace;																			//�`��X���W�X�V
				WriteText[0] = Text[SceneCount][TextCount+Line][LoopCount];												//1byte�ڑ��
				WriteText[1] = Text[SceneCount][TextCount+Line][LoopCount+1];											//2byte�ڑ��
				WriteText[2] = '\0';																					//�k����������
				//DrawStringToHandle(DrawX+WriteX,DrawY + ( LineSpace * Line ),WriteText,GetColor(200,200,200),TextFontHandle);	//�ꕶ���`��
				DrawStringShadow(DrawX+WriteX,DrawY + ( LineSpace * Line ),WriteText,GetColor(233,233,233),GetColor(5,5,5));
				LoopCount+=2;																							//�ꕶ�����J�E���g�A�b�v
			}

			Length = Text[SceneCount][TextCount+Line].length()-2;

			//������̏I�[�Ȃ�΁A�������ݍs�����X�V
			if( Length <= WriteIndex[Line] ){
				WriteLine = Line+1;					//������̏I�[�Ȃ�΁A�������ݍs�����X�V
			}else if( WriteCount % DrawSpeed == 0 ) WriteIndex[Line]+=2;


			//�������S���`��I���t���O�������Ă���Ȃ��,�`��J�E���g���ő�ɂ���(����������)
			if( TextGraphEndFlag == 1 ){
				WriteIndex[Line] = Length;
			}
		}
	}
	
	//�`��^�C�~���O���@�p
	WriteCount++;
	
	//�e�L�X�g���S�ĕ`�悳�ꂽ��A�S���`��I���t���O�𗧂Ă�
	if( WriteLine == LineNo[SceneCount][SerifCount] ) TextGraphEndFlag = 1;

}

/*���O�`��*/
void TextClass::WriteName(){
	//�萔��`
	const int DrawX = 200;
	const int DrawY = windowY - windowY / 3 + 10;

	//Name����l���Ȃ�A�󕶎�����(�n�̕��Ȃ̂Ŗ��O��\�������Ȃ�)
	if( Name[SceneCount][TextCount] == "��l��" ){
		Name[SceneCount][TextCount][0] = '\0';
	}

	//���O�`��
	DrawStringShadow(DrawX,DrawY,Name[SceneCount][TextCount].c_str(),GetColor(233,233,233),GetColor(5,5,5));
}

/*���̍s�֐i�߂�*/
void TextClass::PutNextLine(UserClass &User){
	//�C���X�^���X�擾
	KeyClass*   Key    = KeyClass::GetInstance();
	MouseClass* Mouse = MouseClass::GetInstance();

	//�G���^�[��������āA�e�L�X�g���\�����I����āA���j���[��I�����Ă��Ȃ��Ȃ�A�J�E���g��i�߂�
	if( ( Key->GetState(KEY_INPUT_RETURN) == 1 || Mouse->GetState(MOUSE::LEFT) == 1 || Mouse->GetWheel() < 0 ) && MenuEnterFlag != 1){
		//�e�L�X�g�\�������t���O�������Ă���΃J�E���g��i�߂�
		if( TextGraphEndFlag == 1 ){

			//�e�L�X�g�J�E���g�����݂̍s�����i�߂�
			//TextCount        += RowNo;
			TextCount += LineNo[SceneCount][SerifCount];

			//Graph.Draw();

			//�Z���t�J�E���g��i�߂�
			SerifCount++;

			//�e�L�X�g�\�������t���O���ޯ��޷
			TextGraphEndFlag =  0;
			
			//���݃J�E���g���X�V
			//User.SetSaveData(SceneCount,TextCount,SerifCount);

		}else{
			TextGraphEndFlag = 1;
		}
	}
}

/*�X�L�b�v����*/
void TextClass::SkipFunction(UserClass &User){
	//�L�[�N���X�C���X�^���X�擾
	KeyClass* Key = KeyClass::GetInstance();

	//�ϐ��錾
	static int SkipCount = 0;

	//�X�L�b�v�`�F�b�N
	if( ( Key->GetState(KEY_INPUT_LCONTROL) > 0 || Key->GetState(KEY_INPUT_RCONTROL) >0 ) && SkipPermitFlag == 1){
		TextGraphEndFlag =  1;
		if( SkipCount % 3 == 0 ){
			TextCount += LineNo[SceneCount][SerifCount];
			SerifCount++;
			TextGraphEndFlag =  0;
			//User.SetSaveData(SceneCount,TextCount,SerifCount);
		}
		SkipCount++;
	}
}

/*���ǃ`�F�b�N*/
void TextClass::CheckRead(){
	short int ReadData[2];
	FILE *fp;

	//�萔
	enum{SCENE,TEXT,SERIF};

	//���ǃf�[�^�ǂݍ���
	fp = fopen("./resource/data/read.dat","rb+");
	fseek(fp,0L,SEEK_SET);
	fread(ReadData,2,sizeof(short int),fp);
	fclose(fp);
	
	//���ǃ`�F�b�N
	if( SceneCount < ReadData[SCENE] ){
		SkipPermitFlag = 1;
	}else if( SceneCount == ReadData[SCENE] ){
		if( TextCount < ReadData[TEXT] ) SkipPermitFlag = 1;
	}else{
		//�X�L�b�v�֎~
		SkipPermitFlag = 0;
		ReadData[SCENE] = SceneCount;
		ReadData[TEXT]  = TextCount;
		fp = fopen("./resource/data/read.dat","wb+");
		fwrite(ReadData,2,sizeof(short int),fp);
		fclose(fp);
	}

}

/*�I�[�g����*/
void TextClass::AutoFunction(UserClass &User){
	//�L�[�N���X�C���X�^���X�擾
	KeyClass* Key = KeyClass::GetInstance();

	//�ϐ��錾
	static int AutoCount = 0;
	const  int StopSpeed = 120;

	//�I�[�g�`�F�b�N
	if( Key->GetState(KEY_INPUT_A) == 1 )	AutoFlag *= -1;
	if( AutoFlag == 1 ) DrawStringShadow(10,windowY-50,"AutoMode...",GetColor(255,255,255),GetColor(5,5,5));
	if( AutoFlag == 1 && TextGraphEndFlag == 1 ){
		if( AutoCount % StopSpeed == 0 ){
			TextCount += LineNo[SceneCount][SerifCount];
			SerifCount++;
			TextGraphEndFlag =  0;
			//User.SetSaveData(SceneCount,TextCount,SerifCount);
		}
		AutoCount++;
	}
}

/*�A�C�L���b�`*/
 void TextClass::EyeCatching(UserClass &User){
	MouseClass* Mouse = MouseClass::GetInstance();

	const int MinVol    = 9000;
	const int FadeSpeed = 7;

	//static bool SoundBack  = FALSE;
	static bool FirstFlag  = FALSE;
	static bool PlayFlag   = FALSE;
	static bool FadeFlag1  = FALSE;
	static bool FadeFlag2  = TRUE;
	static int FadeCount   = 255;
	static int MovieVol;
	static int MovieHandle;
	static int TmpSoundCode;


	//���ʎ擾
	MovieVol = User.GetBGMVol() * 4;

	//���݂̃T�E���h�R�[�h�̃o�b�N�A�b�v
	//if( SoundBack == FALSE ){
	//	TmpSoundCode = User.GetBGMCode();
	//	SoundBack = TRUE;
	//}

	//���y��~ 
	User.SetBGMCode( GAME_BGM::STOP );

	//�t�F�[�h�A�E�g����
	if( FadeFlag1 == FALSE && FadeFlag2 == TRUE ){
		SetDrawBright(FadeCount,FadeCount,FadeCount);
		FadeCount -= FadeSpeed;
		if( FadeCount <= 0 ) FadeFlag1 = TRUE;
	}

	//�Đ��O�̏�����
	if( FirstFlag == FALSE && FadeFlag1 == TRUE ){
		SetDrawBright(255,255,255);
		MovieHandle = LoadGraph("./resource/movie/eyecatch.ogv");
		SetMovieVolumeToGraph( MinVol + MovieVol , MovieHandle );
		PlayMovieToGraph( MovieHandle );
		FirstFlag = TRUE;
		PlayFlag  = TRUE;
	}

	//����Đ�
	if( PlayFlag == TRUE ){
		DrawGraph(0,0,MovieHandle,TRUE);
		WaitTimer(17);
	}

	//�Đ��������f
	if( GetMovieStateToGraph(MovieHandle) != 1 && FadeFlag1 == TRUE ){
		PlayFlag  = FALSE;
		FirstFlag = FALSE;
		FadeFlag1 = FALSE;
		FadeFlag2 = FALSE;
	}

	//�t�F�[�h�C��
	if( FadeFlag2 == FALSE ){
		SetDrawBright(FadeCount,FadeCount,FadeCount);
		FadeCount += FadeSpeed;
		if( FadeCount >= 255 ){
			FadeFlag2 = TRUE;
			//SoundBack = FALSE;
			//User.SetBGMCode( TmpSoundCode );
			WriteMode = NORMAL;
		}
	}


	//���b�Z�[�W�`��
	//DrawString(300,windowY - windowY / 3 + 50,"�A�C�L���b�`����A�N���b�N�Ői�ނ���I",GetColor(0,0,0));

	//if( Mouse->GetState(MOUSE::LEFT) == 1 ){
	//	WriteMode = NORMAL;
	//}
}

/*�o�b�N���O*/
void TextClass::BackLogMain(UserClass &User){
	MouseClass* Mouse = MouseClass::GetInstance();
	static BackLogClass BackLog;
	
	//���낢��錾
	static int Count = 0;
	static int Flag  = 0;
	static int End1  = 0;
	static int End2  = 0;
	const  int Stop  = 10;
	const  int END_FLAG = -100000000;
	
	//10�t���[����~����
	if( Count > Stop ){
		if( Flag == 0 ){
			BackLog.Update(LineNo[SceneCount],SerifCount);
			Flag = 1;
		}
		End1 = BackLog.DrawLog(Name[SceneCount],Text[SceneCount]);
		//�O�̃V�[���ɃW�����v
		End2 = BackLog.Jump(TextCount,SerifCount,User);
	}
	Count++;

	//�o�b�N���O����߂�
	if( End1 == END_FLAG || End2 == END_FLAG ){
		if( End2 == END_FLAG ) BackCheckControlCode(User);
		WriteMode = NORMAL;
		Flag      = 0;
	}


}

/*�f�o�b�O�p���Ǒ���*/
void TextClass::ControlRead(){
	/*
	MouseClass* Mouse = MouseClass::GetInstance();
	FILE *fp;
	short int WriteData[2] = {10,10};

	//�f�o�b�O�p���ǃf�[�^�폜����
	if( Mouse->GetState(MOUSE::LEFT) ){

		//�폜
		if( Select == 3 ){
			fp = fopen("./resource/data/read.dat","wb+");
			WriteData[0] = SceneCount;
			WriteData[1] = TextCount;
			fwrite(WriteData,2,sizeof(short int),fp);
			fclose(fp);
		}

		//���߂�
		if( Select == 4 ){
			fp = fopen("./resource/data/read.dat","wb+");
			fwrite(WriteData,2,sizeof(short int),fp);
			fclose(fp);
		}
	}*/
}
			
/*�R���t�B�O�̖��ǃX�L�b�v���ݒ�*/
void TextClass::ReadUpdate(UserClass &User){
	short int WriteData[2];
	FILE *fp;

	int SkipFlag;

	//�X�L�b�v�t���O���擾
	SkipFlag = User.GetSkipFlag();

	//����
	if( SkipFlag == 0 ){
		SkipPermitFlag = 1;
		//fp = fopen("./resource/data/read.dat","wb+");
		//WriteData[0] = 999;
		//WriteData[1] = 999;
		//fwrite(WriteData,2,sizeof(short int),fp);
		//fclose(fp);
	}


	//�֎~
	if( SkipFlag == 1 ){
		SkipPermitFlag = 0;
	/*	fp = fopen("./resource/data/read.dat","wb+");
		WriteData[0] = SceneCount;
		WriteData[1] = TextCount;
		fwrite(WriteData,2,sizeof(short int),fp);
		fclose(fp);*/
	}
}

/*�E�B���h�E��\��*/
void TextClass::NotWindow(){
	auto Mouse = MouseClass::GetInstance();

	//�^�C�}�[
	static int Timer = 0;

	Timer++;

	if( Mouse->GetState( MOUSE::RIGHT ) > 0 && Timer > 20 ){
		WriteMode = NORMAL;
		Timer = 0;
	}
}

/*���Ԃ��o�����悤�Ɍ�����*/
void TextClass::OverTime(UserClass &User){

	//�e��ϐ��錾
	static int TmpMode;					//�O��̃��[�h
	static int FirstFlag;				//���߂̈�񂾂����s���邽�߂̃t���O
	std::string EventCode;				//�C�x���g�R�[�h���i�[

	static int  Count		= 255;		//���邳��ς���J�E���^
	static int  Timer		= 0;		//�^�C�}�[
	static bool BlackFlag	= FALSE;	//�Â��Ȃ����痧��
	static bool WhiteFlag	= FALSE;	//���邭�Ȃ����痧��
	static bool StopFlag    = FALSE;	//��~����t���O
			
	//����̂ݎ��s
	if( FirstFlag == FALSE ){
		TmpMode   = WriteMode;
		FirstFlag = TRUE;
		WriteMode = CHANGE;
	}

	//�C�x���g�R�[�h�󂯎��
	EventCode = Text[SceneCount][TextCount];

	//�R�[�h���u�o�߁v�Ȃ�
	if( EventCode == "�o��" ){
			
			//��ʂ̖��邳��ύX
			SetDrawBright(Count,Count,Count);

			//���邢�Ȃ�J�E���g�����A�Â��Ȃ�J�E���g�グ
			if( BlackFlag == FALSE ) Count-=5;
			else					 Count+=5;

			//���E�܂ŒB������e��t���O�𗧂Ă�
			if( Count < 0   )		 StopFlag  = TRUE;
			if( Count > 255 )		 WhiteFlag = TRUE;

			//��~�t���O�������Ă�Ȃ�^�C�}�[���Z
			if( StopFlag == TRUE ) Timer++;

			//30�t���[���ȏ�Ȃ�
			if( Timer > 30 ){
				Timer	  = 0;
				StopFlag  = FALSE;
				BlackFlag = TRUE;
			}

			//�S�Ă̏������I�������Ȃ�A�e�ϐ�������
			if( WhiteFlag == TRUE ){
				Count = 255;
				Timer = 0;
				BlackFlag = FALSE;
				WhiteFlag = FALSE;
				StopFlag  = FALSE;
				FirstFlag = FALSE;

				TextCount++;
				SerifCount++;
				WriteMode = TmpMode;
			}
		
		}
}

/*�Q�[���I�[�o�[*/
void TextClass::GameEnd(UserClass &User){
	//�萔
	const int DrawX = 250;
	const int DrawY = windowY - windowY / 3 + 10;
	


	//DrawStringToHandle(DrawX,DrawY,"�Q�[���I�[�o�[������A���ߍ��N���b�N�Ń^�C�g���߂��I",GetColor(0,0,0),TextFontHandle);
}

/*���݂̃f�[�^���Z�b�g*/
void TextClass::SetGameData(UserClass &User){
	//���Ԋ֌W
	time_t now;
	struct tm *Date;

	time(&now);
	Date = localtime(&now);
	
	SaveData.SceneCount = SceneCount;
	SaveData.TextCount  = TextCount;
	SaveData.SerifCount = SerifCount;
	SaveData.BGMCode    = User.GetBGMCode();
	SaveData.BackCode   = User.GetBackCode();
	SaveData.CharCode	= User.GetCharacterCode();
	SaveData.Year		= Date->tm_year+1900;
	SaveData.Mon		= Date->tm_mon+1;
	SaveData.Day		= Date->tm_mday;
	SaveData.TextLength = Text[SceneCount][TextCount].size();
	strcpy(SaveData.Text,Text[SceneCount][TextCount].c_str());

	//���݃J�E���g���X�V
	User.SetSaveData(SaveData);
}
	
/*����R�[�h�`�F�b�N*/
void TextClass::CheckCotrolCode(UserClass &User){
	//�e��R�[�h�󂯎��ϐ�
	std::string BGMCode;
	std::string BackCode;
	std::string EventCode;
	std::string CharacterCode;

	bool EventFlag = FALSE;

	do{
	
		EventFlag = FALSE;


		//���y����
		if( Name[SceneCount][TextCount] == "���y" ){
			//BGM�R�[�h�󂯎��
			BGMCode = Text[SceneCount][TextCount];
			if( BGMCode == "��z" )   User.SetBGMCode( GAME_BGM::KAISOU1 );
			if( BGMCode == "�o�" ) User.SetBGMCode( GAME_BGM::DEAI );
			if( BGMCode == "�ʂ�" )   User.SetBGMCode( GAME_BGM::WAKARE );
			if( BGMCode == "����" )   User.SetBGMCode( GAME_BGM::STOP );
			if( BGMCode == "�c��" )	  User.SetBGMCode( GAME_BGM::TITLE);
			TextCount++;
			SerifCount++;
			EventFlag = TRUE;
		}

	
		//�w�i�摜����
		if( Name[SceneCount][TextCount] == "�w�i" ){
			//�w�i�R�[�h�󂯎��
			BackCode = Text[SceneCount][TextCount];
			if( BackCode == "�È�" ) User.SetBackCode( GAME_BACK::BLACK  );
			if( BackCode == "�쌴" ) User.SetBackCode( GAME_BACK::KAWARA );
			if( BackCode == "���" ) User.SetBackCode( GAME_BACK::YOZORA );
			TextCount++;
			SerifCount++;
			EventFlag = TRUE;
		}
		
		//�L�����N�^�摜����
		if( Name[SceneCount][TextCount] == "�L����" ){
			//�L�����N�^�R�[�h�󂯎��
			CharacterCode = Text[SceneCount][TextCount];
			if( CharacterCode == "��"     ) User.SetCharacterCode( GAME_CHAR::AI );
			if( CharacterCode == "��\��" )	User.SetCharacterCode( GAME_CHAR::NOT );
			TextCount++;
			SerifCount++;
			EventFlag = TRUE;
		}

		//���Ԍo��
		if( Name[SceneCount][TextCount] == "�C�x���g" ){
			EventCode = Text[SceneCount][TextCount];
			if( EventCode == "�o��"       ) OverTime(User);
			if( EventCode == "�^�C�g����" ) WriteMode = TITLE;
		}
	
		//�G���h
		if( Name[SceneCount][TextCount] == "�G���h" ){
			TextCount++;
			SerifCount++;
			WriteMode = END;
		}

	}while( EventFlag == TRUE );
}

/*�o�b�N���O����߂����Ƃ��ɑO�̐���R�[�h���擾*/
void TextClass::BackCheckControlCode(UserClass &User){
	int TmpSceneCount,TmpTextCount;
	bool BGMFlag  = FALSE;
	bool BackFlag = FALSE;
	bool CharFlag = FALSE;
	std::string BGMCode;
	std::string BackCode;
	std::string CharacterCode;

	TmpSceneCount = SceneCount;
	TmpTextCount  = TextCount;
	
	//�Ȃ����������~
	User.SetBGMCode( GAME_BGM::STOP );
	User.SetCharacterCode( GAME_CHAR::NOT );

	while( TmpTextCount >= 0 ){
		//���y����
		if( Name[TmpSceneCount][TmpTextCount] == "���y" && BGMFlag == FALSE){
			//BGM�R�[�h�󂯎��
			BGMCode = Text[TmpSceneCount][TmpTextCount];
			if( BGMCode == "��z" )   User.SetBGMCode( GAME_BGM::KAISOU1 );
			if( BGMCode == "�o�" ) User.SetBGMCode( GAME_BGM::DEAI );
			if( BGMCode == "�ʂ�" )   User.SetBGMCode( GAME_BGM::WAKARE );
			if( BGMCode == "����" )   User.SetBGMCode( GAME_BGM::STOP );
			if( BGMCode == "�c��" )	  User.SetBGMCode( GAME_BGM::TITLE);
			BGMFlag = TRUE;
		}
	
		//�w�i�摜����
		if( Name[TmpSceneCount][TmpTextCount] == "�w�i" && BackFlag == FALSE ){
			//�w�i�R�[�h�󂯎��
			BackCode = Text[TmpSceneCount][TmpTextCount];
			if( BackCode == "�È�" ) User.SetBackCode( GAME_BACK::BLACK  );
			if( BackCode == "�쌴" ) User.SetBackCode( GAME_BACK::KAWARA );
			BackFlag = TRUE;
		}
		
		//�L�����N�^�摜����
		if( Name[TmpSceneCount][TmpTextCount] == "�L����"  && CharFlag == FALSE ){
			//�L�����N�^�R�[�h�󂯎��
			CharacterCode = Text[TmpSceneCount][TmpTextCount];
			if( CharacterCode == "��"     ) User.SetCharacterCode( GAME_CHAR::AI );
			if( CharacterCode == "��\��" )	User.SetCharacterCode( GAME_CHAR::NOT );
			CharFlag = TRUE;
		}
		
		//�J�E���g��������
		TmpTextCount--;
		
		//�����e�L�X�g�J�E���g��0�����������e�R�[�h��������
		if( TmpTextCount < 0 ){
			if( BGMFlag  == FALSE ) User.SetBGMCode( GAME_BGM::STOP );
			if( BackFlag == FALSE ) User.SetBackCode( GAME_BACK::BLACK );
			if( CharFlag == FALSE ) User.SetCharacterCode( GAME_CHAR::NOT );
		}
		
		//�S�ẴR�[�h���m�F���ꂽ�珈���𔲂���
		if( BGMFlag == TRUE && BackFlag == TRUE && CharFlag == TRUE  ) break;

	}
}