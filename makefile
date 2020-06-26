
main: main.o IndexBuffer.o VertexBuffer.o VertexBufferLayout.o Renderer.o
	g++ src/*.cpp ./dep/bin/glew.o -o build/main.exe -L./dep/bin \
	-I./dep/include/ -lglfw3  -lgdi32 -lopengl32

main.o: src/main.cpp src/headers/IndexBuffer.h src/headers/VertexBuffer.h
VertexBufferLayout.o: src/VertexBufferLayout.cpp src/headers/VertexBufferLayout.h
IndexBuffer.o: src/IndexBuffer.cpp src/headers/IndexBuffer.h
VertexBuffer.o: src/VertexBuffer.cpp src/headers/VertexBuffer.h
Renderer.o: src/Renderer.cpp src/./headers/Renderer.h \
 src/./headers/IndexBuffer.h src/./headers/Shader.h \
 src/./headers/VertexBuffer.h src/./headers/VertexBufferLayout.h