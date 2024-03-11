#include "Canvas.h"
#include <cstdio>
#include <cstdlib>

Canvas::Canvas(int width, int height) {
  this->matrix = new char *[height];
  for (unsigned int i = 0; i < height; i++)
    this->matrix[i] = new char[width];

  for (unsigned int i = 0; i < height; i++) {
    // char *line = this->matrix[i];
    for (unsigned int j = 0; j < width; j++)
      //*(line + j) = ' ';
      this->matrix[i][j] = ' ';
  }
  this->width = width;
  this->height = height;
}

Canvas::~Canvas() {
  if (this->matrix != nullptr)
    for (int i = 0; i < this->height; i++)
      delete[] this->matrix[i];
  delete[] this->matrix;
}

void Canvas::Print() {
  for (int i = 0; i < this->height; i++) {
    for (int j = 0; j < this->width; j++)
      printf("%c", this->matrix[i][j]);
    printf("\n");
  }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
  for (int i = left; i < right; i++)
    for (int j = top; j < bottom; j++)
      this->matrix[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {

  for (int i = left; i < right; i++)
    for (int j = top; j < bottom; j++)
      if ((i == left || i == right - 1) || (j == top || j == bottom - 1))
        this->matrix[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch) { this->matrix[x][y] = ch; }

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
  int dx = std::abs(x2 - x1);
  int sx = (x1 < x2) ? 1 : -1;
  int dy = -std::abs(y2 - y1);
  int sy = (y1 < y2) ? 1 : -1;
  int error = dx + dy;

  while (true) {
    this->matrix[x1][y1] = ch;
    if (x1 == x2 && y1 == y2)
      break;
    int e2 = 2 * error;
    if (e2 >= dy) {
      if (x1 == x2)
        break;
      error += dy;
      x1 += sx;
    }
    if (e2 <= dx) {
      if (y1 == y2)
        break;
      error += dx;
      y1 += sy;
    }
  }
}

void Canvas::Clear() {
  for (int i = 0; i < this->height; i++)
    for (int j = 0; j < this->width; j++)
      this->matrix[i][j] = ' ';
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
  int radius = ray;
  int x0 = x;
  int y0 = y;

  int xCurr = radius;
  int yCurr = 0;
  int err = 0;

  while (xCurr >= yCurr) {
    this->SetPoint(x0 + xCurr, y0 + yCurr, ch);
    this->SetPoint(x0 + yCurr, y0 + xCurr, ch);
    this->SetPoint(x0 - yCurr, y0 + xCurr, ch);
    this->SetPoint(x0 - xCurr, y0 + yCurr, ch);
    this->SetPoint(x0 - xCurr, y0 - yCurr, ch);
    this->SetPoint(x0 - yCurr, y0 - xCurr, ch);
    this->SetPoint(x0 + yCurr, y0 - xCurr, ch);
    this->SetPoint(x0 + xCurr, y0 - yCurr, ch);

    if (err <= 0) {
      ++yCurr;
      err += 2 * yCurr + 1;
    }
    if (err > 0) {
      --xCurr;
      err -= 2 * xCurr + 1;
    }
  }
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
  int x0 = x;
  int y0 = y;
  int radius = ray;
  for (int dy = -radius; dy <= radius; dy++) {
    for (int dx = -radius; dx <= radius; dx++) {
      if (dx * dx + dy * dy <= radius * radius) {
        SetPoint(x0 + dx, y0 + dy, ch);
      }
    }
  }
}
