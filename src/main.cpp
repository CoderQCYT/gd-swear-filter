#include <Geode/Geode.hpp>
#include <Geode/modify/InfoLayer.hpp>
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
std::string doFilter(const std::string & message) {
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

          while (std::regex_search(searchStart, filtered.cend(), match, entry.pattern)) {
              result.append(searchStart, match.prefix().second);

              std::string word = match.str();
              std::string replacement;

              if (replacementsEnabled && !entry.replacements.empty()) {
                  int64_t bestLevel = -1;
                  for (auto& [lvl, val] : entry.replacements) {
                      if (lvl <= filterLevel && lvl > bestLevel) bestLevel = lvl;
                  }
                  if (bestLevel != -1) replacement = entry.replacements.at(bestLevel);
                  else replacement = std::string(word.length(), '*');
              } else {
                  replacement = word;

                  if (!relaxCensor) replacement = std::string(word.length(), '*');
                  else for (size_t i = 1; i < word.size() - 1; ++i) replacement[i] = '*';
              }

              result.append(replacement);
              searchStart = match.suffix().first;
          }

          result.append(searchStart, filtered.cend());
          filtered = result;
      }
  }

  geode::log::debug("Filter: {}->{}", message, filtered);

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
  bool init(GJGameLevel* p0, GJUserScore* p1, GJLevelList* p2) {
    if (p0 != NULL) {
      if (Mod::get()->getSettingValue<bool>("censor-level-names"))
        p0->m_levelName = doFilter(p0->m_levelName);

      if (Mod::get()->getSettingValue<bool>("censor-level-descriptions")) {
        auto decodedResult = base64::decodeString(p0->m_levelDesc);

        if (decodedResult.isOk()) {
          std::string decodedDesc = decodedResult.unwrap();
          std::string filteredDesc = doFilter(decodedDesc);
          p0->m_levelDesc = base64::encode(filteredDesc);
        }
      }

    }
    return InfoLayer::init(p0, p1, p2);
  }
};

class $modify(LevelCell) {
  void loadFromLevel(GJGameLevel* p0) {
    if (p0 != NULL) {
      if (Mod::get()->getSettingValue<bool>("censor-level-names"))
        p0->m_levelName = doFilter(p0->m_levelName);

      if (Mod::get()->getSettingValue<bool>("censor-level-descriptions")) {
        auto decodedResult = base64::decodeString(p0->m_levelDesc);

        if (decodedResult.isOk()) {
          std::string decodedDesc = decodedResult.unwrap();
          std::string filteredDesc = doFilter(decodedDesc);
          p0->m_levelDesc = base64::encode(filteredDesc);
        }
      }

    }
    return LevelCell::loadFromLevel(p0);
  }
};

class $modify(TextGameObject) {
  void updateTextObject(gd::string text, bool defaultFont) {
    text = doFilter(text);

    return TextGameObject::updateTextObject(text, defaultFont);
  }

  static TextGameObject* create(cocos2d::CCTexture2D* texture) {
    TextGameObject* object = TextGameObject::create(texture);
	  if (Mod::get()->getSettingValue<bool>("censor-text-objects"))
		  object->m_text = doFilter(object->m_text);

      return object;
    }
};

/*
class $modify(PauseLayer) {
  static PauseLayer* create(bool unfocused) {
    geode::log::debug("PauseLayer hook works!");
    auto pauseLayer = PauseLayer::create(unfocused);
    cocos2d::CCScene* scene = cocos2d::CCScene::get();
    cocos2d::CCLabelBMFont* levelName = (cocos2d::CCLabelBMFont*)scene->getChildByID("music-label");
    std::string text = levelName->getString();
    levelName->setString(doFilter(text).c_str());

    return pauseLayer;
  }
};
*/