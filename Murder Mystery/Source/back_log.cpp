#include"../header/define.h"

/*-------------------
 |�Z���t�J�E���g�X�V |
  ------------------- */
BackLogClass::BackLogClass(){
	UpButtonHandle   = LoadGraph("./resource/graph/log_up.png");
	DownButtonHandle = LoadGraph("./resource/graph/log_down.png");
}

void BackLogClass::Update(int *ArgLineNo,int ArgSerifCount){
	//�����o�ϐ�������
	LineNo     = ArgLineNo;
	SerifCount = ArgSerifCount;
	LineHeight = 70;
	DrawLine   = 0;

	//�e�l�擾
	GetDrawLine();
	GetDrawSize();
	GetLogDrawPoint();
	ScrollBar.SizeCalc(DrawSize);
}

/*----------
 | �s���擾 |
  ----------*/
void BackLogClass::GetDrawLine(){
	for( int i=0 ; i<=SerifCount ; i++ ) DrawLine += LineNo[i];
}

/*--------------------------
 | �e�L�X�g�`��c�T�C�Y�擾 |
  --------------------------*/
void BackLogClass::GetDrawSize(){
	const int BottomSpace = 60;
	DrawSize = DrawLine * LineHeight ;
}

/*--------------
 | �`����W�擾 |
  --------------*/
void BackLogClass::GetLogDrawPoint(){
	//�萔��`
	const int BottomSpace = 80;
	const int TextIndent  = 200;
	const int NameIndent  = 50;

	//�S�̕`����W�擾
	LogDrawX = 0;
	LogDrawY = windowY - DrawSize + BottomSpace;
	
	//�e�`����W�擾
	DrawNameX = LogDrawX + NameIndent;
	DrawNameY = LogDrawY;
	DrawTextX = LogDrawX + TextIndent;
	DrawTextY = LogDrawY;
}

/*----------------
 | �o�b�N���O�`�� |
  ----------------*/
int BackLogClass::DrawLog(std::string Name[1024],std::string Text[1024]){
	const int END_FLAG = -100000000;
	const int FontSize = 28;

	int  TmpTextCount    = 0;
	int  TmpSerifCount   = 0;
	int  TmpCount	     = 0;
	int  ContCount		 = 0;
	int  EventCount      = 0;
	int  EventCodeHeight = 0;
	bool ButtonDrawFlag  = FALSE;
	std::string TmpStr;

	unsigned int Color;

	//�e�L�X�g�`��J�E���g������
	DrawTextCount = 0;

	//�X�N���[���o�[�ړ��ʎ擾
	//MoveScroll = ScrollBar.MoveCalc();
	
	//�z�񏉊���
	ButtonY1.clear();
	ButtonY2.clear();
	JumpTextCount.clear();
	JumpSerifCount.clear();

	//�{�^�����W��`
	ButtonX1  = 0;
	ButtonX2  = windowX-110;
	
	//�w�i�`��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,200);
	DrawBox(0,0,windowX,windowY,GetColor(0,0,0),TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);

	//�ړ��ʎ擾
	MoveScroll = MouseScroll();
	if( MoveScroll == END_FLAG ) return END_FLAG;

	//�J�E���^�X�V
	JumpLoopCount = SerifCount;

	//�o�b�N���O�`��
	for( int i=0 ; i<=SerifCount ; i++ ){
		//�e�L�X�g�`�F�b�N
		if( Name[DrawTextCount] == "����"  || Name[DrawTextCount] == "��l��" ) Name[DrawTextCount] = "\0";

		if( Name[DrawTextCount] == "�w�i" || Name[DrawTextCount] == "�L����" || Name[DrawTextCount] == "���y" || Name[DrawTextCount] == "�C�x���g" || Name[DrawTextCount] == "�G���h" ){
			DrawTextCount++;
			//TmpTextCount++;
			TmpSerifCount++;
			EventCount++;
			JumpLoopCount--;
			continue;
		}
		
		//�C�x���g�R�[�h�̍���
		EventCodeHeight = LineHeight * EventCount;

		//���W�ƃJ�E���g���擾
		ButtonY1.push_back( DrawNameY+(LineHeight*DrawTextCount)-LineHeight-EventCodeHeight+EventCodeSize );
		ButtonY2.push_back( DrawNameY+(LineHeight*DrawTextCount)+FontSize-LineHeight-EventCodeHeight+EventCodeSize );
		
		//�W�����v�{�^���`��
		//DrawBox(ButtonX1,ButtonY1[TmpCount],ButtonX2,ButtonY2[TmpCount],GetColor(255,255,255),TRUE);
	

		//�f�o�b�O�p
		TmpStr = Name[DrawTextCount];

		//���O�`��
		DrawString(DrawNameX,DrawNameY+(LineHeight*DrawTextCount)-LineHeight-EventCodeHeight+EventCodeSize,TmpStr.c_str(),GetColor(255,255,255));
		
		//�Z���t�`��
		for( int j=0 ; j<LineNo[i] ; j++ ){
			DrawString(DrawTextX,DrawTextY+(LineHeight*DrawTextCount)-LineHeight-EventCodeHeight+EventCodeSize,Text[DrawTextCount].c_str(),GetColor(255,255,255));
			DrawTextCount++;
			ContCount++;
		}
		
		JumpTextCount.push_back( DrawTextCount - ContCount );
		JumpSerifCount.push_back( i );
		TmpCount++;
		ContCount=0;
	}

	//�C�x���g�R�[�h�̑S�̃T�C�Y�擾
	EventCodeSize = EventCodeHeight;

	//�X�N���[���o�[�`��
	//ScrollBar.DrawScrollBar();

	if( EndFlag == TRUE ) return END_FLAG;
	else				  return 0;
}

