#pragma once
#include <string>
#include <regex>
#include <unordered_map>
#include <vector>

struct SwearEntry {
    std::string patternStr;
    std::regex pattern;
    int level;
    std::unordered_map<int, std::string> replacements;
};

std::vector<SwearEntry> swears = {
    // --- Level 1: Slurs against protected classes ---
    {"nigger", std::regex("\\bnigger\\b", std::regex_constants::icase), 1, {{1,"black person"}}},
    {"faggot", std::regex("\\bfaggot\\b", std::regex_constants::icase), 1, {{1,"gay people"}}},
    {"nigga", std::regex("\\bnigga\\b", std::regex_constants::icase), 1, {{1,"black people"}}},
    {"niggers", std::regex("\\bniggers\\b", std::regex_constants::icase), 1, {{1,"black people"}}},
    {"jipped", std::regex("\\bjipped\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"gypped", std::regex("\\bgypped\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"peanut gallery", std::regex("\\bpeanut gallery\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"peanutgallery", std::regex("\\bpeanutgallery\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"tranny", std::regex("\\btranny\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"hermaphrodite", std::regex("\\bhermaphrodite\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"shemale", std::regex("\\bshemale\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"heshe", std::regex("\\bheshe\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"transgenderist", std::regex("\\btransgenderist\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"transgenderism", std::regex("\\btransgenderism\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"transsexualism", std::regex("\\btranssexualism\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"transsexualist", std::regex("\\btranssexualist\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"batty boy", std::regex("\\bbatty boy\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"battyboy", std::regex("\\bbattyboy\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"cocksucker", std::regex("\\bcocksucker\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"gayrope", std::regex("\\bgayrope\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"homintern", std::regex("\\bhomintern\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"lesbo", std::regex("\\blesbo\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"sissy", std::regex("\\bsissy\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"gay rope", std::regex("\\bgay rope\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"fence-sitter", std::regex("\\bfence-sitter\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"fencesitter", std::regex("\\bfencesitter\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"fence sitter", std::regex("\\bfence sitter\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"bulldyke", std::regex("\\bbulldyke\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"bull dyke", std::regex("\\bbull dyke\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"bull-dyke", std::regex("\\bbull-dyke\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"chickenhawk", std::regex("\\bchickenhawk\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"chicken hawk", std::regex("\\bchicken hawk\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"chicken-hawk", std::regex("\\bchicken-hawk\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"chickenqueen", std::regex("\\bchickenqueen\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"chicken queen", std::regex("\\bchicken queen\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"chicken-queen", std::regex("\\bchicken-queen\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"chickenplucker", std::regex("\\bchickenplucker\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"chicken plucker", std::regex("\\bchicken plucker\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"chicken-plucker", std::regex("\\bchicken-plucker\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"cuntboy", std::regex("\\bcuntboy\\b", std::regex_constants::icase), 1, {{1,""}}},
    {"fag hag", std::regex("\\bfag hag\\b", std::regex_constants::icase), 1, {{1,""}}},

    // --- Level 2: Sexual profanity ---
    {"sperm", std::regex("\\bsperm\\b", std::regex_constants::icase), 2, {{2,"sexual material"}}},
    {"sex", std::regex("\\bsex\\b", std::regex_constants::icase), 2, {{2,"sexual activity"}}},
    {"sexy", std::regex("\\bsexy\\b", std::regex_constants::icase), 2, {{2,"attractive"}}},
    {"semen", std::regex("\\bsemen\\b", std::regex_constants::icase), 2, {{2,"fluid"}}},
    {"jizz", std::regex("\\bjizz\\b", std::regex_constants::icase), 2, {{2,"fluid"}}},
    {"ejaculate", std::regex("\\bejaculate\\b", std::regex_constants::icase), 2, {{2,"release"}}},
    {"jacking", std::regex("\\bjacking\\b", std::regex_constants::icase), 2, {{2,"activity"}}},
    {"jerking", std::regex("\\bjerking\\b", std::regex_constants::icase), 2, {{2,"activity"}}},
    {"edging", std::regex("\\bedging\\b", std::regex_constants::icase), 2, {{2,"activity"}}},
    {"masturbat", std::regex("\\bmasturbat\\b", std::regex_constants::icase), 2, {{2,"activity"}}},
    {"jacked", std::regex("\\bjacked\\b", std::regex_constants::icase), 2, {{2,"excited"}}},
    {"jerked", std::regex("\\bjerked\\b", std::regex_constants::icase), 2, {{2,"moved"}}},
    {"edged", std::regex("\\bedged\\b", std::regex_constants::icase), 2, {{2,"tensed"}}},
    {"penis", std::regex("\\bpenis\\b", std::regex_constants::icase), 2, {{2,"genital"}}},
    {"pussy", std::regex("\\bpussy\\b", std::regex_constants::icase), 2, {{2,"genital"}}},
    {"cock", std::regex("\\bcock\\b", std::regex_constants::icase), 2, {{2,"genital"}}},
    {"dick", std::regex("\\bdick\\b", std::regex_constants::icase), 2, {{2,"genital"}}},
    {"vajina", std::regex("\\bvajina\\b", std::regex_constants::icase), 2, {{2,"vagina"}}},
    {"vagina", std::regex("\\bvagina\\b", std::regex_constants::icase), 2, {{2,"vagina"}}},
    {"fingerbang", std::regex("\\bfingerbang\\b", std::regex_constants::icase), 2, {{2,"sexual act"}}},
    {"bang me", std::regex("\\bbang me\\b", std::regex_constants::icase), 2, {{2,"have sex with me"}}},
    {"bang you", std::regex("\\bbang you\\b", std::regex_constants::icase), 2, {{2,"have sex with you"}}},
    {"orgy", std::regex("\\borgy\\b", std::regex_constants::icase), 2, {{2,"group sexual activity"}}},
    {"orgasm", std::regex("\\borgasm\\b", std::regex_constants::icase), 2, {{2,"climax"}}},
    {"threesome", std::regex("\\bthreesome\\b", std::regex_constants::icase), 2, {{2,"three-person activity"}}},
    {"foursome", std::regex("\\bfoursome\\b", std::regex_constants::icase), 2, {{2,"four-person activity"}}},
    {"2g1c", std::regex("\\b2g1c\\b", std::regex_constants::icase), 2, {{2,"explicit content"}}},

    // --- Level 3: Excrement profanity ---
    {"shit", std::regex("\\bshit\\b", std::regex_constants::icase), 3, {{3,"crap"}}},
    {"shitty", std::regex("\\bshitty\\b", std::regex_constants::icase), 3, {{3,"crappy"}}},
    {"shittiest", std::regex("\\bshittiest\\b", std::regex_constants::icase), 3, {{3,"crappiest"}}},
    {"shitter", std::regex("\\bshitter\\b", std::regex_constants::icase), 3, {{3,"crapper"}}},
    {"shits", std::regex("\\bshits\\b", std::regex_constants::icase), 3, {{3,"craps"}}},

    // --- Level 4: Mild profanity ---
    {"fuck", std::regex("\\bfuck\\b", std::regex_constants::icase), 4, {{4,"hell"}}},
    {"what the fuck", std::regex("\\bwhat the fuck\\b", std::regex_constants::icase), 4, {{4,"what the hell"}}},
    {"bitch", std::regex("\\bbitch\\b", std::regex_constants::icase), 4, {{4,"jerk"}}},
    {"bitches", std::regex("\\bbitches\\b", std::regex_constants::icase), 4, {{4,"jerks"}}},
    {"bitching", std::regex("\\bbitching\\b", std::regex_constants::icase), 4, {{4,"complaining"}}},
    {"twat", std::regex("\\btwat\\b", std::regex_constants::icase), 4, {{4,"jerk"}}},
    {"fucker", std::regex("\\bfucker\\b", std::regex_constants::icase), 4, {{4,"person"}}},
    {"fuckery", std::regex("\\bfuckery\\b", std::regex_constants::icase), 4, {{4,"nonsense"}}},
    {"fucking", std::regex("\\bfucking\\b", std::regex_constants::icase), 4, {{4,"extremely"}}},
    {"fucked", std::regex("\\bfucked\\b", std::regex_constants::icase), 4, {{4,"messed up"}}},
    {"fucks", std::regex("\\bfucks\\b", std::regex_constants::icase), 4, {{4,"issues"}}},
    {"bitcher", std::regex("\\bbitcher\\b", std::regex_constants::icase), 4, {{4,"complainer"}}},
    {"fuk", std::regex("\\bfuk\\b", std::regex_constants::icase), 4, {{4,"heck"}}},
    {"cunt", std::regex("\\bcunt\\b", std::regex_constants::icase), 4, {{4,"jerk"}}},
    {"cunts", std::regex("\\bcunts\\b", std::regex_constants::icase), 4, {{4,"jerks"}}},

    // --- Level 5: Religious and silly levels of profanity ---
    {"god damn", std::regex("\\bgod damn\\b", std::regex_constants::icase), 5, {{5,""}}},
    {"hell", std::regex("\\hell\\b", std::regex_constants::icase), 5, {{5,"heck"}}},
    {"crap", std::regex("\\bshit\\b", std::regex_constants::icase), 3, {{3,"poop"}}},
    {"crappy", std::regex("\\bshitty\\b", std::regex_constants::icase), 3, {{3,"muddy"}}},
    {"crappiest", std::regex("\\bshittiest\\b", std::regex_constants::icase), 3, {{3,"muddiest"}}},
    {"crapper", std::regex("\\bshitter\\b", std::regex_constants::icase), 3, {{3,"toilet"}}},
    {"craps", std::regex("\\bshits\\b", std::regex_constants::icase), 3, {{3,"poops"}}},
};
