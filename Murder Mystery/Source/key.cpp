#include"../header/define.h"

/*------------
 | �L�[�N���X |
  ------------*/
/*�C���X�^���X�擾*/
KeyClass* KeyClass::GetInstance(){
	static KeyClass i;
	return &i;
}

/*�L�[��Ԏ擾*/
void KeyClass::SetHitKey(){
	char TmpKey[256];
	
	GetHitKeyStateAll( TmpKey );

	for( int i=0 ; i<256 ; i++ ){
		if( TmpKey[i] == 1 )	KeyState[i]++;
		else					KeyState[i]=0;
	}
}

/*�w�肳�ꂽ�L�[��Ԃ�Ԃ�*/
int KeyClass::GetState(int KeyCode){
	return KeyState[KeyCode];
}