/*�}�E�X�z�C�[���̈ړ���*/
int BackLogClass::MouseScroll(){
	auto *Mouse = MouseClass::GetInstance();
	int MoveScroll;

	const int END_FLAG = -100000000;
	static bool BackFlag = FALSE;
	static int  Count = 0;
	static int  Timer = 0;
	static bool TimerFlag = FALSE;
	int ClickX,ClickY;

	//�{�^�����W
	const int UpButtonX1 = windowX-100;
	const int UpButtonY1 = 0;
	const int UpButtonX2 = windowX;
	const int UpButtonY2 = 100;

	const int DownButtonX1 = windowX-100;
	const int DownButtonY1 = windowY-100;
	const int DownButtonX2 = windowX;
	const int DownButtonY2 = windowY;

	//��ʂ𒴂����T�C�Y�Ȃ�X�N���[������
	if( DrawSize - EventCodeSize > windowY ){
		//��ɉ�]
		if( Mouse->GetWheel() > 0 && DialogFlag == FALSE ){
			if(DrawNameY - LineHeight + EventCodeSize <= 0){
				DrawNameY += 40;
				DrawTextY += 40;
				BackFlag   = FALSE;
				Count      = 0;
			}
		}

		//���ɉ�](���G�ȕ���Ɖ�������if�A���A���C�ȂƂ��Ƀ��t�@�N�^�����O����)
		if( Mouse->GetWheel() < 0 && DialogFlag == FALSE ){
			if(  DrawNameY >= windowY - DrawSize + LineHeight+20 ){
				DrawNameY -= 40;
				DrawTextY -= 40;
			}else{
				if( BackFlag == TRUE && DialogFlag == FALSE ) return END_FLAG;
				else{
					Count++;
					if( Count > 3 )  BackFlag = TRUE;
				}
			}
		}	

		//�X�N���[���{�^���ݒu		
		//DrawBox(UpButtonX1,UpButtonY1,UpButtonX2,UpButtonY2,GetColor(255,255,255),TRUE);
		//DrawBox(DownButtonX1,DownButtonY1,DownButtonX2,DownButtonY2,GetColor(255,255,255),TRUE);

		//�X�N���[���{�^���摜
		DrawGraph(UpButtonX1,UpButtonY1,UpButtonHandle,TRUE);
		DrawGraph(DownButtonX1,DownButtonY1,DownButtonHandle,TRUE);

		//�}�E�X���W�擾
		Mouse->GetPoint(&ClickX,&ClickY);

		//�N���b�N���ꂽ
		if( Mouse->GetState(MOUSE::LEFT) > 0 ){
			//�y�[�W�A�b�v�{�^��
			if( UpButtonX1 < ClickX && ClickX < UpButtonX2 ){
				if( UpButtonY1 < ClickY && ClickY < UpButtonY2 ){
					if( DrawNameY + LineHeight+20 <= 0 ){
					DrawNameY += 40;
					DrawTextY += 40;
					}
				}
			}
			//�y�[�W�_�E���{�^��
			if( DownButtonX1 < ClickX && ClickX < DownButtonX2 ){
				if( DownButtonY1 < ClickY && ClickY < DownButtonY2 ){
					if( DrawNameY >= windowY - DrawSize + LineHeight+20 ){
					DrawNameY -= 40;
					DrawTextY -= 40;
					}
				}
			}
		}
	
	}else{
		if( Mouse->GetWheel() < 0 && DialogFlag == FALSE ) return END_FLAG;
	}

	//�E�N���b�N�Ŗ߂�
	if( Mouse->GetState( MOUSE::RIGHT ) > 0 && DialogFlag == FALSE ) TimerFlag = TRUE;
	if( TimerFlag == TRUE ){
		Timer++;
		if( Timer > 20 ){
			TimerFlag = FALSE;
			Timer     = 0;
			return END_FLAG;
		}
	}
}

