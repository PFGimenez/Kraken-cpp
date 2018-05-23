#ifndef TESTS_RECTANGULAR_OBSTACLE_H
#define TESTS_RECTANGULAR_OBSTACLE_H

#include "Obstacle.h"
#include "../struct/vector_2d.h"

namespace kraken
{
    class RectangularObstacle : public Obstacle
    {
    public:
        RectangularObstacle(const Vector2D &position, const int &size_x, const int &size_y);
        RectangularObstacle(const Vector2D &position, const int &size_x, const int &size_y, const float &angle);
        RectangularObstacle(const int &distance_to_front, const int &distance_to_back, const int &distance_to_left,
                            const int &distance_to_right);
        RectangularObstacle(const int &distance_to_front, const int &distancesquaredDistance_to_back,
                            const int &distance_to_left,
                            const int &distance_to_right, const float &tilt_angle);
        RectangularObstacle(const Vector2D &position, const int &size_left_x, const int &size_right_x,
                            const int &size_up_y, const int &size_down_y, const float &angle);
        RectangularObstacle(const Vector2D &position, const Vector2D &top_right_corner,
                            const Vector2D &bottom_left_corner, const float &angle);

        void update(const Vector2D &position, const float &orientation);
        void update(const float &x, const float &y, const float &orientation);

        void getExpandedConvexHull(const float &expansion, const float &longestAllowedLength,
                                   std::vector<Vector2D> &vector_2d_list) const override;
        float squaredDistance(const Vector2D &v) const override;
        bool isInObstacle(const Vector2D &pos) const override;
        bool isColliding(const Vector2D &point_a, const Vector2D &point_b) const override;
        bool isColliding(const RectangularObstacle &obs) const override;

        float getHalfDiagonal() const;
    protected:
        Vector2D toObstacleCoordinateSystem(const Vector2D &point) const;
        Vector2D toTableCoordinateSystem(const Vector2D &point) const;

        float getXToObstacleCoordinateSystem(const Vector2D &point) const;
        float getYToObstacleCoordinateSystem(const Vector2D &point) const;

    private:
        bool test_separation(const float &a, const float &b, const float &a2, const float &b2, const float &c2,
                             const float &d2) const;

#if DEBUG
        friend std::ostream &operator<<(std::ostream &strm, const RectangularObstacle &o);
#endif

    protected:
        float angle_;
        float cos_;
        float sin_;

        // these corners are in the obstacle coordinate system
        Vector2D left_bottom_corner_;
        Vector2D left_upper_corner_;
        Vector2D right_bottom_corner_;
        Vector2D right_upper_corner_;

        // these corners are in the table coordinate system
        Vector2D left_bottom_corner_rotate_;
        Vector2D left_upper_corner_rotate_;
        Vector2D right_bottom_corner_rotate_;
        Vector2D right_upper_corner_rotate_;

        Vector2D geometric_center_;
        float half_diagonal_;
    };
}

#endif //TESTS_RECTANGULAR_OBSTACLE_H