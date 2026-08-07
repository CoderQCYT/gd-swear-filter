#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include "../Filter/Filter.hpp"

using namespace geode::prelude;

class $modify(LevelInfoLayer) {
	bool init(GJGameLevel* level, bool challenge) {
		if (!LevelInfoLayer::init(level, challenge)) return false;

		if (Mod::get()->getSettingValue<bool>("censor-level-names")) {
			CCLabelBMFont* label = (CCLabelBMFont*)getChildByID("title-label");
			if (label) label->setString(Filter::BasicText::filter(label->getString()).c_str());
		}
		if (Mod::get()->getSettingValue<bool>("censor-song-names")) {
			CustomSongWidget* songWidget = (CustomSongWidget*)getChildByID("custom-songs-widget");
			CCLabelBMFont* label = (CCLabelBMFont*)songWidget->getChildByID("song-name-label");
			if (label) label->setString(Filter::BasicText::filter(label->getString()).c_str());
		}

		return true;
	}
};
