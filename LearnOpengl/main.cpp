#include<glad/glad.h> 
// Ҫ�Ȱ���glad���ļ�����Ϊglad�ṩ��include<gl.h>֮��Ĳ���
#include<GLFW/glfw3.h>

#include<iostream>

// �û��ı䴰�ڴ�С�Ļص�����
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// ����������룬��ⰴ���Ƿ񱻰���
void processInput(GLFWwindow* window);

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// ���õĲ��� https://www.glfw.org/docs/latest/window.html#window_hints
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); MacOs

	GLFWwindow* window = glfwCreateWindow(1280, 1024, "WindyIce", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl; // GLFW���ڴ���ʧ��
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// GLAD��������OpenGL�ĺ���ָ�룬�����ڵ���OpenGL�ĺ���֮ǰ������Ҫ��ʼ��GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl; // GLAD��ʼ��ʧ��
		return -1;
	}

	glViewport(0, 0, 1280, 1024);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};

	// ���㻺����󣬹������ڴ棬����������㣬ʹ�øö���һ���Է���һ�������ݵ��Կ��ϣ�������ÿ�����㷢��һ�Ρ�
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // GL_ARRAY_BUFFER�Ƕ��㻺�����Ļ�������
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	/*GL_STATIC_DRAW �����ݲ���򼸺�����ı䡣
GL_DYNAMIC_DRAW�����ݻᱻ�ı�ܶࡣ
GL_STREAM_DRAW ������ÿ�λ���ʱ����ı䡣*/



	while (!glfwWindowShouldClose(window)) {

		// ����
		processInput(window);

		// ��Ⱦָ��.

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT); // ����������Color, Depth, Stencil

		// ��鲢�����¼�����������
		glfwSwapBuffers(window);  // ������ɫ����
		glfwPollEvents(); // ����Ƿ���û�д����¼������´���״̬��
	}

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	// ͬʱ�ı��ӿڵĴ�С
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow * window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}