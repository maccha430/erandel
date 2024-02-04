#include"../header/define.h" 

/*----------------
 | ���j���[�N���X |
  ----------------*/
/*�I�����Ɏg�������Z�b�g*/
MenuClass::MenuClass(MenuArg_rec &MenuArg){
	//�p�����[�^�擾
	DrawX			= MenuArg.DrawX;			//�`��I�u�W�F�N�g�̍���X
	DrawY			= MenuArg.DrawY;			//�`��I�u�W�F�N�g�̍���Y
	Interval		= MenuArg.Interval;			//�`��I�u�W�F�N�g���m�̊Ԋu
	Height		    = MenuArg.Height;			//�`��I�u�W�F�N�g�̍���
	ListMin			= MenuArg.ListMin;			//�`��I�u�W�F�N�g�̏����i���o�[
	ListMax			= MenuArg.ListMax;			//�`��I�u�W�F�N�g�̍ő�i���o�[
	AtherNo			= MenuArg.AtherNo;			//�`��I�u�W�F�N�g��I�����Ă��ȂƂ��ɕԂ��i���o�[
	AlphaNo			= MenuArg.AlphaNo;			//�I�𒆃I�u�W�F�N�g�̓����x
	DrawFlag		= MenuArg.DrawFlag;			//�`�悷��I�u�W�F�N�g�̎��(0==�摜�`�� 1==�e�L�X�g�`��)
	DirectionFlag	= MenuArg.DirectionFlag;	//�`�����(0==�c 1==��)

	//�`��I�u�W�F�N�g�擾
	for( int i=0 ; i<ListMax-ListMin ; i++ ){								//�`��I�u�W�F�N�g�����[�v
		if( DrawFlag == MENU::IMAGE ){
			DrawHandle[i] = MenuArg.DrawHandle[i];							//�`��摜���擾
			Width[i]      = MenuArg.Width;									//�摜�̉������擾
		}
		if( DrawFlag == MENU::TEXT ){
			strcpy(DrawText[i],MenuArg.DrawText[i]);						//�`��e�L�X�g���擾
			Width[i]      = strlen(MenuArg.DrawText[i])*(MenuArg.Width/2);	//�e�L�X�g�̉������擾
			TextColor     = MenuArg.TextColor;								//�e�L�X�g�̐F���擾
			FontSize      = MenuArg.Width;									//�t�H���g�T�C�Y�擾
			FontFamily	  = MenuArg.FontFamily;								//�t�H���g�t�@�~���[�擾
		}
		if( DrawFlag == MENU::DATA ){
			Width[i]	  = MenuArg.Width;
		}
	}

}

/*���j���[�ݒu����*/
void MenuClass::Create(){
	Select();	//���j���[�I������
	Draw();		//���j���[�`�揈��
}

/*���j���[�I������*/
void MenuClass::Select(){
	//�ϐ��錾
	static int x,y;
	int i;
	int RowWidth=0;

	//�C���X�^���X��
	MouseClass* Mouse = MouseClass::GetInstance();

	//�}�E�X���W�擾
	Mouse->GetPoint(&x,&y);


	//�}�E�X�I���擾(�c���т̏ꍇ)
	if( DirectionFlag == MENU::COL ){
		for( i=0 ; i<ListMax-ListMin ; i++ ){
			if( x >= DrawX && x <= DrawX + Width[i] ){
				if( y >= DrawY + ( Interval + Height ) * i && y <= DrawY + ( Interval + Height ) * i + Height ){
					SelectNo = i;
					break;
				}
			}
		}
	}

	//�}�E�X�I���擾(�����т̏ꍇ)
	if( DirectionFlag == MENU::ROW ){
		for( i=0 ; i<ListMax-ListMin ; i++ ){
			
			//��̌��ݒn�܂ł̉������擾
			for( int p=0 ; p<i ; p++ ) RowWidth = Width[p]+Interval;

			//�}�E�X�I���擾
			if( x >= DrawX + RowWidth  * i && x <= DrawX + RowWidth * i + Width[i] ){
				if( y >= DrawY && y <= DrawY + Height ){
					SelectNo = i;
					break;
				}
			}
		}
	}

	//���j���[��I�����Ă��Ȃ���΃t���O��܂�(ListMin�ň����Ă�̂́A�l��n���Ƃ���ListMin�����Z���Ă��܂�����)
	if( i+ListMin == ListMax ) SelectNo = AtherNo-ListMin;

}

