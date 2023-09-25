#ifndef __BUFFERHELPERS_H__
#define __BUFFERHELPERS_H__

class Layout;
template<typename T>
void addLayoutMember(Layout& layout, int count) {}

template<>
void addLayoutMember<float>(Layout& layout, int count) {
	layout.addMember(sizeof(float), count, GL_FLOAT);
}
#endif // !__BUFFERHELPERS_H__
