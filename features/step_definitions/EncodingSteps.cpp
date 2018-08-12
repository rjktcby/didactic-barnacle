#include <iostream>
#include <memory>
#include <jpeglib.h>

#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

using cucumber::ScenarioScope;

class JpegEncoderCtx
{
    struct jpeg_compress_struct m_cinfo;
    struct jpeg_error_mgr m_jerr;

  public:
    JpegEncoderCtx()
    {
        m_cinfo.err = jpeg_std_error(&m_jerr);
        jpeg_create_compress(&m_cinfo);
    }

    ~JpegEncoderCtx()
    {
        jpeg_destroy_compress(&m_cinfo);
    }
};

GIVEN("^I create encoding context$")
{
    ScenarioScope<JpegEncoderCtx> context;
}

WHEN("^I set \"([^\"]*)\" to (\\d+)$", (const std::string &name, const int value))
{
    ScenarioScope<JpegEncoderCtx> context;

    std::cout << name << " set to int=" << value << std::endl;
}

WHEN("^I set \"([^\"]*)\" to (.*)$", (const std::string &name, const double value))
{
    ScenarioScope<JpegEncoderCtx> context;

    std::cout << name << " set to double=" << value << std::endl;
}

WHEN("^I set \"([^\"]*)\" to \"([^\"]*)\"$", (const std::string &name, const std::string &value))
{
    ScenarioScope<JpegEncoderCtx> context;

    std::cout << name << " set to string=" << value << std::endl;
}

THEN("^I destroy encoding context$")
{
    ScenarioScope<JpegEncoderCtx> context;
}
