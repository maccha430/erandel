#define GLOBAL_INSTANCE
#include"../header/define.h"
 
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
	//�ϐ��錾
	bool EndFlag = 0;
	
	//�E�B���h�E�ݒ�
	SetOutApplicationLogValidFlag(FALSE);			//���O���o�͂��Ȃ�
	ChangeWindowMode(TRUE);							//�E�B���h�E���[�h�ύX
	SetGraphMode(1280,720,32);						//�E�B���h�E�T�C�Y�w��
	SetWindowText("���̑��蕨 ver1.01");			//�E�B���h�E�^�C�g���ύX
	DxLib_Init();									//DX���C�u����������

	//�����ݒ�
	SetUseDXArchiveFlag( TRUE );					//�A�[�J�C�u�t�@�C���g�p
	SetDXArchiveExtension("kws");					//�g���q�ύX
	SetDrawScreen( DX_SCREEN_BACK );				//����ʐݒ�
	GetClientRect(GetMainWindowHandle(),&rect);		//�E�B���h�E�T�C�Y�擾
	//SetAlwaysRunFlag(TRUE);							//��A�N�e�B�u�ł����s
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);	//���ꂢ�ȃt�H���g
	SetBackgroundColor(255,255,255);

	//�t�H���g�T�C�Y�ݒ�
	MenuFontHandle = CreateFontToHandle( NULL , 36 , -1 , DX_FONTTYPE_ANTIALIASING );
	TextFontHandle = CreateFontToHandle( NULL , 28 , -1 , DX_FONTTYPE_ANTIALIASING );

	//�C���X�^���X��
	UserClass		 User;							//���[�U���N���X
	TitlePageClass*	 TitlePage  = new TitlePageClass;	//�^�C�g���y�[�W�N���X
	GamePageClass*   GamePage   = new GamePageClass;	//�Q�[���y�[�W�N���X
	SecretPageClass* SecretPage = new SecretPageClass;	//���܂��y�[�W�N���X

	//�R���t�B�O�������[�h
	User.LoadConfigData();

	//���C�����[�v
	while( ProcessLoop() == 0 && EndFlag != TRUE ){

		switch( User.GetPage() ){
			//�^�C�g���y�[�W
			case PAGE::TITLE:
				TitlePage->Main(User);
			break;

			//�Q�[���y�[�W
			case PAGE::GAME:
				GamePage->Main(User);
			break;

			//���܂����[�h
			case PAGE::SECRET:
				SecretPage->Main(User);
			break;

			//�Q�[���I��
			case PAGE::END:
				EndFlag = TRUE;
			break;
		}

	}

	//�R���t�B�O�f�[�^�Z�[�u
	User.SaveConfigData();

	delete TitlePage;
	delete GamePage;
	delete SecretPage;

	DxLib_End();

	return 0;
}