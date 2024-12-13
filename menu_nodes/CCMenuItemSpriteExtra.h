#ifndef __CCMENUITEMSPRITEEXTRA_H__
#define __CCMENUITEMSPRITEEXTRA_H__

#include <gd.h>

enum class MenuAnimationType {
    Scale = 0,
    Move = 1,
};

namespace gd {
	#pragma runtime_checks("s", off)
	class CCMenuItemSpriteExtra : public cocos2d::CCMenuItemSprite {
	protected:
		float m_scaleMultiplier;
		float m_baseScale;
		bool m_animationEnabled;
		bool m_colorEnabled;
		float m_unknown;
		std::string m_unknown2;
		std::string m_unknown3;
		float m_colorDip;
		cocos2d::CCPoint m_destPosition;
		cocos2d::CCPoint m_offset;
		MenuAnimationType m_animationType;
		cocos2d::CCPoint m_startPosition;
		CCMenuItemSpriteExtra() {
			reinterpret_cast<void*(__thiscall*)(CCMenuItemSpriteExtra*)>(base + 0x18db0)(this);
		}
	public:
		static CCMenuItemSpriteExtra* create(cocos2d::CCNode* sprite,
			cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback) {
			auto pRet = reinterpret_cast<CCMenuItemSpriteExtra* (__thiscall*)(cocos2d::CCNode*,
				cocos2d::CCObject*, cocos2d::SEL_MenuHandler)>(
					base + 0x18EE0
					)(sprite, target, callback);
			//fix stack before returning
			__asm add esp, 0x8
			return pRet;
		}
		void setSizeMult(float mult) {
			__asm movss xmm1, mult
			return reinterpret_cast<void(__thiscall*)(CCMenuItemSpriteExtra*)>(
				base + 0x19080
				)(this);
		}
		bool init(
			cocos2d::CCNode* sprite,
			cocos2d::CCObject* target,
			cocos2d::SEL_MenuHandler callback
		){
			return init(sprite, sprite, target, callback);
		}
		
		bool init(
			cocos2d::CCNode* normalImage,
			cocos2d::CCNode* selectedImage,
			cocos2d::CCObject* target,
			cocos2d::SEL_MenuHandler callback
		) {
			if (!cocos2d::CCMenuItemSprite::initWithNormalSprite(
				normalImage, selectedImage, nullptr, target, callback
			)) return false;

			this->setAnchorPoint({ .5f, .5f });
			this->setContentSize(normalImage->getScaledContentSize());
			normalImage->setPosition(m_obContentSize / 2);

			m_baseScale = 1.f;
			m_animationEnabled = true;
			m_scaleMultiplier = 1.26f;

			return true;
		}
		
		virtual void activate(){
			return reinterpret_cast<void(__thiscall*)(FLAlertLayer*)>(
				base + 0x191c0
				)(this);
		}
		
		virtual void selected(){
			return reinterpret_cast<void(__thiscall*)(FLAlertLayer*)>(
				base + 0x19270
				)(this);
		}
		
		virtual void unselected(){
			return reinterpret_cast<void(__thiscall*)(FLAlertLayer*)>(
				base + 0x19430
				)(this);
		}
	};
	#pragma runtime_checks("s", restore)
}

#endif