/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>

#include <regex>

#include <Geode/modify/InfoLayer.hpp>

#include <Geode/modify/LevelCell.hpp>

#include <Geode/modify/CommentCell.hpp>

#include "swears.h"

using namespace geode::prelude;
using namespace std;

/**
 * `$modify` lets you extend and modify GD's 
 * classes; to hook a function in Geode, 
 * simply $modify the class and write a new 
 * function definition with the signature of 
 * the one you want to hook.
 */

const char* doFilter(const char * message) {
  std::string oldResult;
  std::string result = message;
  std::vector < std::string > swears;
  if (Mod::get() -> getSettingValue < bool > ("filter-profanity")) {
    for (const auto & swear: profanity) {
      swears.push_back(swear);
    }
  }
  if (Mod::get() -> getSettingValue < bool > ("filter-sexual")) {
    for (const auto & swear: sexual) {
      swears.push_back(swear);
    }
  }
  if (Mod::get() -> getSettingValue < bool > ("filter-racism")) {
    for (const auto & swear: racism) {
      swears.push_back(swear);
    }
  }
  if (Mod::get() -> getSettingValue < bool > ("filter-antilgbtq")) {
    for (const auto & swear: antilgbtq) {
      swears.push_back(swear);
    }
  }
  for (const auto & currentWord: swears) {
    if (!result.empty() && result != "") {
      oldResult = result;
    }
    std::regex pattern((std::string)
      "" + currentWord + (std::string)
      "", std::regex_constants::icase);
      std::string replacement = "";
      replacement = std::string(currentWord.length(), '*');
      if (Mod::get() -> getSettingValue < bool > ("relax-censor")) {
replacement = currentWord[0] + std::string(replacement.length() - 2, '*') + currentWord[replacement.length() - 1];
      }
        
    result = std::regex_replace(result, pattern, replacement);
    if (result.empty()) {
      result = oldResult;
    }
  }
  return result.c_str();
}

class $modify(CommentCell) {
  void loadFromComment(GJComment * p0) {
    if (Mod::get() -> getSettingValue < bool > ("censor-comments")) {
      gd::string oldString = p0 -> m_commentString;
      p0 -> m_commentString = (gd::string) doFilter(p0 -> m_commentString.c_str());
      if (p0 -> m_commentString.empty()) {
        p0 -> m_commentString = oldString;
      }
    }
    CommentCell::loadFromComment(p0);

  }
};

class $modify(InfoLayer) {
  bool init(GJGameLevel* p0, GJUserScore* p1, GJLevelList* p2) {
    if (p0 != NULL) {
      if (Mod::get() -> getSettingValue < bool > ("censor-level-names")) {
        gd::string oldLevelName = p0 -> m_levelName;
        p0 -> m_levelName = (gd::string) doFilter(p0 -> m_levelName.c_str());
        if (p0 -> m_levelName.empty()) {
          p0 -> m_levelName = oldLevelName;
        }
      }
      if (Mod::get() -> getSettingValue < bool > ("censor-level-descriptions")) {
        gd::string oldLevelDesc = p0 -> m_levelDesc;
        p0 -> m_levelDesc = (gd::string) doFilter(p0 -> m_levelDesc.c_str());
        if (p0 -> m_levelDesc.empty()) {
          p0 -> m_levelDesc = oldLevelDesc;
        }
      }
    }
    if (InfoLayer::init(p0, p1, p2) == false) {
      return false;
    }
    return true;
  }
};

class $modify(LevelCell) {
  TodoReturn loadFromLevel(GJGameLevel* p0) {
    if (p0 != NULL) {
      gd::string oldLevelName = p0 -> m_levelName;

      p0 -> m_levelName = (gd::string) doFilter(p0 -> m_levelName.c_str());
      if (p0 -> m_levelName.empty()) {
        p0 -> m_levelName = oldLevelName;
      }
      gd::string oldLevelDesc = p0 -> m_levelDesc;
      p0 -> m_levelDesc = (gd::string) doFilter(p0 -> m_levelDesc.c_str());
      if (p0 -> m_levelDesc.empty()) {
        p0 -> m_levelDesc = oldLevelDesc;
      }
    }
    return LevelCell::loadFromLevel(p0);
  }
};