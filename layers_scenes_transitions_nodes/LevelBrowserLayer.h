#ifndef __LEVELBROWSERLAYER_H__
#define __LEVELBROWSERLAYER_H__

#include <gd.h>

namespace gd {

	class GJSearchObject;
	class TextArea;
	class GJListLayer;

    class LevelBrowserLayer : cocos2d::CCLayer, FLAlertLayerProtocol, SetIDPopupDelegate {
    public:
        void* m_unk;
		TextArea* m_noInternet;
		GJListLayer* m_list;
		CCMenuItemSpriteExtra* m_rightArrow;
		CCMenuItemSpriteExtra* m_leftArrow;
		CCMenuItemSpriteExtra* m_lastBtn;
		CCMenuItemSpriteExtra* m_cancelSearchBtn;
		void* m_unk4;
		cocos2d::CCArray* m_array;
		GJSearchObject* m_searchObject;
		cocos2d::CCLabelBMFont* m_countText;
		cocos2d::CCLabelBMFont* m_pageText;
		CCMenuItemSpriteExtra* m_pageBtn;
		cocos2d::CCLabelBMFont* m_folderText;
		CCMenuItemSpriteExtra* m_folderBtn;
		int m_itemCount;
		int m_pageStartIdx;
		int m_pageEndIdx;
	
    };
}

#endif
