/*--------------------------------
 | �O���t�B�b�N�N���X(���ۃN���X) |
  --------------------------------*/
class GraphClass{
	protected:
		virtual void Load()=0;		//�摜���[�h
		virtual void SetPoint()=0;	//�`����W�Z�b�g

	public:			
		virtual void Draw()=0;		//�摜�`��
		AnimeClass Anime;			//�A�j���C���X�^���X(�W��-�����\��)
};

 
/*----------------------------
 | �^�C�g���O���t�B�b�N�N���X |
  ----------------------------*/
class TitleGraphClass : public GraphClass{
	private:
		//�摜�n���h��
		int  TitleBackHandle;	//�w�i�摜
		
		//�`����W
		int  TitleBackPoint[2];	//�w�i�摜�`����W
		
		//���\�b�h
		void Load();			//�摜���[�h
		void SetPoint();		//�`����W�Z�b�g

	public:
		TitleGraphClass();		//������
		void Draw();			//�摜�`��
};

/*--------------------------
 | �Z�[�u�O���t�B�b�N�N���X |
  --------------------------*/
class SaveGraphClass : public GraphClass{
	private:
		//�摜�n���h��
		int BackgroundHandle;	//�w�i�摜

		//�`����W
		int BackgroundPoint[2];	//�w�i�摜

		//���\�b�h�@
		void Load();			//�摜���[�h
		void SetPoint();		//�摜���W�Z�b�g
	
	public:
		SaveGraphClass();		//������
		void Draw();			//�摜�`��

};

/*----------------------------
 | �e�L�X�g�O���t�B�b�N�N���X |
  ----------------------------*/
class TextGraphClass : public GraphClass{
	private:
		//�摜�n���h��
		vector<int> GameBackHandle;		//�w�i�摜
		int CharacterHandle;			//�L�����N�^�摜
		int TextBoxHandle;				//�e�L�X�g�{�b�N�X
		int SelectBoxHandle;			//�Z���N�g�{�b�N�X

		//�`����W
		int GameBackPoint[2];			//�w�i�摜
		int CharacterPoint[2];			//�L�����N�^�摜
		int TextBoxPoint[2];			//�e�L�X�g�{�b�N�X
		int SelectBoxPoint[2];			//�Z���N�g�{�b�N�X

		//���\�b�h
		void Load();					//�摜���[�h
		void SetPoint();				//�摜���W�Z�b�g


	public:
		TextGraphClass();				//������
		void Draw();					//�ꉞ�ˁA���Ƃŏ�������
		void DrawBack(UserClass &User);	//�w�i�`��
		void DrawChar(UserClass &User);	//�L�����N�^�`��
		void DrawWindow();				//�e�L�X�g�E�B���h�E�`��
};
		
/*------------------------------
 | �R���t�B�O�O���t�B�b�N�N���X |
  ------------------------------*/
class ConfigGraphClass : public GraphClass{
	private:
		//�萔
		enum{TEXTSPEED,AUTOSPEED,ALLVOL,BGMVOL,SEVOL};

		int SelectNo;									//�I��ԍ�
		
		//�摜�n���h��
		int BackgroundHandle;							//�w�i�摜

		//�`����W
		int BackgroundPoint[2];								//�w�i�摜

		struct ConfigData_rec ConfigData;				//�R���t�B�O�R�s�[���
		struct ConfigArg_rec  ConfigParam[6];			//�R���t�B�O�p�����[�^�ɓn���l�Z�b�g
		struct MenuArg_rec    MenuParam;				//�ۑ��Ƃ��^�C�g���ɖ߂�Ƃ��̃��j���[�p�����[�^

		//���\�b�h
		void Load();
		void SetPoint();

	public:
		ConfigGraphClass();								//������

		void SetMenuParam();							//���j���[�p�����[�^�Z�b�g

		void Draw();									//��ʕ`��
		int  GetSelectNo();								//�I�����ꂽ���j���[�̃i���o�[��Ԃ�
		void SetConfigData(ConfigData_rec &ConfigData);	//���ݐݒ肳��Ă��鍀�ڂ�Ⴄ
		ConfigData_rec GetConfigData();					//���ݐݒ肳�ꂽ���ڂ�Ԃ�
};

/*--------------------------------
 | �V�[�N���b�g�O���t�B�b�N�N���X |
  --------------------------------*/
class SecretGraphClass :public GraphClass{
	private:
		//�摜�n���h��
		int BackgroundHandle;	//�w�i�摜
		int PlayButtonHandle;			//�Đ��{�^��

		//�`����W
		int BackgroundPoint[2];	//�w�i�摜
		int PlayButtonPoint[2];	//�Đ��{�^��

		//���\�b�h�@
		void Load();			//�摜���[�h
		void SetPoint();		//�摜���W�Z�b�g
	
	public:
		SecretGraphClass();		//������
		void Draw();			//�摜�`��
		void DrawBack();		//�w�i�`��
		void DrawButton();		//�{�^���`��

};