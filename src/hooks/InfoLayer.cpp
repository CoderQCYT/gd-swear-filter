#include <Geode/Geode.hpp>
#include <Geode/modify/InfoLayer.hpp>
#include "../Filter/Filter.hpp"

using namespace geode::prelude;

class $modify(InfoLayer)
{
	bool init(GJGameLevel* level, GJUserScore* score, GJLevelList* list)
	{
		if (!InfoLayer::init(level, score, list))
			return false;

		if (Mod::get()->getSettingValue<bool>("censor-level-names")) {
			CCLabelBMFont* label =
				(CCLabelBMFont*)getChildByIDRecursive("title-label");
			if (label)
				label->setString(Filter::BasicText::filter(label->getString()).c_str());
		}

		if (Mod::get()->getSettingValue<bool>("censor-level-descriptions")) {
			TextArea* label = (TextArea*)getChildByIDRecursive("description-area");
			if (label)
				label->setString(
					Filter::BasicText::filter(level->getUnpackedLevelDescription()).c_str());
		}

		return true;
	}
};
