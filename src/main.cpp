#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
    void keyDown(cocos2d::enumKeyCodes key) {
        if (key == cocos2d::enumKeyCodes::KEY_R && m_hasCompletedLevel) {
            m_hasCompletedLevel = false;
            this->resetLevel();
            return;
        }

        PlayLayer::keyDown(key);
    }
};
