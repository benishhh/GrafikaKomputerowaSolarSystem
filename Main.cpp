#include "Sphere.h"

const unsigned int width = 800;
const unsigned int height = 800;

// Kod zamnkniêty w takie plusy jest jeszcze z kursu, ale go nie wywala³em
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Vertices coordinates
Vertex vertices[] = { //               COORDINATES           /            COLORS          /           NORMALS         /       TEXTURE COORDINATES    //
	Vertex{ glm::vec3(-1.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f) },
	Vertex{ glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f) },
	Vertex{ glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f) },
	Vertex{ glm::vec3(1.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f) }
};

// Indices for vertices order
GLuint indices[] = {
	0, 1, 2,
	0, 2, 3
};

Vertex lightVertices[] = { //     COORDINATES     //
	Vertex{ glm::vec3(-0.1f, -0.1f, 0.1f) },
	Vertex{ glm::vec3(-0.1f, -0.1f, -0.1f) },
	Vertex{ glm::vec3(0.1f, -0.1f, -0.1f) },
	Vertex{ glm::vec3(0.1f, -0.1f, 0.1f) },
	Vertex{ glm::vec3(-0.1f, 0.1f, 0.1f) },
	Vertex{ glm::vec3(-0.1f, 0.1f, -0.1f) },
	Vertex{ glm::vec3(0.1f, 0.1f, -0.1f) },
	Vertex{ glm::vec3(0.1f, 0.1f, 0.1f) }
};

