/*----------------------------
 | �T�E���h�N���X(���ۃN���X) |
  ----------------------------*/
class SoundClass{
	protected:
		enum{PLAY,STOP};							//�Đ���Ԃ�\���萔
		int PlayFlag;								//�Đ����t���O
		int BGMVol;									//BGM�̉��ʂ��i�[
		int SEVol;									//SE�̉��ʂ��i�[
		int NowPlayCode;							//���ݍĐ����̃R�[�h

		void VarInit();								//�����o�ϐ�������
		virtual void Load()=0;						//���y���[�h

	public:
		virtual void PlayMusic(UserClass &User) = 0;//���y�Đ�
		virtual void StopBGM()=0;					//���y��~
		virtual	void SetVol(UserClass &User);		//���ʃZ�b�g
		//virtual void VolChange();					//���ʃ`�F���W
};


/*------------------------
 | �^�C�g���T�E���h�N���X |
  ------------------------*/
class TitleSoundClass : public SoundClass{
	private:
		int TitleBGM;						//�^�C�g��BGM���i�[
		int TitleBGM2;						//�^�C�g��BGM�Q

		void Load();

	public:
		TitleSoundClass();					//������
		void PlayMusic(UserClass &User);	//���y�Đ�
		void StopBGM();						//���y��~
};

/*----------------------
 | �Q�[���T�E���h�N���X |
  ----------------------*/
class GameSoundClass : public SoundClass{
	enum{HARA,END};

	private:
		std::vector<int> GameBGM;			//�Q�[��BGM���i�[
		void Load();						//���y�ǂݍ���

	public:
		GameSoundClass();					//������
		void PlayMusic(UserClass &User);	//���y�Đ�
		void StopBGM();						//���y��~
};

/*--------------------------
 | �V�X�e���G�t�F�N�g�N���X |
  --------------------------*/
class SESoundClass : public SoundClass{
	enum{DIALOG,ENTER,CANCEL};

	private:
		int DialogSE;
		int EnterSE;
		int CancelSE;

		void Load();

	public:
		SESoundClass();
		void PlayMusic( int Code );
		void PlayMusic( UserClass &User );
		void StopBGM();
};

/*----------------------------
 | �V�[�N���b�g�T�E���h�N���X |
  ----------------------------*/
class SecretSoundClass : public SoundClass{
	enum{TITLE,KAISOU,DEAI,WAKARE,ENDING};
	private:
		int TitleBGM;
		int kaisouBGM;
		int kaisou2BGM;
		int DeaiBGM;
		int WakareBGM;
		int EndingBGM;
		
		void Load();

	public:
		SecretSoundClass();					//������
		void PlayMusic(UserClass &User);	//���y�Đ�(�_�~�[)
		void PlayMusic(int Code);			//���y�Đ�
		void StopBGM();						//���y��~
};


 