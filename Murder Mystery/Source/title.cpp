#include"../header/define.h" 

/*----------------
 | �^�C�g���N���X |
  ----------------*/
/*�^�C�g�����C�����[�h*/
void TitleClass::Main(int &ChangeFlag,UserClass &User){
	bool SecretFlag;
	
	User.SetSecretFlag();
	SecretFlag = User.GetSecretFlag();

	//���j���[�p�����[�^�Z�b�g
	static struct MenuArg_rec MenuParam;
	SetMenuParam_Title(MenuParam,SecretFlag);
	TitleMenuClass Menu(MenuParam);

	//�萔�錾
	const int Speed = 10;	//�t�F�[�h�C�����x

	//���[�h�`�F���W���Ĉ���
	if( ChangeFlag == TRUE ){
		ChangeFlag = FALSE;			//���[�h�`�F���W�t���O��܂�
		FadeFlag   = FALSE;			//�t�F�[�h�����t���O��܂�
		Graph.Anime.Reset();		//�A�j���[�V�������Z�b�g
	}

	//�t�F�[�h�C��
	FadeFlag = Graph.Anime.FadeIn(Speed);

	//�w�i�`��
	Graph.Draw();

	//�^�C�g�����j���[�ݒu
	Menu.Create();

	//�Z�[�u�f�[�^������
	InitSaveData(User);

	//���ݑI�𒆂̃��j���[���擾
	Select = Menu.GetSelectNo();
}

/*���샂�[�h�`�F���W*/
void TitleClass::ModeChange(int &ModeFlag,int &ChangeFlag,UserClass &User){
	//�C���X�^���X��
	MouseClass* Mouse = MouseClass::GetInstance();

	//�Z�[�u�\���̐錾
 	struct SaveData_rec SaveData;

	//���N���b�N���ꂽ
	if( Mouse->GetState(MOUSE::LEFT) == TRUE && FadeFlag == TRUE ){
		//�R���e�B�j���[
		if( Select == TITLE::LOAD ){
			ModeFlag   = MODE::LOAD;
			ChangeFlag = TRUE;
		}

		//�R���t�B�O
		if( Select == TITLE::CONFIG ){
			ModeFlag   = MODE::CONFIG;
			ChangeFlag = TRUE;
		}

		//�Q�[���X�^�[�g
		if( Select == TITLE::START ){
			ModeFlag = MODE::OTHER;
			User.SetPage( PAGE::GAME );

			//�Q�[���J�E���g������
			InitSaveData(User);
			//User.SetSaveData(SaveData);	
		}

		//���܂�
		if( Select == TITLE::SECRET && User.GetSecretFlag() == TRUE ){
			ModeFlag   = MODE::OTHER;
			User.SetPage( PAGE::SECRET );
		}

		//�Q�[���I��
		if( Select == TITLE::END ){
			ModeFlag = MODE::OTHER;
			User.SetPage( PAGE::END );
		}
	}

}

/*�^�C�g���N���X*/
void TitleClass::InitSaveData(UserClass &User){
	SaveData_rec SaveData;
	
	SaveData.SceneCount = 0;
	SaveData.TextCount  = 0;
	SaveData.SerifCount = 0;
	SaveData.BGMCode    = GAME_BGM::STOP;
	SaveData.BackCode   = GAME_BACK::BLACK;
	SaveData.CharCode   = GAME_CHAR::NOT;
	SaveData.Year		= 0;
	SaveData.Mon		= 0;
	SaveData.Day		= 0;
	SaveData.TextLength = 0;
	memset(SaveData.Text,'\0',sizeof(SaveData.Text));

	User.SetSaveData( SaveData );
}