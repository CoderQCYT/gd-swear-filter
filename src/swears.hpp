#pragma once
#include <string>
#include <regex>
#include <unordered_map>
#include <vector>

struct SwearEntry {
    std::string word;
    std::string pattern;
    int level;
    std::unordered_map<int, std::string> replacements;
};

std::vector<SwearEntry> swears = {
    // --- Level 1: Slurs against protected classes ---
    {"nigger", "\\bnigger", 1, {{1,"black person"}}},
    {"faggot", "\\bfaggot", 1, {{1,"gay person"}}},
    {"nigga", "\\bnigga", 1, {{1,"black people"}}},
    {"jipped", "\\bjipped\\b", 1, {{1,""}}},
    {"gypped", "\\bgypped\\b", 1, {{1,""}}},
    {"peanut gallery", "\\bpeanut gallery\\b", 1, {{1,""}}},
    {"peanutgallery", "\\bpeanutgallery\\b", 1, {{1,""}}},
    {"tranny", "\\btranny\\b", 1, {{1,""}}},
    {"hermaphrodite", "\\bhermaphrodite\\b", 1, {{1,""}}},
    {"shemale", "\\bshemale\\b", 1, {{1,""}}},
    {"heshe", "\\bheshe\\b", 1, {{1,""}}},
    {"transgenderist", "\\btransgenderist\\b", 1, {{1,""}}},
    {"transgenderism", "\\btransgenderism\\b", 1, {{1,""}}},
    {"transsexualism", "\\btranssexualism\\b", 1, {{1,""}}},
    {"transsexualist", "\\btranssexualist\\b", 1, {{1,""}}},
    {"batty boy", "\\bbatty boy\\b", 1, {{1,""}}},
    {"battyboy", "\\bbattyboy\\b", 1, {{1,""}}},
    {"cocksucker", "\\bcocksucker\\b", 1, {{1,""}}},
    {"gayrope", "\\bgayrope\\b", 1, {{1,""}}},
    {"homintern", "\\bhomintern\\b", 1, {{1,""}}},
    {"lesbo", "\\blesbo\\b", 1, {{1,""}}},
    {"sissy", "\\bsissy\\b", 1, {{1,""}}},
    {"gay rope", "\\bgay rope\\b", 1, {{1,""}}},
    {"fence-sitter", "\\bfence-sitter\\b", 1, {{1,""}}},
    {"fencesitter", "\\bfencesitter\\b", 1, {{1,""}}},
    {"fence sitter", "\\bfence sitter\\b", 1, {{1,""}}},
    {"bulldyke", "\\bbulldyke\\b", 1, {{1,""}}},
    {"bull dyke", "\\bbull dyke\\b", 1, {{1,""}}},
    {"bull-dyke", "\\bbull-dyke\\b", 1, {{1,""}}},
    {"chickenhawk", "\\bchickenhawk\\b", 1, {{1,""}}},
    {"chicken hawk", "\\bchicken hawk\\b", 1, {{1,""}}},
    {"chicken-hawk", "\\bchicken-hawk\\b", 1, {{1,""}}},
    {"chickenqueen", "\\bchickenqueen\\b", 1, {{1,""}}},
    {"chicken queen", "\\bchicken queen\\b", 1, {{1,""}}},
    {"chicken-queen", "\\bchicken-queen\\b", 1, {{1,""}}},
    {"chickenplucker", "\\bchickenplucker\\b", 1, {{1,""}}},
    {"chicken plucker", "\\bchicken plucker\\b", 1, {{1,""}}},
    {"chicken-plucker", "\\bchicken-plucker\\b", 1, {{1,""}}},
    {"cuntboy", "\\bcuntboy\\b", 1, {{1,""}}},
    {"fag hag", "\\bfag hag\\b", 1, {{1,""}}},
    {"wetback", "\\bwetback\\b", 1, {{1,""}}},
    {"retard", "\\bretard", 1, {{1,""}}},

    // --- Level 2: Sexual profanity ---
    {"sperm", "\\bsperm\\b", 2, {{2,"sexual material"}}},
    {"sex", "\\bsex\\b", 2, {{2,"sexual activity"}}},
    {"sexy", "\\bsexy\\b", 2, {{2,"attractive"}}},
    {"semen", "\\bsemen\\b", 2, {{2,"fluid"}}},
    {"jizz", "\\bjizz\\b", 2, {{2,"fluid"}}},
    {"ejaculate", "\\bejaculate\\b", 2, {{2,"release"}}},
    {"jacking", "\\bjacking\\b", 2, {{2,"activity"}}},
    {"jerking", "\\bjerking\\b", 2, {{2,"activity"}}},
    {"edging", "\\bedging\\b", 2, {{2,"activity"}}},
    {"masturbat", "\\bmasturbat\\b", 2, {{2,"activity"}}},
    {"jacked", "\\bjacked\\b", 2, {{2,"excited"}}},
    {"jerked", "\\bjerked\\b", 2, {{2,"moved"}}},
    {"edged", "\\bedged\\b", 2, {{2,"tensed"}}},
    {"penis", "\\bpenis\\b", 2, {{2,"genital"}}},
    {"pussy", "\\bpussy\\b", 2, {{2,"genital"}}},
    {"cock", "\\bcock\\b", 2, {{2,"genital"}}},
    {"dick", "\\bdick\\b", 2, {{2,"genital"}}},
    {"vajina", "\\bvajina\\b", 2, {{2,"vagina"}}},
    {"vagina", "\\bvagina\\b", 2, {{2,"vagina"}}},
    {"fingerbang", "\\bfingerbang\\b", 2, {{2,"sexual act"}}},
    {"bang me", "\\bbang me\\b", 2, {{2,"have sex with me"}}},
    {"bang you", "\\bbang you\\b", 2, {{2,"have sex with you"}}},
    {"orgy", "\\borgy\\b", 2, {{2,"group sexual activity"}}},
    {"orgasm", "\\borgasm\\b", 2, {{2,"climax"}}},
    {"threesome", "\\bthreesome\\b", 2, {{2,"three-person activity"}}},
    {"foursome", "\\bfoursome\\b", 2, {{2,"four-person activity"}}},
    {"2g1c", "\\b2g1c\\b", 2, {{2,"explicit content"}}},

    // --- Level 3: Excrement profanity ---
    {"shit", "\\bshitt", 3, {{3,"crapp"}}},
    {"shit", "\\bshit", 3, {{3,"crap"}}},

    // --- Level 4: Mild profanity ---
    {"fuck", "\\bfuck\\b", 4, {{4,"hell"}}},
    {"what the fuck", "\\bwhat the fuck\\b", 4, {{4,"what the hell"}}},
    {"bitch", "\\bbitch\\b", 4, {{4,"jerk"}}},
    {"bitches", "\\bbitches\\b", 4, {{4,"jerks"}}},
    {"bitching", "\\bbitching\\b", 4, {{4,"complaining"}}},
    {"twat", "\\btwat\\b", 4, {{4,"jerk"}}},
    {"fucker", "\\bfucker\\b", 4, {{4,"person"}}},
    {"fuckery", "\\bfuckery\\b", 4, {{4,"nonsense"}}},
    {"fucking", "\\bfucking\\b", 4, {{4,"extremely"}}},
    {"fucked", "\\bfucked\\b", 4, {{4,"messed up"}}},
    {"fucks", "\\bfucks\\b", 4, {{4,"issues"}}},
    {"bitcher", "\\bbitcher\\b", 4, {{4,"complainer"}}},
    {"fuk", "\\bfuk\\b", 4, {{4,"heck"}}},
    {"cunt", "\\bcunt\\b", 4, {{4,"jerk"}}},
    {"cunts", "\\bcunts\\b", 4, {{4,"jerks"}}},

    // --- Level 5: Religious and silly levels of profanity ---
    {"god damn", "\\bgod damn", 5, {{5,"darn"}}},
    {"damn", "\\bdamn", 5, {{5,"darn"}}},
    {"hell", "\\bhell\\b", 5, {{5,"heck"}}},
    {"crap", "\\bcrap\\b", 5, {{5,"poop"}}},
    {"crappy", "\\bcrappy\\b", 5, {{5,"muddy"}}},
    {"crappiest", "\\bcrappiest\\b", 5, {{5,"muddiest"}}},
    {"crapper", "\\bcrapper\\b", 5, {{5,"toilet"}}},
    {"craps", "\\bcraps\\b", 5, {{5,"poops"}}},
    {"ass", "\\bass\\b", 5, {{5,"tail"}} },
};
