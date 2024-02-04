/*----------------------
 | �Z�[�u��ʐ���N���X |
  ----------------------*/
class SaveClass{
	protected:
		//�Z�[�u�f�[�^�ꗗ(�\���̂ɂł������H)
		int		   SaveHash[3][10];				//�n�b�V��
		short int  SaveCount[3][10][3];			//�f�[�^�󂯎��z��(�V�[���J�E���g�A�Q�[���J�E���g)
		int        SaveCode[3][10][3];			//�f�[�^�󂯎��z��(BGM,Back)								
		int		   SaveDate[3][10][3];			//���t�z��(�N,��,��)
		int		   SaveTextLength[3][10][1];	//��s�e�L�X�g������
		size_t	   TextSize;					//�e�L�X�g�T�C�Y��size_t�^�ɃL���X�g����
		char       SaveText[3][10][101];		//��s�e�L�X�g	
		int		   Hash;						//�n�b�V���l

		int  Select;							//�I��ԍ�
		int  Page;								//�y�[�W�ԍ�
		int  FadeFlag;							//�t�F�[�h�t���O
		int  ClickFlag;							//�Z�[�u�f�[�^�N���b�N�t���O

		bool LoadFlag;							//�Z�[�u�f�[�^�ǂݍ��݃t���O


		//�_�C�A���O�֌W
		bool SaveDialogFlag;
		bool MenuDialogFlag;
		bool DeleteDialogFlag;

		//���[�h�f�[�^
		struct SaveData_rec LoadData;

		//���j���[�p�����[�^
		struct MenuArg_rec SaveLeftParam;		//�����̃Z�[�u�f�[�^
		struct MenuArg_rec SaveRightParam;		//�E���̃Z�[�u�f�[�^
		struct MenuArg_rec SaveNaviParam;		//�i�r�Q�[�V����
		
		//���\�b�h
		void SetMenuParam();					//���j���[�p�����[�^�Z�b�g

	public:	
		SaveClass();													//������
		void Draw(int &Select);											//�f�[�^�`�揈��
		void Save(UserClass &User);										//�f�[�^�Z�[�u
		void Load(int &ModeFlag,UserClass &User);						//�f�[�^���[�h
		void Delete(UserClass &User);									//�f�[�^�폜
		int  YesNoBox(int ModeFlag);									//�m�F�{�b�N�X

		void Main(int &ChangeFlag);										//���C���֐�
		void ModeChange(int &ModeFlag,int &ChangeFlag,UserClass &User);	//���[�h�`�F���W
		void GetSaveData();												//�Z�[�u�f�[�^�擾
		void ChangePage();												//�Z�[�u�̃y�[�W�ύX
		
		SaveGraphClass Graph;											//�Z�[�u�O���t�B�b�N����
};