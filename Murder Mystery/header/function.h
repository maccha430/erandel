/*�Q�[�����*/
namespace Game{
	void main();
	void title();
	void save(int ModeFlag);
	void debug();
	enum {TITLE,START,LOAD,SECRET,SYSTEM,END,SAVE,DEBUG};
	enum {S_MODE,L_MODE};
};

/*���C�����[�v�Ŏ��s���鏈��*/
int ProcessLoop();

/*�e�t���e�L�X�g�`��*/
void DrawStringShadow(int DrawX,int DrawY,std::string DrawText,unsigned int TextColor,unsigned int ShadowColor);

/*���j���[�p�����[�^�Z�b�g�@�\�^�C�g����ʁ\*/
void SetMenuParam_Title(MenuArg_rec &MenuArg,bool SecretFlag);

/*���j���[�p�����[�^�Z�b�g�@�\�Q�[����ʁ\*/
void SetMenuParam_GameRight(MenuArg_rec &MenuArg);