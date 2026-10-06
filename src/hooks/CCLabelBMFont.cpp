#include <Geode/Geode.hpp>
#include <Geode/modify/CCLabelBMFont.hpp>
#include "../Filter/Filter.hpp"

using namespace geode::prelude;

class $modify(MyLabel,cocos2d::CCLabelBMFont) {
    void updateLabel(){
        this->setString(Filter::BasicText::filter(this->getString()).c_str());
        cocos2d::CCLabelBMFont::updateLabel();
    }
};