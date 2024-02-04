#include"../header/define.h" 


/*--------------------------
 | �y�[�W�N���X(���ۃN���X) |
  --------------------------*/
/*�y�[�W�J�ڏ���*/
void PageClass::MovePage(int Select,int FadeFlag,UserClass &User){
	//�N���b�N���ꂽ��y�[�W�ړ�
	if( FadeFlag == TRUE ) User.SetPage( Select );
}

/*���[�h�Z�b�g*/
void PageClass::SetMode(int Mode,int FadeFlag){
	if( FadeFlag == TRUE ) ModeFlag = Mode;
}

/*���[�h�擾*/
int PageClass::GetMode(){
	return ModeFlag;
}


/*----------------------
 | �^�C�g���y�[�W�N���X |
  ----------------------*/
/*������*/
TitlePageClass::TitlePageClass(){
	//�������샂�[�h�ݒ�
	ModeFlag = MODE::MAIN;
}

/*�^�C�g�����C��*/
void TitlePageClass::Main(UserClass &User){

	//BGM�Đ�
	Sound.SetVol(User);
	Sound.PlayMusic(User);

	//���[�h����
	switch( ModeFlag ){

		//���C�����[�h(�g�b�v���)
		case MODE::MAIN:
			Title.Main(ChangeFlag,User);	
			Title.ModeChange(ModeFlag,ChangeFlag,User);
		break;

		//���[�h���
		case MODE::LOAD:
			Save.Main(ChangeFlag);
			Save.Load(ModeFlag,User);
			Save.Delete(User);
			Save.ModeChange(ModeFlag,ChangeFlag,User);
		break;

		//���܂�
		case MODE::SECRET:

		break;

		//�R���t�B�O���
		case MODE::CONFIG:
			Conf.Main(User,ChangeFlag);
			Conf.ModeChange(ModeFlag,ChangeFlag,User);
		break;

	}

	//�y�[�W���ς��Ƃ��ABGM���~�߂�
	if( ModeFlag == MODE::OTHER ){
		Sound.StopBGM();		//���y���~
		ModeFlag = MODE::MAIN;	//���[�h�t���O��������
		ChangeFlag = TRUE;		//�`�F���W�t���O�𗧂Ă�
	}

}


/*--------------------
 | �Q�[���y�[�W�N���X |
  --------------------*/
/*������*/
GamePageClass::GamePageClass(){
	//�������샂�[�h�ݒ�
	ModeFlag = MODE::MAIN;
}

/*�Q�[�����C��*/
void GamePageClass::Main(UserClass &User){

	Sound.SetVol(User);		//����
	Sound.PlayMusic(User);	//���y�Đ�
	
	//���[�h�擾
	switch( ModeFlag ){
		//�Q�[�����C��
		case MODE::MAIN:
			Text.Main(User);
			Text.ModeChange(ModeFlag,ChangeFlag,User);
		break;		

		//�Z�[�u���
		case MODE::SAVE:
			Save.Main(ChangeFlag);
			Save.Save(User);
			Save.Delete(User);
			Save.ModeChange(ModeFlag,ChangeFlag,User);
		break;

		//���[�h���
		case MODE::LOAD:
			Save.Main(ChangeFlag);
			Save.Load(ModeFlag,User);
			Save.Delete(User);
			Save.ModeChange(ModeFlag,ChangeFlag,User);
		break;

		//�G���f�B���O
		case MODE::END:
			Sound.StopBGM();
			Ending.Main(User,ModeFlag);
		break;

		//�R���t�B�O���
		case MODE::CONFIG:
			Conf.Main(User,ChangeFlag);
			Conf.ModeChange(ModeFlag,ChangeFlag,User);
		break;
	}

	//�y�[�W���ς��Ƃ��A�㏈��������
	if( ModeFlag == MODE::OTHER ){
		Sound.StopBGM();			//���y���~	
		ModeFlag   = MODE::MAIN;	//���[�h�t���O��������
		ChangeFlag = TRUE;			//�`�F���W�t���O�𗧂Ă�
	}

}
			

/*--------------------------
 | �V�[�N���b�g�y�[�W�N���X |
  --------------------------*/
/*���C���֐�*/
void SecretPageClass::Main(UserClass &User){
	Secret.Main(User,ChangeFlag);

}