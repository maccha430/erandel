#include"../header/define.h"

/*--------------
 | �}�E�X�N���X |
  --------------*/
MouseClass* MouseClass::GetInstance(){
	static MouseClass i;
	return &i;
}

/*�}�E�X�̏�Ԃ��擾*/
void MouseClass::SetHitMouse(){
	//�N���b�N���ꂽ�L�[���擾
	if( GetMouseInput() & MOUSE_INPUT_LEFT )	   MouseState[LeftClick]++;
	else										   MouseState[LeftClick]=0;
	if( GetMouseInput() & MOUSE_INPUT_RIGHT )	   MouseState[RightClick]++;
	else										   MouseState[RightClick]=0;

	//���݂̃}�E�X���W���擾
	GetMousePoint(&MouseX,&MouseY);

	//�}�E�X�z�C�[���̉�]�ʂ��擾
	MouseWheel = GetMouseWheelRotVol();
}

/*�}�E�X�̍��W��Ԃ�*/
void MouseClass::GetPoint(int *x,int *y){
	//���݂̃}�E�X���W���|�C���^�ɑ��
	*x = MouseX;
	*y = MouseY;
}

/*�}�E�X�̊e���W��Ԃ�*/
void MouseClass::GetPointX(int &x){	x = MouseX; }
void MouseClass::GetPointY(int &y){ y = MouseY; }

/*�}�E�X�z�C�[���̉�]�ʂ��擾*/
int MouseClass::GetWheel(){
	return MouseWheel;
}


/*�}�E�X�̏�Ԃ�Ԃ�*/
int MouseClass::GetState(int MouseCode){
	//�}�E�X�̏�Ԃ�Ԃ�
	return MouseState[MouseCode];
}