GLuint lightIndices[] = {
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


int main() {
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(width, height, "YoutubeOpenGL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);

	// Texture data
	Texture textures[]{
		Texture("diffuse.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("normal.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	Texture texturesPlanks[]{
		Texture("brick.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("brick.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	Texture texturesSun[]{
		Texture("diffuse.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("normal.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	Texture texturesMerkury[]{
		Texture("pop_cat.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("pop_cat.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};

	Texture texturesWenus[]{
		Texture("pop_cat.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("pop_cat.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	Texture texturesZiemia[]{
		Texture("pop_cat.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("pop_cat.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	Texture texturesMars[]{
		Texture("pop_cat.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("pop_cat.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	Texture texturesJowisz[]{
		Texture("pop_cat.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("pop_cat.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	Texture texturesSaturn[]{
		Texture("pop_cat.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("pop_cat.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	Texture texturesUran[]{
		Texture("pop_cat.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("pop_cat.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};
	Texture texturesNeptun[]{
		Texture("pop_cat.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("pop_cat.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};

	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");
	// Store mesh data in vectors for the mesh
	std::vector<Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	std::vector<GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
	std::vector<Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));
	// Create floor mesh
	Mesh floor(verts, ind, tex);

	// Shader for light cube
	Shader lightShader("light.vert", "light.frag");
	// Store mesh data in vectors for the mesh
	std::vector<Vertex> lightVerts(lightVertices, lightVertices + sizeof(lightVertices) / sizeof(Vertex));
	std::vector<GLuint> lightInd(lightIndices, lightIndices + sizeof(lightIndices) / sizeof(GLuint));
	// Crate light mesh
	Mesh light(lightVerts, lightInd, tex);

	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	glm::vec3 objectPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 objectModel = glm::mat4(1.0f);
	objectModel = glm::translate(objectModel, objectPos);
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	// =============================== PLANETKI====================================
	float wielkosc = 0.0001f; // 10 000km 
	float odleg³oœæ = 0.1871f; // wartoœæ w mln km razy ta zmienna daje fajne proporcje odleg³osci

	// SUN
	Shader sunShader("default.vert", "default.frag");
	std::vector<Vertex> sunVertices = GenerateSphereVertices(69634*wielkosc, 50, 50); // 6.69 to œrednica
	std::vector<GLuint> sunIndices = GenerateSphereIndices(50, 50);
	std::vector<Texture> textSun(texturesSun, texturesSun + sizeof(texturesSun) / sizeof(Texture));
	Mesh sun(sunVertices, sunIndices, textSun);
	glm::vec3 sunPos = glm::vec3(0.0f, 0.0f, 0.0f); // gdzie siê znajduje na scenie
	glm::mat4 sunModel = glm::mat4(1.0f);
	sunModel = glm::translate(sunModel, sunPos);

	// MERKURY
	Shader merkuryShader("default.vert", "default.frag");
	std::vector<Vertex> merkuryVertices = GenerateSphereVertices(0.4878, 50, 50);
	std::vector<GLuint> merkuryIndices = GenerateSphereIndices(50, 50);
	std::vector<Texture> texMerkury(texturesPlanks, texturesPlanks + sizeof(texturesPlanks) / sizeof(Texture));
	Mesh merkury(merkuryVertices, merkuryIndices, texMerkury);
	glm::vec3 merkuryPos = glm::vec3(57.4 * odleg³oœæ, 0.0f, 0.0f); // gdzie siê znajduje na scenie
	glm::mat4 merkuryModel = glm::mat4(1.0f);
	merkuryModel = glm::translate(merkuryModel, merkuryPos);

	// WENUS
	Shader wenusShader("default.vert", "default.frag");
	std::vector<Vertex> wenusVertices = GenerateSphereVertices(12104.0 * wielkosc, 50, 50);
	std::vector<GLuint> wenusIndices = GenerateSphereIndices(50, 50);
	std::vector<Texture> textWenus(texturesWenus, texturesWenus + sizeof(texturesWenus) / sizeof(Texture));
	Mesh wenus(wenusVertices, wenusIndices, textWenus);
	glm::vec3 wenusPos = glm::vec3(108.141 * odleg³oœæ, 0.0f, 0.0f); // gdzie siê znajduje na scenie
	glm::mat4 wenusModel = glm::mat4(1.0f);
	wenusModel = glm::translate(wenusModel, wenusPos);

	// Ziemia
	Shader ziemiaShader("default.vert", "default.frag");
	std::vector<Vertex> ziemiaVertices = GenerateSphereVertices(12756.0 * wielkosc, 50, 50);
	std::vector<GLuint> ziemiaIndices = GenerateSphereIndices(50, 50);
	std::vector<Texture> textZiemia(texturesZiemia, texturesZiemia + sizeof(texturesZiemia) / sizeof(Texture));
	Mesh ziemia(ziemiaVertices, ziemiaIndices, textZiemia);
	glm::vec3 ziemiaPos = glm::vec3(149.5 * odleg³oœæ, 0.0f, 0.0f); // gdzie siê znajduje na scenie
	glm::mat4 ziemiaModel = glm::mat4(1.0f);
	ziemiaModel = glm::translate(ziemiaModel, ziemiaPos);

	// Mars
	Shader marsShader("default.vert", "default.frag");
	std::vector<Vertex> marsVertices = GenerateSphereVertices(6860.0 * wielkosc, 50, 50);
	std::vector<GLuint> marsIndices = GenerateSphereIndices(50, 50);
	std::vector<Texture> textMars(texturesMars, texturesMars + sizeof(texturesMars) / sizeof(Texture));
	Mesh mars(marsVertices, marsIndices, textMars);
	glm::vec3 marsPos = glm::vec3(227.789 * odleg³oœæ, 0.0f, 0.0f); // gdzie siê znajduje na scenie
	glm::mat4 marsModel = glm::mat4(1.0f);
	marsModel = glm::translate(marsModel, marsPos);

	// jowisz
	Shader jowiszShader("default.vert", "default.frag");
	std::vector<Vertex> jowiszVertices = GenerateSphereVertices(143640.0 / 2 * wielkosc, 50, 50);
	std::vector<GLuint> jowiszIndices = GenerateSphereIndices(50, 50);
	std::vector<Texture> textJowisz(texturesJowisz, texturesJowisz + sizeof(texturesJowisz) / sizeof(Texture));
	Mesh jowisz(jowiszVertices, jowiszIndices, textJowisz);
	glm::vec3 jowiszPos = glm::vec3(777.840 /2  * odleg³oœæ, 0.0f, 0.0f); // gdzie siê znajduje na scenie
	glm::mat4 jowiszModel = glm::mat4(1.0f);
	jowiszModel = glm::translate(jowiszModel, jowiszPos);

	// saturn
	Shader saturnShader("default.vert", "default.frag");
	std::vector<Vertex> saturnVertices = GenerateSphereVertices(120570.0 / 2 * wielkosc, 50, 50);
	std::vector<GLuint> saturnIndices = GenerateSphereIndices(50, 50);
	std::vector<Texture> textSaturn(texturesSaturn, texturesSaturn + sizeof(texturesSaturn) / sizeof(Texture));
	Mesh saturn(saturnVertices, saturnIndices, textSaturn);
	glm::vec3 saturnPos = glm::vec3(1426.100 / 2 * odleg³oœæ, 0.0f, 0.0f); // gdzie siê znajduje na scenie
	glm::mat4 saturnModel = glm::mat4(1.0f);
	saturnModel = glm::translate(saturnModel, saturnPos);

	// neptun
	Shader neptunShader("default.vert", "default.frag");
	std::vector<Vertex> neptunVertices = GenerateSphereVertices(57070 * wielkosc, 50, 50);
	std::vector<GLuint> neptunIndices = GenerateSphereIndices(50, 50);
	std::vector<Texture> textNeptun(texturesNeptun, texturesNeptun + sizeof(texturesNeptun) / sizeof(Texture));
	Mesh neptun(neptunVertices, neptunIndices, textNeptun);
	glm::vec3 neptunPos = glm::vec3(2867.830 / 7 * odleg³oœæ, 0.0f, 0.0f); // gdzie siê znajduje na scenie
	glm::mat4 neptunModel = glm::mat4(1.0f);
	neptunModel = glm::translate(neptunModel, neptunPos);


	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	shaderProgram.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(objectModel));
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	// S³oñce podanie macierzy przekszta³ceñ i pozycji œwiat³a do uniformów
	sunShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(sunShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(sunModel));
	glUniform4f(glGetUniformLocation(sunShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(sunShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	// Merkury
	merkuryShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(merkuryShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(merkuryModel));
	glUniform4f(glGetUniformLocation(merkuryShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(merkuryShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	// wenus
	wenusShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(wenusShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(wenusModel));
	glUniform4f(glGetUniformLocation(wenusShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(wenusShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	// ziemia
	ziemiaShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(ziemiaShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(ziemiaModel));
	glUniform4f(glGetUniformLocation(ziemiaShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(ziemiaShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	// mars
	marsShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(marsShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(marsModel));
	glUniform4f(glGetUniformLocation(marsShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(marsShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	// jowisz
	jowiszShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(jowiszShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(jowiszModel));
	glUniform4f(glGetUniformLocation(jowiszShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(jowiszShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	// saturn 
	saturnShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(saturnShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(saturnModel));
	glUniform4f(glGetUniformLocation(saturnShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(saturnShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	// neptun
	neptunShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(neptunShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(neptunModel));
	glUniform4f(glGetUniformLocation(neptunShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(neptunShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);



	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Creates camera object
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	// Main while loop
	while (!glfwWindowShouldClose(window)) {
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		// Handles camera inputs
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		shaderProgram.Activate();
		//vaop.Bind();
		//glDrawElements(GL_TRIANGLES, planetIndices.size(), GL_UNSIGNED_INT, 0);

		// Draws different meshes
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		floor.Draw(shaderProgram, camera);
		light.Draw(lightShader, camera);
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		sun.Draw(sunShader, camera);
		merkury.Draw(merkuryShader, camera);
		wenus.Draw(wenusShader, camera);
		ziemia.Draw(ziemiaShader, camera);
		mars.Draw(marsShader, camera);
		jowisz.Draw(jowiszShader, camera);
		saturn.Draw(saturnShader, camera);


		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	shaderProgram.Delete();
	lightShader.Delete();
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	merkuryShader.Delete();
	wenusShader.Delete();
	ziemiaShader.Delete();
	marsShader.Delete();
	jowiszShader.Delete();
	saturnShader.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}