#include"../header/define.h" 

/*--------------
 | �Z�[�u�N���X |
  --------------*/
/*������*/
SaveClass::SaveClass(){
	ClickFlag      = 0;
	Page           = 0;
	Select		   = 0;
	MenuDialogFlag = FALSE;
	SaveDialogFlag = FALSE;
	LoadFlag	   = TRUE;

	//�p�����[�^�Z�b�g
	SetMenuParam();
}

/*���j���[�p�����[�^�Z�b�g*/
void SaveClass::SetMenuParam(){
	//���f�[�^
	SaveLeftParam.DrawX			= 0;
	SaveLeftParam.DrawY			= 60;
	SaveLeftParam.Interval		= 0;
	SaveLeftParam.Width			= 639;
	SaveLeftParam.Height		= 119;
	SaveLeftParam.ListMin		= 0;
	SaveLeftParam.ListMax		= 5;
	SaveLeftParam.AtherNo		= -1;
	SaveLeftParam.AlphaNo		= 100;
	SaveLeftParam.DrawFlag		= MENU::DATA;
	SaveLeftParam.DirectionFlag	= MENU::COL;

	//�E�f�[�^
	SaveRightParam.DrawX			= 640;
	SaveRightParam.DrawY			= 60;
	SaveRightParam.Interval			= 0;
	SaveRightParam.Width			= 640;
	SaveRightParam.Height			= 119;
	SaveRightParam.ListMin			= 5;
	SaveRightParam.ListMax			= 10;
	SaveRightParam.AtherNo			= -1;
	SaveRightParam.AlphaNo			= 100;
	SaveRightParam.DrawFlag			= MENU::DATA;
	SaveRightParam.DirectionFlag	= MENU::COL;

	//�i�r�Q�[�V����
	SaveNaviParam.DrawX			= 0;
	SaveNaviParam.DrawY			= 660;
	SaveNaviParam.Interval		= 0;
	SaveNaviParam.Width			= 320;
	SaveNaviParam.Height		= 60;
	SaveNaviParam.ListMin		= 10;
	SaveNaviParam.ListMax		= 14;
	SaveNaviParam.AtherNo		= -1;
	SaveNaviParam.AlphaNo		= 200;
	SaveNaviParam.DrawFlag		= MENU::IMAGE;
	SaveNaviParam.DirectionFlag	= MENU::ROW;
	SaveNaviParam.DrawHandle[0]	= LoadGraph("./resource/graph/BackGo.png");
	SaveNaviParam.DrawHandle[1]	= LoadGraph("./resource/graph/TitleBackGo.png");
	SaveNaviParam.DrawHandle[2]	= LoadGraph("./resource/graph/BackPage.png");
	SaveNaviParam.DrawHandle[3]	= LoadGraph("./resource/graph/FrontPage.jpg");

}

/*�Z�[�u���C���֐�*/
void SaveClass::Main(int &ChangeFlag){
	//�X�s�[�h�萔
	const int Speed = 30;
	enum{SCENE,TEXT,SERIF};
	enum{BGM,BACK,CHAR};
	enum{YEAR,MON,DAY};

	//���[�h�`�F���W���Ĉ���,�A�j���[�V������������
	if( ChangeFlag == TRUE ){
		Page       = 0;
		LoadFlag   = TRUE;
		ChangeFlag = FALSE;			//���[�h�`�F���W�t���O��܂�
		FadeFlag   = FALSE;			//�t�F�[�h�����t���O��܂�
		Graph.Anime.Reset();		//�A�j���N���X������
	}


	//�t�F�[�h�C��
	FadeFlag = Graph.Anime.FadeIn(Speed);

	//�Z�[�u�f�[�^�擾
	GetSaveData();

	//�Z�[�u�f�[�^�`��
	Draw(Select);

	//�Z�[�u�f�[�^���[�h
	LoadData.SceneCount = SaveCount[Page][Select][SCENE];
	LoadData.TextCount  = SaveCount[Page][Select][TEXT];
	LoadData.SerifCount = SaveCount[Page][Select][SERIF];
	LoadData.BGMCode    = SaveCode[Page][Select][BGM];
	LoadData.BackCode   = SaveCode[Page][Select][BACK];
	LoadData.CharCode   = SaveCode[Page][Select][CHAR];
	LoadData.Year       = SaveDate[Page][Select][YEAR];
	LoadData.Mon		= SaveDate[Page][Select][MON];
	LoadData.Day		= SaveDate[Page][Select][DAY];
	LoadData.TextLength = SaveTextLength[Page][Select][0];
	strcpy(LoadData.Text,SaveText[Page][Select]);

}

