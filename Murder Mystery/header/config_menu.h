/*--------------------------
 | �R���t�B�O���j���[�N���X |
  --------------------------*/
class ConfigMenuClass{
	private:
		std::string Title;				//���j���[�^�C�g��
		int DrawX,DrawY;				//���j���[�`����W
		int Width,Height;				//���j���[�c���T�C�Y
		int ListNo;						//���j���[���ڐ�
		int SetNo;						//�ݒ肳��Ă���l

		int SelectNo;					//�I�����ꂽ�ԍ�

		struct MenuArg_rec MenuArg;		//���j���[�p�����[�^
		void SetMenuParam();			//���j���[�p�����[�^�Z�b�g

	public:
		ConfigMenuClass(ConfigArg_rec ConfigArg);	

		void Draw();					//�`��
		int  GetSelectNo();				//�N���b�N���ꂽ�l��Ԃ�
};