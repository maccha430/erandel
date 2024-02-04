#include"../header/define.h"

/*--------
 | ������ |
  --------*/
ScrollBarClass::ScrollBarClass(){
	//�����o�ϐ�������
	MoveScroll = 10;
	MaxScroll  = 720;
	MinScroll  = 0;
	BarWidth   = 30;
	MoveAdd    = 1;
	BarDrawX   = 1200;
}

/*--------------------------
 | �X�N���[���o�[�T�C�Y�v�Z |
  --------------------------*/
void ScrollBarClass::SizeCalc(int DrawHeight){
	//�X�N���[���o�[�̍ŏ��l
	const int BarHeightMin = 50;

	//�͂ݏo�Ă镪�̃e�L�X�g�c�T�C�Y�擾
	SubHeight = DrawHeight - windowY;

	//���������͂ݏo�Ă���̂�
	if( SubHeight < 0 ){
		BarHeight = MaxScroll;
		NewDrawY  = MinScroll;
		OldDrawY  = MinScroll;
		BarDrawY  = MinScroll;
	}else{
		//�X�N���[���o�[�T�C�Y�擾
		BarHeight = MaxScroll - SubHeight;

		//�X�N���[���o�[�̃T�C�Y���ŏ��l��������Ă��Ȃ���
		if( BarHeight < BarHeightMin ){
			//�X�N���[���̗ʂ𑝉�������
			MoveAdd   = (double)DrawHeight / ( MaxScroll );

			BarHeight = BarHeightMin;
			BarDrawY  = MaxScroll - BarHeight;
			NewDrawY  = MaxScroll - BarHeight;
			OldDrawY  = MaxScroll - BarHeight;
			SubHeight = MaxScroll - BarHeight;
		}else{
			BarDrawY  = MinScroll + SubHeight;
			NewDrawY  = MinScroll + SubHeight;
			OldDrawY  = MinScroll + SubHeight;
		}
	}
}

/*------------
 | �ړ��ʌv�Z |
  ------------*/
double ScrollBarClass::MoveCalc(){
	MouseClass* Mouse = MouseClass::GetInstance();

	int          TmpDrawY;
	const int    CLICK_FRAME = 1;
	const double ROUNDING    = 0.5;
	const int    BASE_SCROLL = MaxScroll - BarHeight;
	const int    END_FLAG    = -100000000;
	

	//�X�N���[���o�[���N���b�N���ꂽ
	if( Mouse->GetState(MOUSE::LEFT) >= CLICK_FRAME ){
		//���W�擾
		Mouse->GetPointY(TmpDrawY);
		
		//�X�N���[���o�[���N���b�N���ꂽ
		if( BarDrawY <= TmpDrawY && TmpDrawY < BarDrawY + BarHeight ){
			NewDrawY = TmpDrawY - OldDrawY; //NewDrawY�͍�����\���Ă�A��Ŗ��O�ύX
			if( MinScroll < BarDrawY + NewDrawY && BarDrawY + NewDrawY + BarHeight < MaxScroll ){
				BarDrawY   += NewDrawY;
				MoveScroll -= NewDrawY * MoveAdd + ROUNDING;
				OldDrawY   =  BarDrawY;
			}
		}else if( MinScroll < TmpDrawY && TmpDrawY < MaxScroll ){
			//�o�[�̈�̉��̂ق����N���b�N����
			if( windowY - BarHeight < TmpDrawY ){
				BarDrawY   = MinScroll + SubHeight;
				MoveScroll = 0;
				OldDrawY   = BarDrawY;
			}else{
				BarDrawY   = TmpDrawY;
				MoveScroll = (BASE_SCROLL - BarDrawY) * MoveAdd + ROUNDING;
				OldDrawY   = BarDrawY;
			}
		}
	}

	//�}�E�X�z�C�[������]����
	if( Mouse->GetWheel() > 0 ){
		if( MinScroll < BarDrawY - 20 ){
			BarDrawY   -= 20;
			MoveScroll += 20 * MoveAdd + ROUNDING;
			OldDrawY   =  BarDrawY;
		}
	}
	if( Mouse->GetWheel() < 0 ){
		if( BarDrawY + BarHeight + 20 < MaxScroll ){
			BarDrawY   += 20;
			MoveScroll -= 20 * MoveAdd + ROUNDING;
			OldDrawY   =  BarDrawY;
		}else{
			return END_FLAG;
		}
	}

	return MoveScroll;
}

/*--------------------
 | �X�N���[���o�[�`�� |
  --------------------*/
void ScrollBarClass::DrawScrollBar(){
	DrawBox(BarDrawX,BarDrawY,BarDrawX+BarWidth,BarDrawY+BarHeight,GetColor(155,155,155),TRUE);
}