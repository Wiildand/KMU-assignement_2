//
// Created by Remi Peyras on 13/10/2021.
//

#include "MidPoint.hpp"

/**
  * @construct __constructor
  * @desc Create the object MidPoint
  *
  * @param {const float &} xStart Coordinate X for the first point
  * @param {const float &} yStart Coordinate Y for the first point
  * @param {const float &} xEnd Coordinate X for the second point
  * @param {const float &} yEnd Coordinate Y for the second point
  */
MidPoint::MidPoint(const float &xStart, const float &yStart, const float &xEnd, const float &yEnd) :
        _pointStart(xStart, yStart), _pointEnd(xEnd, yEnd) {

}

/**
  * @construct __constructor
  * @desc Create the object MidPoint
  *
  * @param {const glm::vec2 &} pointStart Coordinate for the first point
  * @param {const glm::vec2 &} pointEnd Coordinate for the second point
  */
MidPoint::MidPoint(const glm::vec2 &pointStart, const glm::vec2 &pointEnd) :
        _pointStart(pointStart), _pointEnd(pointEnd) {}

/**
  * @function draw
  * @desc Display all the point from the algorithm of MidPoint
  *
  */
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

/**
  * @function getPointStart
  * @desc Getter of the proprieties _pointStart
  *
  * @returns {glm::vec2} pointStart
  */
glm::vec2 MidPoint::getPointStart() const {
    return _pointStart;
}

/**
  * @function setPointStart
  * @desc Setter of the proprieties _pointStart
  *
  * @param {const float &} x new X Coordinate for the first point
  * @param {const float &} y new Y Coordinate for the first point
  */
void MidPoint::setPointStart(const float &x, const float &y) {
    _pointStart = glm::vec2(x, y);
}

/**
  * @function setPointStart
  * @desc Setter of the proprieties _pointStart
  *
  * @param {const glm::vec2} point new {X, Y} Coordinate for the first point
  */
void MidPoint::setPointStart(const glm::vec2 &point) {
    _pointStart = point;
}

/**
  * @function getPointEnd
  * @desc Getter of the proprieties _pointEnd
  *
  * @returns {glm::vec2} pointEnd
  */
glm::vec2 MidPoint::getPointEnd() const {
    return _pointEnd;
}

/**
  * @function setPointEnd
  * @desc Setter of the proprieties _pointEnd
  *
  * @param {const float &} x new X Coordinate for the second point
  * @param {const float &} y new Y Coordinate for the second point
  */
void MidPoint::setPointEnd(const float &x, const float &y) {
    _pointEnd = glm::vec2(x, y);
}

/**
  * @function setPointEnd
  * @desc Setter of the proprieties _pointEnd
  *
  * @param {const glm::vec2} point new {X, Y} Coordinate for the first point
  */
void MidPoint::setPointEnd(const glm::vec2 &point) {
    _pointEnd = point;
}

/**
 * @function &operator<<
 * @desc Overload of operator '<<' to display directly in the os the information of the class Midpoint
 *
 * @param {std::ostream &} os Display method
 * @param {const MidPoint &} midPoint Class MidPoint which use in the std::<cout | cerr>
 * @returns {std::ostream &} Display the coordinate of the two points
 */
std::ostream &operator<<(std::ostream &os, const MidPoint &midPoint) {

    os << "Start : (" << midPoint.getPointStart().x << ", " << midPoint.getPointStart().y << ")";
    os << " End : (" << midPoint.getPointEnd().x << ", " << midPoint.getPointEnd().y << ")";
    return os;
}

/**
 * @function _drawSmoothPoint
 * @desc Display a point on OpenGL
 *
 * @param {const glm::vec2 &} vector Coordinate of the point to display
 * @param {const float &} pointSize Size of the point to display
 */
void MidPoint::_drawSmoothPoint(const glm::vec2 &vector, const float &pointSize) const {
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

