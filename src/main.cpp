#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>

using namespace geode::prelude;

class $modify(InstantResetDispatcher, CCKeyboardDispatcher) {
    bool dispatchKeyboardMSG(cocos2d::enumKeyCodes key, bool isKeyDown, bool isKeyRepeat, double time) {
        if (isKeyDown && key == cocos2d::KEY_R) {
            if (auto pl = PlayLayer::get()) {
                if (pl->m_hasCompletedLevel) {
                    log::info("=== Scene dump ===");
                    auto scene = cocos2d::CCDirector::sharedDirector()->getRunningScene();
                    if (auto children = scene->getChildren()) {
                        for (int i = 0; i < children->count(); i++) {
                            auto node = static_cast<cocos2d::CCNode*>(children->objectAtIndex(i));
                            log::info("Scene child {}: {} (zOrder {}, visible {})",
                                i, typeid(*node).name(), node->getZOrder(), node->isVisible());
                        }
                    }
                    log::info("PlayLayer children count: {}", pl->getChildrenCount());
                    log::info("=== End dump ===");
                }
            }
        }
        return CCKeyboardDispatcher::dispatchKeyboardMSG(key, isKeyDown, isKeyRepeat, time);
    }
};
