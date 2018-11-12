#ifndef TESTS_CIRCULAR_OBSTACLE_H
#define TESTS_CIRCULAR_OBSTACLE_H

#include "../struct/vector_2d.h"
#include "obstacle.h"

#if DEBUG

#include <ostream>

#endif

namespace kraken
{
    class CircularObstacle : public Obstacle
    {
    public:
        CircularObstacle(const Vector2D &pos, float radius) noexcept;
        bool isInObstacle(const Vector2D &pos) const noexcept override;
        float squaredDistance(const Vector2D &pos) const override;
        void getExpandedConvexHull(const float &expansion, const float &longestAllowedLength,
                                   std::vector<Vector2D> &vector_2d_list) const noexcept override;
        bool isColliding(const Vector2D &point_a, const Vector2D &point_b) const noexcept override;
        bool isColliding(const RectangularObstacle &obs) const noexcept override;
        bool operator==(const Obstacle &rhs) const noexcept override;

#if DEBUG
        friend std::ostream &operator<<(std::ostream &strm, const CircularObstacle &o);
#endif

    protected:
        float const radius_;
        float const squared_radius_;
    };
}

#endif //TESTS_CIRCULAR_OBSTACLE_H
