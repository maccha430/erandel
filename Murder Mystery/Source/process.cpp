#include"../header/define.h"

/*���C�����[�v�ŕK�����s���鏈��*/
int ProcessLoop(){
	//�C���X�^���X��
	KeyClass   *Key   = KeyClass::GetInstance();
	MouseClass *Mouse = MouseClass::GetInstance();

	//�Œ菈��
	ScreenFlip();
	if( ClearDrawScreen() != 0 ) return -1;
	if( ProcessMessage()  != 0 ) return -1;
	Key->SetHitKey();
	Mouse->SetHitMouse();

	return 0;
}
