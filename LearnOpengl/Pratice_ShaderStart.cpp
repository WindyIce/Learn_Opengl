//#include<glad/glad.h> 
//// Ҫ�Ȱ���glad���ļ�����Ϊglad�ṩ��include<gl.h>֮��Ĳ���
//#include<GLFW/glfw3.h>
//
//#include"Shader.h"
//
//#include<iostream>
//
//// �û��ı䴰�ڴ�С�Ļص�����
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//
//// ����������룬��ⰴ���Ƿ񱻰���
//void processInput(GLFWwindow* window);
//
//int p1_ShaderStart();
//
//int p2_ShaderStart();
//
//int p3_ShaderStart();
//
//float vertices[] = {
//	// λ��              // ��ɫ
//	 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // ����
//	-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // ����
//	 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // ����
//};
//
//int p1_ShaderStart() {
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	// ���õĲ��� https://www.glfw.org/docs/latest/window.html#window_hints
//	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); MacOs
//
//	GLFWwindow* window = glfwCreateWindow(1280, 1024, "WindyIce", NULL, NULL);
//	if (window == NULL) {
//		std::cout << "Failed to create GLFW window" << std::endl; // GLFW���ڴ���ʧ��
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	// GLAD��������OpenGL�ĺ���ָ�룬�����ڵ���OpenGL�ĺ���֮ǰ������Ҫ��ʼ��GLAD
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD" << std::endl; // GLAD��ʼ��ʧ��
//		return -1;
//	}
//
//	glViewport(0, 0, 1280, 1024);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	Shader mShader("p1vs.vs", "p1fs.fs");
//
//	// ���㻺����󣬹������ڴ棬����������㣬ʹ�øö���һ���Է���һ�������ݵ��Կ��ϣ�������ÿ�����㷢��һ�Ρ�
//	unsigned int VBO;
//	// ������������κζ������Ե��ö���洢��VAO�С����ö�������ָ���ʱ��ֻ��Ҫ����Щ����ִ��һ�Ρ�
//	unsigned int VAO;
//	// ����������������������ơ�
//	unsigned int EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attribute(s)
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO); // GL_ARRAY_BUFFER�Ƕ��㻺�����Ļ�������
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);// λ������
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));// ��ɫ����
//	glEnableVertexAttribArray(1);
//
//	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//	glBindVertexArray(0); // ��󶨵Ĳ���
//
//
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	while (!glfwWindowShouldClose(window)) {
//
//		// ����
//		processInput(window);
//
//		// ��Ⱦָ��.
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT); // ����������Color, Depth, Stencil
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
//		// ��鲢�����¼�����������
//		glfwSwapBuffers(window);  // ������ɫ����
//		glfwPollEvents(); // ����Ƿ���û�д����¼������´���״̬��
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
//	// ���õĲ��� https://www.glfw.org/docs/latest/window.html#window_hints
//	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); MacOs
//
//	GLFWwindow* window = glfwCreateWindow(1280, 1024, "WindyIce", NULL, NULL);
//	if (window == NULL) {
//		std::cout << "Failed to create GLFW window" << std::endl; // GLFW���ڴ���ʧ��
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	// GLAD��������OpenGL�ĺ���ָ�룬�����ڵ���OpenGL�ĺ���֮ǰ������Ҫ��ʼ��GLAD
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD" << std::endl; // GLAD��ʼ��ʧ��
//		return -1;
//	}
//
//	glViewport(0, 0, 1280, 1024);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	Shader mShader("p2vs.vs", "p2fs.fs");
//
//	// ���㻺����󣬹������ڴ棬����������㣬ʹ�øö���һ���Է���һ�������ݵ��Կ��ϣ�������ÿ�����㷢��һ�Ρ�
//	unsigned int VBO;
//	// ������������κζ������Ե��ö���洢��VAO�С����ö�������ָ���ʱ��ֻ��Ҫ����Щ����ִ��һ�Ρ�
//	unsigned int VAO;
//	// ����������������������ơ�
//	unsigned int EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attribute(s)
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO); // GL_ARRAY_BUFFER�Ƕ��㻺�����Ļ�������
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);// λ������
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));// ��ɫ����
//	glEnableVertexAttribArray(1);
//
//	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//	glBindVertexArray(0); // ��󶨵Ĳ���
//
//
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	while (!glfwWindowShouldClose(window)) {
//
//		// ����
//		processInput(window);
//
//		// ��Ⱦָ��.
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT); // ����������Color, Depth, Stencil
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
//		// ��鲢�����¼�����������
//		glfwSwapBuffers(window);  // ������ɫ����
//		glfwPollEvents(); // ����Ƿ���û�д����¼������´���״̬��
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
//	// ���õĲ��� https://www.glfw.org/docs/latest/window.html#window_hints
//	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); MacOs
//
//	GLFWwindow* window = glfwCreateWindow(1280, 1024, "WindyIce", NULL, NULL);
//	if (window == NULL) {
//		std::cout << "Failed to create GLFW window" << std::endl; // GLFW���ڴ���ʧ��
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	// GLAD��������OpenGL�ĺ���ָ�룬�����ڵ���OpenGL�ĺ���֮ǰ������Ҫ��ʼ��GLAD
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD" << std::endl; // GLAD��ʼ��ʧ��
//		return -1;
//	}
//
//	glViewport(0, 0, 1280, 1024);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	Shader mShader("p3vs.vs", "p3fs.fs");
//
//	// ���㻺����󣬹������ڴ棬����������㣬ʹ�øö���һ���Է���һ�������ݵ��Կ��ϣ�������ÿ�����㷢��һ�Ρ�
//	unsigned int VBO;
//	// ������������κζ������Ե��ö���洢��VAO�С����ö�������ָ���ʱ��ֻ��Ҫ����Щ����ִ��һ�Ρ�
//	unsigned int VAO;
//	// ����������������������ơ�
//	unsigned int EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attribute(s)
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO); // GL_ARRAY_BUFFER�Ƕ��㻺�����Ļ�������
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);// λ������
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));// ��ɫ����
//	glEnableVertexAttribArray(1);
//
//	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//	glBindVertexArray(0); // ��󶨵Ĳ���
//
//
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	while (!glfwWindowShouldClose(window)) {
//
//		// ����
//		processInput(window);
//
//		// ��Ⱦָ��.
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT); // ����������Color, Depth, Stencil
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
//		// ��鲢�����¼�����������
//		glfwSwapBuffers(window);  // ������ɫ����
//		glfwPollEvents(); // ����Ƿ���û�д����¼������´���״̬��
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
//	// ͬʱ�ı��ӿڵĴ�С
//	glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow * window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
//		glfwSetWindowShouldClose(window, true);
//	}
//}