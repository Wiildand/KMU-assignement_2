//
// Created by Remi Peyras on 13/10/2021.
//

#ifndef KMU_ASSIGNEMENT_2_MIDPOINT_HPP
#define KMU_ASSIGNEMENT_2_MIDPOINT_HPP

#include "assignement2.hpp"

class MidPoint {
public:
    explicit MidPoint(const float &xStart = 0, const float &yStart = 0, const float &xEnd = 0, const float &yEnd = 0);

    MidPoint(const glm::vec2 &pointStart, const glm::vec2 &pointEnd);

    ~MidPoint() = default;

    void draw() const;

    glm::vec2 getPointStart() const;

    void setPointStart(const float &x = 0, const float &y = 0);

    void setPointStart(const glm::vec2 &point = glm::vec2(0, 0));

    glm::vec2 getPointEnd() const;

    void setPointEnd(const float &x = 0, const float &y = 0);

    void setPointEnd(const glm::vec2 &point = glm::vec2(0, 0));

    friend std::ostream &operator<<(std::ostream &os, const MidPoint &midPoint);

private:
    glm::vec2 _pointStart;
    glm::vec2 _pointEnd;

    void _drawSmoothPoint(const glm::vec2 &vector, const float pointSize) const;
};


#endif //KMU_ASSIGNEMENT_2_MIDPOINT_HPP
