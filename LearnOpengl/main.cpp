#include<glad/glad.h> 
// 要先包含glad的文件，因为glad提供了include<gl.h>之类的操作
#include<GLFW/glfw3.h>

#include<iostream>

// 用户改变窗口大小的回调函数
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// 处理键盘输入，检测按键是否被按下
void processInput(GLFWwindow* window);

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";


int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// 设置的参数 https://www.glfw.org/docs/latest/window.html#window_hints
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); MacOs

	GLFWwindow* window = glfwCreateWindow(1280, 1024, "WindyIce", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl; // GLFW窗口创建失败
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// GLAD用来管理OpenGL的函数指针，所以在调用OpenGL的函数之前我们需要初始化GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl; // GLAD初始化失败
		return -1;
	}

	glViewport(0, 0, 1280, 1024);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};

	// 顶点缓冲对象，管理顶点内存，储存大量顶点，使用该对象一次性发送一大批数据到显卡上，而不是每个顶点发送一次。
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // GL_ARRAY_BUFFER是顶点缓冲对象的缓冲类型
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	/*GL_STATIC_DRAW ：数据不会或几乎不会改变。
GL_DYNAMIC_DRAW：数据会被改变很多。
GL_STREAM_DRAW ：数据每次绘制时都会改变。*/

	// 创建顶点着色器
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // 第二个参数是传递的字符串数量
	glCompileShader(vertexShader);

	// 创建片段着色器
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	int success;
	char infoLog[512];
	// 获取shader编译的成功与否的信息
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "GL:COMPILE_ERROR顶点着色器编译错误\n" << infoLog << std::endl;
	}

	// 着色器程序对象
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// 检查链接着色器是否成功
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "GL::LINK_ERROR着色器程序链接失败\n" << std::endl;
	}



	while (!glfwWindowShouldClose(window)) {

		// 输入
		processInput(window);

		// 渲染指令.

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT); // 三个参数：Color, Depth, Stencil

		// 检查并调用事件，交换缓冲
		glfwSwapBuffers(window);  // 交换颜色缓冲
		glfwPollEvents(); // 检查是否有没有触发事件，更新窗口状态。
	}

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	// 同时改变视口的大小
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow * window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}