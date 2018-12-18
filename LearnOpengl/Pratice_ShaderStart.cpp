//#include<glad/glad.h> 
//// 要先包含glad的文件，因为glad提供了include<gl.h>之类的操作
//#include<GLFW/glfw3.h>
//
//#include"Shader.h"
//
//#include<iostream>
//
//// 用户改变窗口大小的回调函数
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//
//// 处理键盘输入，检测按键是否被按下
//void processInput(GLFWwindow* window);
//
//int p1_ShaderStart();
//
//int p2_ShaderStart();
//
//int p3_ShaderStart();
//
//float vertices[] = {
//	// 位置              // 颜色
//	 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
//	-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
//	 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
//};
//
//int p1_ShaderStart() {
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	// 设置的参数 https://www.glfw.org/docs/latest/window.html#window_hints
//	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); MacOs
//
//	GLFWwindow* window = glfwCreateWindow(1280, 1024, "WindyIce", NULL, NULL);
//	if (window == NULL) {
//		std::cout << "Failed to create GLFW window" << std::endl; // GLFW窗口创建失败
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	// GLAD用来管理OpenGL的函数指针，所以在调用OpenGL的函数之前我们需要初始化GLAD
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD" << std::endl; // GLAD初始化失败
//		return -1;
//	}
//
//	glViewport(0, 0, 1280, 1024);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	Shader mShader("p1vs.vs", "p1fs.fs");
//
//	// 顶点缓冲对象，管理顶点内存，储存大量顶点，使用该对象一次性发送一大批数据到显卡上，而不是每个顶点发送一次。
//	unsigned int VBO;
//	// 顶点数组对象，任何顶点属性调用都会存储在VAO中。配置顶点属性指针的时候，只需要将那些调用执行一次。
//	unsigned int VAO;
//	// 索引缓冲对象，用来索引绘制。
//	unsigned int EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attribute(s)
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO); // GL_ARRAY_BUFFER是顶点缓冲对象的缓冲类型
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);// 位置属性
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));// 颜色属性
//	glEnableVertexAttribArray(1);
//
//	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//	glBindVertexArray(0); // 解绑定的操作
//
//
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	while (!glfwWindowShouldClose(window)) {
//
//		// 输入
//		processInput(window);
//
//		// 渲染指令.
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT); // 三个参数：Color, Depth, Stencil
//
//		///glUseProgram(shaderProgram);
//		mShader.use();
//
//		float timeValue = glfwGetTime();
//		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
//
//		glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		///glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//
//
//		// 检查并调用事件，交换缓冲
//		glfwSwapBuffers(window);  // 交换颜色缓冲
//		glfwPollEvents(); // 检查是否有没有触发事件，更新窗口状态。
//	}
//
//	// optional: de-allocate all resources once they've outlived their purpose:
//	// ------------------------------------------------------------------------
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//
//	glfwTerminate();
//	return 0;
//}
//
//int p2_ShaderStart() {
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	// 设置的参数 https://www.glfw.org/docs/latest/window.html#window_hints
//	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); MacOs
//
//	GLFWwindow* window = glfwCreateWindow(1280, 1024, "WindyIce", NULL, NULL);
//	if (window == NULL) {
//		std::cout << "Failed to create GLFW window" << std::endl; // GLFW窗口创建失败
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	// GLAD用来管理OpenGL的函数指针，所以在调用OpenGL的函数之前我们需要初始化GLAD
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD" << std::endl; // GLAD初始化失败
//		return -1;
//	}
//
//	glViewport(0, 0, 1280, 1024);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	Shader mShader("p2vs.vs", "p2fs.fs");
//
//	// 顶点缓冲对象，管理顶点内存，储存大量顶点，使用该对象一次性发送一大批数据到显卡上，而不是每个顶点发送一次。
//	unsigned int VBO;
//	// 顶点数组对象，任何顶点属性调用都会存储在VAO中。配置顶点属性指针的时候，只需要将那些调用执行一次。
//	unsigned int VAO;
//	// 索引缓冲对象，用来索引绘制。
//	unsigned int EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attribute(s)
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO); // GL_ARRAY_BUFFER是顶点缓冲对象的缓冲类型
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);// 位置属性
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));// 颜色属性
//	glEnableVertexAttribArray(1);
//
//	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//	glBindVertexArray(0); // 解绑定的操作
//
//
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	while (!glfwWindowShouldClose(window)) {
//
//		// 输入
//		processInput(window);
//
//		// 渲染指令.
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT); // 三个参数：Color, Depth, Stencil
//
//
//
//
//		///glUseProgram(shaderProgram);
//		mShader.use();
//
//		float timeValue = glfwGetTime();
//		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
//		float offset = sin(timeValue)*0.5f;
//		mShader.setFloat("offset", offset);
//
//		glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		///glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//
//
//		// 检查并调用事件，交换缓冲
//		glfwSwapBuffers(window);  // 交换颜色缓冲
//		glfwPollEvents(); // 检查是否有没有触发事件，更新窗口状态。
//	}
//
//	// optional: de-allocate all resources once they've outlived their purpose:
//	// ------------------------------------------------------------------------
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//
//	glfwTerminate();
//	return 0;
//}
//
//int p3_ShaderStart() {
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	// 设置的参数 https://www.glfw.org/docs/latest/window.html#window_hints
//	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); MacOs
//
//	GLFWwindow* window = glfwCreateWindow(1280, 1024, "WindyIce", NULL, NULL);
//	if (window == NULL) {
//		std::cout << "Failed to create GLFW window" << std::endl; // GLFW窗口创建失败
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	// GLAD用来管理OpenGL的函数指针，所以在调用OpenGL的函数之前我们需要初始化GLAD
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD" << std::endl; // GLAD初始化失败
//		return -1;
//	}
//
//	glViewport(0, 0, 1280, 1024);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	Shader mShader("p3vs.vs", "p3fs.fs");
//
//	// 顶点缓冲对象，管理顶点内存，储存大量顶点，使用该对象一次性发送一大批数据到显卡上，而不是每个顶点发送一次。
//	unsigned int VBO;
//	// 顶点数组对象，任何顶点属性调用都会存储在VAO中。配置顶点属性指针的时候，只需要将那些调用执行一次。
//	unsigned int VAO;
//	// 索引缓冲对象，用来索引绘制。
//	unsigned int EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attribute(s)
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO); // GL_ARRAY_BUFFER是顶点缓冲对象的缓冲类型
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);// 位置属性
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));// 颜色属性
//	glEnableVertexAttribArray(1);
//
//	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//	glBindVertexArray(0); // 解绑定的操作
//
//
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	while (!glfwWindowShouldClose(window)) {
//
//		// 输入
//		processInput(window);
//
//		// 渲染指令.
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT); // 三个参数：Color, Depth, Stencil
//
//
//
//
//		///glUseProgram(shaderProgram);
//		mShader.use();
//
//		float timeValue = glfwGetTime();
//		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
//		float offset = sin(timeValue)*0.5f;
//		mShader.setFloat("offset", offset);
//
//		glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		///glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//
//
//		// 检查并调用事件，交换缓冲
//		glfwSwapBuffers(window);  // 交换颜色缓冲
//		glfwPollEvents(); // 检查是否有没有触发事件，更新窗口状态。
//	}
//
//	// optional: de-allocate all resources once they've outlived their purpose:
//	// ------------------------------------------------------------------------
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//
//	glfwTerminate();
//	return 0;
//}
//
//void framebuffer_size_callback(GLFWwindow * window, int width, int height)
//{
//	// 同时改变视口的大小
//	glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow * window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
//		glfwSetWindowShouldClose(window, true);
//	}
//}