#pragma once

#include "gmock/gmock.h"

#include "tcframe/runner/grader/TestCaseGrader.hpp"

namespace tcframe {

class MockTestCaseGrader : public TestCaseGrader {
public:
    MockTestCaseGrader()
            : TestCaseGrader(nullptr, nullptr) {}

    MOCK_METHOD2(grade, Verdict(const TestCase&, const GradingOptions&));
};

}
