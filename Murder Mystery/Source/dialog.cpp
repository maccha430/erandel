#include"../header/define.h" 

/*----------------------
 | �m�F�_�C�A���O�N���X |
  ----------------------*/
/*������*/
DialogClass::DialogClass(){
	//�����o�ϐ�������
	DrawFlag		= FALSE;
	SelectFlag		= -1;
	Timer			= 0;
	MessageFontSize = CreateFontToHandle( NULL , 36 , -1 , DX_FONTTYPE_ANTIALIASING );

	//�`����W������
	SetPoint();

	//���j���[�p�����[�^������
	SetMenuParam();
}

/*���W�w��*/
void DialogClass::SetPoint(){
	DrawX  = 320;
	DrawY  = 240;
	Width  = 640;
	Height = 240;
}

/*���j���[�p�����[�^������*/
void DialogClass::SetMenuParam(){
	MenuParam.DrawX			= DrawX;
	MenuParam.DrawY			= DrawY + Height / 2;
	MenuParam.Interval		= 0;
	MenuParam.Width			= Width / 2;
	MenuParam.Height			= Height / 2;
	MenuParam.ListMin			= 0;
	MenuParam.ListMax			= 2;
	MenuParam.AtherNo			= -1;
	MenuParam.AlphaNo			= 100;
	MenuParam.DrawFlag		= MENU::IMAGE;
	MenuParam.DirectionFlag	= MENU::ROW;

	MenuParam.DrawHandle[0]	= LoadGraph("./resource/graph/Yes.jpg");
	MenuParam.DrawHandle[1]	= LoadGraph("./resource/graph/No.jpg");
}

/*�I��ԍ��Z�b�g*/
void DialogClass::SetSelectNo(int SelectNo,std::string Message){
	this->SelectNo = SelectNo;
	this->Message  = Message;
	DrawFlag       = TRUE;
	FirstFlag	   = FALSE;
}

/*�_�C�A���O�`��*/
void DialogClass::Draw(UserClass &User){
	enum{DIALOG,ENTER,CANCEL};

	auto *Mouse = MouseClass::GetInstance();
	MenuClass Menu(MenuParam);

	//SE���ʃZ�b�g
	SE.SetVol(User);

	//�\������SE�炷
	if( FirstFlag == FALSE ){
		SE.PlayMusic( DIALOG );
		FirstFlag = TRUE;
	}

	//�_�C�A���O�`��
	DrawBox(DrawX,DrawY,DrawX+Width,DrawY+Height,GetColor(144,144,144),TRUE);
	DrawStringToHandle(DrawX,DrawY,Message.c_str(),GetColor(255,255,255),MessageFontSize);
	Menu.Create();

	//�I���t���O�X�V
	if( Mouse->GetState(MOUSE::LEFT) == 1 && Timer > 10 ){
		SelectFlag = Menu.GetSelectNo();
		//�I������SE�炷
		if( SelectFlag == 0 ) SE.PlayMusic( ENTER );
		if( SelectFlag == 1 ) SE.PlayMusic( CANCEL );
	}

	//�^�C�}�J�E���g����
	Timer++;
}

/*�`��t���O���擾*/
bool DialogClass::GetDrawFlag(){
	return DrawFlag;
}

/*�I���t���O�擾*/
int DialogClass::GetSelectFlag(){
	return SelectFlag;
}

/*�I��ԍ��擾*/
int DialogClass::GetSelectNo(){
	return SelectNo;
}

/*�_�C�A���O������*/
void DialogClass::Clear(){
	DrawFlag   = FALSE;
	SelectFlag = -1;
	Timer      = 0;
}