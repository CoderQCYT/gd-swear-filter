#include <Geode/Geode.hpp>
#include <Geode/modify/InfoLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/modify/LevelCell.hpp>
#include <Geode/modify/CommentCell.hpp>
#include <Geode/modify/TextGameObject.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/cocos/label_nodes/CCLabelBMFont.h>
#include <Geode/cocos/base_nodes/CCNode.h>
#include <Geode/cocos/layers_scenes_transitions_nodes/CCScene.h>
#include <Geode/utils/base64.hpp>

#include <regex>
#include <fstream>
#include <vector>
#include <string>

using namespace geode::prelude;

#include "swears.hpp"

// The actual text filtering system
std::string doFilter(const std::string& message) {
	int64_t filterLevel = Mod::get()->getSettingValue<int64_t>("filter-level");
	if (filterLevel <= 0) return message;

	bool replacementsEnabled = Mod::get()->getSettingValue<bool>("enable-replacements");
	bool strictMode = !replacementsEnabled && Mod::get()->getSettingValue<bool>("strict-mode");
	bool relaxCensor = !replacementsEnabled && Mod::get()->getSettingValue<bool>("relax-censor");

	std::string filtered = message;

	for (int64_t currentLevel = 1; currentLevel <= filterLevel; ++currentLevel) {
		for (const auto& entry : swears) {
			if (entry.level != currentLevel) continue;

			std::string result;
			std::string::const_iterator searchStart(filtered.cbegin());
			std::smatch match;
			char replacementChar = Mod::get()->getSettingValue<std::string>("replacement-character")[0];

			std::string pattern = entry.pattern;

			if (strictMode) pattern = std::regex_replace(pattern, std::regex("\\\\b"), "");

			while (std::regex_search(searchStart, filtered.cend(), match, std::regex(pattern, std::regex_constants::icase))) {
				result.append(searchStart, match.prefix().second);

				std::string word = match.str();
				std::string replacement;

				if (replacementsEnabled && !entry.replacements.empty()) {
					int64_t bestLevel = -1;
					for (auto& [lvl, val] : entry.replacements) {
						if (lvl <= filterLevel && lvl > bestLevel) bestLevel = lvl;
					}
					if (bestLevel != -1) replacement = entry.replacements.at(bestLevel);
					else replacement = std::string(word.length(), replacementChar);
				}
				else {
					replacement = word;

					if (!relaxCensor) replacement = std::string(word.length(), replacementChar);
					else for (size_t i = 1; i < word.size() - 1; ++i) replacement[i] = replacementChar;
				}

				result.append(replacement);
				searchStart = match.suffix().first;
			}

			result.append(searchStart, filtered.cend());
			filtered = result;
		}
	}

	// geode::log::debug("Filter: {}->{}", message, filtered);

	return filtered;
}

class $modify(CommentCell) {
	void loadFromComment(GJComment* p0) {
		if (Mod::get()->getSettingValue<bool>("censor-comments"))
			p0->m_commentString = doFilter(p0->m_commentString);

		CommentCell::loadFromComment(p0);
	}
};

class $modify(InfoLayer) {
	bool init(GJGameLevel* level, GJUserScore* score, GJLevelList* list) {
		if (!InfoLayer::init(level, score, list)) return false;

		if (Mod::get()->getSettingValue<bool>("censor-level-names")) {
			CCLabelBMFont* label = (CCLabelBMFont*)getChildByIDRecursive("title-label");
			if (label) label->setString(doFilter(label->getString()).c_str());
		}

		if (Mod::get()->getSettingValue<bool>("censor-level-descriptions")) {
			TextArea* label = (TextArea*)getChildByIDRecursive("description-area");
			if (label) label->setString(doFilter(level->getUnpackedLevelDescription()).c_str());
		}

		return true;
	}
};

class $modify(LevelInfoLayer) {
	bool init(GJGameLevel* level, bool challenge) {
		if (!LevelInfoLayer::init(level, challenge)) return false;

		if (Mod::get()->getSettingValue<bool>("censor-level-names")) {
			CCLabelBMFont* label = (CCLabelBMFont*)getChildByID("title-label");
			if (label) label->setString(doFilter(label->getString()).c_str());
		}
		if (Mod::get()->getSettingValue<bool>("censor-song-names")) {
			CustomSongWidget* songWidget = (CustomSongWidget*)getChildByID("custom-songs-widget");
			CCLabelBMFont* label = (CCLabelBMFont*)songWidget->getChildByID("song-name-label");
			if (label) label->setString(doFilter(label->getString()).c_str());
		}

		return true;
	}
};

class $modify(LevelCell) {
	void loadFromLevel(GJGameLevel* p0) {
		LevelCell::loadFromLevel(p0);

		if (Mod::get()->getSettingValue<bool>("censor-level-names")) {
			CCLabelBMFont* label = (CCLabelBMFont*)LevelCell::getChildByIDRecursive("level-name");
			if (label) label->setString(doFilter(label->getString()).c_str());
		}

		if (Mod::get()->getSettingValue<bool>("censor-song-names")) {
			CCLabelBMFont* label = (CCLabelBMFont*)LevelCell::getChildByIDRecursive("song-name");
			if (label) label->setString(doFilter(label->getString()).c_str());
		}
	}
};

class $modify(TextGameObject) {
	void updateTextObject(gd::string text, bool defaultFont) {
		if (PlayLayer::get() && Mod::get()->getSettingValue<bool>("censor-text-objects")) // don't replace text in the editor
			text = doFilter(text);

		return TextGameObject::updateTextObject(text, defaultFont);
	}

	static TextGameObject* create(cocos2d::CCTexture2D* texture) {
		TextGameObject* object = TextGameObject::create(texture);
		if (PlayLayer::get() && Mod::get()->getSettingValue<bool>("censor-text-objects")) // ditto
			object->m_text = doFilter(object->m_text);

		return object;
	}
};

class $modify(PauseLayer) {
	void customSetup() {
		PauseLayer::customSetup();

		if (Mod::get()->getSettingValue<bool>("censor-level-names")) {
			CCLabelBMFont* levelName = (CCLabelBMFont*)PauseLayer::getChildByIDRecursive("level-name");
			if (levelName) levelName->setString(doFilter(levelName->getString()).c_str());
		}
	}
};