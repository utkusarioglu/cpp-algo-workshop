#ifndef CAW_TEST_LEETCODE_COURSE_SCHEDULE_UNIT_TEST_CC_
#define CAW_TEST_LEETCODE_COURSE_SCHEDULE_UNIT_TEST_CC_

#include <gtest/gtest.h>

#include "leetcode/course_schedule.cc"

namespace CourseSchedule
{
  namespace UnitTests
  {
    struct TestCase {
      int numCourses;
      CourseDefinitionList requirements;
      bool expected;
    };

    class CourseScheduleTf : public ::testing::TestWithParam<TestCase>
    {
    protected:
      TestCase params;
    };

    INSTANTIATE_TEST_CASE_P(
      CourseSchedule, CourseScheduleTf,
      ::testing::Values(
        TestCase(2, CourseDefinitionList{CourseDefinition{1, 0}}, true),
        TestCase(
          2,
          CourseDefinitionList{CourseDefinition{1, 0}, CourseDefinition{0, 1}},
          false
        )
      )
    );

    TEST_P(CourseScheduleTf, damn)
    {
      TestCase testCase = GetParam();
      CourseSchedule c = CourseSchedule();
      bool response = c.canFinish(testCase.numCourses, testCase.requirements);
      ASSERT_EQ(response, testCase.expected);
    };
  }  // namespace UnitTests
}  // namespace CourseSchedule

#endif /* CAW_TEST_LEETCODE_COURSE_SCHEDULE_UNIT_TEST_CC_ */