/*���j���[�`�揈��*/
void MenuClass::Draw(){
	//�ϐ��錾
	int RowWidth = 0;
	static int FirstFlag;
	static int FontHandle;

	//�t�H���g�֘A�ݒ�
	if( DrawFlag == 1 ){
		if( FontFamily == MENU::GOSIC ) ChangeFont("�l�r �S�V�b�N");
		if( FontFamily == MENU::MINTYO) ChangeFont("�l�r ����");

		if( FirstFlag == 0 ){
			FontHandle = CreateFontToHandle( NULL , FontSize , -1 , DX_FONTTYPE_ANTIALIASING );
			FirstFlag++;
		}
		SetFontSize(FontSize);
	}

	//���j���[�`��(�c���т̏ꍇ)
	if( DirectionFlag == MENU::COL ){
		for( int i=0 ; i<ListMax-ListMin ; i++ ){
			if( SelectNo == i ) SetDrawBlendMode(DX_BLENDMODE_ALPHA,AlphaNo);
			//if( SelectNo == i ) TextColor = GetColor(255,0,0);
			//else				TextColor = GetColor(40,40,40);


			if( DrawFlag == MENU::IMAGE ) DrawGraph(  DrawX , DrawY + ( Interval + Height ) * i , DrawHandle[i] , TRUE );
			if( DrawFlag == MENU::TEXT )  DrawStringShadow( DrawX , DrawY + ( Interval + Height ) * i , DrawText[i] , TextColor , GetColor(0,0,0));
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
		}
	}

	//���j���[�`��(�����т̏ꍇ)
	if( DirectionFlag == MENU::ROW ){
		for( int i=0 ; i<ListMax-ListMin ; i++ ){
			//��̌��ݒn�܂ł̉������擾
			for( int p=0 ; p<i ; p++ ) RowWidth = Width[p]+Interval;

			//�I�u�W�F�N�g�`��
			if( SelectNo == i ) SetDrawBlendMode(DX_BLENDMODE_ALPHA,AlphaNo);
			if( DrawFlag == MENU::IMAGE ) DrawGraph(  DrawX + RowWidth * i,DrawY , DrawHandle[i] , TRUE );
			if( DrawFlag == MENU::TEXT )  DrawString( DrawX + RowWidth * i,DrawY , DrawText[i] , TextColor ); 
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
		}
	}

}

/*�I�𒆔ԍ��擾*/
int MenuClass::GetSelectNo(){
	return SelectNo+ListMin;
}


/*----------------------
 | �Z�[�u���j���[�N���X |
  ----------------------*/
/*������*/
SaveMenuClass::SaveMenuClass(MenuArg_rec &MenuArg):MenuClass(MenuArg){}

