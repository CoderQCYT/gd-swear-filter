#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include "../Filter/Filter.hpp"

using namespace geode::prelude;

class $modify(PauseLayer) {
	void customSetup() {
		customSetup();

		if (Mod::get()->getSettingValue<bool>("censor-level-names")) {
			CCLabelBMFont* levelName = (CCLabelBMFont*)getChildByIDRecursive("level-name");
			if (levelName) levelName->setString(Filter::BasicText::filter(levelName->getString()).c_str());
		}
	}
};