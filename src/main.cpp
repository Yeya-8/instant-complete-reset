#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Windows.h>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
    struct Fields {
        bool wasRDown = false;
        bool isCompleting = false;
    };

    void checkForEnd() {
        PlayLayer::checkForEnd();

        if (m_endChecked) {
            m_fields->isCompleting = true;
        }

        pollReset();
    }

    void activatePlatformerEndTrigger(EndTriggerGameObject* object, std::vector<int> const& remapKeys) {
        m_fields->isCompleting = true;
        PlayLayer::activatePlatformerEndTrigger(object, remapKeys);
    }

    void pollReset() {
        bool rDown = (GetAsyncKeyState('R') & 0x8000) != 0;
        if (rDown && !m_fields->wasRDown && m_fields->isCompleting) {
            log::info("R detected, resetting");
            m_fields->isCompleting = false;
            m_hasCompletedLevel = false;
            this->resetLevel();
        }
        m_fields->wasRDown = rDown;
    }
};