/*�Z�[�u��ʂ��烂�[�h�`�F���W*/
void SaveClass::ModeChange(int &ModeFlag,int &ChangeFlag,UserClass &User){
	//�C���X�^���X��
	MouseClass *Mouse = MouseClass::GetInstance();
	static DialogClass Dialog;

	//�萔��`
	enum{BACK=10,TITLEBACK};

	//�_�C�A���O�`��t���O���擾
	MenuDialogFlag = Dialog.GetDrawFlag();

	//���N���b�N����āA�t�F�[�h���I����Ă�
	if( Mouse->GetState(MOUSE::LEFT) == TRUE && FadeFlag == TRUE && MenuDialogFlag == FALSE ){
		switch( Select ){
			//�O�ɖ߂�
			case BACK:
				ModeFlag   = MODE::MAIN;
				ChangeFlag = TRUE;
			break;

			//�^�C�g���ɖ߂�
			case TITLEBACK:
				Dialog.SetSelectNo( Select , "�^�C�g���ɖ߂�܂����H");
			break;
		}
	}

	if( MenuDialogFlag == TRUE ){
		//�_�C�A���O�`��
		Dialog.Draw(User);

		//Yes�Ȃ珈��
		if( Dialog.GetSelectFlag() == DIALOG::YES ){
			
			//�I��ԍ��󂯎��
			Select = Dialog.GetSelectNo();

			//�^�C�g���Ȃ��
			if( Select == TITLEBACK ){
				ModeFlag = MODE::OTHER;
				User.SetPage( PAGE::TITLE );
				Dialog.Clear();
			}
		}
		
		//No�Ȃ�_�C�A���O�폜
		if( Dialog.GetSelectFlag() == DIALOG::NO ) 	Dialog.Clear();
	}
}

/*�Z�[�u�f�[�^�`��*/
void SaveClass::Draw(int &Select){
	//�Z�[�u�f�[�^�̐�
	const int SaveNo	  = 5;
	const int AtherSelect = -1;
	const int PageNo      = 3;
	enum{YEAR,MON,DAY};

	//�e�탁�j���[�錾
	static SaveMenuClass LeftMenu(SaveLeftParam);
	static SaveMenuClass RightMenu(SaveRightParam);
	static MenuClass NaviMenu(SaveNaviParam);

	//�����Ƃ��ēn���Z�[�u�f�[�^	
	Dvector_i	RightData_Date( 5 , vector<int>(3) );
	Dvector_i	LeftData_Date( 5 , vector<int>(3) );
	std::vector<char*> RightData_Text(5);
	std::vector<char*> LeftData_Text(5);

	//�f�[�^���
	for(int i=0 ; i<SaveNo ; i++ ){
		//���t
		LeftData_Date[i][YEAR]  = SaveDate[Page][i][YEAR];
		LeftData_Date[i][MON]   = SaveDate[Page][i][MON];
		LeftData_Date[i][DAY]   = SaveDate[Page][i][DAY];
		RightData_Date[i][YEAR] = SaveDate[Page][i+SaveNo][YEAR];
		RightData_Date[i][MON]  = SaveDate[Page][i+SaveNo][MON];
		RightData_Date[i][DAY]  = SaveDate[Page][i+SaveNo][DAY];
						
		//��s�e�L�X�g
		LeftData_Text[i]  = SaveText[Page][i];
		RightData_Text[i] = SaveText[Page][i+SaveNo];
		
	}

	/*�Z�[�u�f�[�^�X�V*/
	LeftMenu.UpdateData(LeftData_Date,LeftData_Text);
	RightMenu.UpdateData(RightData_Date,RightData_Text);

	/*���j���[�̑I��ԍ��擾*/
	if( MenuDialogFlag == FALSE && SaveDialogFlag == FALSE ){
		LeftMenu.Select();		
		RightMenu.Select();		
		NaviMenu.Select();
	}

	/*�w�i�`��*/
	Graph.Draw();

	/*���j���[�`��*/
	LeftMenu.Draw(Page);		
	RightMenu.Draw(Page);		
	NaviMenu.Draw();

	/*�I�𒆔ԍ����擾*/
	Select = NaviMenu.GetSelectNo();
	if( Select == AtherSelect ) Select = RightMenu.GetSelectNo();
	if( Select == AtherSelect ) Select = LeftMenu.GetSelectNo();

	//�y�[�W�؂�ւ�
	ChangePage();

}