/*�Z�[�u�f�[�^�`��*/
void SaveMenuClass::Draw(int Page){
	//�ϐ��錾
	//char Str[256];
	std::vector<std::string> Str(2);
	char TmpDateText[100];

	//�萔
	enum{SCENE,TEXT,SERIF};
	enum{YEAR,MON,DAY};
	enum{DATE};
	const int FontSize = 24;

	//�t�H���g�T�C�Y�Z�b�g
	SetFontSize(FontSize);

	//���ڐ��J��Ԃ�
	for( int i=0 ; i<ListMax-ListMin ; i++ ){
		//�f�[�^������΁A������
		if( SaveDate[i][YEAR] != 0){
			//�f�[�^���H
			sprintf(TmpDateText,"%d�N%d��%d��",SaveDate[i][YEAR],SaveDate[i][MON],SaveDate[i][DAY]);
			if( strlen( SaveText[i] ) > 40 ){
				SaveText[i][42] = '.';
				SaveText[i][43] = '.';
				SaveText[i][44] = '.';
				SaveText[i][45] = '\0';
			}

			//���H�f�[�^���
			Str[DATE] = TmpDateText;
			Str[TEXT] = SaveText[i];
		}else{
			Str[DATE] = "Not Found.";
			Str[TEXT] = "";
		}

		//�w�i�`��
		if( SelectNo == i )		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
		else					SetDrawBlendMode(DX_BLENDMODE_ALPHA,AlphaNo);
		/******************�t�̃}�W�b�N�i���o�[�Ղ�****************/
		DrawBox(DrawX+5,DrawY+Height*i+5,DrawX+Width[i]-5,Height+60+(Height*i)-5,GetColor(30,30,30),TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);

		//�f�[�^�`��
		DrawString(DrawX+FontSize,DrawY+30+(Height*i),Str[DATE].c_str(),GetColor(255,255,255));
		DrawString(DrawX+FontSize,DrawY+30+40+((Height)*i),Str[TEXT].c_str(),GetColor(255,255,255));

		//�y�[�W�ԍ��`��
		DrawFormatString(1000,20,GetColor(255,255,255),"�\ %d�y�[�W �\",Page+1);
	}
}

/*�Z�[�u�f�[�^�X�V*/
void SaveMenuClass::UpdateData(Dvector_i Date,std::vector<char*> Text){
	this->SaveDate = Date;
	this->SaveText = Text;
}

/*------------------------
 | �^�C�g�����j���[�N���X |
  ------------------------*/
/*������*/
TitleMenuClass::TitleMenuClass(MenuArg_rec &MenuArg):MenuClass(MenuArg){}

/*�`��*/
void TitleMenuClass::Draw(){
	//�ϐ��錾
	int RowWidth = 0;
	static int FirstFlag;
	static int FontHandle;

	//�t�H���g�֘A�ݒ�
	if( DrawFlag == 1 ){
		if( FontFamily == MENU::GOSIC ) ChangeFont("�l�r �S�V�b�N");
		if( FontFamily == MENU::MINTYO) ChangeFont("�l�r ����");

		if( FirstFlag == 0 ){
			FontHandle = CreateFontToHandle( NULL , FontSize , -1 , DX_FONTTYPE_ANTIALIASING );
			FirstFlag++;
		}
		SetFontSize(FontSize);
	}

	//���j���[�`��(�c���т̏ꍇ)
	if( DirectionFlag == MENU::COL ){
		for( int i=0 ; i<ListMax-ListMin ; i++ ){
			//if( SelectNo == i ) SetDrawBlendMode(DX_BLENDMODE_ALPHA,AlphaNo);
			if( SelectNo == i ) TextColor = GetColor(255,0,0);
			else				TextColor = GetColor(40,40,40);
			
			//DrawStringS(DrawX,DrawY-50,"���킵��",GetColor(255,255,255),28);

			if( DrawFlag == MENU::IMAGE ) DrawGraph(  DrawX , DrawY + ( Interval + Height ) * i , DrawHandle[i] , TRUE );
			if( DrawFlag == MENU::TEXT )  DrawStringShadow( DrawX , DrawY + ( Interval + Height ) * i , DrawText[i] , TextColor , GetColor(230,230,230));
			//SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
		}
	}

	//���j���[�`��(�����т̏ꍇ)
	if( DirectionFlag == MENU::ROW ){
		for( int i=0 ; i<ListMax-ListMin ; i++ ){
			//��̌��ݒn�܂ł̉������擾
			for( int p=0 ; p<i ; p++ ) RowWidth = Width[p]+Interval;

			//�I�u�W�F�N�g�`��
			if( SelectNo == i ) SetDrawBlendMode(DX_BLENDMODE_ALPHA,AlphaNo);
			if( DrawFlag == MENU::IMAGE ) DrawGraph(  DrawX + RowWidth * i,DrawY , DrawHandle[i] , TRUE );
			if( DrawFlag == MENU::TEXT )  DrawString( DrawX + RowWidth * i,DrawY , DrawText[i] , TextColor ); 
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
		}
	}
}


/*--------------------------
 | �R���t�B�O���j���[�N���X |
  --------------------------*/
/*������*/
ConfigListClass::ConfigListClass(int SetNo,MenuArg_rec &MenuArg):MenuClass(MenuArg){
	this->SetNo = SetNo;
}

/*�R���t�B�O���j���[�`��*/
void ConfigListClass::Draw(){
	//�ϐ��錾
	int RowWidth = 0;
	static int FirstFlag;
	static int FontHandle;

	//�t�H���g�֘A�ݒ�
	if( FontFamily == MENU::GOSIC ) ChangeFont("�l�r �S�V�b�N");
	if( FontFamily == MENU::MINTYO) ChangeFont("�l�r ����");
	//SetFontSize(FontSize);

	if( FirstFlag == 0 ){
		FontHandle = CreateFontToHandle( NULL , FontSize , -1 , DX_FONTTYPE_ANTIALIASING );
		FirstFlag++;
	}

	//���j���[�`��
	for( int i=0 ; i<ListMax-ListMin ; i++ ){
		//��̌��ݒn�܂ł̉������擾
		for( int p=0 ; p<i ; p++ ) RowWidth = Width[p]+Interval;

		//�I�u�W�F�N�g�`��
		if( SelectNo == i || SetNo == i ){
			//SetDrawBlendMode(DX_BLENDMODE_ALPHA,AlphaNo);
			//SetDrawBlendMode(DX_BLENDMODE_ADD,255);
			TextColor = GetColor(255,80,80);
		}else TextColor = GetColor(255,255,255);
		//if( DrawFlag == MENU::IMAGE ) DrawGraph(  DrawX + RowWidth * i,DrawY , DrawHandle[i] , TRUE );
		if( DrawFlag == MENU::TEXT )  DrawStringToHandle( DrawX + RowWidth * i,DrawY , DrawText[i] , TextColor , MenuFontHandle ); 
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	}


}


/*----------------------------
 | �V�[�N���b�g���j���[�N���X |
  ----------------------------*/
/*������*/
SecretMenuClass::SecretMenuClass(MenuArg_rec &MenuArg):MenuClass(MenuArg){}

/*�`��*/
void SecretMenuClass::Draw(int SetNo){
	//�ϐ��錾
	int RowWidth = 0;
	static int FirstFlag;
	static int FontHandle;

	//�t�H���g�֘A�ݒ�
	if( DrawFlag == 1 ){
		if( FontFamily == MENU::GOSIC ) ChangeFont("�l�r �S�V�b�N");
		if( FontFamily == MENU::MINTYO) ChangeFont("�l�r ����");

		if( FirstFlag == 0 ){
			FontHandle = CreateFontToHandle( NULL , FontSize , -1 , DX_FONTTYPE_ANTIALIASING );
			FirstFlag++;
		}
		SetFontSize(FontSize);
	}

	//���j���[�`��(�c���т̏ꍇ)
	if( DirectionFlag == MENU::COL ){
		for( int i=0 ; i<ListMax-ListMin ; i++ ){
			//if( SelectNo == i ) SetDrawBlendMode(DX_BLENDMODE_ALPHA,AlphaNo);
			if( SelectNo == i || SetNo == i ) TextColor = GetColor(255,0,0);
			else				TextColor = GetColor(255,255,255);


			if( DrawFlag == MENU::IMAGE ) DrawGraph(  DrawX , DrawY + ( Interval + Height ) * i , DrawHandle[i] , TRUE );
			if( DrawFlag == MENU::TEXT )  DrawStringShadow( DrawX , DrawY + ( Interval + Height ) * i , DrawText[i] , TextColor , GetColor(0,0,0));
			//SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
		}
	}

	//���j���[�`��(�����т̏ꍇ)
	if( DirectionFlag == MENU::ROW ){
		for( int i=0 ; i<ListMax-ListMin ; i++ ){
			//��̌��ݒn�܂ł̉������擾
			for( int p=0 ; p<i ; p++ ) RowWidth = Width[p]+Interval;

			//�I�u�W�F�N�g�`��
			if( SelectNo == i ) SetDrawBlendMode(DX_BLENDMODE_ALPHA,AlphaNo);
			if( DrawFlag == MENU::IMAGE ) DrawGraph(  DrawX + RowWidth * i,DrawY , DrawHandle[i] , TRUE );
			if( DrawFlag == MENU::TEXT )  DrawString( DrawX + RowWidth * i,DrawY , DrawText[i] , TextColor ); 
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
		}
	}

}