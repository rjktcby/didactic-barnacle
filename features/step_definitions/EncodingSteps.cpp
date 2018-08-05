#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

using cucumber::ScenarioScope;

struct JpegCtx
{
};

GIVEN("^I create jpeg encoder$")
{
    ScenarioScope<JpegCtx> context;
}
