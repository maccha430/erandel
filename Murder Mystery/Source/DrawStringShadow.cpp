#include"../header/define.h" 


void DrawStringShadow(int DrawX,int DrawY,std::string DrawText,unsigned int TextColor,unsigned int ShadowColor){
	//�`����W�ϐ��錾
	int TextX,TextY;

	//�e�Ɋւ���萔���`
	const int ShadowX = 0;
	const int ShadowY = 3;


	/*�w�i��`��*/

	// �e�̕\���J�n�ʒu
	TextX = DrawX+ ShadowX;
	TextY = DrawY + ShadowY;

	// �e�̃x�[�X�ƂȂ镶�����`��
	DrawString( TextX , TextY , DrawText.c_str(), ShadowColor);
	
	// �e�L�X�g�\���J�n�ʒu
	TextX = DrawX;
	TextY = DrawY;

	// ������̕`��
	DrawString(TextX, TextY,DrawText.c_str(), TextColor);

}