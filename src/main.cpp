#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
    struct Fields {
        bool isCompleting = false;
    };

    void levelComplete() {
        m_fields->isCompleting = true;
        PlayLayer::levelComplete();
    }
};

class $modify(InstantResetDispatcher, CCKeyboardDispatcher) {
    bool dispatchKeyboardMSG(cocos2d::enumKeyCodes key, bool isKeyDown, bool isKeyRepeat, double time) {
        if (isKeyDown && key == cocos2d::KEY_R) {
            if (auto pl = PlayLayer::get()) {
                auto modPl = static_cast<MyPlayLayer*>(pl);
                if (modPl->m_fields->isCompleting) {
                    modPl->m_fields->isCompleting = false;
                    pl->m_hasCompletedLevel = false;
                    log::info("Completion detected early, resetting now");
                    pl->resetLevel();
                    return true;
                }
            }
        }
        return CCKeyboardDispatcher::dispatchKeyboardMSG(key, isKeyDown, isKeyRepeat, time);
    }
};
