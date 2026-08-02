#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Windows.h>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
    struct Fields {
        bool wasRDown = false;
    };

    void update(float dt) {
        PlayLayer::update(dt);

        bool rDown = (GetAsyncKeyState('R') & 0x8000) != 0;
        if (rDown && !m_fields->wasRDown && m_endChecked) {
            log::info("R detected via raw poll in update(), resetting");
            m_hasCompletedLevel = false;
            this->resetLevel();
        }
        m_fields->wasRDown = rDown;
    }
};
