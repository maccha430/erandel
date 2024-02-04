#include"../header/define.h" 

/*----------------------------
 | �^�C�g���O���t�B�b�N�N���X |
  ----------------------------*/
/*������*/
TitleGraphClass::TitleGraphClass(){
	Load();
	SetPoint();
}

/*�摜���[�h*/
void TitleGraphClass::Load(){
	TitleBackHandle = LoadGraph("./resource/graph/Title3.png");
}

/*�`����W�Z�b�g*/
void TitleGraphClass::SetPoint(){
	TitleBackPoint[GRAPH::X] = 0;
	TitleBackPoint[GRAPH::Y] = 0;
}

/*�摜�`��*/
void TitleGraphClass::Draw(){
	DrawGraph(TitleBackPoint[GRAPH::X],TitleBackPoint[GRAPH::Y],TitleBackHandle,TRUE);
}


/*--------------------------
 | �Z�[�u�O���t�B�b�N�N���X |
  --------------------------*/
/*������*/
SaveGraphClass::SaveGraphClass(){
	Load();			//�摜�ǂݍ���
	SetPoint();		//�`����W�Z�b�g
}
	
/*�摜���[�h*/
void SaveGraphClass::Load(){
	//�w�i�摜
	BackgroundHandle = LoadGraph("./resource/graph/save_back.png");
}

/*�`����W�Z�b�g*/
void SaveGraphClass::SetPoint(){
	//�w�i�摜
	BackgroundPoint[GRAPH::X] = 0;
	BackgroundPoint[GRAPH::Y] = 0;
}

/*�摜�`��*/
void SaveGraphClass::Draw(){
	//�w�i�`��
	DrawGraph(BackgroundPoint[GRAPH::X],BackgroundPoint[GRAPH::Y],BackgroundHandle,TRUE);
}


/*--------------------------
 | �e�L�X�g���t�B�b�N�N���X |
  --------------------------*/
/*������*/
TextGraphClass::TextGraphClass(){
	Load();			//�摜�ǂݍ���
	SetPoint();		//�`����W�Z�b�g
}

/*�摜���[�h*/
void TextGraphClass::Load(){
	//�w�i���[�h
	GameBackHandle.push_back( LoadGraph("./resource/graph/BackGround1.png") );
	GameBackHandle.push_back( LoadGraph("./resource/graph/BackGround2.png") );
	
	//�L�����N�^�`��
	CharacterHandle = LoadGraph("./resource/graph/character1.png");

	//�e�L�X�g�{�b�N�X
	TextBoxHandle	 = LoadGraph("./resource/graph/TextBox.png");
	
}

/*�`����W�Z�b�g*/
void TextGraphClass::SetPoint(){
	//�w�i
	GameBackPoint[GRAPH::X] = 0;
	GameBackPoint[GRAPH::Y] = 0;

	//�L�����N�^�`����W
	CharacterPoint[GRAPH::X] = windowX / 3;
	CharacterPoint[GRAPH::Y] = 0;

	//�e�L�X�g�{�b�N�X
	TextBoxPoint[GRAPH::X]  = 0;
	TextBoxPoint[GRAPH::Y]  = windowY - windowY / 3;


}

/*�w�i�`��*/
void TextGraphClass::DrawBack(UserClass &User){
	//�w�i�`��
	switch( User.GetBackCode() ){
		case GAME_BACK::KAWARA:
			DrawGraph(GameBackPoint[GRAPH::X],GameBackPoint[GRAPH::Y],GameBackHandle[GAME_BACK::KAWARA],TRUE);
		break;	
	
		case GAME_BACK::YOZORA:
			DrawGraph(GameBackPoint[GRAPH::X],GameBackPoint[GRAPH::Y],GameBackHandle[GAME_BACK::YOZORA],TRUE);
		break;

		case GAME_BACK::BLACK:
			DrawBox(0,0,windowX,windowY,GetColor(0,0,0),TRUE);
		break;
	}
}

/*�L�����N�^�`��*/
void TextGraphClass::DrawChar(UserClass &User){
	//�L�����N�^�`��
	switch( User.GetCharacterCode() ){
		case GAME_CHAR::AI:
			DrawGraph(CharacterPoint[GRAPH::X],CharacterPoint[GRAPH::Y],CharacterHandle,TRUE);
		break;

		case GAME_CHAR::NOT:
		break;
	}
}

