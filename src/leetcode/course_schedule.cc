#ifndef CAW_SRC_LEETCODE_COURSE_SCHEDULE_CC_
#define CAW_SRC_LEETCODE_COURSE_SCHEDULE_CC_

#include <stack>
#include <unordered_set>
#include <vector>

namespace CourseSchedule
{
  using CourseDefinition = std::vector<int>;
  using CourseDefinitionList = std::vector<CourseDefinition>;

  typedef struct Course {
    std::vector<Course*> requirements = std::vector<Course*>();
  } Course;

  using CourseSet = std::unordered_set<Course*>;
  using CourseStack = std::stack<Course*>;

  class CourseSchedule
  {
  public:
    /**
     * A dfs that keeps track of visited edges. If ANY edge has been visited, it
     * returns false.
     */
    bool canFinish(int numCourses, CourseDefinitionList& list)
    {
      std::vector<Course*> courseGraph;
      for (int i = 0; i < numCourses; i++) {
        Course* c = new Course();
        courseGraph.push_back(c);
      }
      for (int i = 0; i < list.size(); i++) {
        int courseId = list[i][0];
        int requirementId = list[i][1];
        Course* requirementCourse = courseGraph[requirementId];
        Course* enrolledCourse = courseGraph[courseId];
        (*enrolledCourse).requirements.push_back(requirementCourse);
      }

      CourseStack stack = CourseStack();
      stack.push(courseGraph[0]);
      CourseSet stack_set = CourseSet();
      stack_set.insert(courseGraph[0]);

      while (stack.size() > 0) {
        Course* current = stack.top();
        std::vector<Course*> requirements = current->requirements;
        stack.pop();
        for (Course* requirement : requirements) {
          if (stack_set.contains(requirement)) {
            return false;
          }
          stack.push(requirement);
          stack_set.insert(requirement);
        }
      }

      return true;
    }
  };
}  // namespace CourseSchedule

#endif /* CAW_SRC_LEETCODE_COURSE_SCHEDULE_CC_ */
