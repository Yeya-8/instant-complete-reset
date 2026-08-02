#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Windows.h>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
    struct Fields {
        bool wasRDown = false;
    };

    void checkForEnd() {
        PlayLayer::checkForEnd();

        bool rDown = (GetAsyncKeyState('R') & 0x8000) != 0;
        if (rDown && !m_fields->wasRDown && m_endChecked) {
            log::info("R detected via raw poll during end sequence, resetting");
            m_hasCompletedLevel = false;
            this->resetLevel();
        }
        m_fields->wasRDown = rDown;
    }
};
