# KMU-assignement_2

Student id : 7001893 Rémi-Peyras

Response of all exercice : '''Response_7001893-Rémi-PEYRAS.docx'''
Documentation of the project into folder: '''Documentation'''
Source of the Code into folder : '''source + include'''

## Mandatory

You need to have :

- Cmake
- make

## How To build the Code

- Create a new folder named : '''build'''
- Enter into the folder '''build'''
- Do this command : '''cmake ..''' (will generate a configuration to compile the code)
- Do this command : '''make''' (compile the code)
- Do this command : '''./ComputerGraphic_Assignment_02''' (will execute the code)

# --- Documentation ---

# Main.cpp

## **displayAxis**

> Method to display the different axis in the window

```
void displayAxis() 
```

___

## **exerciseMidPoint**

> Function to create and display the MidPoint Exercice

```
void exerciseMidPoint() 
```

___

## **processInput**

> Function to manage the different style of input only ESCAPE is available to leave the program

```
void processInput(GLFWwindow *window) 
```

### PARAMETERS:

| NAME | TYPE | DESCRIPTION |
|------ | ------ | -------------|
|window|GLFWwindow *|Window active by OpenGL|

___

## **initGlwWindow**

> Initialization of the structure GLFWwindow

```
GLFWwindow *initGlwWindow() 
```

### RETURN VALUE:

|TYPE | DESCRIPTION |
|------|-------------|
|GLFWwindow *|Structure GLFWwindow setup correctly|

___

# MidPoint.cpp

## **__constructor**

> Create the object MidPoint

```
MidPoint::MidPoint(const float &xStart, const float &yStart, const float &xEnd, const float &yEnd) :
        _pointStart(xStart, yStart), _pointEnd(xEnd, yEnd) 
```

### PARAMETERS:

| NAME | TYPE | DESCRIPTION |
|------ | ------ | -------------|
|xStart|const float &|Coordinate X for the first point|
|yStart|const float &|Coordinate Y for the first point|
|xEnd|const float &|Coordinate X for the second point|
|yEnd|const float &|Coordinate Y for the second point|

___

## **__constructor**

> Create the object MidPoint

```
MidPoint::MidPoint(const glm::vec2 &pointStart, const glm::vec2 &pointEnd) :
        _pointStart(pointStart), _pointEnd(pointEnd) 
```

### PARAMETERS:

| NAME | TYPE | DESCRIPTION |
|------ | ------ | -------------|
|pointStart|const glm::vec2 &|Coordinate for the first point|
|pointEnd|const glm::vec2 &|Coordinate for the second point|

___

## **draw**

> Display all the point from the algorithm of MidPoint

```
void MidPoint::draw() const 
```

___

## **getPointStart**

> Getter of the proprieties _pointStart

```
glm::vec2 MidPoint::getPointStart() const 
```

### RETURN VALUE:

|TYPE | DESCRIPTION |
|------|-------------|
|glm::vec2|pointStart|

___

## **setPointStart**

> Setter of the proprieties _pointStart

```
void MidPoint::setPointStart(const float &x, const float &y) 
```

### PARAMETERS:

| NAME | TYPE | DESCRIPTION |
|------ | ------ | -------------|
|x|const float &|new X Coordinate for the first point|
|y|const float &|new Y Coordinate for the first point|

___

## **setPointStart**

> Setter of the proprieties _pointStart

```
void MidPoint::setPointStart(const glm::vec2 &point) 
```

### PARAMETERS:

| NAME | TYPE | DESCRIPTION |
|------ | ------ | -------------|
|point|const glm::vec2|new {X, Y} Coordinate for the first point|

___

## **getPointEnd**

> Getter of the proprieties _pointEnd

```
glm::vec2 MidPoint::getPointEnd() const 
```

### RETURN VALUE:

|TYPE | DESCRIPTION |
|------|-------------|
|glm::vec2|pointEnd|

___

## **setPointEnd**

> Setter of the proprieties _pointEnd

```
void MidPoint::setPointEnd(const float &x, const float &y) 
```

### PARAMETERS:

| NAME | TYPE | DESCRIPTION |
|------ | ------ | -------------|
|x|const float &|new X Coordinate for the second point|
|y|const float &|new Y Coordinate for the second point|

___

## **setPointEnd**

> Setter of the proprieties _pointEnd

```
void MidPoint::setPointEnd(const glm::vec2 &point) 
```

### PARAMETERS:

| NAME | TYPE | DESCRIPTION |
|------ | ------ | -------------|
|point|const glm::vec2|new {X, Y} Coordinate for the first point|

___

## **&operator<<**

> Overload of operator '<<' to display directly in the os the information of the class Midpoint

```
std::ostream &operator<<(std::ostream &os, const MidPoint &midPoint) 
```

### PARAMETERS:

| NAME | TYPE | DESCRIPTION |
|------ | ------ | -------------|
|os|std::ostream &|Display method|
|midPoint|const MidPoint &|Class MidPoint which use in the std::<cout | cerr>|

### RETURN VALUE:

|TYPE | DESCRIPTION |
|------|-------------|
|std::ostream &|Display the coordinate of the two points|

___

## **_drawSmoothPoint**

> Display a point on OpenGL

```
void MidPoint::_drawSmoothPoint(const glm::vec2 &vector, const float &pointSize) const 
```

### PARAMETERS:

| NAME | TYPE | DESCRIPTION |
|------ | ------ | -------------|
|vector|const glm::vec2 &|Coordinate of the point to display|
|pointSize|const float &|Size of the point to display|

___
