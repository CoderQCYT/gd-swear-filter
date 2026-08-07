#include <Geode/Geode.hpp>
#include <Geode/modify/LevelCell.hpp>
#include "../Filter/Filter.hpp"

using namespace geode::prelude;


class $modify(LevelCell) {
	void loadFromLevel(GJGameLevel* p0) {
		LevelCell::loadFromLevel(p0);

		if (Mod::get()->getSettingValue<bool>("censor-level-names")) {
			CCLabelBMFont* label = (CCLabelBMFont*)LevelCell::getChildByIDRecursive("level-name");
			if (label) label->setString(Filter::BasicText::filter(label->getString()).c_str());
		}

		if (Mod::get()->getSettingValue<bool>("censor-song-names")) {
			CCLabelBMFont* label = (CCLabelBMFont*)LevelCell::getChildByIDRecursive("song-name");
			if (label) label->setString(Filter::BasicText::filter(label->getString()).c_str());
		}
	}
};