/*----------------
 | ���j���[�N���X |
  ----------------*/
class MenuClass{
	protected:
		//���j���[�p�����[�^
		int  DrawX,DrawY;		//�`��I�u�W�F�N�g������W
		int  Interval;			//�`��I�u�W�F�N�g���m�̊Ԋu
		int  Width[32];			//�`��I�u�W�F�N�g�̕�
		int  Height;			//�`��I�u�W�F�N�g�̍���
		int  ListMin;			//�`��I�u�W�F�N�g�̍ŏ��i���o�[
		int  ListMax;			//�`��I�u�W�F�N�g�̍ő�i���o�[
		int  AtherNo;			//�`��I�u�W�F�N�g��I�����Ă��ȂƂ��ɕԂ��i���o�[
		int  AlphaNo;			//�I�𒆃I�u�W�F�N�g�̓����x
		int  DrawFlag;			//�`�悷��I�u�W�F�N�g�̎��(0==�摜�`�� 1==�e�L�X�g�`��)
	    int  DirectionFlag;		//�`�����(0==�c 1==��)

		//�摜�I�u�W�F�N�g	
		int  DrawHandle[32];

		//�e�L�X�g�I�u�W�F�N�g
		char DrawText[32][32];
		unsigned int  TextColor;
		int  FontSize;
		int  FontFamily;

	 	//���j���[�ݒu�֐��֘A 	
		int  SelectNo;											//�I�𒆔ԍ�

 	public:
		MenuClass(MenuArg_rec &MenuArg);						//������
		void Create();											//���j���[�ݒu
		void Select();											//���j���[�I������
		virtual void Draw();									//���j���[�`�揈��
		int  GetSelectNo();										//�I�𒆔ԍ��擾
};

/*----------------------
 | �Z�[�u���j���[�N���X |
  ----------------------*/
class SaveMenuClass : public MenuClass{
	protected:
		Dvector_i				SaveDate;
		std::vector<char*>      SaveText;
		//short int SaveData[3][10][2];							//�f�[�^�󂯎��ϐ�(�V�[���J�E���g�A�Q�[���J�E���g)
	public:
		SaveMenuClass(MenuArg_rec &MenuArg);					//������
		void Draw(int Page);									//�Z�[�u�f�[�^��`��
		void UpdateData(Dvector_i Date,std::vector<char*> Text);
		//void UpdateData(short int ***ArgSaveData);				//�Z�[�u�f�[�^�X�V							//�Z�[�u�f�[�^�X�V
};

/*------------------------
 | �^�C�g�����j���[�N���X |
  ------------------------*/
class TitleMenuClass : public MenuClass{
	public:
		TitleMenuClass(MenuArg_rec &MenuArg);
		void Draw();
};

/*--------------------------
 | �R���t�B�O���j���[�N���X |
  --------------------------*/
class ConfigListClass : public MenuClass{
	protected:
		int SetNo;
	public:
		ConfigListClass(int SetNo,MenuArg_rec &MenuArg);
		void Draw();
};

/*----------------------------
 | �V�[�N���b�g���j���[�N���X |
  ----------------------------*/
class SecretMenuClass : public MenuClass{
	public:
		SecretMenuClass(MenuArg_rec &MenuArg);
		void Draw(int SetNo );
};