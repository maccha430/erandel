/*--------------------
 | �V�[�N���b�g�N���X |
  --------------------*/
class SecretClass{
	private:
		int Select;									//�I��ԍ��󂯎��
		int FadeFlag;								//�t�F�[�h�t���O
		int SetNo;									//�Đ����i���o�[
		Dvector_s ShowText;							//�`��e�L�X�g

		MenuArg_rec MusicListParam;					//�Ȉꗗ�p�����[�^

	public:
		SecretClass();								//������
		void SetMenuParam();						//���j���[�p�����[�^�Z�b�g
		void SetText();								//�e�L�X�g�Z�b�g
		void Main(UserClass& User,int &ChangeFlag);	//���C��
		SecretGraphClass Graph;						//�O���t�B�b�N
		SecretSoundClass Sound;						//�T�E���h

};
