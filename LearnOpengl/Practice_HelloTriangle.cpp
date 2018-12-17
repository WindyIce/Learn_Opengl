#include<glad/glad.h> 
// Ҫ�Ȱ���glad���ļ�����Ϊglad�ṩ��include<gl.h>֮��Ĳ���
#include<GLFW/glfw3.h>

#include<iostream>

// �û��ı䴰�ڴ�С�Ļص�����
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// ����������룬��ⰴ���Ƿ񱻰���
void processInput(GLFWwindow* window);

int p1_HelloTriangle();
int p2_HelloTriangle();
int p3_HelloTriangle();

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

const char* fragmentShaderSource1 = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 1.0f, 0.5f, 1.0f);\n"
"}\n\0";


int p1_HelloTriangle() {
	float vertices1[] = {
	0.0f,0.5f,0.0f,
	-0.5f,0.0f,0.0f,
	0.0f,0.0f,0.0f,
	0.0f,-0.5f,0.0f,
	0.5f,0.0f,0.0f
	};

	unsigned int indices1[] = {
		0,1,2,
		2,3,4
	};

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

	// ����������ɫ��
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // �ڶ��������Ǵ��ݵ��ַ�������
	glCompileShader(vertexShader);

	// ����Ƭ����ɫ��
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	int success;
	char infoLog[512];
	// ��ȡshader����ĳɹ�������Ϣ
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "GL:COMPILE_ERROR������ɫ���������\n" << infoLog << std::endl;
	}

	// ��ɫ���������
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// ���������ɫ���Ƿ�ɹ�
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "GL::LINK_ERROR��ɫ����������ʧ��\n" << std::endl;
	}
	// ����ɫ���������ӵ��������֮�󣬾Ϳ���ɾ����ɫ��������
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// ���㻺����󣬹������ڴ棬����������㣬ʹ�øö���һ���Է���һ�������ݵ��Կ��ϣ�������ÿ�����㷢��һ�Ρ�
	unsigned int VBO;
	// ������������κζ������Ե��ö���洢��VAO�С����ö�������ָ���ʱ��ֻ��Ҫ����Щ����ִ��һ�Ρ�
	unsigned int VAO;
	// ����������������������ơ�
	unsigned int EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attribute(s)
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // GL_ARRAY_BUFFER�Ƕ��㻺�����Ļ�������
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
	// ָ������������Ⱦ
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices1), indices1, GL_STATIC_DRAW);
	/*GL_STATIC_DRAW �����ݲ���򼸺�����ı䡣
GL_DYNAMIC_DRAW�����ݻᱻ�ı�ܶࡣ
GL_STREAM_DRAW ������ÿ�λ���ʱ����ı䡣*/

// 1.���ö�������ָ��(��0���൱������ĸ��ƶ������黺�幩OpenGL: GLBindBuffer)
/*
��һ������ָ������Ҫ���õĶ������ԡ������ڶ�����ɫ����ʹ��layout(location = 0)������position�������Ե�λ��ֵ(Location)�������԰Ѷ������Ե�λ��ֵ����Ϊ0����Ϊ����ϣ�������ݴ��ݵ���һ�����������У������������Ǵ���0��
�ڶ�������ָ���������ԵĴ�С������������һ��vec3������3��ֵ��ɣ����Դ�С��3��
����������ָ�����ݵ����ͣ�������GL_FLOAT(GLSL��vec*�����ɸ�����ֵ��ɵ�)��
���ĸ��������������Ƿ�ϣ�����ݱ���׼��(Normalize)�������������ΪGL_TRUE���������ݶ��ᱻӳ�䵽0�������з�����signed������-1����1֮�䡣���ǰ�������ΪGL_FALSE��
�����������������(Stride)�������������������Ķ���������֮��ļ���������¸���λ��������3��float֮�����ǰѲ�������Ϊ3 * sizeof(float)��Ҫע�������������֪����������ǽ������еģ���������������֮��û�п�϶������Ҳ��������Ϊ0����OpenGL�������岽���Ƕ��٣�ֻ�е���ֵ�ǽ�������ʱ�ſ��ã���һ�������и���Ķ������ԣ����Ǿͱ����С�ĵض���ÿ����������֮��ļ���������ں���ῴ����������ӣ���ע: �����������˼��˵���Ǵ�������Եڶ��γ��ֵĵط�����������0λ��֮���ж����ֽڣ���
���һ��������������void*��������Ҫ���ǽ��������ֵ�ǿ������ת��������ʾλ�������ڻ�������ʼλ�õ�ƫ����(Offset)������λ������������Ŀ�ͷ������������0�����ǻ��ں�����ϸ�������������
*/
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0); // ��󶨵Ĳ���

	glUseProgram(shaderProgram);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!glfwWindowShouldClose(window)) {

		// ����
		processInput(window);

		// ��Ⱦָ��.

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT); // ����������Color, Depth, Stencil

		glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);



		// ��鲢�����¼�����������
		glfwSwapBuffers(window);  // ������ɫ����
		glfwPollEvents(); // ����Ƿ���û�д����¼������´���״̬��
	}

	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glfwTerminate();
	return 0;
}

