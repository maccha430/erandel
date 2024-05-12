/*----------------
 | アイテムクラス |
  ----------------*/

class ItemClass {
protected:
	int Select;														//選択番号受け取り
	int FadeFlag;													//フェードフラグ
	bool flags[32];													//フラグ受け取り
	struct MenuArg_rec  UpperItemParam;								//上メニューパラメータ
	struct MenuArg_rec  UnderItemParam;								//上メニューパラメータ
	struct MenuArg_rec	ItemNaviParam;								//アイテムナビ
	vector<int> ItemHandle;											//アイテム画像

	bool ItemDialogFlag;
	bool MenuDialogFlag;

public:
	ItemClass();														//初期化
	void Main(UserClass& User, int& ChangeFlag);						//メイン
	void ModeChange(int& ModeFlag, int& ChangeFlag, UserClass& User);	//モードチェンジ
	void SetMenuParam();												//メニューパラメータセット
	void ItemLoad(bool flags[32]);										//アイテム画像をメニューにセット
	void Draw();														//描画
	ItemGraphClass Graph;												//グラフィック

};