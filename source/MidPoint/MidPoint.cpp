//
// Created by Remi Peyras on 13/10/2021.
//

#include "MidPoint.hpp"


MidPoint::MidPoint(const float &xStart, const float &yStart, const float &xEnd, const float &yEnd) :
        _pointStart(xStart, yStart), _pointEnd(xEnd, yEnd) {}

MidPoint::MidPoint(const glm::vec2 &pointStart, const glm::vec2 &pointEnd) :
        _pointStart(pointStart), _pointEnd(pointEnd) {}


void MidPoint::draw() const {
    float dx = _pointEnd.x - _pointStart.x;
    float dy = _pointEnd.y - _pointStart.y;
    float pointSize = 25;

    _drawSmoothPoint(_pointStart, pointSize);
    std::cout << _pointStart.x << "," << _pointStart.y << std::endl;
    if (dy <= dx) {
        float d = dy - (dx / 2);
        float x = _pointStart.x;
        float y = _pointStart.y;
        std::cout << x << "," << y << std::endl;

        for (float x = _pointStart.x; x < _pointEnd.x;) {
            x++;
            if (d < 0)
                d += dy;
            else {
                d += (dy - dx);
                y++;
            }
            std::cout << x << "," << y << std::endl;
            _drawSmoothPoint({x, y}, pointSize);
        }
    } else if (dx < dy) {
        float d = dx - (dy / 2);
        float x = _pointStart.x;
        for (float y = _pointStart.y; y < _pointEnd.y;) {
            y++;
            if (d < 0)
                d += dx;
            else {
                d += (dx - dy);
                x++;
            }
            std::cout << x << "," << y << std::endl;
            _drawSmoothPoint({x, y}, pointSize);
        }
    }
}

glm::vec2 MidPoint::getPointStart() const {
    return _pointStart;
}

void MidPoint::setPointStart(const float &x, const float &y) {
    _pointStart = glm::vec2(x, y);
}

void MidPoint::setPointStart(const glm::vec2 &point) {
    _pointStart = point;
}

glm::vec2 MidPoint::getPointEnd() const {
    return _pointEnd;
}

void MidPoint::setPointEnd(const float &x, const float &y) {
    _pointEnd = glm::vec2(x, y);
}

void MidPoint::setPointEnd(const glm::vec2 &point) {
    _pointEnd = point;
}

std::ostream &operator<<(std::ostream &os, const MidPoint &midPoint) {

    os << "Start : (" << midPoint.getPointStart().x << ", " << midPoint.getPointStart().y << ")";
    os << " End : (" << midPoint.getPointEnd().x << ", " << midPoint.getPointEnd().y << ")";
    return os;
}

void MidPoint::_drawSmoothPoint(const glm::vec2 &vector, const float pointSize) const {
    GLfloat pointVertex[] = {vector.x, vector.y};

    glPushMatrix();

    glEnable(GL_POINT_SMOOTH);
    glEnableClientState(GL_VERTEX_ARRAY);
    glPointSize(pointSize);
    glVertexPointer(2, GL_FLOAT, 0, pointVertex);
    glDrawArrays(GL_POINTS, 0, 1);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisable(GL_POINT_SMOOTH);
    glPopMatrix();
}

