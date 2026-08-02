#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

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

    void levelComplete() {
        log::info("levelComplete() called");
        PlayLayer::levelComplete();
    }

    void activatePlatformerEndTrigger(EndTriggerGameObject* object, std::vector<int> const& remapKeys) {
        log::info("activatePlatformerEndTrigger() called");
        PlayLayer::activatePlatformerEndTrigger(object, remapKeys);
    }
};
