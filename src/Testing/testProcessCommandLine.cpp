// Unit test for MPAGSCipher ProcessCommandLine interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"
#include "CaesarMode.hpp"

TEST_CASE("helpRequested flag turns on when calling --help", "[cmdargument]"){

    std::vector<std::string> argVector{"", "--help"};
    ProgramSettings setting{false, false, "", "", "", CipherMode::Encrypt};

    processCommandLine(argVector, setting);

    REQUIRE( setting.helpRequested == true );
}

TEST_CASE("versionRequested flag turns on when calling --version", "[cmdargument]"){

    std::vector<std::string> argVector{"", "--version"};
    ProgramSettings setting{false, false, "", "", "", CipherMode::Encrypt};

    processCommandLine(argVector, setting);

    REQUIRE( setting.versionRequested == true );
}