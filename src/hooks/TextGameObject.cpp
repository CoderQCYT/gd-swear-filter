#include <Geode/Geode.hpp>
#include <Geode/modify/TextGameObject.hpp>
#include "../Filter/Filter.hpp"

using namespace geode::prelude;

class $modify(TextGameObject) {
	void updateTextObject(gd::string text, bool defaultFont) {
		if (PlayLayer::get() && Mod::get()->getSettingValue<bool>("censor-text-objects")) // don't replace text in the editor
			text = Filter::BasicText::filter(text);

		return TextGameObject::updateTextObject(text, defaultFont);
	}

	static TextGameObject* create(cocos2d::CCTexture2D* texture) {
		TextGameObject* object = TextGameObject::create(texture);
		if (PlayLayer::get() && Mod::get()->getSettingValue<bool>("censor-text-objects")) // ditto
			object->m_text = Filter::BasicText::filter(object->m_text);

		return object;
	}
};