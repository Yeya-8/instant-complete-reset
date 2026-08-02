#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
    struct Fields {
        bool isCompleting = false;
    };

    void activatePlatformerEndTrigger(EndTriggerGameObject* object, std::vector<int> const& remapKeys) {
        m_fields->isCompleting = true;
        log::info("activatePlatformerEndTrigger fired - animation starting");
        PlayLayer::activatePlatformerEndTrigger(object, remapKeys);
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
                    log::info("R caught mid-animation, resetting now");
                    pl->resetLevel();
                    return true;
                }
            }
        }
        return CCKeyboardDispatcher::dispatchKeyboardMSG(key, isKeyDown, isKeyRepeat, time);
    }
};