/*�Z�[�u�f�[�^�̎擾*/
void SaveClass::GetSaveData(){
	//�t�@�C���|�C���^�錾
	FILE *fp;
	int TmpHash = 0;

	const int Key = 7;

	//�ǂݍ��݃t���O�������Ă�Ȃ�
	if( LoadFlag == TRUE ){
		//�ϐ�������
		Hash = 0;
		memset(SaveCount,0,sizeof(SaveCount));
		memset(SaveCode,0,sizeof(SaveCode));
		memset(SaveDate,0,sizeof(SaveDate));
		memset(SaveTextLength,0,sizeof(SaveTextLength));
		memset(SaveText,0,sizeof(SaveText));

		//�t�@�C���I�[�v��
		fp = fopen("./resource/data/save.dat","rb+");
	
		//�f�[�^�󂯎��
		fseek(fp,0L,SEEK_SET);
		for( int j=0 ; j<3  ; j++ ){
			for( int i=0 ; i<10 ; i++ ){
				fread(&Hash,1,sizeof(int),fp);
				fread(SaveCount[j][i],3,sizeof(short int),fp);
				fread(SaveCode[j][i],3,sizeof(int),fp);
				fread(SaveDate[j][i],3,sizeof(int),fp);
				fread(SaveTextLength[j][i],1,sizeof(int),fp);
				TextSize = (size_t)SaveTextLength[j][i][0];
				fread(SaveText[j][i],1,sizeof(SaveText[j][i]),fp);

				//�n�b�V���l�v�Z
				for( int h=0 ; h<3 ; h++ ) TmpHash += SaveCount[j][i][h];
				TmpHash = Hash^Key;
				TmpHash = Hash%Key;
				if( Hash != TmpHash ){
					//�����I��
					MessageBox(NULL,"�ǂ����ăf�[�^�̉�₂Ȃ�Ă����̂��I\n(�v���O�����̕s��̏ꍇ�͊J���҂܂ŘA�����������B)","�Ă����΃������p��",MB_OK);
					exit(0);
				}
				TmpHash = 0;
			}
		}
		//�t�@�C���N���[�Y
		fclose(fp);
		
		//�ǂݍ��݃t���O���ޯ��޷
		LoadFlag = FALSE;
	}
}

