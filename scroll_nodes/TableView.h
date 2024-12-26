#ifndef __TABLEVIEW_H__
#define __TABLEVIEW_H__

#include <gd.h>

namespace gd {

	class CCScrollLayerExt;
	class CCScrollLayerExtDelegate;
	class CCIndexPath;
	
	typedef enum {
		//idk what goes here
	} TableViewCellEditingStyle;

	class TableView : public CCScrollLayerExt, public CCScrollLayerExtDelegate {
		//lol i kinda just gave up i dont feel like re'ing this rn
	protected:
		PAD(8);
		cocos2d::CCPoint m_obUnknown1;
		cocos2d::CCPoint m_obUnknown2;
		cocos2d::CCPoint m_obUnknown3;
		PAD(8);
		cocos2d::CCArray* m_pArray1;
		cocos2d::CCArray* m_pArray2;
		cocos2d::CCArray* m_pArray3;
		PAD(28);
	};

	class TableViewCell : public cocos2d::CCLayer {
	public:
		PAD(8);
		CCIndexPath m_iIndexPath;
		PAD(4);
		std::string m_sUnknown;
		PAD(8);
		cocos2d::CCLayerColor* m_pLayerColor;
		cocos2d::CCLayer* m_pLayer;
		PAD(4);

		TableViewCell(const char* name, float height, cocos2d::ccColor4B color) {
			__asm {
				movss xmm2, height
				movss xmm3, color
			}
			reinterpret_cast<void(__thiscall*)(TableViewCell*, const char*)>(
				base + 0x32E70
				)(this, name);
		}
	};

	class TableViewDelegate {
	public:
		virtual void willTweenToIndexPath(CCIndexPath&, TableViewCell*, TableView*) {}
		virtual void didEndTweenToIndexPath(CCIndexPath&, TableView*) {}
		virtual void TableViewWillDisplayCellForRowAtIndexPath(CCIndexPath&, TableViewCell*, TableView*) {}
		virtual void TableViewDidDisplayCellForRowAtIndexPath(CCIndexPath&, TableViewCell*, TableView*) {}
		virtual void TableViewWillReloadCellForRowAtIndexPath(CCIndexPath&, TableViewCell*, TableView*) {}
		virtual float cellHeightForRowAtIndexPath(CCIndexPath&, TableView*) = 0;
		virtual void didSelectRowAtIndexPath(CCIndexPath&, TableView*) = 0;
	};

	class TableViewDataSource {
	public:
		virtual unsigned int numberOfRowsInSection(unsigned int, TableView*) = 0;
		virtual unsigned int numberOfSectionsInTableView(TableView*) { return 1; }
		virtual void TableViewCommitCellEditingStyleForRowAtIndexPath(TableView*, TableViewCellEditingStyle, CCIndexPath&) {}
		virtual TableViewCell* cellForRowAtIndexPath(CCIndexPath&, TableView*) = 0;
	};

	class GJGameLevel;
	class LevelCell /* 0x184 */ : public TableViewCell /* 0x17c */ {
	public:
		GJGameLevel* m_pLevel;  // 0x17c
		PAD(4)
	};

	class GJUserScore;
	class GJComment : public cocos2d::CCNode {
	public:
		std::string m_commentString;
		std::string m_userName;
		int m_commentID;
		int m_userID;
		int m_likeCount;
		int m_levelID;
		bool m_isSpam;
		int m_accountID;
		std::string m_uploadDate;
		bool m_commentDeleted;
		int m_percentage;
		int m_modBadge;
		cocos2d::ccColor3B m_color;
		bool m_hasLevelID;
		GJUserScore* m_userScore;

		static GJComment* create(cocos2d::CCDictionary* dict) {
			return reinterpret_cast<GJComment * (__fastcall*)(cocos2d::CCDictionary*)>(
				gd::base + 0xc3740
				)(dict);
		}
	};

	class CommentCell : public TableViewCell {
	public:
		PAD(0x4);
		cocos2d::CCSprite* m_pIconSprite;
		cocos2d::CCLabelBMFont* m_pLikeLabel;
		GJComment* m_pComment;
		PAD(0x4);
	};

	class GJScoreCell : public TableViewCell {

	};
}

#endif