#ifndef CAW_SRC_LEETCODE_SPIRAL_MATRIX_CC_
#define CAW_SRC_LEETCODE_SPIRAL_MATRIX_CC_

#include <limits.h>

#include <tuple>
#include <vector>

namespace SpiralMatrix
{
  using Linearized = std::vector<int>;
  using Row = std::vector<int>;
  using Matrix = std::vector<Row>;
  using Position = std::tuple<int, int>;

  class SpiralMatrix
  {
  public:
    Linearized handle(Matrix &matrix) const
    {
      int VISITED = INT_MAX;
      int ySize = matrix.size();
      int xSize = matrix[0].size();
      int count = xSize * ySize;
      Linearized spiral = Linearized(count);
      int direction = 0;
      Position pos = std::make_tuple(0, 0);  // x, y

      auto getX = [&pos]() { return std::get<0>(pos); };
      auto getY = [&pos]() { return std::get<1>(pos); };

      auto getPosValue = [&matrix, &pos, &getX, &getY]() {
        return matrix[getY()][getX()];
      };

      auto advancePos = [&pos, &getX, &getY](int xIncrement, int yIncrement) {
        pos = std::make_tuple(getX() + xIncrement, getY() + yIncrement);
      };

      auto advanceDirection = [&direction]() {
        direction = (direction + 1) % 4;
      };

      auto isPosVisited = [&pos, &getPosValue, VISITED]() {
        return getPosValue() == VISITED;
      };

      for (int i = 0; i < count; i++) {
        int posValue = getPosValue();
        matrix[getY()][getX()] = VISITED;
        spiral[i] = posValue;

        switch (direction) {
          // right
          case 0:
            advancePos(1, 0);
            if (getX() == xSize || isPosVisited()) {
              advanceDirection();
              advancePos(-1, 1);
            }
            break;
          // bottom
          case 1:
            advancePos(0, 1);
            if (getY() == ySize || isPosVisited()) {
              advanceDirection();
              advancePos(-1, -1);
            }
            break;
          // left;
          case 2:
            advancePos(-1, 0);
            if (getX() == -1 || isPosVisited()) {
              advanceDirection();
              advancePos(1, -1);
            }
            break;
          // top
          case 3:
            advancePos(0, -1);
            if (getY() == -1 || isPosVisited()) {
              advanceDirection();
              advancePos(1, 1);
            }
            break;
        }
      }

      return spiral;
    }
  };
};  // namespace SpiralMatrix

#endif /* CAW_SRC_LEETCODE_SPIRAL_MATRIX_CC_ */
