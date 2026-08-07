#include "../Filter.hpp"
#include <Geode/Geode.hpp>
using namespace geode::prelude;

#include "swears.hpp"

// The actual text filtering system
std::string Filter::BasicText::filter(const std::string& message) {
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