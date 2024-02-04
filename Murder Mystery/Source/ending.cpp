#include"../header/define.h"

/*--------------------
 | �G���f�B���O�N���X |
  --------------------*/
/*������*/
EndingClass::EndingClass(){
	PlayFlag    = FALSE;
}

/*����Đ�*/
void EndingClass::StartMovie(UserClass &User){
	static bool FirstFlag = FALSE;
	int MovieVol;

	const int MinVol = 9000;

	//���ʎ擾
	MovieVol = User.GetBGMVol() * 4;

	//�Đ��O�̏�����
	if( FirstFlag == FALSE ){
		MovieHandle = LoadGraph("./resource/movie/Ending.ogv");
		SetMovieVolumeToGraph( MinVol + MovieVol,MovieHandle) ;
		PlayMovieToGraph( MovieHandle );
		FirstFlag  = TRUE;
		PlayFlag  = TRUE;
	}

	//����Đ�
	if( PlayFlag == TRUE ){
		DrawGraph(0,0,MovieHandle,TRUE);
		WaitTimer(17);
	}

	//�Đ��������f
	if( GetMovieStateToGraph(MovieHandle) != 1 ){
		PlayFlag  = FALSE;
		FirstFlag = FALSE;
	}
}

/*�Z�[�u�G���f�B���O*/
void EndingClass::SaveEnd(){
	FILE *fp;

	const int EndKey = 831;

	fp = fopen("./resource/data/syslog.dat","wb+");
	fwrite(&EndKey,1,sizeof(int),fp);
	fclose(fp);

}

/*�^�C�g���ɖ߂�*/
void EndingClass::BackTitle(UserClass &User,int &ModeFlag){
	if( PlayFlag == FALSE ){
		ModeFlag = MODE::MAIN;
		//User.SetPage(PAGE::TITLE);
	}
}

/*���C��*/
void EndingClass::Main(UserClass &User,int &ModeFlag){
	//����Đ�
	StartMovie(User);
	
	//�I���������Ƃ��L�^
	SaveEnd();

	//�G���f�B���O��A�^�C�g���ɖ߂�
	BackTitle(User,ModeFlag);
}



