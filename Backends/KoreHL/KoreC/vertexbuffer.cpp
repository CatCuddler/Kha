#include <Kore/pch.h>
#include <Kore/Graphics4/Graphics.h>
#include <hl.h>

extern "C" vbyte *hl_kore_create_vertexstructure() {
	return (vbyte*)new Kore::Graphics4::VertexStructure();
}

extern "C" void hl_kore_vertexstructure_add(vbyte *structure, vbyte *name, int data) {
	Kore::Graphics4::VertexStructure* struc = (Kore::Graphics4::VertexStructure*)structure;
	struc->add((char*)name, (Kore::Graphics4::VertexData)data);
}

extern "C" vbyte *hl_kore_create_vertexbuffer(int vertexCount, vbyte *structure, int stepRate) {
	Kore::Graphics4::VertexStructure* struc = (Kore::Graphics4::VertexStructure*)structure;
	return (vbyte*)new Kore::Graphics4::VertexBuffer(vertexCount, *struc, stepRate);
}

extern "C" void hl_kore_delete_vertexbuffer(vbyte *buffer) {
	Kore::Graphics4::VertexBuffer* buf = (Kore::Graphics4::VertexBuffer*)buffer;
	delete buf;
}

extern "C" vbyte *hl_kore_vertexbuffer_lock(vbyte *buffer) {
	Kore::Graphics4::VertexBuffer* buf = (Kore::Graphics4::VertexBuffer*)buffer;
	return (vbyte*)buf->lock();
}

extern "C" void hl_kore_vertexbuffer_unlock(vbyte *buffer) {
	Kore::Graphics4::VertexBuffer* buf = (Kore::Graphics4::VertexBuffer*)buffer;
	buf->unlock();
}

extern "C" int hl_kore_vertexbuffer_count(vbyte *buffer) {
	Kore::Graphics4::VertexBuffer* buf = (Kore::Graphics4::VertexBuffer*)buffer;
	return buf->count();
}

extern "C" int hl_kore_vertexbuffer_stride(vbyte *buffer) {
	Kore::Graphics4::VertexBuffer* buf = (Kore::Graphics4::VertexBuffer*)buffer;
	return buf->stride();
}
