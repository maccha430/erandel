/*----------------------
 | �m�F�_�C�A���O�N���X |
  ----------------------*/
class DialogClass{
	private:
		int  DrawX,DrawY;										//�`����WX
		int  Width,Height;										//�`����WY
		std::string Message;									//�_�C�A���O���b�Z�[�W
		int  MessageFontSize;									//���b�Z�[�W�t�H���g�T�C�Y
		int  SelectFlag;										//�I���t���O
		bool DrawFlag;											//�`��t���O
		int  SelectNo;											//�I��ԍ�
		int  Timer;												//�^�C�}�J�E���^
		bool FirstFlag;											//��񂾂����s���鏈���̃t���O

		struct MenuArg_rec MenuParam;							//���j���[�̃p�����[�^

	public:
		DialogClass();											//������
		void SetPoint();										//���W������
		void SetMenuParam();									//���j���[�p�����[�^�ݒ�
		
		void SetSelectNo(int SelectNo,std::string Message);		//�I��ԍ��Z�b�g
		void Draw(UserClass &User);								//�_�C�A���O�`��
		bool GetDrawFlag();										//�`��t���O�擾
		int  GetSelectFlag();									//�I���t���O�擾
		int  GetSelectNo();										//�I��ԍ��擾
		void Clear();											//�_�C�A���O�폜

		//SE�Ɋւ���N���X
		SESoundClass SE;
};