/*�f�[�^�Z�[�u*/
void SaveClass::Save(UserClass &User){
	//�C���X�^���X��
	MouseClass* Mouse = MouseClass::GetInstance();
	static DialogClass Dialog;

	//���낢��錾
	FILE *fp;
	static int  TrueSelect = 12;

	//�ϐ��B
	short int SceneCount = 0;
	short int TextCount  = 0;
	short int SerifCount = 0;
	SaveData_rec SaveData;

	//�萔
	enum{SCENE,TEXT,SERIF};
	enum{BGM,BACK,CHAR};
	enum{YEAR,MON,DAY};
	const int SaveDataMin = 0;
	const int SaveDataMax = 10;
	const int Key		  = 7;

	//�^�C�g���`��
	SetFontSize(40);
	DrawString(20,20,"�\ �Z�[�u��� �\",GetColor(255,255,255));

	//�_�C�A���O�`��t���O���擾
	SaveDialogFlag = Dialog.GetDrawFlag();

	//���N���b�N���ꂽ��
	if( Mouse->GetState(MOUSE::LEFT) == TRUE && FadeFlag == TRUE && SaveDialogFlag == FALSE && DeleteDialogFlag == FALSE ){
		if( SaveDataMin <= Select && Select < SaveDataMax ){
			Dialog.SetSelectNo( Select , "�Z�[�u���Ă����ł����H" );
		}
	}

	if( SaveDialogFlag == TRUE ){
		
		//�_�C�A���O�`��
		Dialog.Draw(User);

		//Yes�̏ꍇ
		if( Dialog.GetSelectFlag() == DIALOG::YES ){
			
			//�I��ԍ��󂯎��
			Select = Dialog.GetSelectNo();

			//�t�@�C���I�[�v��
			fp = fopen("./resource/data/save.dat","wb+");

			//���݂̃f�[�^�ǂݍ���
			SaveData = User.GetSaveData();
		
			SaveCount[Page][Select][SCENE]  = SaveData.SceneCount ; 
			SaveCount[Page][Select][TEXT]   = SaveData.TextCount  ; 
			SaveCount[Page][Select][SERIF]  = SaveData.SerifCount ;
			SaveCode[Page][Select][BGM]     = SaveData.BGMCode    ;
			SaveCode[Page][Select][BACK]    = SaveData.BackCode   ;
			SaveCode[Page][Select][CHAR]    = SaveData.CharCode	  ;
			SaveDate[Page][Select][YEAR]    = SaveData.Year       ;
			SaveDate[Page][Select][MON]     = SaveData.Mon	      ;
			SaveDate[Page][Select][DAY]     = SaveData.Day		  ;
			SaveTextLength[Page][Select][0] = SaveData.TextLength ; 
			strcpy(SaveText[Page][Select],SaveData.Text);


			//�Z�[�u�f�[�^��������
			for( int j=0 ; j<3 ; j++ ){
				for( int i=0 ; i<10 ; i++ ){
					
					//�n�b�V���l�v�Z
					for( int h=0 ; h<3 ; h++ ) Hash += SaveCount[j][i][h];
					Hash = Hash^Key;
					Hash = Hash%Key;

					fwrite(&Hash,1,sizeof(int),fp);
					fwrite(SaveCount[j][i],3,sizeof(short int),fp);
					fwrite(SaveCode[j][i],3,sizeof(int),fp);
					fwrite(SaveDate[j][i],3,sizeof(int),fp);
					fwrite(SaveTextLength[j][i],1,sizeof(int),fp);
					TextSize = (size_t)SaveTextLength[j][i][0];
					fwrite(SaveText[j][i],1,sizeof(SaveText[j][i]),fp);
				}
			}

			//�t�@�C���N���[�Y
			fclose(fp);
			Dialog.Clear();
		}

		//No�̏ꍇ
		if( Dialog.GetSelectFlag() == DIALOG::NO ){
			//�_�C�A���O�폜
			Dialog.Clear();
		}	
	}
}
	
/*�Z�[�u�f�[�^���[�h*/
void SaveClass::Load(int &ModeFlag,UserClass& User){
	//�C���X�^���X��
	MouseClass* Mouse = MouseClass::GetInstance();
	static DialogClass Dialog;

	//�萔��`
	const int SaveDataMin = 0;
	const int SaveDataMax = 10;

	//�^�C�g���`��
	SetFontSize(40);
	DrawString(20,20,"�\ ���[�h��� �\",GetColor(255,255,255));

	//�_�C�A���O�`��t���O���擾
	SaveDialogFlag = Dialog.GetDrawFlag();

	//���N���b�N����āA�t�F�[�h���������Ă���
	if( Mouse->GetState(MOUSE::LEFT) == TRUE && FadeFlag == TRUE && SaveDialogFlag == FALSE && DeleteDialogFlag == FALSE ){
		if( SaveDataMin <= Select && Select < SaveDataMax && SaveDate[Page][Select][0] != 0 ){
			Dialog.SetSelectNo( Select , "���[�h���Ă�낵���ł����H" );
		}
	}


	//�_�C�A���O���`�悳��Ă���Ȃ��
	if( SaveDialogFlag == TRUE ){
		
		//�_�C�A���O�`��
		Dialog.Draw(User);

		//Yes�Ȃ�
		if( Dialog.GetSelectFlag() == DIALOG::YES ){

			//�I��ԍ����󂯎��
			Select = Dialog.GetSelectNo();

			//�ǂݍ��ݏ���
			User.SetSaveData(LoadData);
			ModeFlag = MODE::OTHER;
			User.SetPage( PAGE::GAME );

			//�_�C�A���O�폜
			Dialog.Clear();
		}

		//No�Ȃ�
		if( Dialog.GetSelectFlag() == DIALOG::NO ){
			Dialog.Clear();
		}
	}

}

/*�y�[�W�؂�ւ�*/
void SaveClass::ChangePage(){
	auto *Mouse = MouseClass::GetInstance();

	static int  Timer     = 0;
	static bool ClickOk   = TRUE;
	static bool ClickFlag = 0;

	if( Mouse->GetState(MOUSE::LEFT) == 1 && ClickFlag == FALSE ){

		ClickFlag = TRUE;
		
		if( Select == 12 ) Page = ( Page + 2 ) % 3;
		if( Select == 13 ) Page = ( Page + 1 ) % 3;

	}

	if( ClickFlag == TRUE ) Timer++;
	if( Timer > 10       ){
		ClickFlag = FALSE;
		Timer = 0;
	}

}

/*�Z�[�u�f�[�^�폜*/
void SaveClass::Delete(UserClass &User){
	//�C���X�^���X��
	MouseClass* Mouse = MouseClass::GetInstance();
	static DialogClass Dialog;

	//���낢��錾
	FILE *fp;
	static int  TrueSelect = 12;
	static int  Timer      = 0;

	//�ϐ��B
	short int SceneCount = 0;
	short int TextCount  = 0;
	short int SerifCount = 0;
	SaveData_rec SaveData;
	int Hash = 0;

	//�萔
	enum{SCENE,TEXT,SERIF};
	enum{BGM,BACK,CHAR};
	enum{YEAR,MON,DAY};
	const int SaveDataMin = 0;
	const int SaveDataMax = 10;
	const int Key = 7;

	//�_�C�A���O�`��t���O���擾
	DeleteDialogFlag = Dialog.GetDrawFlag();

	//���N���b�N���ꂽ��
	if( Mouse->GetState(MOUSE::RIGHT) == TRUE && FadeFlag == TRUE && SaveDialogFlag == FALSE && DeleteDialogFlag == FALSE ){
		if( SaveDataMin <= Select && Select < SaveDataMax && SaveDate[Page][Select][YEAR] != 0){
			Dialog.SetSelectNo( Select , "�폜���܂���H" );
			Timer = 0;
		}
	}

	if( DeleteDialogFlag == TRUE ){
		
		//�_�C�A���O�`��
		Dialog.Draw(User);

		//Yes�̏ꍇ
		if( Dialog.GetSelectFlag() == DIALOG::YES ){
			
			//�I��ԍ��󂯎��
			Select = Dialog.GetSelectNo();

			//�t�@�C���I�[�v��
			fp = fopen("./resource/data/save.dat","wb+");
			
			//��f�[�^����
			//Hash							= 0;
			SaveCount[Page][Select][SCENE]  = 0;
			SaveCount[Page][Select][TEXT]   = 0; 
			SaveCount[Page][Select][SERIF]  = 0;
			SaveCode[Page][Select][BGM]     = 0;
			SaveCode[Page][Select][BACK]    = 0; 
			SaveCode[Page][Select][CHAR]	= 0;
			SaveDate[Page][Select][YEAR]    = 0;
			SaveDate[Page][Select][MON]     = 0;
			SaveDate[Page][Select][DAY]     = 0;
			SaveTextLength[Page][Select][0] = 0; 
			//strcpy(SaveText[Page][Select],"\0");
			memset(SaveText[Page][Select],'\0',sizeof(SaveText[Page][Select]));


			//�Z�[�u�f�[�^��������
			for( int j=0 ; j<3 ; j++ ){
				for( int i=0 ; i<10 ; i++ ){
					//�n�b�V���l�v�Z
					for( int h=0 ; h<3 ; h++ ) Hash += SaveCount[j][i][h];
					Hash = Hash^Key;
					Hash = Hash%Key;

					fwrite(&Hash,1,sizeof(int),fp);
					fwrite(SaveCount[j][i],3,sizeof(short int),fp);
					fwrite(SaveCode[j][i],3,sizeof(int),fp);
					fwrite(SaveDate[j][i],3,sizeof(int),fp);
					fwrite(SaveTextLength[j][i],1,sizeof(int),fp);
					TextSize = (size_t)SaveTextLength[j][i][0];
					fwrite(SaveText[j][i],1,sizeof(SaveText[j][i]),fp);
				}
			}

			//�t�@�C���N���[�Y
			fclose(fp);
			//Timer++;
			Dialog.Clear();
		}

		//No�̏ꍇ
		if( Dialog.GetSelectFlag() == DIALOG::NO ){
			//�_�C�A���O�폜
			Dialog.Clear();
			
		}	
	}
}
	