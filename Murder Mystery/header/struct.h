/*���j���[�N���X�ɓn���p�����[�^*/
struct MenuArg_rec{
	//�p�����[�^
	int  DrawX,DrawY;		//�`��I�u�W�F�N�g������W
	int  Interval;			//�`��I�u�W�F�N�g���m�̊Ԋu
	int  Width,Height;		//�`��I�u�W�F�N�g�̕��ƍ���(Width,height�̓e�L�X�g�̏ꍇ�t�H���g�T�C�Y�ɂȂ�)
	int  ListMin;			//�`��I�u�W�F�N�g�̍ŏ��i���o�[
	int  ListMax;			//�`��I�u�W�F�N�g�̍ő�i���o�[
	int  AtherNo;			//�`��I�u�W�F�N�g��I�����Ă��ȂƂ��ɕԂ��i���o�[
	int  AlphaNo;			//�I�𒆃I�u�W�F�N�g�̓����x
	int  DrawFlag;			//�`�悷��I�u�W�F�N�g�̎��(0==�摜�`�� 1==�e�L�X�g�`��)
	int  DirectionFlag;		//�`�����(0==�c 1==��)

	//�`��t���O���O�Ȃ�Ή摜
	int  DrawHandle[32];	//�`��I�u�W�F�N�g

	//�`��t���O���P�Ȃ�΃e�L�X�g
	char DrawText[32][32];	//�`��e�L�X�g
	unsigned int  TextColor;			//�`��e�L�X�g�J���[
	int  FontFamily;		//�t�H���g�t�@�~���[

};

/*�R���t�B�O���j���[�ɓn���p�����[�^*/
struct ConfigArg_rec{
	//�p�����[�^
	std::string Title;	//�^�C�g��
	int			DrawX;	//�`��X���W
	int			DrawY;	//�`��Y���W
	int			Width;	//���j���[�̉���
	int			Height;	//���j���[�̍���
	int			ListNo;	//���ڂ̐�
	int			SetNo;	//�ݒ肳��Ă���l
};

/*�Z�[�u�f�[�^�\����*/
struct SaveData_rec{
	short int   SceneCount;	//�V�[���J�E���g
	short int   TextCount;	//�e�L�X�g�J�E���g
	short int   SerifCount;	//�Z���t�J�E���g
	int         BGMCode;	//BGM�R�[�h
	int         BackCode;	//�w�i�R�[�h
	int			CharCode;	//�L�����N�^�[�R�[�h
	int			Year;		//�N
	int			Mon;		//��
	int			Day;		//��
	int         TextLength;	//�e�L�X�g�̕�����(�o�C�g��)
	char		Text[61];	//�e�L�X�g1�s(�����100%�ޯ̧���ް�۰�̌��ɂȂ邩��Astd::string�ɂ��Ă������ƁI)
};

/*�R���t�B�O�f�[�^�\����*/
struct ConfigData_rec{
	//�e�L�X�g�֘A
	int  TextSpeed;
	int  AutoSpeed;
	int  SkipFlag;

	//���ʊ֘A
	int  AllBolume;
	int  BGMBolume;
	int  SEBolume;
};
