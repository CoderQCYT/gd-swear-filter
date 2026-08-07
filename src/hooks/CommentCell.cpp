#include <Geode/Geode.hpp>
#include <Geode/modify/CommentCell.hpp>
#include "../Filter/Filter.hpp"

using namespace geode::prelude;

class $modify(CommentCell) {
	void loadFromComment(GJComment* p0) {
		if (Mod::get()->getSettingValue<bool>("censor-comments"))
			p0->m_commentString = Filter::BasicText::filter(p0->m_commentString);

		CommentCell::loadFromComment(p0);
	}
};