#include"../header/define.h" 

/*------------------
 | �R���t�B�O�N���X |
  ------------------*/
/*������*/
ConfigClass::ConfigClass(){
	Select = -1;
}

/*���C���֐�*/
void ConfigClass::Main(UserClass& User,int &ChangeFlag){

	//�萔�錾
	const int Speed = 60;	//�t�F�[�h�C�����x

	//���[�h�`�F���W�����Ƃ��A������
	if( ChangeFlag == TRUE ){
		ConfigData = User.GetConfigData(); //���[�U�[�N���X�̃R���t�B�O�����R�s�[
		
		//�e�X�g�p
		BackConfigData = ConfigData;

		ChangeFlag = FALSE;					//���[�h�`�F���W�t���O��܂�
		FadeFlag   = FALSE;					//�t�F�[�h�����t���O��܂�
		Graph.Anime.Reset();				//�A�j���[�V�������Z�b�g
	}

	//�t�F�[�h�C��
	FadeFlag = Graph.Anime.FadeIn(Speed);

	//�O���t�B�b�N�N���X�ɃR���t�B�O����n��
	Graph.SetConfigData(ConfigData);
	
	//��ʕ`��
	Graph.Draw();

	//�O���t�B�b�N�N���X����ύX���ꂽ�R���t�B�O�����󂯎��
	ConfigData = Graph.GetConfigData();

	//����Ƃ��̃��j���[�I��ԍ��󂯎��
	Select = Graph.GetSelectNo();

	//�R���t�B�O�f�[�^�����[�U�[�N���X�ɔ��f������B
	User.SetConfigData(ConfigData);
}


/*���[�h�`�F���W�N���X*/
void ConfigClass::ModeChange(int &ModeFlag,int &ChangeFlag,UserClass &User){
	//�C���X�^���X��
	MouseClass *Mouse = MouseClass::GetInstance();
	static DialogClass Dialog;
	
	//�萔��`
	enum{INIT,SAVE,BACK,TITLEBACK};

	//���N���b�N����āA�t�F�[�h���I����Ă�
	if( Mouse->GetState(MOUSE::LEFT) == TRUE && FadeFlag == TRUE && Dialog.GetDrawFlag() == FALSE){
		switch( Select ){
			//�Z�[�u
			case SAVE:
				Dialog.SetSelectNo( Select , "�ύX��ۑ����Ă����ł����H" );
			break;

			//�o�b�N
			case BACK:
				Dialog.SetSelectNo( Select , "�ύX��ۑ����Ȃ��Ŗ߂�܂����H" );
			break;

			//�^�C�g���o�b�N
			case TITLEBACK:
				Dialog.SetSelectNo( Select , "�^�C�g���ɖ߂�܂����H" );
			break;

			//������
			case INIT:
				Dialog.SetSelectNo( Select ,"�ݒ�����������܂����H" );
			break;
		}
	}

	//�_�C�A���O���\������Ă���Ȃ�
	if( Dialog.GetDrawFlag() == TRUE ){

		//�_�C�A���O�`��
		Dialog.Draw(User);

		//�u�͂��v���N���b�N
		if( Dialog.GetSelectFlag() == DIALOG::YES ){
			switch( Dialog.GetSelectNo() ){
				//�ݒ�ۑ�
				case SAVE:
					ModeFlag = MODE::MAIN;
					ChangeFlag = TRUE;
				break;

				//�߂�
				case BACK:
					User.SetConfigData(BackConfigData);
					ModeFlag = MODE::MAIN;
					ChangeFlag = TRUE;	
				break;

				//�^�C�g���ɖ߂�
				case TITLEBACK:
					User.SetConfigData(BackConfigData);
					ModeFlag = MODE::OTHER;
					User.SetPage( PAGE::TITLE );
				break;

				//�ݒ菉����
				case INIT:
					ConfigData.TextSpeed = 2;
					ConfigData.AutoSpeed = 2;
					ConfigData.SkipFlag  = 0;
					ConfigData.AllBolume = 3;
					ConfigData.BGMBolume = 2;
					ConfigData.SEBolume  = 2;
				break;
			}
			//�_�C�A���O�폜
			Dialog.Clear();
		}

		//�u�������v���N���b�N
		if( Dialog.GetSelectFlag() == DIALOG::NO ){
			//�_�C�A���O�폜
			Dialog.Clear();
		}
	}
}