/*�e�L�X�g�E�B���h�E�`��*/
void TextGraphClass::DrawWindow(){
	//�e�L�X�g�{�b�N�X�`��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,255);
	DrawGraph(TextBoxPoint[GRAPH::X],TextBoxPoint[GRAPH::Y],TextBoxHandle,TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
}

/*�f�o�b�O�p*/
void TextGraphClass::Draw(){}

/*------------------------------
 | �R���t�B�O�O���t�B�b�N�N���X |
  ------------------------------*/
/*������*/
ConfigGraphClass::ConfigGraphClass(){
	Load();
	SetPoint();

	/*�߂�Ƃ�����̃��j���[�p�����[�^*/
	MenuParam.DrawX			= 640;
	MenuParam.DrawY			= 576;
	MenuParam.Interval		= 0;
	MenuParam.Width			= 160;
	MenuParam.Height		= 144;
	MenuParam.ListMin		= 0;
	MenuParam.ListMax		= 4;
	MenuParam.AtherNo		= -1;
	MenuParam.AlphaNo		= 200;
	MenuParam.DrawFlag		= MENU::IMAGE;
	MenuParam.DirectionFlag	= MENU::ROW;

	MenuParam.DrawHandle[0]	= LoadGraph("./resource/graph/conf_init.jpg");
	MenuParam.DrawHandle[1]	= LoadGraph("./resource/graph/conf_save.jpg");
	MenuParam.DrawHandle[2] = LoadGraph("./resource/graph/conf_back.jpg");
	MenuParam.DrawHandle[3] = LoadGraph("./resource/graph/conf_title.jpg");
}

/*�摜���[�h*/
void ConfigGraphClass::Load(){
	//�w�i�摜
	BackgroundHandle = LoadGraph("./resource/graph/conf_back.png");
}

/*�`����W�Z�b�g*/
void ConfigGraphClass::SetPoint(){
	//�w�i�摜
	BackgroundPoint[GRAPH::X] = 0;
	BackgroundPoint[GRAPH::Y] = 0;
}

/*�I�����ꂽ���j���[�̃i���o�[��Ԃ�*/
int ConfigGraphClass::GetSelectNo(){ return SelectNo; }

/*���ݐݒ肳��Ă��鍀�ڂ�Ⴄ*/
void ConfigGraphClass::SetConfigData(ConfigData_rec &ConfigData){
	this->ConfigData = ConfigData; 
}

/*���ݐݒ肳�ꂽ���ڂ�Ԃ�*/
ConfigData_rec ConfigGraphClass::GetConfigData(){
	return ConfigData; 
}

/*�p�����[�^���Z�b�g*/
void ConfigGraphClass::SetMenuParam(){

	/*�R���t�B�O���j���[�̃p�����[�^�Z�b�g*/

	ConfigParam[TEXTSPEED].Title  = "�e�L�X�g�\�����x";
	ConfigParam[TEXTSPEED].DrawX  = 10;
	ConfigParam[TEXTSPEED].DrawY  = 144;
	ConfigParam[TEXTSPEED].Width  = 640;
	ConfigParam[TEXTSPEED].Height = 144;
	ConfigParam[TEXTSPEED].ListNo = 5;
	ConfigParam[TEXTSPEED].SetNo  = ConfigData.TextSpeed;

	ConfigParam[AUTOSPEED].Title  = "�I�[�g���[�h�\�����x";
	ConfigParam[AUTOSPEED].DrawX  = 10;
	ConfigParam[AUTOSPEED].DrawY  = 144*2;
	ConfigParam[AUTOSPEED].Width  = 640;
	ConfigParam[AUTOSPEED].Height = 144;
	ConfigParam[AUTOSPEED].ListNo = 5;
	ConfigParam[AUTOSPEED].SetNo  = ConfigData.AutoSpeed;

	/*ConfigParam[SKIP].Title  = "���ǃX�L�b�v���邩";
	ConfigParam[SKIP].DrawX  = 10;
	ConfigParam[SKIP].DrawY  = 144*3;
	ConfigParam[SKIP].Width  = 640;
	ConfigParam[SKIP].Height = 144;
	ConfigParam[SKIP].ListNo = 2;
	ConfigParam[SKIP].SetNo  = ConfigData.SkipFlag;
	*/

	ConfigParam[ALLVOL].Title  = "�S�̉���";
	ConfigParam[ALLVOL].DrawX  = 650;
	ConfigParam[ALLVOL].DrawY  = 144;
	ConfigParam[ALLVOL].Width  = 640;
	ConfigParam[ALLVOL].Height = 144;
	ConfigParam[ALLVOL].ListNo = 5;
	ConfigParam[ALLVOL].SetNo  = ConfigData.AllBolume;

	ConfigParam[BGMVOL].Title  = "BGM����";
	ConfigParam[BGMVOL].DrawX  = 650;
	ConfigParam[BGMVOL].DrawY  = 144*2;
	ConfigParam[BGMVOL].Width  = 640;
	ConfigParam[BGMVOL].Height = 144;
	ConfigParam[BGMVOL].ListNo = 5;
	ConfigParam[BGMVOL].SetNo  = ConfigData.BGMBolume;

	
	ConfigParam[SEVOL].Title  = "SE����";
	ConfigParam[SEVOL].DrawX  = 650;
	ConfigParam[SEVOL].DrawY  = 144*3;
	ConfigParam[SEVOL].Width  = 640;
	ConfigParam[SEVOL].Height = 144;
	ConfigParam[SEVOL].ListNo = 5;
	ConfigParam[SEVOL].SetNo  = ConfigData.SEBolume;
}

/*��ʕ`��*/
void ConfigGraphClass::Draw(){
	//�}�E�X�C���X�^���X�󂯎��
	auto *Mouse = MouseClass::GetInstance();
	
	//�ϐ��錾
	ConfigMenuClass *Menu[5];

	//�p�����[�^�Z�b�g
	SetMenuParam();

	//�C���X�^���X�ϐ���`
	for( int i=0 ; i<5 ; i++ ){ Menu[i] = new ConfigMenuClass(ConfigParam[i]); }
	MenuClass GlobalMenu(MenuParam);

	//�w�i�`��
	DrawGraph(BackgroundPoint[GRAPH::X],BackgroundPoint[GRAPH::Y],BackgroundHandle,TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,100);
	DrawBox(50,100,windowX-50,windowY-144,GetColor(0,0,0),TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);

	//��ʃ^�C�g��
	DrawString(10,10,"�\ �R���t�B�O��� �\",GetColor(255,255,255));

	//�R���t�B�O�E�O���[�o�����j���[�`��
	for( int i=0 ; i<5 ; i++ ) Menu[i]->Draw();
	GlobalMenu.Create();

	//�I��ԍ��擾
	if( Mouse->GetState(MOUSE::LEFT) > 0 ){
		//�R���t�B�O���j���[�̔ԍ��擾
		for( int i=0 ; i<5 ; i++ ){
			if( ConfigParam[i].ListNo != Menu[i]->GetSelectNo() ){
				if( i == 0 ) ConfigData.TextSpeed = Menu[i]->GetSelectNo();
				if( i == 1 ) ConfigData.AutoSpeed = Menu[i]->GetSelectNo();
				//if( i == 2 ) ConfigData.SkipFlag  = Menu[i]->GetSelectNo();
				if( i == 2 ) ConfigData.AllBolume = Menu[i]->GetSelectNo();
				if( i == 3 ) ConfigData.BGMBolume = Menu[i]->GetSelectNo();
				if( i == 4 ) ConfigData.SEBolume  = Menu[i]->GetSelectNo();
			}
		}

		//�O���[�o�����j���[�̔ԍ��擾
		SelectNo = GlobalMenu.GetSelectNo();
	}

	
	
	//�I�u�W�F�N�g�J��
	for( int i=0 ; i<5 ; i++ ) delete Menu[i];
}

/*--------------------------------
 | �V�[�N���b�g�O���t�B�b�N�N���X |
  --------------------------------*/
/*������*/
SecretGraphClass::SecretGraphClass(){
	Load();			//�摜�ǂݍ���
	SetPoint();		//�`����W�Z�b�g
}
	
/*�摜���[�h*/
void SecretGraphClass::Load(){
	BackgroundHandle = LoadGraph("./resource/graph/secret_back.png");
	PlayButtonHandle = LoadGraph("./resource/graph/play_button.jpg");
}

/*�`����W�Z�b�g*/
void SecretGraphClass::SetPoint(){
	//�w�i�摜
	BackgroundPoint[GRAPH::X] = 0;
	BackgroundPoint[GRAPH::Y] = 0;
}

/*�摜�`��*/
void SecretGraphClass::Draw(){
	DrawBack();
}

/*�w�i�`��*/
void SecretGraphClass::DrawBack(){
	DrawGraph(BackgroundPoint[GRAPH::X],BackgroundPoint[GRAPH::Y],BackgroundHandle,TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,120);
	DrawBox(50,50,windowX-50,windowY-50,GetColor(0,0,0),TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	DrawLine(500,100,500,windowY-100,GetColor(0,0,0));
}

