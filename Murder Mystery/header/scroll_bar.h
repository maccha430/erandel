/*----------------------
 | �X�N���[���o�[�N���X |
  ----------------------*/
class ScrollBarClass{
	private:
		int BarDrawX;					//�`��X���W
		int BarDrawY;					//�`��Y���W
		int BarWidth;					//�X�N���[���o�[���T�C�Y
		int BarHeight;					//�X�N���[���o�[�c�T�C�Y
		int MaxScroll;					//�X�N���[���ő�l
		int MinScroll;					//�X�N���[���ŏ��l
		int OldDrawY;					//�N���b�N�����O��Y���W
		int NewDrawY;					//�N���b�N���ꂽ����Y���W
		double MoveScroll;					//�ړ���
		double MoveAdd;					//�ړ��ʒǉ�
		int SubHeight;					//�`��I�u�W�F�N�g����ʂ���͂ݏo���Ă��

	public:
		ScrollBarClass();				//������
		double  MoveCalc();				//�ړ��ʌv�Z
		void SizeCalc(int DrawHeight);	//�X�N���[���o�[�T�C�Y�v�Z
		void DrawScrollBar();			//�X�N���[���o�[�`��
};