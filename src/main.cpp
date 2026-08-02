#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>

using namespace geode::prelude;

class $modify(InstantResetDispatcher, CCKeyboardDispatcher) {
    bool dispatchKeyboardMSG(cocos2d::enumKeyCodes key, bool isKeyDown, bool isKeyRepeat, double time) {
        if (isKeyDown && key == cocos2d::KEY_R) {
            log::info("R pressed, checking PlayLayer...");
            if (auto pl = PlayLayer::get()) {
                log::info("PlayLayer found. m_hasCompletedLevel = {}", pl->m_hasCompletedLevel);
                if (pl->m_hasCompletedLevel) {
                    log::info("Calling resetLevel()");
                    pl->m_hasCompletedLevel = false;
                    pl->resetLevel();
                    return true;
                }
            } else {
                log::info("PlayLayer::get() returned null");
            }
        }
        return CCKeyboardDispatcher::dispatchKeyboardMSG(key, isKeyDown, isKeyRepeat, time);
    }
};
