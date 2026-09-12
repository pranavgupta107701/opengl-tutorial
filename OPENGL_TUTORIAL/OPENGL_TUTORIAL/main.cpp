#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"Texture.h"
#include"Camera.h"

/*/GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f, // front left 
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f, // back left
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f, // back right
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f, // front right
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	2.5f, 5.0f  // top
};

// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 1, 4,
	1, 2, 4,
	2, 3, 4,
	3, 0, 4
};

GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord    /   Normals          //
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, -1.0f,  0.0f, // front left	Bottom
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,		0.0f, -1.0f,  0.0f, // back  left	face	
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, -1.0f,  0.0f, // back  right
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,		0.0f, -1.0f,  0.0f, // front right

	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,		0.0f, 0.5f, 0.8f, // front right	Front
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.5f, 0.8f, // front left		Face
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	2.5f, 5.0f,		0.0f, 0.5f, 0.8f, // top

	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,		0.0f, 0.5f, -0.8f,  // back  left	Back
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.5f, -0.8f,  // back  right	Face
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	2.5f, 5.0f,		0.0f, 0.5f, -0.8f,  // top

	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.8f, 0.5f,  0.0f,  // back  right	Right
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,		0.8f, 0.5f,  0.0f,  // front right	Face
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	2.5f, 5.0f,		0.8f, 0.5f,  0.0f,  // top

	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		-0.8f, 0.5f, 0.0f,   // front left	Left
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,		-0.8f, 0.5f, 0.0f,   // back  left	Face
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	2.5f, 5.0f,		-0.8f, 0.5f, 0.0f,   // top
};

GLuint indices[] =
{
	0, 1, 3,
	1, 2, 3,
	4, 5, 6,
	7, 8, 9,
	10, 11, 12,
	13, 14, 15
};*/

GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord    /   Normals          //
	 -0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 1.0f,  0.0f, // front left	Bottom
	 -0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,		0.0f, 1.0f,  0.0f, // back  left	face	
	 0.5f,  0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,		0.0f, 1.0f,  0.0f, // back  right
	 0.5f,  0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,		0.0f, 1.0f,  0.0f  // front right
};

GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3,
};
GLfloat lightVertices[] =
{
	//     COORDINATES    
	 0.1f,  0.1f,  0.1f,    // front top    right 0
	 0.1f, -0.1f,  0.1f,    // front bottom right 1
	 0.1f,  0.1f, -0.1f,    // front top    left  2
	 0.1f, -0.1f, -0.1f,    // front bottom left  3
	-0.1f,  0.1f,  0.1f,    // back  top    right 4
	-0.1f, -0.1f,  0.1f,    // back  bottom right 5
	-0.1f,  0.1f, -0.1f,    // back  top    left  6
	-0.1f, -0.1f, -0.1f,    // back  bottom left  7
};

GLuint lightIndices[] = {
	0, 1, 2,
	1, 2, 3,
	4, 5, 6,
	5, 6, 7,
	0, 4, 2,
	4, 2, 6,
	1, 5, 3,
	5, 3, 7,
	0, 1, 4,
	1, 4, 5,
	2, 3, 6,
	3, 6, 7
};


const int width = 800;
const int height = 800;

int main()
{
	//initialize glfw
	glfwInit();

	//tell glfw version and profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	//initialize window, check if window is there, make the current context window
	GLFWwindow* window = glfwCreateWindow(width, height, "wazzaaaa", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//load glad
	gladLoadGL();

	//specify the viewport of opengl in the window
	glViewport(0, 0, 800, 800);

	Shader shaderProgram("default.vert", "default.frag");
	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	// Shader for light cube
	Shader lightShader("light.vert", "light.frag");
	VAO lightVAO;
	lightVAO.Bind();

	VBO lightVBO(lightVertices, sizeof(lightVertices));
	EBO lightEBO(lightIndices, sizeof(lightIndices));

	lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
	lightVAO.Unbind();
	lightVBO.Unbind();
	lightEBO.Unbind();

	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.0f, 0.5f, 0.0f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	glm::vec3 pyramidPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 pyramidModel = glm::mat4(1.0f);
	pyramidModel = glm::translate(pyramidModel, pyramidPos);


	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	shaderProgram.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	//texture

	Texture coolCat("planks.png", GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE);
	coolCat.texUnit(shaderProgram, "tex0", 0);
	Texture coolCatSpec("planksSpec.png", GL_TEXTURE_2D, 1, GL_RED, GL_UNSIGNED_BYTE);
	coolCatSpec.texUnit(shaderProgram, "tex1", 1);

	glEnable(GL_DEPTH_TEST);

	Camera camera(width, height, glm::vec3(0.0f, 1.0f, 2.0f));

	double prevTime = glfwGetTime();
	//keep window open until its gonna close
	while (!glfwWindowShouldClose(window))
	{
		//draw triangle
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		double crntTime = glfwGetTime();
		double deltaTime = crntTime - prevTime;
		prevTime = crntTime;
		shaderProgram.Activate();


		// Handles camera inputs
		camera.Inputs(window, deltaTime);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);



		shaderProgram.Activate();
		glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.position.x, camera.position.y, camera.position.z);
		camera.Matrix(shaderProgram, "camMatrix");
		coolCat.Bind();
		coolCatSpec.Bind();
		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
		VAO1.Unbind();



		lightShader.Activate();
		camera.Matrix(lightShader, "camMatrix");
		lightVAO.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);
		lightVAO.Unbind();

		/*// Tells OpenGL which Shader Program we want to use
		lightShader.Activate();
		// Export the camMatrix to the Vertex Shader of the light cube
		camera.Matrix(lightShader, "camMatrix");
		// Bind the VAO so OpenGL knows to use it
		lightVAO.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);*/


		glfwSwapBuffers(window);

		//check for events
		glfwPollEvents();
	}
	
	// delete vao vbo and shader program
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	coolCat.Delete();
	coolCatSpec.Delete();
	shaderProgram.Delete();
	lightVAO.Delete();
	lightVBO.Delete();
	lightEBO.Delete();
	lightShader.Delete();
	
	//terminate
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}