int p2_HelloTriangle() {
	float firstTriangle[] = {
			-0.9f, -0.5f, 0.0f,  // left 
			-0.0f, -0.5f, 0.0f,  // right
			-0.45f, 0.5f, 0.0f,  // top 
	};
	float secondTriangle[] = {
		0.0f, -0.5f, 0.0f,  // left
		0.9f, -0.5f, 0.0f,  // right
		0.45f, 0.5f, 0.0f   // top 
	};

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

	// ����������ɫ��
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // �ڶ��������Ǵ��ݵ��ַ�������
	glCompileShader(vertexShader);

	// ����Ƭ����ɫ��
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	int success;
	char infoLog[512];
	// ��ȡshader����ĳɹ�������Ϣ
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "GL:COMPILE_ERROR������ɫ���������\n" << infoLog << std::endl;
	}

	// ��ɫ���������
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// ���������ɫ���Ƿ�ɹ�
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "GL::LINK_ERROR��ɫ����������ʧ��\n" << std::endl;
	}
	// ����ɫ���������ӵ��������֮�󣬾Ϳ���ɾ����ɫ��������
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// ���㻺����󣬹������ڴ棬����������㣬ʹ�øö���һ���Է���һ�������ݵ��Կ��ϣ�������ÿ�����㷢��һ�Ρ�
	unsigned int VBOs[2];
	// ������������κζ������Ե��ö���洢��VAO�С����ö�������ָ���ʱ��ֻ��Ҫ����Щ����ִ��һ�Ρ�
	unsigned int VAOs[2];
	glGenVertexArrays(2, VAOs);
	glGenBuffers(2, VBOs);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attribute(s)
	glBindVertexArray(VAOs[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]); // GL_ARRAY_BUFFER�Ƕ��㻺�����Ļ�������
	glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(VAOs[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0); // ��󶨵Ĳ���

	glUseProgram(shaderProgram);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!glfwWindowShouldClose(window)) {

		// ����
		processInput(window);

		// ��Ⱦָ��.

		glClearColor(19.0f / 255.0f, 176.0f / 255.0f, 193.0f / 255.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT); // ����������Color, Depth, Stencil

		glBindVertexArray(VAOs[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindVertexArray(VAOs[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);


		// ��鲢�����¼�����������
		glfwSwapBuffers(window);  // ������ɫ����
		glfwPollEvents(); // ����Ƿ���û�д����¼������´���״̬��
	}

	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	glDeleteVertexArrays(2, VAOs);
	glDeleteBuffers(2, VBOs);

	glfwTerminate();
	return 0;
}

int p3_HelloTriangle() {
	float firstTriangle[] = {
			-0.9f, -0.5f, 0.0f,  // left 
			-0.0f, -0.5f, 0.0f,  // right
			-0.45f, 0.5f, 0.0f,  // top 
	};
	float secondTriangle[] = {
		0.0f, -0.5f, 0.0f,  // left
		0.9f, -0.5f, 0.0f,  // right
		0.45f, 0.5f, 0.0f   // top 
	};

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

	// ����������ɫ��
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // �ڶ��������Ǵ��ݵ��ַ�������
	glCompileShader(vertexShader);

	// ����Ƭ����ɫ��
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	unsigned int fragmentShader1;
	fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader1, 1, &fragmentShaderSource1, NULL);
	glCompileShader(fragmentShader1);

	int success;
	char infoLog[512];
	// ��ȡshader����ĳɹ�������Ϣ
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "GL:COMPILE_ERROR������ɫ���������\n" << infoLog << std::endl;
	}

	// ��ɫ���������
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// ���������ɫ���Ƿ�ɹ�
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "GL::LINK_ERROR��ɫ����������ʧ��\n" << std::endl;
	}

	

	unsigned int shaderProgram1;
	shaderProgram1 = glCreateProgram();
	glAttachShader(shaderProgram1, vertexShader);
	glAttachShader(shaderProgram1, fragmentShader1);
	glLinkProgram(shaderProgram1);
	glGetProgramiv(shaderProgram1, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram1, 512, NULL, infoLog);
		std::cout << "GL::LINK_ERROR��ɫ����������ʧ��\n" << std::endl;
	}
	// ����ɫ���������ӵ��������֮�󣬾Ϳ���ɾ����ɫ��������
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glDeleteShader(fragmentShader1);
	// ���㻺����󣬹������ڴ棬����������㣬ʹ�øö���һ���Է���һ�������ݵ��Կ��ϣ�������ÿ�����㷢��һ�Ρ�
	unsigned int VBOs[2];
	// ������������κζ������Ե��ö���洢��VAO�С����ö�������ָ���ʱ��ֻ��Ҫ����Щ����ִ��һ�Ρ�
	unsigned int VAOs[2];
	glGenVertexArrays(2, VAOs);
	glGenBuffers(2, VBOs);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attribute(s)
	glBindVertexArray(VAOs[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]); // GL_ARRAY_BUFFER�Ƕ��㻺�����Ļ�������
	glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(VAOs[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0); // ��󶨵Ĳ���

	
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!glfwWindowShouldClose(window)) {

		// ����
		processInput(window);

		// ��Ⱦָ��.

		glClearColor(19.0f / 255.0f, 176.0f / 255.0f, 193.0f / 255.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT); // ����������Color, Depth, Stencil

		glUseProgram(shaderProgram);
		glBindVertexArray(VAOs[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);


		glUseProgram(shaderProgram1);
		glBindVertexArray(VAOs[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);


		// ��鲢�����¼�����������
		glfwSwapBuffers(window);  // ������ɫ����
		glfwPollEvents(); // ����Ƿ���û�д����¼������´���״̬��
	}

	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	glDeleteVertexArrays(2, VAOs);
	glDeleteBuffers(2, VBOs);

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