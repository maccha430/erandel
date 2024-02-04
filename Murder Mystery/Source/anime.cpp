#include"../header/define.h" 

/*----------------------
 | �A�j���[�V�����N���X |
  ----------------------*/

/*�\ ��ʑS�̂̍�����̃t�F�[�h�C�� �\
	�����@�F�t�F�[�h�C���̑��x
�@�@�߂�l�F�t�F�[�h�C���I���łP��Ԃ��B
*/

/*�ϐ�������*/
AnimeClass::AnimeClass(){
	FadeFlag = 0;
	Count    = 0;
}

/*�t�F�[�h�C������*/
int AnimeClass::FadeIn(int Speed){
	//��ʂ����񂾂񖾂邭����
	if( FadeFlag == 0 ){
		SetDrawBright(Count,Count,Count);
		Count+=Speed;
	}

	//��ʂ��ő�܂Ŗ��邭�Ȃ������~
	if( Count >= 255 ) FadeFlag = 1;

	return FadeFlag;
}

/*�S�Ă̕ϐ���������*/
void AnimeClass::Reset(){
	FadeFlag = 0;
	Count    = 0;
}