/*�O�̃Z���t�ɃW�����v*/
int BackLogClass::Jump(short int &TextCount,short int &SerifCount,UserClass &User){
	auto *Mouse = MouseClass::GetInstance();
	static DialogClass Dialog;

	int ClickX,ClickY;

	static bool JumpFlag   = FALSE;
	static bool ClearFlag  = FALSE;
	static int  Timer1     = 0;
	static int  Timer2     = 0;
	static int  JumpNo	   = 0;

	//�萔
	const int END_FLAG = -100000000;
	const int WaitTime = 30;


	//���W�擾
	Mouse->GetPoint(&ClickX,&ClickY);

	//�_�C�A���O�t���O�擾
	DialogFlag = Dialog.GetDrawFlag();


	if( Mouse->GetState(MOUSE::LEFT) > 0 && DialogFlag == FALSE ){
		for( int i=0 ; i<=JumpLoopCount ; i++ ){
			if( ButtonX1 < ClickX && ClickX < ButtonX2 ){
				if( ButtonY1[i] < ClickY && ClickY < ButtonY2[i] ){
					SelectNo = i; //�I�����Ă�W�����v�{�^���̃i���o�[�Z�b�g
					Dialog.SetSelectNo( i , "�W�����v���Ă�낵���ł����H" );
				}
			}
		}
	}

	//�_�C�A���O���`�悳��Ă���Ȃ��
	if( DialogFlag == TRUE ){

		//�_�C�A���O�`��
		Dialog.Draw(User);

		//Yes
		if( Dialog.GetSelectFlag() == DIALOG::YES ){

			//�I��ԍ����󂯎��
			JumpNo = Dialog.GetSelectNo();

			//�W�����v����
			TextCount  = (short int)JumpTextCount[JumpNo];
			SerifCount = (short int)JumpSerifCount[JumpNo];
			JumpFlag   = TRUE;

			//�_�C�A���O�폜
			ClearFlag = TRUE;
			//Dialog.Clear();
		}

		//No
		if( Dialog.GetSelectFlag() == DIALOG::NO ){
			ClearFlag = TRUE;
			//Dialog.Clear();
		}
	}


	if( ClearFlag == TRUE ){
		Timer2++;
		if( Timer2 > WaitTime ){
			Timer2 = 0;
			Dialog.Clear();
			ClearFlag = FALSE;
		}
	}


	if( JumpFlag == TRUE ){
		Timer1++;
		if( Timer1 > WaitTime ){
			Timer1 = 0;
			JumpFlag = FALSE;
			return END_FLAG;
		}
	}
}