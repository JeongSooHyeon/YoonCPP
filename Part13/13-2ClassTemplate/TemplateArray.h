#pragma once
#ifndef __ARRAY_TEMPLATE_H_
#define __ARRAY_TEMPLATE_H_

template <typename T>
class BoundCheckTemplateArray {
private:
	T* arr;
	int arrlen;
	BoundCheckTemplateArray(const BoundCheckTemplateArray& arr) {}
	BoundCheckTemplateArray& operator=(const BoundCheckTemplateArray& arr) {}
public:
	BoundCheckTemplateArray(int len);
	T& operator[] (int idx);
	T operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckTemplateArray();
};
#endif