/*------------------
 | ���[�U���N���X |
  ------------------*/

/*���[�U�N���X*/
 class UserClass{
	private:	
		int    PageFlag;								//���݂̃y�[�W
		struct SaveData_rec   SaveData;					//�Z�[�u�f�[�^
		struct ConfigData_rec ConfigData;				//�R���t�B�O�f�[�^
		int    BGMCode;									//BGM�R�[�h
		int    BackCode;								//�w�i�摜�R�[�h
		int    CharCode;								//�L�����N�^�R�[�h
		bool   SecretFlag;								//�V�[�N���b�g�t���O
		

	public:
		UserClass();									//�����o�ϐ�������
		void SetPage(int Page);							//���݃y�[�W���Z�b�g
		int  GetPage();									//���݃y�[�W���擾
		void SetSaveData(SaveData_rec &SaveData);		//�Z�[�u�f�[�^�Z�b�g
		SaveData_rec GetSaveData();						//�Z�[�u�f�[�^�擾
		void LoadConfigData();							//�R���t�B�O��񃍁[�h
		void SaveConfigData();							//�R���t�B�O���Z�[�u
		void SetConfigData(ConfigData_rec &ConfigData);	//�R���t�B�O�f�[�^�Z�b�g
		ConfigData_rec GetConfigData();					//�R���t�B�O�f�[�^�擾
		
		//�e�R���t�B�O�f�[�^��Ԃ�
		int  GetTextSpeed();		//�e�L�X�g�̕\�����x
		int  GetAutoTextSpeed();	//�I�[�g���[�h�̕\�����x
		int  GetSkipFlag();			//���ǃX�L�b�v�������邩
		int  GetBGMVol();			//BGM�̉���
		int  GetSEVol();			//SE�̉���
 
		//���Ǌ֌W
		void ReadUpdate();			//���Ǌ֌W

		//�T�E���h�R�[�h
		void SetBGMCode(int Code);	
		int  GetBGMCode();			

		//�w�i�R�[�h
		void SetBackCode(int Code);	
		int  GetBackCode();		

		//�L�����N�^�R�[�h
		void SetCharacterCode(int Code);
		int  GetCharacterCode();

		//�V�[�N���b�g�t���O
		void SetSecretFlag();
		bool GetSecretFlag();
};