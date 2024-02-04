#include"../header/define.h" 

/*--------------------------
 | �R���t�B�O���j���[�N���X |
  --------------------------*/
/*������*/
ConfigMenuClass::ConfigMenuClass(ConfigArg_rec ConfigArg){
	//�����o�ϐ�������
	this->Title  = ConfigArg.Title;
	this->DrawX  = ConfigArg.DrawX;
	this->DrawY  = ConfigArg.DrawY;
	this->Width  = ConfigArg.Width;
	this->Height = ConfigArg.Height;
	this->ListNo = ConfigArg.ListNo;
	this->SetNo  = ConfigArg.SetNo;

	//�R���t�B�O���j���[�p�����[�^�Z�b�g
	SetMenuParam();
}

/*�R���t�B�O���j���[�p�����[�^�Z�b�g*/
void ConfigMenuClass::SetMenuParam(){
	int Interval;	//���ڂƍ��ڂ̊�
	int FontSize;	//�t�H���g�̑傫��

	FontSize = Height / 4;
	Interval = (Width - FontSize / 2 * ListNo ) / ( ListNo + 1 ) ;

	MenuArg.DrawX			= DrawX + Interval;
	MenuArg.DrawY			= DrawY + Height / 2;
	MenuArg.Interval		= Interval;
	MenuArg.Width			= FontSize;
	MenuArg.Height			= FontSize;
	MenuArg.ListMin			= 0;
	MenuArg.ListMax			= ListNo;
	MenuArg.AtherNo			= ListNo;
	MenuArg.AlphaNo			= 100;
	MenuArg.DrawFlag		= MENU::TEXT;
	MenuArg.DirectionFlag	= MENU::ROW;
	
	for( int i=0 ; i<ListNo ; i++ ){
		sprintf(MenuArg.DrawText[i],"%d",i+1);
	}

	//if( ListNo == 2 ){
	//	strcpy(MenuArg.DrawText[0],"Yes");
	//	strcpy(MenuArg.DrawText[1],"No");
	//}

	MenuArg.TextColor  = GetColor(255,255,255);
	MenuArg.FontFamily = MENU::GOSIC;

}

/*�I��ԍ����擾*/
int ConfigMenuClass::GetSelectNo(){
	return SelectNo;
}

/*���j���[�`��*/
void ConfigMenuClass::Draw(){
	//�ϐ��錾
	ConfigListClass Menu(SetNo,MenuArg);

	int TitleWidth;	//�^�C�g���̉���
	int Interval;	//�^�C�g�������̍��E�̕�

	
	//�t�H���g�T�C�Y�w��
	const int FontSize = Height / 4;


	//�t�H���g�T�C�Y�ς���
	//SetFontSize(FontSize);


	//�^�C�g�������̍��E�̕����擾
	TitleWidth = Title.length() * FontSize / 2;
	Interval   = ( Width - TitleWidth ) / 2;

	//�R���t�B�O���j���[�`��
	DrawStringToHandle(DrawX+Interval,DrawY,Title.c_str(),GetColor(255,255,255),MenuFontHandle);
	Menu.Create();

	//�I��ԍ����擾
	SelectNo = Menu.GetSelectNo();



}
