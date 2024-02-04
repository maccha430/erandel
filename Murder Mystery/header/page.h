/*--------------------------
 | �y�[�W�N���X(���ۃN���X) |
  --------------------------*/
class PageClass{
	protected:
		int ModeFlag;											//���샂�[�h(Main�Load�Conf�̎O���)
		int ChangeFlag;											//���[�h���ς�����Ƃ��ɗ���

	public:
		void MovePage(int select,int FadeFlag,UserClass &User);	//�y�[�W�J�ڏ���
		void SetMode(int Mode,int FadeFlag);					//���[�h�Z�b�g
		int  GetMode();											//���݃��[�h�擾
		SaveClass		Save;									//�Z�[�u�N���X�C���X�^���X(�W��-�����\��)
		ConfigClass		Conf;									//�R���t�B�O�N���X�C���X�^���X
};


/*----------------------
 | �^�C�g���y�[�W�N���X |
  ----------------------*/
class TitlePageClass : public PageClass{
	public:
		TitlePageClass();					//������
		void Main(UserClass &User);			//�^�C�g���y�[�W�̓����
		TitleClass      Title;				//�^�C�g���N���X�C���X�^���X(�W��-�����\��)
		TitleSoundClass Sound;				//�^�C�g���T�E���h�N���X
};

/*--------------------
 | �Q�[���y�[�W�N���X |
  --------------------*/
class GamePageClass : public PageClass{
	public:
		GamePageClass();					//������
		void Main(UserClass &User);			//�Q�[���y�[�W�̓����
		TextClass		Text;				//�e�L�X�g�N���X(�W��-�����\��)	
		GameSoundClass  Sound;				//�Q�[���T�E���h�N���X			
		EndingClass     Ending;				//�G���f�B���O�N���X
};

/*--------------------------
 | �V�[�N���b�g�y�[�W�N���X |
  --------------------------*/
class SecretPageClass : public PageClass{
	public:
		void Main(UserClass &User);	//���C���֐�
		SecretClass Secret;
};
