#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../html_encode/Encode.h"

TEST_CASE("Check for replacement characters") {
	string input_string = "Cat <says> \"Meow\". M&M's";
	string output_string = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	CHECK(HtmlEncode(input_string) == output_string);
}