#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
    void keyDown(cocos2d::enumKeyCodes key) {
        if (key == cocos2d::KEY_R && this->m_hasCompletedLevel) {
            this->m_hasCompletedLevel = false;
            this->resetLevel();
            return;
        }

        PlayLayer::keyDown(key);
    }
};
