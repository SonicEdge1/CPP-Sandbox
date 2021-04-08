
#include "strike_task.hpp"

// References:
//    CMS (activemq-cpp) Overview : https://activemq.apache.org/components/cms/overview
//    CMS (activemq-cpp) pub/sub example : https://activemq.apache.org/components/cms/example
//    XSD (CodeSynthesis) getting started guide : https://www.codesynthesis.com/projects/xsd/documentation/cxx/tree/guide/
//    XSD (CodeSynthesis) manual : https://www.codesynthesis.com/projects/xsd/documentation/cxx/tree/manual/
//    XSD (CodeSynthesis) API reference : https://www.codesynthesis.com/projects/xsd/documentation/cxx/tree/reference/html/
//    XSD (CodeSynthesis) CLI reference: https://www.codesynthesis.com/projects/xsd/documentation/xsd.xhtml


int main (int argc, char* argv[])
{
    setenv("SPDLOG_LEVEL", "trace", 1);

    TaskExample strike_example;

    strike_example.send_message();

    strike_example.wait_for_messages();
}
