//
//
//#include<glad/glad.h> 
//// 要先包含glad的文件，因为glad提供了include<gl.h>之类的操作
//#include<GLFW/glfw3.h>
//
//#include<iostream>
//
//// 用户改变窗口大小的回调函数
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//
//// 处理键盘输入，检测按键是否被按下
//void processInput(GLFWwindow* window);
//
//int p1_HelloTriangle();
//int p2_HelloTriangle();
//int p3_HelloTriangle();
//
//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";
//
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\n\0";
//
//const char* fragmentShaderSource1 = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 1.0f, 0.5f, 1.0f);\n"
//"}\n\0";
//
//
//int p1_HelloTriangle() {
//	float vertices1[] = {
//	0.0f,0.5f,0.0f,
//	-0.5f,0.0f,0.0f,
//	0.0f,0.0f,0.0f,
//	0.0f,-0.5f,0.0f,
//	0.5f,0.0f,0.0f
//	};
//
//	unsigned int indices1[] = {
//		0,1,2,
//		2,3,4
//	};
//
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
//	// 创建顶点着色器
//	unsigned int vertexShader;
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // 第二个参数是传递的字符串数量
//	glCompileShader(vertexShader);
//
//	// 创建片段着色器
//	unsigned int fragmentShader;
//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//
//	int success;
//	char infoLog[512];
//	// 获取shader编译的成功与否的信息
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "GL:COMPILE_ERROR顶点着色器编译错误\n" << infoLog << std::endl;
//	}
//
//	// 着色器程序对象
//	unsigned int shaderProgram;
//	shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//	// 检查链接着色器是否成功
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//		std::cout << "GL::LINK_ERROR着色器程序链接失败\n" << std::endl;
//	}
//	// 把着色器对象链接到程序对象之后，就可以删除着色器对象了
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
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
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
//	// 指明索引缓冲渲染
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices1), indices1, GL_STATIC_DRAW);
//	/*GL_STATIC_DRAW ：数据不会或几乎不会改变。
//GL_DYNAMIC_DRAW：数据会被改变很多。
//GL_STREAM_DRAW ：数据每次绘制时都会改变。*/
//
//// 1.设置顶点属性指针(第0步相当与上面的复制顶点数组缓冲供OpenGL: GLBindBuffer)
///*
//第一个参数指定我们要配置的顶点属性。我们在顶点着色器中使用layout(location = 0)定义了position顶点属性的位置值(Location)吗？它可以把顶点属性的位置值设置为0。因为我们希望把数据传递到这一个顶点属性中，所以这里我们传入0。
//第二个参数指定顶点属性的大小。顶点属性是一个vec3，它由3个值组成，所以大小是3。
//第三个参数指定数据的类型，这里是GL_FLOAT(GLSL中vec*都是由浮点数值组成的)。
//第四个参数定义我们是否希望数据被标准化(Normalize)。如果我们设置为GL_TRUE，所有数据都会被映射到0（对于有符号型signed数据是-1）到1之间。我们把它设置为GL_FALSE。
//第五个参数叫做步长(Stride)，它告诉我们在连续的顶点属性组之间的间隔。由于下个组位置数据在3个float之后，我们把步长设置为3 * sizeof(float)。要注意的是由于我们知道这个数组是紧密排列的（在两个顶点属性之间没有空隙）我们也可以设置为0来让OpenGL决定具体步长是多少（只有当数值是紧密排列时才可用）。一旦我们有更多的顶点属性，我们就必须更小心地定义每个顶点属性之间的间隔，我们在后面会看到更多的例子（译注: 这个参数的意思简单说就是从这个属性第二次出现的地方到整个数组0位置之间有多少字节）。
//最后一个参数的类型是void*，所以需要我们进行这个奇怪的强制类型转换。它表示位置数据在缓冲中起始位置的偏移量(Offset)。由于位置数据在数组的开头，所以这里是0。我们会在后面详细解释这个参数。
//*/
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//	glBindVertexArray(0); // 解绑定的操作
//
//	glUseProgram(shaderProgram);
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
//		glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//		//glDrawArrays(GL_TRIANGLES, 0, 3);
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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
//int p2_HelloTriangle() {
//	float firstTriangle[] = {
//			-0.9f, -0.5f, 0.0f,  // left 
//			-0.0f, -0.5f, 0.0f,  // right
//			-0.45f, 0.5f, 0.0f,  // top 
//	};
//	float secondTriangle[] = {
//		0.0f, -0.5f, 0.0f,  // left
//		0.9f, -0.5f, 0.0f,  // right
//		0.45f, 0.5f, 0.0f   // top 
//	};
//
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
//	// 创建顶点着色器
//	unsigned int vertexShader;
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // 第二个参数是传递的字符串数量
//	glCompileShader(vertexShader);
//
//	// 创建片段着色器
//	unsigned int fragmentShader;
//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//
//	int success;
//	char infoLog[512];
//	// 获取shader编译的成功与否的信息
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "GL:COMPILE_ERROR顶点着色器编译错误\n" << infoLog << std::endl;
//	}
//
//	// 着色器程序对象
//	unsigned int shaderProgram;
//	shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//	// 检查链接着色器是否成功
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//		std::cout << "GL::LINK_ERROR着色器程序链接失败\n" << std::endl;
//	}
//	// 把着色器对象链接到程序对象之后，就可以删除着色器对象了
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	// 顶点缓冲对象，管理顶点内存，储存大量顶点，使用该对象一次性发送一大批数据到显卡上，而不是每个顶点发送一次。
//	unsigned int VBOs[2];
//	// 顶点数组对象，任何顶点属性调用都会存储在VAO中。配置顶点属性指针的时候，只需要将那些调用执行一次。
//	unsigned int VAOs[2];
//	glGenVertexArrays(2, VAOs);
//	glGenBuffers(2, VBOs);
//	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attribute(s)
//	glBindVertexArray(VAOs[0]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]); // GL_ARRAY_BUFFER是顶点缓冲对象的缓冲类型
//	glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glBindVertexArray(VAOs[1]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//	glEnableVertexAttribArray(0);
//
//	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//	glBindVertexArray(0); // 解绑定的操作
//
//	glUseProgram(shaderProgram);
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	while (!glfwWindowShouldClose(window)) {
//
//		// 输入
//		processInput(window);
//
//		// 渲染指令.
//
//		glClearColor(19.0f / 255.0f, 176.0f / 255.0f, 193.0f / 255.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT); // 三个参数：Color, Depth, Stencil
//
//		glBindVertexArray(VAOs[0]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		glBindVertexArray(VAOs[1]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//
//		// 检查并调用事件，交换缓冲
//		glfwSwapBuffers(window);  // 交换颜色缓冲
//		glfwPollEvents(); // 检查是否有没有触发事件，更新窗口状态。
//	}
//
//	// optional: de-allocate all resources once they've outlived their purpose:
//	// ------------------------------------------------------------------------
//	glDeleteVertexArrays(2, VAOs);
//	glDeleteBuffers(2, VBOs);
//
//	glfwTerminate();
//	return 0;
//}
//
//int p3_HelloTriangle() {
//	float firstTriangle[] = {
//			-0.9f, -0.5f, 0.0f,  // left 
//			-0.0f, -0.5f, 0.0f,  // right
//			-0.45f, 0.5f, 0.0f,  // top 
//	};
//	float secondTriangle[] = {
//		0.0f, -0.5f, 0.0f,  // left
//		0.9f, -0.5f, 0.0f,  // right
//		0.45f, 0.5f, 0.0f   // top 
//	};
//
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
//	// 创建顶点着色器
//	unsigned int vertexShader;
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // 第二个参数是传递的字符串数量
//	glCompileShader(vertexShader);
//
//	// 创建片段着色器
//	unsigned int fragmentShader;
//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//
//	unsigned int fragmentShader1;
//	fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader1, 1, &fragmentShaderSource1, NULL);
//	glCompileShader(fragmentShader1);
//
//	int success;
//	char infoLog[512];
//	// 获取shader编译的成功与否的信息
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "GL:COMPILE_ERROR顶点着色器编译错误\n" << infoLog << std::endl;
//	}
//
//	// 着色器程序对象
//	unsigned int shaderProgram;
//	shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//	// 检查链接着色器是否成功
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//		std::cout << "GL::LINK_ERROR着色器程序链接失败\n" << std::endl;
//	}
//
//	
//
//	unsigned int shaderProgram1;
//	shaderProgram1 = glCreateProgram();
//	glAttachShader(shaderProgram1, vertexShader);
//	glAttachShader(shaderProgram1, fragmentShader1);
//	glLinkProgram(shaderProgram1);
//	glGetProgramiv(shaderProgram1, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgram1, 512, NULL, infoLog);
//		std::cout << "GL::LINK_ERROR着色器程序链接失败\n" << std::endl;
//	}
//	// 把着色器对象链接到程序对象之后，就可以删除着色器对象了
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//	glDeleteShader(fragmentShader1);
//	// 顶点缓冲对象，管理顶点内存，储存大量顶点，使用该对象一次性发送一大批数据到显卡上，而不是每个顶点发送一次。
//	unsigned int VBOs[2];
//	// 顶点数组对象，任何顶点属性调用都会存储在VAO中。配置顶点属性指针的时候，只需要将那些调用执行一次。
//	unsigned int VAOs[2];
//	glGenVertexArrays(2, VAOs);
//	glGenBuffers(2, VBOs);
//	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attribute(s)
//	glBindVertexArray(VAOs[0]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]); // GL_ARRAY_BUFFER是顶点缓冲对象的缓冲类型
//	glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glBindVertexArray(VAOs[1]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//	glEnableVertexAttribArray(0);
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
//		glClearColor(19.0f / 255.0f, 176.0f / 255.0f, 193.0f / 255.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT); // 三个参数：Color, Depth, Stencil
//
//		glUseProgram(shaderProgram);
//		glBindVertexArray(VAOs[0]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//
//		glUseProgram(shaderProgram1);
//		glBindVertexArray(VAOs[1]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//
//		// 检查并调用事件，交换缓冲
//		glfwSwapBuffers(window);  // 交换颜色缓冲
//		glfwPollEvents(); // 检查是否有没有触发事件，更新窗口状态。
//	}
//
//	// optional: de-allocate all resources once they've outlived their purpose:
//	// ------------------------------------------------------------------------
//	glDeleteVertexArrays(2, VAOs);
//	glDeleteBuffers(2, VBOs);
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