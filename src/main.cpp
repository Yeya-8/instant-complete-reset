#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
    struct Fields {
        bool lastCompleted = false;
        bool lastEndChecked = false;
    };

    void checkForEnd() {
        PlayLayer::checkForEnd();

        if (m_hasCompletedLevel != m_fields->lastCompleted) {
            m_fields->lastCompleted = m_hasCompletedLevel;
            log::info("m_hasCompletedLevel changed to {}", m_hasCompletedLevel);
        }
        if (m_endChecked != m_fields->lastEndChecked) {
            m_fields->lastEndChecked = m_endChecked;
            log::info("m_endChecked changed to {}", m_endChecked);
        }
    }
};

class $modify(InstantResetDispatcher, CCKeyboardDispatcher) {
    bool dispatchKeyboardMSG(cocos2d::enumKeyCodes key, bool isKeyDown, bool isKeyRepeat, double time) {
        if (isKeyDown && key == cocos2d::KEY_R) {
            log::info("R pressed");
        }
        return CCKeyboardDispatcher::dispatchKeyboardMSG(key, isKeyDown, isKeyRepeat, time);
    }
};
