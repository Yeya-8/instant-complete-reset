#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>
#include <Geode/loader/Loader.hpp>

using namespace geode::prelude;

class $modify(InstantResetDispatcher, CCKeyboardDispatcher) {
    bool dispatchKeyboardMSG(cocos2d::enumKeyCodes key, bool isKeyDown, bool isKeyRepeat, double time) {
        if (isKeyDown && key == cocos2d::KEY_R) {
            if (auto pl = PlayLayer::get()) {
                if (pl->m_hasCompletedLevel) {
                    pl->m_hasCompletedLevel = false;
                    Loader::get()->queueInMainThread([]() {
                        if (auto pl = PlayLayer::get()) {
                            pl->resetLevel();
                        }
                    });
                    return true;
                }
            }
        }
        return CCKeyboardDispatcher::dispatchKeyboardMSG(key, isKeyDown, isKeyRepeat, time);
    }
};
